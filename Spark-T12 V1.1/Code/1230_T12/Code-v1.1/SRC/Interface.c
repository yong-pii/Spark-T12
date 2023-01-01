#include "interface.h"


extern PWMx_Duty PWMA_Duty;
//extern u8  xdata   tmp[Max_Length];        //EEPROM操作缓冲
extern u16 Ch1_vinput;
extern u16 present_temp, expect_temp, temp_T12,NTC_temp_v; //当前温度，期望温度
extern u16 Kp, Ti, Td;
extern u16 set_sleep_time;  //设置休眠时间
static  u8 z = 0;
extern u16 sleep_time_s, set_sleep_time;  //休眠计时
/***********************************************************
*@fuction	:show_Init
*@brief		:初始显示界面
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-03
***********************************************************/

void show_Init(void)
{
    OLED_ShowString(8, 1, "Spark_T12", 16);
    delay_ms(1000);
} 


void show_1(void)
{
    u8 i;
    i++;
    if(key_add() == 1)
    {
        expect_temp += 10;
    }
    else if(key_lessen() == 1)
    {
        expect_temp -= 10;
    }

    //OLED_ShowNum(45, 0, NTC_temp_v, 4, 8); //显示当前温度
    OLED_ShowNum(5, 0, expect_temp, 3, 22); //显示期望温度
      
   //OLED_ShowNum(0, 0, temp_T12, 4, 16); //显示期望温度

    
 		OLED_ShowNum(100, 2, (abs(expect_temp - temp_T12) * 100) / expect_temp, 3, 8);	 //显示温度差值百分比%
    OLED_ShowString(120, 2, "%", 8);
    if(i == 10)
    {
        OLED_ShowNum(100, 0, ((PWMA_Duty.PWM2_Duty)) / 655, 3, 8);    //显示功率百分比%
        i = 0;
    }
    OLED_ShowString(120, 0, "%", 8);
		
		if(expect_temp>450) expect_temp = 450;
		if(expect_temp<100) expect_temp = 100;
		//data_send(present_temp);
}

void show_2(void)  //电源电压选择界面
{
    static u8 i[5] = {5, 9, 12, 15, 20}, x = 0;
   
    //  u16 v;
    if(key_add() == 1)
    {
        if(x<5)x++;
        //OLED_Clear();
			power(i[x]);
        OLED_ShowNum(70, 2, i[x], 2, 16);
			power_record();
        delay_ms(200);
    }
    else if(key_lessen() == 1)
    {
        if(x>0&&x<5)x--;
        //OLED_Clear();
			power(i[x]);
        OLED_ShowNum(70, 2, i[x], 2, 16);
			power_record();
        delay_ms(200);
    }
    if(x > 4) x = 0;
    
    //v= 0.03867 * Get_ADCResult(1)/1;
    OLED_ShowNum(70, 0, Ch1_vinput, 5, 16); //输入电压
    //OLED_ShowNum(0,0,0.03867 * Get_ADCResult(1)/1,2,16);  //输入电压


}

void show_3(void)
{
    u8 i = 0;
    static u8 j, k;
    OLED_ShowNum(105, 0, Kp, 3,16); //显示Kp数值
   // OLED_ShowNum(118, 0,(Kp*10)%10, 1, 8); //显示Kp数值	
	
    OLED_ShowNum( 45, 2, Ti, 2, 16); //显示Ti数值
    OLED_ShowNum(110, 2, Td, 2, 16); //显示Td数值

    OLED_ShowString(65, 2, "  ", 16); //消隐Td的">>"
    OLED_ShowString( 0, 2, "  ", 16); //消隐Ti的">>"
    OLED_ShowString(65, 0, ">>", 16); //kP的">>"

    while(i == 0) //调整Kp
    {
        j = key_add();
        k = key_lessen();
        if(j == 1) Kp=Kp+1; //识别到up短按,Kp+1
        else if(k == 1) Kp-=1; //识别到down短按,Kp-1
        else if(j == 2) i = 1; //识别到up长按,切换到Td
        //		else
        //		if(k==2) i=2;   //识别到down长按,切换到Ti

        OLED_ShowNum(105, 0, Kp, 3,16); //显示Kp数值
        if(key_mode() == 1)
        {
            z++;
            i = 3;
        }
        if(Kp > 150) Kp = 150;
        if(Kp < 1) Kp = 1;
				if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM					
    }

    OLED_ShowString(65, 2, "  ", 16); //消隐Td的">>"
    OLED_ShowString(0, 2, ">>", 16); //消隐Ti的">>"
    OLED_ShowString(65, 0, "  ", 16); //消隐kP的">>"

    while(i == 1) //调整Ti
    {
        j = key_add();
        k = key_lessen();
        if(j == 1) Ti++; //识别到up短按,Kp+1
        else if(k == 1) Ti--; //识别到down短按,Kp-1
        else if(j == 2) i = 2; //识别到up长按,切换到Td
        //		else
        //		if(k==2) i=0;  //识别到down长按,切换到Ti

        OLED_ShowNum(45, 2, (u16)Ti, 2, 16); //显示Ti数值
        if(key_mode() == 1)
        {
            z++;
            i = 3;
        }
        if(Ti > 100) Ti = 100;
        if(Ti < 0) Ti = 0;
				if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM					
    }

    OLED_ShowString(65, 2, ">>", 16); //消隐Td的">>"
    OLED_ShowString(0, 2, "  ", 16); //消隐Ti的">>"
    OLED_ShowString(65, 0, "  ", 16); //消隐kP的">>"

    while(i == 2) //调整Td
    {
        j = key_add();
        k = key_lessen();

        if(j == 1) Td++; //识别到up短按,Kp+1
        else if(k == 1) Td--; //识别到down短按,Kp-1
        else if(j == 2) i = 0; //识别到up长按,切换到Kp
        //		else
        //		if(k==2) i=1;  //识别到down长按,切换到Ti

        OLED_ShowNum(110, 2, (u16)Td, 2, 16); //显示Td数值
        if(key_mode() == 1)
        {
            z++;
            i = 3;
        }
        if(Td > 100) Td = 100;
        if(Td < 0) Td = 0;
				if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM					
    }

}

