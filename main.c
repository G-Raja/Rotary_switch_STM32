/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under BSD 3-Clause license,
  * the "License"; You may not use this file except in compliance with the
  * License. You may obtain a copy of the License at:
  *                        opensource.org/licenses/BSD-3-Clause
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "tim.h"
#include "usart.h"
#include "gpio.h"
#include "stdio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
TIM_HandleTypeDef htim2;
UART_HandleTypeDef huart1;

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
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

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */
	uint8_t MSG[50] = {'\0'};
	uint8_t bitStatus = 0,bitStatus1 = 0,bitStatus2 = 0,bitStatus3 = 0;
	uint8_t Bit_status = 0;

  /* USER CODE END 1 */

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
  MX_TIM2_Init();
  MX_USART1_UART_Init();
  HAL_TIM_Encoder_Start(&htim2, TIM_CHANNEL_ALL);
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  while (1)
  {
	  bitStatus = HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0);
	/*if(bitStatus)
	{
		//sprintf(MSG, "A0 pin status = %d\n\r", bitStatus);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);

		//HAL_Delay(1000);
		//bitStatus = 0;
		//sprintf(MSG, "A0 pin status = %d\n\r", bitStatus);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	}*/
	bitStatus1 = HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1);
	/*if(bitStatus1)
	{
		//sprintf(MSG, "A1 pin status = %d\n\r", bitStatus1);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);

		//HAL_Delay(1000);
		//bitStatus1 = 0;
		//sprintf(MSG, "A1 pin status = %d\n\r", bitStatus1);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	}*/
	bitStatus2 = HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2);
	/*if(bitStatus2)
	{
		//sprintf(MSG, "A2 pin status = %d\n\r", bitStatus2);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
		//HAL_Delay(1000);

		//bitStatus2 = 0;
		//sprintf(MSG, "A2 pin status = %d\n\r", bitStatus2);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	}*/
	bitStatus3 = HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3);
	/*if(bitStatus3)
	{
		//sprintf(MSG, "A3 pin status = %d\n\r", bitStatus3);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
		//HAL_Delay(1000);


		//bitStatus3 = 0;
		//sprintf(MSG, "A3 pin status = %d\n\r", bitStatus3);
		//HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	}*/
	Bit_status=((bitStatus<<3)|(bitStatus1<<2)|(bitStatus2<<1)|( bitStatus3 ));
	sprintf(MSG, "Bit_status = %d\n\r", Bit_status);
	HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	Bit_status = 0;

	HAL_Delay(3000);


    /* USER CODE END WHILE
	  if(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_0))
	         {
	             sprintf(MSG, "Encoder0 Switch Released, Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
	             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	         }
	         else
	         {
	             sprintf(MSG, "Encoder0 Switch Pressed,  Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
	             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	         }
	  if(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_1))
	 	         {
	 	             sprintf(MSG, "Encoder1 Switch Released, Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
	 	             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	 	         }
	 	         else
	 	         {
	 	             sprintf(MSG, "Encoder1 Switch Pressed,  Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
	 	             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	 	         }
	  if(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_2 ))
		         {
		             sprintf(MSG, "Encoder2 Switch Released, Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
		             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
		         }
		         else
		         {
		             sprintf(MSG, "Encoder2 Switch Pressed,  Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
		             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
		         }
	  if(HAL_GPIO_ReadPin (GPIOA, GPIO_PIN_3))
	 	         {
	 	             sprintf(MSG, "Encoder3 Switch Released, Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
	 	             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	 	         }
	 	         else
	 	         {
	 	             sprintf(MSG, "Encoder3 Switch Pressed,  Encoder Ticks = %d\n\r", ((TIM2->CNT)>>2));
	 	             HAL_UART_Transmit(&huart1, MSG, sizeof(MSG), 100);
	 	         }

	         HAL_Delay(100);*/

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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  HAL_RCC_MCOConfig(RCC_MCO, RCC_MCO1SOURCE_PLLCLK, RCC_MCODIV_1);
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */

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
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

