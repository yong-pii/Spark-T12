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

#ifndef		__CONFIG_H
#define		__CONFIG_H

/*********************************************************/

#define MAIN_Fosc		30000000L	//定义主时钟
//#define MAIN_Fosc		12000000L	//定义主时钟
//#define MAIN_Fosc		11059200L	//定义主时钟
//#define MAIN_Fosc		 5529600L	//定义主时钟
//#define MAIN_Fosc		24000000L	//定义主时钟


/*********************************************************/

#include	"STC8xxxx.H"
#include	"delay.h"
#include	"timer.h"
#include	"GPIO.h"
#include "oled.h"
//#include "bmp.h"
#include	"adc.h"
#include "UART.h"
#include 	"eeprom.h"
#include	"PWM.h"


#include	"beep.h"
#include  "key.h"
#include "interface.h"
#include "Ch224d.h"
#include "Spark_T12_PID.h"
#include "sleep.h"

#include <stdio.h>
#include <stdlib.h>

#define     Max_Length          3      //读写EEPROM缓冲长度

#endif
