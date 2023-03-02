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

#ifndef	_STC8xxxx_H
#define	_STC8xxxx_H

#include <intrins.h>

/*  BYTE Registers  */
sfr P0    = 0x80;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr	S4CON = 0x84;
sfr	S4BUF = 0x85;
sfr PCON  = 0x87;

sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr	AUXR = 0x8E;
sfr WAKE_CLKO = 0x8F;
sfr INT_CLKO  = 0x8F;

sfr P1    = 0x90;
sfr P1M1  = 0x91;	//P1M1.n,P1M0.n 	=00--->Standard,	01--->push-pull		实际上1T的都一样
sfr P1M0  = 0x92;	//					=10--->pure input,	11--->open drain
sfr P0M1  = 0x93;	//P0M1.n,P0M0.n 	=00--->Standard,	01--->push-pull
sfr P0M0  = 0x94;	//					=10--->pure input,	11--->open drain
sfr P2M1  = 0x95;	//P2M1.n,P2M0.n 	=00--->Standard,	01--->push-pull
sfr P2M0  = 0x96;	//					=10--->pure input,	11--->open drain
//sfr PCON2 = 0x97;
//sfr	AUXR2 = 0x97;

sfr SCON  = 0x98;
sfr SBUF  = 0x99;
sfr S2CON = 0x9A;	//
sfr S2BUF = 0x9B;	//

sfr P2    = 0xA0;
sfr BUS_SPEED = 0xA1;
sfr P_SW1 = 0xA2;

sfr IE    = 0xA8;
sfr SADDR = 0xA9;
sfr WKTCL = 0xAA;	//唤醒定时器低字节
sfr WKTCH = 0xAB;	//唤醒定时器高字节
sfr	S3CON = 0xAC;
sfr S3BUF = 0xAD;
sfr TA    = 0xAE;
sfr IE2   = 0xAF;

sfr P3    = 0xB0;
sfr P3M1  = 0xB1;	//P3M1.n,P3M0.n 	=00--->Standard,	01--->push-pull
sfr P3M0  = 0xB2;	//					=10--->pure input,	11--->open drain
sfr P4M1  = 0xB3;	//P4M1.n,P4M0.n 	=00--->Standard,	01--->push-pull
sfr P4M0  = 0xB4;	//					=10--->pure input,	11--->open drain
sfr IP2   = 0xB5;
sfr IP2H  = 0xB6;
sfr IPH   = 0xB7;

sfr IP        = 0xB8;
sfr SADEN     = 0xB9;
sfr	P_SW2     = 0xBA;
sfr	VOCTRL    = 0xBB;
sfr ADC_CONTR = 0xBC;	//ADC控制寄存器
sfr ADC_RES   = 0xBD;	//ADC结果高字节
sfr ADC_RESL  = 0xBE;	//ADC结果低字节

sfr P4        = 0xC0;
sfr WDT_CONTR = 0xC1;

sfr IAP_DATA  = 0xC2;
sfr IAP_ADDRH = 0xC3;
sfr IAP_ADDRL = 0xC4;
sfr IAP_CMD   = 0xC5;
sfr IAP_TRIG  = 0xC6;
sfr IAP_CONTR = 0xC7;

sfr ISP_DATA  = 0xC2;
sfr ISP_ADDRH = 0xC3;
sfr ISP_ADDRL = 0xC4;
sfr ISP_CMD   = 0xC5;
sfr ISP_TRIG  = 0xC6;
sfr ISP_CONTR = 0xC7;

sfr P5     = 0xC8;	//
sfr P5M1   = 0xC9;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
sfr P5M0   = 0xCA;	//					=10--->pure input,	11--->open drain
sfr P6M1   = 0xCB;	//	P5M1.n,P5M0.n 	=00--->Standard,	01--->push-pull
sfr P6M0   = 0xCC;	//					=10--->pure input,	11--->open drain
sfr SPSTAT = 0xCD;	//
sfr SPCTL  = 0xCE;	//
sfr SPDAT  = 0xCF;	//

sfr PSW    = 0xD0;
sfr	T4T3M  = 0xD1;
sfr	T4H    = 0xD2;
sfr	T4L    = 0xD3;
sfr	T3H    = 0xD4;
sfr	T3L    = 0xD5;
sfr	T2H    = 0xD6;
sfr	T2L    = 0xD7;

sfr	TH4    = 0xD2;
sfr	TL4    = 0xD3;
sfr	TH3    = 0xD4;
sfr	TL3    = 0xD5;
sfr	TH2    = 0xD6;
sfr	TL2    = 0xD7;

sfr CCON   = 0xD8;	//
sfr CMOD   = 0xD9;	//
sfr CCAPM0 = 0xDA;	//PCA模块0的工作模式寄存器。
sfr CCAPM1 = 0xDB;	//PCA模块1的工作模式寄存器。
sfr CCAPM2 = 0xDC;	//PCA模块2的工作模式寄存器。
//sfr CCAPM3 = 0xDD;	//PCA模块3的工作模式寄存器。
sfr USBCLK = 0xDC;
sfr	ADCCFG = 0xDE;	//
sfr	IP3    = 0xDF;	//中断优先级寄存器

sfr ACC    = 0xE0;
sfr	P7M1   = 0xE1;
sfr	P7M0   = 0xE2;
sfr	DPS    = 0xE3;
sfr	DPL1   = 0xE4;
sfr	DPH1   = 0xE5;
sfr	CMPCR1 = 0xE6;
sfr	CMPCR2 = 0xE7;

sfr	P6     = 0xE8;
sfr CL     = 0xE9;	//
sfr CCAP0L = 0xEA;	//PCA模块0的捕捉/比较寄存器低8位。
sfr CCAP1L = 0xEB;	//PCA模块1的捕捉/比较寄存器低8位。
sfr CCAP2L = 0xEC;	//PCA模块2的捕捉/比较寄存器低8位。
//sfr CCAP3L = 0xED;	//PCA模块3的捕捉/比较寄存器低8位。
sfr USBDAT   = 0xEC;
sfr IP3H     = 0xEE;
sfr	AUXINTIF = 0xEF;	//辅助中断标志 B6-INT4IF, B5-INT3IF, B4-INT2IF, B2-T4IF, B1-T3IF, B0-T2IF

sfr B        = 0xF0;
sfr	PWMSET   = 0xF1;	//增强型PWM全局配置寄存器
sfr PCA_PWM0 = 0xF2;	//PCA模块0 PWM寄存器。
sfr PCA_PWM1 = 0xF3;	//PCA模块1 PWM寄存器。
sfr PCA_PWM2 = 0xF4;	//PCA模块2 PWM寄存器。
//sfr PCA_PWM3 = 0xF5;	//PCA模块3 PWM寄存器。
sfr	PWMCFG01 = 0xF6;	//增强型PWM配置寄存器
sfr	PWMCFG23 = 0xF7;	//增强型PWM配置寄存器
sfr USBCON  = 0xF4;
sfr IAP_TPS = 0xF5;

sfr	P7     = 0xF8;
sfr CH     = 0xF9;
sfr CCAP0H = 0xFA;		//PCA模块0的捕捉/比较寄存器高8位。
sfr CCAP1H = 0xFB;		//PCA模块1的捕捉/比较寄存器高8位。
sfr CCAP2H = 0xFC;		//PCA模块2的捕捉/比较寄存器高8位。
//sfr CCAP3H = 0xFD;		//PCA模块3的捕捉/比较寄存器高8位。
sfr	PWMCFG45 = 0xFE;	//增强型PWM配置寄存器
sfr USBADR = 0xFC;
sfr	RSTCFG = 0xFF;		//


//                                     7    6    5    4    3     2       1       0      Reset Value
//INT_CLKO:  中断与时钟输出控制寄存器  -   EX4  EX3  EX2   -   T2CLKO  T1CLKO  T0CLKO    0000,0000
#define	INT4_Enable()	INT_CLKO |= (1 << 6)
#define	INT3_Enable()	INT_CLKO |= (1 << 5)	
#define	INT2_Enable()	INT_CLKO |= (1 << 4)	
#define	INT1_Enable()	EX1 = 1
#define	INT0_Enable()	EX0 = 1

#define	INT4_Disable()	INT_CLKO &= ~(1 << 6)
#define	INT3_Disable()	INT_CLKO &= ~(1 << 5)	
#define	INT2_Disable()	INT_CLKO &= ~(1 << 4)	
#define	INT1_Disable()	EX1 = 0
#define	INT0_Disable()	EX0 = 0

//                               7    6       5       4      3    2     1     0      Reset Value
//AUXINTIF:  辅助中断标志寄存器  -  INT4IF  INT3IF  INT2IF   -   T4IF  T3IF  T2IF    0000,0000
#define	INT4IF	0x40
#define	INT3IF	0x20
#define	INT2IF	0x10
#define	T4IF	0x04
#define	T3IF	0x02
#define	T2IF	0x01

#define	INT4_Clear()	AUXINTIF &= ~INT4IF		/* 清除外中断4标志位 */
#define	INT3_Clear()	AUXINTIF &= ~INT3IF		/* 清除外中断3标志位 */
#define	INT2_Clear()	AUXINTIF &= ~INT2IF		/* 清除外中断2标志位 */
#define	INT1_Clear()	IE1 = 0					/* 清除外中断1标志位 */
#define	INT0_Clear()	IE0 = 0					/* 清除外中断0标志位 */

#define	INT0_Fall()		IT0 = 1		/* INT0 下降沿中断           */
#define	INT0_RiseFall()	IT0 = 0		/* INT0 下降沿上升沿均中断   */
#define	INT1_Fall()		IT1 = 1		/* INT1 下降沿中断           */
#define	INT1_RiseFall()	IT0 = 0		/* INT1 下降沿上升沿均中断   */


//===============================================================
#define	EAXSFR()		P_SW2 |=  0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展SFR(XSFR) */
#define	EAXRAM()		P_SW2 &= ~0x80		/* MOVX A,@DPTR/MOVX @DPTR,A指令的操作对象为扩展RAM(XRAM) */

#define	I2C_USE_P14P15()	P_SW2 &= ~0x30						/* 将I2C切换到P1.4(SDA) P1.5(SCL)(上电默认).*/
#define	I2C_USE_P24P25()	P_SW2  = (P_SW2 & ~0x30) | 0x10		/* 将I2C切换到P2.4(SDA) P2.5(SCL).*/
#define	I2C_USE_P76P77()	P_SW2  = (P_SW2 & ~0x30) | 0x20		/* 将I2C切换到P7.6(SDA) P7.7(SCL).*/
#define	I2C_USE_P33P32()	P_SW2 |= 0x30						/* 将I2C切换到P3.3(SDA) P3.2(SCL).*/

#define CLKSEL      (*(unsigned char volatile xdata *)0xfe00)
#define	CKSEL		(*(unsigned char volatile xdata *)0xfe00)	/* 主时钟源选择    */
#define	CLKDIV		(*(unsigned char volatile xdata *)0xfe01)	/* 主时钟分频      */
#define	IRC24MCR	(*(unsigned char volatile xdata *)0xfe02)	/* IRC 24MHZ控制   */
#define	XOSCCR		(*(unsigned char volatile xdata *)0xfe03)	/* XOSC控制        */
#define	IRC32KCR	(*(unsigned char volatile xdata *)0xfe04)	/* IRC 32KHZ控制   */
#define MCLKOCR   (*(unsigned char volatile xdata *)0xfe05)
#define IRCDB     (*(unsigned char volatile xdata *)0xfe06)
#define X32KCR    (*(unsigned char volatile xdata *)0xfe08)

#define	MainFosc_IRC24M()	CKSEL = (CKSEL & ~0x03)			/* 选择内部24MHZ时钟 */
#define	MainFosc_XTAL()		CKSEL = (CKSEL & ~0x03) | 0x01	/* 选择外部晶振或时钟 */
#define	MainFosc_IRC32K()	CKSEL =  CKSEL | 0x03			/* 选择内部32K时钟 */
#define	EXT_CLOCK()			XOSCCR = 0x80					/* 选择外部时钟 */
#define	EXT_CRYSTAL()		XOSCCR = 0xC0					/* 选择外部晶振 */


#define	P0PU		(*(unsigned char volatile xdata *)0xfe10)	/* P0 4.1K Pull Up Enable  */
#define	P1PU		(*(unsigned char volatile xdata *)0xfe11)	/* P1 4.1K Pull Up Enable  */
#define	P2PU		(*(unsigned char volatile xdata *)0xfe12)	/* P2 4.1K Pull Up Enable  */
#define	P3PU		(*(unsigned char volatile xdata *)0xfe13)	/* P3 4.1K Pull Up Enable  */
#define	P4PU		(*(unsigned char volatile xdata *)0xfe14)	/* P4 4.1K Pull Up Enable  */
#define	P5PU		(*(unsigned char volatile xdata *)0xfe15)	/* P5 4.1K Pull Up Enable  */
#define	P6PU		(*(unsigned char volatile xdata *)0xfe16)	/* P6 4.1K Pull Up Enable  */
#define	P7PU		(*(unsigned char volatile xdata *)0xfe17)	/* P7 4.1K Pull Up Enable  */

#define	P0NCS		(*(unsigned char volatile xdata *)0xfe18)	/* P0 Non Schmit Trigger  0: 使能端口施密特触发功能(默认), 1: 禁止  */
#define	P1NCS		(*(unsigned char volatile xdata *)0xfe19)	/* P1 Non Schmit Trigger  */
#define	P2NCS		(*(unsigned char volatile xdata *)0xfe1a)	/* P2 Non Schmit Trigger  */
#define	P3NCS		(*(unsigned char volatile xdata *)0xfe1b)	/* P3 Non Schmit Trigger  */
#define	P4NCS		(*(unsigned char volatile xdata *)0xfe1c)	/* P4 Non Schmit Trigger  */
#define	P5NCS		(*(unsigned char volatile xdata *)0xfe1d)	/* P5 Non Schmit Trigger  */
#define	P6NCS		(*(unsigned char volatile xdata *)0xfe1e)	/* P6 Non Schmit Trigger  */
#define	P7NCS		(*(unsigned char volatile xdata *)0xfe1f)	/* P7 Non Schmit Trigger  */

#define P0SR    (*(unsigned char volatile xdata *)0xfe20) /* 端口电平转换速度  0: 快, 1: 慢(默认)  */
#define P1SR    (*(unsigned char volatile xdata *)0xfe21)
#define P2SR    (*(unsigned char volatile xdata *)0xfe22)
#define P3SR    (*(unsigned char volatile xdata *)0xfe23)
#define P4SR    (*(unsigned char volatile xdata *)0xfe24)
#define P5SR    (*(unsigned char volatile xdata *)0xfe25)
#define P6SR    (*(unsigned char volatile xdata *)0xfe26)
#define P7SR    (*(unsigned char volatile xdata *)0xfe27)

#define P0DR    (*(unsigned char volatile xdata *)0xfe28) /* 端口驱动电流控制  0: 增强驱动能力, 1: 一般驱动能力(默认)  */
#define P1DR    (*(unsigned char volatile xdata *)0xfe29)
#define P2DR    (*(unsigned char volatile xdata *)0xfe2a)
#define P3DR    (*(unsigned char volatile xdata *)0xfe2b)
#define P4DR    (*(unsigned char volatile xdata *)0xfe2c)
#define P5DR    (*(unsigned char volatile xdata *)0xfe2d)
#define P6DR    (*(unsigned char volatile xdata *)0xfe2e)
#define P7DR    (*(unsigned char volatile xdata *)0xfe2f)

#define P0IE    (*(unsigned char volatile xdata *)0xfe30)/* 端口数字信号输入使能  0: 禁止数字信号输入, 1: 使能数字信号输入(默认)  */
#define P1IE    (*(unsigned char volatile xdata *)0xfe31)
#define P2IE    (*(unsigned char volatile xdata *)0xfe32)
#define P3IE    (*(unsigned char volatile xdata *)0xfe33)
#define P4IE    (*(unsigned char volatile xdata *)0xfe34)
#define P5IE    (*(unsigned char volatile xdata *)0xfe35)
#define P6IE    (*(unsigned char volatile xdata *)0xfe36)
#define P7IE    (*(unsigned char volatile xdata *)0xfe37)

#define	I2CCFG		(*(unsigned char volatile xdata *)0xfe80)	/*   */
#define	I2CMSCR		(*(unsigned char volatile xdata *)0xfe81)	/*   */
#define	I2CMSST		(*(unsigned char volatile xdata *)0xfe82)	/*   */
#define	I2CSLCR		(*(unsigned char volatile xdata *)0xfe83)	/*   */
#define	I2CSLST		(*(unsigned char volatile xdata *)0xfe84)	/*   */
#define	I2CSLADR	(*(unsigned char volatile xdata *)0xfe85)	/*   */
#define	I2CTXD		(*(unsigned char volatile xdata *)0xfe86)	/*   */
#define	I2CRXD		(*(unsigned char volatile xdata *)0xfe87)	/*   */
#define I2CMSAUX  (*(unsigned char volatile xdata *)0xfe88)

#define TM2PS     (*(unsigned char volatile xdata *)0xfea2)
#define TM3PS     (*(unsigned char volatile xdata *)0xfea3)
#define TM4PS     (*(unsigned char volatile xdata *)0xfea4)
#define ADCTIM    (*(unsigned char volatile xdata *)0xfea8)
#define T3T4PIN   (*(unsigned char volatile xdata *)0xfeac)

#define PWMA_ETRPS (*(unsigned char volatile xdata *)0xfeb0)
#define PWMA_ENO   (*(unsigned char volatile xdata *)0xfeb1)
#define PWMA_PS    (*(unsigned char volatile xdata *)0xfeb2)
#define PWMA_IOAUX (*(unsigned char volatile xdata *)0xfeb3)
#define PWMB_ETRPS (*(unsigned char volatile xdata *)0xfeb4)
#define PWMB_ENO   (*(unsigned char volatile xdata *)0xfeb5)
#define PWMB_PS    (*(unsigned char volatile xdata *)0xfeb6)
#define PWMB_IOAUX (*(unsigned char volatile xdata *)0xfeb7)
#define PWMA_CR1   (*(unsigned char volatile xdata *)0xfec0)
#define PWMA_CR2   (*(unsigned char volatile xdata *)0xfec1)
#define PWMA_SMCR  (*(unsigned char volatile xdata *)0xfec2)
#define PWMA_ETR   (*(unsigned char volatile xdata *)0xfec3)
#define PWMA_IER   (*(unsigned char volatile xdata *)0xfec4)
#define PWMA_SR1   (*(unsigned char volatile xdata *)0xfec5)
#define PWMA_SR2   (*(unsigned char volatile xdata *)0xfec6)
#define PWMA_EGR   (*(unsigned char volatile xdata *)0xfec7)
#define PWMA_CCMR1 (*(unsigned char volatile xdata *)0xfec8)
#define PWMA_CCMR2 (*(unsigned char volatile xdata *)0xfec9)
#define PWMA_CCMR3 (*(unsigned char volatile xdata *)0xfeca)
#define PWMA_CCMR4 (*(unsigned char volatile xdata *)0xfecb)
#define PWMA_CCER1 (*(unsigned char volatile xdata *)0xfecc)
#define PWMA_CCER2 (*(unsigned char volatile xdata *)0xfecd)
#define PWMA_CNTR  (*(unsigned int volatile xdata *)0xfece)
#define PWMA_CNTRH (*(unsigned char volatile xdata *)0xfece)
#define PWMA_CNTRL (*(unsigned char volatile xdata *)0xfecf)
#define PWMA_PSCR  (*(unsigned int volatile xdata *)0xfed0)
#define PWMA_PSCRH (*(unsigned char volatile xdata *)0xfed0)
#define PWMA_PSCRL (*(unsigned char volatile xdata *)0xfed1)
#define PWMA_ARR   (*(unsigned int volatile xdata *)0xfed2)
#define PWMA_ARRH  (*(unsigned char volatile xdata *)0xfed2)
#define PWMA_ARRL  (*(unsigned char volatile xdata *)0xfed3)
#define PWMA_RCR   (*(unsigned char volatile xdata *)0xfed4)
#define PWMA_CCR1  (*(unsigned int volatile xdata *)0xfed5)
#define PWMA_CCR1H (*(unsigned char volatile xdata *)0xfed5)
#define PWMA_CCR1L (*(unsigned char volatile xdata *)0xfed6)
#define PWMA_CCR2  (*(unsigned int volatile xdata *)0xfed7)
#define PWMA_CCR2H (*(unsigned char volatile xdata *)0xfed7)
#define PWMA_CCR2L (*(unsigned char volatile xdata *)0xfed8)
#define PWMA_CCR3  (*(unsigned int volatile xdata *)0xfed9)
#define PWMA_CCR3H (*(unsigned char volatile xdata *)0xfed9)
#define PWMA_CCR3L (*(unsigned char volatile xdata *)0xfeda)
#define PWMA_CCR4  (*(unsigned int volatile xdata *)0xfedb)
#define PWMA_CCR4H (*(unsigned char volatile xdata *)0xfedb)
#define PWMA_CCR4L (*(unsigned char volatile xdata *)0xfedc)
#define PWMA_BRK   (*(unsigned char volatile xdata *)0xfedd)
#define PWMA_DTR   (*(unsigned char volatile xdata *)0xfede)
#define PWMA_OISR  (*(unsigned char volatile xdata *)0xfedf)

#define PWMB_CR1   (*(unsigned char volatile xdata *)0xfee0)
#define PWMB_CR2   (*(unsigned char volatile xdata *)0xfee1)
#define PWMB_SMCR  (*(unsigned char volatile xdata *)0xfee2)
#define PWMB_ETR   (*(unsigned char volatile xdata *)0xfee3)
#define PWMB_IER   (*(unsigned char volatile xdata *)0xfee4)
#define PWMB_SR1   (*(unsigned char volatile xdata *)0xfee5)
#define PWMB_SR2   (*(unsigned char volatile xdata *)0xfee6)
#define PWMB_EGR   (*(unsigned char volatile xdata *)0xfee7)
#define PWMB_CCMR1 (*(unsigned char volatile xdata *)0xfee8)
#define PWMB_CCMR2 (*(unsigned char volatile xdata *)0xfee9)
#define PWMB_CCMR3 (*(unsigned char volatile xdata *)0xfeea)
#define PWMB_CCMR4 (*(unsigned char volatile xdata *)0xfeeb)
#define PWMB_CCER1 (*(unsigned char volatile xdata *)0xfeec)
#define PWMB_CCER2 (*(unsigned char volatile xdata *)0xfeed)
#define PWMB_CNTR  (*(unsigned int volatile xdata *)0xfeee)
#define PWMB_CNTRH (*(unsigned char volatile xdata *)0xfeee)
#define PWMB_CNTRL (*(unsigned char volatile xdata *)0xfeef)
#define PWMB_PSCR  (*(unsigned int volatile xdata *)0xfef0)
#define PWMB_PSCRH (*(unsigned char volatile xdata *)0xfef0)
#define PWMB_PSCRL (*(unsigned char volatile xdata *)0xfef1)
#define PWMB_ARR   (*(unsigned int volatile xdata *)0xfef2)
#define PWMB_ARRH  (*(unsigned char volatile xdata *)0xfef2)
#define PWMB_ARRL  (*(unsigned char volatile xdata *)0xfef3)
#define PWMB_RCR   (*(unsigned char volatile xdata *)0xfef4)
#define PWMB_CCR5  (*(unsigned int volatile xdata *)0xfef5)
#define PWMB_CCR5H (*(unsigned char volatile xdata *)0xfef5)
#define PWMB_CCR5L (*(unsigned char volatile xdata *)0xfef6)
#define PWMB_CCR6  (*(unsigned int volatile xdata *)0xfef7)
#define PWMB_CCR6H (*(unsigned char volatile xdata *)0xfef7)
#define PWMB_CCR6L (*(unsigned char volatile xdata *)0xfef8)
#define PWMB_CCR7  (*(unsigned int volatile xdata *)0xfef9)
#define PWMB_CCR7H (*(unsigned char volatile xdata *)0xfef9)
#define PWMB_CCR7L (*(unsigned char volatile xdata *)0xfefa)
#define PWMB_CCR8  (*(unsigned int volatile xdata *)0xfefb)
#define PWMB_CCR8H (*(unsigned char volatile xdata *)0xfefb)
#define PWMB_CCR8L (*(unsigned char volatile xdata *)0xfefc)
#define PWMB_BRK   (*(unsigned char volatile xdata *)0xfefd)
#define PWMB_DTR   (*(unsigned char volatile xdata *)0xfefe)
#define PWMB_OISR  (*(unsigned char volatile xdata *)0xfeff)

/////////////////////////////////////////////////
//FD00H-FDFFH
/////////////////////////////////////////////////

