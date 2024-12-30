/*
 * fnd_controller.h
 *
 *  Created on: Mar 2, 2022
 *      Author: JiWanOh
 */

#ifndef SRC_FND_CONTROLLER_H_
#define SRC_FND_CONTROLLER_H_

#include "main.h"
#include "stm32f1xx_hal.h"

#define TM1637_CLK_HIGH() HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_SET)
#define TM1637_CLK_LOW()  HAL_GPIO_WritePin(TM1637_CLK_GPIO_Port, TM1637_CLK_Pin, GPIO_PIN_RESET)
#define TM1637_DIO_HIGH() HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_SET)
#define TM1637_DIO_LOW()  HAL_GPIO_WritePin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin, GPIO_PIN_RESET)
#define TM1637_DIO_READ() HAL_GPIO_ReadPin(TM1637_DIO_GPIO_Port, TM1637_DIO_Pin)


#define Led_off 10
#define Underbar 11

#define TM1637_CMD_SET_DATA  0x40
#define TM1637_CMD_SET_ADDR  0xC0
#define TM1637_CMD_SET_CTRL  0x80

#define TM1637_BRIGHTNESS_MAX  0x07
#define TM1637_DISPLAY_ON      0x08

void TM1637_Init(void);
void TM1637_SetBrightness(uint8_t brightness);
void TM1637_DisplayDigits(uint8_t digits[4]);
void TM1637_Clear(void);


#endif /* SRC_FND_CONTROLLER_H_ */
