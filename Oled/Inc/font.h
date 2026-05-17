/**
 * @file font.h
 * @brief 字体和图片数据头文件
 * Code from keysking
 */

/*
 ____                                             |
/    \           ___            ___    __    __   | ___    ___     __
|       |    |  /   \  |    |  /   \  /  \  /  \  |/   \  /   \  |/
|       |    |  |      |    |  |      |   \/   |  |    |  |---/  | 
\____/  \____/  \___/  \____/  \___/  |        |  \____/  \____  |
                        -Cucumber-
*/

#ifndef __FONT_H_
#define __FONT_H_
#include "stdint.h"
#include "string.h"

typedef struct ASCIIFont {
  uint8_t h;
  uint8_t w;
  uint8_t *chars;
} ASCIIFont;

extern const ASCIIFont afont8x6;    // 8*6 ASCII字体
extern const ASCIIFont afont12x6;   // 12*6 ASCII字体
extern const ASCIIFont afont16x8;   // 16*8 ASCII字体
extern const ASCIIFont afont24x12;  // 24*12 ASCII字体

/**
 * @brief 字体结构体
 * @note  字库前4字节存储utf8编码 剩余字节存储字模数据
 * @note 字库数据可以使用波特律动LED取模助手生成(https://led.baud-dance.com)
 */
typedef struct Font {
  uint8_t h;              // 字高度
  uint8_t w;              // 字宽度
  const uint8_t *chars;   // 字库 字库前4字节存储utf8编码 剩余字节存储字模数据
  uint8_t len;            // 字库长度 超过256则请改为uint16_t
  const ASCIIFont *ascii; // 缺省ASCII字体 当字库中没有对应字符且需要显示ASCII字符时使用
} Font;

extern const Font font16x16;  // 包含ASCII字符和部分中文字符的16x16字体

/**
 * @brief 图片结构体
 * @note  图片数据可以使用波特律动LED取模助手生成(https://led.baud-dance.com)
 */
typedef struct Image {
  uint8_t w;           // 图片宽度
  uint8_t h;           // 图片高度
  const uint8_t *data; // 图片数据
} Image;

extern const Image bilibiliImg;
extern const Image bilibiliTVImg;

#ifdef __cplusplus
extern "C" {
#endif
  
  

#ifdef __cplusplus
}
#endif

#endif // __FONT_H_
