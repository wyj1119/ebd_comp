#ifndef __GET_MFCC_H__
#define __GET_MFCC_H__

#include "main.h"
#include "mfccdata.h"
#include "usart.h"

#define FFT_LENGTH 512
#define N_MEL_FILTER 64
#define MFCC_OUT 32
typedef union 
{
 float data_f[1536];
 int8_t data_u[6144];
}mel_union;
void Init_my_mfcc(arm_mfcc_instance_f32 *S);
void cal_mfcc(arm_mfcc_instance_f32 *S , float32_t *audio_input , float32_t *mfcc_output);
#endif
