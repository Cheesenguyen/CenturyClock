#include "ledmatrix.h"
#include "main.h"
#include "constant.h"

#include <stdint.h>

#include "ecall.h"

/*
void LEDMATRIX_DisplayDigit(int digit, int x, int y, uint32_t color);
void LEDMATRIX_DisplayRow(uint8_t row, int width, int x, int y, uint32_t color);
void LEDMATRIX_DisplayPixel(int x, int y, uint32_t color);
*/

/**
  * @brief  Display digit as row by using g_p_font_digit array 
  * @param  digit: number wanted to be draw
  * @param  x: horizontal position (column) of the digit’s top-left corner.
  * @param  y: vertical position (row) of the digit’s top-left corner.
  * @param  color: color used to display number
  * @retval none
  */

void LEDMATRIX_DisplayDigit(int digit, int x, int y, uint32_t color){
    int height = FONT_HEIGHT;
    const uint8_t *p_row = g_p_font_digit + digit*FONT_HEIGHT;

    while(height > 0){
        height = height - 1;
        p_row = p_row + 1;
        LEDMATRIX_DisplayRow(*p_row, FONT_WIDTH, x, y, color);
        y = y + 1;
    }
}

/**
  * @brief  Use pixel to display a row
  * @param  row: bitmap data of one horizontal row of the digit, where each bit represents a pixel (1 = on, 0 = off)
  * @param  width: the number of pixels (columns) in the digit row
  * @param  x: horizontal position (column) of the digit’s top-left corner.
  * @param  y: vertical position (row) of the digit’s top-left corner.
  * @param  color: color used to display number
  * @retval none
  */

void LEDMATRIX_DisplayRow(const uint8_t row, int width, int x, int y, uint32_t color){
    for (int i = 0; i < width; i++) {
        // Lấy bit từ MSB sang LSB
        int bit = (row >> (width - 1 - i)) & 0x1;
        if (bit) {
            LEDMATRIX_DisplayPixel(x + i, y, color);
        }else {
            LEDMATRIX_DisplayPixel(x + i, y, COLOR_BACKGROUND);
        }
    }
}

/**
  * @brief  Display each pixel 
  * @param  x: horizontal position (column) of the digit’s top-left corner.
  * @param  y: vertical position (row) of the digit’s top-left corner.
  * @param  color: color used to display number
  * @retval none
  */

void LEDMATRIX_DisplayPixel(int x, int y, uint32_t color){
    int position = (x << 16) | y;
    ECALL_100 (position, color);
}