#define     PWM0C       (*(unsigned int volatile xdata *)0xff00)
#define     PWM0CH      (*(unsigned char volatile xdata *)0xff00)
#define     PWM0CL      (*(unsigned char volatile xdata *)0xff01)
#define     PWM0CKS     (*(unsigned char volatile xdata *)0xff02)
#define     PWM0TADC    (*(unsigned int volatile xdata *)0xff03)
#define     PWM0TADCH   (*(unsigned char volatile xdata *)0xff03)
#define     PWM0TADCL   (*(unsigned char volatile xdata *)0xff04)
#define     PWM0IF      (*(unsigned char volatile xdata *)0xff05)
#define     PWM0FDCR    (*(unsigned char volatile xdata *)0xff06)
#define     PWM00T1     (*(unsigned int volatile xdata *)0xff10)
#define     PWM00T1H    (*(unsigned char volatile xdata *)0xff10)
#define     PWM00T1L    (*(unsigned char volatile xdata *)0xff11)
#define     PWM00T2     (*(unsigned int volatile xdata *)0xff12)
#define     PWM00T2H    (*(unsigned char volatile xdata *)0xff12)
#define     PWM00T2L    (*(unsigned char volatile xdata *)0xff13)
#define     PWM00CR     (*(unsigned char volatile xdata *)0xff14)
#define     PWM00HLD    (*(unsigned char volatile xdata *)0xff15)
#define     PWM01T1     (*(unsigned int volatile xdata *)0xff18)
#define     PWM01T1H    (*(unsigned char volatile xdata *)0xff18)
#define     PWM01T1L    (*(unsigned char volatile xdata *)0xff19)
#define     PWM01T2    	(*(unsigned int volatile xdata *)0xff1a)
#define     PWM01T2H    (*(unsigned char volatile xdata *)0xff1a)
#define     PWM01T2L    (*(unsigned char volatile xdata *)0xff1b)
#define     PWM01CR     (*(unsigned char volatile xdata *)0xff1c)
#define     PWM01HLD    (*(unsigned char volatile xdata *)0xff1d)
#define     PWM02T1     (*(unsigned int volatile xdata *)0xff20)
#define     PWM02T1H    (*(unsigned char volatile xdata *)0xff20)
#define     PWM02T1L    (*(unsigned char volatile xdata *)0xff21)
#define     PWM02T2    	(*(unsigned int volatile xdata *)0xff22)
#define     PWM02T2H    (*(unsigned char volatile xdata *)0xff22)
#define     PWM02T2L    (*(unsigned char volatile xdata *)0xff23)
#define     PWM02CR     (*(unsigned char volatile xdata *)0xff24)
#define     PWM02HLD    (*(unsigned char volatile xdata *)0xff25)
#define     PWM03T1    	(*(unsigned int volatile xdata *)0xff28)
#define     PWM03T1H    (*(unsigned char volatile xdata *)0xff28)
#define     PWM03T1L    (*(unsigned char volatile xdata *)0xff29)
#define     PWM03T2    	(*(unsigned int volatile xdata *)0xff2a)
#define     PWM03T2H    (*(unsigned char volatile xdata *)0xff2a)
#define     PWM03T2L    (*(unsigned char volatile xdata *)0xff2b)
#define     PWM03CR     (*(unsigned char volatile xdata *)0xff2c)
#define     PWM03HLD    (*(unsigned char volatile xdata *)0xff2d)
#define     PWM04T1    	(*(unsigned int volatile xdata *)0xff30)
#define     PWM04T1H    (*(unsigned char volatile xdata *)0xff30)
#define     PWM04T1L    (*(unsigned char volatile xdata *)0xff31)
#define     PWM04T2    	(*(unsigned int volatile xdata *)0xff32)
#define     PWM04T2H    (*(unsigned char volatile xdata *)0xff32)
#define     PWM04T2L    (*(unsigned char volatile xdata *)0xff33)
#define     PWM04CR     (*(unsigned char volatile xdata *)0xff34)
#define     PWM04HLD    (*(unsigned char volatile xdata *)0xff35)
#define     PWM05T1     (*(unsigned int volatile xdata *)0xff38)
#define     PWM05T1H    (*(unsigned char volatile xdata *)0xff38)
#define     PWM05T1L    (*(unsigned char volatile xdata *)0xff39)
#define     PWM05T2     (*(unsigned int volatile xdata *)0xff3a)
#define     PWM05T2H    (*(unsigned char volatile xdata *)0xff3a)
#define     PWM05T2L    (*(unsigned char volatile xdata *)0xff3b)
#define     PWM05CR     (*(unsigned char volatile xdata *)0xff3c)
#define     PWM05HLD    (*(unsigned char volatile xdata *)0xff3d)
#define     PWM06T1     (*(unsigned int volatile xdata *)0xff40)
#define     PWM06T1H    (*(unsigned char volatile xdata *)0xff40)
#define     PWM06T1L    (*(unsigned char volatile xdata *)0xff41)
#define     PWM06T2     (*(unsigned int volatile xdata *)0xff42)
#define     PWM06T2H    (*(unsigned char volatile xdata *)0xff42)
#define     PWM06T2L    (*(unsigned char volatile xdata *)0xff43)
#define     PWM06CR     (*(unsigned char volatile xdata *)0xff44)
#define     PWM06HLD    (*(unsigned char volatile xdata *)0xff45)
#define     PWM07T1     (*(unsigned int volatile xdata *)0xff48)
#define     PWM07T1H    (*(unsigned char volatile xdata *)0xff48)
#define     PWM07T1L    (*(unsigned char volatile xdata *)0xff49)
#define     PWM07T2     (*(unsigned int volatile xdata *)0xff4a)
#define     PWM07T2H    (*(unsigned char volatile xdata *)0xff4a)
#define     PWM07T2L    (*(unsigned char volatile xdata *)0xff4b)
#define     PWM07CR     (*(unsigned char volatile xdata *)0xff4c)
#define     PWM07HLD    (*(unsigned char volatile xdata *)0xff4d)
#define     PWM1C       (*(unsigned int volatile xdata *)0xff50)
#define     PWM1CH      (*(unsigned char volatile xdata *)0xff50)
#define     PWM1CL      (*(unsigned char volatile xdata *)0xff51)
#define     PWM1CKS     (*(unsigned char volatile xdata *)0xff52)
#define     PWM1IF      (*(unsigned char volatile xdata *)0xff55)
#define     PWM1FDCR    (*(unsigned char volatile xdata *)0xff56)
#define     PWM10T1     (*(unsigned int volatile xdata *)0xff60)
#define     PWM10T1H    (*(unsigned char volatile xdata *)0xff60)
#define     PWM10T1L    (*(unsigned char volatile xdata *)0xff61)
#define     PWM10T2     (*(unsigned int volatile xdata *)0xff62)
#define     PWM10T2H    (*(unsigned char volatile xdata *)0xff62)
#define     PWM10T2L    (*(unsigned char volatile xdata *)0xff63)
#define     PWM10CR     (*(unsigned char volatile xdata *)0xff64)
#define     PWM10HLD    (*(unsigned char volatile xdata *)0xff65)
#define     PWM11T1     (*(unsigned int volatile xdata *)0xff68)
#define     PWM11T1H    (*(unsigned char volatile xdata *)0xff68)
#define     PWM11T1L    (*(unsigned char volatile xdata *)0xff69)
#define     PWM11T2     (*(unsigned int volatile xdata *)0xff6a)
#define     PWM11T2H    (*(unsigned char volatile xdata *)0xff6a)
#define     PWM11T2L    (*(unsigned char volatile xdata *)0xff6b)
#define     PWM11CR     (*(unsigned char volatile xdata *)0xff6c)
#define     PWM11HLD    (*(unsigned char volatile xdata *)0xff6d)
#define     PWM12T1     (*(unsigned int volatile xdata *)0xff70)
#define     PWM12T1H    (*(unsigned char volatile xdata *)0xff70)
#define     PWM12T1L    (*(unsigned char volatile xdata *)0xff71)
#define     PWM12T2     (*(unsigned int volatile xdata *)0xff72)
#define     PWM12T2H    (*(unsigned char volatile xdata *)0xff72)
#define     PWM12T2L    (*(unsigned char volatile xdata *)0xff73)
#define     PWM12CR     (*(unsigned char volatile xdata *)0xff74)
#define     PWM12HLD    (*(unsigned char volatile xdata *)0xff75)
#define     PWM13T1     (*(unsigned int volatile xdata *)0xff78)
#define     PWM13T1H    (*(unsigned char volatile xdata *)0xff78)
#define     PWM13T1L    (*(unsigned char volatile xdata *)0xff79)
#define     PWM13T2     (*(unsigned int volatile xdata *)0xff7a)
#define     PWM13T2H    (*(unsigned char volatile xdata *)0xff7a)
#define     PWM13T2L    (*(unsigned char volatile xdata *)0xff7b)
#define     PWM13CR     (*(unsigned char volatile xdata *)0xff7c)
#define     PWM13HLD    (*(unsigned char volatile xdata *)0xff7d)
#define     PWM14T1     (*(unsigned int volatile xdata *)0xff80)
#define     PWM14T1H    (*(unsigned char volatile xdata *)0xff80)
#define     PWM14T1L    (*(unsigned char volatile xdata *)0xff81)
#define     PWM14T2     (*(unsigned int volatile xdata *)0xff82)
#define     PWM14T2H    (*(unsigned char volatile xdata *)0xff82)
#define     PWM14T2L    (*(unsigned char volatile xdata *)0xff83)
#define     PWM14CR     (*(unsigned char volatile xdata *)0xff84)
#define     PWM14HLD    (*(unsigned char volatile xdata *)0xff85)
#define     PWM15T1     (*(unsigned int volatile xdata *)0xff88)
#define     PWM15T1H    (*(unsigned char volatile xdata *)0xff88)
#define     PWM15T1L    (*(unsigned char volatile xdata *)0xff89)
#define     PWM15T2     (*(unsigned int volatile xdata *)0xff8a)
#define     PWM15T2H    (*(unsigned char volatile xdata *)0xff8a)
#define     PWM15T2L    (*(unsigned char volatile xdata *)0xff8b)
#define     PWM15CR     (*(unsigned char volatile xdata *)0xff8c)
#define     PWM15HLD    (*(unsigned char volatile xdata *)0xff8d)
#define     PWM16T1     (*(unsigned int volatile xdata *)0xff90)
#define     PWM16T1H    (*(unsigned char volatile xdata *)0xff90)
#define     PWM16T1L    (*(unsigned char volatile xdata *)0xff91)
#define     PWM16T2     (*(unsigned int volatile xdata *)0xff92)
#define     PWM16T2H    (*(unsigned char volatile xdata *)0xff92)
#define     PWM16T2L    (*(unsigned char volatile xdata *)0xff93)
#define     PWM16CR     (*(unsigned char volatile xdata *)0xff94)
#define     PWM16HLD    (*(unsigned char volatile xdata *)0xff95)
#define     PWM17T1     (*(unsigned int volatile xdata *)0xff98)
#define     PWM17T1H    (*(unsigned char volatile xdata *)0xff98)
#define     PWM17T1L    (*(unsigned char volatile xdata *)0xff99)
#define     PWM17T2     (*(unsigned int volatile xdata *)0xff9a)
#define     PWM17T2H    (*(unsigned char volatile xdata *)0xff9a)
#define     PWM17T2L    (*(unsigned char volatile xdata *)0xff9b)
#define     PWM17CR     (*(unsigned char volatile xdata *)0xff9c)
#define     PWM17HLD    (*(unsigned char volatile xdata *)0xff9d)
#define     PWM2C       (*(unsigned int volatile xdata *)0xffa0)
#define     PWM2CH      (*(unsigned char volatile xdata *)0xffa0)
#define     PWM2CL      (*(unsigned char volatile xdata *)0xffa1)
#define     PWM2CKS     (*(unsigned char volatile xdata *)0xffa2)
#define     PWM2TADC    (*(unsigned int volatile xdata *)0xffa3)
#define     PWM2TADCH   (*(unsigned char volatile xdata *)0xffa3)
#define     PWM2TADCL   (*(unsigned char volatile xdata *)0xffa4)
#define     PWM2IF      (*(unsigned char volatile xdata *)0xffa5)
#define     PWM2FDCR    (*(unsigned char volatile xdata *)0xffa6)
#define     PWM20T1     (*(unsigned int volatile xdata *)0xffb0)
#define     PWM20T1H    (*(unsigned char volatile xdata *)0xffb0)
#define     PWM20T1L    (*(unsigned char volatile xdata *)0xffb1)
#define     PWM20T2     (*(unsigned int volatile xdata *)0xffb2)
#define     PWM20T2H    (*(unsigned char volatile xdata *)0xffb2)
#define     PWM20T2L    (*(unsigned char volatile xdata *)0xffb3)
#define     PWM20CR     (*(unsigned char volatile xdata *)0xffb4)
#define     PWM20HLD    (*(unsigned char volatile xdata *)0xffb5)
#define     PWM21T1     (*(unsigned int volatile xdata *)0xffb8)
#define     PWM21T1H    (*(unsigned char volatile xdata *)0xffb8)
#define     PWM21T1L    (*(unsigned char volatile xdata *)0xffb9)
#define     PWM21T2     (*(unsigned int volatile xdata *)0xffba)
#define     PWM21T2H    (*(unsigned char volatile xdata *)0xffba)
#define     PWM21T2L    (*(unsigned char volatile xdata *)0xffbb)
#define     PWM21CR     (*(unsigned char volatile xdata *)0xffbc)
#define     PWM21HLD    (*(unsigned char volatile xdata *)0xffbd)
#define     PWM22T1     (*(unsigned int volatile xdata *)0xffc0)
#define     PWM22T1H    (*(unsigned char volatile xdata *)0xffc0)
#define     PWM22T1L    (*(unsigned char volatile xdata *)0xffc1)
#define     PWM22T2     (*(unsigned int volatile xdata *)0xffc2)
#define     PWM22T2H    (*(unsigned char volatile xdata *)0xffc2)
#define     PWM22T2L    (*(unsigned char volatile xdata *)0xffc3)
#define     PWM22CR     (*(unsigned char volatile xdata *)0xffc4)
#define     PWM22HLD    (*(unsigned char volatile xdata *)0xffc5)
#define     PWM23T1     (*(unsigned int volatile xdata *)0xffc8)
#define     PWM23T1H    (*(unsigned char volatile xdata *)0xffc8)
#define     PWM23T1L    (*(unsigned char volatile xdata *)0xffc9)
#define     PWM23T2     (*(unsigned int volatile xdata *)0xffca)
#define     PWM23T2H    (*(unsigned char volatile xdata *)0xffca)
#define     PWM23T2L    (*(unsigned char volatile xdata *)0xffcb)
#define     PWM23CR     (*(unsigned char volatile xdata *)0xffcc)
#define     PWM23HLD    (*(unsigned char volatile xdata *)0xffcd)
#define     PWM24T1     (*(unsigned int volatile xdata *)0xffd0)
#define     PWM24T1H    (*(unsigned char volatile xdata *)0xffd0)
#define     PWM24T1L    (*(unsigned char volatile xdata *)0xffd1)
#define     PWM24T2     (*(unsigned int volatile xdata *)0xffd2)
#define     PWM24T2H    (*(unsigned char volatile xdata *)0xffd2)
#define     PWM24T2L    (*(unsigned char volatile xdata *)0xffd3)
#define     PWM24CR     (*(unsigned char volatile xdata *)0xffd4)
#define     PWM24HLD    (*(unsigned char volatile xdata *)0xffd5)
#define     PWM25T1     (*(unsigned int volatile xdata *)0xffd8)
#define     PWM25T1H    (*(unsigned char volatile xdata *)0xffd8)
#define     PWM25T1L    (*(unsigned char volatile xdata *)0xffd9)
#define     PWM25T2     (*(unsigned int volatile xdata *)0xffda)
#define     PWM25T2H    (*(unsigned char volatile xdata *)0xffda)
#define     PWM25T2L    (*(unsigned char volatile xdata *)0xffdb)
#define     PWM25CR     (*(unsigned char volatile xdata *)0xffdc)
#define     PWM25HLD    (*(unsigned char volatile xdata *)0xffdd)
#define     PWM26T1     (*(unsigned int volatile xdata *)0xffe0)
#define     PWM26T1H    (*(unsigned char volatile xdata *)0xffe0)
#define     PWM26T1L    (*(unsigned char volatile xdata *)0xffe1)
#define     PWM26T2     (*(unsigned int volatile xdata *)0xffe2)
#define     PWM26T2H    (*(unsigned char volatile xdata *)0xffe2)
#define     PWM26T2L    (*(unsigned char volatile xdata *)0xffe3)
#define     PWM26CR     (*(unsigned char volatile xdata *)0xffe4)
#define     PWM26HLD    (*(unsigned char volatile xdata *)0xffe5)
#define     PWM27T1     (*(unsigned int volatile xdata *)0xffe8)
#define     PWM27T1H    (*(unsigned char volatile xdata *)0xffe8)
#define     PWM27T1L    (*(unsigned char volatile xdata *)0xffe9)
#define     PWM27T2     (*(unsigned int volatile xdata *)0xffea)
#define     PWM27T2H    (*(unsigned char volatile xdata *)0xffea)
#define     PWM27T2L    (*(unsigned char volatile xdata *)0xffeb)
#define     PWM27CR     (*(unsigned char volatile xdata *)0xffec)
#define     PWM27HLD    (*(unsigned char volatile xdata *)0xffed)

/////////////////////////////////////////////////
//FC00H-FCFFH
/////////////////////////////////////////////////

#define     PWM3C       (*(unsigned int volatile xdata *)0xfc00)
#define     PWM3CH      (*(unsigned char volatile xdata *)0xfc00)
#define     PWM3CL      (*(unsigned char volatile xdata *)0xfc01)
#define     PWM3CKS     (*(unsigned char volatile xdata *)0xfc02)
#define     PWM3IF      (*(unsigned char volatile xdata *)0xfc05)
#define     PWM3FDCR    (*(unsigned char volatile xdata *)0xfc06)
#define     PWM30T1     (*(unsigned int volatile xdata *)0xfc10)
#define     PWM30T1H    (*(unsigned char volatile xdata *)0xfc10)
#define     PWM30T1L    (*(unsigned char volatile xdata *)0xfc11)
#define     PWM30T2     (*(unsigned int volatile xdata *)0xfc12)
#define     PWM30T2H    (*(unsigned char volatile xdata *)0xfc12)
#define     PWM30T2L    (*(unsigned char volatile xdata *)0xfc13)
#define     PWM30CR     (*(unsigned char volatile xdata *)0xfc14)
#define     PWM30HLD    (*(unsigned char volatile xdata *)0xfc15)
#define     PWM31T1     (*(unsigned int volatile xdata *)0xfc18)
#define     PWM31T1H    (*(unsigned char volatile xdata *)0xfc18)
#define     PWM31T1L    (*(unsigned char volatile xdata *)0xfc19)
#define     PWM31T2     (*(unsigned int volatile xdata *)0xfc1a)
#define     PWM31T2H    (*(unsigned char volatile xdata *)0xfc1a)
#define     PWM31T2L    (*(unsigned char volatile xdata *)0xfc1b)
#define     PWM31CR     (*(unsigned char volatile xdata *)0xfc1c)
#define     PWM31HLD    (*(unsigned char volatile xdata *)0xfc1d)
#define     PWM32T1     (*(unsigned int volatile xdata *)0xfc20)
#define     PWM32T1H    (*(unsigned char volatile xdata *)0xfc20)
#define     PWM32T1L    (*(unsigned char volatile xdata *)0xfc21)
#define     PWM32T2     (*(unsigned int volatile xdata *)0xfc22)
#define     PWM32T2H    (*(unsigned char volatile xdata *)0xfc22)
#define     PWM32T2L    (*(unsigned char volatile xdata *)0xfc23)
#define     PWM32CR     (*(unsigned char volatile xdata *)0xfc24)
#define     PWM32HLD    (*(unsigned char volatile xdata *)0xfc25)
#define     PWM33T1     (*(unsigned int volatile xdata *)0xfc28)
#define     PWM33T1H    (*(unsigned char volatile xdata *)0xfc28)
#define     PWM33T1L    (*(unsigned char volatile xdata *)0xfc29)
#define     PWM33T2     (*(unsigned int volatile xdata *)0xfc2a)
#define     PWM33T2H    (*(unsigned char volatile xdata *)0xfc2a)
#define     PWM33T2L    (*(unsigned char volatile xdata *)0xfc2b)
#define     PWM33CR     (*(unsigned char volatile xdata *)0xfc2c)
#define     PWM33HLD    (*(unsigned char volatile xdata *)0xfc2d)
#define     PWM34T1     (*(unsigned int volatile xdata *)0xfc30)
#define     PWM34T1H    (*(unsigned char volatile xdata *)0xfc30)
#define     PWM34T1L    (*(unsigned char volatile xdata *)0xfc31)
#define     PWM34T2     (*(unsigned int volatile xdata *)0xfc32)
#define     PWM34T2H    (*(unsigned char volatile xdata *)0xfc32)
#define     PWM34T2L    (*(unsigned char volatile xdata *)0xfc33)
#define     PWM34CR     (*(unsigned char volatile xdata *)0xfc34)
#define     PWM34HLD    (*(unsigned char volatile xdata *)0xfc35)
#define     PWM35T1     (*(unsigned int volatile xdata *)0xfc38)
#define     PWM35T1H    (*(unsigned char volatile xdata *)0xfc38)
#define     PWM35T1L    (*(unsigned char volatile xdata *)0xfc39)
#define     PWM35T2     (*(unsigned int volatile xdata *)0xfc3a)
#define     PWM35T2H    (*(unsigned char volatile xdata *)0xfc3a)
#define     PWM35T2L    (*(unsigned char volatile xdata *)0xfc3b)
#define     PWM35CR     (*(unsigned char volatile xdata *)0xfc3c)
#define     PWM35HLD    (*(unsigned char volatile xdata *)0xfc3d)
#define     PWM36T1     (*(unsigned int volatile xdata *)0xfc40)
#define     PWM36T1H    (*(unsigned char volatile xdata *)0xfc40)
#define     PWM36T1L    (*(unsigned char volatile xdata *)0xfc41)
#define     PWM36T2     (*(unsigned int volatile xdata *)0xfc42)
#define     PWM36T2H    (*(unsigned char volatile xdata *)0xfc42)
#define     PWM36T2L    (*(unsigned char volatile xdata *)0xfc43)
#define     PWM36CR     (*(unsigned char volatile xdata *)0xfc44)
#define     PWM36HLD    (*(unsigned char volatile xdata *)0xfc45)
#define     PWM37T1     (*(unsigned int volatile xdata *)0xfc48)
#define     PWM37T1H    (*(unsigned char volatile xdata *)0xfc48)
#define     PWM37T1L    (*(unsigned char volatile xdata *)0xfc49)
#define     PWM37T2     (*(unsigned int volatile xdata *)0xfc4a)
#define     PWM37T2H    (*(unsigned char volatile xdata *)0xfc4a)
#define     PWM37T2L    (*(unsigned char volatile xdata *)0xfc4b)
#define     PWM37CR     (*(unsigned char volatile xdata *)0xfc4c)
#define     PWM37HLD    (*(unsigned char volatile xdata *)0xfc4d)
#define     PWM4C       (*(unsigned int volatile xdata *)0xfc50)
#define     PWM4CH      (*(unsigned char volatile xdata *)0xfc50)
#define     PWM4CL      (*(unsigned char volatile xdata *)0xfc51)
#define     PWM4CKS     (*(unsigned char volatile xdata *)0xfc52)
#define     PWM4TADC    (*(unsigned int volatile xdata *)0xfc53)
#define     PWM4TADCH   (*(unsigned char volatile xdata *)0xfc53)
#define     PWM4TADCL   (*(unsigned char volatile xdata *)0xfc54)
#define     PWM4IF      (*(unsigned char volatile xdata *)0xfc55)
#define     PWM4FDCR    (*(unsigned char volatile xdata *)0xfc56)
#define     PWM40T1     (*(unsigned int volatile xdata *)0xfc60)
#define     PWM40T1H    (*(unsigned char volatile xdata *)0xfc60)
#define     PWM40T1L    (*(unsigned char volatile xdata *)0xfc61)
#define     PWM40T2     (*(unsigned int volatile xdata *)0xfc62)
#define     PWM40T2H    (*(unsigned char volatile xdata *)0xfc62)
#define     PWM40T2L    (*(unsigned char volatile xdata *)0xfc63)
#define     PWM40CR     (*(unsigned char volatile xdata *)0xfc64)
#define     PWM40HLD    (*(unsigned char volatile xdata *)0xfc65)
#define     PWM41T1     (*(unsigned int volatile xdata *)0xfc68)
#define     PWM41T1H    (*(unsigned char volatile xdata *)0xfc68)
#define     PWM41T1L    (*(unsigned char volatile xdata *)0xfc69)
#define     PWM41T2     (*(unsigned int volatile xdata *)0xfc6a)
#define     PWM41T2H    (*(unsigned char volatile xdata *)0xfc6a)
#define     PWM41T2L    (*(unsigned char volatile xdata *)0xfc6b)
#define     PWM41CR     (*(unsigned char volatile xdata *)0xfc6c)
#define     PWM41HLD    (*(unsigned char volatile xdata *)0xfc6d)
#define     PWM42T1     (*(unsigned int volatile xdata *)0xfc70)
#define     PWM42T1H    (*(unsigned char volatile xdata *)0xfc70)
#define     PWM42T1L    (*(unsigned char volatile xdata *)0xfc71)
#define     PWM42T2     (*(unsigned int volatile xdata *)0xfc72)
#define     PWM42T2H    (*(unsigned char volatile xdata *)0xfc72)
#define     PWM42T2L    (*(unsigned char volatile xdata *)0xfc73)
#define     PWM42CR     (*(unsigned char volatile xdata *)0xfc74)
#define     PWM42HLD    (*(unsigned char volatile xdata *)0xfc75)
#define     PWM43T1     (*(unsigned int volatile xdata *)0xfc78)
#define     PWM43T1H    (*(unsigned char volatile xdata *)0xfc78)
#define     PWM43T1L    (*(unsigned char volatile xdata *)0xfc79)
#define     PWM43T2     (*(unsigned int volatile xdata *)0xfc7a)
#define     PWM43T2H    (*(unsigned char volatile xdata *)0xfc7a)
#define     PWM43T2L    (*(unsigned char volatile xdata *)0xfc7b)
#define     PWM43CR     (*(unsigned char volatile xdata *)0xfc7c)
#define     PWM43HLD    (*(unsigned char volatile xdata *)0xfc7d)
#define     PWM44T1     (*(unsigned int volatile xdata *)0xfc80)
#define     PWM44T1H    (*(unsigned char volatile xdata *)0xfc80)
#define     PWM44T1L    (*(unsigned char volatile xdata *)0xfc81)
#define     PWM44T2     (*(unsigned int volatile xdata *)0xfc82)
#define     PWM44T2H    (*(unsigned char volatile xdata *)0xfc82)
#define     PWM44T2L    (*(unsigned char volatile xdata *)0xfc83)
#define     PWM44CR     (*(unsigned char volatile xdata *)0xfc84)
#define     PWM44HLD    (*(unsigned char volatile xdata *)0xfc85)
#define     PWM45T1     (*(unsigned int volatile xdata *)0xfc88)
#define     PWM45T1H    (*(unsigned char volatile xdata *)0xfc88)
#define     PWM45T1L    (*(unsigned char volatile xdata *)0xfc89)
#define     PWM45T2     (*(unsigned int volatile xdata *)0xfc8a)
#define     PWM45T2H    (*(unsigned char volatile xdata *)0xfc8a)
#define     PWM45T2L    (*(unsigned char volatile xdata *)0xfc8b)
#define     PWM45CR     (*(unsigned char volatile xdata *)0xfc8c)
#define     PWM45HLD    (*(unsigned char volatile xdata *)0xfc8d)
#define     PWM46T1     (*(unsigned int volatile xdata *)0xfc90)
#define     PWM46T1H    (*(unsigned char volatile xdata *)0xfc90)
#define     PWM46T1L    (*(unsigned char volatile xdata *)0xfc91)
#define     PWM46T2     (*(unsigned int volatile xdata *)0xfc92)
#define     PWM46T2H    (*(unsigned char volatile xdata *)0xfc92)
#define     PWM46T2L    (*(unsigned char volatile xdata *)0xfc93)
#define     PWM46CR     (*(unsigned char volatile xdata *)0xfc94)
#define     PWM46HLD    (*(unsigned char volatile xdata *)0xfc95)
#define     PWM47T1     (*(unsigned int volatile xdata *)0xfc98)
#define     PWM47T1H    (*(unsigned char volatile xdata *)0xfc98)
#define     PWM47T1L    (*(unsigned char volatile xdata *)0xfc99)
#define     PWM47T2     (*(unsigned int volatile xdata *)0xfc9a)
#define     PWM47T2H    (*(unsigned char volatile xdata *)0xfc9a)
#define     PWM47T2L    (*(unsigned char volatile xdata *)0xfc9b)
#define     PWM47CR     (*(unsigned char volatile xdata *)0xfc9c)
#define     PWM47HLD    (*(unsigned char volatile xdata *)0xfc9d)
#define     PWM5C       (*(unsigned int volatile xdata *)0xfca0)
#define     PWM5CH      (*(unsigned char volatile xdata *)0xfca0)
#define     PWM5CL      (*(unsigned char volatile xdata *)0xfca1)
#define     PWM5CKS     (*(unsigned char volatile xdata *)0xfca2)
#define     PWM5IF      (*(unsigned char volatile xdata *)0xfca5)
#define     PWM5FDCR    (*(unsigned char volatile xdata *)0xfca6)
#define     PWM50T1     (*(unsigned int volatile xdata *)0xfcb0)
#define     PWM50T1H    (*(unsigned char volatile xdata *)0xfcb0)
#define     PWM50T1L    (*(unsigned char volatile xdata *)0xfcb1)
#define     PWM50T2     (*(unsigned int volatile xdata *)0xfcb2)
#define     PWM50T2H    (*(unsigned char volatile xdata *)0xfcb2)
#define     PWM50T2L    (*(unsigned char volatile xdata *)0xfcb3)
#define     PWM50CR     (*(unsigned char volatile xdata *)0xfcb4)
#define     PWM50HLD    (*(unsigned char volatile xdata *)0xfcb5)
#define     PWM51T1     (*(unsigned int volatile xdata *)0xfcb8)
#define     PWM51T1H    (*(unsigned char volatile xdata *)0xfcb8)
#define     PWM51T1L    (*(unsigned char volatile xdata *)0xfcb9)
#define     PWM51T2     (*(unsigned int volatile xdata *)0xfcba)
#define     PWM51T2H    (*(unsigned char volatile xdata *)0xfcba)
#define     PWM51T2L    (*(unsigned char volatile xdata *)0xfcbb)
#define     PWM51CR     (*(unsigned char volatile xdata *)0xfcbc)
#define     PWM51HLD    (*(unsigned char volatile xdata *)0xfcbd)
#define     PWM52T1     (*(unsigned int volatile xdata *)0xfcc0)
#define     PWM52T1H    (*(unsigned char volatile xdata *)0xfcc0)
#define     PWM52T1L    (*(unsigned char volatile xdata *)0xfcc1)
#define     PWM52T2     (*(unsigned int volatile xdata *)0xfcc2)
#define     PWM52T2H    (*(unsigned char volatile xdata *)0xfcc2)
#define     PWM52T2L    (*(unsigned char volatile xdata *)0xfcc3)
#define     PWM52CR     (*(unsigned char volatile xdata *)0xfcc4)
#define     PWM52HLD    (*(unsigned char volatile xdata *)0xfcc5)
#define     PWM53T1     (*(unsigned int volatile xdata *)0xfcc8)
#define     PWM53T1H    (*(unsigned char volatile xdata *)0xfcc8)
#define     PWM53T1L    (*(unsigned char volatile xdata *)0xfcc9)
#define     PWM53T2     (*(unsigned int volatile xdata *)0xfcca)
#define     PWM53T2H    (*(unsigned char volatile xdata *)0xfcca)
#define     PWM53T2L    (*(unsigned char volatile xdata *)0xfccb)
#define     PWM53CR     (*(unsigned char volatile xdata *)0xfccc)
#define     PWM53HLD    (*(unsigned char volatile xdata *)0xfccd)
#define     PWM54T1     (*(unsigned int volatile xdata *)0xfcd0)
#define     PWM54T1H    (*(unsigned char volatile xdata *)0xfcd0)
#define     PWM54T1L    (*(unsigned char volatile xdata *)0xfcd1)
#define     PWM54T2     (*(unsigned int volatile xdata *)0xfcd2)
#define     PWM54T2H    (*(unsigned char volatile xdata *)0xfcd2)
#define     PWM54T2L    (*(unsigned char volatile xdata *)0xfcd3)
#define     PWM54CR     (*(unsigned char volatile xdata *)0xfcd4)
#define     PWM54HLD    (*(unsigned char volatile xdata *)0xfcd5)
#define     PWM55T1     (*(unsigned int volatile xdata *)0xfcd8)
#define     PWM55T1H    (*(unsigned char volatile xdata *)0xfcd8)
#define     PWM55T1L    (*(unsigned char volatile xdata *)0xfcd9)
#define     PWM55T2     (*(unsigned int volatile xdata *)0xfcda)
#define     PWM55T2H    (*(unsigned char volatile xdata *)0xfcda)
#define     PWM55T2L    (*(unsigned char volatile xdata *)0xfcdb)
#define     PWM55CR     (*(unsigned char volatile xdata *)0xfcdc)
#define     PWM55HLD    (*(unsigned char volatile xdata *)0xfcdd)
#define     PWM56T1     (*(unsigned int volatile xdata *)0xfce0)
#define     PWM56T1H    (*(unsigned char volatile xdata *)0xfce0)
#define     PWM56T1L    (*(unsigned char volatile xdata *)0xfce1)
#define     PWM56T2     (*(unsigned int volatile xdata *)0xfce2)
#define     PWM56T2H    (*(unsigned char volatile xdata *)0xfce2)
#define     PWM56T2L    (*(unsigned char volatile xdata *)0xfce3)
#define     PWM56CR     (*(unsigned char volatile xdata *)0xfce4)
#define     PWM56HLD    (*(unsigned char volatile xdata *)0xfce5)
#define     PWM57T1     (*(unsigned int volatile xdata *)0xfce8)
#define     PWM57T1H    (*(unsigned char volatile xdata *)0xfce8)
#define     PWM57T1L    (*(unsigned char volatile xdata *)0xfce9)
#define     PWM57T2     (*(unsigned int volatile xdata *)0xfcea)
#define     PWM57T2H    (*(unsigned char volatile xdata *)0xfcea)
#define     PWM57T2L    (*(unsigned char volatile xdata *)0xfceb)
#define     PWM57CR     (*(unsigned char volatile xdata *)0xfcec)
#define     PWM57HLD    (*(unsigned char volatile xdata *)0xfced)


