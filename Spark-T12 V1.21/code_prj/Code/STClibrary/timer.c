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

/*************	本地变量声明	**************/
u8 PWM_Duty;    //PWM占空比
u8 tpme_skewing;   //温度校准偏移量
u16 vv_T12;    //烙铁头热电偶电压

/*************  外部函数和变量声明 *****************/
extern u16 present_temp, expect_temp; //当前温度，期望温度
extern u16 Ch1_vinput, NTC_temp, temp_T12;
extern bit sleep_fig;
extern u16 sleep_time_s, set_sleep_time;  //休眠计时
static u16 temporary_Duty;
extern u16 xx, yy, zz;
extern u16 F_pwmti;
extern bit beep_fig;
/********************* Timer0中断函数 1ms中断一次************************/
void timer0_int (void) interrupt TIMER0_VECTOR
{
    static u8 i = 0;

    if(sleep_fig == 1)  //休眠模式
    {
        PWM_Duty = 0;            //占空比清零
        P12 = 0;
    }
    else  //正常模式
    {

        i++;

        if(i <= PWM_Duty)
            P12 = 1;
        else
            P12 = 0;



        if(i == 100)
        {
            //beep = !beep;
            i = 0;
            present_temp = filter(10); //滤波

            NTC_temp = resistanceToTemperature(NTC_outres(3.3, (float)((825 / 256) * Get_ADCResult(14)) / 1000, 10000), 3455, 10000, 25); //计算NTC电阻温度

            Ch1_vinput =  (9075 / 256) * Get_ADCResult(1) / 1; //计算当前供电电压
            vv_T12 = present_temp;   //调试 显示当前热电偶电压用
            if(present_temp < 100) present_temp = 100;  //热电偶电压区域限制

            present_temp = order_fitting(present_temp);  //拟合输出温度

					present_temp=present_temp+tpme_skewing; //增加温度偏移量
					
            temp_T12 = present_temp;  //读取当前温度

            if(present_temp >= 550  || expect_temp < present_temp)
                PWM_Duty = 0;
            else if(present_temp < 180)
                PWM_Duty = 95; //低温下ADC无法正确读出数据，需要加热到一定温度。
            else
                PWM_Duty =  PID(present_temp, expect_temp) / 15; //计算并输出占空比

            if(PWM_Duty > 95) PWM_Duty = 95; //输出占空比限制

        }
    }
}

/********************* Timer1中断函数--休眠控制 *******************2ms中断一次*****/
void timer1_int (void) interrupt TIMER1_VECTOR
{
    static u16 ms2 = 0;
    ms2++;

    SC7A20_GetInfo();  //获取xyz轴加速度值

    temp_protect(ms2,NTC_temp);//温度限制保护  注：此处存在多处调用

    if(ms2 == 500)
    {
        sleep_time_s++;    //休眠计时
        ms2 = 0;
    }
    if(xx > 80 && yy > 80 && zz > 80) sleep_time_s = 0; //检测到动作，休眠计时清零

    if(sleep_time_s >= 65535) sleep_time_s = 60000; //防溢出

}

/********************* Timer2中断函数--蜂鸣器控制 ************************/
void timer2_int (void) interrupt TIMER2_VECTOR
{
    //if(beep_fig)
    beep = !beep;
}

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
