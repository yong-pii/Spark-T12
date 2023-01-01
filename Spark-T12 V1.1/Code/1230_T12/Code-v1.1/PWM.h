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

#ifndef __PWM_H
#define __PWM_H	 

#include	"config.h"

//#define ENO1P       0x01
//#define ENO1N       0x02
#define ENO2P       0x04
//#define ENO2N       0x08
//#define ENO3P       0x10
//#define ENO3N       0x20
//#define ENO4P       0x40
//#define ENO4N       0x80

//#define ENO5P       0x01
//#define ENO6P       0x04
//#define ENO7P       0x10
//#define ENO8P       0x40

#define	PWMA	1
//#define	PWMB	2

//#define	PWM1_SW_P10_P11		0
//#define	PWM1_SW_P20_P21		1
//#define	PWM1_SW_P60_P61		2

#define	PWM2_SW_P12_P13		0
//#define	PWM2_SW_P22_P23		(1<<2)
//#define	PWM2_SW_P62_P63		(2<<2)

//#define	PWM3_SW_P14_P15		0
//#define	PWM3_SW_P24_P25		(1<<4)
//#define	PWM3_SW_P64_P65		(2<<4)

//#define	PWM4_SW_P16_P17		0
//#define	PWM4_SW_P26_P27		(1<<6)
//#define	PWM4_SW_P66_P67		(2<<6)
//#define	PWM4_SW_P34_P33		(3<<6)

//#define	PWM5_SW_P20				0
//#define	PWM5_SW_P17				1
//#define	PWM5_SW_P00				2
//#define	PWM5_SW_P74				3

//#define	PWM6_SW_P21				0
//#define	PWM6_SW_P54				(1<<2)
//#define	PWM6_SW_P01				(2<<2)
//#define	PWM6_SW_P75				(3<<2)

//#define	PWM7_SW_P22				0
//#define	PWM7_SW_P33				(1<<4)
//#define	PWM7_SW_P02				(2<<4)
//#define	PWM7_SW_P76				(3<<4)

//#define	PWM8_SW_P23				0
//#define	PWM8_SW_P34				(1<<6)
//#define	PWM8_SW_P03				(2<<6)
//#define	PWM8_SW_P77				(3<<6)

typedef struct
{ 
//	u8	PWM1_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
	u8	PWM2_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
//	u8	PWM3_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
//	u8	PWM4_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
//	u8	PWM5_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
//	u8	PWM6_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
//	u8	PWM7_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2
//	u8	PWM8_Mode;			//模式,   CCMRn_FREEZE,CCMRn_MATCH_VALID,CCMRn_MATCH_INVALID,CCMRn_ROLLOVER,CCMRn_FORCE_INVALID,CCMRn_FORCE_VALID,CCMRn_PWM_MODE1,CCMRn_PWM_MODE2

	u16	PWM_Period;			//周期时间,   0~65535
//	u16	PWM1_Duty;			//PWM1占空比时间, 0~Period
	u16	PWM2_Duty;			//PWM2占空比时间, 0~Period
//	u16	PWM3_Duty;			//PWM3占空比时间, 0~Period
//	u16	PWM4_Duty;			//PWM4占空比时间, 0~Period
//	u16	PWM5_Duty;			//PWM5占空比时间, 0~Period
//	u16	PWM6_Duty;			//PWM6占空比时间, 0~Period
//	u16	PWM7_Duty;			//PWM7占空比时间, 0~Period
//	u16	PWM8_Duty;			//PWM8占空比时间, 0~Period
	u8	PWM_DeadTime;		//死区发生器设置, 0~255

//	u8	PWM_CC1Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC1NEnable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
	u8	PWM_CC2Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
	u8	PWM_CC2NEnable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC3Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC3NEnable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC4Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC4NEnable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC5Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC6Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC7Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE
//	u8	PWM_CC8Enable;	//开启输入捕获/比较输出,  ENABLE,DISABLE

	u8	PWM_Reload;			//输出比较的预装载使能,   ENABLE,DISABLE
	u8	PWM_Fast;				//输出比较快速功能使能,   ENABLE,DISABLE

//	u8	PWM1_SetPriority;	//设置PWM1优先级,   Priority_0,Priority_1,Priority_2,Priority_3
	u8	PWM2_SetPriority;	//设置PWM2优先级,   Priority_0,Priority_1,Priority_2,Priority_3
//	u8	PWM3_SetPriority;	//设置PWM3优先级,   Priority_0,Priority_1,Priority_2,Priority_3
//	u8	PWM4_SetPriority;	//设置PWM4优先级,   Priority_0,Priority_1,Priority_2,Priority_3
//	u8	PWM5_SetPriority;	//设置PWM4优先级,   Priority_0,Priority_1,Priority_2,Priority_3

	u8	PWM_EnoSelect;	//输出通道选择,	ENO1P,ENO1N,ENO2P,ENO2N,ENO3P,ENO3N,ENO4P,ENO4N / ENO5P,ENO6P,ENO7P,ENO8P
	u8	PWM_PreLoad;		//预装载,     ENABLE,DISABLE
	u8	PWM_PS_SW;			//切换端口,   PWM1_SW_P10_P11,PWM1_SW_P20_P21,PWM1_SW_P60_P61
	u8	PWM_CEN_Enable;	//使能计数器, ENABLE,DISABLE

	u8	PWM_BrakeEnable;	//刹车输入使能,  ENABLE,DISABLE
	u8	PWM_MainOutEnable;//主输出使能,  ENABLE,DISABLE
} PWMx_InitDefine; 

typedef struct
{ 
	u16	PWM1_Duty;			//PWM1占空比时间, 0~Period
	u16	PWM2_Duty;			//PWM2占空比时间, 0~Period
	u16	PWM3_Duty;			//PWM3占空比时间, 0~Period
	u16	PWM4_Duty;			//PWM4占空比时间, 0~Period
	u16	PWM5_Duty;			//PWM5占空比时间, 0~Period
	u16	PWM6_Duty;			//PWM6占空比时间, 0~Period
	u16	PWM7_Duty;			//PWM7占空比时间, 0~Period
	u16	PWM8_Duty;			//PWM8占空比时间, 0~Period
} PWMx_Duty; 

u8	PWM_Configuration(u8 PWM, PWMx_InitDefine *PWMx);
void UpdatePwm(u8 PWM, PWMx_Duty *PWMx);

#endif