//						             7      6      5      4      3      2      1      0     Reset Value
//sfr PWMSET = 0xF1H;  ENGLBSET PWMRST ENPWM5 ENPWM4 ENPWM3 ENPWM2 ENPWM1 ENPWM0  0000,0000  /* 增强型PWM全局配置寄存器 */ 
#define PWM15_SET_Uniform()				PWMSET |= 0x80		//1：6组PWM采用统一的设置方式
#define PWM15_SET_Independent()		PWMSET &= ~0x80		//0：6组PWM采用各自独立的设置方式

#define PWM15_Reset()							PWMSET |= 0x40		//1：复位所有PWM的XFR寄存器，SFR不变

#define PWM15_PWM5_Enable()				PWMSET |= 0x20		//1：使能PWM5（包括 PWM50~PWM54）。
#define PWM15_PWM5_Disable()			PWMSET &= ~0x20		//0：关闭PWM5

#define PWM15_PWM4_Enable()				PWMSET |= 0x10		//1：使能PWM4（包括 PWM40~PWM47）。
#define PWM15_PWM4_Disable()			PWMSET &= ~0x10		//0：关闭PWM4

#define PWM15_PWM3_Enable()				PWMSET |= 0x08		//1：使能PWM3（包括 PWM30~PWM37）。
#define PWM15_PWM3_Disable()			PWMSET &= ~0x08		//0：关闭PWM3

#define PWM15_PWM2_Enable()				PWMSET |= 0x04		//1：使能PWM2（包括 PWM20~PWM27）。
#define PWM15_PWM2_Disable()			PWMSET &= ~0x04		//0：关闭PWM2

#define PWM15_PWM1_Enable()				PWMSET |= 0x02		//1：使能PWM1（包括 PWM10~PWM17）。
#define PWM15_PWM1_Disable()			PWMSET &= ~0x02		//0：关闭PWM1

#define PWM15_PWM0_Enable()				PWMSET |= 0x01		//1：使能PWM0（包括 PWM00~PWM07）。
#define PWM15_PWM0_Disable()			PWMSET &= ~0x01		//0：关闭PWM0

//						              7       6       5       4       3        2        1        0     Reset Value
//sfr PWMCFG01= 0xF6H;  PWM1CBIF EPWM1CBI FLTPS0 PWM1CEN PWM0CBIF EPWM0CBI ENPWM0TA PWM0CEN  0000,0000  /* 增强型PWM配置寄存器 */ 
//sfr PWMCFG23= 0xF7H;  PWM3CBIF EPWM3CBI FLTPS1 PWM3CEN PWM2CBIF EPWM2CBI ENPWM2TA PWM2CEN  0000,0000  /* 增强型PWM配置寄存器 */ 
//sfr PWMCFG45= 0xFEH;  PWM5CBIF EPWM5CBI FLTPS2 PWM5CEN PWM4CBIF EPWM4CBI ENPWM4TA PWM4CEN  0000,0000  /* 增强型PWM配置寄存器 */ 
#define		PWM1CBIF			0x80
#define		PWM0CBIF			0x08
#define		FLTPSn				0x20

#define PWM15_Counter1Int_Enable()		PWMCFG01 |= 0x40		//1：使能计数器归零中断
#define PWM15_Counter1Int_Disable()		PWMCFG01 &= ~0x40		//0：关闭计数器归零中断
#define PWM15_Counter1_Enable()				PWMCFG01 |= 0x10		//1：使能计数器
#define PWM15_Counter1_Disable()			PWMCFG01 &= ~0x10		//0：关闭计数器
#define PWM15_Counter0Int_Enable()		PWMCFG01 |= 0x04		//1：使能计数器归零中断
#define PWM15_Counter0Int_Disable()		PWMCFG01 &= ~0x04		//0：关闭计数器归零中断
#define PWM15_Counter0_Enable()				PWMCFG01 |= 0x01		//1：使能计数器
#define PWM15_Counter0_Disable()			PWMCFG01 &= ~0x01		//0：关闭计数器
#define PWM15_PWM0_ADC_Enable()				PWMCFG01 |= 0x02		//1：PWM与ADC相关联
#define PWM15_PWM0_ADC_Disable()			PWMCFG01 &= ~0x02		//0：PWM与ADC不关联

#define PWM15_Counter3Int_Enable()		PWMCFG23 |= 0x40		//1：使能计数器归零中断
#define PWM15_Counter3Int_Disable()		PWMCFG23 &= ~0x40		//0：关闭计数器归零中断
#define PWM15_Counter3_Enable()				PWMCFG23 |= 0x10		//1：使能计数器
#define PWM15_Counter3_Disable()			PWMCFG23 &= ~0x10		//0：关闭计数器
#define PWM15_Counter2Int_Enable()		PWMCFG23 |= 0x04		//1：使能计数器归零中断
#define PWM15_Counter2Int_Disable()		PWMCFG23 &= ~0x04		//0：关闭计数器归零中断
#define PWM15_Counter2_Enable()				PWMCFG23 |= 0x01		//1：使能计数器
#define PWM15_Counter2_Disable()			PWMCFG23 &= ~0x01		//0：关闭计数器
#define PWM15_PWM2_ADC_Enable()				PWMCFG23 |= 0x02		//1：PWM与ADC相关联
#define PWM15_PWM2_ADC_Disable()			PWMCFG23 &= ~0x02		//0：PWM与ADC不关联

#define PWM15_Counter5Int_Enable()		PWMCFG45 |= 0x40		//1：使能计数器归零中断
#define PWM15_Counter5Int_Disable()		PWMCFG45 &= ~0x40		//0：关闭计数器归零中断
#define PWM15_Counter5_Enable()				PWMCFG45 |= 0x10		//1：使能计数器
#define PWM15_Counter5_Disable()			PWMCFG45 &= ~0x10		//0：关闭计数器
#define PWM15_Counter4Int_Enable()		PWMCFG45 |= 0x04		//1：使能计数器归零中断
#define PWM15_Counter4Int_Disable()		PWMCFG45 &= ~0x04		//0：关闭计数器归零中断
#define PWM15_Counter4_Enable()				PWMCFG45 |= 0x01		//1：使能计数器
#define PWM15_Counter4_Disable()			PWMCFG45 &= ~0x01		//0：关闭计数器
#define PWM15_PWM4_ADC_Enable()				PWMCFG45 |= 0x02		//1：PWM与ADC相关联
#define PWM15_PWM4_ADC_Disable()			PWMCFG45 &= ~0x02		//0：PWM与ADC不关联

/*  PWMnIF  */
#define		C7IF   = (1<<7)
#define		C6IF   = (1<<6)
#define		C5IF   = (1<<5)
#define		C4IF   = (1<<4)
#define		C3IF   = (1<<3)
#define		C2IF   = (1<<2)
#define		C1IF   = (1<<1)
#define		C0IF   = 1

/*  PWMnFDCR  */
#define		INVCMP   = (1<<7)
#define		INVIO    = (1<<6)
#define		ENFD     = (1<<5)
#define		FLTFLIO  = (1<<4)
#define		EFDI     = (1<<3)
#define		FDCMP    = (1<<2)
#define		FDIO     = (1<<1)
#define		FDIF     = 1

//						             7  6  5     4      3      2      1      0     Reset Value
//sfr PWM0CKS = 0xFF02H;   -  -  -   SELT2          PWM_PS[3:0]          xxx0,0000  /* 增强型PWM时钟选择存器 */ 
//sfr PWM1CKS = 0xFF52H;   -  -  -   SELT2          PWM_PS[3:0]          xxx0,0000  /* 增强型PWM时钟选择存器 */ 
//sfr PWM2CKS = 0xFFA2H;   -  -  -   SELT2          PWM_PS[3:0]          xxx0,0000  /* 增强型PWM时钟选择存器 */ 
//sfr PWM3CKS = 0xFC02H;   -  -  -   SELT2          PWM_PS[3:0]          xxx0,0000  /* 增强型PWM时钟选择存器 */ 
//sfr PWM4CKS = 0xFC52H;   -  -  -   SELT2          PWM_PS[3:0]          xxx0,0000  /* 增强型PWM时钟选择存器 */ 
//sfr PWM5CKS = 0xFCA2H;   -  -  -   SELT2          PWM_PS[3:0]          xxx0,0000  /* 增强型PWM时钟选择存器 */ 
#define PWM0_PS_Clock()				PWM0CKS &= ~0x10		//0：PWMn时钟源为系统时钟分频后的时钟
#define PWM0_T2_Clock()				PWM0CKS |= 0x10			//1：PWMn时钟源为定时器2的溢出脉冲
#define PWM0_PS_Set(n)				PWM0CKS = (PWM0CKS & ~0x0F) | (n & 0x0F)		//系统时钟预分频参数设置：SYSclk / (PWM_PS+1)
#define PWM1_PS_Clock()				PWM1CKS &= ~0x10		//0：PWMn时钟源为系统时钟分频后的时钟
#define PWM1_T2_Clock()				PWM1CKS |= 0x10			//1：PWMn时钟源为定时器2的溢出脉冲
#define PWM1_PS_Set(n)				PWM1CKS = (PWM1CKS & ~0x0F) | (n & 0x0F)		//系统时钟预分频参数设置：SYSclk / (PWM_PS+1)
#define PWM2_PS_Clock()				PWM2CKS &= ~0x10		//0：PWMn时钟源为系统时钟分频后的时钟
#define PWM2_T2_Clock()				PWM2CKS |= 0x10			//1：PWMn时钟源为定时器2的溢出脉冲
#define PWM2_PS_Set(n)				PWM2CKS = (PWM2CKS & ~0x0F) | (n & 0x0F)		//系统时钟预分频参数设置：SYSclk / (PWM_PS+1)
#define PWM3_PS_Clock()				PWM3CKS &= ~0x10		//0：PWMn时钟源为系统时钟分频后的时钟
#define PWM3_T2_Clock()				PWM3CKS |= 0x10			//1：PWMn时钟源为定时器2的溢出脉冲
#define PWM3_PS_Set(n)				PWM3CKS = (PWM3CKS & ~0x0F) | (n & 0x0F)		//系统时钟预分频参数设置：SYSclk / (PWM_PS+1)
#define PWM4_PS_Clock()				PWM4CKS &= ~0x10		//0：PWMn时钟源为系统时钟分频后的时钟
#define PWM4_T2_Clock()				PWM4CKS |= 0x10			//1：PWMn时钟源为定时器2的溢出脉冲
#define PWM4_PS_Set(n)				PWM4CKS = (PWM4CKS & ~0x0F) | (n & 0x0F)		//系统时钟预分频参数设置：SYSclk / (PWM_PS+1)
#define PWM5_PS_Clock()				PWM5CKS &= ~0x10		//0：PWMn时钟源为系统时钟分频后的时钟
#define PWM5_T2_Clock()				PWM5CKS |= 0x10			//1：PWMn时钟源为定时器2的溢出脉冲
#define PWM5_PS_Set(n)				PWM5CKS = (PWM5CKS & ~0x0F) | (n & 0x0F)		//系统时钟预分频参数设置：SYSclk / (PWM_PS+1)

/*  PWMnTADC  */
#define PWM15_PWM0TADC(n)			PWM0TADC = (n & 0x7fff)		//PWM触发ADC时间点
#define PWM15_PWM2TADC(n)			PWM2TADC = (n & 0x7fff)		//PWM触发ADC时间点
#define PWM15_PWM4TADC(n)			PWM4TADC = (n & 0x7fff)		//PWM触发ADC时间点

/*  PWMnTADC  */
#define PWM15_PWM0TADC(n)			PWM0TADC = (n & 0x7fff)		//PWM触发ADC时间点


/*  BIT Registers  */
/*  PSW   */
sbit CY   = PSW^7;
sbit AC   = PSW^6;
sbit F0   = PSW^5;
sbit RS1  = PSW^4;
sbit RS0  = PSW^3;
sbit OV   = PSW^2;
sbit F1   = PSW^1;
sbit P    = PSW^0;

/*  TCON  */
sbit TF1  = TCON^7;	//定时器1溢出中断标志位
sbit TR1  = TCON^6;	//定时器1运行控制位
sbit TF0  = TCON^5;	//定时器0溢出中断标志位
sbit TR0  = TCON^4;	//定时器0运行控制位
sbit IE1  = TCON^3;	//外中断1标志位
sbit IT1  = TCON^2;	//外中断1信号方式控制位，1：下降沿中断，0：上升下降均中断。
sbit IE0  = TCON^1;	//外中断0标志位
sbit IT0  = TCON^0;	//外中断0信号方式控制位，1：下降沿中断，0：上升下降均中断。

/*  P0  */
sbit  P00 = P0^0;
sbit  P01 = P0^1;
sbit  P02 = P0^2;
sbit  P03 = P0^3;
sbit  P04 = P0^4;
sbit  P05 = P0^5;
sbit  P06 = P0^6;
sbit  P07 = P0^7;

/*  P1  */
sbit  P10 = P1^0;
sbit  P11 = P1^1;
sbit  P12 = P1^2;
sbit  P13 = P1^3;
sbit  P14 = P1^4;
sbit  P15 = P1^5;
sbit  P16 = P1^6;
sbit  P17 = P1^7;

sbit  RXD2      = P1^0;
sbit  TXD2      = P1^1;
sbit  CCP1      = P1^0;
sbit  CCP0      = P1^1;
sbit  SPI_SS    = P1^2;
sbit  SPI_MOSI  = P1^3;
sbit  SPI_MISO  = P1^4;
sbit  SPI_SCLK  = P1^5;

sbit  SPI_SS_2    = P2^2;
sbit  SPI_MOSI_2  = P2^3;
sbit  SPI_MISO_2  = P2^4;
sbit  SPI_SCLK_2  = P2^5;

sbit  SPI_SS_3    = P5^4;
sbit  SPI_MOSI_3  = P4^0;
sbit  SPI_MISO_3  = P4^1;
sbit  SPI_SCLK_3  = P4^3;

sbit  SPI_SS_4    = P3^5;
sbit  SPI_MOSI_4  = P3^4;
sbit  SPI_MISO_4  = P3^3;
sbit  SPI_SCLK_4  = P3^2;

/*  P2  */
sbit  P20 = P2^0;
sbit  P21 = P2^1;
sbit  P22 = P2^2;
sbit  P23 = P2^3;
sbit  P24 = P2^4;
sbit  P25 = P2^5;
sbit  P26 = P2^6;
sbit  P27 = P2^7;

/*  P3  */
sbit  P30 = P3^0;
sbit  P31 = P3^1;
sbit  P32 = P3^2;
sbit  P33 = P3^3;
sbit  P34 = P3^4;
sbit  P35 = P3^5;
sbit  P36 = P3^6;
sbit  P37 = P3^7;

sbit RXD  = P3^0;
sbit TXD  = P3^1;
sbit INT0 = P3^2;
sbit INT1 = P3^3;
sbit T0   = P3^4;
sbit T1   = P3^5;
sbit WR   = P3^6;
sbit RD   = P3^7;

sbit INT2 = P3^6;
sbit INT3 = P3^7;
sbit INT4 = P3^0;
sbit CCP2  = P3^7;

sbit CLKOUT0   = P3^5;
sbit CLKOUT1   = P3^4;

/*  P4  */
sbit  P40 = P4^0;
sbit  P41 = P4^1;
sbit  P42 = P4^2;
sbit  P43 = P4^3;
sbit  P44 = P4^4;
sbit  P45 = P4^5;
sbit  P46 = P4^6;
sbit  P47 = P4^7;

/*  P5  */
sbit  P50 = P5^0;
sbit  P51 = P5^1;
sbit  P52 = P5^2;
sbit  P53 = P5^3;
sbit  P54 = P5^4;
sbit  P55 = P5^5;
sbit  P56 = P5^6;
sbit  P57 = P5^7;

/*  P6  */
sbit  P60 = P6^0;
sbit  P61 = P6^1;
sbit  P62 = P6^2;
sbit  P63 = P6^3;
sbit  P64 = P6^4;
sbit  P65 = P6^5;
sbit  P66 = P6^6;
sbit  P67 = P6^7;

/*  P7  */
sbit  P70 = P7^0;
sbit  P71 = P7^1;
sbit  P72 = P7^2;
sbit  P73 = P7^3;
sbit  P74 = P7^4;
sbit  P75 = P7^5;
sbit  P76 = P7^6;
sbit  P77 = P7^7;


/*  SCON  */
sbit SM0  = SCON^7;	//SM0/FE		SM0 SM1 = 00 ~ 11: 方式0~3
sbit SM1  = SCON^6;	//
sbit SM2  = SCON^5;	//多机通讯
sbit REN  = SCON^4;	//接收允许
sbit TB8  = SCON^3;	//发送数据第8位
sbit RB8  = SCON^2;	//接收数据第8位
sbit TI   = SCON^1;	//发送中断标志位
sbit RI   = SCON^0;	//接收中断标志位

/*  IE   */
sbit EA   = IE^7;	//中断允许总控制位
sbit ELVD = IE^6;	//低压监测中断允许位
sbit EADC = IE^5;	//ADC 中断 允许位
sbit ES   = IE^4;	//串行中断 允许控制位
sbit ET1  = IE^3;	//定时中断1允许控制位
sbit EX1  = IE^2;	//外部中断1允许控制位
sbit ET0  = IE^1;	//定时中断0允许控制位
sbit EX0  = IE^0;	//外部中断0允许控制位

sbit ACC0 = ACC^0;
sbit ACC1 = ACC^1;
sbit ACC2 = ACC^2;
sbit ACC3 = ACC^3;
sbit ACC4 = ACC^4;
sbit ACC5 = ACC^5;
sbit ACC6 = ACC^6;
sbit ACC7 = ACC^7;

sbit B0 = B^0;
sbit B1 = B^1;
sbit B2 = B^2;
sbit B3 = B^3;
sbit B4 = B^4;
sbit B5 = B^5;
sbit B6 = B^6;
sbit B7 = B^7;


//							             7     6     5     4     3     2     1     0     Reset Value
//sfr IE2       = 0xAF;		ETKSUI   ET4   ET3   ES4   ES3   ET2   ESPI  ES2   x000,0000B	//Auxiliary Interrupt   
#define		SPI_INT_ENABLE()		IE2 |=  2	/* 允许SPI中断		*/
#define		SPI_INT_DISABLE()		IE2 &= ~2	/* 允许SPI中断		*/
#define		UART2_INT_ENABLE()		IE2 |=  1	/* 允许串口2中断	*/
#define		UART2_INT_DISABLE()		IE2 &= ~1	/* 允许串口2中断	*/


//                                           7      6      5      4      3      2      1      0      Reset Value
//sfr IP2   = 0xB5; //                    PPWM2FD PI2C   PCMP    PX4  PPWM0FD  PPWM0  PSPI   PS2     0000,0000
#define		PUSB		0x80
#define		PPWM2FD	0x80
#define		PTKSU		0x80
#define		PI2C	0x40
#define		PCMP	0x20
#define		PX4		0x10
#define		PPWM0FD	0x08
#define		PPWM0	0x04
#define		PSPI	0x02
#define		PS2		0x01
//                                           7      6      5      4      3      2      1      0      Reset Value
//sfr IP2H  = 0xB6; //                    PPWM2FDH PI2CH PCMPH   PX4H PPWM0FDH PPWM0H PSPIH  PS2H    0000,0000
#define		PUSBH		0x80
#define		PPWM2FDH	0x80
#define		PTKSUH	0x80
#define		PI2CH		0x40
#define		PCMPH		0x20
#define		PX4H		0x10
#define		PPWM0FDH	0x08
#define		PPWM0H	0x04
#define		PSPIH		0x02
#define		PS2H		0x01

//串口2中断优先级控制
#define 	UART2_Priority(n)			do{if(n == 0) IP2H &= ~PS2H, IP2 &= ~PS2; \
																if(n == 1) IP2H &= ~PS2H, IP2 |= PS2; \
																if(n == 2) IP2H |= PS2H, IP2 &= ~PS2; \
																if(n == 3) IP2H |= PS2H, IP2 |= PS2; \
															}while(0)
//SPI中断优先级控制
#define 	SPI_Priority(n)				do{if(n == 0) IP2H &= ~PSPIH, IP2 &= ~PSPI; \
																if(n == 1) IP2H &= ~PSPIH, IP2 |= PSPI; \
																if(n == 2) IP2H |= PSPIH, IP2 &= ~PSPI; \
																if(n == 3) IP2H |= PSPIH, IP2 |= PSPI; \
															}while(0)
//外部中断4中断优先级控制
#define 	INT4_Priority(n)				do{if(n == 0) IP2H &= ~PX4H, IP2 &= ~PX4; \
																if(n == 1) IP2H &= ~PX4H, IP2 |= PX4; \
																if(n == 2) IP2H |= PX4H, IP2 &= ~PX4; \
																if(n == 3) IP2H |= PX4H, IP2 |= PX4; \
															}while(0)
//比较器中断优先级控制
#define 	CMP_Priority(n)				do{if(n == 0) IP2H &= ~PCMPH, IP2 &= ~PCMP; \
																if(n == 1) IP2H &= ~PCMPH, IP2 |= PCMP; \
																if(n == 2) IP2H |= PCMPH, IP2 &= ~PCMP; \
																if(n == 3) IP2H |= PCMPH, IP2 |= PCMP; \
															}while(0)
//I2C中断优先级控制
#define 	I2C_Priority(n)				do{if(n == 0) IP2H &= ~PI2CH, IP2 &= ~PI2C; \
																if(n == 1) IP2H &= ~PI2CH, IP2 |= PI2C; \
																if(n == 2) IP2H |= PI2CH, IP2 &= ~PI2C; \
																if(n == 3) IP2H |= PI2CH, IP2 |= PI2C; \
															}while(0)
//增强型PWM0中断优先级控制
#define 	PWM0_Priority(n)			do{if(n == 0) IP2H &= ~PPWM0H, IP2 &= ~PPWM0; \
																if(n == 1) IP2H &= ~PPWM0H, IP2 |= PPWM0; \
																if(n == 2) IP2H |= PPWM0H, IP2 &= ~PPWM0; \
																if(n == 3) IP2H |= PPWM0H, IP2 |= PPWM0; \
															}while(0)
