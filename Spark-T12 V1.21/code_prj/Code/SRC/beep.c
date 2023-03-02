#include	"beep.h"

/************* 本地函数和变量声明 *****************/

bit beep_fig;
/***************************************************/

/***********************************************************
*@fuction	:Beep
*@brief		:驱动无源蜂鸣器
*@param		:ON/OFF
*@return	:void
*@author	:--xptx
*@date		:2022-10-02
***********************************************************/

void Beep(bit x)
{
    if(!x)  //打开蜂鸣器
    {
        //beep_fig=1;
        TIM_InitTypeDef		TIM_InitStructure;						//结构定义
        TIM_InitStructure.TIM_Interrupt = ENABLE;					//中断是否允许,   ENABLE或DISABLE. (注意: Timer2固定为16位自动重装, 中断固定为低优先级)
        TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;		//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
        TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
        TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / 8000UL);				//初值
        TIM_InitStructure.TIM_Run       = ENABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
        Timer_Inilize(Timer2, &TIM_InitStructure);					//初始化Timer2	  Timer0,Timer1,Timer2,Timer3,Timer4
    }
    else  if(x)//关闭蜂鸣器
    {
        //beep_fig=0;
        TIM_InitTypeDef		TIM_InitStructure;						//结构定义
        TIM_InitStructure.TIM_Interrupt = DISABLE;					//中断是否允许,   ENABLE或DISABLE. (注意: Timer2固定为16位自动重装, 中断固定为低优先级)
        TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;		//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
        TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
        TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / 8000UL);				//初值
        TIM_InitStructure.TIM_Run       = DISABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
        Timer_Inilize(Timer2, &TIM_InitStructure);					//初始化Timer2	  Timer0,Timer1,Timer2,Timer3,Timer4
        //delay_ms(1);
        beep = 0;
    }

}
