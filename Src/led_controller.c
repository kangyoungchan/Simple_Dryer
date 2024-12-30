/*
 * led_controller.c
 *
 *  Created on: Dec 17, 2024
 *      Author: sooju
 */

#include "led_controller.h"

void led1onoff(on_off_t on_off)
{
	if(on_off == ON_t)
	{
		HAL_GPIO_WritePin(PB6_LED1_GPIO_Port, PB6_LED1_Pin, 0);
	}
	else if(on_off == OFF_t){
		HAL_GPIO_WritePin(PB6_LED1_GPIO_Port, PB6_LED1_Pin, 1);
	}
}


void led2onoff(on_off_t on_off)
{
	if(on_off == ON_t)
	{
		HAL_GPIO_WritePin(PB7_LED2_GPIO_Port, PB7_LED2_Pin, 0);
	}
	else if(on_off == OFF_t){
		HAL_GPIO_WritePin(PB7_LED2_GPIO_Port, PB7_LED2_Pin, 1);
	}
}