//增强型PWM0异常检测中断优先级控制
#define 	PWM0FD_Priority(n)		do{if(n == 0) IP2H &= ~PPWM0FDH, IP2 &= ~PPWM0FD; \
																if(n == 1) IP2H &= ~PPWM0FDH, IP2 |= PPWM0FD; \
																if(n == 2) IP2H |= PPWM0FDH, IP2 &= ~PPWM0FD; \
																if(n == 3) IP2H |= PPWM0FDH, IP2 |= PPWM0FD; \
															}while(0)
//增强型PWM2异常检测中断优先级控制
#define 	PWM2FD_Priority(n)		do{if(n == 0) IP2H &= ~PPWM2FDH, IP2 &= ~PPWM2FD; \
																if(n == 1) IP2H &= ~PPWM2FDH, IP2 |= PPWM2FD; \
																if(n == 2) IP2H |= PPWM2FDH, IP2 &= ~PPWM2FD; \
																if(n == 3) IP2H |= PPWM2FDH, IP2 |= PPWM2FD; \
															}while(0)
//触摸按键中断优先级控制
#define 	PTKSU_Priority(n)			do{if(n == 0) IP2H &= ~PTKSUH, IP2 &= ~PTKSU; \
																if(n == 1) IP2H &= ~PTKSUH, IP2 |= PTKSU; \
																if(n == 2) IP2H |= PTKSUH, IP2 &= ~PTKSU; \
																if(n == 3) IP2H |= PTKSUH, IP2 |= PTKSU; \
															}while(0)

//                                           7      6      5     4      3      2      1     0      Reset Value
//sfr IP3   = 0xDF; //                    PPWM4FD PPWM5  PPWM4  PPWM3  PPWM2  PPWM1  PS4   PS3     0000,0000
#define		PPWM4FD	0x80
#define		PPWM5		0x40
#define		PPWM4		0x20
#define		PPWM3		0x10
#define		PPWM2		0x08
#define		PPWM1		0x04
#define		PRTC		0x04
#define		PS4			0x02
#define		PS3			0x01
//                                           7        6       5      4       3       2     1     0      Reset Value
//sfr IP3H  = 0xEE; //                    PPWM4FDH PPWM5H  PPWM4H  PPWM3H  PPWM2H  PPWM1H PS4H  PS3H    0000,0000
#define		PPWM4FDH	0x80
#define		PPWM5H		0x40
#define		PPWM4H		0x20
#define		PPWM3H		0x10
#define		PPWM2H	0x08
#define		PPWM1H	0x04
#define		PRTCH		0x04
#define		PS4H		0x02
#define		PS3H		0x01

#ifdef STC8Hxx

//增强型PWM1中断优先级控制
#define 	PWM1_Priority(n)			do{if(n == 0) IP2H &= ~PPWM1H, IP2 &= ~PPWM1; \
																if(n == 1) IP2H &= ~PPWM1H, IP2 |= PPWM1; \
																if(n == 2) IP2H |= PPWM1H, IP2 &= ~PPWM1; \
																if(n == 3) IP2H |= PPWM1H, IP2 |= PPWM1; \
															}while(0)
//增强型PWM2中断优先级控制
#define 	PWM2_Priority(n)			do{if(n == 0) IP2H &= ~PPWM2H, IP2 &= ~PPWM2; \
																if(n == 1) IP2H &= ~PPWM2H, IP2 |= PPWM2; \
																if(n == 2) IP2H |= PPWM2H, IP2 &= ~PPWM2; \
																if(n == 3) IP2H |= PPWM2H, IP2 |= PPWM2; \
															}while(0)
//USB中断优先级控制
#define 	USB_Priority(n)				do{if(n == 0) IP2H &= ~PUSBH, IP2 &= ~PUSB; \
																if(n == 1) IP2H &= ~PUSBH, IP2 |= PUSB; \
																if(n == 2) IP2H |= PUSBH, IP2 &= ~PUSB; \
																if(n == 3) IP2H |= PUSBH, IP2 |= PUSB; \
															}while(0)
//RTC中断优先级控制
#define 	RTC_Priority(n)				do{if(n == 0) IP3H &= ~PRTCH, IP3 &= ~PRTC; \
																if(n == 1) IP3H &= ~PRTCH, IP3 |= PRTC; \
																if(n == 2) IP3H |= PRTCH, IP3 &= ~PRTC; \
																if(n == 3) IP3H |= PRTCH, IP3 |= PRTC; \
															}while(0)
#else

//增强型PWM1中断优先级控制
#define 	PWM1_Priority(n)			do{if(n == 0) IP3H &= ~PPWM1H, IP3 &= ~PPWM1; \
																if(n == 1) IP3H &= ~PPWM1H, IP3 |= PPWM1; \
																if(n == 2) IP3H |= PPWM1H, IP3 &= ~PPWM1; \
																if(n == 3) IP3H |= PPWM1H, IP3 |= PPWM1; \
															}while(0)
//增强型PWM2中断优先级控制
#define 	PWM2_Priority(n)			do{if(n == 0) IP3H &= ~PPWM2H, IP3 &= ~PPWM2; \
																if(n == 1) IP3H &= ~PPWM2H, IP3 |= PPWM2; \
																if(n == 2) IP3H |= PPWM2H, IP3 &= ~PPWM2; \
																if(n == 3) IP3H |= PPWM2H, IP3 |= PPWM2; \
															}while(0)

#endif

//增强型PWM3中断优先级控制
#define 	PWM3_Priority(n)			do{if(n == 0) IP3H &= ~PPWM3H, IP3 &= ~PPWM3; \
																if(n == 1) IP3H &= ~PPWM3H, IP3 |= PPWM3; \
																if(n == 2) IP3H |= PPWM3H, IP3 &= ~PPWM3; \
																if(n == 3) IP3H |= PPWM3H, IP3 |= PPWM3; \
															}while(0)
//增强型PWM4中断优先级控制
#define 	PWM4_Priority(n)			do{if(n == 0) IP3H &= ~PPWM4H, IP3 &= ~PPWM4; \
																if(n == 1) IP3H &= ~PPWM4H, IP3 |= PPWM4; \
																if(n == 2) IP3H |= PPWM4H, IP3 &= ~PPWM4; \
																if(n == 3) IP3H |= PPWM4H, IP3 |= PPWM4; \
															}while(0)
//增强型PWM5中断优先级控制
#define 	PWM5_Priority(n)			do{if(n == 0) IP3H &= ~PPWM5H, IP3 &= ~PPWM5; \
																if(n == 1) IP3H &= ~PPWM5H, IP3 |= PPWM5; \
																if(n == 2) IP3H |= PPWM5H, IP3 &= ~PPWM5; \
																if(n == 3) IP3H |= PPWM5H, IP3 |= PPWM5; \
															}while(0)
//增强型PWM4异常检测中断优先级控制
#define 	PWM4FD_Priority(n)		do{if(n == 0) IP3H &= ~PPWM4FDH, IP3 &= ~PPWM4FD; \
																if(n == 1) IP3H &= ~PPWM4FDH, IP3 |= PPWM4FD; \
																if(n == 2) IP3H |= PPWM4FDH, IP3 &= ~PPWM4FD; \
																if(n == 3) IP3H |= PPWM4FDH, IP3 |= PPWM4FD; \
															}while(0)
//串口3中断优先级控制
#define 	UART3_Priority(n)			do{if(n == 0) IP3H &= ~PS3H, IP3 &= ~PS3; \
																if(n == 1) IP3H &= ~PS3H, IP3 |= PS3; \
																if(n == 2) IP3H |= PS3H, IP3 &= ~PS3; \
																if(n == 3) IP3H |= PS3H, IP3 |= PS3; \
															}while(0)
//串口4中断优先级控制
#define 	UART4_Priority(n)			do{if(n == 0) IP3H &= ~PS4H, IP3 &= ~PS4; \
																if(n == 1) IP3H &= ~PS4H, IP3 |= PS4; \
																if(n == 2) IP3H |= PS4H, IP3 &= ~PS4; \
																if(n == 3) IP3H |= PS4H, IP3 |= PS4; \
															}while(0)

//                                          7     6     5    4    3    2    1    0    Reset Value
//sfr IP      = 0xB8; //中断优先级低位      PPCA  PLVD  PADC  PS   PT1  PX1  PT0  PX0   0000,0000
//--------
sbit PPCA	= IP^7;	//PCA 模块中断优先级
sbit PLVD	= IP^6;	//低压监测中断优先级
sbit PADC	= IP^5;	//ADC 中断优先级
sbit PS  	= IP^4;	//串行中断0优先级设定位
sbit PT1	= IP^3;	//定时中断1优先级设定位
sbit PX1	= IP^2;	//外部中断1优先级设定位
sbit PT0	= IP^1;	//定时中断0优先级设定位
sbit PX0	= IP^0;	//外部中断0优先级设定位

//                                           7      6      5      4      3      2      1      0      Reset Value
//sfr IPH   = 0xB7; //中断优先级高位       PPCAH  PLVDH   PADCH   PSH   PT1H    PX1H   PT0H   PX0H    0000,0000
#define		PPCAH	0x80
#define		PLVDH	0x40
#define		PADCH	0x20
#define		PSH		0x10
#define		PT1H	0x08
#define		PX1H	0x04
#define		PT0H	0x02
#define		PX0H	0x01

//外部中断0中断优先级控制
#define 	INT0_Priority(n)			do{if(n == 0) IPH &= ~PX0H, PX0 = 0; \
																if(n == 1) IPH &= ~PX0H, PX0 = 1; \
																if(n == 2) IPH |= PX0H, PX0 = 0; \
																if(n == 3) IPH |= PX0H, PX0 = 1; \
															}while(0)
//外部中断1中断优先级控制
#define 	INT1_Priority(n)			do{if(n == 0) IPH &= ~PX1H, PX1 = 0; \
																if(n == 1) IPH &= ~PX1H, PX1 = 1; \
																if(n == 2) IPH |= PX1H, PX1 = 0; \
																if(n == 3) IPH |= PX1H, PX1 = 1; \
															}while(0)
//定时器0中断优先级控制
#define 	Timer0_Priority(n)		do{if(n == 0) IPH &= ~PT0H, PT0 = 0; \
																if(n == 1) IPH &= ~PT0H, PT0 = 1; \
																if(n == 2) IPH |= PT0H, PT0 = 0; \
																if(n == 3) IPH |= PT0H, PT0 = 1; \
															}while(0)
//定时器1中断优先级控制
#define 	Timer1_Priority(n)		do{if(n == 0) IPH &= ~PT1H, PT1 = 0; \
																if(n == 1) IPH &= ~PT1H, PT1 = 1; \
																if(n == 2) IPH |= PT1H, PT1 = 0; \
																if(n == 3) IPH |= PT1H, PT1 = 1; \
															}while(0)
//串口1中断优先级控制
#define 	UART1_Priority(n)			do{if(n == 0) IPH &= ~PSH, PS = 0; \
																if(n == 1) IPH &= ~PSH, PS = 1; \
																if(n == 2) IPH |= PSH, PS = 0; \
																if(n == 3) IPH |= PSH, PS = 1; \
															}while(0)
//ADC中断优先级控制
#define 	ADC_Priority(n)				do{if(n == 0) IPH &= ~PADCH, PADC = 0; \
																if(n == 1) IPH &= ~PADCH, PADC = 1; \
																if(n == 2) IPH |= PADCH, PADC = 0; \
																if(n == 3) IPH |= PADCH, PADC = 1; \
															}while(0)
//低压检测中断优先级控制
#define 	LVD_Priority(n)				do{if(n == 0) IPH &= ~PLVDH, PADC = 0; \
																if(n == 1) IPH &= ~PLVDH, PADC = 1; \
																if(n == 2) IPH |= PLVDH, PADC = 0; \
																if(n == 3) IPH |= PLVDH, PADC = 1; \
															}while(0)
//CCP/PCA/PWM中断优先级控制
#define 	PCA_Priority(n)				do{if(n == 0) IPH &= ~PPCAH, PPCA = 0; \
																if(n == 1) IPH &= ~PPCAH, PPCA = 1; \
																if(n == 2) IPH |= PPCAH, PPCA = 0; \
																if(n == 3) IPH |= PPCAH, PPCA = 1; \
															}while(0)

//#define		PCA_InterruptFirst()	PPCA = 1
//#define		LVD_InterruptFirst()	PLVD = 1
//#define		ADC_InterruptFirst()	PADC = 1
//#define		UART1_InterruptFirst()	PS   = 1
//#define		Timer1_InterruptFirst()	PT1  = 1
//#define		INT1_InterruptFirst()	PX1  = 1
//#define		Timer0_InterruptFirst()	PT0  = 1
//#define		INT0_InterruptFirst()	PX0  = 1


/*************************************************************************************************/


//                       7      6     5    4    3    2     1      0        Reset Value
//sfr CMPCR1 = 0xE6;   CMPEN  CMPIF  PIE  NIE  PIS  NIS  CMPOE  CMPRES      00000000B
#define	CMPEN	0x80	//1: 允许比较器, 0: 禁止,关闭比较器电源
#define	CMPIF	0x40	//比较器中断标志, 包括上升沿或下降沿中断, 软件清0
#define	PIE		0x20	//1: 比较结果由0变1, 产生上升沿中断
#define	NIE		0x10	//1: 比较结果由1变0, 产生下降沿中断
#define	PIS		0x08	//输入正极性选择, 0: 选择内部P3.7做正输入,           1: 由ADC_CHS[3:0]所选择的ADC输入端做正输入.
#define	NIS		0x04	//输入负极性选择, 0: 选择内部BandGap电压BGv做负输入, 1: 选择外部P3.6做输入.
#define	CMPOE	0x02	//1: 允许比较结果输出, 0: 禁止.
#define	CMPRES	0x01	//比较结果, 1: CMP+电平高于CMP-,  0: CMP+电平低于CMP-,  只读

#define	CMP_P_P37	0x00	//输入正极性选择, 0: 选择内部P3.7做正输入
#define	CMP_P_ADC	0x08	//输入正极性选择, 1: 由ADC_CHS[3:0]所选择的ADC输入端做正输入.
#define	CMP_N_GAP	0x00	//输入负极性选择, 0: 选择内部BandGap电压BGv做负输入.
#define	CMP_N_P36	0x04	//输入负极性选择, 1: 选择外部P3.6做输入.

#define	CMPO_P34()	P_SW2 &= ~0x08	//结果输出到P3.4.
#define	CMPO_P41()	P_SW2 |=  0x08	//结果输出到P4.1.

//                       7        6       5  4  3  2  1  0    Reset Value
//sfr CMPCR2 = 0xE7;   INVCMPO  DISFLT       LCDTY[5:0]       00001001B
#define	INVCMPO	0x80	//1: 比较器输出IO取反,  0: 不取反
#define	DISFLT	0x40	//1: 关闭0.1uF滤波,   	0: 允许
#define	LCDTY	0x00	//0~63, 比较结果变化延时周期数



/*************************************************************************************************/
//                     7     6     5    4    3    2   1   0       Reset Value
//sfr SCON  = 0x98;   SM0   SM1   SM2  REN  TB8  RB8  TI  RI      00000000B		 //S1 Control

#define		S1_DoubleRate()		PCON  |=  0x80
#define		S1_SHIFT()			SCON  &=  0x3f

#define		S1_8bit()			SCON   =  (SCON & 0x3f) | 0x40
#define		S1_9bit()			SCON   =  (SCON & 0x3f) | 0xc0
#define		S1_RX_Enable()		SCON  |=  0x10
#define		S1_RX_Disable()		SCON  &= ~0x10
#define		TI1					TI					/* 判断TI1是否发送完成								 */
#define		RI1					RI					/* 判断RI1是否接收完成								 */
#define		SET_TI1()			TI = 1				/* 设置TI1(引起中断)								 */
#define		CLR_TI1()			TI = 0				/* 清除TI1											 */
#define		CLR_RI1()			RI = 0				/* 清除RI1											 */
#define		S1TB8_SET()			TB8 = 1				/* 设置TB8											 */
#define		S1TB8_CLR()			TB8 = 0				/* 清除TB8											 */
#define		S1_Int_Enable()		ES     =  1			/* 串口1允许中断									 */
#define		S1_Int_Disable()	ES     =  0			/* 串口1禁止中断									 */
#define 	S1_BRT_UseTimer1()	AUXR  &= ~1
#define 	S1_BRT_UseTimer2()	AUXR  |=  1
#define		S1_USE_P30P31()		P_SW1 &= ~0xc0						//UART1 使用P30 P31口	默认
#define		S1_USE_P36P37()		P_SW1  =  (P_SW1 & ~0xc0) | 0x40	//UART1 使用P36 P37口
#define		S1_USE_P16P17()		P_SW1  =  (P_SW1 & ~0xc0) | 0x80	//UART1 使用P16 P17口
#define		S1_USE_P43P44()		P_SW1 |=  0xc0						//UART1 使用P43 P44口
//#define		S1_TXD_RXD_SHORT()	PCON2 |=  (1<<4)	//将TXD与RXD连接中继输出
//#define		S1_TXD_RXD_OPEN()	PCON2 &= ~(1<<4)	//将TXD与RXD连接中继断开	默认

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S2CON = 0x9A;		S2SM0    -    S2SM2  S2REN  S2TB8  S2RB8  S2TI  S2RI      00000000B		 //S2 Control

#define		S2_MODE0()			S2CON &= ~(1<<7)	/* 串口2模式0，8位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_MODE1()			S2CON |=  (1<<7)	/* 串口2模式1，9位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_8bit()			S2CON &= ~(1<<7)	/* 串口2模式0，8位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_9bit()			S2CON |=  (1<<7)	/* 串口2模式1，9位UART，波特率 = 定时器2的溢出率 / 4 */
#define		S2_RX_Enable()		S2CON |=  (1<<4)	/* 允许串2接收										 */
#define		S2_RX_Disable()		S2CON &= ~(1<<4)	/* 禁止串2接收										 */
#define		TI2					(S2CON & 2) 		/* 判断TI2是否发送完成								 */
#define		RI2					(S2CON & 1) 		/* 判断RI2是否接收完成								 */
#define		SET_TI2()			S2CON |=  (1<<1)	/* 设置TI2(引起中断)								 */
#define		CLR_TI2()			S2CON &= ~(1<<1)	/* 清除TI2											 */
#define		CLR_RI2()			S2CON &= ~1			/* 清除RI2											 */
#define		S2TB8_SET()			S2CON |=  (1<<3)	/* 设置TB8											 */
#define		S2TB8_CLR()			S2CON &= ~(1<<3)	/* 清除TB8											 */
#define		S2_Int_Enable()		IE2   |=  1			/* 串口2允许中断									 */
#define		S2_Int_Disable()	IE2   &= ~1			/* 串口2禁止中断									 */
#define		S2_USE_P10P11()		P_SW2 &= ~1			/* UART2 使用P1口	默认							 */
#define		S2_USE_P46P47()		P_SW2 |=  1			/* UART2 使用P4口									 */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S3CON = 0xAC;		S3SM0  S3ST3  S3SM2  S3REN  S3TB8  S3RB8  S3TI  S3RI      00000000B		 //S3 Control

#define		S3_MODE0()			S3CON &= ~(1<<7)	/* 串口3模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_MODE1()			S3CON |=  (1<<7)	/* 串口3模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_8bit()			S3CON &= ~(1<<7)	/* 串口3模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_9bit()			S3CON |=  (1<<7)	/* 串口3模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S3_RX_Enable()		S3CON |=  (1<<4)	/* 允许串3接收									     */
#define		S3_RX_Disable()		S3CON &= ~(1<<4)	/* 禁止串3接收									     */
#define		TI3					(S3CON & 2) != 0	/* 判断TI3是否发送完成								 */
#define		RI3					(S3CON & 1) != 0	/* 判断RI3是否接收完成								 */
#define		SET_TI3()			S3CON |=  (1<<1)	/* 设置TI3(引起中断)								 */
#define		CLR_TI3()			S3CON &= ~(1<<1)	/* 清除TI3											 */
#define		CLR_RI3()			S3CON &= ~1			/* 清除RI3											 */
#define		S3TB8_SET()			S3CON |=  (1<<3)	/* 设置TB8											 */
#define		S3TB8_CLR()			S3CON &= ~(1<<3)	/* 清除TB8											 */
#define		S3_Int_Enable()		IE2   |=  (1<<3)	/* 串口3允许中断								     */
#define		S3_Int_Disable()	IE2   &= ~(1<<3)	/* 串口3禁止中断								     */
#define 	S3_BRT_UseTimer3()	S3CON |=  (1<<6)	/* BRT select Timer3								 */
#define 	S3_BRT_UseTimer2()	S3CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S3_USE_P00P01()		P_SW2 &= ~2			/* UART3 使用P0口	默认						     */
#define		S3_USE_P50P51()		P_SW2 |=  2			/* UART3 使用P5口								     */

//						  7      6      5      4      3      2     1     0        Reset Value
//sfr S4CON = 0x84;		S4SM0  S4ST4  S4SM2  S4REN  S4TB8  S4RB8  S4TI  S4RI      00000000B		 //S4 Control

#define		S4_MODE0()			S4CON &= ~(1<<7)	/* 串口4模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_MODE1()			S4CON |=  (1<<7)	/* 串口4模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_8bit()			S4CON &= ~(1<<7)	/* 串口4模式0，8位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_9bit()			S4CON |=  (1<<7)	/* 串口4模式1，9位UART，波特率 = 定时器的溢出率 / 4  */
#define		S4_RX_Enable()		S4CON |=  (1<<4)	/* 允许串4接收									     */
#define		S4_RX_Disable()		S4CON &= ~(1<<4)	/* 禁止串4接收									     */
#define		TI4					(S4CON & 2) != 0	/* 判断TI3是否发送完成							     */
#define		RI4					(S4CON & 1) != 0	/* 判断RI3是否接收完成							     */
#define		SET_TI4()			S4CON |=  2			/* 设置TI3(引起中断)							     */
#define		CLR_TI4()			S4CON &= ~2			/* 清除TI3										     */
#define		CLR_RI4()			S4CON &= ~1			/* 清除RI3										     */
#define		S4TB8_SET()			S4CON |=  8			/* 设置TB8										     */
#define		S4TB8_CLR()			S4CON &= ~8			/* 清除TB8										     */
#define		S4_Int_Enable()		IE2   |=  (1<<4)	/* 串口4允许中断								     */
#define		S4_Int_Disable()	IE2   &= ~(1<<4)	/* 串口4禁止中断								     */
#define 	S4_BRT_UseTimer4()	S4CON |=  (1<<6)	/* BRT select Timer4								 */
#define 	S4_BRT_UseTimer2()	S4CON &= ~(1<<6)	/* BRT select Timer2								 */
#define		S4_USE_P02P03()		P_SW2 &= ~4			/* UART4 使用P0口	默认						     */
#define		S4_USE_P52P53()		P_SW2 |=  4			/* UART4 使用P5口								     */



/**********************************************************/
//						   7     6       5      4     3      2      1      0    Reset Value
//sfr AUXR  = 0x8E;		T0x12 T1x12 UART_M0x6  T2R  T2_C/T T2x12 EXTRAM  S1ST2  0000,0000	//Auxiliary Register 

#define 	InternalXdata_Disable()		AUXR |=  2		/* 禁止使用内部xdata, 所有访问xdata都是访问外部xdata  */
#define 	InternalXdata_Enable()		AUXR &= ~2		/* 允许使用内部xdata, 当访问的地址在内部xdata范围时, 访问内部的xadta, 当地址超过内部xdata时, 访问外部xdata  */
#define		S1_M0x6()					AUXR |=  (1<<5)	/* UART Mode0 Speed is 6x Standard       */
#define		S1_M0x1()					AUXR &= ~(1<<5)	/* default,	UART Mode0 Speed is Standard */

//====================================
#define		Timer0_16bitAutoReload()	TMOD &= ~0x03					/* 16位自动重装	*/
#define		Timer0_16bit()				TMOD  = (TMOD & ~0x03) | 0x01	/* 16位         */
#define		Timer0_8bitAutoReload()		TMOD  = (TMOD & ~0x03) | 0x02	/* 8位自动重装	*/
#define		Timer0_16bitAutoRL_NoMask()	TMOD |=  0x03		/* 16位自动重装不可屏蔽中断	*/
#define 	Timer0_Run()	 			TR0 = 1				/* 允许定时器0计数			*/
#define 	Timer0_Stop()	 			TR0 = 0				/* 禁止定时器0计数			*/
#define		Timer0_Gate_INT0_P32()		TMOD |=  (1<<3)		/* 时器0由外部INT0高电平允许定时计数 */
#define		Timer0_AsTimer()			TMOD &= ~(1<<2)		/* 时器0用做定时器	*/
#define		Timer0_AsCounter()			TMOD |=  (1<<2)		/* 时器0用做计数器	*/
#define		Timer0_AsCounterP34()		TMOD |=  (1<<2)		/* 时器0用做计数器	*/
#define 	Timer0_1T()					AUXR |=  (1<<7)		/* Timer0 clodk = fo	*/
#define 	Timer0_12T()				AUXR &= ~(1<<7)		/* Timer0 clodk = fo/12	12分频,	default	*/
#define		Timer0_CLKO_Enable()		INT_CLKO |=  1			/* 允许 T0 溢出脉冲在T0(P3.5)脚输出，Fck0 = 1/2 T0 溢出率，T0可以1T或12T。	*/
#define		Timer0_CLKO_Disable()		INT_CLKO &= ~1
#define		Timer0_CLKO_Enable_P34()	INT_CLKO |=  1			/* 允许 T0 溢出脉冲在T0(P3.5)脚输出，Fck0 = 1/2 T0 溢出率，T0可以1T或12T。	*/
#define		Timer0_CLKO_Disable_P34()	INT_CLKO &= ~1
#define 	Timer0_InterruptEnable()	ET0 = 1				/* 允许Timer1中断.*/
#define 	Timer0_InterruptDisable()	ET0 = 0				/* 禁止Timer1中断.*/

