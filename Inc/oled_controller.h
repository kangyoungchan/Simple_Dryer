/*
 * oled_controller.h
 *
 *  Created on: Dec 16, 2024
 *      Author: sooju
 */

#ifndef INC_OLED_CONTROLLER_H_
#define INC_OLED_CONTROLLER_H_

#include "ssd1306.h"

void opening();
void pirnt_inform();
void print_temper(int temper);
void succession_display();
void work_on_change();
void work_off_change();

#endif /* INC_OLED_CONTROLLER_H_ */
