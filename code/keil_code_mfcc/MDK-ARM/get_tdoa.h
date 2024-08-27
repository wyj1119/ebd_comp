#ifndef __GET_TDOA_H__
#define __GET_TDOA_H__

#include "main.h"
#include "usart.h"

//�ٶ�FcΪ10kHz Ƶ�ʷֱ���FΪ10Hz 
#define 	FFT_LENTH 	2048

typedef struct
{
		float sound_data_x[FFT_LENTH*2];
		float sound_data_y[FFT_LENTH*2];//����TDOA����·�ź�		 �洢Ϊ������ʽ   
		//����fftʱ����������ø�����
		float rxy[FFT_LENTH*2];//ifft���
		float t_differ;//ʱ��
}TDOA_Structure;

typedef struct
{
		double r;
		double the;
}Sound_Pos_Structure;

void cal_tdoa(TDOA_Structure *TDOA_Str,uint8_t printf_option);
void generate_wave(TDOA_Structure *TDOA_Str,uint8_t printf_option);
//void cal_positon(TDOA_Structure *TDOA_Str12 , TDOA_Structure *TDOA_Str13 , Sound_Pos_Structure *Sound_Pos_Str , uint8_t printf_option);
#endif
