#include <stdint.h>
#include <stdbool.h>
#include "cclock.h"
#include "main.h"
#include "constant.h"
#include "clock.h"
#include "display.h"


/**
  * @brief  Generates a 1-second signal based on the cycle counter
  * @param  none
  * @retval true: one second has elapsed (signal generated)
  * @retval false: not yet one second
  */
bool CCLOCK_Wait1sSignal(){
    if(g_cycle_1s_count == CYCLE_1S_WAIT){
        g_cycle_1s_count = 0;
        g_1s_signal = true;
        return true;
    }
    else{
        g_cycle_1s_count += 1;
        return false;
    }
}

/**
  * @brief  Updates the clock time when a 1-second signal is received, cascading overflow from seconds up to years
  * @param  none
  * @retval none
  */
void CCLOCK_UpdateTime() {
    if (g_1s_signal == true) {
        g_1s_signal = false;

        bool b_clock_overflow = CLOCK_IncreaseOneSecond();
        if (b_clock_overflow == true) {
            b_clock_overflow = CLOCK_IncreaseOneMinute();
            if (b_clock_overflow == true) {
                b_clock_overflow = CLOCK_IncreaseOneHour();
                if (b_clock_overflow == true) {
                    b_clock_overflow = CLOCK_IncreaseOneDay(g_clock_month, g_clock_year);
                    if (b_clock_overflow == true) {
                        b_clock_overflow = CLOCK_IncreaseOneMonth();
                        if (b_clock_overflow == true) {
                            CLOCK_IncreaseOneYear();
                        }
                    }
                }
            }
        }
    }
}

/**
  * @brief  Displays the complete clock on the LED matrix by drawing hour, minute, second, day, month, and year
  * @retval none
  */
void CCLOCK_DisplayClock(){
    DISPLAY_DisplayHour();
    DISPLAY_DisplayMinute();
    DISPLAY_DisplaySecond();
    DISPLAY_DisplayDay();
    DISPLAY_DisplayMonth();
    DISPLAY_DisplayYear();

}