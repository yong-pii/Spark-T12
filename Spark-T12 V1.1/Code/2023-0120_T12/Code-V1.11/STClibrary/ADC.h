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

#ifndef	__ADC_H
#define	__ADC_H

#include	"config.h"

#define ADC_RES_12BIT	1		//0: MCU为10位ADC; 1: MCU为12位ADC


#define	ADC_P10		0x01	//IO引脚 Px.0
#define	ADC_P11		0x02	//IO引脚 Px.1
#define	ADC_P12		0x04	//IO引脚 Px.2
#define	ADC_P13		0x08	//IO引脚 Px.3
#define	ADC_P14		0x10	//IO引脚 Px.4
#define	ADC_P15		0x20	//IO引脚 Px.5
#define	ADC_P16		0x40	//IO引脚 Px.6
#define	ADC_P17		0x80	//IO引脚 Px.7
#define	ADC_P1_All	0xFF	//IO所有引脚

#define ADC_POWER	(1<<7)	//ADC 电源
#define ADC_START	(1<<6)	//ADC 转换启动控制位。自动清0
#define ADC_FLAG	(1<<5)	//ADC 转换结束标志位。软件清0
#define ADC_EPWMT	(1<<4)	//使能 PWM 同步触发 ADC 功能
#define ADC_CH0		0
#define ADC_CH1		1
#define ADC_CH2		2
#define ADC_CH3		3
#define ADC_CH4		4
#define ADC_CH5		5
#define ADC_CH6		6
#define ADC_CH7		7
#define ADC_CH8		8
#define ADC_CH9		9
#define ADC_CH10	10
#define ADC_CH11	11
#define ADC_CH12	12
#define ADC_CH13	13
#define ADC_CH14	14
#define ADC_CH15	15

#define ADC_SPEED_2X1T		0			//SYSclk/2/1
#define ADC_SPEED_2X2T		1			//SYSclk/2/2
#define ADC_SPEED_2X3T		2			//SYSclk/2/3
#define ADC_SPEED_2X4T		3			//SYSclk/2/4
#define ADC_SPEED_2X5T		4			//SYSclk/2/5
#define ADC_SPEED_2X6T		5			//SYSclk/2/6
#define ADC_SPEED_2X7T		6			//SYSclk/2/7
#define ADC_SPEED_2X8T		7			//SYSclk/2/8
#define ADC_SPEED_2X9T		8			//SYSclk/2/9
#define ADC_SPEED_2X10T		9			//SYSclk/2/10
#define ADC_SPEED_2X11T		10		//SYSclk/2/11
#define ADC_SPEED_2X12T		11		//SYSclk/2/12
#define ADC_SPEED_2X13T		12		//SYSclk/2/13
#define ADC_SPEED_2X14T		13		//SYSclk/2/14
#define ADC_SPEED_2X15T		14		//SYSclk/2/15
#define ADC_SPEED_2X16T		15		//SYSclk/2/16

#define ADC_LEFT_JUSTIFIED		0		//ADC Result left-justified
#define ADC_RIGHT_JUSTIFIED		1		//ADC Result right-justified


typedef struct
{
	u8	ADC_SMPduty;		//ADC 模拟信号采样时间控制, 0~31（注意： SMPDUTY 一定不能设置小于 10）
	u8	ADC_Speed;			//设置 ADC 工作时钟频率	ADC_SPEED_2X1T~ADC_SPEED_2X16T
	u8	ADC_Power;			//ADC功率允许/关闭	ENABLE,DISABLE
	u8	ADC_AdjResult;	//ADC结果调整,	ADC_LEFT_JUSTIFIED,ADC_RIGHT_JUSTIFIED
	u8	ADC_Priority;			//优先级设置	Priority_0,Priority_1,Priority_2,Priority_3
	u8	ADC_Interrupt;	//中断允许	ENABLE,DISABLE
	u8	ADC_CsSetup;		//ADC 通道选择时间控制 0(默认),1
	u8	ADC_CsHold;			//ADC 通道选择保持时间控制 0,1(默认),2,3
} ADC_InitTypeDef;

void	ADC_Inilize(ADC_InitTypeDef *ADCx);
void	ADC_PowerControl(u8 pwr);
u16		Get_ADCResult(u8 channel);	//channel = 0~15

#endif
