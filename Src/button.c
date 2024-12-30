/*
 * button.c
 *
 *  Created on: Dec 17, 2024
 *      Author: sooju
 */


#include "button.h"

int count=0;

void CheckButton()
{


	if (g_f_sw_up) {

		        temper_up();
				g_f_sw_up = 0;

			}

			if (g_f_sw_down) {

				temper_down();
				g_f_sw_down = 0;
			}

			if (g_f_sw_fix) {

				setFixedTemper();
				g_f_sw_fix = 0;
			}

}


on_off_t getSwState()
{
	if(HAL_GPIO_ReadPin(PA4_START_SW_PIN_GPIO_Port, PA4_START_SW_PIN_Pin))
	{
		return ON_t;
	}
	else
	{
		return OFF_t;
	}
}


