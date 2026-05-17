/**
 * @file    IR_sensor.h
 * @author  Cucumber
 * @brief   控制红外传感器的库的头函数
 * @version 0.1
 * @date    2026-06-11
 * 
 * @copyright Copyright (c) 2026
 ____                                             |
/    \           ___            ___    __    __   | ___    ___     __
|       |    |  /   \  |    |  /   \  /  \  /  \  |/   \  /   \  |/
|       |    |  |      |    |  |      |   \/   |  |    |  |---/  | 
\____/  \____/  \___/  \____/  \___/  |        |  \____/  \____  |
                        -Cucumber-
 * 
 */

#ifndef __IR_SENSOR_H_
#define __IR_SENSOR_H_

#include "stm32f1xx_hal.h"
#include <stdbool.h>

#define IR_PORT GPIOB
#define IR_PIN GPIO_PIN_9

#ifdef __cplusplus

void IR_Read();


extern "C" {
#endif //__cplusplus

bool IR_Read_(void);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__IR_SENSOR_H_