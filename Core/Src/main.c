/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "adc.h"
#include "dma.h"
#include "i2c.h"
#include "tim.h"
#include "gpio.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "oled.h"
#include "font.h"
#include "ws2812.h"
// #include "ws2812_DMA.h"
#include "LDR.h"
#include "IR_sensor.h"
#include <stdio.h>
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
#define READ_KEY1     HAL_GPIO_ReadPin(KEY1_GPIO_Port, KEY1_Pin)==GPIO_PIN_RESET
#define READ_KEY2     HAL_GPIO_ReadPin(KEY2_GPIO_Port, KEY2_Pin)==GPIO_PIN_RESET
#define READ_KEY3     HAL_GPIO_ReadPin(KEY3_GPIO_Port, KEY3_Pin)==GPIO_PIN_RESET
#define READ_KEY4     HAL_GPIO_ReadPin(KEY4_GPIO_Port, KEY4_Pin)==GPIO_PIN_RESET
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{

  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_DMA_Init();
  MX_I2C2_Init();
  MX_ADC1_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */

  // oled.h
  OLED_Init_();

  // WS2812_Update_();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */

  WS2812_Test();

  uint8_t mode = 3;                   // Mode 3, 全亮, Mode 0 减3度
  char mode_str[10] = "";             // 模式显示
  char brightness_str[20] = "";       // 光强显示

  while (1)
  {
    // 光强读取
    uint16_t brightness = VoltageRead_();

    // 按键读取
    if(READ_KEY1 || READ_KEY2 || READ_KEY3 || READ_KEY4) {
      
      if (READ_KEY1 && mode > 0)     // 亮度减弱
        mode--;
      if (READ_KEY2 && mode < 3)     // 亮度增强
        mode++;
      
      if (READ_KEY3) {                // 预备按键

      }
      if (READ_KEY4) {                // 预备按键

      }

      HAL_Delay(200);
    }

    // OLED显示

    sprintf(mode_str, "Mode: %d", mode);
    sprintf(brightness_str, "Brightness: %d", brightness);

    OLED_NewFrame_();
    OLED_PrintString_(80, 0, "=SRPT_SMARTLED=", &font16x16, 0);
    OLED_PrintString_(0, 16, mode_str, &font16x16, 0);
    OLED_PrintString_(0, 32, brightness_str, &font16x16, 0);
    OLED_ShowFrame_();

    // 小灯控制
    if (IR_Read_()) {   // 检测到物体, 根据光强和模式设置小灯亮度

      // 发送一个大于50us的低电平复位信号
      HAL_GPIO_WritePin(LED_Port, LED_PIN, GPIO_PIN_RESET);
      HAL_Delay(1);

      float brightness_basic = brightness / (3.3f/5.0f);
      uint8_t brightness_WS = (uint8_t)(brightness_basic) + mode;
      uint16_t light_bri = 2^brightness_WS;
      if (light_bri > 255) light_bri = 255;       // 防止溢出

      WS2812Set_(light_bri, light_bri, light_bri);
      WS2812Set_(light_bri, light_bri, light_bri);
      WS2812Set_(light_bri, light_bri, light_bri);
      WS2812Set_(light_bri, light_bri, light_bri);
    
      // 发送一个大于50us的低电平复位信号
      HAL_GPIO_WritePin(LED_Port, LED_PIN, GPIO_PIN_RESET);
      HAL_Delay(1);

    } else {            // 没有检测到物体, 关闭小灯

      // 发送一个大于50us的低电平复位信号
      HAL_GPIO_WritePin(LED_Port, LED_PIN, GPIO_PIN_RESET);
      HAL_Delay(1);

      WS2812Set_(0, 0, 0);
      WS2812Set_(0, 0, 0);
      WS2812Set_(0, 0, 0);
      WS2812Set_(0, 0, 0);

      // 发送一个大于50us的低电平复位信号
      HAL_GPIO_WritePin(LED_Port, LED_PIN, GPIO_PIN_RESET);
      HAL_Delay(1);
    }
    
    // 延迟然后进下一循环
    HAL_Delay(100);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};
  RCC_PeriphCLKInitTypeDef PeriphClkInit = {0};

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSE;
  RCC_OscInitStruct.HSEState = RCC_HSE_ON;
  RCC_OscInitStruct.HSEPredivValue = RCC_HSE_PREDIV_DIV1;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSE;
  RCC_OscInitStruct.PLL.PLLMUL = RCC_PLL_MUL9;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_ADC;
  PeriphClkInit.AdcClockSelection = RCC_ADCPCLK2_DIV6;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    Error_Handler();
  }
}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}
#ifdef USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
