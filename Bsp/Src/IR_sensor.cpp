/**
 * @file    IR_sensor.cpp
 * @author  Cucumber
 * @brief   控制红外传感器的库的源文件
 * @version 0.1
 * @date    2026-06-11
 * 
 * @copyright Copyright (c) 2026
 *
 ____                                             |
/    \           ___            ___    __    __   | ___    ___     __
|       |    |  /   \  |    |  /   \  /  \  /  \  |/   \  /   \  |/
|       |    |  |      |    |  |      |   \/   |  |    |  |---/  | 
\____/  \____/  \___/  \____/  \___/  |        |  \____/  \____  |
                        -Cucumber- 
 * 
 */

#include "IR_sensor.h"

/**
 * @brief 读取红外传感器的值
 * @return 有物体时返回true
 * @return 无物体时返回false
 */
bool IR_Read() {
  if (HAL_GPIO_ReadPin(IR_PORT, IR_PIN) == GPIO_PIN_RESET) {
    return true;    // 检测到物体
  } else {
    return false;   // 没有检测到物体
  }
}

extern "C" {
    
bool IR_Read_() { return IR_Read(); }

}