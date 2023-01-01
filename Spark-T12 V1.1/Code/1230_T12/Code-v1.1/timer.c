/*---------------------------------------------------------------------*/
/* --- STC MCU Limited ------------------------------------------------*/
/* --- STC 1T Series MCU Demo Programme -------------------------------*/
/* --- Mobile: (86)13922805190 ----------------------------------------*/
/* --- Fax: 86-0513-55012956,55012947,55012969 ------------------------*/
/* --- Tel: 86-0513-55012928,55012929,55012966 ------------------------*/
/* --- Web: www.STCMCU.com --------------------------------------------*/
/* --- Web: www.STCMCUDATA.com  ---------------------------------------*/
/* --- QQ:  800003751 -------------------------------------------------*/
/* 如果要在程序中使用此代码,请在程序中注明使用了STC的资料及程序            */
/*---------------------------------------------------------------------*/

/*************	功能说明	**************

本文件为STC8系列的定时器初始化和中断程序,用户可以在这个文件中修改自己需要的中断程序.

******************************************/

#include	"timer.h"
#include	"PWM.h"

//#define adc1 Get_ADCResult(1)
//#include "Spark_T12_PID.h"
//#include	"beep.h"
//extern bit fig1;
//extern beep P37

/*************	本地变量声明	**************/
//bit PWM1_Flag;
//bit PWM2_Flag;
//bit PWM3_Flag;
//bit PWM4_Flag;

/*************  外部函数和变量声明 *****************/
extern PWMx_Duty PWMA_Duty;
extern u16 present_temp, expect_temp; //当前温度，期望温度
extern u16 Ch1_vinput, NTC_temp_v, temp_T12;
extern bit sleep_fig;
extern u16 sleep_time_s, set_sleep_time;  //休眠计时
extern u16 sleep_io_v;    //休眠IO口电压
static u16 temporary_Duty;


/********************* Timer0中断函数 1ms中断一次************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{
    static u16 i = 0;
    i++;
    if(i == 10)
    {
        sleep_io_v = (3300 / 1024) * Get_ADCResult(10); //测sleep引脚电压
        NTC_temp_v = (3300 / 1024) * Get_ADCResult(14) / 1; //计算当前NTC温度
    }

    if(i == 82)
    {
        PWMA_Duty.PWM2_Duty = 0;            //占空比清零
        UpdatePwm(PWMA, &PWMA_Duty);        //PWM 占空比设置函数


    }
    if(i == 85)
    {
        Ch1_vinput = 11 * (3300 / 1024) * Get_ADCResult(1) / 1; //计算当前供电电压
        i = 0;

        present_temp = filter(10); //滤波

        //       Vcc_ref =  ( 1190 / Get_ADCResult(15) ) * 1024 ;
        //      present_temp = ( Vcc_ref / 1024 ) * Get_ADCResult(0);

        //  present_temp =Vcc_ref;
        // 			present_temp =  3300/1024  * Get_ADCResult(0);  (  (1190 * 1024) / Get_ADCResult(15)  )
        temp_T12 = present_temp;
        present_temp = order_fitting(present_temp);  //拟合输出温度

        if(present_temp <= 450 && sleep_fig==0)  //温度限制保护
            PWMA_Duty.PWM2_Duty = PID(present_temp, expect_temp); //计算并输出占空比
        else
            PWMA_Duty.PWM2_Duty = 0;

        if(present_temp < 70)  PWMA_Duty.PWM2_Duty = 58982; //低温下ADC无法正确读出数据，需要加热到一定温度。

        UpdatePwm(PWMA, &PWMA_Duty);             //PWM 占空比设置函数
    }
}

/********************* Timer1中断函数--休眠控制 *******************2ms中断一次*****/
void timer1_int (void) interrupt TIMER1_VECTOR
{
    static u16 ms2 = 0;
    ms2++;
    if(ms2 == 500)
    {
        sleep_time_s++;    //休眠计时
        ms2 = 0;
    }
    if(sleep_io_v >= 28) sleep_time_s = 0; //电压超阈值说明烙铁发生动作，休眠计时清零
		
    if(sleep_time_s >= 65535) sleep_time_s = 60000; //防溢出

    //if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM
}

/********************* Timer2中断函数--蜂鸣器控制 ************************/
void timer2_int (void) interrupt TIMER2_VECTOR
{ 
    beep = !beep;
}

///********************* Timer3中断函数************************/
//void timer3_int (void) interrupt TIMER3_VECTOR
//{
//
//}

///********************* Timer4中断函数************************/
//void timer4_int (void) interrupt TIMER4_VECTOR
//{
//
//}


