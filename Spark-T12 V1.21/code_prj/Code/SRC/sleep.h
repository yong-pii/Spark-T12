#ifndef		__SLEEP_H
#define		__SLEEP_H

#include	"config.h"

#define sleep P32

//void sleep_PWM_RST(void);  //�ر�PWM������
//void sleep_PWM_SET(void);  //����PWM������  
void sleep_show(void);     //������ʾ
void sleep_mode(void);     //����ģʽ
bit SC7A20_signal(void);    //�����Ǽ��
void sleep_forced(void);    //ǿ������

#endif
