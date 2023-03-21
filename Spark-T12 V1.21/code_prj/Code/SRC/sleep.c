#include "sleep.h"

bit sleep_fig = 0;
u16 sleep_time_s = 0, set_sleep_time = 5; //���߼�ʱ����������ʱ��


extern u8 z;
extern u16 xx, yy, zz;

/***********************************************************
*@fuction	:sleep_show
*@brief		:
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/

void sleep_show(void)
{
    static u16 i;
    i += 10;
    if(SC7A20_signal() == 1) sleep_time_s = 0; //�����Ǽ�⵽����˵�������������������߼�ʱ����

    if((i % 1000) == 0)
    {
        OLED_Clear();//����
        OLED_ShowChinese( i / 100 + 0, 1, 6, 12); //��
        OLED_ShowChinese(i / 100 + 14, 1, 7, 12); //��
        OLED_ShowChinese(i / 100 + 28, 1, 12, 12); //��
    }
    delay_ms(10);

    if(i >= 12001) i = 0;
}

bit SC7A20_signal(void)
{
    if(xx > 80 && yy > 80 && zz > 80)
    {
        Beep(ON);
        delay_ms(50);
        Beep(OFF);
        return 1;
    }
    else return 0;


}

/***********************************************************
*@fuction	:sleep_mode
*@brief		:����ģʽ
*@param		:--
*@return	:void
*@author	:--xptx
*@date		:2022-10-24
***********************************************************/

void sleep_mode(void)
{
    OLED_Clear();//����
    delay_ms(10);
    sleep_fig = 1; //���߱�־λ��һ
    P12 = 0; //����pwm���IO��
    while(1)
    {
        sleep_show();  //������ʾ����
        if(SC7A20_signal() == 1)
        {
            sleep_time_s = 0; //�����Ǽ�⵽����˵�������������������߼�ʱ����
            z = 0; //���ؽ���1
            interface_show1_Init();  //��ʼ������1
            break;
        }
    }
    sleep_fig = 0; //���߽�������־λ��0
}

void sleep_forced(int sleep) {
    if (1 == sleep) {
        OLED_Clear();//����
        delay_ms(10);
        sleep_fig = 1; //���߱�־λ��һ
        P12 = 0; //����pwm���IO��
        sleep_show();  //������ʾ����
    } else {
        sleep_fig = 0; //���߽�������־λ��0
    }
}