#define		T0_Load(n)					TH0 = (n) / 256,	TL0 = (n) % 256
#define		T0_Load_us_1T(n)			Timer0_AsTimer(),Timer0_1T(), Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/1000)*(n))/1000)/256, TL0=(65536-((MAIN_Fosc/1000)*(n))/1000)%256
#define		T0_Load_us_12T(n)			Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-((MAIN_Fosc/12000)*(n))/1000)/256,TL0=(65536-((MAIN_Fosc/12000)*(n))/1000)%256
#define		T0_Frequency_1T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_1T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit0,TR0=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T0_Frequency_12T_P35(n)		ET0=0,Timer0_AsTimer(),Timer0_12T(),Timer0_16bitAutoReload(),TH0=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL0=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit0,TR0=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define		Timer1_16bitAutoReload()	TMOD &= ~0x30					/* 16位自动重装	*/
#define		Timer1_16bit()				TMOD  = (TMOD & ~0x30) | 0x10	/* 16位			*/
#define		Timer1_8bitAutoReload()		TMOD  = (TMOD & ~0x30) | 0x20	/* 8位自动重装	*/
#define 	Timer1_Run()	 			TR1 = 1				/* 允许定时器1计数			*/
#define 	Timer1_Stop()	 			TR1 = 0				/* 禁止定时器1计数			*/
#define		Timer1_Gate_INT1_P33()		TMOD |=  (1<<7)		/* 时器1由外部INT1高电平允许定时计数	*/
#define		Timer1_AsTimer()			TMOD &= ~(1<<6)		/* 时器1用做定时器			*/
#define		Timer1_AsCounter()			TMOD |=  (1<<6)		/* 时器1用做计数器			*/
#define		Timer1_AsCounterP35()		TMOD |=  (1<<6)		/* 时器1用做计数器			*/
#define 	Timer1_1T()					AUXR |=  (1<<6)		/* Timer1 clodk = fo		*/
#define 	Timer1_12T()				AUXR &= ~(1<<6)		/* Timer1 clodk = fo/12	12分频,	default	*/
#define		Timer1_CLKO_Enable()		INT_CLKO |=  2			/* 允许 T1 溢出脉冲在T1(P3.4)脚输出，Fck1 = 1/2 T1 溢出率，T1可以1T或12T。	*/
#define		Timer1_CLKO_Disable()		INT_CLKO &= ~2
#define		Timer1_CLKO_Enable_P35()	INT_CLKO |=  2			/* 允许 T1 溢出脉冲在T1(P3.4)脚输出，Fck1 = 1/2 T1 溢出率，T1可以1T或12T。	*/
#define		Timer1_CLKO_Disable_P35()	INT_CLKO &= ~2
#define 	Timer1_InterruptEnable()	ET1 = 1				/* 允许Timer1中断.	*/
#define 	Timer1_InterruptDisable()	ET1 = 0				/* 禁止Timer1中断.	*/

#define		T1_Load(n)					TH1 = (n) / 256,	TL1 = (n) % 256
#define		T1_Load_us_1T(n)			Timer1_AsTimer(),Timer1_1T(), Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL1=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T1_Load_us_12T(n)			Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL1=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T1_Frequency_1T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_1T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/2)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/2)/(n))%256,INT_CLKO |= bit1,TR1=1		/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T1_Frequency_12T_P34(n)		ET1=0,Timer1_AsTimer(),Timer1_12T(),Timer1_16bitAutoReload(),TH1=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL1=(65536-(n/2+MAIN_Fosc/24)/(n))%256,INT_CLKO |= bit1,TR1=1	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer2_Run()	 			AUXR |=  (1<<4)	/* 允许定时器2计数	*/
#define 	Timer2_Stop()	 			AUXR &= ~(1<<4)	/* 禁止定时器2计数	*/
#define		Timer2_AsTimer()			AUXR &= ~(1<<3)	/* 时器2用做定时器	*/
#define		Timer2_AsCounter()			AUXR |=  (1<<3)	/* 时器2用做计数器	*/
#define		Timer2_AsCounterP31()		AUXR |=  (1<<3)	/* 时器2用做计数器	*/
#define 	Timer2_1T()					AUXR |=  (1<<2)	/* Timer0 clock = fo	*/
#define 	Timer2_12T()				AUXR &= ~(1<<2)	/* Timer0 clock = fo/12	12分频,	default	*/
#define		Timer2_CLKO_Enable()		INT_CLKO |=  4		/* 允许 T2 溢出脉冲在P1.3脚输出，Fck2 = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer2_CLKO_Disable()		INT_CLKO &= ~4
#define		Timer2_CLKO_Enable_P13()	INT_CLKO |=  4		/* 允许 T2 溢出脉冲在P1.3脚输出，Fck2 = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer2_CLKO_Disable_P13()	INT_CLKO &= ~4
#define 	Timer2_InterruptEnable()	IE2  |=  (1<<2)	/* 允许Timer2中断.	*/
#define 	Timer2_InterruptDisable()	IE2  &= ~(1<<2)	/* 禁止Timer2中断.	*/

#define		T2_Load(n)					TH2 = (n) / 256,	TL2 = (n) % 256
#define		T2_Load_us_1T(n)			Timer2_AsTimer(),Timer2_1T(), TH2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL2=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T2_Load_us_12T(n)			Timer2_AsTimer(),Timer2_12T(),TH2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL2=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T2_Frequency_1T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_1T(), TH2=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL2=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T2_Frequency_12T_P30(n)		Timer2_InterruptDisable(),Timer2_AsTimer(),Timer2_12T(),TH2=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL2=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer2_CLKO_Enable_P30(),Timer2_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer3_Run()	 			T4T3M |=  (1<<3)	/* 允许定时器3计数	*/
#define 	Timer3_Stop()	 			T4T3M &= ~(1<<3)	/* 禁止定时器3计数	*/
#define		Timer3_AsTimer()			T4T3M &= ~(1<<2)	/* 时器3用做定时器	*/
#define		Timer3_AsCounter()			T4T3M |=  (1<<2)	/* 时器3用做计数器, P0.5为外部脉冲	*/
#define		Timer3_AsCounterP05()		T4T3M |=  (1<<2)	/* 时器3用做计数器, P0.5为外部脉冲	*/
#define 	Timer3_1T()					T4T3M |=  (1<<1)	/* 1T模式	*/
#define 	Timer3_12T()				T4T3M &= ~(1<<1)	/* 12T模式,	default	*/
#define		Timer3_CLKO_Enable()		T4T3M |=  1			/* 允许T3溢出脉冲在T3(P0.4)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer3_CLKO_Disable()		T4T3M &= ~1			/* 禁止T3溢出脉冲在T3(P0.4)脚输出	*/
#define		Timer3_CLKO_Enable_P04()	T4T3M |=  1			/* 允许T3溢出脉冲在T3(P0.4)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer3_CLKO_Disable_P04()	T4T3M &= ~1			/* 禁止T3溢出脉冲在T3(P0.4)脚输出	*/
#define 	Timer3_InterruptEnable()	IE2  |=  (1<<5)		/* 允许Timer3中断.	*/
#define 	Timer3_InterruptDisable()	IE2  &= ~(1<<5)		/* 禁止Timer3中断.	*/

#define		T3_Load(n)					TH3 = (n) / 256,	TL3 = (n) % 256
#define		T3_Load_us_1T(n)			Timer3_AsTimer(),Timer3_1T(), TH3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL3=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T3_Load_us_12T(n)			Timer3_AsTimer(),Timer3_12T(),TH3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL3=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T3_Frequency_1T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_1T(), TH3=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL3=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T3_Frequency_12T_P04(n)		Timer3_InterruptDisable(),Timer3_AsTimer(),Timer3_12T(),TH3=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL3=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer3_CLKO_P04_Enable,Timer3_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */

//====================================
#define 	Timer4_Run()	 			T4T3M |=  (1<<7)	/* 允许定时器4计数	*/
#define 	Timer4_Stop()	 			T4T3M &= ~(1<<7)	/* 禁止定时器4计数	*/
#define		Timer4_AsTimer()			T4T3M &= ~(1<<6)	/* 时器4用做定时器  */
#define		Timer4_AsCounter()			T4T3M |=  (1<<6)	/* 时器4用做计数器, P0.7为外部脉冲	*/
#define		Timer4_AsCounterP07()		T4T3M |=  (1<<6)	/* 时器4用做计数器, P0.7为外部脉冲	*/
#define 	Timer4_1T()					T4T3M |=  (1<<5)	/* 1T模式	*/
#define 	Timer4_12T()				T4T3M &= ~(1<<5)	/* 12T模式,	default	*/
#define		Timer4_CLKO_Enable()		T4T3M |=  (1<<4)	/* 允许T4溢出脉冲在T4(P0.6)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer4_CLKO_Disable()		T4T3M &= ~(1<<4)	/* 禁止T4溢出脉冲在T4(P0.6)脚输出	*/
#define		Timer4_CLKO_Enable_P06()	T4T3M |=  (1<<4)	/* 允许T4溢出脉冲在T4(P0.6)脚输出，Fck = 1/2 T2 溢出率，T2可以1T或12T。	*/
#define		Timer4_CLKO_Disable_P06()	T4T3M &= ~(1<<4)	/* 禁止T4溢出脉冲在T4(P0.6)脚输出	*/
#define 	Timer4_InterruptEnable()	IE2  |=  (1<<6)		/* 允许Timer4中断.	*/
#define 	Timer4_InterruptDisable()	IE2  &= ~(1<<6)		/* 禁止Timer4中断.	*/

#define		T4_Load(n)					TH4 = (n) / 256,	TL4 = (n) % 256
#define		T4_Load_us_1T(n)			Timer4_AsTimer(),Timer4_1T(), TH4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)/256, TL4=(65536-((MAIN_Fosc/1000)*(n)+500)/1000)%256
#define		T4_Load_us_12T(n)			Timer4_AsTimer(),Timer4_12T(),TH4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)/256,TL4=(65536-((MAIN_Fosc/12000)*(n)+500)/1000)%256
#define		T4_Frequency_1T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_1T(), TH4=(65536-(n/2+MAIN_Fosc/2)/(n))/256, TL4=(65536-(n/2+MAIN_Fosc/2)/(n))%256, Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
#define		T4_Frequency_12T_P06(n)		Timer4_InterruptDisable(),Timer4_AsTimer(),Timer4_12T(),TH4=(65536-(n/2+MAIN_Fosc/24)/(n))/256,TL4=(65536-(n/2+MAIN_Fosc/24)/(n))%256,Timer4_CLKO_P06_Enable(),Timer4_Run()	/* fx=fosc/(2*M)/n,  M=1 or M=12 */
//====================================================================================================================

//sfr WDT_CONTR = 0xC1; //Watch-Dog-Timer Control register
//                                      7     6     5      4       3      2   1   0     Reset Value
//                                  WDT_FLAG  -  EN_WDT CLR_WDT IDLE_WDT PS2 PS1 PS0    xx00,0000
#define D_WDT_FLAG			(1<<7)
#define D_EN_WDT			(1<<5)
#define D_CLR_WDT			(1<<4)	/* auto clear	*/
#define D_IDLE_WDT			(1<<3)	/* WDT counter when Idle	*/
#define D_WDT_SCALE_2		0
#define D_WDT_SCALE_4		1
#define D_WDT_SCALE_8		2		/* T=393216*N/fo	*/
#define D_WDT_SCALE_16		3
#define D_WDT_SCALE_32		4
#define D_WDT_SCALE_64		5
#define D_WDT_SCALE_128		6
#define D_WDT_SCALE_256		7

#define	WDT_PS_Set(n)	WDT_CONTR = (WDT_CONTR & ~0x07) | (n & 0x07)		/* 看门狗定时器时钟分频系数设置 */
#define	WDT_reset(n)	WDT_CONTR = D_EN_WDT + D_CLR_WDT + D_IDLE_WDT + (n)		/* 初始化WDT，喂狗 */


//						  7     6      5    4     3      2    1     0     Reset Value
//sfr PCON   = 0x87;	SMOD  SMOD0  LVDF  POF   GF1    GF0   PD   IDL    0001,0000	 //Power Control 
//SMOD		//串口双倍速
//SMOD0
#define		LVDF		(1<<5)	/* P4.6低压检测标志 */
//POF
//GF1
//GF0
//#define 	D_PD		2		/* set 1, power down mode */
//#define 	D_IDLE		1		/* set 1, idle mode */
#define		MCU_IDLE()			PCON |= 1	/* MCU 进入 IDLE 模式 */
#define		MCU_POWER_DOWN()	PCON |= 2	/* MCU 进入 睡眠 模式 */


//sfr IAP_CMD   = 0xC5;
#define		IAP_STANDBY()	IAP_CMD = 0		//IAP空闲命令（禁止）
#define		IAP_READ()		IAP_CMD = 1		//IAP读出命令
#define		IAP_WRITE()		IAP_CMD = 2		//IAP写入命令
#define		IAP_ERASE()		IAP_CMD = 3		//IAP擦除命令

//sfr IAP_TRIG  = 0xC6;
#define 	IAP_TRIG()	IAP_TRIG = 0x5A,	IAP_TRIG = 0xA5		/* IAP触发命令 */

//							            7    6    5      4    3   2  1   0   Reset Value
//sfr IAP_CONTR = 0xC7;		IAPEN SWBS SWRST CFAIL  -   -  -   -   0000,x000	//IAP Control Register

#define IAP_EN          (1<<7)
#define IAP_SWBS        (1<<6)
#define IAP_SWRST       (1<<5)
#define IAP_CMD_FAIL    (1<<4)

#define	IAP_ENABLE()		IAP_CONTR = IAP_EN; IAP_TPS = MAIN_Fosc / 1000000
#define	IAP_DISABLE()		IAP_CONTR = 0; IAP_CMD = 0; IAP_TRIG = 0; IAP_ADDRH = 0xff; IAP_ADDRL = 0xff


/* ADC Register */
//								7       6      5       4         3      2    1    0   Reset Value
//sfr ADC_CONTR = 0xBC;		ADC_POWER SPEED1 SPEED0 ADC_FLAG ADC_START CHS2 CHS1 CHS0 0000,0000	/* AD 转换控制寄存器 */ 
//sfr ADC_RES  = 0xBD;		ADCV.9 ADCV.8 ADCV.7 ADCV.6 ADCV.5 ADCV.4 ADCV.3 ADCV.2	  0000,0000	/* A/D 转换结果高8位 */ 
//sfr ADC_RESL = 0xBE;												  ADCV.1 ADCV.0	  0000,0000	/* A/D 转换结果低2位 */
//sfr ADC_CONTR  = 0xBC;	//直接用MOV操作，不要用与或


//sfr SPCTL  = 0xCE;	SPI控制寄存器
//   7       6       5       4       3       2       1       0    	Reset Value
//	SSIG	SPEN	DORD	MSTR	CPOL	CPHA	SPR1	SPR0		0x00

#define	SPI_SSIG_None()		SPCTL |=  (1<<7)		/* 1: 忽略SS脚	*/
#define	SPI_SSIG_Enable()	SPCTL &= ~(1<<7)		/* 0: SS脚用于决定主从机	*/
#define	SPI_Enable()		SPCTL |=  (1<<6)		/* 1: 允许SPI	*/
#define	SPI_Disable()		SPCTL &= ~(1<<6)		/* 0: 禁止SPI	*/
#define	SPI_LSB_First()		SPCTL |=  (1<<5)		/* 1: LSB先发	*/
#define	SPI_MSB_First()		SPCTL &= ~(1<<5)		/* 0: MSB先发	*/
#define	SPI_Master()		SPCTL |=  (1<<4)		/* 1: 设为主机	*/
#define	SPI_Slave()			SPCTL &= ~(1<<4)		/* 0: 设为从机	*/
#define	SPI_SCLK_NormalH()	SPCTL |=  (1<<3)		/* 1: 空闲时SCLK为高电平	*/
#define	SPI_SCLK_NormalL()	SPCTL &= ~(1<<3)		/* 0: 空闲时SCLK为低电平	*/
#define	SPI_PhaseH()		SPCTL |=  (1<<2)		/* 1: 	*/
#define	SPI_PhaseL()		SPCTL &= ~(1<<2)		/* 0: 	*/
#define	SPI_Speed(n)		SPCTL = (SPCTL & ~3) | (n)	/*设置速度, 0 -- fosc/4, 1 -- fosc/8, 2 -- fosc/16, 3 -- fosc/32	*/

//sfr SPDAT  = 0xCF; //SPI Data Register                                                     0000,0000
//sfr SPSTAT  = 0xCD;	//SPI状态寄存器
//   7       6      5   4   3   2   1   0    	Reset Value
//	SPIF	WCOL	-	-	-	-	-	-
#define	SPIF	0x80		/* SPI传输完成标志。写入1清0。*/
#define	WCOL	0x40		/* SPI写冲突标志。写入1清0。  */

#define		SPI_USE_P12P13P14P15()	P_SW1 &= ~0x0c					/* 将SPI切换到P12(SS) P13(MOSI) P14(MISO) P15(SCLK)(上电默认)。*/
#define		SPI_USE_P22P23P24P25()	P_SW1 = (P_SW1 & ~0x0c) | 0x04	/* 将SPI切换到P22(SS) P23(MOSI) P24(MISO) P25(SCLK)。*/
#define		SPI_USE_P74P75P76P77()	P_SW1 = (P_SW1 & ~0x0c) | 0x08	/* 将SPI切换到P74(SS) P75(MOSI) P76(MISO) P77(SCLK)。*/
#define		SPI_USE_P35P34P33P32()	P_SW1 =  P_SW1 | 0x0C			/* 将SPI切换到P35(SS) P34(MOSI) P33(MISO) P32(SCLK)。*/


//						             7    6     5     4     3     2     1     0    Reset Value
//sfr I2CCFG = 0xFE80H;  ENI2C MSSL             MSSPEED[5:0]             0000,0000  /* I2C配置寄存器 */ 
#define		I2C_Function(n)	(n==0?(I2CCFG &= ~0x80):(I2CCFG |= 0x80))	//0：禁止 I2C 功能；1：使能 I2C 功能
#define		I2C_ENABLE()	I2CCFG |= 0x80		/* 使能 I2C 功能 */
#define		I2C_DISABLE()	I2CCFG &= ~0x80		/* 禁止 I2C 功能 */
#define		I2C_Master()	I2CCFG |=  0x40		/* 1: 设为主机	*/
#define		I2C_Slave()		I2CCFG &= ~0x40		/* 0: 设为从机	*/
#define		I2C_SetSpeed(n)	I2CCFG = (I2CCFG & ~0x3f) | (n & 0x3f)	/* 总线速度=Fosc/2/(Speed*2+4) */

//						              7    6     5     4     3     2     1     0    Reset Value
//sfr I2CMSCR = 0xFE81H;  EMSI   -     -     -         MSCMD[3:0]         0000,0000  /* I2C配置寄存器 */ 
#define		I2C_Master_Inturrupt(n)	(n==0?(I2CMSCR &= ~0x80):(I2CMSCR |= 0x80))	//0：禁止 I2C 功能；1：使能 I2C 功能

#define	I2C_CMD_None				0
#define	I2C_CMD_Start				1
#define	I2C_CMD_Send				2
#define	I2C_CMD_RACK				3
#define	I2C_CMD_Read				4
#define	I2C_CMD_SACK				5
#define	I2C_CMD_Stop				6
#define	I2C_CMD_RFU1				7
#define	I2C_CMD_RFU2				8
#define	I2C_CMD_Start_Send_RACK		9
#define	I2C_CMD_Send_RACK					10
#define	I2C_CMD_Read_SACK					11
#define	I2C_CMD_Read_SNAK					12

#define		I2C_Command(n)	I2CMSCR = (I2CMSCR & ~0x0f) | (n & 0x0f)	/* 主机命令 */

//						              7     6     5     4     3     2      1     0        Reset Value
//sfr I2CMSST = 0xFE82H;  MSBUSY MSIF   -     -     -     -   MSACKI MSACKO     0000,0000  /* I2C主机状态寄存器 */ 

//						              7    6     5     4     3     2     1     0      Reset Value
//sfr I2CMSAUX = 0xFE88H;   -    -     -     -     -     -     -    WDTA    0000,0000  /* I2C主机辅助控制寄存器 */ 
#define		I2C_WDTA_EN()		I2CMSAUX |= 0x01		/* 使能自动发送 */
#define		I2C_WDTA_DIS()	I2CMSAUX &= ~0x01		/* 禁止自动发送 */

//						             7     6     5     4     3     2    1    0       Reset Value
//sfr I2CSLCR = 0xFE83H;   -   ESTAI  ERXI  ETXI ESTOI   -    -  SLRET     0000,0000  /* I2C从机控制寄存器 */ 
#define		I2C_ESTAI_EN()		I2CSLCR |= 0x40			/* 使能从机接收START信号中断 */
#define		I2C_ESTAI_DIS()		I2CSLCR &= ~0x40		/* 禁止从机接收START信号中断 */
#define		I2C_ERXI_EN()			I2CSLCR |= 0x20			/* 使能从机接收1字节数据中断 */
#define		I2C_ERXI_DIS()		I2CSLCR &= ~0x20		/* 禁止从机接收1字节数据中断 */
#define		I2C_ETXI_EN()			I2CSLCR |= 0x10			/* 使能从机发送1字节数据中断 */
#define		I2C_ETXI_DIS()		I2CSLCR &= ~0x10		/* 禁止从机发送1字节数据中断 */
#define		I2C_ESTOI_EN()		I2CSLCR |= 0x08			/* 使能从机接收STOP信号中断 */
#define		I2C_ESTOI_DIS()		I2CSLCR &= ~0x08		/* 禁止从机接收STOP信号中断 */
#define		I2C_SLRET()				I2CSLCR |= 0x01			/* 复位从机模式 */

//						               7      6     5     4     3     2      1     0        Reset Value
//sfr I2CSLST = 0xFE84H;  SLBUSY  STAIF  RXIF  TXIF STOIF   -   SLACKI SLACKO     0000,0000  /* I2C从机状态寄存器 */ 

//						              7    6     5     4     3     2     1     0      Reset Value
//sfr I2CSLADR = 0xFE85H;              I2CSLADR[7:1]                 MA     0000,0000  /* I2C从机地址寄存器 */ 
#define		I2C_Address(n)	I2CSLADR = (I2CSLADR & 0x01) | (n << 1)	/* 从机地址 */
#define		I2C_MATCH_EN()	I2CSLADR &= ~0x01	/* 使能从机地址比较功能，只接受相匹配地址 */
#define		I2C_MATCH_DIS()	I2CSLADR |= 0x01	/* 禁止从机地址比较功能，接受所有设备地址 */


//						               7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_ENO = 0xFEB1H;  ENO4N ENO4P ENO3N ENO3P ENO2N ENO2P ENO1N ENO1P  0000,0000  /* 输出使能寄存器 */ 
//sfr PWMB_ENO = 0xFEB5H;    -   ENO8P   -   ENO7P   -   ENO6P   -   ENO5P  0000,0000  /* 输出使能寄存器 */ 
#define		PWM1P_OUT_EN()	PWMA_ENO |= 0x01	/* 使能 PWM1P 输出 */
#define		PWM1P_OUT_DIS()	PWMA_ENO &= ~0x01	/* 禁止 PWM1P 输出 */
#define		PWM1N_OUT_EN()	PWMA_ENO |= 0x02	/* 使能 PWM1N 输出 */
#define		PWM1N_OUT_DIS()	PWMA_ENO &= ~0x02	/* 禁止 PWM1N 输出 */
#define		PWM2P_OUT_EN()	PWMA_ENO |= 0x04	/* 使能 PWM2P 输出 */
#define		PWM2P_OUT_DIS()	PWMA_ENO &= ~0x04	/* 禁止 PWM2P 输出 */
#define		PWM2N_OUT_EN()	PWMA_ENO |= 0x08	/* 使能 PWM2N 输出 */
#define		PWM2N_OUT_DIS()	PWMA_ENO &= ~0x08	/* 禁止 PWM2N 输出 */
#define		PWM3P_OUT_EN()	PWMA_ENO |= 0x10	/* 使能 PWM3P 输出 */
#define		PWM3P_OUT_DIS()	PWMA_ENO &= ~0x10	/* 禁止 PWM3P 输出 */
#define		PWM3N_OUT_EN()	PWMA_ENO |= 0x20	/* 使能 PWM3N 输出 */
#define		PWM3N_OUT_DIS()	PWMA_ENO &= ~0x20	/* 禁止 PWM3N 输出 */
#define		PWM4P_OUT_EN()	PWMA_ENO |= 0x40	/* 使能 PWM3P 输出 */
#define		PWM4P_OUT_DIS()	PWMA_ENO &= ~0x40	/* 禁止 PWM3P 输出 */
#define		PWM4N_OUT_EN()	PWMA_ENO |= 0x80	/* 使能 PWM3N 输出 */
#define		PWM4N_OUT_DIS()	PWMA_ENO &= ~0x80	/* 禁止 PWM3N 输出 */

#define		PWM5P_OUT_EN()	PWMB_ENO |= 0x01	/* 使能 PWM5P 输出 */
#define		PWM5P_OUT_DIS()	PWMB_ENO &= ~0x01	/* 禁止 PWM5P 输出 */
#define		PWM6P_OUT_EN()	PWMB_ENO |= 0x04	/* 使能 PWM6P 输出 */
#define		PWM6P_OUT_DIS()	PWMB_ENO &= ~0x04	/* 禁止 PWM6P 输出 */
#define		PWM7P_OUT_EN()	PWMB_ENO |= 0x10	/* 使能 PWM7P 输出 */
#define		PWM7P_OUT_DIS()	PWMB_ENO &= ~0x10	/* 禁止 PWM7P 输出 */
#define		PWM8P_OUT_EN()	PWMB_ENO |= 0x40	/* 使能 PWM8P 输出 */
#define		PWM8P_OUT_DIS()	PWMB_ENO &= ~0x40	/* 禁止 PWM8P 输出 */

#define		PWMA_OutChannelSel(n)		PWMA_ENO = n	//选择输出通道
#define		PWMB_OutChannelSel(n)		PWMB_ENO = n	//选择输出通道

//						              7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_PS = 0xFEB2H;  C4PS1 C4PS0 C3PS1 C3PS0 C2PS1 C2PS0 C1PS1 C1PS0  0000,0000  /* 输出使能寄存器 */ 
//sfr PWMB_PS = 0xFEB6H;  C8PS1 C8PS0 C7PS1 C7PS0 C6PS1 C6PS0 C5PS1 C5PS0  0000,0000  /* 输出使能寄存器 */ 

#define		PWM1_USE_P10P11()		PWMA_PS = (PWMA_PS & ~0x03)					/* PWM 通道 1 输出脚切换到P10(PWM1P) P11(PWM1N) */ 
#define		PWM1_USE_P20P21()		PWMA_PS = (PWMA_PS & ~0x03) | 0x01	/* PWM 通道 1 输出脚切换到P20(PWM1P) P21(PWM1N) */ 
#define		PWM1_USE_P60P61()		PWMA_PS = (PWMA_PS & ~0x03) | 0x02	/* PWM 通道 1 输出脚切换到P60(PWM1P) P61(PWM1N) */ 

#define		PWM2_USE_P12P13()		PWMA_PS = (PWMA_PS & ~0x0C)					/* PWM 通道 2 输出脚切换到P12/P54(PWM2P) P13(PWM2N) */ 
#define		PWM2_USE_P22P23()		PWMA_PS = (PWMA_PS & ~0x0C) | 0x04	/* PWM 通道 2 输出脚切换到P22(PWM2P) P23(PWM2N) */ 
#define		PWM2_USE_P62P63()		PWMA_PS = (PWMA_PS & ~0x0C) | 0x08	/* PWM 通道 2 输出脚切换到P62(PWM2P) P63(PWM2N) */ 

#define		PWM3_USE_P14P15()		PWMA_PS = (PWMA_PS & ~0x30)					/* PWM 通道 3 输出脚切换到P14(PWM3P) P15(PWM3N) */ 
#define		PWM3_USE_P24P25()		PWMA_PS = (PWMA_PS & ~0x30) | 0x10	/* PWM 通道 3 输出脚切换到P24(PWM3P) P25(PWM3N) */ 
#define		PWM3_USE_P64P65()		PWMA_PS = (PWMA_PS & ~0x30) | 0x20	/* PWM 通道 3 输出脚切换到P64(PWM3P) P65(PWM3N) */ 

