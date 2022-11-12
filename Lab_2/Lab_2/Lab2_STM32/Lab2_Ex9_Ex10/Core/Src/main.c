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

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

#include"software_timer.h"

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
TIM_HandleTypeDef htim2;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
/* USER CODE BEGIN PFP */

const int MAX_LED = 4;

void display7SEG(int num,
		GPIO_TypeDef* a_seg_GPIO_Port, uint16_t a_seg_Pin,
		GPIO_TypeDef* b_seg_GPIO_Port, uint16_t b_seg_Pin,
		GPIO_TypeDef* c_seg_GPIO_Port, uint16_t c_seg_Pin,
		GPIO_TypeDef* d_seg_GPIO_Port, uint16_t d_seg_Pin,
		GPIO_TypeDef* e_seg_GPIO_Port, uint16_t e_seg_Pin,
		GPIO_TypeDef* f_seg_GPIO_Port, uint16_t f_seg_Pin,
		GPIO_TypeDef* g_seg_GPIO_Port, uint16_t g_seg_Pin);

void update7SEG(int num);

int led_buffer [4] = {1 , 2 , 3 , 4};
void updateClockBuffer(int hour,  int minute);

uint8_t matrix_buffer[8] = {0x01 , 0x02 , 0x03 , 0x04 , 0x05 , 0x06 , 0x07 , 0x08 };
const int MAX_LED_MATRIX = 8;

void updateLEDMatrix (int index);

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
  /* USER CODE BEGIN 2 */

  HAL_TIM_Base_Start_IT(&htim2);

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  Set_timer(100, 0);
  Set_timer(50, 1);
  Set_timer(100, 2);
  int hour = 22 , minute = 59 , second = 50;
  int index_led = 0;
  int index_led_matrix = 0;
  int first_time = 1;
  while (1)
  {
	  if(first_time == 1)
	  {
			HAL_GPIO_WritePin(seg_a_GPIO_Port, seg_a_Pin, RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_Port, seg_b_Pin, RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_Port, seg_c_Pin, RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_Port, seg_d_Pin, RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_Port, seg_e_Pin, RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_Port, seg_f_Pin, RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_Port, seg_g_Pin, RESET);


			first_time = 0;
	  }

	  if(timer_flag[0] == 1)
	  {
		  Set_timer(100, 0);
		  HAL_GPIO_TogglePin(led_red_GPIO_Port, led_red_Pin);
		  HAL_GPIO_TogglePin(dot_GPIO_Port, dot_Pin);
		  second++;
		  if(second >= 60)
		  {
			  second = 0;
			  minute++;
		  }
		  if(minute >= 60)
		  {
			  minute = 0;
			  hour++;
		  }
		  if(hour >= 24)
		  {
			  hour = 0;
		  }

		  updateClockBuffer(hour, minute);

	  }

	  if(timer_flag[1] == 1)
	  {
		  Set_timer(50, 1);
		  if(index_led >= MAX_LED)
		  {
			  index_led = 0;
		  }
		  update7SEG(index_led);
		  display7SEG(led_buffer[index_led],
		  				  seg_a_GPIO_Port, seg_a_Pin,
		  				  seg_b_GPIO_Port, seg_b_Pin,
		  				  seg_c_GPIO_Port, seg_c_Pin,
		  				  seg_d_GPIO_Port, seg_d_Pin,
		  				  seg_e_GPIO_Port, seg_e_Pin,
		  				  seg_f_GPIO_Port, seg_f_Pin,
		  				  seg_g_GPIO_Port, seg_g_Pin);
		  index_led++;
	  }

	  if(timer_flag[2] == 1)
	  {
		  Set_timer(100, 2);
		  if(index_led_matrix >= 8)
		  {
			  index_led_matrix = 0;

		  updateLEDMatrix(index_led_matrix++);
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

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }
  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_ClockConfigTypeDef sClockSourceConfig = {0};
  TIM_MasterConfigTypeDef sMasterConfig = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 8000 - 1;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 10 - 1;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_Base_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sClockSourceConfig.ClockSource = TIM_CLOCKSOURCE_INTERNAL;
  if (HAL_TIM_ConfigClockSource(&htim2, &sClockSourceConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, enm_0_Pin|enm_1_Pin|dot_Pin|led_red_Pin
                          |enable_0_Pin|enable_1_Pin|enable_2_Pin|enable_3_Pin
                          |enm_2_Pin|enm_3_Pin|enm_4_Pin|enm_5_Pin
                          |enm_6_Pin|enm_7_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, seg_a_Pin|seg_b_Pin|seg_c_Pin|row_2_Pin
                          |row_3_Pin|row_4_Pin|row_5_Pin|row_6_Pin
                          |row_7_Pin|seg_d_Pin|seg_e_Pin|seg_f_Pin
                          |seg_g_Pin|row_0_Pin|row_1_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : enm_0_Pin enm_1_Pin dot_Pin led_red_Pin
                           enable_0_Pin enable_1_Pin enable_2_Pin enable_3_Pin
                           enm_2_Pin enm_3_Pin enm_4_Pin enm_5_Pin
                           enm_6_Pin enm_7_Pin */
  GPIO_InitStruct.Pin = enm_0_Pin|enm_1_Pin|dot_Pin|led_red_Pin
                          |enable_0_Pin|enable_1_Pin|enable_2_Pin|enable_3_Pin
                          |enm_2_Pin|enm_3_Pin|enm_4_Pin|enm_5_Pin
                          |enm_6_Pin|enm_7_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : seg_a_Pin seg_b_Pin seg_c_Pin row_2_Pin
                           row_3_Pin row_4_Pin row_5_Pin row_6_Pin
                           row_7_Pin seg_d_Pin seg_e_Pin seg_f_Pin
                           seg_g_Pin row_0_Pin row_1_Pin */
  GPIO_InitStruct.Pin = seg_a_Pin|seg_b_Pin|seg_c_Pin|row_2_Pin
                          |row_3_Pin|row_4_Pin|row_5_Pin|row_6_Pin
                          |row_7_Pin|seg_d_Pin|seg_e_Pin|seg_f_Pin
                          |seg_g_Pin|row_0_Pin|row_1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

void HAL_TIM_PeriodElapsedCallback(TIM_HandleTypeDef *htim)
{
	Run_timer();
}

void display7SEG(int num,
		GPIO_TypeDef* a_seg_GPIO_Port, uint16_t a_seg_Pin,
		GPIO_TypeDef* b_seg_GPIO_Port, uint16_t b_seg_Pin,
		GPIO_TypeDef* c_seg_GPIO_Port, uint16_t c_seg_Pin,
		GPIO_TypeDef* d_seg_GPIO_Port, uint16_t d_seg_Pin,
		GPIO_TypeDef* e_seg_GPIO_Port, uint16_t e_seg_Pin,
		GPIO_TypeDef* f_seg_GPIO_Port, uint16_t f_seg_Pin,
		GPIO_TypeDef* g_seg_GPIO_Port, uint16_t g_seg_Pin)
{
	switch (num) {
		case 0:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, RESET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, RESET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, SET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, SET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, SET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, SET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, SET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, RESET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, SET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, SET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, SET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, SET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, SET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, SET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, RESET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, SET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, SET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, RESET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, SET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, RESET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, RESET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, SET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, SET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, SET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, SET);
			break;
		case 8:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, RESET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, RESET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(a_seg_GPIO_Port, a_seg_Pin, RESET);
			HAL_GPIO_WritePin(b_seg_GPIO_Port, b_seg_Pin, RESET);
			HAL_GPIO_WritePin(c_seg_GPIO_Port, c_seg_Pin, RESET);
			HAL_GPIO_WritePin(d_seg_GPIO_Port, d_seg_Pin, RESET);
			HAL_GPIO_WritePin(e_seg_GPIO_Port, e_seg_Pin, SET);
			HAL_GPIO_WritePin(f_seg_GPIO_Port, f_seg_Pin, RESET);
			HAL_GPIO_WritePin(g_seg_GPIO_Port, g_seg_Pin, RESET);
			break;
		default:
			break;
	}
}

void update7SEG(int num)
{
	  switch (num)
	  {
		case 0:
			HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, RESET);
			HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, SET);
			HAL_GPIO_WritePin(enable_2_GPIO_Port, enable_2_Pin, SET);
			HAL_GPIO_WritePin(enable_3_GPIO_Port, enable_3_Pin, SET);
			break;
		case 1:
			HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, SET);
			HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, RESET);
			HAL_GPIO_WritePin(enable_2_GPIO_Port, enable_2_Pin, SET);
			HAL_GPIO_WritePin(enable_3_GPIO_Port, enable_3_Pin, SET);
			break;
		case 2:
			HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, SET);
			HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, SET);
			HAL_GPIO_WritePin(enable_2_GPIO_Port, enable_2_Pin, RESET);
			HAL_GPIO_WritePin(enable_3_GPIO_Port, enable_3_Pin, SET);
			break;
		case 3:
			HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, SET);
			HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, SET);
			HAL_GPIO_WritePin(enable_2_GPIO_Port, enable_2_Pin, SET);
			HAL_GPIO_WritePin(enable_3_GPIO_Port, enable_3_Pin, RESET);
			break;
		default:
			break;
	  }
}

