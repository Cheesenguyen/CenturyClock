#include <stdint.h>
#include "../inc/main.h"
#include "../inc/constant.h"
#include "../inc/clock.h"
#include "../inc/cclock.h"
#include "../inc/display.h"

/*
bool CCLOCK_Wait1sSignal();
void CCLOCK_UpdateTime();
void CCLOCK_DisplayClock();
*/

bool CCLOCK_Wait1sSignal(){
    if(g_cycle_1s_count == CYCLE_1S_WAIT){
        g_cycle_1s_count = 0;
        g_1s_signal = true;
    }
    else{
        g_cycle_1s_count += 1;
    }
}

void CCLOCK_UpdateTime(){
    if(g_1s_signal == true){
        g_1s_signal = false;
        b_clock_overflow = CLOCK_IncreaseOneSecond();           // b_clock_overflow bieens return o ham khac
        if(b_clock_overflow == false){
            b_clock_overflow = CLOCK_IncreaseOneMinute();
            if(b_clock_overflow == false){
                b_clock_overflow = CLOCK_IncreaseOneHour();
                if(b_clock_overflow == false){
                    b_clock_overflow = CLOCK_IncreaseOneDay(g_clock_month, g_clock_year);
                    if(b_clock_overflow == false){
                        CLOCK_IncreaseOneYear();
                    }
                }
            }
        }
    }
}

void CCLOCK_DisplayClock(){
    DISPLAY_DisplayHour();
    DISPLAY_DisplayMinute();
    DISPLAY_DisplaySecond();
    DISPLAY_DisplayDay();
    DISPLAY_DisplayMonth();
    DISPLAY_DisplayYear();
}