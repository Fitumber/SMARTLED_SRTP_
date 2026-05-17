/**
 * @file    ws2812.h
 * @author  Cucumber
 * @brief   控制WS2812灯的库的头文件
 * @version 0.1
 * @date    2026-05-23
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

#ifndef __WS2812_H_
#define __WS2812_H_

#include "stm32f1xx_hal.h"

#define LED_Port        GPIOB
#define LED_PIN         GPIO_PIN_0
#define LED_NUM         4
// #define LED_DATALEN     LED_NUM*24

#ifdef __cplusplus

// uint32_t ws2812_buffer[LED_DATALEN];                // 将24位RGB颜色转换为PWM占空比数据的数组

void WS2812Set(uint8_t r, uint8_t g, uint8_t b);   // 将颜色数据转换为占空比数据

extern "C" {
#endif //__cplusplus

void WS2812Set_(uint8_t r, uint8_t g, uint8_t b);   // 将颜色数据转换为占空比数据
void WS2812_Test(void);                             // 测试


#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__WS2812_H_