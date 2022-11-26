/*
 * global.c
 *
 *  Created on: Nov 25, 2022
 *      Author: Windows 10
 */

#include "global.h"

void led_red_toggle()
{
	HAL_GPIO_TogglePin(led_red_GPIO_Port, led_red_Pin);
}

void led_orange_toggle()
{
	HAL_GPIO_TogglePin(led_orange_GPIO_Port, led_orange_Pin);
}

void led_yellow_toggle()
{
	HAL_GPIO_TogglePin(led_yellow_GPIO_Port, led_yellow_Pin);
}

void led_green_toggle()
{
	HAL_GPIO_TogglePin(led_green_GPIO_Port, led_green_Pin);
}

void led_blue_toggle()
{
	HAL_GPIO_TogglePin(led_blue_GPIO_Port, led_blue_Pin);
}

