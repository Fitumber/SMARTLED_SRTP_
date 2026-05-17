# 智能小灯项目 
该项目为我们的SRTP项目--“基于STM32的智能感应小灯程序”的源码     
使用了HAL库, 利用VScode和CubeMX进行项目构建与编程       
其中OLED的控制库代码来自B站UP主 [**keysking**](https://space.bilibili.com/6100925?spm_id_from=333.337.0.0)

## 现有问题
- 无法控制WS2812b小灯的颜色, 小灯一直为**白光**, 无法更改颜色;

## 使用的模块
1. MCU  - STM32F103C8T6
2. LED  - WS2812b 0807
3. 光敏电阻
4. 红外模块
5. OLED 0.96寸 显示屏