#define		PWM4_USE_P16P17()		PWMA_PS = (PWMA_PS & ~0xC0)					/* PWM 通道 4 输出脚切换到P16(PWM4P) P17(PWM4N) */ 
#define		PWM4_USE_P26P27()		PWMA_PS = (PWMA_PS & ~0xC0) | 0x40	/* PWM 通道 4 输出脚切换到P26(PWM4P) P27(PWM4N) */ 
#define		PWM4_USE_P66P67()		PWMA_PS = (PWMA_PS & ~0xC0) | 0x80	/* PWM 通道 4 输出脚切换到P66(PWM4P) P67(PWM4N) */ 
#define		PWM4_USE_P34P33()		PWMA_PS = (PWMA_PS | 0xC0)					/* PWM 通道 4 输出脚切换到P34(PWM4P) P33(PWM4N) */ 

#define		PWM5_USE_P20()			PWMB_PS = (PWMB_PS & ~0x03)					/* PWM 通道 5 输出脚切换到P20(PWM5) */ 
#define		PWM5_USE_P17()			PWMB_PS = (PWMB_PS & ~0x03) | 0x01	/* PWM 通道 5 输出脚切换到P17(PWM5) */ 
#define		PWM5_USE_P00()			PWMB_PS = (PWMB_PS & ~0x03) | 0x02	/* PWM 通道 5 输出脚切换到P00(PWM5) */ 
#define		PWM5_USE_P74()			PWMB_PS = (PWMB_PS | 0x03)					/* PWM 通道 5 输出脚切换到P74(PWM5) */ 

#define		PWM6_USE_P21()			PWMB_PS = (PWMB_PS & ~0x0C)					/* PWM 通道 6 输出脚切换到P21(PWM6) */ 
#define		PWM6_USE_P54()			PWMB_PS = (PWMB_PS & ~0x0C) | 0x04	/* PWM 通道 6 输出脚切换到P54(PWM6) */ 
#define		PWM6_USE_P01()			PWMB_PS = (PWMB_PS & ~0x0C) | 0x08	/* PWM 通道 6 输出脚切换到P01(PWM6) */ 
#define		PWM6_USE_P75()			PWMB_PS = (PWMB_PS | 0x0C)					/* PWM 通道 6 输出脚切换到P75(PWM6) */ 

#define		PWM7_USE_P22()			PWMB_PS = (PWMB_PS & ~0x30)					/* PWM 通道 7 输出脚切换到P22(PWM7) */ 
#define		PWM7_USE_P33()			PWMB_PS = (PWMB_PS & ~0x30) | 0x10	/* PWM 通道 7 输出脚切换到P33(PWM7) */ 
#define		PWM7_USE_P02()			PWMB_PS = (PWMB_PS & ~0x30) | 0x20	/* PWM 通道 7 输出脚切换到P02(PWM7) */ 
#define		PWM7_USE_P76()			PWMB_PS = (PWMB_PS | 0x30)					/* PWM 通道 7 输出脚切换到P76(PWM7) */ 

#define		PWM8_USE_P23()			PWMB_PS = (PWMB_PS & ~0xC0)					/* PWM 通道 8 输出脚切换到P23(PWM8) */ 
#define		PWM8_USE_P34()			PWMB_PS = (PWMB_PS & ~0xC0) | 0x40	/* PWM 通道 8 输出脚切换到P34(PWM8) */ 
#define		PWM8_USE_P03()			PWMB_PS = (PWMB_PS & ~0xC0) | 0x80	/* PWM 通道 8 输出脚切换到P03(PWM8) */ 
#define		PWM8_USE_P77()			PWMB_PS = (PWMB_PS | 0xC0)					/* PWM 通道 8 输出脚切换到P77(PWM8) */ 

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_IOAUX = 0xFEB3H;  AUX4N AUX4P AUX3N AUX3P AUX2N AUX2P AUX1N AUX1P  0000,0000  /* 输出附加使能寄存器 */ 
//sfr PWMB_IOAUX = 0xFEB7H;    -   AUX8P   -   AUX7P   -   AUX6P   -   AUX5P  0000,0000  /* 输出附加使能寄存器 */ 
#define AUX4N			(1<<7)
#define AUX4P			(1<<6)
#define AUX3N			(1<<5)
#define AUX3P			(1<<4)
#define AUX2N			(1<<3)
#define AUX2P			(1<<2)
#define AUX1N			(1<<1)
#define AUX1P			(1)

#define AUX8P			(1<<6)
#define AUX7P			(1<<4)
#define AUX6P			(1<<2)
#define AUX5P			(1)


//						               7     6     5    4    3    2    1     0    Reset Value
//sfr PWMA_CR1 = 0xFEC0H;  ARPEA CMSA1 CMSA0 DIRA OPMA URSA UDISA CENA  0000,0000  /* 控制寄存器 1 */ 
//sfr PWMB_CR1 = 0xFEE0H;  ARPEB CMSB1 CMSB0 DIRB OPMB URSB UDISB CENB  0000,0000  /* 控制寄存器 1 */ 
#define ARPE1			(1<<7)
#define ARPE2			(1<<7)
#define PWMA_AlignMode_Edge()			PWMA_CR1 = (PWMA_CR1 & ~0x60)
#define PWMA_AlignMode_Mid1()			PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x20
#define PWMA_AlignMode_Mid2()			PWMA_CR1 = (PWMA_CR1 & ~0x60) | 0x40
#define PWMA_AlignMode_Mid3()			PWMA_CR1 = (PWMA_CR1 | 0x60)
#define PWMA_DIR_UP()							PWMA_CR1 &= ~0x10
#define PWMA_DIR_DN()							PWMA_CR1 |= 0x10
#define PWMA_OPMA(n)							(n==0?(PWMA_CR1 &= ~0x08):(PWMA_CR1 |= 0x08))	//单脉冲模式 0：在发生更新事件时，计数器不停止；1：在发生下一次更新事件时，清除 CEN 位，计数器停止
#define PWMA_URSA(n)							(n==0?(PWMA_CR1 &= ~0x04):(PWMA_CR1 |= 0x04))	//更新请求源
#define PWMA_UDISA(n)							(n==0?(PWMA_CR1 &= ~0x02):(PWMA_CR1 |= 0x02))	//禁止更新 0：产生更新（UEV）事件；1：不产生更新事件
#define PWMA_CEN_Enable()					PWMA_CR1 |= 0x01		//1：使能计数器
#define PWMA_CEN_Disable()				PWMA_CR1 &= ~0x01		//0：禁止计数器

#define PWMB_AlignMode_Edge()			PWMB_CR1 = (PWMB_CR1 & ~0x60)
#define PWMB_AlignMode_Mid1()			PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x20
#define PWMB_AlignMode_Mid2()			PWMB_CR1 = (PWMB_CR1 & ~0x60) | 0x40
#define PWMB_AlignMode_Mid3()			PWMB_CR1 = (PWMB_CR1 | 0x60)
#define PWMB_DIR_UP()							PWMB_CR1 &= ~0x10
#define PWMB_DIR_DN()							PWMB_CR1 |= 0x10
#define PWMB_OPMB(n)							(n==0?(PWMB_CR1 &= ~0x08):(PWMB_CR1 |= 0x08))	//单脉冲模式 0：在发生更新事件时，计数器不停止；1：在发生下一次更新事件时，清除 CEN 位，计数器停止
#define PWMB_URSB(n)							(n==0?(PWMB_CR1 &= ~0x04):(PWMB_CR1 |= 0x04))	//更新请求源
#define PWMB_UDISB(n)							(n==0?(PWMB_CR1 &= ~0x02):(PWMB_CR1 |= 0x02))	//禁止更新 0：产生更新（UEV）事件；1：不产生更新事件
#define PWMB_CEN_Enable()					PWMB_CR1 |= 0x01		//1：使能计数器
#define PWMB_CEN_Disable()				PWMB_CR1 &= ~0x01		//0：禁止计数器


//						               7     6     5    4    3    2    1    0    Reset Value
//sfr PWMA_CR2 = 0xFEC1H;  TI1S MMSA2 MMSA1 MMSA0  -  COMSA  -  CCPCA  0000,x0x0  /* 控制寄存器 2 */ 
//sfr PWMB_CR2 = 0xFEE1H;  TI5S MMSB2 MMSB1 MMSB0  -  COMSB  -  CCPCB  0000,x0xx  /* 控制寄存器 2 */ 
#define PWM1P_TI1()							PWMA_CR2 &= ~0x80
#define PWM1P2P3P_XOR_TI1()			PWMA_CR2 |= 0x80
#define PWM5P_TI2()							PWMB_CR2 &= ~0x80
#define PWM5P6P7P_XOR_TI2()			PWMB_CR2 |= 0x80

#define MMSn_RESET					0		//复位
#define MMSn_ENABLE					1		//使能
#define MMSn_UPDATE					2		//更新
#define MMSn_COMP_TRGO			3		//比较脉冲
#define MMSn_OC1REF_TRGO		4		//比较
#define MMSn_OC2REF_TRGO		5		//比较
#define MMSn_OC3REF_TRGO		6		//比较
#define MMSn_OC4REF_TRGO		7		//比较

#define PWMA_MainModeSel(n)		PWMA_CR2 = (PWMA_CR2 & ~0x70) | (n<<4)	//主模式选择
#define PWMB_MainModeSel(n)		PWMB_CR2 = (PWMB_CR2 & ~0x70) | (n<<4)	//主模式选择

//0：当 CCPC=1 时，只有在 COMG 位置 1 的时候这些控制位才被更新
//1：当 CCPC=1 时，只有在 COMG 位置 1 或 TRGI 发生上升沿的时候这些控制位才被更新
#define PWMA_COMSUpdateCtrl(n)		PWMA_CR2 = (n==0?(PWMA_CR2 &= ~0x04):(PWMA_CR2 |= 0x04))	//捕获/比较控制位的更新控制选择
#define PWMB_COMSUpdateCtrl(n)		PWMB_CR2 = (n==0?(PWMB_CR2 &= ~0x04):(PWMB_CR2 |= 0x04))	//捕获/比较控制位的更新控制选择
//0： CCIE， CCINE， CCiP， CCiNP 和 OCIM 位不是预装载的
//1： CCIE， CCINE， CCiP， CCiNP 和 OCIM 位是预装载的；设置该位后，它们只在设置了 COMG位后被更新。
#define PWMA_CCPCAPreloaded(n)		PWMA_CR2 = (n==0?(PWMA_CR2 &= ~0x01):(PWMA_CR2 |= 0x01))	//捕获/比较预装载控制位(该位只对具有互补输出的通道起作用)
#define PWMB_CCPCBPreloaded(n)		PWMA_CR2 = (n==0?(PWMA_CR2 &= ~0x01):(PWMA_CR2 |= 0x01))	//捕获/比较预装载控制位(该位只对具有互补输出的通道起作用)


//						               7    6    5    4    3    2     1     0    Reset Value
//sfr PWMA_SMCR = 0xFEC2H;  MSMA TSA2 TSA1 TSA0  -  SMSA2 SMSA1 SMSA0  0000,x000  /* 从模式控制寄存器 */ 
//sfr PWMB_SMCR = 0xFEE2H;  MSMB TSB2 TSB1 TSB0  -  SMSB2 SMSB1 SMSB0  0000,x000  /* 从模式控制寄存器 */ 
#define SMCR_TSn_ITR2				2
#define SMCR_TSn_EDGE				4
#define SMCR_TSn_TIMER1			5
#define SMCR_TSn_TIMER2			6
#define SMCR_TSn_ETRF				7

#define PWMA_SMCR_Source(n)		PWMA_SMCR = (PWMA_SMCR & ~0x70) | (n<<4)	//触发源选择
#define PWMB_SMCR_Source(n)		PWMB_SMCR = (PWMB_SMCR & ~0x70) | (n<<4)	//触发源选择

#define SMCR_SMSA_INSIDE_CLK			0
#define SMCR_SMSA_ENCODER_M1			1
#define SMCR_SMSA_ENCODER_M2			2
#define SMCR_SMSA_ENCODER_M3			3
#define SMCR_SMSA_RESET						4
#define SMCR_SMSA_GATE						5
#define SMCR_SMSA_TRIG						6
#define SMCR_SMSA_EXT_CLK					7

#define PWMA_SMCR_SMS(n)		PWMA_SMCR = (PWMA_SMCR & ~0x07) | (n & 7)	//时钟/触发/从模式选择
#define PWMB_SMCR_SMS(n)		PWMB_SMCR = (PWMB_SMCR & ~0x07) | (n & 7)	//时钟/触发/从模式选择

//						               7    6    5      4     3     2     1     0     Reset Value
//sfr PWMA_ETR = 0xFEC3H;  ETP1 ECE1 ETPS11 ETPS10 ETF13 ETF12 ETF11 ETF10  0000,0000  /* 外部触发寄存器 */ 
//sfr PWMB_ETR = 0xFEE3H;  ETP2 ECE2 ETPS21 ETPS20 ETF23 ETF22 ETF21 ETF20  0000,0000  /* 外部触发寄存器 */ 

//						               7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_IER = 0xFEC4H;  BIEA TIEA COMIEA CC4IE CC3IE CC2IE CC1IE UIEA  0000,0000  /* 中断使能寄存器 */ 
//sfr PWMB_IER = 0xFEE4H;  BIEB TIEB COMIEB CC8IE CC7IE CC6IE CC5IE UIEB  0000,0000  /* 中断使能寄存器 */ 
#define PWMA_UIEA_Enable()		PWMA_IER |= 0x01		//1：允许更新中断
#define PWMA_UIEA_Disable()		PWMA_IER &= ~0x01		//0：禁止更新中断
#define PWMA_CC1IE_Enable()		PWMA_IER |= 0x02		//1：允许捕获/比较中断
#define PWMA_CC1IE_Disable()	PWMA_IER &= ~0x02		//0：禁止捕获/比较中断
#define PWMA_CC2IE_Enable()		PWMA_IER |= 0x04		//1：允许捕获/比较中断
#define PWMA_CC2IE_Disable()	PWMA_IER &= ~0x04		//0：禁止捕获/比较中断
#define PWMA_CC3IE_Enable()		PWMA_IER |= 0x08		//1：允许捕获/比较中断
#define PWMA_CC3IE_Disable()	PWMA_IER &= ~0x08		//0：禁止捕获/比较中断
#define PWMA_CC4IE_Enable()		PWMA_IER |= 0x10		//1：允许捕获/比较中断
#define PWMA_CC4IE_Disable()	PWMA_IER &= ~0x10		//0：禁止捕获/比较中断
#define PWMA_COMIEA_Enable()	PWMA_IER |= 0x20		//1：允许COM中断
#define PWMA_COMIEA_Disable()	PWMA_IER &= ~0x20		//0：禁止COM中断
#define PWMA_TIEA_Enable()		PWMA_IER |= 0x40		//1：允许触发中断
#define PWMA_TIEA_Disable()		PWMA_IER &= ~0x40		//0：禁止触发中断
#define PWMA_BIEA_Enable()		PWMA_IER |= 0x80		//1：允许刹车中断
#define PWMA_BIEA_Disable()		PWMA_IER &= ~0x80		//0：禁止刹车中断

//						               7    6    5      4     3     2     1    0    Reset Value
//sfr PWMA_SR1 = 0xFEC5H;  BIF1 TIF1 COMIF1 CC4IF CC3IF CC2IF CC1IF UIF1  0000,0000  /* 状态寄存器 1 */ 
//sfr PWMB_SR1 = 0xFEE5H;  BIF2 TIF2 COMIF2 CC8IF CC7IF CC6IF CC5IF UIF2  0000,0000  /* 状态寄存器 1 */ 
#define UIF1			1
#define CC1IF			(1<<1)
#define CC2IF			(1<<2)
#define CC3IF			(1<<3)
#define CC4IF			(1<<4)
#define COMIF1		(1<<5)
#define TIF1			(1<<6)
#define BIF1			(1<<7)

#define UIF2			1
#define CC5IF			(1<<1)
#define CC6IF			(1<<2)
#define CC7IF			(1<<3)
#define CC8IF			(1<<4)
#define COMIF2		(1<<5)
#define TIF2			(1<<6)
#define BIF2			(1<<7)

//						              7   6   5    4     3     2     1    0   Reset Value
//sfr PWMA_SR2 = 0xFEC6H;   -   -   -  CC4OF CC3OF CC2OF CC1OF  -   xxx0,000x  /* 状态寄存器 2 */ 
//sfr PWMB_SR2 = 0xFEE6H;   -   -   -  CC8OF CC7OF CC6OF CC5OF  -   xxx0,000x  /* 状态寄存器 2 */ 

//						              7   6    5    4    3    2    1    0   Reset Value
//sfr PWMA_EGR = 0xFEC7H;  BG1 TG1 COMG1 CC4G CC3G CC2G CC1G UG1  0000,0000  /* 事件产生寄存器 */ 
//sfr PWMB_EGR = 0xFEE7H;  BG2 TG2 COMG2 CC8G CC7G CC6G CC5G UG2  0000,0000  /* 事件产生寄存器 */ 

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H;  OC1CE OC1M2 OC1M1 OC1M0 OC1PE OC1FE CC1S1 CC1S0  0000,0000  /* 捕获/比较模式寄存器 1 - 通道配置为比较输出模式 */ 
//sfr PWMB_CCMR1 = 0xFEE8H;  OC5CE OC5M2 OC5M1 OC5M0 OC5PE OC5FE CC5S1 CC5S0  0000,0000  /* 捕获/比较模式寄存器 1 - 通道配置为比较输出模式 */ 
#define OCnCE			(1<<7)

#define CCMRn_FREEZE							0x00		//冻结
#define CCMRn_MATCH_VALID					0x10		//匹配时设置通道 n 的输出为有效电平
#define CCMRn_MATCH_INVALID				0x20		//匹配时设置通道 n 的输出为无效电平
#define CCMRn_ROLLOVER						0x30		//翻转
#define CCMRn_FORCE_INVALID				0x40		//强制为无效电平
#define CCMRn_FORCE_VALID					0x50		//强制为有效电平
#define CCMRn_PWM_MODE1						0x60		//PWM 模式 1
#define CCMRn_PWM_MODE2						0x70		//PWM 模式 2

#define PWMA_OC1ModeSet(n)				PWMA_CCMR1 = (PWMA_CCMR1 & ~0x70) | (n)		//输出比较模式设置
#define PWMB_OC5ModeSet(n)				PWMB_CCMR1 = (PWMB_CCMR1 & ~0x70) | (n)		//输出比较模式设置

#define PWMA_OC1_ReloadEnable()		PWMA_CCMR1 |= 0x08		//1：开启 OC1PE 输出比较的预装载功能
#define PWMA_OC1_RelosdDisable()	PWMA_CCMR1 &= ~0x08		//0：禁止 OC1PE 输出比较的预装载功能
#define PWMB_OC5_ReloadEnable()		PWMB_CCMR1 |= 0x08		//1：开启 OC5PE 输出比较的预装载功能
#define PWMB_OC5_RelosdDisable()	PWMB_CCMR1 &= ~0x08		//0：禁止 OC5PE 输出比较的预装载功能

#define PWMA_OC1_FastEnable()			PWMA_CCMR1 |= 0x04		//1：开启 OC1FE 输出比较快速功能
#define PWMA_OC1_FastDisable()		PWMA_CCMR1 &= ~0x04		//0：禁止 OC1FE 输出比较快速功能
#define PWMB_OC5_FastEnable()			PWMB_CCMR1 |= 0x04		//1：开启 OC5FE 输出比较快速功能
#define PWMB_OC5_FastDisable()		PWMB_CCMR1 &= ~0x04		//0：禁止 OC5FE 输出比较快速功能

#define CCAS_OUTPUT						0x00		//输出
#define CCAS_IUTPUT_TI1FP1		0x01		//输入，IC1/IC2/IC3/IC4 映射在 TI1FP1 上
#define CCAS_IUTPUT_TI2FP1		0x02		//输入，IC1/IC2/IC3/IC4 映射在 TI2FP1 上
#define CCAS_IUTPUT_TRC				0x03		//输入，IC1/IC2/IC3/IC4 映射在 TRC 上
#define CCBS_OUTPUT						0x00		//输出
#define CCBS_IUTPUT_TI5FP5		0x01		//输入，IC5/IC6/IC7/IC8 映射在 TI5FP5 上
#define CCBS_IUTPUT_TI6FP5		0x02		//输入，IC5/IC6/IC7/IC8 映射在 TI6FP5 上
#define CCBS_IUTPUT_TRC				0x03		//输入，IC5/IC6/IC7/IC8 映射在 TRC 上

#define PWMA_CC1S_Direction(n)		PWMA_CCMR1 = (PWMA_CCMR1 & ~0x03) | (n)		//捕获/比较 1 选择。这两位定义通道的方向（输入/输出），及输入脚的选择
#define PWMB_CC5S_Direction(n)		PWMB_CCMR1 = (PWMB_CCMR1 & ~0x03) | (n)		//捕获/比较 5 选择。这两位定义通道的方向（输入/输出），及输入脚的选择

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR1 = 0xFEC8H;  IC1F3 IC1F2 IC1F1 IC1F0 IC1PSC1 IC1PSC0 CC1S1 CC1S0  0000,0000  /* 捕获/比较模式寄存器 1 - 通道配置为捕获输入模式 */ 
//sfr PWMB_CCMR1 = 0xFEE8H;  IC5F3 IC5F2 IC5F1 IC5F0 IC5PSC1 IC5PSC0 CC5S1 CC5S0  0000,0000  /* 捕获/比较模式寄存器 1 - 通道配置为捕获输入模式 */ 

#define ICnF_01_Clock			0
#define ICnF_02_Clock			1
#define ICnF_04_Clock			2
#define ICnF_08_Clock			3
#define ICnF_12_Clock			4
#define ICnF_16_Clock			5
#define ICnF_24_Clock			6
#define ICnF_32_Clock			7
#define ICnF_48_Clock			8
#define ICnF_64_Clock			9
#define ICnF_80_Clock			10
#define ICnF_96_Clock			11
#define ICnF_128_Clock		12
#define ICnF_160_Clock		13
#define ICnF_192_Clock		14
#define ICnF_256_Clock		15

#define PWMA_IC1F_FilterClock(n)	PWMA_CCMR1 = (PWMA_CCMR1 & 0x0F) | (n<<4)		//输入捕获 1 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度
#define PWMB_IC5F_FilterClock(n)	PWMB_CCMR1 = (PWMB_CCMR1 & 0x0F) | (n<<4)		//输入捕获 5 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度

#define PWMA_IC1PSC_PrescalerSet(n)		PWMA_CCMR1 = (PWMA_CCMR1 & 0xF3) | ((n&3)<<2)		//输入/捕获 1 预分频器，0~3
#define PWMB_IC5PSC_PrescalerSet(n)		PWMB_CCMR1 = (PWMB_CCMR1 & 0xF3) | ((n&3)<<2)		//输入/捕获 5 预分频器，0~3

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H;  OC2CE OC2M2 OC2M1 OC2M0 OC2PE OC2FE CC2S1 CC2S0  0000,0000  /* 捕获/比较模式寄存器 2 - 通道配置为比较输出模式 */ 
//sfr PWMB_CCMR2 = 0xFEE9H;  OC6CE OC6M2 OC6M1 OC6M0 OC6PE OC6FE CC6S1 CC6S0  0000,0000  /* 捕获/比较模式寄存器 2 - 通道配置为比较输出模式 */ 

#define PWMA_OC2ModeSet(n)				PWMA_CCMR2 = (PWMA_CCMR2 & ~0x70) | (n)		//输出比较模式设置
#define PWMB_OC6ModeSet(n)				PWMB_CCMR2 = (PWMB_CCMR2 & ~0x70) | (n)		//输出比较模式设置

#define PWMA_OC2_ReloadEnable()		PWMA_CCMR2 |= 0x08		//1：开启 OC2PE 输出比较的预装载功能
#define PWMA_OC2_RelosdDisable()	PWMA_CCMR2 &= ~0x08		//0：禁止 OC2PE 输出比较的预装载功能
#define PWMB_OC6_ReloadEnable()		PWMB_CCMR2 |= 0x08		//1：开启 OC6PE 输出比较的预装载功能
#define PWMB_OC6_RelosdDisable()	PWMB_CCMR2 &= ~0x08		//0：禁止 OC6PE 输出比较的预装载功能

#define PWMA_OC2_FastEnable()			PWMA_CCMR2 |= 0x04		//1：开启 OC2FE 输出比较快速功能
#define PWMA_OC2_FastDisable()		PWMA_CCMR2 &= ~0x04		//0：禁止 OC2FE 输出比较快速功能
#define PWMB_OC6_FastEnable()			PWMB_CCMR2 |= 0x04		//1：开启 OC6FE 输出比较快速功能
#define PWMB_OC6_FastDisable()		PWMB_CCMR2 &= ~0x04		//0：禁止 OC6FE 输出比较快速功能

#define PWMA_CC2S_Direction(n)		PWMA_CCMR2 = (PWMA_CCMR2 & ~0x03) | (n)		//捕获/比较 2 选择。这两位定义通道的方向（输入/输出），及输入脚的选择
#define PWMB_CC6S_Direction(n)		PWMB_CCMR2 = (PWMB_CCMR2 & ~0x03) | (n)		//捕获/比较 6 选择。这两位定义通道的方向（输入/输出），及输入脚的选择

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR2 = 0xFEC9H;  IC2F3 IC2F2 IC2F1 IC2F0 IC2PSC1 IC2PSC0 CC2S1 CC2S0  0000,0000  /* 捕获/比较模式寄存器 2 - 通道配置为捕获输入模式 */ 
//sfr PWMB_CCMR2 = 0xFEE9H;  IC6F3 IC6F2 IC6F1 IC6F0 IC6PSC1 IC6PSC0 CC6S1 CC6S0  0000,0000  /* 捕获/比较模式寄存器 2 - 通道配置为捕获输入模式 */ 

#define PWMA_IC2F_FilterClock(n)	PWMA_CCMR2 = (PWMA_CCMR2 & 0x0F) | (n<<4)		//输入捕获 2 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度
#define PWMB_IC6F_FilterClock(n)	PWMB_CCMR2 = (PWMB_CCMR2 & 0x0F) | (n<<4)		//输入捕获 6 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度

#define PWMA_IC2PSC_PrescalerSet(n)		PWMA_CCMR2 = (PWMA_CCMR2 & 0xF3) | ((n&3)<<2)		//输入/捕获 2 预分频器，0~3
#define PWMB_IC6PSC_PrescalerSet(n)		PWMB_CCMR2 = (PWMB_CCMR2 & 0xF3) | ((n&3)<<2)		//输入/捕获 6 预分频器，0~3

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH;  OC3CE OC3M2 OC3M1 OC3M0 OC3PE OC3FE CC3S1 CC3S0  0000,0000  /* 捕获/比较模式寄存器 3 - 通道配置为比较输出模式 */ 
//sfr PWMB_CCMR3 = 0xFEEAH;  OC7CE OC7M2 OC7M1 OC7M0 OC7PE OC7FE CC7S1 CC7S0  0000,0000  /* 捕获/比较模式寄存器 3 - 通道配置为比较输出模式 */ 