/***********************************************************
*@fuction	:show_4
*@brief		:休眠时间设置界面
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/
void show_4(void)
{
    //
  OLED_ShowNum(40, 2,set_sleep_time, 2, 16); //显示设置无状态自动休眠时长
	
    if(key_add() == 1)
    {
      set_sleep_time++;
    }
    else if(key_lessen() == 1)
    {
     set_sleep_time--;
    }
		if(set_sleep_time<1) set_sleep_time=1;  //限制休眠时间大于一分钟
		
		OLED_ShowNum(0,2,sleep_time_s,3,16);
}


/***********************************************************
*@fuction	:interface_show
*@brief		:
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/
void interface_show(void)
{


    OLED_Clear();
    OLED_ShowChinese(40, 1, 0, 12); //℃
    OLED_ShowString(70, 2, "Eeeor", 8);	//功率百分比%
    OLED_ShowString(70, 0, "power", 8);	//功率百分比%
    while(z == 0)  //界面1
    {
				if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM
        show_1();
        if(key_mode() == 1) z++;
    }
    OLED_Clear();
    while(z == 1)  //界面2 设置供电电压
    {
			  bit f=0;
			
				if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM			
        OLED_ShowChinese(0,0,13, 12); //当前电压
        OLED_ShowChinese(14,0,14, 12); 
        OLED_ShowChinese(28,0,17, 12); 
        OLED_ShowChinese(42,0,18, 12); 			
			  OLED_ShowString(55, 0, ":", 16);
			
        OLED_ShowChinese(0,2,15, 12); //输入电压
        OLED_ShowChinese(14,2,16, 12); 
        OLED_ShowChinese(28,2,17, 12); 
        OLED_ShowChinese(42,2,18, 12); 			
			  OLED_ShowString( 55,2, ":", 16);			
			
			if(!f){ f=1; OLED_ShowNum(70, 2,v_data_out(), 2, 16); }
			
        OLED_ShowString(110, 0, "mV", 16);
        OLED_ShowString(110, 2, "V", 16);			
        show_2();
        if(key_mode() == 1) z++;
			  power_record();
    }
    OLED_Clear();
    while(z == 2)  //界面3
    {
		
        OLED_ShowString(10, 0, "PID:", 16);
        OLED_ShowString(85, 0, "Kp:", 16);
        OLED_ShowString(20, 2, "Ti:", 16);
        OLED_ShowString(85, 2, "Td:", 16);
        show_3();
        if(key_mode() == 1) z++;
    }
    OLED_Clear();		
    while(z == 3) //界面4
    {
				if((sleep_time_s/60)>=set_sleep_time)  sleep_mode();  //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM			
		 OLED_ShowChinese( 0, 0,10, 12); //设置无操作自动休眠
     OLED_ShowChinese(14, 0,11, 12); //	
     OLED_ShowChinese(28, 0, 1, 12); //
     OLED_ShowChinese(42, 0, 2, 12); //
     OLED_ShowChinese(56, 0, 3, 12); //
     OLED_ShowChinese(70, 0, 4, 12); //
     OLED_ShowChinese(84, 0, 5, 12); //
     OLED_ShowChinese(98, 0, 6, 12); //
     OLED_ShowChinese(112,0, 7, 12); //	

     OLED_ShowString(70, 2, "Min", 16);	//min
		 show_4();		
			
     if(key_mode() == 1) z++;
    }

    if(z > 3) z = 0;

}

