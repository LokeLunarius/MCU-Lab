/*
 * software_timer.c
 *
 *  Created on: Oct 17, 2022
 *      Author: Windows 10
 */

#include "software_timer.h"

const int timer_arr_size = 18;
int timer_counter[18] = {
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0};
int timer_flag[18] = {
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0};


void Set_timer(int duration, int arr_pos)
{
	timer_counter[arr_pos] = duration;
	timer_flag[arr_pos] = 0;
}

void Run_timer()
{
	int i = 0;
	while(i < timer_arr_size)
	{
		if(timer_counter[i] > 0)
		{
			timer_counter[i]--;
			if(timer_counter[i] <= 0)
			{
				timer_flag[i] = 1;
			}
		}
		i++;
	}
}
