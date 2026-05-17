/**
 * @file    ws2812_DMA.h
 * @author  your name (you@domain.com)
 * @brief   使用DMA控制WS2812b小灯的库的头文件
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

#ifndef __WS2812_DWA_H_
#define __WS2812_DWA_H_

#include "main.h"
#include "tim.h"

#ifdef __cplusplus


void WS2812_Update();



extern "C" {
#endif //__cplusplus

void WS2812_Update_(void);  

#ifdef __cplusplus
}
#endif //__cplusplus

#endif //__WS2812_DWA_H_