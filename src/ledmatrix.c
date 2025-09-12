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
    const uint8_t * const *p_row = g_p_font_digit + digit;

    while(height > 0){
        height = height - 1;
        p_row = p_row + FONT_WIDTH;
        LEDMATRIX_DisplayRow(*p_row, FONT_WIDTH, x, y, color);
    }
}

void LEDMATRIX_DisplayRow(const uint8_t *row, int width, int x, int y, uint32_t color){
    while (1)
    {
        int width = width - 1;
        if(width >= 0){
            if((*row) & (0x1 << width) == 1){
                LEDMATRIX_DisplayPixel(x, y, color);
            }
            else{
                LEDMATRIX_DisplayPixel(x, y, COLOR_BACKGROUND);
            }

        }
        x = x + 1;
    }
}

void LEDMATRIX_DisplayPixel(int x, int y, uint32_t color){
    int position = (x << 16) | y;
    ECALL_100 (position, color);
}

