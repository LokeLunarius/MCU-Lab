/*
 * button.c
 *
 *  Created on: Sep 21, 2022
 *      Author: KAI
 */

#include "button.h"

int KeyReg_0[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg_1[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg_2[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int KeyReg_3[3] = {NORMAL_STATE, NORMAL_STATE, NORMAL_STATE};
int TimeOutForKeyPress =  300;
int button_flag[3] = {0, 0, 0};

int isButtonPressed(int index){
	if(button_flag[index] == 1){
		button_flag[index] = 0;
		return 1;
	}
	return 0;
}

void subKeyProcess(int index){
	//TODO
	//HAL_GPIO_TogglePin(LED_RED_GPIO_Port, LED_RED_Pin);
	button_flag[index] = 1;
}


GPIO_PinState button_detector(int index)
{
	switch (index) {
		case 0:
			return HAL_GPIO_ReadPin(change_mode_GPIO_Port, change_mode_Pin);
			break;
		case 1:
			return HAL_GPIO_ReadPin(change_time_GPIO_Port, change_time_Pin);
			break;
		case 2:
			return HAL_GPIO_ReadPin(set_time_GPIO_Port, set_time_Pin);
			break;
		default:
			return NORMAL_STATE;
			break;
	}
}


void getKeyInput(){
	int i = 0;
	while(i < 3)
	{
		  KeyReg_0[i] = KeyReg_1[i];
		  KeyReg_1[i] = KeyReg_2[i];
		  KeyReg_2[i] = button_detector(i);
		  if ((KeyReg_1[i] == KeyReg_0[i]) && (KeyReg_1[i] == KeyReg_2[i]))
		  {
		    if (KeyReg_2[i] != KeyReg_3[i])
		    {
		      KeyReg_3[i] = KeyReg_2[i];

		      if (KeyReg_3[i] == PRESSED_STATE)
		      {
		        TimeOutForKeyPress = 300;
		        subKeyProcess(i);
		      }
		    }
		    else
		    {
		       TimeOutForKeyPress --;
		        if (TimeOutForKeyPress == 0)
		        {
		          KeyReg_3[i] = NORMAL_STATE;
		        }
		    }
		  }
		i++;
	}
}