#define PWMA_OC3ModeSet(n)				PWMA_CCMR3 = (PWMA_CCMR3 & ~0x70) | (n)		//输出比较模式设置
#define PWMB_OC7ModeSet(n)				PWMB_CCMR3 = (PWMB_CCMR3 & ~0x70) | (n)		//输出比较模式设置

#define PWMA_OC3_ReloadEnable()		PWMA_CCMR3 |= 0x08		//1：开启 OC3PE 输出比较的预装载功能
#define PWMA_OC3_RelosdDisable()	PWMA_CCMR3 &= ~0x08		//0：禁止 OC3PE 输出比较的预装载功能
#define PWMB_OC7_ReloadEnable()		PWMB_CCMR3 |= 0x08		//1：开启 OC7PE 输出比较的预装载功能
#define PWMB_OC7_RelosdDisable()	PWMB_CCMR3 &= ~0x08		//0：禁止 OC7PE 输出比较的预装载功能

#define PWMA_OC3_FastEnable()			PWMA_CCMR3 |= 0x04		//1：开启 OC3FE 输出比较快速功能
#define PWMA_OC3_FastDisable()		PWMA_CCMR3 &= ~0x04		//0：禁止 OC3FE 输出比较快速功能
#define PWMB_OC7_FastEnable()			PWMB_CCMR3 |= 0x04		//1：开启 OC7FE 输出比较快速功能
#define PWMB_OC7_FastDisable()		PWMB_CCMR3 &= ~0x04		//0：禁止 OC7FE 输出比较快速功能

#define PWMA_CC3S_Direction(n)		PWMA_CCMR3 = (PWMA_CCMR3 & ~0x03) | (n)		//捕获/比较 3 选择。这两位定义通道的方向（输入/输出），及输入脚的选择
#define PWMB_CC7S_Direction(n)		PWMB_CCMR3 = (PWMB_CCMR3 & ~0x03) | (n)		//捕获/比较 7 选择。这两位定义通道的方向（输入/输出），及输入脚的选择

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR3 = 0xFECAH;  IC3F3 IC3F2 IC3F1 IC3F0 IC3PSC1 IC3PSC0 CC3S1 CC3S0  0000,0000  /* 捕获/比较模式寄存器 3 - 通道配置为捕获输入模式 */ 
//sfr PWMB_CCMR3 = 0xFEEAH;  IC7F3 IC7F2 IC7F1 IC7F0 IC7PSC1 IC7PSC0 CC7S1 CC7S0  0000,0000  /* 捕获/比较模式寄存器 3 - 通道配置为捕获输入模式 */ 

#define PWMA_IC3F_FilterClock(n)	PWMA_CCMR3 = (PWMA_CCMR3 & 0x0F) | (n<<4)		//输入捕获 3 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度
#define PWMB_IC7F_FilterClock(n)	PWMB_CCMR3 = (PWMB_CCMR3 & 0x0F) | (n<<4)		//输入捕获 7 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度

#define PWMA_IC3PSC_PrescalerSet(n)		PWMA_CCMR3 = (PWMA_CCMR3 & 0xF3) | ((n&3)<<2)		//输入/捕获 3 预分频器，0~3
#define PWMB_IC7PSC_PrescalerSet(n)		PWMB_CCMR3 = (PWMB_CCMR3 & 0xF3) | ((n&3)<<2)		//输入/捕获 7 预分频器，0~3

//						                 7     6     5     4     3     2     1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH;  OC4CE OC4M2 OC4M1 OC4M0 OC4PE OC4FE CC4S1 CC4S0  0000,0000  /* 捕获/比较模式寄存器 4 - 通道配置为比较输出模式 */ 
//sfr PWMB_CCMR4 = 0xFEEBH;  OC8CE OC8M2 OC8M1 OC8M0 OC8PE OC8FE CC8S1 CC8S0  0000,0000  /* 捕获/比较模式寄存器 4 - 通道配置为比较输出模式 */ 

#define PWMA_OC4ModeSet(n)				PWMA_CCMR4 = (PWMA_CCMR4 & ~0x70) | (n)		//输出比较模式设置
#define PWMB_OC8ModeSet(n)				PWMB_CCMR4 = (PWMB_CCMR4 & ~0x70) | (n)		//输出比较模式设置

#define PWMA_OC4_ReloadEnable()		PWMA_CCMR4 |= 0x08		//1：开启 OC4PE 输出比较的预装载功能
#define PWMA_OC4_RelosdDisable()	PWMA_CCMR4 &= ~0x08		//0：禁止 OC4PE 输出比较的预装载功能
#define PWMB_OC8_ReloadEnable()		PWMB_CCMR4 |= 0x08		//1：开启 OC8PE 输出比较的预装载功能
#define PWMB_OC8_RelosdDisable()	PWMB_CCMR4 &= ~0x08		//0：禁止 OC8PE 输出比较的预装载功能

#define PWMA_OC4_FastEnable()			PWMA_CCMR4 |= 0x04		//1：开启 OC4FE 输出比较快速功能
#define PWMA_OC4_FastDisable()		PWMA_CCMR4 &= ~0x04		//0：禁止 OC4FE 输出比较快速功能
#define PWMB_OC8_FastEnable()			PWMB_CCMR4 |= 0x04		//1：开启 OC8FE 输出比较快速功能
#define PWMB_OC8_FastDisable()		PWMB_CCMR4 &= ~0x04		//0：禁止 OC8FE 输出比较快速功能

#define PWMA_CC4S_Direction(n)		PWMA_CCMR4 = (PWMA_CCMR4 & ~0x03) | (n)		//捕获/比较 4 选择。这两位定义通道的方向（输入/输出），及输入脚的选择
#define PWMB_CC8S_Direction(n)		PWMB_CCMR4 = (PWMB_CCMR4 & ~0x03) | (n)		//捕获/比较 8 选择。这两位定义通道的方向（输入/输出），及输入脚的选择

//						                 7     6     5     4      3       2      1     0    Reset Value
//sfr PWMA_CCMR4 = 0xFECBH;  IC4F3 IC4F2 IC4F1 IC4F0 IC4PSC1 IC4PSC0 CC4S1 CC4S0  0000,0000  /* 捕获/比较模式寄存器 4 - 通道配置为捕获输入模式 */ 
//sfr PWMB_CCMR4 = 0xFEEBH;  IC8F3 IC8F2 IC8F1 IC8F0 IC8PSC1 IC8PSC0 CC8S1 CC8S0  0000,0000  /* 捕获/比较模式寄存器 4 - 通道配置为捕获输入模式 */ 

#define PWMA_IC4F_FilterClock(n)	PWMA_CCMR4 = (PWMA_CCMR4 & 0x0F) | (n<<4)		//输入捕获 4 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度
#define PWMB_IC8F_FilterClock(n)	PWMB_CCMR4 = (PWMB_CCMR4 & 0x0F) | (n<<4)		//输入捕获 8 滤波器选择，该位域定义了 TIn 的采样频率及数字滤波器长度

#define PWMA_IC4PSC_PrescalerSet(n)		PWMA_CCMR4 = (PWMA_CCMR4 & 0xF3) | ((n&3)<<2)		//输入/捕获 4 预分频器，0~3
#define PWMB_IC8PSC_PrescalerSet(n)		PWMB_CCMR4 = (PWMB_CCMR4 & 0xF3) | ((n&3)<<2)		//输入/捕获 8 预分频器，0~3

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER1 = 0xFECCH;  CC2NP CC2NE CC2P CC2E CC1NP CC1NE CC1P CC1E  0000,0000  /* 捕获/比较使能寄存器 1 */ 
//sfr PWMB_CCER1 = 0xFEECH;    -     -   CC6P CC6E   -     -   CC5P CC5E  0000,0000  /* 捕获/比较使能寄存器 1 */ 

#define PWMA_CCER1_Disable()			PWMA_CCER1 = 0x00			//关闭所有输入捕获/比较输出
#define PWMA_CC1E_Enable()				PWMA_CCER1 |= 0x01		//1：开启输入捕获/比较输出
#define PWMA_CC1E_Disable()				PWMA_CCER1 &= ~0x01		//0：关闭输入捕获/比较输出
#define PWMA_CC1P_LowValid()			PWMA_CCER1 |= 0x02		//1：低电平有效
#define PWMA_CC1P_HighValid()			PWMA_CCER1 &= ~0x02		//0：高电平有效
#define PWMA_CC1P_CaptureRise()		PWMA_CCER1 |= 0x02		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMA_CC1P_CaptureFall()		PWMA_CCER1 &= ~0x02		//0：捕获发生在 TI1F 或 TI2F 的上升沿
#define PWMA_CC1NE_Enable()				PWMA_CCER1 |= 0x04		//1：开启比较输出
#define PWMA_CC1NE_Disable()			PWMA_CCER1 &= ~0x04		//0：关闭比较输出
#define PWMA_CC1NP_LowValid()			PWMA_CCER1 |= 0x08		//1：低电平有效
#define PWMA_CC1NP_HighValid()		PWMA_CCER1 &= ~0x08		//0：高电平有效

#define PWMA_CC2E_Enable()				PWMA_CCER1 |= 0x10		//1：开启输入捕获/比较输出
#define PWMA_CC2E_Disable()				PWMA_CCER1 &= ~0x10		//0：关闭输入捕获/比较输出
#define PWMA_CC2P_LowValid()			PWMA_CCER1 |= 0x20		//1：低电平有效
#define PWMA_CC2P_HighValid()			PWMA_CCER1 &= ~0x20		//0：高电平有效
#define PWMA_CC2P_CaptureRise()		PWMA_CCER1 |= 0x20		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMA_CC2P_CaptureFall()		PWMA_CCER1 &= ~0x20		//0：捕获发生在 TI1F 或 TI2F 的上升沿
#define PWMA_CC2NE_Enable()				PWMA_CCER1 |= 0x40		//1：开启比较输出
#define PWMA_CC2NE_Disable()			PWMA_CCER1 &= ~0x40		//0：关闭比较输出
#define PWMA_CC2NP_LowValid()			PWMA_CCER1 |= 0x80		//1：低电平有效
#define PWMA_CC2NP_HighValid()		PWMA_CCER1 &= ~0x80		//0：高电平有效

#define PWMB_CCER1_Disable()			PWMB_CCER1 = 0x00			//关闭所有输入捕获/比较输出
#define PWMB_CC5E_Enable()				PWMB_CCER1 |= 0x01		//1：开启输入捕获/比较输出
#define PWMB_CC5E_Disable()				PWMB_CCER1 &= ~0x01		//0：关闭输入捕获/比较输出
#define PWMB_CC5P_LowValid()			PWMB_CCER1 |= 0x02		//1：低电平有效
#define PWMB_CC5P_HighValid()			PWMB_CCER1 &= ~0x02		//0：高电平有效
#define PWMB_CC5P_CaptureRise()		PWMB_CCER1 |= 0x02		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMB_CC5P_CaptureFall()		PWMB_CCER1 &= ~0x02		//0：捕获发生在 TI1F 或 TI2F 的上升沿

#define PWMB_CC6E_Enable()				PWMB_CCER1 |= 0x10		//1：开启输入捕获/比较输出
#define PWMB_CC6E_Disable()				PWMB_CCER1 &= ~0x10		//0：关闭输入捕获/比较输出
#define PWMB_CC6P_LowValid()			PWMB_CCER1 |= 0x20		//1：低电平有效
#define PWMB_CC6P_HighValid()			PWMB_CCER1 &= ~0x20		//0：高电平有效
#define PWMB_CC6P_CaptureRise()		PWMB_CCER1 |= 0x20		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMB_CC6P_CaptureFall()		PWMB_CCER1 &= ~0x20		//0：捕获发生在 TI1F 或 TI2F 的上升沿

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCER2 = 0xFECDH;  CC4NP CC4NE CC4P CC4E CC3NP CC3NE CC3P CC3E  0000,0000  /* 捕获/比较使能寄存器 2 */ 
//sfr PWMB_CCER2 = 0xFEEDH;    -     -   CC8P CC8E   -     -   CC7P CC7E  0000,0000  /* 捕获/比较使能寄存器 2 */ 

#define PWMA_CCER2_Disable()			PWMA_CCER2 = 0x00			//关闭所有输入捕获/比较输出
#define PWMA_CC3E_Enable()				PWMA_CCER2 |= 0x01		//1：开启输入捕获/比较输出
#define PWMA_CC3E_Disable()				PWMA_CCER2 &= ~0x01		//0：关闭输入捕获/比较输出
#define PWMA_CC3P_LowValid()			PWMA_CCER2 |= 0x02		//1：低电平有效
#define PWMA_CC3P_HighValid()			PWMA_CCER2 &= ~0x02		//0：高电平有效
#define PWMA_CC3P_CaptureRise()		PWMA_CCER2 |= 0x02		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMA_CC3P_CaptureFall()		PWMA_CCER2 &= ~0x02		//0：捕获发生在 TI1F 或 TI2F 的上升沿
#define PWMA_CC3NE_Enable()				PWMA_CCER2 |= 0x04		//1：开启比较输出
#define PWMA_CC3NE_Disable()			PWMA_CCER2 &= ~0x04		//0：关闭比较输出
#define PWMA_CC3NP_LowValid()			PWMA_CCER2 |= 0x08		//1：低电平有效
#define PWMA_CC3NP_HighValid()		PWMA_CCER2 &= ~0x08		//0：高电平有效

#define PWMA_CC4E_Enable()				PWMA_CCER2 |= 0x10		//1：开启输入捕获/比较输出
#define PWMA_CC4E_Disable()				PWMA_CCER2 &= ~0x10		//0：关闭输入捕获/比较输出
#define PWMA_CC4P_LowValid()			PWMA_CCER2 |= 0x20		//1：低电平有效
#define PWMA_CC4P_HighValid()			PWMA_CCER2 &= ~0x20		//0：高电平有效
#define PWMA_CC4P_CaptureRise()		PWMA_CCER2 |= 0x20		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMA_CC4P_CaptureFall()		PWMA_CCER2 &= ~0x20		//0：捕获发生在 TI1F 或 TI2F 的上升沿
#define PWMA_CC4NE_Enable()				PWMA_CCER2 |= 0x40		//1：开启比较输出
#define PWMA_CC4NE_Disable()			PWMA_CCER2 &= ~0x40		//0：关闭比较输出
#define PWMA_CC4NP_LowValid()			PWMA_CCER2 |= 0x80		//1：低电平有效
#define PWMA_CC4NP_HighValid()		PWMA_CCER2 &= ~0x80		//0：高电平有效

#define PWMB_CCER2_Disable()			PWMB_CCER2 = 0x00			//关闭所有输入捕获/比较输出
#define PWMB_CC7E_Enable()				PWMB_CCER2 |= 0x01		//1：开启输入捕获/比较输出
#define PWMB_CC7E_Disable()				PWMB_CCER2 &= ~0x01		//0：关闭输入捕获/比较输出
#define PWMB_CC7P_LowValid()			PWMB_CCER2 |= 0x02		//1：低电平有效
#define PWMB_CC7P_HighValid()			PWMB_CCER2 &= ~0x02		//0：高电平有效
#define PWMB_CC7P_CaptureRise()		PWMB_CCER2 |= 0x02		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMB_CC7P_CaptureFall()		PWMB_CCER2 &= ~0x02		//0：捕获发生在 TI1F 或 TI2F 的上升沿

#define PWMB_CC8E_Enable()				PWMB_CCER2 |= 0x10		//1：开启输入捕获/比较输出
#define PWMB_CC8E_Disable()				PWMB_CCER2 &= ~0x10		//0：关闭输入捕获/比较输出
#define PWMB_CC8P_LowValid()			PWMB_CCER2 |= 0x20		//1：低电平有效
#define PWMB_CC8P_HighValid()			PWMB_CCER2 &= ~0x20		//0：高电平有效
#define PWMB_CC8P_CaptureRise()		PWMB_CCER2 |= 0x20		//1：捕获发生在 TI1F 或 TI2F 的下降沿
#define PWMB_CC8P_CaptureFall()		PWMB_CCER2 &= ~0x20		//0：捕获发生在 TI1F 或 TI2F 的上升沿

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CNTRH = 0xFECEH;                   CNT1[15:8]                  0000,0000  /* 计数器高 8 位 */ 
//sfr PWMB_CNTRH = 0xFEEEH;                   CNT2[15:8]                  0000,0000  /* 计数器高 8 位 */ 
//sfr PWMA_CNTRL = 0xFECFH;                   CNT1[7:0]                   0000,0000  /* 计数器低 8 位 */ 
//sfr PWMB_CNTRL = 0xFEEFH;                   CNT2[7:0]                   0000,0000  /* 计数器低 8 位 */ 

#define PWMA_Counter(n)						PWMA_CNTR = n		//计数器设置
#define PWMB_Counter(n)						PWMB_CNTR = n		//计数器设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_PSCRH = 0xFED0H;                   PSC1[15:8]                  0000,0000  /* 预分频器高 8 位 */ 
//sfr PWMB_PSCRH = 0xFEF0H;                   PSC2[15:8]                  0000,0000  /* 预分频器高 8 位 */ 
//sfr PWMA_PSCRL = 0xFED1H;                   PSC1[7:0]                   0000,0000  /* 预分频器低 8 位 */ 
//sfr PWMB_PSCRL = 0xFEF1H;                   PSC2[7:0]                   0000,0000  /* 预分频器低 8 位 */ 

#define PWMA_Prescaler(n)					PWMA_PSCR = n		//预分频器设置
#define PWMB_Prescaler(n)					PWMB_PSCR = n		//预分频器设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_ARRH = 0xFED2H;                    ARR1[15:8]                  0000,0000  /* 自动重装载寄存器高 8 位 */ 
//sfr PWMB_ARRH = 0xFEF2H;                    ARR2[15:8]                  0000,0000  /* 自动重装载寄存器高 8 位 */ 
//sfr PWMA_ARRL = 0xFED3H;                    ARR1[7:0]                   0000,0000  /* 自动重装载寄存器低 8 位 */ 
//sfr PWMB_ARRL = 0xFEF3H;                    ARR2[7:0]                   0000,0000  /* 自动重装载寄存器低 8 位 */ 

#define PWMA_AutoReload(n)				PWMA_ARR = n		//自动重装载寄存器设置
#define PWMB_AutoReload(n)				PWMB_ARR = n		//自动重装载寄存器设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_RCR = 0xFED4H;                     REP1[7:0]                   0000,0000  /* 重复计数器寄存器 */ 
//sfr PWMB_RCR = 0xFEF4H;                     REP2[7:0]                   0000,0000  /* 重复计数器寄存器 */ 

#define PWMA_ReCounter(n)					PWMA_RCR = n		//重复计数器寄存器设置
#define PWMB_ReCounter(n)					PWMB_RCR = n		//重复计数器寄存器设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR1H = 0xFED5H;                   CCR1[15:8]                  0000,0000  /* 捕获/比较寄存器 1 高 8 位 */ 
//sfr PWMB_CCR5H = 0xFEF5H;                   CCR5[15:8]                  0000,0000  /* 捕获/比较寄存器 1 高 8 位 */ 
//sfr PWMA_CCR1L = 0xFED6H;                   CCR1[7:0]                   0000,0000  /* 捕获/比较寄存器 1 低 8 位 */ 
//sfr PWMB_CCR5L = 0xFEF6H;                   CCR5[7:0]                   0000,0000  /* 捕获/比较寄存器 1 低 8 位 */ 

#define PWMA_Duty1(n)							PWMA_CCR1 = n		//捕获/比较寄存器 1 设置
#define PWMB_Duty5(n)							PWMB_CCR5 = n		//捕获/比较寄存器 1 设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR2H = 0xFED7H;                   CCR2[15:8]                  0000,0000  /* 捕获/比较寄存器 2 高 8 位 */ 
//sfr PWMB_CCR6H = 0xFEF7H;                   CCR6[15:8]                  0000,0000  /* 捕获/比较寄存器 2 高 8 位 */ 
//sfr PWMA_CCR2L = 0xFED8H;                   CCR2[7:0]                   0000,0000  /* 捕获/比较寄存器 2 低 8 位 */ 
//sfr PWMB_CCR6L = 0xFEF8H;                   CCR6[7:0]                   0000,0000  /* 捕获/比较寄存器 2 低 8 位 */ 

#define PWMA_Duty2(n)							PWMA_CCR2 = n		//捕获/比较寄存器 2 设置
#define PWMB_Duty6(n)							PWMB_CCR6 = n		//捕获/比较寄存器 2 设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR3H = 0xFED9H;                   CCR3[15:8]                  0000,0000  /* 捕获/比较寄存器 3 高 8 位 */ 
//sfr PWMB_CCR7H = 0xFEF9H;                   CCR7[15:8]                  0000,0000  /* 捕获/比较寄存器 3 高 8 位 */ 
//sfr PWMA_CCR3L = 0xFEDAH;                   CCR3[7:0]                   0000,0000  /* 捕获/比较寄存器 3 低 8 位 */ 
//sfr PWMB_CCR7L = 0xFEFAH;                   CCR7[7:0]                   0000,0000  /* 捕获/比较寄存器 3 低 8 位 */ 

#define PWMA_Duty3(n)							PWMA_CCR3 = n		//捕获/比较寄存器 3 设置
#define PWMB_Duty7(n)							PWMB_CCR7 = n		//捕获/比较寄存器 3 设置

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_CCR4H = 0xFEDBH;                   CCR4[15:8]                  0000,0000  /* 捕获/比较寄存器 4 高 8 位 */ 
//sfr PWMB_CCR8H = 0xFEFBH;                   CCR8[15:8]                  0000,0000  /* 捕获/比较寄存器 4 高 8 位 */ 
//sfr PWMA_CCR4L = 0xFEDCH;                   CCR4[7:0]                   0000,0000  /* 捕获/比较寄存器 4 低 8 位 */ 
//sfr PWMB_CCR8L = 0xFEFCH;                   CCR8[7:0]                   0000,0000  /* 捕获/比较寄存器 4 低 8 位 */ 

#define PWMA_Duty4(n)							PWMA_CCR4 = n		//捕获/比较寄存器 4 设置
#define PWMB_Duty8(n)							PWMB_CCR8 = n		//捕获/比较寄存器 4 设置

//						              7    6    5    4     3     2     1      0     Reset Value
//sfr PWMA_BRK = 0xFEDDH;  MOE1 AOE1 BKP1 BKE1 OSSR1 OSSI1 LOCK11 LOCK10  0000,0000  /* 刹车寄存器 */ 
//sfr PWMB_BRK = 0xFEFDH;  MOE2 AOE2 BKP2 BKE2 OSSR2 OSSI2 LOCK21 LOCK20  0000,0000  /* 刹车寄存器 */ 

#define PWMA_BrakeOutputEnable()				PWMA_BRK |= 0x80		//1：主输出使能
#define PWMA_BrakeOutputDisable()				PWMA_BRK &= ~0x80		//0：主输出禁止
#define PWMB_BrakeOutputEnable()				PWMB_BRK |= 0x80		//1：主输出使能
#define PWMB_BrakeOutputDisable()				PWMB_BRK &= ~0x80		//0：主输出禁止

#define PWMA_BrakeAutoOutputEnable()		PWMA_BRK |= 0x40		//1：自动输出使能
#define PWMA_BrakeAutoOutputDisable()		PWMA_BRK &= ~0x40		//0：自动输出禁止
#define PWMB_BrakeAutoOutputEnable()		PWMB_BRK |= 0x40		//1：自动输出使能
#define PWMB_BrakeAutoOutputDisable()		PWMB_BRK &= ~0x40		//0：自动输出禁止

#define PWMA_BrakeHighValid()						PWMA_BRK |= 0x20		//1：刹车输入高电平有效
#define PWMA_BrakeLowValid()						PWMA_BRK &= ~0x20		//0：刹车输入低电平有效
#define PWMB_BrakeHighValid()						PWMB_BRK |= 0x20		//1：刹车输入高电平有效
#define PWMB_BrakeLowValid()						PWMB_BRK &= ~0x20		//0：刹车输入低电平有效

#define PWMA_BrakeEnable()							PWMA_BRK |= 0x10		//1：开启刹车输入
#define PWMA_BrakeDisable()							PWMA_BRK &= ~0x10		//0：禁止刹车输入
#define PWMB_BrakeEnable()							PWMB_BRK |= 0x10		//1：开启刹车输入
#define PWMB_BrakeDisable()							PWMB_BRK &= ~0x10		//0：禁止刹车输入

//运行模式下“关闭状态”选择
#define PWMA_OSSRnEnable()							PWMA_BRK |= 0x08		//1：当 PWM 不工作时，一旦 CCiE=1 或 CCiNE=1，首先开启 OC/OCN 并输出无效电平，然后置OC/OCN 使能输出信号=1
#define PWMA_OSSRnDisable()							PWMA_BRK &= ~0x08		//0：当 PWM 不工作时，禁止 OC/OCN 输出（OC/OCN 使能输出信号=0）
#define PWMB_OSSRnEnable()							PWMB_BRK |= 0x08		//1：当 PWM 不工作时，一旦 CCiE=1 或 CCiNE=1，首先开启 OC/OCN 并输出无效电平，然后置OC/OCN 使能输出信号=1
#define PWMB_OSSRnDisable()							PWMB_BRK &= ~0x08		//0：当 PWM 不工作时，禁止 OC/OCN 输出（OC/OCN 使能输出信号=0）
//空闲模式下“关闭状态”选择
#define PWMA_OSSInEnable()							PWMA_BRK |= 0x04		//1：当 PWM 不工作时，一旦 CCiE=1 或 CCiNE=1，OC/OCN 首先输出其空闲电平，然后 OC/OCN使能输出信号=1
#define PWMA_OSSInDisable()							PWMA_BRK &= ~0x04		//0：当 PWM 不工作时，禁止 OC/OCN 输出（OC/OCN 使能输出信号=0）
#define PWMB_OSSInEnable()							PWMB_BRK |= 0x04		//1：当 PWM 不工作时，一旦 CCiE=1 或 CCiNE=1，OC/OCN 首先输出其空闲电平，然后 OC/OCN使能输出信号=1
#define PWMB_OSSInDisable()							PWMB_BRK &= ~0x04		//0：当 PWM 不工作时，禁止 OC/OCN 输出（OC/OCN 使能输出信号=0）

#define PWMn_lock_L0			0		//寄存器无写保护
#define PWMn_lock_L1			1		//锁定级别 1：不能写入 PWMn_BKR 寄存器的 BKE、BKP、AOE 位和PWMn_OISR 寄存器的 OISI 位
#define PWMn_lock_L2			2		//锁定级别 2：不能写入锁定级别 1 中的各位，也不能写入 CC 极性位以及 OSSR/OSSI 位
#define PWMn_lock_L3			3		//锁定级别 3：不能写入锁定级别 2 中的各位，也不能写入 CC 控制位

#define PWMA_LockLevelSet(n)						PWMA_BRK = (PWMA_BRK & ~0x03) | (n&3)		//锁定设置。该位为防止软件错误而提供的写保护措施
#define PWMB_LockLevelSet(n)						PWMB_BRK = (PWMB_BRK & ~0x03) | (n&3)		//锁定设置。该位为防止软件错误而提供的写保护措施

