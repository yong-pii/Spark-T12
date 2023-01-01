#include	"config.h"



#define Sleep_Fig P32
PWMx_Duty PWMA_Duty;

//PWMx_Duty PWMA_Duty_rst;
u16 thermocouple_v, temp_T12, NTC_temp_v; //热电偶电压，烙铁头温度，NTC电阻分压电压

u8  xdata   tmp[Max_Length];        //EEPROM操作缓冲
extern u16 sleep_time_s;  //休眠计时
extern u16 sleep_time_s, set_sleep_time;  //休眠计时
u16 Ch1_vinput;  //供电电压
/************************ IO口配置 ****************************/
void	GPIO_config(void)
{
    GPIO_InitTypeDef	GPIO_InitStructure;				//结构定义

    GPIO_InitStructure.Pin  = GPIO_Pin_2 | GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;				//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
    GPIO_InitStructure.Mode = GPIO_PullUp;			//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P1, &GPIO_InitStructure);	//初始化

    GPIO_InitStructure.Pin  = GPIO_Pin_0 | GPIO_Pin_1;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_InitStructure.Mode = GPIO_HighZ;	//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P1, &GPIO_InitStructure);	//初始化

    GPIO_InitStructure.Pin  = GPIO_Pin_6;		//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7
    GPIO_InitStructure.Mode = GPIO_HighZ;	//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化

    GPIO_InitStructure.Pin  = GPIO_Pin_3 | GPIO_Pin_4 | GPIO_Pin_5;				//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
    GPIO_InitStructure.Mode = GPIO_OUT_PP;			//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化

    GPIO_InitStructure.Pin  = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_7;				//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
    GPIO_InitStructure.Mode = GPIO_OUT_PP;			//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P3, &GPIO_InitStructure);	//初始化

    GPIO_InitStructure.Pin  = GPIO_Pin_All;			//指定要初始化的IO, GPIO_Pin_0 ~ GPIO_Pin_7, 或操作
    GPIO_InitStructure.Mode = GPIO_PullUp;			//指定IO的输入或输出方式,GPIO_PullUp,GPIO_HighZ,GPIO_OUT_OD,GPIO_OUT_PP
    GPIO_Inilize(GPIO_P5, &GPIO_InitStructure);	//初始化
}


/******************* AD配置函数 *******************/
void	ADC_config(void)
{
    ADC_InitTypeDef		ADC_InitStructure;		//结构定义
    ADC_InitStructure.ADC_SMPduty   = 10;		//ADC 模拟信号采样时间控制, 0~31（注意： SMPDUTY 一定不能设置小于 10）
    ADC_InitStructure.ADC_CsSetup   = 0;		//ADC 通道选择时间控制 0(默认),1
    ADC_InitStructure.ADC_CsHold    = 1;		//ADC 通道选择保持时间控制 0,1(默认),2,3
    ADC_InitStructure.ADC_Speed     = ADC_SPEED_2X1T;		//设置 ADC 工作时钟频率	ADC_SPEED_2X1T~ADC_SPEED_2X16T
    ADC_InitStructure.ADC_Power     = ENABLE;				//ADC功率允许/关闭	ENABLE,DISABLE
    ADC_InitStructure.ADC_AdjResult = ADC_RIGHT_JUSTIFIED;	//ADC结果调整,	ADC_LEFT_JUSTIFIED,ADC_RIGHT_JUSTIFIED
    ADC_InitStructure.ADC_Priority    = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    ADC_InitStructure.ADC_Interrupt = DISABLE;			//中断允许	ENABLE,DISABLE
    ADC_Inilize(&ADC_InitStructure);					//初始化
    ADC_PowerControl(ENABLE);							//单独的ADC电源操作函数, ENABLE或DISABLE
}

/***************  串口初始化函数 *****************/
//void	UART_config(void)
//{
//	COMx_InitDefine		COMx_InitStructure;					//结构定义
//	COMx_InitStructure.UART_Mode      = UART_8bit_BRTx;	//模式, UART_ShiftRight,UART_8bit_BRTx,UART_9bit,UART_9bit_BRTx
//	COMx_InitStructure.UART_BRT_Use   = BRT_Timer1;			//选择波特率发生器, BRT_Timer1, BRT_Timer2 (注意: 串口2固定使用BRT_Timer2)
//	COMx_InitStructure.UART_BaudRate  = 9600ul;			//波特率, 一般 110 ~ 115200
//	COMx_InitStructure.UART_RxEnable  = ENABLE;				//接收允许,   ENABLE或DISABLE
//	COMx_InitStructure.BaudRateDouble = DISABLE;			//波特率加倍, ENABLE或DISABLE
//	COMx_InitStructure.UART_Interrupt = ENABLE;				//中断允许,   ENABLE或DISABLE
//	COMx_InitStructure.UART_Priority    = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
//	COMx_InitStructure.UART_P_SW      = UART1_SW_P30_P31;	//切换端口,   UART1_SW_P30_P31,UART1_SW_P36_P37,UART1_SW_P16_P17,UART1_SW_P43_P44
//	UART_Configuration(UART1, &COMx_InitStructure);		//初始化串口1 UART1,UART2,UART3,UART4
//}

