/*
 * temperature_sensor.c
 *
 *  Created on: Dec 10, 2024
 *      Author: sooju
 */
#include "temperature_sensor.h"


 uint16_t rawData;
 uint16_t tempData;

void TMP_Select()
{
	HAL_GPIO_WritePin(TMP_CS_GPIO_Port, TMP_CS_Pin, 0);
}

void TMP_Unselect()
{
	HAL_GPIO_WritePin(TMP_CS_GPIO_Port, TMP_CS_Pin, 1);
}

void TMP_Receive(uint8_t *readdata , uint8_t data_length, uint16_t timeout , double *tmp)
{

	HAL_Delay(220);
	TMP_Select();
	HAL_Delay(1);
	HAL_SPI_Receive(&hspi1, readdata, data_length, timeout);
	TMP_Unselect();
	rawData = (readdata[0] << 8) | readdata[1];
    tempData= (rawData>>3) & 0x0fff;
    *tmp=  tempData * 0.25;

}
