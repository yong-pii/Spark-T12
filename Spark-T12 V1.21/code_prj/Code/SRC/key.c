#include "key.h"

/****按键控制函数****/


u8 key_mode(void)
{
    u16 i = 0; //临时变量
    if(!k2)
    {

        Beep(ON);
        while(!k2) //检测到按键按下，进入循环
        {
            delay_ms(1);
            i++;  //开始计时
        }
        Beep(OFF);
    }
    if(i > 10 && i < 500) return 1; //检测到短按
    else if(i > 500)      return 2;	 //检测到长按
    else return 0;
}


u8 key_add(void)
{
    u16 i = 0; //临时变量
    static u8 r;
    if(!k3)
    {
        Beep(ON);
        while(!k3) //检测到按键按下，进入循环
        {
            delay_ms(1);
            i++;  //开始计时
            //if(i>1500) break;
        }
        Beep(OFF);
    }
    if(i > 10 && i < 500) r = 1; //检测到短按
    else if(i > 500)      r = 2;	 //检测到长按
    else r = 0;
    //		if(i>0) data_send(r);  //4位数据发送
    return r;
}

u8 key_lessen(void)
{
    u16 i = 0; //临时变量
    u8 r;
    if(!k1)
    {
        Beep(ON);
        while(!k1) //检测到按键按下，进入循环
        {
            delay_ms(1);
            i++;  //开始计时
            //if(i>1500) break;
        }
        Beep(OFF);
    }
    if(i > 10 && i < 500) r = 1; //检测到短按
    else if(i > 500)      r = 2;	 //检测到长按
    else r = 0;
    //if(i>0) data_send(r);  //4位数据发送
    return r;
}