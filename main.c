/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "../inc/constant.h"
#include "../inc/cclock.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdint.h>

/* Global variables ----------------------------------------------------------*/
// Bộ đếm chu kỳ 1s
int g_cycle_1s_count = 0;

// Cờ tín hiệu
bool g_1s_signal = false;
bool g_increase_signal = false;

// Thời gian thực
uint16_t g_clock_second = 0;
uint16_t g_clock_minute = 0;
uint16_t g_clock_hour   = 0;
uint16_t g_clock_day    = 1;
uint16_t g_clock_month  = 1;
uint16_t g_clock_year  = 2000;  

// Font hiển thị chữ số (con trỏ hằng)
const void *g_p_font_digit = NULL;

/* Private includes ----------------------------------------------------------*/

#include "ecall.h"

/*

*/
/* Private typedef -----------------------------------------------------------*/

/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/
void MAIN_Run(void);
void MAIN_Init(void);
void MAIN_Loop(void);
void CCLOCK_DisplayClock(void);
bool CCLOCK_Wait1sSignal(void);
void CCLOCK_UpdateTime(void);

/* Private user code ---------------------------------------------------------*/
void MAIN_Run(void) {
    MAIN_Init();
    MAIN_Loop();
}

void MAIN_Init(void){
    g_clock_second = DEFAULT_SECOND;
    g_clock_minute = DEFAULT_MINUTE;
    g_clock_hour = DEFAULT_HOUR;
    g_clock_day = DEFAULT_DAY;
    g_clock_month = DEFAULT_MONTH;
    g_clock_year = DEFAULT_YEAR;
    g_cycle_1s_count = 0;
    g_1s_signal = false;

    CCLOCK_DisplayClock();
}

void MAIN_Loop(){
    while (1) {
        if (CCLOCK_Wait1sSignal() == true) {
            CCLOCK_UpdateTime();
            CCLOCK_DisplayClock();
        }
    }
}

/**
  * @brief  The application entry point.
  * @retval int
  */

  
int main(void) {
    MAIN_Run();

    return 0;
}

