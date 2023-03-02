#include <math.h>
#include <NTC.h>
/**
 * @brief
 *
 * @param _R1       当前温度下的电阻
 * @param _B        所使用的NTC电阻B值(datasheet里面有,例如3950)
 * @param _R2       T2温度下的电阻
 * @param _T2       一般是25℃
 * @return float    返回的就是当前温度(℃)
 */
float resistanceToTemperature(float _R1, float _B, float _R2, float _T2)
{
    return (1.0 / ((1.0 / _B) * log(_R1 / _R2) + (1.0 / (_T2 + 273.15))) - 273.15);
}

/***********************************************************
*@fuction	:NTC_outres
*@brief		: 电阻串联反求下串联NTC电阻值
*@param		:Vcc   电源电压
*@param		:VR    分压电压值
*@param		:R1    上串联电阻值
*@return	:u16   返回NTC电阻值
*@author	:--xptx
*@date		:2023-02-22
***********************************************************/

float NTC_outres(float Vcc, float VR, float R1)
{

    return ( (VR * R1) / (Vcc - VR) );

}


void bp(u8 t)
{
    u8 i;
    for(i = 0; i < t; i++)
    {
        beep = 1;
        Delay125us();
        beep = 0;
        Delay125us();
    }
}


/***********************************************************
*@fuction	:temp_protect
*@brief		:温度限制保护
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2023-02-23
***********************************************************/

void temp_protect(u8 ms_2, NTC__temp)
{
    if((85 - NTC__temp) <= 5)
    {
        switch (85 - NTC__temp)
        {
        case 0:
            while(1)
            {
                EA = 0;
                P12 = 0;
                OLED_Clear();//清屏
                OLED_Clear();//清屏
                OLED_Clear();//清屏
                while(1)
                {
                    bp(80);
                    OLED_ShowString(30, 1, "over temp !", 16);
                    //                    beep = 1;
                    //                    Delay125us();
                    //                    beep = 0;
                    //                    Delay125us();
                }
            }
            break;
        case 1:
            if(ms_2 % 50 == 0)//5hz
            {
                bp(80);
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
                //                Delay125us();
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
            }
            break;
        case 2:
            if(ms_2 % 50 == 0)//10hz
            {
                bp(80);
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
                //                Delay125us();
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
            }
            break;
        case 3:
            if(ms_2 % 100 == 0)//5hz
            {
                bp(80);
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
                //                Delay125us();
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
            }
            break;
        case 4:
            if(ms_2 % 250 == 0)//2hz
            {
                bp(80);
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
                //                Delay125us();
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
            }
            break;
        case 5:
            if(ms_2 % 500 == 0)//1hz
            {
                bp(80);
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
                //                Delay125us();
                //                beep = 1;
                //                Delay125us();
                //                beep = 0;
            }
            break;
        }
    }
}

