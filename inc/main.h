#ifndef MAIN_H
#define MAIN_H

#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>


extern int g_cycle_1s_count;

// Cờ tín hiệu
extern bool g_1s_signal;
extern bool g_increase_signal;

// Thời gian thực
extern uint16_t g_clock_second;
extern uint16_t g_clock_minute;
extern uint16_t g_clock_hour;
extern uint16_t g_clock_day;
extern uint16_t g_clock_month;
extern uint16_t g_clock_year; 

// Font hiển thị chữ số (con trỏ hằng)
extern const void *g_p_font_digit;
#endif