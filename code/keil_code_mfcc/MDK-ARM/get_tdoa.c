#include "get_tdoa.h"

#define Fs 16000
#define SCALE_rxy 1000000		//rxy 放大倍数 若不放大则会由于ifft得到的值太小,而float精度不够导致输出全0

void cplx_mag(float *input,float *output,uint32_t lenth,uint8_t output_option)//output_option==0  输出值为实数存储形式  output_option==1  输出值为复数存储形式 
{
	uint32_t i=0;
	
	if(output_option==0)
	{
			for(i=0;i<lenth;i++)
			{
					output[i] = sqrt(input[i*2]*input[i*2] + input[i*2+1]*input[i*2+1]);
			}
	}
	else if(output_option==1)
	{
			for(i=0;i<lenth;i++)
			{
					output[i*2] = sqrt(input[i*2]*input[i*2] + input[i*2+1]*input[i*2+1]);
					output[i*2+1] = 0;
			}
	}
}

void dot_prod(float *inputA,float *inputB,uint32_t lenth,float *real,float *imag)
{
	uint32_t i=0;
		for(i=0;i<lenth;i++)
		{
				real[i]=inputA[i*2]*inputB[i*2] - inputA[i*2+1]*inputB[i*2+1];
				imag[i]=inputA[i*2]*inputB[i*2+1] + inputA[i*2+1]*inputB[i*2];
		}
}
void dot_prod_A_dot_conjB(float *inputA,float *inputB,uint32_t lenth,float *real,float *imag)
{
	uint32_t i=0;
		for(i=0;i<lenth;i++)
		{
				real[i]=inputA[i*2]*inputB[i*2] + inputA[i*2+1]*inputB[i*2+1];
				imag[i]=-inputA[i*2]*inputB[i*2+1] + inputA[i*2+1]*inputB[i*2];
		}
}

void get_max_rxy(TDOA_Structure *TDOA_Str,float *max_val,uint32_t *max_idx)
{
		uint32_t i=0;
		float max_val_temp=0;
		for(i=0;i<FFT_LENTH;i++)
		{
				if(TDOA_Str->rxy[i*2]>max_val_temp)
				{
						max_val_temp = TDOA_Str->rxy[i*2];
						*max_idx = i;
				}				
		}
		*max_val = max_val_temp;
}


uint16_t F_ge_wave=500;

//21.333ms

uint16_t delay_point=10;
void generate_wave(TDOA_Structure *TDOA_Str,uint8_t printf_option)
{
		uint16_t i=0;
		for(i=0;i<FFT_LENTH;i++)
		{
			
			TDOA_Str->sound_data_x[i*2]=10*arm_sin_f32(2*PI*F_ge_wave/Fs*i);
			TDOA_Str->sound_data_x[i*2+1]=0;
			
			if(i<(FFT_LENTH-delay_point))
			{
				TDOA_Str->sound_data_y[(i+delay_point)*2]=arm_sin_f32(2*PI*F_ge_wave/Fs*(i));
				TDOA_Str->sound_data_y[(i+delay_point)*2+1]=0;
			}
			
		
		}
		for(i=0;i<FFT_LENTH;i++)
		{
			if(printf_option==1)
					USART_printf(&huart3,"%f,%f\r\n",TDOA_Str->sound_data_x[i*2],TDOA_Str->sound_data_y[i*2]);
		}
}

float32_t real_temp[FFT_LENTH]={0};//实部
float32_t imag_temp[FFT_LENTH]={0};//虚部

