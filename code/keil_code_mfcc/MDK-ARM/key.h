#ifndef __KEY_H__
#define __KEY_H__

#include "main.h"

#define KEY0	HAL_GPIO_ReadPin(B1_GPIO_Port,B1_Pin)

 
uint8_t KEY_Scan(uint8_t mode);

#define KEY0_PRES 	1	//B0°´ÏÂ

#endif



