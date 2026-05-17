/**
 * @file    adc_base.cpp
 * @author  Cucumber
 * @brief   ADC控制库
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

#include "adc_base.h"
#include "adc.h"
#include "main.h"
#include "stm32f103xb.h"

int ADC_Read(ADC_HandleTypeDef* ADC_Port) {
    HAL_ADC_Start(ADC_Port);
    HAL_ADC_PollForConversion(ADC_Port, HAL_MAX_DELAY);
    return HAL_ADC_GetValue(ADC_Port);
}

extern "C" {

int ADC_Read() { return ADC_Read(&ADC_PORT); }

}
