/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "crc.h"
#include "dma.h"
#include "i2s.h"
#include "tim.h"
#include "usart.h"
#include "usb_otg.h"
#include "gpio.h"
#include "app_x-cube-ai.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "key.h"
#include "get_mfcc.h"
#include "get_tdoa.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define AUDIO_LENGTH 7920
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
arm_mfcc_instance_f32  S;

uint32_t audio_data_ori[AUDIO_LENGTH*4]={0};//麦克风0原始数据
uint32_t audio_data_ori_1[AUDIO_LENGTH*4]={0};//麦克风1原始数据
//8080*2双buffer  *2接收时双声道 只有右声道有效

float32_t *audio_data=NULL;//麦克风0转换后的音频数据
float32_t *audio_data_1=NULL;//麦克风1转换后的音频数据

mel_union   mel_data;//32*48 麦克风 mfcc输出结果

uint8_t flag[3]={0};//0--无数据  1--前半  2--后半

//计算时延
TDOA_Structure TDOA_M12_Str={0};
__IO uint8_t flag_beep=0;//0--响 1--关

void Init_beep(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = GPIO_PIN_8;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);
	HAL_GPIO_WritePin(GPIOC,GPIO_PIN_8,GPIO_PIN_RESET);
}

float trans_24_cmpl_src(uint32_t input)
{
		int32_t output=0;
		
		input &= 0x00ffffff;
		
		if((input&0x800000UL)==0x800000UL)
		{
				//负数
				output =-((input^0x00ffffff) + 1);	//加法运算优先级大于异或
		}
		else 
		{
				//正数
				output = input;
		}
		
		return (float)output;
}
//麦克风0处理函数
void trans_audio_ori_to_float(uint8_t flag_dma)
{
		uint32_t i=0;
		uint32_t *p=NULL;
		
		if(flag_dma==1)
			p=audio_data_ori;
		else
			p=audio_data_ori+AUDIO_LENGTH*2;
			
		audio_data=(float32_t*)p;
		
		for(i=0;i<AUDIO_LENGTH;i++)
		{
				audio_data[i]=trans_24_cmpl_src(p[i*2+1]) ;
//				printf("%f\r\n",audio_data[i]);
		}
		
		for(i=0;i<FFT_LENTH;i++)
		{
				TDOA_M12_Str.sound_data_x[i*2] = audio_data[i];
				TDOA_M12_Str.sound_data_x[i*2+1] = 0;				
		}
}
//麦克风1处理函数
void trans_audio_ori_1_to_float(uint8_t flag_dma)
{
		uint32_t i=0;
		uint32_t *p=NULL;
		
		if(flag_dma==1)
			p=audio_data_ori_1;
		else
			p=audio_data_ori_1+AUDIO_LENGTH*2;
			
		audio_data_1=(float32_t*)p;
		
		for(i=0;i<AUDIO_LENGTH;i++)
		{
				audio_data_1[i]=trans_24_cmpl_src(p[i*2+1]);
//				printf("%f\r\n",audio_data[i]);
		}
		
		for(i=0;i<FFT_LENTH;i++)
		{
				TDOA_M12_Str.sound_data_y[i*2] = audio_data_1[i];
				TDOA_M12_Str.sound_data_y[i*2+1] = 0;
		}
}