//						                 7     6     5    4    3     2    1    0    Reset Value
//sfr PWMA_DTR = 0xFEDEH;                     DTG1[7:0]                   0000,0000  /* 死区寄存器 */ 
//sfr PWMB_DTR = 0xFEFEH;                     DTG2[7:0]                   0000,0000  /* 死区寄存器 */ 

//DTGn[7:5] = 000~011: 死区时间 = DTGn[7:0] * tCK_PSC
//DTGn[7:5] = 100~101: 死区时间 = (64 + DTGn[6:0]) * 2 * tCK_PSC
//DTGn[7:5] = 110:     死区时间 = (32 + DTGn[5:0]) * 8 * tCK_PSC
//DTGn[7:5] = 111:     死区时间 = (32 + DTGn[4:0]) * 16 * tCK_PSC

#define PWMA_DeadTime(n)					PWMA_DTR = n		//死区发生器设置
#define PWMB_DeadTime(n)					PWMB_DTR = n		//死区发生器设置

//						                7    6     5    4     3    2     1    0    Reset Value
//sfr PWMA_OISR = 0xFEDFH;  OIS4N OIS4 OIS3N OIS3 OIS2N OIS2 OIS1N OIS1  0000,0000  /* 输出空闲状态寄存器 */ 
//sfr PWMB_OISR = 0xFEFFH;    -   OIS8   -   OIS7   -   OIS6   -   OIS5  x0x0,x0x0  /* 输出空闲状态寄存器 */ 

#define PWMA_OC1_OUT_0()					PWMA_OISR &= ~0x01	/* 当 MOE=0 时，如果 OC1N 使能，则在一个死区后，OC1=0 */
#define PWMA_OC1_OUT_1()					PWMA_OISR |= 0x01		/* 当 MOE=0 时，如果 OC1N 使能，则在一个死区后，OC1=1 */
#define PWMA_OC1N_OUT_0()					PWMA_OISR &= ~0x02	/* 当 MOE=0 时，则在一个死区后，OC1N=0 */
#define PWMA_OC1N_OUT_1()					PWMA_OISR |= 0x02		/* 当 MOE=0 时，则在一个死区后，OC1N=1 */
#define PWMA_OC2_OUT_0()					PWMA_OISR &= ~0x04	/* 当 MOE=0 时，如果 OC2N 使能，则在一个死区后，OC2=0 */
#define PWMA_OC2_OUT_1()					PWMA_OISR |= 0x04		/* 当 MOE=0 时，如果 OC2N 使能，则在一个死区后，OC2=1 */
#define PWMA_OC2N_OUT_0()					PWMA_OISR &= ~0x08	/* 当 MOE=0 时，则在一个死区后，OC2N=0 */
#define PWMA_OC2N_OUT_1()					PWMA_OISR |= 0x08		/* 当 MOE=0 时，则在一个死区后，OC2N=1 */
#define PWMA_OC3_OUT_0()					PWMA_OISR &= ~0x10	/* 当 MOE=0 时，如果 OC3N 使能，则在一个死区后，OC3=0 */
#define PWMA_OC3_OUT_1()					PWMA_OISR |= 0x10		/* 当 MOE=0 时，如果 OC3N 使能，则在一个死区后，OC3=1 */
#define PWMA_OC3N_OUT_0()					PWMA_OISR &= ~0x20	/* 当 MOE=0 时，则在一个死区后，OC3N=0 */
#define PWMA_OC3N_OUT_1()					PWMA_OISR |= 0x20		/* 当 MOE=0 时，则在一个死区后，OC3N=1 */
#define PWMA_OC4_OUT_0()					PWMA_OISR &= ~0x40	/* 当 MOE=0 时，如果 OC4N 使能，则在一个死区后，OC4=0 */
#define PWMA_OC4_OUT_1()					PWMA_OISR |= 0x40		/* 当 MOE=0 时，如果 OC4N 使能，则在一个死区后，OC4=1 */
#define PWMA_OC4N_OUT_0()					PWMA_OISR &= ~0x80	/* 当 MOE=0 时，则在一个死区后，OC4N=0 */
#define PWMA_OC4N_OUT_1()					PWMA_OISR |= 0x80		/* 当 MOE=0 时，则在一个死区后，OC4N=1 */

#define PWMB_OC5_OUT_0()					PWMB_OISR &= ~0x01	/* 当 MOE=0 时，则在一个死区后，OC5=0 */
#define PWMB_OC5_OUT_1()					PWMB_OISR |= 0x01		/* 当 MOE=0 时，则在一个死区后，OC5=1 */
#define PWMB_OC6_OUT_0()					PWMB_OISR &= ~0x04	/* 当 MOE=0 时，则在一个死区后，OC6=0 */
#define PWMB_OC6_OUT_1()					PWMB_OISR |= 0x04		/* 当 MOE=0 时，则在一个死区后，OC6=1 */
#define PWMB_OC7_OUT_0()					PWMB_OISR &= ~0x10	/* 当 MOE=0 时，则在一个死区后，OC7=0 */
#define PWMB_OC7_OUT_1()					PWMB_OISR |= 0x10		/* 当 MOE=0 时，则在一个死区后，OC7=1 */
#define PWMB_OC8_OUT_0()					PWMB_OISR &= ~0x40	/* 当 MOE=0 时，则在一个死区后，OC8=0 */
#define PWMB_OC8_OUT_1()					PWMB_OISR |= 0x40		/* 当 MOE=0 时，则在一个死区后，OC8=1 */




/*
;PCA_PWMn:    7       6     5   4   3   2     1       0
;			EBSn_1	EBSn_0	-	-	-	-	EPCnH	EPCnL
;B5-B2:		保留
;B1(EPCnH):	在PWM模式下，与CCAPnH组成9位数。
;B0(EPCnL):	在PWM模式下，与CCAPnL组成9位数。
*/
#define		PWM0_NORMAL()	PCA_PWM0 &= ~3					/* PWM0正常输出(默认)	*/
#define		PWM0_OUT_0()	PCA_PWM0 |=  3, CCAP0H = 0xff	/* PWM0一直输出0		*/
#define		PWM0_OUT_1()	PCA_PWM0 &= 0xc0, CCAP0H = 0	/* PWM0一直输出1		*/

#define		PWM1_NORMAL()	PCA_PWM1 &= ~3					/* PWM1正常输出(默认)	*/
#define		PWM1_OUT_0()	PCA_PWM1 |=  3, CCAP1H = 0xff	/* PWM1一直输出0		*/
#define		PWM1_OUT_1()	PCA_PWM1 &= 0xc0, CCAP1H = 0	/* PWM1一直输出1		*/

#define		PWM2_NORMAL()	PCA_PWM2 &= ~3					/* PWM2正常输出(默认)	*/
#define		PWM2_OUT_0()	PCA_PWM2 |=  3, CCAP2H = 0xff	/* PWM2一直输出0		*/
#define		PWM2_OUT_1()	PCA_PWM2 &= 0xc0, CCAP2H = 0	/* PWM2一直输出1		*/

//#define		PWM3_NORMAL()	PCA_PWM3 &= ~3					/* PWM3正常输出(默认)	*/
//#define		PWM3_OUT_0()	PCA_PWM3 |=  3, CCAP3H = 0xff	/* PWM3一直输出0		*/
//#define		PWM3_OUT_1()	PCA_PWM3 &= 0xc0, CCAP3H = 0	/* PWM3一直输出1		*/


//						7     6     5     4     3     2     1     0     Reset Value
//sfr CCON   = 0xD8;	CF    CR    -     -    CCF3  CCF2  CCF1  CCF0   00xx,xx00	//PCA 控制寄存器。
sbit CCF0  = CCON^0;	/* PCA 模块0中断标志，由硬件置位，必须由软件清0。	*/
sbit CCF1  = CCON^1;	/* PCA 模块1中断标志，由硬件置位，必须由软件清0。	*/
sbit CCF2  = CCON^2;	/* PCA 模块2中断标志，由硬件置位，必须由软件清0。	*/
//sbit CCF3  = CCON^3;	/* PCA 模块3中断标志，由硬件置位，必须由软件清0。	*/
sbit CR    = CCON^6;	/* 1: 允许PCA计数器计数，必须由软件清0。*/
sbit CF    = CCON^7;	/* PCA计数器溢出（CH，CL由FFFFH变为0000H）标志。PCA计数器溢出后由硬件置位，必须由软件清0。*/

//					 7     6     5     4     3     2     1     0    Reset Value
//sfr CMOD  = 0xD9;	CIDL   -     -     -   CPS2   CPS1  CPS0  ECF   0xxx,0000	//PCA 工作模式寄存器。
#define PCA_IDLE_OFF()		CMOD |=  (1<<7)				/* IDLE状态PCA停止计数。	*/
#define PCA_IDLE_ON()		CMOD &= ~(1<<7)				/* IDLE状态PCA继续计数。	*/
#define PCA_CLK_12T()		CMOD &= ~0x0E				/* PCA计数脉冲选择 fosc/12	*/
#define PCA_CLK_2T()		CMOD = (CMOD & ~0x0E) + 2	/* PCA计数脉冲选择 fosc/2	*/
#define PCA_CLK_T0()		CMOD = (CMOD & ~0x0E) + 4	/* PCA计数脉冲选择Timer0中断，Timer0可通过AUXR寄存器设置成工作在12T或1T模式。	*/
#define PCA_CLK_ECI()		CMOD = (CMOD & ~0x0E) + 6	/* PCA计数脉冲选择从ECI/P3.4脚输入的外部时钟，最大 fosc/2。	*/
#define PCA_CLK_1T()		CMOD = (CMOD & ~0x0E) + 8	/* PCA计数脉冲选择 Fosc	*/
#define PCA_CLK_4T()		CMOD = (CMOD & ~0x0E) + 10	/* PCA计数脉冲选择 Fosc/4	*/
#define PCA_CLK_6T()		CMOD = (CMOD & ~0x0E) + 12	/* PCA计数脉冲选择 Fosc/6	*/
#define PCA_CLK_8T()		CMOD = (CMOD & ~0x0E) + 14	/* PCA计数脉冲选择 Fosc/8	*/
#define PCA_INT_ENABLE()	CMOD |=  1					/* PCA计数器溢出中断允许位，1---允许CF（CCON.7）产生中断。	*/
#define PCA_INT_DISABLE()	CMOD &= ~1					/* PCA计数器溢出中断禁止。	*/

//                	    7      6       5        4       3       2       1      0    Reset Value
//sfr P_SW1 = 0xA2;	  S1_S1  S1_S0  CCP_S1   CCP_S0  SPI_S1   SPI_S0    0      -    nn00,000x		//Auxiliary Register 1
#define		PCA_USE_P12P11P10P37()	P_SW1 &= ~0x30				/* 将PCA/PWM切换到P12(ECI) P11(CCP0) P10(CCP1) P37(CCP2)(上电默认) */
#define		PCA_USE_P34P35P36P37()	P_SW1 = (P_SW1 & ~0x30) | 0x10	/* 将PCA/PWM切换到P34(ECI) P35(CCP0) P36(CCP1) P37(CCP2) */
#define		PCA_USE_P24P25P26P27()	P_SW1 = (P_SW1 & ~0x30) | 0x20	/* 将PCA/PWM切换到P24(ECI) P25(CCP0) P26(CCP1) P27(CCP2) */


/*									7     6       5       4     3     2     1     0     Reset Value
//sfr CCAPM0 = 0xDA;	PWM 寄存器  -   ECOM0  CCAPP0  CCAPN0  MAT0  TOG0  PWM0  ECCF0   x000,0000	//PCA 模块0
//sfr CCAPM1 = 0xDB;	PWM 寄存器  -   ECOM1  CCAPP1  CCAPN1  MAT1  TOG1  PWM1  ECCF1   x000,0000	//PCA 模块1
//sfr CCAPM2 = 0xDC;	PWM 寄存器  -   ECOM2  CCAPP2  CCAPN2  MAT2  TOG2  PWM2  ECCF2   x000,0000	//PCA 模块2
//sfr CCAPM3 = 0xDD;	PWM 寄存器  -   ECOM3  CCAPP3  CCAPN3  MAT3  TOG3  PWM3  ECCF3   x000,0000	//PCA 模块3
;ECOMn = 1:	允许比较功能。
;CAPPn = 1:	允许上升沿触发捕捉功能。
;CAPNn = 1:	允许下降沿触发捕捉功能。
;MATn  = 1:	当匹配情况发生时，允许CCON中的CCFn置位。
;TOGn  = 1:	当匹配情况发生时，CEXn将翻转。(CEX0/PCA0/PWM0/P3.7,CEX1/PCA1/PWM1/P3.5)
;PWMn  = 1:	将CEXn设置为PWM输出。
;ECCFn = 1:	允许CCON中的CCFn触发中断。
;ECOMn CAPPn CAPNn MATn TOGn PWMn ECCFn
;  0     0     0    0    0    0     0		00H	未启用任何功能。
;  x     1     0    0    0    0     x	 	20H	16位CEXn上升沿触发捕捉功能。
;  x     0     1    0    0    0     x	 	10H	16位CEXn下降沿触发捕捉功能。
;  x     1     1    0    0    0     x	 	30H	16位CEXn/PCAn边沿（上、下沿）触发捕捉功能。
;  1     0     0    1    0    0     x	 	48H	16位软件定时器。
;  1     0     0    1    1    0     x	 	4CH	16位高速脉冲输出。
;  1     0     0    0    0    1     0		42H	8位PWM。无中断
;  1     1     0    0    0    1     1		63H	8位PWM。低变高可产生中断
;  1     0     1    0    0    1     1		53H	8位PWM。高变低可产生中断
;  1     1     1    0    0    1     1		73H	8位PWM。低变高或高变低均可产生中断
;*******************************************************************
;*******************************************************************/

#define		PCA0_none()				CCAPM0 = 0
#define		PCA0_PWM(nbit)			CCAPM0 = 0x42,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_PWM_rise_int(nbit) CCAPM0 = 0x63,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_PWM_fall_int(nbit) CCAPM0 = 0x53,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_PWM_edge_int(nbit) CCAPM0 = 0x73,PCA_PWM0 = (PCA_PWM0 & 0x3f) | (nbit<<6)
#define		PCA0_capture_rise()		CCAPM0 = (0x20 + 1)
#define		PCA0_capture_fall()		CCAPM0 = (0x10 + 1)
#define		PCA0_capture_edge()		CCAPM0 = (0x30 + 1)
#define		PCA0_16bit_Timer()		CCAPM0 = (0x48 + 1)
#define		PCA0_High_PulseEnable()	CCAPM0 |= 0x04

#define		PCA1_none()				CCAPM1 = 0
#define		PCA1_PWM(nbit)			CCAPM1 = 0x42,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_PWM_rise_int(nbit) CCAPM1 = 0x63,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_PWM_fall_int(nbit) CCAPM1 = 0x53,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_PWM_edge_int(nbit) CCAPM1 = 0x73,PCA_PWM1 = (PCA_PWM1 & 0x3f) | (nbit<<6)
#define		PCA1_capture_rise()		CCAPM1 = (0x20 + 1)
#define		PCA1_capture_fall()		CCAPM1 = (0x10 + 1)
#define		PCA1_capture_edge()		CCAPM1 = (0x30 + 1)
#define		PCA1_16bit_Timer()		CCAPM1 = (0x48 + 1)
#define		PCA1_High_PulseEnable()	CCAPM1 |= 0x04

#define		PCA2_none()				CCAPM2 = 0
#define		PCA2_PWM(nbit)			CCAPM2 = 0x42,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_PWM_rise_int(nbit) CCAPM2 = 0x63,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_PWM_fall_int(nbit) CCAPM2 = 0x53,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_PWM_edge_int(nbit) CCAPM2 = 0x73,PCA_PWM2 = (PCA_PWM2 & 0x3f) | (nbit<<6)
#define		PCA2_capture_rise()		CCAPM2 = (0x20 + 1)
#define		PCA2_capture_fall()		CCAPM2 = (0x10 + 1)
#define		PCA2_capture_edge()		CCAPM2 = (0x30 + 1)
#define		PCA2_16bit_Timer()		CCAPM2 = (0x48 + 1)
#define		PCA2_High_PulseEnable()	CCAPM2 |= 0x04

//#define		PCA3_none()				CCAPM3 = 0
//#define		PCA3_PWM(nbit)			CCAPM3 = 0x42,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_PWM_rise_int(nbit) CCAPM3 = 0x63,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_PWM_fall_int(nbit) CCAPM3 = 0x53,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_PWM_edge_int(nbit) CCAPM3 = 0x73,PCA_PWM3 = (PCA_PWM3 & 0x3f) | (nbit<<6)
//#define		PCA3_capture_rise()		CCAPM3 = (0x20 + 1)
//#define		PCA3_capture_fall()		CCAPM3 = (0x10 + 1)
//#define		PCA3_capture_edge()		CCAPM3 = (0x30 + 1)
//#define		PCA3_16bit_Timer()		CCAPM3 = (0x48 + 1)
//#define		PCA3_High_PulseEnable()	CCAPM3 |= 0x04

/**********************************************************/
typedef 	unsigned char	u8;
typedef 	unsigned int	u16;
typedef 	         int	h16;
typedef 	unsigned long	u32;

/**********************************************************/
#define NOP1()  _nop_()
#define NOP2()  NOP1(),NOP1()
#define NOP3()  NOP2(),NOP1()
#define NOP4()  NOP3(),NOP1()
#define NOP5()  NOP4(),NOP1()
#define NOP6()  NOP5(),NOP1()
#define NOP7()  NOP6(),NOP1()
#define NOP8()  NOP7(),NOP1()
#define NOP9()  NOP8(),NOP1()
#define NOP10() NOP9(),NOP1()
#define NOP11() NOP10(),NOP1()
#define NOP12() NOP11(),NOP1()
#define NOP13() NOP12(),NOP1()
#define NOP14() NOP13(),NOP1()
#define NOP15() NOP14(),NOP1()
#define NOP16() NOP15(),NOP1()
#define NOP17() NOP16(),NOP1()
#define NOP18() NOP17(),NOP1()
#define NOP19() NOP18(),NOP1()
#define NOP20() NOP19(),NOP1()
#define NOP21() NOP20(),NOP1()
#define NOP22() NOP21(),NOP1()
#define NOP23() NOP22(),NOP1()
#define NOP24() NOP23(),NOP1()
#define NOP25() NOP24(),NOP1()
#define NOP26() NOP25(),NOP1()
#define NOP27() NOP26(),NOP1()
#define NOP28() NOP27(),NOP1()
#define NOP29() NOP28(),NOP1()
#define NOP30() NOP29(),NOP1()
#define NOP31() NOP30(),NOP1()
#define NOP32() NOP31(),NOP1()
#define NOP33() NOP32(),NOP1()
#define NOP34() NOP33(),NOP1()
#define NOP35() NOP34(),NOP1()
#define NOP36() NOP35(),NOP1()
#define NOP37() NOP36(),NOP1()
#define NOP38() NOP37(),NOP1()
#define NOP39() NOP38(),NOP1()
#define NOP40() NOP39(),NOP1()
#define NOP(N)  NOP##N()


/**********************************************/
#define	Pin0		0x01	//IO引脚 Px.0
#define	Pin1		0x02	//IO引脚 Px.1
#define	Pin2		0x04	//IO引脚 Px.2
#define	Pin3		0x08	//IO引脚 Px.3
#define	Pin4		0x10	//IO引脚 Px.4
#define	Pin5		0x20	//IO引脚 Px.5
#define	Pin6		0x40	//IO引脚 Px.6
#define	Pin7		0x80	//IO引脚 Px.7
#define	PinAll		0xFF	//IO所有引脚

#define P0n_standard(bitn)			P0M1 &= ~(bitn),	P0M0 &= ~(bitn)	/* 00  */
#define P0n_push_pull(bitn)			P0M1 &= ~(bitn),	P0M0 |=  (bitn)	/* 01  */
#define P0n_pure_input(bitn)		P0M1 |=  (bitn),	P0M0 &= ~(bitn)	/* 10  */
#define P0n_open_drain(bitn)		P0M1 |=  (bitn),	P0M0 |=  (bitn)	/* 11  */

#define P1n_standard(bitn)			P1M1 &= ~(bitn),	P1M0 &= ~(bitn)
#define P1n_push_pull(bitn)			P1M1 &= ~(bitn),	P1M0 |=  (bitn)
#define P1n_pure_input(bitn)		P1M1 |=  (bitn),	P1M0 &= ~(bitn)
#define P1n_open_drain(bitn)		P1M1 |=  (bitn),	P1M0 |=  (bitn)

#define P2n_standard(bitn)			P2M1 &= ~(bitn),	P2M0 &= ~(bitn)
#define P2n_push_pull(bitn)			P2M1 &= ~(bitn),	P2M0 |=  (bitn)
#define P2n_pure_input(bitn)		P2M1 |=  (bitn),	P2M0 &= ~(bitn)
#define P2n_open_drain(bitn)		P2M1 |=  (bitn),	P2M0 |=  (bitn)

#define P3n_standard(bitn)			P3M1 &= ~(bitn),	P3M0 &= ~(bitn)
#define P3n_push_pull(bitn)			P3M1 &= ~(bitn),	P3M0 |=  (bitn)
#define P3n_pure_input(bitn)		P3M1 |=  (bitn),	P3M0 &= ~(bitn)
#define P3n_open_drain(bitn)		P3M1 |=  (bitn),	P3M0 |=  (bitn)

#define P4n_standard(bitn)			P4M1 &= ~(bitn),	P4M0 &= ~(bitn)
#define P4n_push_pull(bitn)			P4M1 &= ~(bitn),	P4M0 |=  (bitn)
#define P4n_pure_input(bitn)		P4M1 |=  (bitn),	P4M0 &= ~(bitn)
#define P4n_open_drain(bitn)		P4M1 |=  (bitn),	P4M0 |=  (bitn)

#define P5n_standard(bitn)			P5M1 &= ~(bitn),	P5M0 &= ~(bitn)
#define P5n_push_pull(bitn)			P5M1 &= ~(bitn),	P5M0 |=  (bitn)
#define P5n_pure_input(bitn)		P5M1 |=  (bitn),	P5M0 &= ~(bitn)
#define P5n_open_drain(bitn)		P5M1 |=  (bitn),	P5M0 |=  (bitn)

#define P6n_standard(bitn)			P6M1 &= ~(bitn),	P6M0 &= ~(bitn)
#define P6n_push_pull(bitn)			P6M1 &= ~(bitn),	P6M0 |=  (bitn)
#define P6n_pure_input(bitn)		P6M1 |=  (bitn),	P6M0 &= ~(bitn)
#define P6n_open_drain(bitn)		P6M1 |=  (bitn),	P6M0 |=  (bitn)

#define P7n_standard(bitn)			P7M1 &= ~(bitn),	P7M0 &= ~(bitn)
#define P7n_push_pull(bitn)			P7M1 &= ~(bitn),	P7M0 |=  (bitn)
#define P7n_pure_input(bitn)		P7M1 |=  (bitn),	P7M0 &= ~(bitn)
#define P7n_open_drain(bitn)		P7M1 |=  (bitn),	P7M0 |=  (bitn)


/****************************************************************/


//sfr INT_CLKO = 0x8F;	//附加的 SFR WAKE_CLKO (地址：0x8F)
/*
    7   6    5    4   3     2        1       0         Reset Value
    -  EX4  EX3  EX2  -   T2CLKO   T1CLKO  T0CLKO      0000,0000B
b6 -  EX4      : 外中断INT4允许
b5 -  EX3      : 外中断INT3允许
b4 -  EX2      : 外中断INT2允许
b2 - T1CLKO    : 允许 T2 溢出脉冲在P3.0脚输出，Fck1 = 1/2 T1 溢出率
b1 - T1CLKO    : 允许 T1 溢出脉冲在P3.4脚输出，Fck1 = 1/2 T1 溢出率
b0 - T0CLKO    : 允许 T0 溢出脉冲在P3.5脚输出，Fck0 = 1/2 T0 溢出率
*/

#define		LVD_InterruptEnable()		ELVD = 1
#define		LVD_InterruptDisable()		ELVD = 0


//sfr WKTCL = 0xAA;	//唤醒定时器低字节
//sfr WKTCH = 0xAB;	//唤醒定时器高字节
//	B7		B6	B5	B4	B3	B2	B1	B0		B7	B6	B5	B4	B3	B2	B1	B0
//	WKTEN				S11	S10	S9	S8		S7	S6	S5	S4	S3	S2	S1	S0	n * 560us
#define		WakeTimerDisable()		WKTCH &= 0x7f	/* WKTEN = 0		禁止睡眠唤醒定时器 */
#define		WakeTimerSet(scale)		WKTCL = (scale) % 256,WKTCH = (scale) / 256 | 0x80	/* WKTEN = 1	允许睡眠唤醒定时器 */



//sfr BUS_SPEED = 0xA1; //Stretch register      -   -  -  -   -   -  EXRTS1  EXRTSS0 xxxx,xx10
#define		BUS_SPEED_1T()	BUS_SPEED = BUS_SPEED & ~3
#define		BUS_SPEED_2T()	BUS_SPEED = (BUS_SPEED & ~3) | 1
#define		BUS_SPEED_4T()	BUS_SPEED = (BUS_SPEED & ~3) | 2
#define		BUS_SPEED_8T()	BUS_SPEED = (BUS_SPEED & ~3) | 3

#define		BUS_RD_WR_P44_P43()	BUS_SPEED = BUS_SPEED & 0x3f
#define		BUS_RD_WR_P37_P36()	BUS_SPEED = (BUS_SPEED & 0x3f) | 0x40
#define		BUS_RD_WR_P42_P40()	BUS_SPEED = (BUS_SPEED & 0x3f) | 0x80


/*   interrupt vector */
#define		INT0_VECTOR		0
#define		TIMER0_VECTOR	1
#define		INT1_VECTOR		2
#define		TIMER1_VECTOR	3
#define		UART1_VECTOR	4
#define		ADC_VECTOR		5
#define		LVD_VECTOR		6
#define		PCA_VECTOR		7
#define		UART2_VECTOR	8
#define		SPI_VECTOR		9
#define		INT2_VECTOR		10
#define		INT3_VECTOR		11
#define		TIMER2_VECTOR	12
#define		INT4_VECTOR		16
#define		UART3_VECTOR	17
#define		UART4_VECTOR	18
#define		TIMER3_VECTOR	19
#define		TIMER4_VECTOR	20
#define		CMP_VECTOR		21
#define		PWM0_VECTOR		22
#define		PWMFD_VECTOR	23
#define		I2C_VECTOR		24
#define		USB_VECTOR		25
#define		PWMA_VECTOR		26
#define		PWMB_VECTOR		27
#define		PWM1_VECTOR		28
#define		PWM2_VECTOR		29
#define		PWM3_VECTOR		30
#define		PWM4_VECTOR		31
#define		PWM5_VECTOR		32


#define	TRUE	1
#define	FALSE	0

//=============================================================

//========================================

#define	Priority_0			0	//中断优先级为 0 级（最低级）
#define	Priority_1			1	//中断优先级为 1 级（较低级）
#define	Priority_2			2	//中断优先级为 2 级（较高级）
#define	Priority_3			3	//中断优先级为 3 级（最高级）

//========================================

#define		ENABLE		1
#define		DISABLE		0

#endif
