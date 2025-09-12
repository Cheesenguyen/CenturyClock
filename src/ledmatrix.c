#include <stdint.h>
#include "../inc/constant.h"
#include "../inc/main.h"
#include "../inc/ecall.h"
#include "../inc/ledmatrix.h"

/*
void LEDMATRIX_DisplayDigit(int digit, int x, int y, uint32_t color);
void LEDMATRIX_DisplayRow(uint8_t row, int width, int x, int y, uint32_t color);
void LEDMATRIX_DisplayPixel(int x, int y, uint32_t color);
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


void LEDMATRIX_DisplayPixel(int x, int y, uint32_t color){
    int position = (x << 16) | y;
    ECALL_100 (position, color);
}

