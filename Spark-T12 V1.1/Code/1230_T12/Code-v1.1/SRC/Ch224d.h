#ifndef		__Ch224d_H
#define		__Ch224d_H

#include	"config.h"

#define CFG1 P33
#define CFG2 P34
#define CFG3 P35
void power_Init(void);  //type-C(QC or PD) Supply voltage Init 
void power(u8 x);  //type-C(QC or PD) Supply voltage selection 
u8 v_data_out(void);
void power_record(void);
#endif