#ifndef		__SPARK_T12_PID_H
#define		__SPARK_T12_PID_H

#include	"config.h"

//void data_send(u16 j);                //16位数据发送
u16 order_fitting(u16 dat);           //热电偶电压数据处理函数
//u16 filter(u8 Num,u16 Vcc_Adc, u16 dat);  //滤波函数
u16 filter(u8 Num);
u16 PID(u16 E, u16 K);
#endif

