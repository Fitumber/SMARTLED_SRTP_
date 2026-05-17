/**
 * @file    ws2812_DMA.cpp
 * @author  Cucumber
 * @brief   使用DMA控制WS2812b小灯的库的实现文件
 * @version 0.1
 * @date    2026-06-10
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

#include "ws2812_DMA.h"

// 宏定义占空比
#define Code0       30
#define Code1       60
#define CodeReset   0


void WS2812_Update() {  
    static uint16_t data[] = {
        Code1, Code1, Code1, Code1, Code1, Code1, Code1, Code1, 
        Code0, Code0, Code0, Code0, Code0, Code0, Code0, Code0,
        Code0, Code0, Code0, Code0, Code0, Code0, Code0, Code0, 

        // Reset信号 
        CodeReset
    };

    HAL_TIM_PWM_Start_DMA(&htim3, TIM_CHANNEL_1, (uint32_t*)data, sizeof(data)/sizeof(uint16_t));

}



extern "C" {

void WS2812_Update_(void) { WS2812_Update(); }

}