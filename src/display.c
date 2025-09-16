#include "display.h"
#include "main.h"
#include "constant.h"

#include <stdint.h>

#include "ledmatrix.h"

/**
  * @brief  display two numbers of second
  * @param  none
  * @retval none
  */
void DISPLAY_DisplaySecond(){
    DISPLAY_DisplayNumber(g_clock_second, POS_SS_X, POS_SS_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

/**
  * @brief  display two numbers of minute
  * @param  none
  * @retval none
  */
void DISPLAY_DisplayMinute(){
    DISPLAY_DisplayNumber(g_clock_minute, POS_MI_X, POS_MI_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

/**
  * @brief  display two numbers of hour
  * @param  none
  * @retval none
  */
void DISPLAY_DisplayHour(){
    DISPLAY_DisplayNumber(g_clock_hour, POS_HH_X, POS_HH_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

/**
  * @brief  display two numbers of day
  * @param  none
  * @retval none
  */
void DISPLAY_DisplayDay(){
    DISPLAY_DisplayNumber(g_clock_day, POS_DD_X, POS_DD_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

/**
  * @brief  display two numbers of month
  * @param  none
  * @retval none
  */
void DISPLAY_DisplayMonth(){
    DISPLAY_DisplayNumber(g_clock_month, POS_MO_X, POS_MO_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);  
}

/**
  * @brief  display two last numbers of year
  * @param  none
  * @retval none
  */
void DISPLAY_DisplayYear(){
    DISPLAY_DisplayNumber(g_clock_year, POS_YY_X, POS_YY_Y, NUMBER_WIDTH_2, COLOR_DEFAULT);
}

/**
  * @brief  displays an integer on the LED matrix by breaking it into digits and drawing them side by side
  * @param  number: the integer to display
  * @param  position_x: x-coordinate of the leftmost digit
  * @param  position_y: y-coordinate of the digits
  * @param  display_width: number of digits to render
  * @param  color: color used to display number
  * @retval none
  */

void DISPLAY_DisplayNumber(int number, int position_x, int position_y, int display_width, uint32_t color){
    int x = position_x + (FONT_WIDTH + 1) * (display_width - 1); 
    int y = position_y;
    while(display_width != 0){
        int digit = number % 10;
        number = number / 10;
        LEDMATRIX_DisplayDigit(digit, x, y, color);
        x = x - (FONT_WIDTH + 1); 
        display_width = display_width - 1;
    }
}