/*
 * fsm_traffic_light.h
 *
 *  Created on: Nov 19, 2022
 *      Author: Windows 10
 */

#ifndef INC_FSM_TRAFFIC_LIGHT_H_
#define INC_FSM_TRAFFIC_LIGHT_H_

#include "global.h"

#define north_south	123456789
#define east_west	987654321

extern int status_traffic_led_north_south;
extern int status_traffic_led_east_west;

extern int red_traffic_led_time;
extern int yellow_traffic_led_time;
extern int green_traffic_led_time;

extern int tmp_red_traffic_led_time;
extern int tmp_yellow_traffic_led_time;
extern int tmp_green_traffic_led_time;

extern int enable_trigger;

void display_7_seg_north_south(int index);

void display_7_seg_east_west(int index);

void number_processing(int current_tmp_time, int* index_0, int* index_1);

void fsm_traffic_light();

#endif /* INC_FSM_TRAFFIC_LIGHT_H_ */
