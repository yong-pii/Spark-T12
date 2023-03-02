#include "interface.h"
#include "bmp.h"

/*************************外部变量声明******************************/
extern u8 PWM_Duty;
extern u16 Ch1_vinput;
extern u16 present_temp, expect_temp, temp_T12, NTC_temp; //当前温度，期望温度，热电偶电压，NTC电阻温度
extern h16 Kp, Ti, Td;
extern u16 sleep_time_s, set_sleep_time;                  //休眠计时(秒)    设置休眠时间

extern u16 vv_T12;
extern u16 F_pwmti;
extern u8 tpme_skewing;   //温度校准偏移量
extern u16 Start_addrs;
extern u8  xdata  eeprom_dat[10];
/*******************************************************************/

/*************************本地变量声明******************************/
u8 z = 0;  //界面页
/*******************************************************************/

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
    OLED_DrawBMP(0, 0, 128, 32, BMP2);
    delay_ms(2000);
}

void show_1(void)
{
    static u8 i;
    i++;
    if(key_add() == 1  && expect_temp < 450)
    {
        expect_temp += 10;
        eeprom_dat[2] = expect_temp / 10;
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);

        OLED_ShowNum(15, 0, expect_temp, 3, 22);  //显示期望温度
    }
    else if(key_lessen() == 1 && expect_temp > 150)
    {
        expect_temp -= 10;
        eeprom_dat[2] = expect_temp / 10;
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);
        OLED_ShowNum(15, 0, expect_temp, 3, 22);  //显示期望温度
    }
    //OLED_ShowNum(45, 0, NTC_temp_v, 4, 8); //显示温度


    if(i == 250)
    {
        //  OLED_ShowNum(70, 0, temp_T12, 3, 8); //显示当前温度
        // OLED_ShowNum(70, 2, vv_T12, 4, 8); //显示当前
        OLED_ShowNum(100, 2, (abs(expect_temp - temp_T12) * 100) / expect_temp, 3, 8);	 //显示温度差值百分比%
        OLED_ShowNum(100, 0, PWM_Duty, 3, 8);    //显示功率百分比%
        i = 0;
    }


    //    if(expect_temp > 450)
    //    {
    //        expect_temp = 450;
    //        OLED_ShowNum(15, 0, expect_temp, 3, 22);  //显示期望温度
    //    }
    //    if(expect_temp < 100)
    //    {
    //        expect_temp = 100;
    //        OLED_ShowNum(15, 0, expect_temp, 3, 22);  //显示期望温度
    //    }
    //data_send(present_temp);
}

void show_2(void)  //电源电压选择界面
{
    static u8 i[5] = {5, 9, 12, 15, 20}, x = 0;
    static u8 time_i = 0;
    time_i++;
    if(key_add() == 1)
    {
        if(x < 5)x++;

        power(i[x]);
        eeprom_dat[0] = i[x];
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);
        OLED_ShowNum(70, 2, i[x], 2, 16);

        delay_ms(200);
    }
    else if(key_lessen() == 1)
    {
        if(x > 0 && x < 5)x--;

        power(i[x]);
        eeprom_dat[0] = i[x];
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);
        OLED_ShowNum(70, 2, i[x], 2, 16);

        delay_ms(200);
    }
    if(x > 4) x = 0;

    //v= 0.03867 * Get_ADCResult(1)/1;
    if(time_i == 20)
    {
        time_i = 0;
        OLED_ShowNum(70, 0, Ch1_vinput, 5, 16); //输入电压
    }
    //OLED_ShowNum(0,0,0.03867 * Get_ADCResult(1)/1,2,16);  //输入电压
}

/***********************************************************
*@fuction	:show_3
*@brief		:温度偏移补偿界面
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2023-02-26
***********************************************************/

