/*
 * fsm_led_blink.c
 *
 *  Created on: Nov 20, 2022
 *      Author: Windows 10
 */
#include "fsm_leb_blink.h"

void blink_led(int led_color)
{
	switch (led_color) {
		case red_traffic_led:
			HAL_GPIO_TogglePin(led_north_south_red_GPIO_Port, led_north_south_red_Pin);
			HAL_GPIO_TogglePin(led_east_west_red_GPIO_Port, led_east_west_red_Pin);
			break;
		case yellow_traffic_led:
			HAL_GPIO_TogglePin(led_north_south_yellow_GPIO_Port, led_north_south_yellow_Pin);
			HAL_GPIO_TogglePin(led_east_west_yellow_GPIO_Port, led_east_west_yellow_Pin);
			break;
		case green_traffic_led:
			HAL_GPIO_TogglePin(led_north_south_green_GPIO_Port, led_north_south_green_Pin);
			HAL_GPIO_TogglePin(led_east_west_green_GPIO_Port, led_east_west_green_Pin);
			break;
		default:
			break;
	}
}

void switch_enable_trigger()
{
	switch (enable_trigger) {
		case 0:
			enable_trigger = 1;
			break;
		case 1:
			enable_trigger = 0;
			break;
		default:
			break;
	}
}

void mode_7seg_display(int index_0, int index_1, int my_mode)
{
	switch (enable_trigger) {
		case 0:
			HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, GPIO_PIN_SET);
			display_7_seg_north_south(index_0);
			break;
		case 1:
			HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, GPIO_PIN_SET);
			HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, GPIO_PIN_RESET);
			display_7_seg_north_south(index_1);
			break;
		default:
			break;
	}
	display_7_seg_east_west(my_mode);
}

void fsm_led_blink()
{
	int index_0 = 0;
	int index_1 = 0;
	switch (status_mode) {
		case mode_2:
			blink_led(red_traffic_led);
			number_processing(tmp_red_led_time/100, &index_0, &index_1);
			mode_7seg_display(index_0, index_1, 2);

			switch_enable_trigger();

			HAL_Delay(500);
			break;
		case mode_3:
			blink_led(yellow_traffic_led);
			number_processing(tmp_yellow_led_time/100, &index_0, &index_1);
			mode_7seg_display(index_0, index_1, 3);

			switch_enable_trigger();

			HAL_Delay(500);
			break;
		case mode_4:
			blink_led(green_traffic_led);
			number_processing(tmp_green_led_time/100, &index_0, &index_1);
			mode_7seg_display(index_0, index_1, 4);

			switch_enable_trigger();

			HAL_Delay(500);
			break;
		default:
			break;
	}
}
