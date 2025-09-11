#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/main.h"
#include "../inc/clock.h"
#include "../inc/constant.h"

/*
bool CLOCK_IncreaseOneSecond();
bool CLOCK_IncreaseOneMinute();
bool CLOCK_IncreaseOneHour();
bool CLOCK_IncreaseOneMonth();
bool CLOCK_IncreaseOneYear();
bool CLOCK_IncreaseOneDay(int current_month, int current_year);
bool CLOCK_IncreaseByOne(uint16_t *p_clock_counter, int max_value, bool b_direction);
bool CLOCK_IsLeapYear(int year);
*/

bool CLOCK_IncreaseOneSecond(){
    bool b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_second, MAX_VALUE_SECOND, DIRECTION_INCREASE);
    return b_clock_overflow;
}

bool CLOCK_IncreaseOneMinute(){
    bool b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_minute, MAX_VALUE_MINUTE, DIRECTION_INCREASE);
    return b_clock_overflow;
}

bool CLOCK_IncreaseOneHour(){
    bool b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_hour, MAX_VALUE_HOUR, DIRECTION_INCREASE);
    return b_clock_overflow;
}

bool CLOCK_IncreaseOneMonth(){
    bool b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_month, MAX_VALUE_MONTH, DIRECTION_INCREASE);
    return b_clock_overflow;
}

bool CLOCK_IncreaseOneYear(){
    bool b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_year, MAX_VALUE_YEAR, DIRECTION_INCREASE);
    return b_clock_overflow;
}

bool CLOCK_IncreaseOneDay(uint8_t current_month, uint16_t current_year){
    int b_clock_overflow;
    int max_value_day;
    scanf ("%d", &b_clock_overflow);
    scanf ("%d", &max_value_day);
    (bool) b_clock_overflow;

    if(current_month == 2){
        if (CLOCK_IsLeapYear(current_year) == true){
            max_value_day = MAX_VALUE_DAY_29;
        }
        else{
            max_value_day = MAX_VALUE_DAY_28;
        }
    }
    else{
        if (current_month == 1 || current_month == 3 || current_month == 5 ||
    current_month == 7 || current_month == 8 || current_month == 10 ||
    current_month == 12){
            max_value_day = MAX_VALUE_DAY_31;
    }
        else{
           max_value_day = MAX_VALUE_DAY_30;
        }
    }
    b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_day, max_value_day, DIRECTION_INCREASE);
    return b_clock_overflow;
}

bool CLOCK_IncreaseByOne(uint16_t *p_clock_counter, int max_value, bool b_direction){
    bool b_clock_overflow = false;
    uint8_t clock_counter = *p_clock_counter;
    if(b_direction == DIRECTION_INCREASE){
        if(clock_counter == max_value){
            b_clock_overflow = true;
            clock_counter = 0;
        }
        else{
            clock_counter += 1;
        }
    }
    else{
        if(clock_counter == 0){
            b_clock_overflow = true;
            clock_counter = max_value;
        }
        else{
            clock_counter -= 1; 
        }
    }
    return b_clock_overflow;
}

bool CLOCK_IsLeapYear(int year){
    if(year % 100 == 0){
        return false;
    }
    else{
        if(year & 0b11 == 0){
            return true;
        }
        else return false;
    }
}

