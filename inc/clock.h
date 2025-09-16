#ifndef CLOCK_H
#define CLOCK_H

#include <stdbool.h>
#include <stdint.h>

bool CLOCK_IncreaseOneSecond();
bool CLOCK_IncreaseOneMinute();
bool CLOCK_IncreaseOneHour();
bool CLOCK_IncreaseOneMonth();
bool CLOCK_IncreaseOneYear();
bool CLOCK_IncreaseOneDay(uint8_t current_month, uint16_t current_year);
bool CLOCK_IncreaseByOne(uint16_t *p_clock_counter, int max_value, bool b_direction);
bool CLOCK_IsLeapYear(int year);

#endif