#ifndef DISPLAY_H
#define DISPLAY_H

#include <stdint.h>
#include "../inc/main.h"
#include "../inc/constant.h"
#include "../inc/ledmatrix.h"

void DISPLAY_DisplaySecond();
void DISPLAY_DisplayMinute();
void DISPLAY_DisplayHour();
void DISPLAY_DisplayDay();
void DISPLAY_DisplayMonth();
void DISPLAY_DisplayYear();
void DISPLAY_DisplayNumber(int number, int position_x, int position_y, int display_width, uint32_t color);


#endif
