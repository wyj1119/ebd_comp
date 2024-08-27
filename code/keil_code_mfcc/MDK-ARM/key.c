#include "key.h"


uint8_t KEY_Scan(uint8_t mode)
{	 
	static uint8_t key_up=1;//按键按松开标志
	if(mode)key_up=1;  //支持连按		  
	if(key_up&&(KEY0==1))
	{
		HAL_Delay(10);//去抖动 
		key_up=0;
		if(KEY0==1)return KEY0_PRES;
	}else if(KEY0==0)key_up=1;  
 	return 0;// 无按键按下
}


