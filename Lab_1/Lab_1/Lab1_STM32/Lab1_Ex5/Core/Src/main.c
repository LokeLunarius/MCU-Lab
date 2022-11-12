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
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

void display7SEG(int num,
		GPIO_TypeDef* a_seg_GPIO_PORT, uint16_t a_seg_Pin,
		GPIO_TypeDef* b_seg_GPIO_PORT, uint16_t b_seg_Pin,
		GPIO_TypeDef* c_seg_GPIO_PORT, uint16_t c_seg_Pin,
		GPIO_TypeDef* d_seg_GPIO_PORT, uint16_t d_seg_Pin,
		GPIO_TypeDef* e_seg_GPIO_PORT, uint16_t e_seg_Pin,
		GPIO_TypeDef* f_seg_GPIO_PORT, uint16_t f_seg_Pin,
		GPIO_TypeDef* g_seg_GPIO_PORT, uint16_t g_seg_Pin);
char led_toggle(
		GPIO_TypeDef* red, uint16_t red_pin ,
		GPIO_TypeDef* yellow, uint16_t yellow_pin,
		GPIO_TypeDef* green, uint16_t green_pin,
		char color);

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
  /* USER CODE BEGIN 2 */

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
  int first_time_counter = 1;
  int counter_x = 0;
  int counter_y = 0;
  char color_x;
  char color_y;
  int first_time_light = 1;
  while (1)
  {
	  //Counter set
	  if(first_time_counter == 1)
	  {
		  counter_x = 9;
		  display7SEG(counter_y--,
				  a_v_seg_GPIO_Port, a_v_seg_Pin,
				  b_v_seg_GPIO_Port, b_v_seg_Pin,
				  c_v_seg_GPIO_Port, c_v_seg_Pin,
				  d_v_seg_GPIO_Port, d_v_seg_Pin,
				  e_v_seg_GPIO_Port, e_v_seg_Pin,
				  f_v_seg_GPIO_Port, f_v_seg_Pin,
				  g_v_seg_GPIO_Port, g_v_seg_Pin
				  );

		  counter_y = 6;
		  display7SEG(counter_x--,
				  a_h_seg_GPIO_Port, a_h_seg_Pin,
				  b_h_seg_GPIO_Port, b_h_seg_Pin,
				  c_h_seg_GPIO_Port, c_h_seg_Pin,
				  d_h_seg_GPIO_Port, d_h_seg_Pin,
				  e_h_seg_GPIO_Port, e_h_seg_Pin,
				  f_h_seg_GPIO_Port, f_h_seg_Pin,
				  g_h_seg_GPIO_Port, g_h_seg_Pin
				  );
		  first_time_counter = 0;
	  }
	  //Light
	  if(first_time_light == 1)
	  {
		  HAL_GPIO_TogglePin(led_yellow_vert_GPIO_Port, led_yellow_vert_Pin);
		  HAL_GPIO_TogglePin(led_green_vert_GPIO_Port, led_green_vert_Pin);
		  color_y = 'R';

		  HAL_GPIO_TogglePin(led_yellow_hori_GPIO_Port, led_yellow_hori_Pin);
		  HAL_GPIO_TogglePin(led_red_hori_GPIO_Port, led_red_hori_Pin);
		  color_x = 'G';

		  first_time_light = 0;
	  }
	  if(color_y == 'R')
	  {
		  counter_y = 9;
		  counter_x = 6;
		  for (int i = 0; i < 7; i++)
		  {
			  display7SEG(counter_y--,
					  a_v_seg_GPIO_Port, a_v_seg_Pin,
					  b_v_seg_GPIO_Port, b_v_seg_Pin,
					  c_v_seg_GPIO_Port, c_v_seg_Pin,
					  d_v_seg_GPIO_Port, d_v_seg_Pin,
					  e_v_seg_GPIO_Port, e_v_seg_Pin,
					  f_v_seg_GPIO_Port, f_v_seg_Pin,
					  g_v_seg_GPIO_Port, g_v_seg_Pin
					  );
			  display7SEG(counter_x--,
					  a_h_seg_GPIO_Port, a_h_seg_Pin,
					  b_h_seg_GPIO_Port, b_h_seg_Pin,
					  c_h_seg_GPIO_Port, c_h_seg_Pin,
					  d_h_seg_GPIO_Port, d_h_seg_Pin,
					  e_h_seg_GPIO_Port, e_h_seg_Pin,
					  f_h_seg_GPIO_Port, f_h_seg_Pin,
					  g_h_seg_GPIO_Port, g_h_seg_Pin
					  );
			  HAL_Delay(1000);
		  }
		  color_x = led_toggle(
				  led_red_hori_GPIO_Port, led_red_hori_Pin,
				  led_yellow_hori_GPIO_Port, led_yellow_hori_Pin,
				  led_green_hori_GPIO_Port, led_green_hori_Pin,
				  color_x);
		  counter_x = 2;
		  for (int i = 0; i < 3; i++)
		  {
			  display7SEG(counter_y--,
					  a_v_seg_GPIO_Port, a_v_seg_Pin,
					  b_v_seg_GPIO_Port, b_v_seg_Pin,
					  c_v_seg_GPIO_Port, c_v_seg_Pin,
					  d_v_seg_GPIO_Port, d_v_seg_Pin,
					  e_v_seg_GPIO_Port, e_v_seg_Pin,
					  f_v_seg_GPIO_Port, f_v_seg_Pin,
					  g_v_seg_GPIO_Port, g_v_seg_Pin
					  );
			  display7SEG(counter_x--,
					  a_h_seg_GPIO_Port, a_h_seg_Pin,
					  b_h_seg_GPIO_Port, b_h_seg_Pin,
					  c_h_seg_GPIO_Port, c_h_seg_Pin,
					  d_h_seg_GPIO_Port, d_h_seg_Pin,
					  e_h_seg_GPIO_Port, e_h_seg_Pin,
					  f_h_seg_GPIO_Port, f_h_seg_Pin,
					  g_h_seg_GPIO_Port, g_h_seg_Pin
					  );
			  HAL_Delay(1000);
		  }
		  color_x = led_toggle(
				  led_red_hori_GPIO_Port, led_red_hori_Pin,
				  led_yellow_hori_GPIO_Port, led_yellow_hori_Pin,
				  led_green_hori_GPIO_Port, led_green_hori_Pin,
				  color_x);
		  color_y = led_toggle(
				  led_red_vert_GPIO_Port, led_red_vert_Pin,
				  led_yellow_vert_GPIO_Port, led_yellow_vert_Pin,
				  led_green_vert_GPIO_Port, led_green_vert_Pin,
				  color_y);
	  }
	  else if (color_x == 'R')
	  {
		  counter_x = 9;
		  counter_y = 6;
		  for (int i = 0; i < 7; i++)
		  {
			  display7SEG(counter_y--,
					  a_v_seg_GPIO_Port, a_v_seg_Pin,
					  b_v_seg_GPIO_Port, b_v_seg_Pin,
					  c_v_seg_GPIO_Port, c_v_seg_Pin,
					  d_v_seg_GPIO_Port, d_v_seg_Pin,
					  e_v_seg_GPIO_Port, e_v_seg_Pin,
					  f_v_seg_GPIO_Port, f_v_seg_Pin,
					  g_v_seg_GPIO_Port, g_v_seg_Pin
					  );
			  display7SEG(counter_x--,
					  a_h_seg_GPIO_Port, a_h_seg_Pin,
					  b_h_seg_GPIO_Port, b_h_seg_Pin,
					  c_h_seg_GPIO_Port, c_h_seg_Pin,
					  d_h_seg_GPIO_Port, d_h_seg_Pin,
					  e_h_seg_GPIO_Port, e_h_seg_Pin,
					  f_h_seg_GPIO_Port, f_h_seg_Pin,
					  g_h_seg_GPIO_Port, g_h_seg_Pin
					  );
			  HAL_Delay(1000);
		  }
		  color_y = led_toggle(
				  led_red_vert_GPIO_Port, led_red_vert_Pin,
				  led_yellow_vert_GPIO_Port, led_yellow_vert_Pin,
				  led_green_vert_GPIO_Port, led_green_vert_Pin,
				  color_y);
		  counter_y = 2;
		  for (int i = 0; i < 3; i++)
		  {
			  display7SEG(counter_y--,
					  a_v_seg_GPIO_Port, a_v_seg_Pin,
					  b_v_seg_GPIO_Port, b_v_seg_Pin,
					  c_v_seg_GPIO_Port, c_v_seg_Pin,
					  d_v_seg_GPIO_Port, d_v_seg_Pin,
					  e_v_seg_GPIO_Port, e_v_seg_Pin,
					  f_v_seg_GPIO_Port, f_v_seg_Pin,
					  g_v_seg_GPIO_Port, g_v_seg_Pin
					  );
			  display7SEG(counter_x--,
					  a_h_seg_GPIO_Port, a_h_seg_Pin,
					  b_h_seg_GPIO_Port, b_h_seg_Pin,
					  c_h_seg_GPIO_Port, c_h_seg_Pin,
					  d_h_seg_GPIO_Port, d_h_seg_Pin,
					  e_h_seg_GPIO_Port, e_h_seg_Pin,
					  f_h_seg_GPIO_Port, f_h_seg_Pin,
					  g_h_seg_GPIO_Port, g_h_seg_Pin
					  );
			  HAL_Delay(1000);
		  }
		  color_y = led_toggle(
				  led_red_vert_GPIO_Port, led_red_vert_Pin,
				  led_yellow_vert_GPIO_Port, led_yellow_vert_Pin,
				  led_green_vert_GPIO_Port, led_green_vert_Pin,
				  color_y);
		  color_x = led_toggle(
				  led_red_hori_GPIO_Port, led_red_hori_Pin,
				  led_yellow_hori_GPIO_Port, led_yellow_hori_Pin,
				  led_green_hori_GPIO_Port, led_green_hori_Pin,
				  color_x);
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
  HAL_GPIO_WritePin(GPIOA, led_red_vert_Pin|led_yellow_vert_Pin|led_green_vert_Pin|led_red_hori_Pin
                          |led_yellow_hori_Pin|led_green_hori_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, a_v_seg_Pin|b_v_seg_Pin|c_v_seg_Pin|d_h_seg_Pin
                          |e_h_seg_Pin|f_h_seg_Pin|g_h_seg_Pin|d_v_seg_Pin
                          |e_v_seg_Pin|f_v_seg_Pin|g_v_seg_Pin|a_h_seg_Pin
                          |b_h_seg_Pin|c_h_seg_Pin, GPIO_PIN_RESET);

  /*Configure GPIO pins : led_red_vert_Pin led_yellow_vert_Pin led_green_vert_Pin led_red_hori_Pin
                           led_yellow_hori_Pin led_green_hori_Pin */
  GPIO_InitStruct.Pin = led_red_vert_Pin|led_yellow_vert_Pin|led_green_vert_Pin|led_red_hori_Pin
                          |led_yellow_hori_Pin|led_green_hori_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pins : a_v_seg_Pin b_v_seg_Pin c_v_seg_Pin d_h_seg_Pin
                           e_h_seg_Pin f_h_seg_Pin g_h_seg_Pin d_v_seg_Pin
                           e_v_seg_Pin f_v_seg_Pin g_v_seg_Pin a_h_seg_Pin
                           b_h_seg_Pin c_h_seg_Pin */
  GPIO_InitStruct.Pin = a_v_seg_Pin|b_v_seg_Pin|c_v_seg_Pin|d_h_seg_Pin
                          |e_h_seg_Pin|f_h_seg_Pin|g_h_seg_Pin|d_v_seg_Pin
                          |e_v_seg_Pin|f_v_seg_Pin|g_v_seg_Pin|a_h_seg_Pin
                          |b_h_seg_Pin|c_h_seg_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

}

/* USER CODE BEGIN 4 */

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

char led_toggle(GPIO_TypeDef* red, uint16_t red_pin , GPIO_TypeDef* yellow, uint16_t yellow_pin, GPIO_TypeDef* green, uint16_t green_pin, char color)
{
	  if(color == 'R')
	  {
		  HAL_GPIO_TogglePin(red, red_pin);
		  HAL_GPIO_TogglePin(green, green_pin);
		  color = 'G';
	  }
	  else if (color == 'Y')
	  {
		  HAL_GPIO_TogglePin(yellow, yellow_pin);
		  HAL_GPIO_TogglePin(red, red_pin);
		  color = 'R';
	  }
	  else if (color == 'G')
	  {
		  HAL_GPIO_TogglePin(green, green_pin);
		  HAL_GPIO_TogglePin(yellow, yellow_pin);
		  color = 'Y';
	  }
	  return color;
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
