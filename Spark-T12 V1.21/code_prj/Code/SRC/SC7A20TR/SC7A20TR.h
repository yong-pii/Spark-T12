#ifndef __SC7A20_H
#define __SC7A20_H

#include "config.h"
//#include	"STC8A_Delay.h"
//#include "delay.h"

#define SC7A20_I2C_WADDR 0x32	//I2C写地址：7位I2C地址+一位写
#define SC7A20_I2C_RADDR 0x33	//I2C写地址：7位I2C地址+一位读

void SC7A20_Init(void);  //SC7A20初始化
int SC7A20_Get_ACCD(u8 accd_lsb,u8 accd_msb);  //SC7A20获取加速度值
void SC7A20_GetInfo(void);  //SC7A20获取xyz轴加速度值
int SC7A20_Get_ACCD(u8 accd_lsb,u8 accd_msb);


void SC7A20_Read_Byte(u8 RAddr, u8 *RData);

#endif  
