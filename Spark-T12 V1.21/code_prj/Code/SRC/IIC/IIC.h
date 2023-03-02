#ifndef	__I2C_H
#define	__I2C_H

#include	"config.h"

//sbit I2C_SCL=P3^2;//SCL
//sbit I2C_SDA=P3^3;//SDA
#define  I2C_SCL P13
#define  I2C_SDA P14


#define I2C_SCL_Clr() I2C_SCL=0
#define I2C_SCL_Set() I2C_SCL=1

#define I2C_SDA_Clr() I2C_SDA=0
#define I2C_SDA_Set() I2C_SDA=1

//void Wait();
void Start();
void SendData(char dat);
void RecvACK();
char RecvData(u8 SF_Ack);
void SendACK();
void SendNAK();
void Stop();

#endif
