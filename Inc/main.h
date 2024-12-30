/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f1xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define PA4_START_SW_PIN_Pin GPIO_PIN_4
#define PA4_START_SW_PIN_GPIO_Port GPIOA
#define TMP_CS_Pin GPIO_PIN_7
#define TMP_CS_GPIO_Port GPIOA
#define PB0_TEMP_SET_UP_Pin GPIO_PIN_0
#define PB0_TEMP_SET_UP_GPIO_Port GPIOB
#define PB0_TEMP_SET_UP_EXTI_IRQn EXTI0_IRQn
#define PB1_TEMP_SET_DOWN_Pin GPIO_PIN_1
#define PB1_TEMP_SET_DOWN_GPIO_Port GPIOB
#define PB1_TEMP_SET_DOWN_EXTI_IRQn EXTI1_IRQn
#define PB2_TEMP_SET_FIX_Pin GPIO_PIN_2
#define PB2_TEMP_SET_FIX_GPIO_Port GPIOB
#define PB2_TEMP_SET_FIX_EXTI_IRQn EXTI2_IRQn
#define TM1637_CLK_Pin GPIO_PIN_12
#define TM1637_CLK_GPIO_Port GPIOB
#define TM1637_DIO_Pin GPIO_PIN_13
#define TM1637_DIO_GPIO_Port GPIOB
#define PB5_RELAY_ON_OFF_CTRL_Pin GPIO_PIN_5
#define PB5_RELAY_ON_OFF_CTRL_GPIO_Port GPIOB
#define PB6_LED1_Pin GPIO_PIN_6
#define PB6_LED1_GPIO_Port GPIOB
#define PB7_LED2_Pin GPIO_PIN_7
#define PB7_LED2_GPIO_Port GPIOB

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
