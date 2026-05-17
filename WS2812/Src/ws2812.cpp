/**
 * @file    ws2812.cpp
 * @author  Cucumber
 * @brief   对WS2812灯的控制库
 * @version 0.1
 * @date 2  026-05-23
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

#include "ws2812.h"
#include "time.h"

#define WS2812_SET()    (LED_Port->BSRR = LED_PIN)                                      // 对应引脚输出高电
#define WS2812_RESET()  (LED_Port->BSRR = (uint32_t)LED_PIN << 16)                      // 对应引脚输出低电平 ?
#define delay_nops_(n)  do { for (volatile int i = 0; i < n; i++) __NOP(); } while(0)   // 大约每个nop占用一个时钟周期

// ==================== 小灯控制底层 ====================

/**
 * @brief 发送单个bit (0或1)
 * @param bit   单一信号
 */
static void WS2812_SendBit(uint8_t bit) {
    // __disable_irq();
    if (bit == 1) {     // 发送逻辑"1": 高电平约800ns
        WS2812_SET();
        delay_nops_(56);   // 约800ns
        WS2812_RESET();
        delay_nops_(32);   // 约450ns
    } else {            // 发送逻辑"0": 高电平约400ns
        WS2812_SET();
        delay_nops_(28);   // 约400ns
        WS2812_RESET();
        delay_nops_(60);   // 约850ns
    }
    // __enable_irq();
}

/**
 * @brief 发送一个字节的数据 (注意顺序)
 * @param byte  字节信号
 */
static void WS2812_SendByte(uint8_t byte) {
    for (int8_t i = 7; i >= 0; i--)     // 高位先发
        WS2812_SendBit((byte >> i) & 0x01);
}

/**
 * @brief 发送单个小灯控制的信号
 * 
 * @param r     红色
 * @param g     绿色
 * @param b     蓝色
 */
void WS2812Set(uint8_t r, uint8_t g, uint8_t b) {
    // 必须按 绿(G)->红(R)->蓝(B) 的顺序发送
    WS2812_SendByte(g);
    WS2812_SendByte(r);
    WS2812_SendByte(b);
}



extern "C" {

void WS2812Set_(uint8_t r, uint8_t g, uint8_t b) { WS2812Set(r, g, b); }
void WS2812_Test() {
    // 发送一个大于50us的低电平复位信号
    HAL_GPIO_WritePin(LED_Port, LED_PIN, GPIO_PIN_RESET);
    HAL_Delay(1);

    WS2812Set(255, 255,255);
    WS2812Set(0, 0, 0);
    // WS2812Set(0, 0, 0);
    // WS2812Set(0, 0, 0);

    // 发送一个大于50us的低电平复位信号
    HAL_GPIO_WritePin(LED_Port, LED_PIN, GPIO_PIN_RESET);
    HAL_Delay(1);
}

}