void show_3(void)
{
    if(key_add() == 1 && tpme_skewing < 80)
    {
        tpme_skewing += 1;
        eeprom_dat[1] = tpme_skewing;
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);
        OLED_ShowNum(56, 2, tpme_skewing, 2, 16);

        delay_ms(200);
    }
    else if(key_lessen() == 1  && tpme_skewing > 0)
    {
        tpme_skewing -= 1;
        eeprom_dat[1] = tpme_skewing;
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);
        OLED_ShowNum(56, 2, tpme_skewing, 2, 16);

        delay_ms(200);
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
    static u16 dat;


    if(key_add() == 1 && set_sleep_time < 30)
    {
        set_sleep_time++;

        eeprom_dat[3] = set_sleep_time;
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);

        OLED_ShowNum(40, 2, set_sleep_time, 2, 16); //显示设置无状态自动休眠时长
    }
    else if(key_lessen() == 1 && set_sleep_time > 5)
    {
        set_sleep_time--;

        eeprom_dat[3] = set_sleep_time;
        Eeprom_updata(Start_addrs, &eeprom_dat, 4);

        OLED_ShowNum(40, 2, set_sleep_time, 2, 16); //显示设置无状态自动休眠时长
    }
    if(set_sleep_time < 1)//限制休眠时间大于一分钟
    {
        set_sleep_time = 1;
        OLED_ShowNum(40, 2, set_sleep_time, 2, 16); //显示设置无状态自动休眠时长
    }
    if(dat != sleep_time_s) //sleep_time_s改动时刷新数据
    {
        dat = sleep_time_s;
        OLED_ShowNum(0, 2, sleep_time_s, 3, 16);
    }
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
    OLED_Clear();  //清屏
    //****界面1固定显示字****//
    OLED_ShowChinese(50, 1, 0, 12); //℃
    OLED_ShowString(70, 2, "Error", 8);	//功率百分比%
    OLED_ShowString(70, 0, "power", 8);	//功率百分比%
    OLED_ShowString(120, 2, "%", 8);
    OLED_ShowString(120, 0, "%", 8);
    OLED_ShowNum(15, 0, expect_temp, 3, 22);  //显示期望温度
    /*************************/
    while(z == 0)  //界面1
    {
        show_1();
        if(key_mode() == 1) z++;
        if((sleep_time_s / 60) >= set_sleep_time)  sleep_mode(); //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM
    }
    OLED_Clear();//清屏
    while(z == 1)  //界面2 设置供电电压
    {
        bit f = 0;
        if(!f)
        {
            f = 1;
            OLED_ShowChinese(0, 0, 13, 12); //当前电压
            OLED_ShowChinese(14, 0, 14, 12);
            OLED_ShowChinese(28, 0, 17, 12);
            OLED_ShowChinese(42, 0, 18, 12);
            OLED_ShowString(55, 0, ":", 16);

            OLED_ShowChinese(0, 2, 15, 12); //输入电压
            OLED_ShowChinese(14, 2, 16, 12);
            OLED_ShowChinese(28, 2, 17, 12);
            OLED_ShowChinese(42, 2, 18, 12);
            OLED_ShowString( 55, 2, ":", 16);
            OLED_ShowNum(70, 2, eeprom_dat[0], 2, 16);
            // OLED_ShowNum(70, 2, read_rom(Start_addrs), 2, 16);
            OLED_ShowString(110, 0, "mV", 16);
            OLED_ShowString(110, 2, "V", 16);
        }
        show_2();
        if(key_mode() == 1) z++;
        power_record();

        if((sleep_time_s / 60) >= set_sleep_time)  sleep_mode(); //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM
    }
    OLED_Clear();//清屏
    while(z == 2)  //界面3
    {
        bit f = 0;
        if(!f)
        {
            f = 1;
            OLED_ShowChinese(20, 0, 19, 12);  // 温(0) 度(1) 偏(2) 移(3) 校(4) 准(5)
            OLED_ShowChinese(34, 0, 20, 12);
            OLED_ShowChinese(48, 0, 21, 12);
            OLED_ShowChinese(62, 0, 22, 12);
            OLED_ShowChinese(76, 0, 23, 12);
            OLED_ShowChinese(90, 0, 24, 12);
            OLED_ShowString(40, 2, "+", 16);
            OLED_ShowChinese(80, 2, 0, 12); //℃
            OLED_ShowNum(56, 2, tpme_skewing, 2, 16);
        }
        show_3();
        if(key_mode() == 1) z++;
    }
    OLED_Clear();		//清屏
    while(z == 3) //界面4
    {

        OLED_ShowChinese( 0, 0, 10, 12); //设置无操作自动休眠
        OLED_ShowChinese(14, 0, 11, 12); //
        OLED_ShowChinese(28, 0, 1, 12); //
        OLED_ShowChinese(42, 0, 2, 12); //
        OLED_ShowChinese(56, 0, 3, 12); //
        OLED_ShowChinese(70, 0, 4, 12); //
        OLED_ShowChinese(84, 0, 5, 12); //
        OLED_ShowChinese(98, 0, 6, 12); //
        OLED_ShowChinese(112, 0, 7, 12); //

        OLED_ShowString(70, 2, "Min", 16);	//min
        OLED_ShowNum(40, 2, set_sleep_time, 2, 16); //显示设置无状态自动休眠时长
        show_4();

        if(key_mode() == 1) z++;
        if((sleep_time_s / 60) >= set_sleep_time)  sleep_mode(); //计时时间大于设置休眠时间，进入休眠模式，期间关闭PWM
    }

    if(z > 3) z = 0;

}

void interface_show1_Init(void)
{
    OLED_Clear();  //清屏
    //****界面1固定显示字****//
    OLED_ShowChinese(50, 1, 0, 12); //℃
    OLED_ShowString(70, 2, "Error", 8);	//功率百分比%
    OLED_ShowString(70, 0, "power", 8);	//功率百分比%
    OLED_ShowString(120, 2, "%", 8);
    OLED_ShowString(120, 0, "%", 8);
    OLED_ShowNum(15, 0, expect_temp, 3, 22);  //显示期望温度
    /*************************/
}
