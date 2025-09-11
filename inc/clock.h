#ifndef CLOCK_H
#define CLOCK_H

#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/main.h"
#include "../inc/clock.h"
#include "../inc/constant.h"

extern bool b_clock_overflow;

bool CLOCK_IncreaseOneSecond();
bool CLOCK_IncreaseOneMinute();
bool CLOCK_IncreaseOneHour();
bool CLOCK_IncreaseOneMonth();
bool CLOCK_IncreaseOneYear();
bool CLOCK_IncreaseOneDay(uint8_t current_month, uint16_t current_year);
bool CLOCK_IncreaseByOne(uint16_t *p_clock_counter, int max_value, bool b_direction);
bool CLOCK_IsLeapYear(int year);

#endif