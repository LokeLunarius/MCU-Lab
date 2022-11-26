/*
 * scherduler.h
 *
 *  Created on: Nov 25, 2022
 *      Author: Windows 10
 */

#ifndef INC_SCHERDULER_H_
#define INC_SCHERDULER_H_

#include "global.h"

typedef struct
{
	void (*pTask)(void);
	uint32_t	Delay;
	uint32_t	Period;
	uint8_t		RunMe;

	uint32_t	TaskID;
}sTasks;

#define SCH_MAX_TASKS 	60

void SCH_Init(void);

void SCH_Add_Task(void(*pFunction)(), uint32_t DELAY, uint32_t PERIOD);

void SCH_Update(void);

void SCH_Dispatch_Task(void);

void SCH_Delete(uint32_t ID);

#endif /* INC_SCHERDULER_H_ */
