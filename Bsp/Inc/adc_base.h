/**
 * @file    adc_base.h
 * @author  Cucumber
 * @brief   ADC 控制库头文件
 * @version 0.1
 * @date    2026-05-23
 * 
 ____                                             |
/    \           ___            ___    __    __   | ___    ___     __
|       |    |  /   \  |    |  /   \  /  \  /  \  |/   \  /   \  |/
|       |    |  |      |    |  |      |   \/   |  |    |  |---/  | 
\____/  \____/  \___/  \____/  \___/  |        |  \____/  \____  |
                        -Cucumber-

 * @copyright Copyright (c) 2026
 * 
 */

#include "main.h"

#define ADC_PORT    hadc1

#ifndef __ADC_BASE_H_
#define __ADC_BASE_H_

#ifdef __cplusplus

int ADC_Read(ADC_HandleTypeDef* ADC_Port);

extern "C" {
#endif //__cplusplus

int ADC_Read();

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__ADC_BASE_H_
