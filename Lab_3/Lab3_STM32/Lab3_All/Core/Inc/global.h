/*
 * global.h
 *
 *  Created on: Nov 5, 2022
 *      Author: Windows 10
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#include "software_timer.h"
#include "button.h"
#include "main.h"
#include "fsm_traffic_light.h"
#include "fsm_mode.h"
#include "fsm_leb_blink.h"

#define init 255

#define north_south_led_time 0
#define east_west_led_time 	1

#define north_south_7seg_time 	2
#define east_west_7seg_time 	3
#define enable_time 			4

#define red_traffic_led 	30
#define yellow_traffic_led 	31
#define green_traffic_led 	32

#define mode_1	101
#define mode_2 	102
#define mode_3	103
#define mode_4	104
#endif /* INC_GLOBAL_H_ */
