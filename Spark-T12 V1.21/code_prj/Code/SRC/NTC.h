#ifndef		__NTC_H
#define		__NTC_H

#include	"config.h"

float resistanceToTemperature(float _R1, float _B, float _R2, float _T2);
float NTC_outres(float Vcc,float VR,float R1);
void temp_protect(u8 ms_2,NTC__temp);
void bp(u8 t);
#endif
