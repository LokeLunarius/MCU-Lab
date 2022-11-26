/*
 * fsm_traffic_light.c
 *
 *  Created on: Nov 19, 2022
 *      Author: Windows 10
 */


#include "fsm_traffic_light.h"

// ############################################################################################################

int status_traffic_led_north_south = 255;
int status_traffic_led_east_west =  255;

int red_traffic_led_time = 1200;
int yellow_traffic_led_time = 300;
int green_traffic_led_time = 900;

int tmp_red_traffic_led_time = 0;
int tmp_yellow_traffic_led_time = 0;
int tmp_green_traffic_led_time = 0;

int enable_trigger = 0;

// ############################################################################################################

//   MY FUNCTION   ##################
void display_7_seg_north_south(int index)
{
	GPIO_TypeDef* seg_a_GPIO_PORT = seg_north_south_a_GPIO_Port; uint16_t seg_a_PIN = seg_north_south_a_Pin;
	GPIO_TypeDef* seg_b_GPIO_PORT = seg_north_south_b_GPIO_Port; uint16_t seg_b_PIN = seg_north_south_b_Pin;
	GPIO_TypeDef* seg_c_GPIO_PORT = seg_north_south_c_GPIO_Port; uint16_t seg_c_PIN = seg_north_south_c_Pin;
	GPIO_TypeDef* seg_d_GPIO_PORT = seg_north_south_d_GPIO_Port; uint16_t seg_d_PIN = seg_north_south_d_Pin;
	GPIO_TypeDef* seg_e_GPIO_PORT = seg_north_south_e_GPIO_Port; uint16_t seg_e_PIN = seg_north_south_e_Pin;
	GPIO_TypeDef* seg_f_GPIO_PORT = seg_north_south_f_GPIO_Port; uint16_t seg_f_PIN = seg_north_south_f_Pin;
	GPIO_TypeDef* seg_g_GPIO_PORT = seg_north_south_g_GPIO_Port; uint16_t seg_g_PIN = seg_north_south_g_Pin;
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

void display_7_seg_east_west(int index)
{
	GPIO_TypeDef* seg_a_GPIO_PORT = seg_east_west_a_GPIO_Port; uint16_t seg_a_PIN = seg_east_west_a_Pin;
	GPIO_TypeDef* seg_b_GPIO_PORT = seg_east_west_b_GPIO_Port; uint16_t seg_b_PIN = seg_east_west_b_Pin;
	GPIO_TypeDef* seg_c_GPIO_PORT = seg_east_west_c_GPIO_Port; uint16_t seg_c_PIN = seg_east_west_c_Pin;
	GPIO_TypeDef* seg_d_GPIO_PORT = seg_east_west_d_GPIO_Port; uint16_t seg_d_PIN = seg_east_west_d_Pin;
	GPIO_TypeDef* seg_e_GPIO_PORT = seg_east_west_e_GPIO_Port; uint16_t seg_e_PIN = seg_east_west_e_Pin;
	GPIO_TypeDef* seg_f_GPIO_PORT = seg_east_west_f_GPIO_Port; uint16_t seg_f_PIN = seg_east_west_f_Pin;
	GPIO_TypeDef* seg_g_GPIO_PORT = seg_east_west_g_GPIO_Port; uint16_t seg_g_PIN = seg_east_west_g_Pin;
	switch (index) {
		case 0:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_SET);
			break;
		case 1:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_SET);
			break;
		case 2:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 3:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 4:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 5:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 6:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 7:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_SET);
			break;
		case 8:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		case 9:
			HAL_GPIO_WritePin(seg_a_GPIO_PORT, seg_a_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_b_GPIO_PORT, seg_b_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_c_GPIO_PORT, seg_c_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_d_GPIO_PORT, seg_d_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_e_GPIO_PORT, seg_e_PIN, GPIO_PIN_SET);
			HAL_GPIO_WritePin(seg_f_GPIO_PORT, seg_f_PIN, GPIO_PIN_RESET);
			HAL_GPIO_WritePin(seg_g_GPIO_PORT, seg_g_PIN, GPIO_PIN_RESET);
			break;
		default:
			break;
	}
}

