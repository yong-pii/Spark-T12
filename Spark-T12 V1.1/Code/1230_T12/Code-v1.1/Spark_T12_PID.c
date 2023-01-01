#include "Spark_T12_PID.h"
#include <math.h>
/**
    Kp:比例参数    Ek:本次偏差值   Ek_1:上次偏差值   Ek_2:上上次偏差值
    Ti:积分时间    T:采样时间      Td:微分时间
**/
h16 Kp = 150, Ti = 5, T = 8, Td = 2, Ek;
static h16 Ek_1, Ek_2 ;
u16 present_temp, expect_temp = 300; //当前温度，期望温度


/***********************************************************
*@fuction	:PID
*@brief		:增量式PID
*@param		:E:当前值  K:期望值
*@return	:Output：要调整的占空比。
*@author	:--xptx
*@date		:2022-10-08
***********************************************************/

u16 PID(u16 E, u16 K)
{
    h16 Output;
    Ek = E - K;     //计算本次偏差，当前值-期望值
    Output = Kp * (Ek - Ek_1) + Kp * (T / Ti) * Ek + Kp * (Td / T) * (Ek - 2 * Ek_1 + Ek_2) ;  //计算本次PID
    Ek_2 = Ek_1;    //更新上上次偏差
    Ek_1 = Ek;      //更新上一次偏差
    Output = abs(Output); //
    //if(Output<0) Output=0;
    return Output;  //返回计算结果
}



//void data_send(u16 j)  //4位数据发送
//{
//    PrintString1("\r\n");
//    //    PrintString1("T12的ADC值为:\r\n");    //UART1发送一个字符串
//    //    //Get_ADCResult(i);		//参数0~15,查询方式做一次ADC, 丢弃一次
//    //    //j = 3300 / 1024 * j;
//    //    TX1_write2buff('A');
//    //    TX1_write2buff('D');
//    //    //TX1_write2buff(i+'0');
//    //    TX1_write2buff('=');
//    TX1_write2buff(j / 1000 + '0');
//    TX1_write2buff(j % 1000 / 100 + '0');
//    TX1_write2buff(j % 100 / 10 + '0');
//    TX1_write2buff(j % 10 + '0');
//    //    TX1_write2buff(' ');
//    //    TX1_write2buff(' ');

//    PrintString1("\n");
//}

/***********************************************************
*@fuction	:order_fitting
*@brief		:数据处理函数，对ADC输出的电压进行一次4阶多项式拟合，输出对应温度
*@param		:--Thermocouple voltage of T12
*@return	:temp
*@author	:--xptx
*@date		:2022-11-10
***********************************************************/

u16 order_fitting(u16 dat)
{
    u16 temp;  //定义一个变量
    temp = 2 * pow(10, -11) * pow(dat, 4) + 2 * pow(10, -8) * pow(dat, 3) - 0.0004 * pow(dat, 2) + 0.7985 * dat + 24.271 ;  //4阶多项式拟合
    return temp; //返回
}
/***********************************************************
*@fuction	:filter
*@brief		:滤波n次，去掉一个最大值，去掉一个最小值，余下的求平均值
*@param		:--u8 Num 滤波次数  Vcc_Adc 内部16通道的ADC值  u16 dat 被滤数据
*@return	:mean
*@author	:--xptx
*@date		:2022-11-11
***********************************************************/
u16 filter(u8 Num)
{ 
    u16 temp [20] ; //差值绝对值
    u16 max, mini, mean, sum = 0; //最大值 最小值 平均值
    u8 i;
	  u16 Vref; //MCU供电电压/基准电压（mV）
    for(i = 0; i < Num; i++)
    {
			  Vref=( 1190 / Get_ADCResult(15) ) * 1024 ;  //求出供电电源电压/基准电压
        temp [i] = ( Vref / 1024 ) * Get_ADCResult(0);
    }

    max  = temp[0];  //写入初值
    mini = temp[0];

    for(i = 0; i < Num; i++) //历遍数组求最大最小值
    {
        if(max < temp[i])
            max = temp[i];
        if(mini > temp[i])
            mini = temp[i];
    }
    for(i = 0; i < Num; i++)
    {
        sum += temp[i];
    }
    mean = (sum - max - mini) / (Num - 2);
    return 	mean;
}
//u16 filter(u8 Num,u16 Vcc_Adc, u16 dat)
//{ 
//    u16 temp [20] ; //差值绝对值
//    u16 max, mini, mean, sum = 0; //最大值 最小值 平均值
//    u8 i;
//	  u16 Vcc; //MCU供电电压（mV）
//    for(i = 0; i < Num; i++)
//    {
//			Vcc=1190/1024 * Vcc_Adc;  //求出供电电源电压 
//        temp [i] = ( Vcc / 1024 ) * dat;
//    }

//    max  = temp[0];  //写入初值
//    mini = temp[0];

//    for(i = 0; i < Num; i++) //历遍数组求最大最小值
//    {
//        if(max < temp[i])
//            max = temp[i];
//        if(mini > temp[i])
//            mini = temp[i];
//    }
//    for(i = 0; i < Num; i++)
//    {
//        sum += temp[i];
//    }
//    mean = (sum - max - mini) / (Num - 2);
//    return 	mean;
//}
