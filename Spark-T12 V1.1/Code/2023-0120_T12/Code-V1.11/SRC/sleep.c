#include "sleep.h"
u16 sleep_io_v;
bit sleep_fig=0;
u16 sleep_time_s = 0, set_sleep_time = 5; //休眠计时，设置休眠时间
extern PWMx_Duty PWMA_Duty;
extern u8 z = 0;
/***********************************************************
*@fuction	:sleep_PWM_RST
*@brief		:关闭PWM发生器
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/
void sleep_PWM_RST(void)
{
    PWMx_InitDefine		PWMx_InitStructure;
    PWMx_InitStructure.PWM2_Mode       =	CCMRn_PWM_MODE1;	//模式,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
    PWMx_InitStructure.PWM2_SetPriority  = Priority_1;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    PWMx_InitStructure.PWM_Period      = 65535;							//周期时间,   0~65535    约11.6khz
    PWMx_InitStructure.PWM2_Duty       = PWMA_Duty.PWM2_Duty;	//PWM2占空比时间, 0~Period
    PWMx_InitStructure.PWM_DeadTime    = 0;								//死区发生器设置, 0~255
    PWMx_InitStructure.PWM_EnoSelect   = ENO2P;//ENO1P | ENO1N | ENO2P | ENO2N | ENO3P | ENO3N | ENO4P | ENO4N;	//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
    PWMx_InitStructure.PWM_PS_SW       = PWM2_SW_P12_P13;//PWM1_SW_P60_P61| PWM2_SW_P62_P63 | PWM3_SW_P64_P65 | PWM4_SW_P66_P67;	//切换端口,		PWM1_SW_P10_P11,PWM1_SW_P20_P21,PWM1_SW_P60_P61
    PWMx_InitStructure.PWM_CC2Enable   = DISABLE;				//开启PWM2P输入捕获/比较输出,  ENABLE,DISABLE
    PWMx_InitStructure.PWM_MainOutEnable = DISABLE;				//主输出使能, ENABLE,DISABLE
    PWMx_InitStructure.PWM_CEN_Enable   = DISABLE;				//使能计数器, ENABLE,DISABLE
    PWM_Configuration(PWMA, &PWMx_InitStructure);				//初始化PWM,  PWMA,PWMB

}

/***********************************************************
*@fuction	:sleep_PWM_SET
*@brief		:开启PWM发生器
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/

void sleep_PWM_SET(void)
{
    PWMx_InitDefine		PWMx_InitStructure;

    PWMx_InitStructure.PWM2_Mode    =	CCMRn_PWM_MODE1;	//模式,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
    PWMx_InitStructure.PWM2_SetPriority  = Priority_1;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    PWMx_InitStructure.PWM_Period   = 65535;							//周期时间,   0~65535    约11.6khz
    PWMx_InitStructure.PWM2_Duty    = PWMA_Duty.PWM2_Duty;	//PWM2占空比时间, 0~Period
    PWMx_InitStructure.PWM_DeadTime = 0;								//死区发生器设置, 0~255
    PWMx_InitStructure.PWM_EnoSelect   = ENO2P;//ENO1P | ENO1N | ENO2P | ENO2N | ENO3P | ENO3N | ENO4P | ENO4N;	//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
    PWMx_InitStructure.PWM_PS_SW       = PWM2_SW_P12_P13;//PWM1_SW_P60_P61| PWM2_SW_P62_P63 | PWM3_SW_P64_P65 | PWM4_SW_P66_P67;	//切换端口,		PWM1_SW_P10_P11,PWM1_SW_P20_P21,PWM1_SW_P60_P61
    PWMx_InitStructure.PWM_CC2Enable   = ENABLE;				//开启PWM2P输入捕获/比较输出,  ENABLE,DISABLE
    PWMx_InitStructure.PWM_MainOutEnable = ENABLE;				//主输出使能, ENABLE,DISABLE
    PWMx_InitStructure.PWM_CEN_Enable   = ENABLE;				//使能计数器, ENABLE,DISABLE
    PWM_Configuration(PWMA, &PWMx_InitStructure);				//初始化PWM,  PWMA,PWMB

}

/***********************************************************
*@fuction	:sleep_show
*@brief		:
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/

void sleep_show(void)
{
    static u16 i;
	i+=10;
			if(sleep_io_v >= 28) sleep_time_s = 0; //电压超阈值说明烙铁发生动作，休眠计时清零
			
			if((i % 1000) == 0)
			{
        OLED_Clear();//清屏
        OLED_ShowChinese( i/100 + 0, 1, 6, 12); //休
        OLED_ShowChinese(i/100 + 14, 1, 7, 12); //眠
        OLED_ShowChinese(i/100 + 28, 1, 12, 12); //中
			}
			delay_ms(10);
			
		if(i>=12001) i=0;
}



/***********************************************************
*@fuction	:sleep_mode
*@brief		:休眠模式
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/

void sleep_mode(void)
{
    OLED_Clear();//清屏
    sleep_PWM_RST();  //关闭PWM
	  sleep_fig=1; //休眠标志位置一
		P12=0;  //拉低pwm输出IO口
    while(1)
    {
        sleep_show();  //休眠显示界面
        if(sleep_io_v >= 28) sleep_time_s = 0; //电压超阈值说明烙铁发生动作，休眠计时清零

        if((sleep_time_s / 60) < set_sleep_time) //休眠计时小于设定值，检测到动作，计数重置，跳出休眠模式
        {
            sleep_PWM_SET();
					  if(z==0)  //返回界面1
					interface_show1_Init();  //初始化界面1
            //interface_show();
						// OLED_Clear();  //清屏
            break;
        }
			//if(P12) P12=0;  //重复检测保护
    }
	sleep_fig=0; //休眠结束，标志位置0

}