//========================================================================
// 函数: u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
// 描述: 定时器初始化程序.
// 参数: TIMx: 结构参数,请参考timer.h里的定义.
// 返回: 成功返回0, 空操作返回1,错误返回2.
// 版本: V1.0, 2012-10-22
//========================================================================
u8	Timer_Inilize(u8 TIM, TIM_InitTypeDef *TIMx)
{
    if(TIM > Timer4)	return 1;	//空操作

    if(TIM == Timer0)
    {
        Timer0_Stop();		//停止计数
        if(TIMx->TIM_Interrupt == ENABLE)		Timer0_InterruptEnable();	//允许中断
        else		Timer0_InterruptDisable();	//禁止中断
        if(TIMx->TIM_Priority > Priority_3)	return 2;	//错误
        Timer0_Priority(TIMx->TIM_Priority);	//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3

        if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return 2;	//错误
        TMOD = (TMOD & ~0x30) | TIMx->TIM_Mode;	//工作模式,0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装
        if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	Timer0_12T();	//12T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		Timer0_1T();	//1T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	Timer0_AsCounter();	//对外计数或分频
        else		Timer0_AsTimer();	//定时
        if(TIMx->TIM_ClkOut == ENABLE)	Timer0_CLKO_Enable();	//输出时钟
        else		Timer0_CLKO_Disable();	//不输出时钟

        T0_Load(TIMx->TIM_Value);
        if(TIMx->TIM_Run == ENABLE)	Timer0_Run();	//开始运行
        return	0;		//成功
    }

    if(TIM == Timer1)
    {
        Timer1_Stop();		//停止计数
        if(TIMx->TIM_Interrupt == ENABLE)		Timer1_InterruptEnable();	//允许中断
        else		Timer1_InterruptDisable();	//禁止中断
        if(TIMx->TIM_Priority > Priority_3)	return 2;	//错误
        Timer1_Priority(TIMx->TIM_Priority);	//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
        if(TIMx->TIM_Mode >= TIM_16BitAutoReloadNoMask)	return 2;	//错误
        TMOD = (TMOD & ~0x30) | TIMx->TIM_Mode;	//工作模式,0: 16位自动重装, 1: 16位定时/计数, 2: 8位自动重装
        if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	Timer1_12T();	//12T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		Timer1_1T();	//1T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	Timer1_AsCounter();	//对外计数或分频
        else		Timer1_AsTimer();	//定时
        if(TIMx->TIM_ClkOut == ENABLE)	Timer1_CLKO_Enable();	//输出时钟
        else		Timer1_CLKO_Disable();	//不输出时钟

        T1_Load(TIMx->TIM_Value);
        if(TIMx->TIM_Run == ENABLE)	Timer1_Run();	//开始运行
        return	0;		//成功
    }

    if(TIM == Timer2)		//Timer2,固定为16位自动重装, 中断无优先级
    {
        Timer2_Stop();	//停止计数
        if(TIMx->TIM_Interrupt == ENABLE)		Timer2_InterruptEnable();	//允许中断
        else		Timer2_InterruptDisable();	//禁止中断
        if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
        if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	Timer2_12T();	//12T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		Timer2_1T();	//1T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	Timer2_AsCounter();	//对外计数或分频
        else		Timer2_AsTimer();		//定时
        if(TIMx->TIM_ClkOut == ENABLE)	Timer2_CLKO_Enable();		//输出时钟
        else		Timer2_CLKO_Disable();	//不输出时钟

        T2_Load(TIMx->TIM_Value);
        if(TIMx->TIM_Run == ENABLE)	Timer2_Run();	//开始运行
        return	0;		//成功
    }

    if(TIM == Timer3)		//Timer3,固定为16位自动重装, 中断无优先级
    {
        Timer3_Stop();	//停止计数
        if(TIMx->TIM_Interrupt == ENABLE)		Timer3_InterruptEnable();	//允许中断
        else		Timer3_InterruptDisable();	//禁止中断
        if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
        if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	Timer3_12T();	//12T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		Timer3_1T();	//1T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	Timer3_AsCounter();	//对外计数或分频
        else		Timer3_AsTimer();		//定时
        if(TIMx->TIM_ClkOut == ENABLE)	Timer3_CLKO_Enable();		//输出时钟
        else		Timer3_CLKO_Disable();	//不输出时钟

        T3_Load(TIMx->TIM_Value);
        if(TIMx->TIM_Run == ENABLE)	Timer3_Run();	//开始运行
        return	0;		//成功
    }

    if(TIM == Timer4)		//Timer3,固定为16位自动重装, 中断无优先级
    {
        Timer4_Stop();	//停止计数
        if(TIMx->TIM_Interrupt == ENABLE)		Timer4_InterruptEnable();	//允许中断
        else		Timer4_InterruptDisable();	//禁止中断
        if(TIMx->TIM_ClkSource >  TIM_CLOCK_Ext)	return 2;
        if(TIMx->TIM_ClkSource == TIM_CLOCK_12T)	Timer4_12T();	//12T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_1T)		Timer4_1T();	//1T
        if(TIMx->TIM_ClkSource == TIM_CLOCK_Ext)	Timer4_AsCounter();	//对外计数或分频
        else		Timer4_AsTimer();		//定时
        if(TIMx->TIM_ClkOut == ENABLE)	Timer4_CLKO_Enable();		//输出时钟
        else		Timer4_CLKO_Disable();	//不输出时钟

        T4_Load(TIMx->TIM_Value);
        if(TIMx->TIM_Run == ENABLE)	Timer4_Run();	//开始运行
        return	0;		//成功
    }
    return 2;	//错误
}
