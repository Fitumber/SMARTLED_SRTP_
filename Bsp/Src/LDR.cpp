/**
 * @file    LDR.cpp
 * @author  Cucumber
 * @brief   光敏电阻的控制库
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

#include "adc_base.h"
#include "LDR.h"

static float Voltage_sys = 3.3f;         // 系统电压

/**
 * @brief 计算光敏电阻的电压
 * 
 * @return float 电压值
 */
float VoltageRead() {

    int value = ADC_Read();
    float voltage = (value/4095.0f)*Voltage_sys;

    return voltage;

}

/**
 * @brief 计算光照强度 
 * 
 * @param   voltage     光敏电阻两侧的电势差
 * @return  float       光照强度
 */
float Voltage2Illumination(float voltage) {
    // 这里可以根据实际的电路连接和光敏电阻的特性来计算光照强度
    // 例如，如果使用了一个简单的分压电路，可以使用以下公式：
    // Illumination = (Vcc * adcValue) / (4095 - adcValue)
    // 其中 Vcc 是系统电压，4095 是 ADC 的最大值（12 位 ADC）
    float illumination = (Voltage_sys * voltage) / (Voltage_sys - voltage); // 简单的分压计算
    return illumination;
}

extern "C" {

float VoltageRead_() { return VoltageRead(); }
float Voltage2Illumination_(float voltage) { return Voltage2Illumination(voltage); }

}