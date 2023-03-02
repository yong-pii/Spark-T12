#include "SC7A20TR.h"
#include "IIC.h"
#include "stdio.h"	//使用printf打印数据到串口

/*************************外部变量声明******************************/

extern bit IIC_communication_busy;
extern u16 xx, yy, zz;

/*******************************************************************/


/*
SC7A20向寄存器写一个字节
RAddr：寄存器地址
WData：数据
*/
void SC7A20_Write_Byte(u8 RAddr, u8 WData)
{
    if(IIC_communication_busy == 0)
    {
        IIC_communication_busy = 1; //IIC总线挂起标志位（忙碌）

        Start();
        SendData(SC7A20_I2C_WADDR);
        RecvACK();
        SendData(RAddr);
        RecvACK();
        SendData(WData);
        RecvACK();
        Stop();

        IIC_communication_busy = 0; //IIC总线解放标志位（未使用）
    }
}

/*
SC7A20从寄存器读一个字节
RAddr：寄存器地址
RData：接收数据地址
*/
void SC7A20_Read_Byte(u8 RAddr, u8 *RData)
{
    if(IIC_communication_busy == 0)
    {
        IIC_communication_busy = 1; //IIC总线挂起标志位（忙碌）

        Start();
        SendData(SC7A20_I2C_WADDR);
        RecvACK();
        SendData(RAddr);
        RecvACK();
        Start();
        SendData(SC7A20_I2C_RADDR);
        RecvACK();
        *RData = RecvData(0);
        Stop();

        IIC_communication_busy = 0; //IIC总线解放标志位（未使用）
    }
}

/*
SC7A20初始化
*/
void SC7A20_Init(void)
{
    SC7A20_Write_Byte(0x20, 0x77); //400Hz+正常模式xyz使能
    SC7A20_Write_Byte(0x21, 0x88); //高通滤波：正常模式,00+滤波使能
    SC7A20_Write_Byte(0x23, 0x88); //读取完成再更新、2g+正常模式
}

/*
SC7A20获取加速度值
accd_lsb：加速度值低寄存器地址
accd_msb：加速度值高寄存器地址
返回值accd_f：加速度值，单位mg
*/
int SC7A20_Get_ACCD(u8 accd_lsb, u8 accd_msb)
{
    u8 accd_l, accd_m = 0;
    unsigned int temp;
    int accd;

    SC7A20_Read_Byte(accd_lsb, &accd_l);
    SC7A20_Read_Byte(accd_msb, &accd_m);
    temp &= 0x0000;
    temp |= accd_m;
    temp <<= 8;
    temp &= 0xff00;
    temp |= accd_l;
    if(temp & 0x8000)
    {
        temp >>= 4;
        temp |= 0xf000;
    }
    else
    {
        temp >>= 4;
        temp &= 0x0fff;
    }
    accd = temp * 1;
    return accd;
}

/*
SC7A20获取xyz轴加速度值
*/
void SC7A20_GetInfo(void)
{
    //获取三轴数据
    int x = 0, y = 0, z = 0;
    unsigned char i = 16;

    x = SC7A20_Get_ACCD(0x28, 0x29);
    y = SC7A20_Get_ACCD(0x2A, 0x2B);
    z = SC7A20_Get_ACCD(0x2C, 0x2D);

    xx = (u16)abs(x);
    yy = (u16)abs(y);
    zz = (u16)abs(z);



    //printf("x:%hd mg, y:%hd mg, z:%hd mg \r\n",x,y,z);
}
