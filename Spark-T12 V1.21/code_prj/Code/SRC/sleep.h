#ifndef		__SLEEP_H
#define		__SLEEP_H

#include	"config.h"

#define sleep P32

//void sleep_PWM_RST(void);  //关闭PWM发生器
//void sleep_PWM_SET(void);  //开启PWM发生器  
void sleep_show(void);     //休眠显示
void sleep_mode(void);     //休眠模式
bit SC7A20_signal(void);

#endif
