#ifndef LEDMATRIX_H
#define LEDMATRIX_H

#include <stdint.h>
#include <stdbool.h>

#include "constant.h" 
#include "main.h"
#include "ecall.h"

void LEDMATRIX_DisplayDigit(int digit, int x, int y, uint32_t color);
void LEDMATRIX_DisplayRow(const uint8_t *row, int width, int x, int y, uint32_t color);
void LEDMATRIX_DisplayPixel(int x, int y, uint32_t color);

#endif