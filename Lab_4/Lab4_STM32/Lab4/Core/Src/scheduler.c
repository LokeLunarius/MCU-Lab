/*
 * scheduler.c
 *
 *  Created on: Nov 25, 2022
 *      Author: Windows 10
 */

#include "scherduler.h"

sTasks SCH_tasks_G[SCH_MAX_TASKS];
uint8_t current_index_task = 0;

void SCH_Init(void)
{
	current_index_task = 0;
}

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD)
{
	if(current_index_task < SCH_MAX_TASKS)
	{
		SCH_tasks_G[current_index_task].pTask = pFunction;
		SCH_tasks_G[current_index_task].Delay = DELAY/10;
		SCH_tasks_G[current_index_task].Period = PERIOD/10;
		SCH_tasks_G[current_index_task].RunMe = 0;
		SCH_tasks_G[current_index_task].TaskID = current_index_task;

		current_index_task++;
	}
}

void SCH_Update(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].Delay > 0)
		{
			SCH_tasks_G[i].Delay--;
		}
		else
		{
			SCH_tasks_G[i].Delay = SCH_tasks_G[i].Period;
			SCH_tasks_G[i].RunMe += 1;
		}
	}
}

void SCH_Dispatch_Task(void)
{
	for(int i = 0; i < current_index_task; i++)
	{
		if(SCH_tasks_G[i].RunMe > 0)
		{
			SCH_tasks_G[i].RunMe--;
			(*SCH_tasks_G[i].pTask)();
			if(SCH_tasks_G[i].Period == 0)
			{
				SCH_Delete(i);
			}
		}
	}
}

void SCH_Delete(uint32_t ID)
{
	for(int i = ID; i < SCH_MAX_TASKS - 1; i++)
	{
		SCH_tasks_G[i] = SCH_tasks_G[i+1];
	}
	current_index_task = current_index_task - 1;
}