void updateClockBuffer(int hour,  int minute)
{

	if(hour >= 0 && hour <10)
	{
		led_buffer[0] = 0;
		led_buffer[1] = hour;
	}
	else
	{
		led_buffer[0] = hour/10;
		led_buffer[1] = hour%10;
	}

	if(minute >= 0 && minute <10)
	{
		led_buffer[2] = 0;
		led_buffer[3] = minute;
	}
	else
	{
		led_buffer[2] = minute/10;
		led_buffer[3] = minute%10;
	}
}

void updateLEDMatrix (int index)
{
	switch (index) {
		/*case 0:
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] <<	17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_8 << 16 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14 | GPIO_PIN_15;

			break;
		case 1://111111
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_9 << 16 | GPIO_PIN_8 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14| GPIO_PIN_15;
			break;
		case 2://222222
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_10 << 16 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14| GPIO_PIN_15;
			break;
		case 3://333333
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_11 << 16 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_12 | GPIO_PIN_13 | GPIO_PIN_14| GPIO_PIN_15;
			break;
		case 4://444444
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_12 << 16 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_13 | GPIO_PIN_14| GPIO_PIN_15;
			break;
		case 5://555555
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_13 << 16 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_14| GPIO_PIN_15;
			break;
		case 6:
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_14 << 16 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13| GPIO_PIN_15;
			break;
		case 7:
			GPIOA->BSRR = (uint32_t)matrix_buffer[index] << 17 | ((uint16_t)(~matrix_buffer[index]) << 8 >> 7);
			GPIOB->BSRR = (uint32_t)GPIO_PIN_15 << 16 | GPIO_PIN_8 | GPIO_PIN_9 | GPIO_PIN_10 | GPIO_PIN_11 | GPIO_PIN_12 | GPIO_PIN_13| GPIO_PIN_14;
			break;*/
		default:
			break;
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

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