void display_traffic_led(int color_traffic_led, int positon)
{
	switch (positon) {
		case north_south:
			switch (color_traffic_led) {
				case red_traffic_led:
					HAL_GPIO_WritePin(led_north_south_red_GPIO_Port, led_north_south_red_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(led_north_south_yellow_GPIO_Port, led_north_south_yellow_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_north_south_green_GPIO_Port, led_north_south_green_Pin, GPIO_PIN_SET);
					break;
				case yellow_traffic_led:
					HAL_GPIO_WritePin(led_north_south_red_GPIO_Port, led_north_south_red_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_north_south_yellow_GPIO_Port, led_north_south_yellow_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(led_north_south_green_GPIO_Port, led_north_south_green_Pin, GPIO_PIN_SET);
					break;
				case green_traffic_led:
					HAL_GPIO_WritePin(led_north_south_red_GPIO_Port, led_north_south_red_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_north_south_yellow_GPIO_Port, led_north_south_yellow_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_north_south_green_GPIO_Port, led_north_south_green_Pin, GPIO_PIN_RESET);
					break;
				default:
					break;
			}
			break;
		case east_west:
			switch (color_traffic_led) {
				case red_traffic_led:
					HAL_GPIO_WritePin(led_east_west_red_GPIO_Port, led_east_west_red_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(led_east_west_yellow_GPIO_Port, led_east_west_yellow_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_east_west_green_GPIO_Port, led_east_west_green_Pin, GPIO_PIN_SET);
					break;
				case yellow_traffic_led:
					HAL_GPIO_WritePin(led_east_west_red_GPIO_Port, led_east_west_red_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_east_west_yellow_GPIO_Port, led_east_west_yellow_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(led_east_west_green_GPIO_Port, led_east_west_green_Pin, GPIO_PIN_SET);
					break;
				case green_traffic_led:
					HAL_GPIO_WritePin(led_east_west_red_GPIO_Port, led_east_west_red_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_east_west_yellow_GPIO_Port, led_east_west_yellow_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(led_east_west_green_GPIO_Port, led_east_west_green_Pin, GPIO_PIN_RESET);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

void tmp_val_init()
{
	tmp_red_traffic_led_time = red_traffic_led_time/100;
	tmp_yellow_traffic_led_time = yellow_traffic_led_time/100;
	tmp_green_traffic_led_time = green_traffic_led_time/100;
}

void tmp_val_overload()
{
	if(tmp_red_traffic_led_time <= 0)
	{
		tmp_red_traffic_led_time = red_traffic_led_time/100;
	}
	if(tmp_yellow_traffic_led_time <= 0)
	{
		tmp_yellow_traffic_led_time = yellow_traffic_led_time/100;
	}
	if(tmp_green_traffic_led_time <= 0)
	{
		tmp_green_traffic_led_time = green_traffic_led_time/100;
	}
}

void number_processing(int current_tmp_time, int* index_0, int* index_1)
{
	*index_0 = current_tmp_time/10;
	*index_1 = current_tmp_time%10;
}

void timer_scan_7seg(int position, int* current_tmp_time)
{
	switch (position) {
		case north_south:
			if(timer_flag[north_south_7seg_time] == 1)
			{
				*current_tmp_time = *current_tmp_time - 1;
				Set_timer(100, north_south_7seg_time);
			}
			break;
		case east_west:
			if(timer_flag[east_west_7seg_time] == 1)
			{
				*current_tmp_time = *current_tmp_time - 1;
				Set_timer(100, east_west_7seg_time);
			}
			break;
		default:
			break;
	}
}

void enable_trigger_scan()
{
	if(timer_flag[enable_time] == 1)
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
		Set_timer(50, enable_time);
	}
}

void enable_display_7seg(int index_0, int index_1, int position)
{
	switch (position) {
		case north_south:
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
			break;
		case east_west:
			switch (enable_trigger) {
				case 0:
					HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, GPIO_PIN_RESET);
					HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, GPIO_PIN_SET);
					display_7_seg_east_west(index_0);
					break;
				case 1:
					HAL_GPIO_WritePin(enable_0_GPIO_Port, enable_0_Pin, GPIO_PIN_SET);
					HAL_GPIO_WritePin(enable_1_GPIO_Port, enable_1_Pin, GPIO_PIN_RESET);
					display_7_seg_east_west(index_1);
					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}

// ############################################################################################################

//   MY FSM MODE 1   ##################
void fsm_traffic_light()
{
	int initial_red_position = north_south;
	int index_0 = 0;
	int index_1 = 0;
	switch (initial_red_position) {
		// north-sount initial red case ####################################
		case north_south:
			//  north-south case ##################
			switch (status_traffic_led_north_south) {
				case init:
					display_traffic_led(red_traffic_led, north_south);
					status_traffic_led_north_south = red_traffic_led;
					tmp_val_init();

					enable_trigger = 0;

					Set_timer(red_traffic_led_time, north_south_led_time);
					Set_timer(100,north_south_7seg_time);
					Set_timer(50, enable_time);
					break;
				case red_traffic_led:
					display_traffic_led(red_traffic_led, north_south);

					tmp_val_overload();
					number_processing(tmp_red_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, north_south);

					if(timer_flag[north_south_led_time]== 1)
					{
						status_traffic_led_north_south = green_traffic_led;
						Set_timer(green_traffic_led_time, north_south_led_time);
					}
					timer_scan_7seg(north_south, &tmp_red_traffic_led_time);
					enable_trigger_scan();

					break;
				case yellow_traffic_led:
					display_traffic_led(yellow_traffic_led, north_south);

					tmp_val_overload();
					number_processing(tmp_yellow_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, north_south);

					if(timer_flag[north_south_led_time]== 1)
					{
						status_traffic_led_north_south = red_traffic_led;
						Set_timer(red_traffic_led_time, north_south_led_time);
					}
					timer_scan_7seg(north_south, &tmp_yellow_traffic_led_time);
					enable_trigger_scan();

					break;
				case green_traffic_led:
					display_traffic_led(green_traffic_led, north_south);

					tmp_val_overload();
					number_processing(tmp_green_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, north_south);

					if(timer_flag[north_south_led_time]== 1)
					{
						status_traffic_led_north_south = yellow_traffic_led;
						Set_timer(yellow_traffic_led_time, north_south_led_time);
					}
					timer_scan_7seg(north_south, &tmp_green_traffic_led_time);
					enable_trigger_scan();

					break;
				default:
					break;
			}
			//  east-west case ##################
			switch (status_traffic_led_east_west) {
				case init:
					display_traffic_led(green_traffic_led, east_west);
					status_traffic_led_east_west = green_traffic_led;
					tmp_val_init();

					enable_trigger = 0;

					Set_timer(green_traffic_led_time, east_west_led_time);
					Set_timer(100,east_west_7seg_time);
					Set_timer(50, enable_time);
					break;
				case red_traffic_led:
					display_traffic_led(red_traffic_led, east_west);

					tmp_val_overload();
					number_processing(tmp_red_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, east_west);

					if(timer_flag[east_west_led_time]== 1)
					{
						status_traffic_led_east_west = green_traffic_led;
						Set_timer(green_traffic_led_time, east_west_led_time);
					}
					timer_scan_7seg(east_west, &tmp_red_traffic_led_time);
					enable_trigger_scan();

					break;
				case yellow_traffic_led:
					display_traffic_led(yellow_traffic_led, east_west);

					tmp_val_overload();
					number_processing(tmp_yellow_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, east_west);

					if(timer_flag[east_west_led_time]== 1)
					{
						status_traffic_led_east_west = red_traffic_led;
						Set_timer(red_traffic_led_time, east_west_led_time);
					}
					timer_scan_7seg(east_west, &tmp_yellow_traffic_led_time);
					enable_trigger_scan();

					break;
				case green_traffic_led:
					display_traffic_led(green_traffic_led, east_west);

					tmp_val_overload();
					number_processing(tmp_green_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, east_west);

					if(timer_flag[east_west_led_time]== 1)
					{
						status_traffic_led_east_west = yellow_traffic_led;
						Set_timer(yellow_traffic_led_time, east_west_led_time);
					}
					timer_scan_7seg(east_west, &tmp_green_traffic_led_time);
					enable_trigger_scan();

					break;
				default:
					break;
			}
			break;
		//  east-west initial red case ####################################
		case east_west:
			//  north-south case ##################
			switch (status_traffic_led_north_south) {
				case init:
					display_traffic_led(green_traffic_led, north_south);
					status_traffic_led_north_south = green_traffic_led;
					tmp_val_init();

					enable_trigger = 0;

					Set_timer(green_traffic_led_time, north_south_led_time);
					Set_timer(100,north_south_7seg_time);
					Set_timer(50, enable_time);
					break;
				case red_traffic_led:
					display_traffic_led(red_traffic_led, north_south);

					tmp_val_overload();
					number_processing(tmp_red_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, north_south);

					if(timer_flag[north_south_led_time]== 1)
					{
						status_traffic_led_north_south = green_traffic_led;
						Set_timer(green_traffic_led_time, north_south_led_time);
					}
					timer_scan_7seg(north_south, &tmp_red_traffic_led_time);
					enable_trigger_scan();

					break;
				case yellow_traffic_led:
					display_traffic_led(yellow_traffic_led, north_south);

					tmp_val_overload();
					number_processing(tmp_yellow_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, north_south);

					if(timer_flag[north_south_led_time]== 1)
					{
						status_traffic_led_north_south = red_traffic_led;
						Set_timer(red_traffic_led_time, north_south_led_time);
					}
					timer_scan_7seg(north_south, &tmp_yellow_traffic_led_time);
					enable_trigger_scan();

					break;
				case green_traffic_led:
					display_traffic_led(green_traffic_led, north_south);

					tmp_val_overload();
					number_processing(tmp_green_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, north_south);

					if(timer_flag[north_south_led_time]== 1)
					{
						status_traffic_led_north_south = yellow_traffic_led;
						Set_timer(yellow_traffic_led_time, north_south_led_time);
					}
					timer_scan_7seg(north_south, &tmp_green_traffic_led_time);
					enable_trigger_scan();

					break;
				default:
					break;
			}
			//  east-west case ##################
			switch (status_traffic_led_east_west) {
				case init:
					display_traffic_led(red_traffic_led, east_west);
					status_traffic_led_east_west = red_traffic_led;
					tmp_val_init();

					enable_trigger = 0;

					Set_timer(red_traffic_led_time, east_west_led_time);
					Set_timer(100,east_west_7seg_time);
					Set_timer(50, enable_time);
					break;
				case red_traffic_led:
					display_traffic_led(red_traffic_led, east_west);

					tmp_val_overload();
					number_processing(tmp_red_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, east_west);

					if(timer_flag[east_west_led_time]== 1)
					{
						status_traffic_led_east_west = green_traffic_led;
						Set_timer(green_traffic_led_time, east_west_led_time);
					}
					timer_scan_7seg(east_west, &tmp_red_traffic_led_time);
					enable_trigger_scan();

					break;
				case yellow_traffic_led:
					display_traffic_led(yellow_traffic_led, east_west);

					tmp_val_overload();
					number_processing(tmp_yellow_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, east_west);

					if(timer_flag[east_west_led_time]== 1)
					{
						status_traffic_led_east_west = red_traffic_led;
						Set_timer(red_traffic_led_time, east_west_led_time);
					}
					timer_scan_7seg(east_west, &tmp_yellow_traffic_led_time);
					enable_trigger_scan();

					break;
				case green_traffic_led:
					display_traffic_led(green_traffic_led, east_west);

					tmp_val_overload();
					number_processing(tmp_green_traffic_led_time, &index_0, &index_1);
					enable_display_7seg(index_0, index_1, east_west);

					if(timer_flag[east_west_led_time]== 1)
					{
						status_traffic_led_east_west = yellow_traffic_led;
						Set_timer(yellow_traffic_led_time, east_west_led_time);
					}
					timer_scan_7seg(east_west, &tmp_green_traffic_led_time);
					enable_trigger_scan();

					break;
				default:
					break;
			}
			break;
		default:
			break;
	}
}
