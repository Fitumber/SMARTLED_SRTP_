/**
 * @brief Oled屏幕控制库
 * @note Code Mostly From keysking
 */

/*
 ____                                             |
/    \           ___            ___    __    __   | ___    ___     __
|       |    |  /   \  |    |  /   \  /  \  /  \  |/   \  /   \  |/
|       |    |  |      |    |  |      |   \/   |  |    |  |---/  | 
\____/  \____/  \___/  \____/  \___/  |        |  \____/  \____  |
                        -Cucumber-
*/

#ifndef __OLED_H_
#define __OLED_H_

#include "main.h"
#include "font.h"
#include "string.h"

typedef enum {
  OLED_COLOR_NORMAL = 0, // 正常模式 黑底白字
  OLED_COLOR_REVERSED    // 反色模式 白底黑字
} OLED_ColorMode;

#define i2c_Port hi2c2

#ifdef __cplusplus

#define OLED_ADDRESS 0x78

// OLED参数
#define OLED_PAGE 8            // OLED页数
#define OLED_ROW 8 * OLED_PAGE // OLED行数
#define OLED_COLUMN 128        // OLED列数

// 显存
extern uint8_t OLED_GRAM[OLED_PAGE][OLED_COLUMN];

//函数声明
void OLED_SendCmd(uint8_t cmd);   /* 发送指令的函数 */
void OLED_Send(uint8_t *data, uint8_t len); /* 发送数据的函数 */
void OLED_Init();  /* OLED初始化函数 */
void OLED_Test();  /* OLED测试函数 */

void OLED_DisPlay_On(void);   /* 打开显示 */
void OLED_DisPlay_Off(void);  /* 关闭显示 */
void OLED_NewFrame();   /* 清空显存 绘制新的一帧 */
void OLED_ShowFrame();  /* 将当前显存显示到屏幕上 */

void OLED_SetPixel(uint8_t x, uint8_t y, OLED_ColorMode color); /* 设置一个像素点 */
void OLED_SetByte_Fine(uint8_t page, uint8_t column, uint8_t data, uint8_t start, uint8_t end, OLED_ColorMode color);   /* 设置显存中一字节数据的某几位 */
void OLED_SetByte(uint8_t page, uint8_t column, uint8_t data, OLED_ColorMode color);    /* 设置显存中一字节数据 */
void OLED_SetBits_Fine(uint8_t x, uint8_t y, uint8_t data, uint8_t len, OLED_ColorMode color);  /* 设置显存中一字节长度的数据的某几位 */
void OLED_SetBits(uint8_t x, uint8_t y, uint8_t data, OLED_ColorMode color);    /* 设置显存中一字节长度的数据 */
void OLED_SetBlock(uint8_t x, uint8_t y, const uint8_t *data, uint8_t w, uint8_t h, OLED_ColorMode color);  /* 设置一块显存区域 */

void OLED_DrawLine(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_ColorMode color);   /* 绘制一条线段 */
void OLED_DrawRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);  /* 绘制一个矩形 */
void OLED_DrawFilledRectangle(uint8_t x, uint8_t y, uint8_t w, uint8_t h, OLED_ColorMode color);    /* 绘制一个填充矩形 */
void OLED_DrawTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, OLED_ColorMode color);   /* 绘制一个三角形 */
void OLED_DrawFilledTriangle(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, uint8_t x3, uint8_t y3, OLED_ColorMode color);  /* 绘制一个填充三角形 */
void OLED_DrawCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);    /* 绘制一个圆 */
void OLED_DrawFilledCircle(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);  /* 绘制一个填充圆 */
void OLED_DrawBitmap(uint8_t x, uint8_t y, const uint8_t *data, uint8_t w, uint8_t h, OLED_ColorMode color);    /* 绘制一个位图 */
void OLED_DrawEllipse(uint8_t x, uint8_t y, uint8_t a, uint8_t b, OLED_ColorMode color);    /* 绘制一个椭圆 */

void OLED_DrawImage(uint8_t x, uint8_t y, const Image *img, OLED_ColorMode color);  /* 绘制一个图片 */
void OLED_PrintString(uint8_t x, uint8_t y, char *str, const Font *font, OLED_ColorMode color);   /* 打印字符串 */
void OLED_PrintASCIIChar(uint8_t x, uint8_t y, char c, const Font *font, OLED_ColorMode color);   /* 打印一个ASCII字符 */
uint8_t _OLED_GetUTF8Len(char *str);    /* 获取一个UTF-8编码的字符的字节长度 */

extern "C" {
#endif  //__cplusplus

    void OLED_SendCmd_(uint8_t cmd);
    void OLED_Send_(uint8_t *data, uint8_t len);
    void OLED_Init_(void);
    void OLED_Test_(void);

    void OLED_DisPlay_On_(void);
    void OLED_DisPlay_Off_(void);

    void OLED_NewFrame_(void);
    void OLED_ShowFrame_(void);

    void OLED_DrawLine_(uint8_t x1, uint8_t y1, uint8_t x2, uint8_t y2, OLED_ColorMode color);
    void OLED_DrawCircle_(uint8_t x, uint8_t y, uint8_t r, OLED_ColorMode color);

    void OLED_PrintASCIIChar_(uint8_t x, uint8_t y, char c, const Font *font, OLED_ColorMode color);
    void OLED_PrintString_(uint8_t x, uint8_t y, char *str, const Font *font, OLED_ColorMode color);



#ifdef __cplusplus
}
#endif  //__cplusplus

#endif  //__OLED_H_