/*
 * heater_controller.h
 *
 *  Created on: Dec 17, 2024
 *      Author: sooju
 */

#ifndef INC_HEATER_CONTROLLER_H_
#define INC_HEATER_CONTROLLER_H_

#include "controlType.h"
#include "main.h"
#include "oled_controller.h"
#include "button.h"

#define DEFAULT_TEMP 30
#define temp_up_gap 3


void setFixedTemper();
int getFixedTemper();
void heaterControll(double current_tmp);
void temper_up();
void temper_down();
void heaterOnOff(uint8_t onoff);

#endif /* INC_HEATER_CONTROLLER_H_ */