void cal_tdoa(TDOA_Structure *TDOA_Str,uint8_t printf_option)
{
		uint16_t i=0;
		uint32_t max_idx_rxy=0;
		float32_t max_val_rxy=0;		
		arm_cfft_instance_f32 * S;
		
		arm_cfft_init_f32(S,FFT_LENTH);
		arm_cfft_f32(S,TDOA_Str->sound_data_x,0,1);//由于输入是顺序的,经过蝶形运算得到输出为错位的数,使能位翻转功能可将输出改为顺序					
		arm_cfft_f32(S,TDOA_Str->sound_data_y,0,1);//输出没有利用对称性砍掉一半
			
		dot_prod_A_dot_conjB(TDOA_Str->sound_data_x,TDOA_Str->sound_data_y,FFT_LENTH,real_temp,imag_temp);	//X(w) * conj(Y(w))  (a+bi)(c+di)=(ac-bd)+(ad+bc)i
				
		for(i=0;i<FFT_LENTH;i++)
		{
				TDOA_Str->rxy[i*2]=SCALE_rxy * real_temp[i] / sqrt(real_temp[i]*real_temp[i] + imag_temp[i]*imag_temp[i]);
				TDOA_Str->rxy[i*2+1]=SCALE_rxy * imag_temp[i] / sqrt(real_temp[i]*real_temp[i] + imag_temp[i]*imag_temp[i]);
		}//rxy = 1/phi * Rxy
			
		arm_cfft_f32(S,TDOA_Str->rxy,1,1);//ifft		
		
		get_max_rxy(TDOA_Str,&max_val_rxy,&max_idx_rxy);//反傅里叶变换数组构成也是  实部 虚部 实部 虚部...

		if(max_idx_rxy>FFT_LENTH/2)	
			TDOA_Str->t_differ=(float)(FFT_LENTH - max_idx_rxy - 1)/(float)Fs;//s
		else 
			TDOA_Str->t_differ= - (float)max_idx_rxy/(float)Fs;//s
		
		if(printf_option==1)
		{
//			if(TDOA_Str->t_differ*34>50 || TDOA_Str->t_differ*34<-50)return;		
			USART_printf(&huart3,"t_differ=%fms,dis=%fcm\r\n",TDOA_Str->t_differ*1000,TDOA_Str->t_differ*34000);
		}
			
}


//#define SOUND_SPEED 340.0f					//m/s
//#define SOUND_SPEED_2 (SOUND_SPEED*SOUND_SPEED)	//SOUND_SPEED * SOUND_SPEED
//#define D_MIC 0.5f								//m
//#define D_MIC_2 (D_MIC*D_MIC)						//D_MIC * D_MIC

//void cal_positon(TDOA_Structure *TDOA_Str12 , TDOA_Structure *TDOA_Str13 , Sound_Pos_Structure *Sound_Pos_Str , uint8_t printf_option)
//{
//		double t12;
//		double t13;
//		
//		
//	
//		t12 = TDOA_Str12->t_differ;
//		t13 = TDOA_Str13->t_differ;
//		
//		Sound_Pos_Str->r =

//			( -2*SOUND_SPEED_2 * pow(t12,2)  +  2*SOUND_SPEED_2*t12*t13  -  SOUND_SPEED_2*pow(t13,2)  +  2*D_MIC_2 )
//			/
//			( 4*SOUND_SPEED*t12 - 2*SOUND_SPEED*t13 );
//			
//		Sound_Pos_Str->the = asin((pow((1 - (SOUND_SPEED_2*pow((- SOUND_SPEED_2*pow(t12,2)*t13 + SOUND_SPEED_2*t12*pow(t13,2) + 4*D_MIC_2*t12 - 3*D_MIC_2*t13),2))/(D_MIC_2*pow((2*SOUND_SPEED_2*pow(t12,2) - 4*SOUND_SPEED_2*t12*t13 + SOUND_SPEED_2*pow(t13,2) + 2*D_MIC_2),2))),0.5)*(2*SOUND_SPEED_2*pow(t12,2) - 4*SOUND_SPEED_2*t12*t13 + SOUND_SPEED_2*pow(t13,2) + 2*D_MIC_2))/(- 2*SOUND_SPEED_2*pow(t12,2) + 2*SOUND_SPEED_2*t12*t13 - SOUND_SPEED_2*pow(t13,2) + 2*D_MIC_2));
//		
//		if(printf_option == 1)
//		{
//				if(TDOA_Str13->t_differ>0)
//				{
//						USART_printf(&huart3,"右:\t");
//				}
//				else
//				{
//		//				TDOA_Str12->t_differ = -TDOA_Str12->t_differ;
//		//				TDOA_Str13->t_differ = -TDOA_Str13->t_differ;
//						USART_printf(&huart3,"左:\t");
//				}
//				USART_printf(&huart3,"r = %lfcm\t the = %lf°\r\n",Sound_Pos_Str->r*100 , Sound_Pos_Str->the * 180 / PI);
//		}
//}



