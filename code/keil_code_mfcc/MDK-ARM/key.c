#include "key.h"


uint8_t KEY_Scan(uint8_t mode)
{	 
	static uint8_t key_up=1;//�������ɿ���־
	if(mode)key_up=1;  //֧������		  
	if(key_up&&(KEY0==1))
	{
		HAL_Delay(10);//ȥ���� 
		key_up=0;
		if(KEY0==1)return KEY0_PRES;
	}else if(KEY0==0)key_up=1;  
 	return 0;// �ް�������
}