//void generate_audio(uint8_t printf_option)
//{
//		for(uint32_t i=0;i<AUDIO_LENGTH;i++)
//		{
//			audio_data[i]=1;
//			if(printf_option)
//				printf("%u:%f\r\n",i,audio_data[i]);
//		}
//			
//		
//}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* Enable I-Cache---------------------------------------------------------*/
  SCB_EnableICache();

  /* Enable D-Cache---------------------------------------------------------*/
  SCB_EnableDCache();

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_USB_OTG_HS_USB_Init();
  MX_I2S1_Init();
  MX_USART1_UART_Init();
  MX_USART2_UART_Init();
  MX_USART3_UART_Init();
  MX_I2S2_Init();
  MX_I2S3_Init();
  MX_CRC_Init();
  MX_TIM3_Init();
  MX_TIM4_Init();
  MX_X_CUBE_AI_Init();
  /* USER CODE BEGIN 2 */
	Init_beep();
	Init_my_mfcc(&S);
	
	HAL_TIM_Base_Start_IT(&htim3);
	
	HAL_I2S_Receive_DMA(&hi2s1,(uint16_t*)audio_data_ori,AUDIO_LENGTH*4);
	HAL_I2S_Receive_DMA(&hi2s2,(uint16_t*)audio_data_ori_1,AUDIO_LENGTH*4);
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
		if(flag[0]!=0&&flag[1]!=0)
		{
				trans_audio_ori_to_float(flag[0]);
				cal_mfcc(&S,audio_data,mel_data.data_f);
				MX_X_CUBE_AI_Process();
				
				trans_audio_ori_1_to_float(flag[1]);
				cal_mfcc(&S,audio_data_1,mel_data.data_f);
				MX_X_CUBE_AI_Process();							
				
				//cal_position and trans to bluetooth		
				cal_tdoa(&TDOA_M12_Str,1);
				//cal_position and trans to bluetooth		
				
				flag[0]=0;
				flag[1]=0;
				HAL_GPIO_TogglePin(LED_GREEN_GPIO_Port,LED_GREEN_Pin);
							
		}
	
    /* USER CODE END WHILE */


    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Supply configuration update enable
  */
  HAL_PWREx_ConfigSupply(PWR_LDO_SUPPLY);

  /** Configure the main internal regulator output voltage
  */
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE0);

  while(!__HAL_PWR_GET_FLAG(PWR_FLAG_VOSRDY)) {}

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI48|RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSI48State = RCC_HSI48_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLM = 4;
  RCC_OscInitStruct.PLL.PLLN = 275;
  RCC_OscInitStruct.PLL.PLLP = 1;
  RCC_OscInitStruct.PLL.PLLQ = 4;
  RCC_OscInitStruct.PLL.PLLR = 2;
  RCC_OscInitStruct.PLL.PLLRGE = RCC_PLL1VCIRANGE_1;
  RCC_OscInitStruct.PLL.PLLVCOSEL = RCC_PLL1VCOWIDE;
  RCC_OscInitStruct.PLL.PLLFRACN = 0;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2
                              |RCC_CLOCKTYPE_D3PCLK1|RCC_CLOCKTYPE_D1PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.SYSCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB3CLKDivider = RCC_APB3_DIV2;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_APB1_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_APB2_DIV2;
  RCC_ClkInitStruct.APB4CLKDivider = RCC_APB4_DIV2;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_3) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */
#include <stdio.h>
int fputc(int ch, FILE *f)
{
  HAL_UART_Transmit(&huart3, (uint8_t *)&ch, 1, 0xffff);
  return ch;
}

uint8_t flag_start_cal_tdoa=0;
uint8_t cnt_start_cal_tdoa[3]={0};//前5次会读出噪声,舍去前5次数据
void HAL_I2S_RxHalfCpltCallback(I2S_HandleTypeDef *hi2s)
{
		if(flag_start_cal_tdoa==0)
			USART_printf(&huart3,"in:1");
			
		if(hi2s==&hi2s1)
		{
				if(flag_start_cal_tdoa==1)
				{
					if(flag[0]==0)
						flag[0]=1;
					else
						USART_printf(&huart3,"hi2s1_buzy:1");
				}
		}
		if(hi2s==&hi2s2)
		{
				if(flag_start_cal_tdoa==1)
				{
					if(flag[1]==0)
						flag[1]=1;
					else
						USART_printf(&huart3,"hi2s2_buzy:1");
				}
		}
		
}

void HAL_I2S_RxCpltCallback(I2S_HandleTypeDef *hi2s)
{
		if(flag_start_cal_tdoa==0)
			USART_printf(&huart3,"in:2\r\n");
		if(hi2s==&hi2s1)
		{
				if(flag_start_cal_tdoa==1)
				{
					if(flag[0]==0)
						flag[0]=2;
					else
						USART_printf(&huart3,"hi2s1_buzy:2");
				}
				else 
				{
					cnt_start_cal_tdoa[0]++;
				}
		}
		
		if(hi2s==&hi2s2)
		{
				if(flag_start_cal_tdoa==1)
				{
					if(flag[1]==0)
						flag[1]=2;
					else
						USART_printf(&huart3,"hi2s2_buzy:2");
				}
				else 
				{
					cnt_start_cal_tdoa[1]++;
				}
		}
		
		if(cnt_start_cal_tdoa[0]>5&&cnt_start_cal_tdoa[1]>5)
		{
				flag_start_cal_tdoa=1;
		}
}

void HAL_I2S_ErrorCallback(I2S_HandleTypeDef *hi2s)
{
		USART_printf(&huart3,"ERROR%d\r\n",hi2s->ErrorCode);
}

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	static uint8_t cnt_beep=0;
	
		if(htim==&htim3)
		{
			if(flag_beep==1)
			{
					if(++cnt_beep>=10)
					{
						flag_beep=2;
						cnt_beep=0;
						BEEP_CLOSE;						
					}
					else
					{
						BEEP_Toggle;
					}
			}
				
		}
			
}
/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
