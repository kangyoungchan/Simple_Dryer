/*
 * temperature_sensor.h
 *
 *  Created on: Dec 10, 2024
 *      Author: sooju
 */

#ifndef INC_TEMPERATURE_SENSOR_H_
#define INC_TEMPERATURE_SENSOR_H_

#include "main.h"

extern SPI_HandleTypeDef hspi1;



void TMP_Select();


void TMP_Unselect();


void TMP_Recevie(uint16_t *readdata , uint8_t data_length, uint8_t time_out , float *tmp);


#endif /* INC_TEMPERATURE_SENSOR_H_ */