/************************ 定时器配置 ****************************/
void	Timer_config(void)
{
    TIM_InitTypeDef		TIM_InitStructure;						//结构定义

    TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
    TIM_InitStructure.TIM_Priority  = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    TIM_InitStructure.TIM_Interrupt = ENABLE;					//中断是否允许,   ENABLE或DISABLE
    TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;		//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
    TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
    TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / 10000UL);		//中断频率, 1000次/秒
    TIM_InitStructure.TIM_Run       = ENABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
    Timer_Inilize(Timer0, &TIM_InitStructure);					//初始化Timer0	  Timer0,Timer1,Timer2,Timer3,Timer4


    TIM_InitStructure.TIM_Mode      = TIM_16BitAutoReload;	//指定工作模式,   TIM_16BitAutoReload,TIM_16Bit,TIM_8BitAutoReload,TIM_16BitAutoReloadNoMask
    TIM_InitStructure.TIM_Priority    = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    TIM_InitStructure.TIM_Interrupt = ENABLE;					//中断是否允许,   ENABLE或DISABLE
    TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;		//指定时钟源, TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
    TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
    TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (500 * 12));			//初值,2ms中断一次
    TIM_InitStructure.TIM_Run       = ENABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
    Timer_Inilize(Timer1, &TIM_InitStructure);					//初始化Timer1	  Timer0,Timer1,Timer2,Timer3,Timer4

    TIM_InitStructure.TIM_Interrupt = DISABLE;					//中断是否允许,   ENABLE或DISABLE. (注意: Timer2固定为16位自动重装, 中断固定为低优先级)
    TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_1T;		//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
    TIM_InitStructure.TIM_ClkOut    = DISABLE;				//是否输出高速脉冲, ENABLE或DISABLE
    TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / 8000UL);				//初值
    TIM_InitStructure.TIM_Run       = DISABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
    Timer_Inilize(Timer2, &TIM_InitStructure);					//初始化Timer2	  Timer0,Timer1,Timer2,Timer3,Timer4

    //	TIM_InitStructure.TIM_Interrupt = ENABLE;					//中断是否允许,   ENABLE或DISABLE. (注意: Timer2固定为16位自动重装, 中断固定为低优先级)
    //	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;	//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
    //	TIM_InitStructure.TIM_ClkOut    = ENABLE;					//是否输出高速脉冲, ENABLE或DISABLE
    //	TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (4000*12));		//初值
    //	TIM_InitStructure.TIM_Run      = ENABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
    //	Timer_Inilize(Timer3,&TIM_InitStructure);					//初始化Timer3	  Timer0,Timer1,Timer2,Timer3,Timer4

    //	TIM_InitStructure.TIM_Interrupt = ENABLE;					//中断是否允许,   ENABLE或DISABLE. (注意: Timer2固定为16位自动重装, 中断固定为低优先级)
    //	TIM_InitStructure.TIM_ClkSource = TIM_CLOCK_12T;	//指定时钟源,     TIM_CLOCK_1T,TIM_CLOCK_12T,TIM_CLOCK_Ext
    //	TIM_InitStructure.TIM_ClkOut    = ENABLE;					//是否输出高速脉冲, ENABLE或DISABLE
    //	TIM_InitStructure.TIM_Value     = 65536UL - (MAIN_Fosc / (1000));		//初值
    //	TIM_InitStructure.TIM_Run       = ENABLE;					//是否初始化后启动定时器, ENABLE或DISABLE
    //	Timer_Inilize(Timer4,&TIM_InitStructure);					//初始化Timer4	  Timer0,Timer1,Timer2,Timer3,Timer4
}

