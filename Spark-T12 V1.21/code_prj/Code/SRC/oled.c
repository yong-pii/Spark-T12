#include	"IIC.h"
#include "oled.h"
#include "oledfont.h"


/*************************外部变量声明******************************/

extern bit IIC_communication_busy;
extern u16 xx, yy, zz;

/*******************************************************************/


//OLED的显存
//存放格式如下.
//[0]0 1 2 3 ... 127
//[1]0 1 2 3 ... 127
//[2]0 1 2 3 ... 127
//[3]0 1 2 3 ... 127
//[4]0 1 2 3 ... 127
//[5]0 1 2 3 ... 127
//[6]0 1 2 3 ... 127
//[7]0 1 2 3 ... 127




//反显函数
void OLED_ColorTurn(u8 i)
{
    if(i == 0)
    {
        OLED_WR_Byte(0xA6, OLED_CMD); //正常显示
    }
    if(i == 1)
    {
        OLED_WR_Byte(0xA7, OLED_CMD); //反色显示
    }
}

//屏幕旋转180度
void OLED_DisplayTurn(u8 i)
{
    if(i == 0)
    {
        OLED_WR_Byte(0xC8, OLED_CMD); //正常显示
        OLED_WR_Byte(0xA1, OLED_CMD);
    }
    if(i == 1)
    {
        OLED_WR_Byte(0xC0, OLED_CMD); //反转显示
        OLED_WR_Byte(0xA0, OLED_CMD);
    }
}

//发送一个字节
//向SSD1306写入一个字节。
//mode:数据/命令标志 0,表示命令;1,表示数据;
void OLED_WR_Byte(u8 dat, u8 mode)
{
    if(IIC_communication_busy == 0)
    {
        IIC_communication_busy = 1; //IIC总线挂起标志位（忙碌）

        Start();
        SendData(0x78);
        RecvACK();
        if(mode)
        {
            SendData(0x40);
        }
        else
        {
            SendData(0x00);
        }
        RecvACK();
        SendData(dat);
        RecvACK();
        Stop();

        IIC_communication_busy = 0; //IIC总线解放标志位（未使用）
    }
}

//坐标设置

void OLED_Set_Pos(u8 x, u8 y)
{
    OLED_WR_Byte(0xb0 + y, OLED_CMD);
    OLED_WR_Byte(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
    OLED_WR_Byte((x & 0x0f), OLED_CMD);
}
//开启OLED显示
//void OLED_Display_On(void)
//{
//	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
//	OLED_WR_Byte(0X14,OLED_CMD);  //DCDC ON
//	OLED_WR_Byte(0XAF,OLED_CMD);  //DISPLAY ON
//}
//关闭OLED显示
//void OLED_Display_Off(void)
//{
//	OLED_WR_Byte(0X8D,OLED_CMD);  //SET DCDC命令
//	OLED_WR_Byte(0X10,OLED_CMD);  //DCDC OFF
//	OLED_WR_Byte(0XAE,OLED_CMD);  //DISPLAY OFF
//}
//清屏函数,清完屏,整个屏幕是黑色的!和没点亮一样!!!
void OLED_Clear(void)
{
    u8 i, n;
    for(i = 0; i < 4; i++)
    {
        OLED_WR_Byte (0xb0 + i, OLED_CMD); //设置页地址（0~7）
        OLED_WR_Byte (0x00, OLED_CMD);     //设置显示位置—列低地址
        OLED_WR_Byte (0x10, OLED_CMD);     //设置显示位置—列高地址
        for(n = 0; n < 128; n++)OLED_WR_Byte(0, OLED_DATA);
    } //更新显示
}

//在指定位置显示一个字符,包括部分字符
//x:0~127
//y:0~63
//sizey:选择字体 6x8  8x16
void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 sizey)
{
    u8 c = 0, sizex = sizey / 2;
    u16 i = 0, size1;
    if(sizey == 8)size1 = 6;
    else size1 = (sizey / 8 + ((sizey % 8) ? 1 : 0)) * (sizey / 2);
    c = chr - ' '; //得到偏移后的值
    OLED_Set_Pos(x, y);
    for(i = 0; i < size1; i++)
    {
        if(i % sizex == 0 && sizey != 8) OLED_Set_Pos(x, y++);
        if(sizey == 8) OLED_WR_Byte(asc2_0806[c][i], OLED_DATA); //6X8字号
        else if(sizey == 16) OLED_WR_Byte(asc2_1608[c][i], OLED_DATA); //8x16字号
        else if(sizey == 22) OLED_WR_Byte(asc2_2010[c - 16][i], OLED_DATA); //用户添加字号
        else return;
    }
}
//m^n函数
u32 oled_pow(u8 m, u8 n)
{
    u32 result = 1;
    while(n--)result *= m;
    return result;
}
//显示数字
//x,y :起点坐标
//num:要显示的数字
//len :数字的位数
//sizey:字体大小
void OLED_ShowNum(u8 x, u8 y, u32 num, u8 len, u8 sizey)
{
    u8 t, temp, m = 0;
    u8 enshow = 0;
    if(sizey == 8)m = 2;
    for(t = 0; t < len; t++)
    {
        temp = (num / oled_pow(10, len - t - 1)) % 10;
        if(enshow == 0 && t < (len - 1))
        {
            if(temp == 0)
            {
                OLED_ShowChar(x + (sizey / 2 + m)*t, y, ' ', sizey);
                continue;
            }
            else enshow = 1;
        }
        OLED_ShowChar(x + (sizey / 2 + m)*t, y, temp + '0', sizey);
    }
}
//显示一个字符号串
void OLED_ShowString(u8 x, u8 y, u8 *chr, u8 sizey)
{
    u8 j = 0;
    while (chr[j] != '\0')
    {
        OLED_ShowChar(x, y, chr[j++], sizey);
        if(sizey == 8)x += 6;
        else x += sizey / 2;
    }
}
//显示汉字
void OLED_ShowChinese(u8 x, u8 y, u8 no, u8 sizey)
{
    u16 i, size1 = (sizey / 8 + ((sizey % 8) ? 1 : 0)) * sizey;
    for(i = 0; i < size1; i++)
    {
        if(i % sizey == 0) OLED_Set_Pos(x, y++);
        //		if(sizey==16) OLED_WR_Byte(Hzk[no][i],OLED_DATA);//16x16字号
        //else
        if(sizey == 12) OLED_WR_Byte(Hzk12[no][i], OLED_DATA); //用户添加字号
        else return;
    }
}


