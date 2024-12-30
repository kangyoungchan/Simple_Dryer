/*
 * heater_controller.c
 *
 *  Created on: Dec 17, 2024
 *      Author: sooju
 */

#include "heater_controller.h"

static uint8_t m_state;

static int m_fixed_temper = DEFAULT_TEMP;
static int m_desired_temper = DEFAULT_TEMP;

void temper_up()
{
	m_desired_temper++;
	if(m_desired_temper > 99)
	{
	m_desired_temper = 0;
	}

	print_temper(m_desired_temper);
}

void temper_down()
{
	    m_desired_temper--;
		if(m_desired_temper < 0)
		{
		m_desired_temper = 99;
		}

		print_temper(m_desired_temper);
}

void setFixedTemper()
{
	m_fixed_temper = m_desired_temper;
	succession_display(m_fixed_temper);
}


int getFixedTemper()
{
	return m_desired_temper;
}


void heaterOnOff(uint8_t onoff)
{
	m_state = onoff;
	HAL_GPIO_WritePin(PB5_RELAY_ON_OFF_CTRL_GPIO_Port, PB5_RELAY_ON_OFF_CTRL_Pin, !m_state);
}




void heaterControll(double current_tmp)
{

		if(m_fixed_temper - temp_up_gap > (int)current_tmp && getSwState() == ON_t)
		{
			heaterOnOff(ON_t);
			led2onoff(ON_t);
			work_on_change();
		}
		else
		{
			heaterOnOff(OFF_t);
			led2onoff(OFF_t);
			work_off_change();
		}

}




