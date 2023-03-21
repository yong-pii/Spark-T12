#include "sleep.h"

bit sleep_fig = 0;
u16 sleep_time_s = 0, set_sleep_time = 5; //休眠计时，设置休眠时间


extern u8 z;
extern u16 xx, yy, zz;

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
    i += 10;
    if(SC7A20_signal() == 1) sleep_time_s = 0; //陀螺仪检测到动作说明烙铁发生动作，休眠计时清零

    if((i % 1000) == 0)
    {
        OLED_Clear();//清屏
        OLED_ShowChinese( i / 100 + 0, 1, 6, 12); //休
        OLED_ShowChinese(i / 100 + 14, 1, 7, 12); //眠
        OLED_ShowChinese(i / 100 + 28, 1, 12, 12); //中
    }
    delay_ms(10);

    if(i >= 12001) i = 0;
}

bit SC7A20_signal(void)
{
    if(xx > 80 && yy > 80 && zz > 80)
    {
        Beep(ON);
        delay_ms(50);
        Beep(OFF);
        return 1;
    }
    else return 0;


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
    delay_ms(10);
    sleep_fig = 1; //休眠标志位置一
    P12 = 0; //拉低pwm输出IO口
    while(1)
    {
        sleep_show();  //休眠显示界面
        if(SC7A20_signal() == 1)
        {
            sleep_time_s = 0; //陀螺仪检测到动作说明烙铁发生动作，休眠计时清零
            z = 0; //返回界面1
            interface_show1_Init();  //初始化界面1
            break;
        }
    }
    sleep_fig = 0; //休眠结束，标志位置0
}

void sleep_forced(int sleep) {
    if (1 == sleep) {
        OLED_Clear();//清屏
        delay_ms(10);
        sleep_fig = 1; //休眠标志位置一
        P12 = 0; //拉低pwm输出IO口
        sleep_show();  //休眠显示界面
    } else {
        sleep_fig = 0; //休眠结束，标志位置0
    }
}