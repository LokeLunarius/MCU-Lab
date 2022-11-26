/*
 * software_timer.h
 *
 *  Created on: Oct 17, 2022
 *      Author: Windows 10
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer_flag[];

void Set_timer(int duration, int arr_pos);
void Run_timer();

#endif /* INC_SOFTWARE_TIMER_H_ */
