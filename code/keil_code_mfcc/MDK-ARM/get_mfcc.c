#include "get_mfcc.h"
#include "key.h"

	
void Init_my_mfcc(arm_mfcc_instance_f32 *S)
{
		uint8_t res = 0;
		res = arm_mfcc_init_f32(S,
														FFT_LENGTH,
														N_MEL_FILTER,
														MFCC_OUT,
														mfcc_dct_coefs_config1_f32,
														mfcc_filter_pos_config1_f32,
														mfcc_filter_len_config1_f32,
														mfcc_filter_coefs_config1_f32,
														mfcc_window_coefs_config1_f32);
														
		if(res==ARM_MATH_SUCCESS)
			printf("MFCC_Init_OK\r\n");
		else
			printf("MFCC_Init_ERROR!!!\r\n");
		
}



//32*48
void cal_mfcc(arm_mfcc_instance_f32 *S , float32_t *audio_input , float32_t *mfcc_output)
{
		float32_t fft_temp[FFT_LENGTH+2]={0};
		float32_t mfcc_input_temp[512]={0};
		float32_t mfcc_output_temp[32]={0};
		uint32_t i,j;
		for(i=0;i<48;i++)
		{
				for(j=0;j<FFT_LENGTH;j++)
				{
						if(j<400)
							mfcc_input_temp[j]=audio_input[i*160+j];
						else
							mfcc_input_temp[j]=0;
//						printf("i=%u,j=%u,input:%f\r\n",i,j,mfcc_input_temp[j]);
				}
				
				arm_mfcc_f32(S,mfcc_input_temp,mfcc_output_temp,fft_temp);
				for(j=0;j<32;j++)
				{
						mfcc_output[j*48+i]=mfcc_output_temp[j];
//						printf("%f\r\n",mfcc_output_temp[j]);
				}
//				while(!KEY_Scan(0));
		}
		
//		for(i=0;i<1536;i++)
//		{
//			printf("%f\r\n",mfcc_output[i]);
//		}

}


