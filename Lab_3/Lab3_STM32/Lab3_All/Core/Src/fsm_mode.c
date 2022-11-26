/*
 * fsm_mode.c
 *
 *  Created on: Nov 19, 2022
 *      Author: Windows 10
 */


#include "fsm_mode.h"

int status_mode = 255;

int tmp_red_led_time = 0;
int tmp_yellow_led_time = 0;
int tmp_green_led_time = 0;

// Reality Balance Setting
int reality_balance = 180399;

// ##################
void reset_led()
{
	HAL_GPIO_WritePin(led_north_south_red_GPIO_Port, led_north_south_red_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_north_south_yellow_GPIO_Port, led_north_south_yellow_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_north_south_green_GPIO_Port, led_north_south_green_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_east_west_red_GPIO_Port, led_east_west_red_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_east_west_yellow_GPIO_Port, led_east_west_yellow_Pin, GPIO_PIN_SET);
	HAL_GPIO_WritePin(led_east_west_green_GPIO_Port, led_east_west_green_Pin, GPIO_PIN_SET);
}

void mode_button_scan()
{
	if(isButtonPressed(0) == 1)
	{
		tmp_red_led_time = red_traffic_led_time;
		tmp_yellow_led_time = yellow_traffic_led_time;
		tmp_green_led_time = green_traffic_led_time;
		reset_led();
		switch (status_mode) {
			case mode_1:
				status_mode = mode_2;
				break;
			case mode_2:
				status_mode = mode_3;
				break;
			case mode_3:
				status_mode = mode_4;
				break;
			case mode_4:
				status_mode = mode_1;
				status_traffic_led_north_south = init;
				status_traffic_led_east_west = init;
				break;
			default:
				break;
		}
	}
}

void increase_button_scan()
{
	if(isButtonPressed(1) == 1)
	{
		switch (status_mode) {
			case mode_2:
				tmp_red_led_time = tmp_red_led_time + 100;
				if(tmp_red_led_time > 9900)
				{
					tmp_red_led_time = 100;
				}
				break;
			case mode_3:
				tmp_yellow_led_time = tmp_yellow_led_time + 100;
				if(tmp_yellow_led_time > 9900)
				{
					tmp_yellow_led_time = 100;
				}
				break;
			case mode_4:
				tmp_green_led_time = tmp_green_led_time + 100;
				if(tmp_yellow_led_time > 9900)
				{
					tmp_yellow_led_time = 100;
				}
				break;
			default:
				break;
		}
	}
}
void reality_balance_red()
{
	if(tmp_red_led_time > 9900 || tmp_red_led_time < 900)
	{
		tmp_red_led_time = 900;
	}
	tmp_green_led_time = tmp_red_led_time - tmp_yellow_led_time;
}

void reality_balance_green()
{
	if(tmp_green_led_time < 600 || tmp_green_led_time > 9600)
	{
		tmp_red_led_time = 600;
	}
	tmp_red_led_time = tmp_green_led_time + tmp_yellow_led_time;
}

void reality_balance_set()
{
	if (reality_balance != 0)
	{
		tmp_yellow_led_time = 300;
		switch (status_mode) {
			case mode_2:
				reality_balance_red();
				break;
			case mode_4:
				reality_balance_green();
				break;
			default:
				break;
		}
	}
}

void set_button_scan()
{
	if(isButtonPressed(2) == 1)
	{
		reality_balance_set();
		red_traffic_led_time = tmp_red_led_time;
		yellow_traffic_led_time = tmp_yellow_led_time;
		green_traffic_led_time = tmp_green_led_time;
	}
}

void fsm_mode()
{
	switch (status_mode) {
		case init:
			status_mode = mode_1;
			break;
		case mode_1:
			fsm_traffic_light();
			mode_button_scan();
			break;
		case mode_2:
			fsm_led_blink();
			mode_button_scan();
			increase_button_scan();
			set_button_scan();
			break;
		case mode_3:
			fsm_led_blink();
			mode_button_scan();
			increase_button_scan();
			set_button_scan();
			break;
		case mode_4:
			fsm_led_blink();
			mode_button_scan();
			increase_button_scan();
			set_button_scan();
			break;
		default:
			break;
	}
}