/***************  PWM初始化函数 *****************/
void	PWM_config(void)
{
    PWMx_InitDefine		PWMx_InitStructure;

    //PWMx_InitStructure.PWM1_Mode    =	CCMRn_PWM_MODE1;	//模式,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
    PWMx_InitStructure.PWM2_Mode    =	CCMRn_PWM_MODE1;	//模式,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
    //PWMx_InitStructure.PWM3_Mode    =	CCMRn_PWM_MODE1;	//模式,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
    //PWMx_InitStructure.PWM4_Mode    =	CCMRn_PWM_MODE1;	//模式,		CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2

    //PWMx_InitStructure.PWM1_SetPriority  = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    PWMx_InitStructure.PWM2_SetPriority  = Priority_1;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    //PWMx_InitStructure.PWM3_SetPriority  = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3
    //PWMx_InitStructure.PWM4_SetPriority  = Priority_0;			//指定中断优先级(低到高) Priority_0,Priority_1,Priority_2,Priority_3

    PWMx_InitStructure.PWM_Period   = 65535;							//周期时间,   0~65535    约460hz
    //PWMx_InitStructure.PWM1_Duty    = PWMA_Duty.PWM1_Duty;	//PWM1占空比时间, 0~Period
    PWMx_InitStructure.PWM2_Duty    = PWMA_Duty.PWM2_Duty;	//PWM2占空比时间, 0~Period
    //PWMx_InitStructure.PWM3_Duty    = PWMA_Duty.PWM3_Duty;	//PWM3占空比时间, 0~Period
    //PWMx_InitStructure.PWM4_Duty    = PWMA_Duty.PWM4_Duty;	//PWM4占空比时间, 0~Period
    PWMx_InitStructure.PWM_DeadTime = 0;								//死区发生器设置, 0~255

    PWMx_InitStructure.PWM_EnoSelect   = ENO2P;//ENO1P | ENO1N | ENO2P | ENO2N | ENO3P | ENO3N | ENO4P | ENO4N;	//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
    PWMx_InitStructure.PWM_PS_SW       = PWM2_SW_P12_P13;//PWM1_SW_P60_P61| PWM2_SW_P62_P63 | PWM3_SW_P64_P65 | PWM4_SW_P66_P67;	//切换端口,		PWM1_SW_P10_P11,PWM1_SW_P20_P21,PWM1_SW_P60_P61
    //						PWM2_SW_P12_P13,PWM2_SW_P22_P23,PWM2_SW_P62_P63
    //						PWM3_SW_P14_P15,PWM3_SW_P24_P25,PWM3_SW_P64_P65
    //						PWM4_SW_P16_P17,PWM4_SW_P26_P27,PWM4_SW_P66_P67,PWM4_SW_P34_P33

    //	PWMx_InitStructure.PWM_CC1Enable   = ENABLE;				//开启PWM1P输入捕获/比较输出,  ENABLE,DISABLE
    //	PWMx_InitStructure.PWM_CC1NEnable  = ENABLE;				//开启PWM1N输入捕获/比较输出,  ENABLE,DISABLE
    PWMx_InitStructure.PWM_CC2Enable   = ENABLE;				//开启PWM2P输入捕获/比较输出,  ENABLE,DISABLE
    //	PWMx_InitStructure.PWM_CC2NEnable  = ENABLE;				//开启PWM2N输入捕获/比较输出,  ENABLE,DISABLE
    //	PWMx_InitStructure.PWM_CC3Enable   = ENABLE;				//开启PWM3P输入捕获/比较输出,  ENABLE,DISABLE
    //	PWMx_InitStructure.PWM_CC3NEnable  = ENABLE;				//开启PWM3N输入捕获/比较输出,  ENABLE,DISABLE
    //	PWMx_InitStructure.PWM_CC4Enable   = ENABLE;				//开启PWM4P输入捕获/比较输出,  ENABLE,DISABLE
    //	PWMx_InitStructure.PWM_CC4NEnable  = ENABLE;				//开启PWM4N输入捕获/比较输出,  ENABLE,DISABLE

    PWMx_InitStructure.PWM_MainOutEnable = ENABLE;				//主输出使能, ENABLE,DISABLE
    PWMx_InitStructure.PWM_CEN_Enable   = ENABLE;				//使能计数器, ENABLE,DISABLE
    PWM_Configuration(PWMA, &PWMx_InitStructure);				//初始化PWM,  PWMA,PWMB
}


/******************** 主函数**************************/
void main(void)
{

    PWMA_Duty.PWM2_Duty = 6000;  //占空比 x/65536
    GPIO_config();  //GPIO初始化
    P3PU = 0x38;      //设置P3IO口上拉电阻
    //UART_config();  //串口初始化
    ADC_config();	    //ADC初始化
    Timer_config();   //定时器初始化
    PWM_config();     //硬件PWM初始化
    EA = 1;           //开中断



    OLED_Init();          //初始化OLED
    OLED_ColorTurn(0);    //0正常显示，1 反色显示
    OLED_DisplayTurn(1);  //0正常显示 1 屏幕翻转显示

    UpdatePwm(PWMA, &PWMA_Duty);  //PWM 占空比设置函数

    OLED_Clear();  //oled清屏
    show_Init();   //显示初始界面
    OLED_Clear();  //oled清屏
    power_Init();  //恢复供电电压记忆
    //Beep(OFF);

    // beep = 0;
    while (1)
    {
        interface_show();  //界面
    }
}



