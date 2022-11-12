/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define enm_0_Pin GPIO_PIN_2
#define enm_0_GPIO_Port GPIOA
#define enm_1_Pin GPIO_PIN_3
#define enm_1_GPIO_Port GPIOA
#define dot_Pin GPIO_PIN_4
#define dot_GPIO_Port GPIOA
#define led_red_Pin GPIO_PIN_5
#define led_red_GPIO_Port GPIOA
#define enable_0_Pin GPIO_PIN_6
#define enable_0_GPIO_Port GPIOA
#define enable_1_Pin GPIO_PIN_7
#define enable_1_GPIO_Port GPIOA
#define seg_a_Pin GPIO_PIN_0
#define seg_a_GPIO_Port GPIOB
#define seg_b_Pin GPIO_PIN_1
#define seg_b_GPIO_Port GPIOB
#define seg_c_Pin GPIO_PIN_2
#define seg_c_GPIO_Port GPIOB
#define row_2_Pin GPIO_PIN_10
#define row_2_GPIO_Port GPIOB
#define row_3_Pin GPIO_PIN_11
#define row_3_GPIO_Port GPIOB
#define row_4_Pin GPIO_PIN_12
#define row_4_GPIO_Port GPIOB
#define row_5_Pin GPIO_PIN_13
#define row_5_GPIO_Port GPIOB
#define row_6_Pin GPIO_PIN_14
#define row_6_GPIO_Port GPIOB
#define row_7_Pin GPIO_PIN_15
#define row_7_GPIO_Port GPIOB
#define enable_2_Pin GPIO_PIN_8
#define enable_2_GPIO_Port GPIOA
#define enable_3_Pin GPIO_PIN_9
#define enable_3_GPIO_Port GPIOA
#define enm_2_Pin GPIO_PIN_10
#define enm_2_GPIO_Port GPIOA
#define enm_3_Pin GPIO_PIN_11
#define enm_3_GPIO_Port GPIOA
#define enm_4_Pin GPIO_PIN_12
#define enm_4_GPIO_Port GPIOA
#define enm_5_Pin GPIO_PIN_13
#define enm_5_GPIO_Port GPIOA
#define enm_6_Pin GPIO_PIN_14
#define enm_6_GPIO_Port GPIOA
#define enm_7_Pin GPIO_PIN_15
#define enm_7_GPIO_Port GPIOA
#define seg_d_Pin GPIO_PIN_3
#define seg_d_GPIO_Port GPIOB
#define seg_e_Pin GPIO_PIN_4
#define seg_e_GPIO_Port GPIOB
#define seg_f_Pin GPIO_PIN_5
#define seg_f_GPIO_Port GPIOB
#define seg_g_Pin GPIO_PIN_6
#define seg_g_GPIO_Port GPIOB
#define row_0_Pin GPIO_PIN_8
#define row_0_GPIO_Port GPIOB
#define row_1_Pin GPIO_PIN_9
#define row_1_GPIO_Port GPIOB
/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
