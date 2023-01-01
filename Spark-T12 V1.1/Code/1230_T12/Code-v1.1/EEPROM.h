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

#ifndef	__EEPROM_H
#define	__EEPROM_H

#include	"config.h"

#define		STC8X1K08	8
#define		STC8X1K16	16
#define		STC8XxK32	32
#define		STC8XxK60	60

//	选择MCU型号
#define	MCU_Type	STC8X1K08  //STC8X1K08, STC8X1K16, STC8XxK32, STC8XxK32, STC8XxK60

/************************** ISP/IAP *****************************

   型号    大小  扇区数  开始地址    结束地址   MOVC读偏移地址
STC8X1K08   4K   8扇区   0x0000  ~  0x0FFF       0x2000
STC8X1K16  12K   24扇区  0x0000  ~  0x2FFF       0x4000
STC8XxK32  32K   64扇区  0x0000  ~  0x7FFF       0x8000
STC8XxK60   4K   8扇区   0x0000  ~  0x0FFF       0xF000

*/

#if   (MCU_Type == STC8X1K08)
      #define   MOVC_ShiftAddress    0x2000
#elif (MCU_Type == STC8X1K16)
      #define   MOVC_ShiftAddress    0x4000
#elif (MCU_Type == STC8XxK32)
      #define   MOVC_ShiftAddress    0x8000
#elif (MCU_Type == STC8XxK60)
      #define   MOVC_ShiftAddress    0xF000
#else
      #define   MOVC_ShiftAddress    0xC000		//用户自定义
#endif


void	DisableEEPROM(void);
void 	EEPROM_read_n(u16 EE_address,u8 *DataAddress,u16 number);
void 	EEPROM_write_n(u16 EE_address,u8 *DataAddress,u16 number);
void	EEPROM_SectorErase(u16 EE_address);

u16 read_rom(u16 address);
void write_rom(u16 address,u16 Data_Address);  //16位 数据写入
#endif