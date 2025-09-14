#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/main.h"
#include "../inc/clock.h"
#include "../inc/constant.h"
#include "../inc/ecall.h"

/**
  * @brief Increments the second counter by one, checking for overflow
  * @param  none
  * @retval true: second overflowed and wrapped to 0
  * @retval false: second incremented normally
  */
bool CLOCK_IncreaseOneSecond(void){
    return CLOCK_IncreaseByOne(&g_clock_second, MAX_VALUE_SECOND, DIRECTION_INCREASE);
}

/**
  * @brief Increments the minute counter by one, checking for overflow
  * @param  none
  * @retval true: minute overflowed and wrapped to 0
  * @retval false: minute incremented normally
  */
bool CLOCK_IncreaseOneMinute(void){
    return CLOCK_IncreaseByOne(&g_clock_minute, MAX_VALUE_MINUTE, DIRECTION_INCREASE);
}

/**
  * @brief Increments the hour counter by one, checking for overflow
  * @param  none
  * @retval true: hour overflowed and wrapped to 0
  * @retval false: hour incremented normally
  */
bool CLOCK_IncreaseOneHour(void){
    return CLOCK_IncreaseByOne(&g_clock_hour, MAX_VALUE_HOUR, DIRECTION_INCREASE);
}

/**
  * @brief  Increments the month counter by one, checking for overflow
  * @param  none
  * @retval true: month overflowed and wrapped to 0
  * @retval false: moth incremented normally
  */
bool CLOCK_IncreaseOneMonth(void){
    return CLOCK_IncreaseByOne(&g_clock_month, MAX_VALUE_MONTH, DIRECTION_INCREASE);
}

/**
  * @brief  Increments the year counter by one, checking for overflow
  * @param  none
  * @retval true: year overflowed and wrapped to 0
  * @retval false: year incremented normally
  */
bool CLOCK_IncreaseOneYear(void){
    return CLOCK_IncreaseByOne(&g_clock_year, MAX_VALUE_YEAR, DIRECTION_INCREASE);
}

/**
  * @brief Increases the day counter by one, considering the current month and year
  * @param  curren_month: the current month (1–12)
  * @param  curren_year: the current year
  * @retval true: day overflow occurred (reset to 1, next month should be incremented)
  * @retval false: day incremented normally within the same month
  */
bool CLOCK_IncreaseOneDay(uint8_t current_month, uint16_t current_year){
    int max_value_day;

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
    //b_clock_overflow = CLOCK_IncreaseByOne(&g_clock_day, max_value_day, DIRECTION_INCREASE);
    return CLOCK_IncreaseByOne(&g_clock_day, max_value_day, DIRECTION_INCREASE);
}

/**
  * @brief  Updates a clock counter by one step (increase or decrease) and checks for overflow/underflow 
  * @param  p_clock_counter: pointer to the counter value (second, minute, hour, etc.)
  * @param  max_value: maximum valid value for the counter
  * @param  b_direction: operation direction (increase or decrease)
  * @retval true: counter overflowed/underflowed
  * @retval false: counter updated without overflow
  */
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
    *p_clock_counter = clock_counter;
    return b_clock_overflow;
}

/**
  * @brief  Check is the year is leap or not
  * @param  year: the year being displayed 
  * @retval true: the given year is a leap year.
  * @retval false: the given year is not a leap year
  */
bool CLOCK_IsLeapYear(int year){
    if ((year % 400) == 0) return true;
    if ((year % 100) == 0) return false;
    if ((year % 4) == 0)   return true;
    return false;
}