//显示图片
//x,y显示坐标
//sizex,sizey,图片长宽
//BMP：要显示的图片
void OLED_DrawBMP(u8 x, u8 y, u8 sizex, u8 sizey, u8 BMP[])
{
    u16 j = 0;
    u8 i, m;
    sizey = sizey / 8 + ((sizey % 8) ? 1 : 0);
    for(i = 0; i < sizey; i++)
    {
        OLED_Set_Pos(x, i + y);
        for(m = 0; m < sizex; m++)
        {
            OLED_WR_Byte(BMP[j++], OLED_DATA);
        }
    }
}



//OLED初始化
void OLED_Init(void)
{
    //	OLED_RES_Clr();
    //delay_ms(200);
    //	OLED_RES_Set();

    //打开显示
    OLED_WR_Byte(0xAE, OLED_CMD); /*display off*/
    //设置列地址
    OLED_WR_Byte(0x00, OLED_CMD); /*set lower column address*/
    OLED_WR_Byte(0x10, OLED_CMD); /*set higher column address*/

    OLED_WR_Byte(0x00, OLED_CMD); /*set display start line*/

    //设置页地址
    OLED_WR_Byte(0xB0, OLED_CMD); /*set page address*/

    //设置对比度【第二个最大对比度】
    OLED_WR_Byte(0x81, OLED_CMD); /*contract control*/
    OLED_WR_Byte(0xff, OLED_CMD); /*128*/

    OLED_WR_Byte(0xA1, OLED_CMD); /*set segment remap*/

    //设置为正常显示，1：显示，0：不显示
    OLED_WR_Byte(0xA6, OLED_CMD); /*normal / reverse*/

    //设置多路传输比率
    OLED_WR_Byte(0xA8, OLED_CMD); /*multiplex ratio*/
    OLED_WR_Byte(0x1F, OLED_CMD); /*duty = 1/32*/

    //上下方向显示，正常显示0xc8(0xc0上下反置)
    OLED_WR_Byte(0xC8, OLED_CMD); /*Com scan direction*/ //扫描方向

    //设置显示偏移，不偏移设置0
    OLED_WR_Byte(0xD3, OLED_CMD); /*set display offset*/
    OLED_WR_Byte(0x00, OLED_CMD);

    //设置时钟分频和RC振荡器频率
    OLED_WR_Byte(0xD5, OLED_CMD); /*set osc division*/
    OLED_WR_Byte(0x80, OLED_CMD);

    //设置预充电器件的持续时间
    OLED_WR_Byte(0xD9, OLED_CMD); /*set pre-charge period*/
    OLED_WR_Byte(0x1f, OLED_CMD);

    OLED_WR_Byte(0xDA, OLED_CMD); //设置列引脚的硬件配置
    OLED_WR_Byte(0x00, OLED_CMD);

    OLED_WR_Byte(0xdb, OLED_CMD); //调整Vcomif调节器的输出
    OLED_WR_Byte(0x40, OLED_CMD);

    OLED_WR_Byte(0x8d, OLED_CMD); //启用电荷泵（0x10禁用电荷泵）
    OLED_WR_Byte(0x14, OLED_CMD);
    //delay_ms(200);
    OLED_Clear();
    OLED_WR_Byte(0xAF, OLED_CMD); /*display ON*/
}

