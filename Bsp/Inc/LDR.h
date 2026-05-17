/**
 * @file    LDR.h
 * @author  Cucumber
 * @brief   对光敏电阻的控制的库的头函数
 * @version 0.1
 * @date    2026-05-23

 ____                                             |
/    \           ___            ___    __    __   | ___    ___     __
|       |    |  /   \  |    |  /   \  /  \  /  \  |/   \  /   \  |/
|       |    |  |      |    |  |      |   \/   |  |    |  |---/  | 
\____/  \____/  \___/  \____/  \___/  |        |  \____/  \____  |
                        -Cucumber-

 * 
 * @copyright Copyright (c) 2026
 * 
 */

#ifndef __LDR_H_
#define __LDR_H_

#include "adc_base.h"

#ifdef __cplusplus

float VoltageRead();
float Voltage2Illumination(float voltage);



extern "C" {
#endif //__cplusplus

float VoltageRead_();
float Voltage2Illumination_(float voltage);

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__LDR_H_