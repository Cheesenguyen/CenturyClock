#include <stdint.h>
#include "../inc/main.h"
#include "../inc/constant.h"
#include "../inc/display.h"

/*
void DISPLAY_DisplaySecond();
void DISPLAY_DisplayMinute();
void DISPLAY_DisplayHour();
void DISPLAY_DisplayDay();
void DISPLAY_DisplayMonth();
void DISPLAY_DisplayYear();
void DISPLAY_DisplayNumber(int number, int position_x, int position_y, int display_width, uint32_t color);
*/

void DISPLAY_DisplaySecond(){
    DISPLAY_DisplayNumber(g_clock_second, POS_SS_X, POS_SS_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}
void DISPLAY_DisplayMinute(){
    DISPLAY_DisplayNumber(g_clock_minute, POS_MI_X, POS_MI_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}
void DISPLAY_DisplayHour(){
    DISPLAY_DisplayNumber(g_clock_hour, POS_HH_X, POS_HH_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}
void DISPLAY_DisplayDay(){
    DISPLAY_DisplayNumber(g_clock_day, POS_DD_X, POS_DD_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}
void DISPLAY_DisplayMonth(){
    DISPLAY_DisplayNumber(g_clock_month, POS_MO_X, POS_MO_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);  
}
void DISPLAY_DisplayYear(){
    DISPLAY_DisplayNumber(g_clock_year, POS_YY_X, POS_YY_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

void DISPLAY_DisplayNumber(int number, int position_x, int position_y, int display_width, uint32_t color){
    int x = position_x + (FONT_WIDTH + 1) * (display_width - 1); 
    int y = position_y;
    while(display_width != 0){
        int digit = number % 10;
        int number = number / 10;
        LEDMATRIX_DisplayDigit(digit, x, y, color);
        x = x - (FONT_WIDTH + 1); 
        display_width = display_width - 1;
    }
}