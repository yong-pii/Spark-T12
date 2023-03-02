#include "Ch224d.h"


/*************************外部变量声明******************************/
extern u16 Start_addrs;
extern u8  xdata  eeprom_dat[10];
/*******************************************************************/


/* 0x0040 eeprom 为电压选择记录地址*/
/***********************************************************
*@fuction	:power
*@brief		:控制供电电压
*@param		:5/9/12/15/20
*@return	:void
*@author	:--xptx
*@date		:2022-10-02
***********************************************************/
void power_Init(void)
{
    u8 i;
    i = eeprom_dat[0]; //读取数据

    if(i == 5 || i == 9 || i == 12 || i == 15 || i == 20) //数据校验
        power(i);
    else
    {
        eeprom_dat[0] = 5;
        Eeprom_data_Init(Start_addrs, &eeprom_dat, 4);
        power(i);
    }
}

/***********************************************************
*@fuction	:power_record
*@brief		:  更新记忆供电电压
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-11-13
***********************************************************/

void power_record(void)
{
    u8 i;  //临时变量
    EA = 0; //关闭中断
    //    i = (u8)read_rom(power_addrs); //读取数据//读取记录数据
    if( (v_data_out() != i) && (v_data_out() != 0))    //对比,io设置电压值与存入电压值不相等且io设置电压值不等于0
        //        write_rom(power_addrs, (u16)v_data_out()); //写入io设置电压值
        EA = 1; //打开中断
    //重新记忆
}

void power(u8 x)
{
    if(x == 5)
    {
        CFG1 = 1;
        CFG2 = CFG3 = 0;
    }
    else if(x == 9)
    {
        CFG1 = CFG2 = CFG3 = 0;
    }
    else if(x == 12)
    {
        CFG1 = CFG2 = 0;
        CFG3 = 1;
    }
    else if(x == 15)
    {
        CFG1 = 0;
        CFG2 = CFG3 = 1;
    }
    else if(x == 20)
    {
        CFG1 = 0;
        CFG2 = 1;
        CFG3 = 0;
    }
}

/***********************************************************
*@fuction	:v_data_out
*@brief		:根据GPIO状态返回当前电压数据
*@param		:--void
*@return	:Current supply voltage
*@author	:--xptx
*@date		:2022-11-20
***********************************************************/

u8 v_data_out(void)
{
    u8 i;
    if( CFG1 == 0 && CFG2 == 1 && CFG3 == 0)  i = 20;
    else if( CFG1 == 0 && CFG2 == 1 && CFG3 == 1)  i = 15;
    else if( CFG1 == 0 && CFG2 == 0 && CFG3 == 1)  i = 12;
    else if( CFG1 == 0 && CFG2 == 0 && CFG3 == 0)  i = 9;
    else if( CFG1 == 1 && CFG2 == 0 && CFG3 == 0)  i = 5;
    else
        i = 0;
    return i;
}
