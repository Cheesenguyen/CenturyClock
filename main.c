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
// dữ liệu font 5x8 cho các chữ số 0-9
static const uint8_t font_digit_data[10][FONT_HEIGHT] = {
    {0x0E,0x11,0x13,0x15,0x19,0x11,0x11,0x0E}, // 0
    {0x04,0x0C,0x14,0x04,0x04,0x04,0x04,0x1F}, // 1
    {0x0E,0x11,0x01,0x02,0x04,0x08,0x10,0x1F}, // 2
    {0x0E,0x11,0x01,0x06,0x01,0x01,0x11,0x0E}, // 3
    {0x11,0x11,0x11,0x1F,0x01,0x01,0x01,0x01}, // 4
    {0x1F,0x10,0x10,0x1E,0x01,0x01,0x01,0x1E}, // 5
    {0x0F,0x10,0x10,0x1F,0x11,0x11,0x11,0x0E}, // 6
    {0x1F,0x01,0x01,0x02,0x04,0x04,0x04,0x04}, // 7
    {0x0E,0x11,0x11,0x0E,0x11,0x11,0x11,0x0E}, // 8
    {0x0E,0x11,0x11,0x1F,0x01,0x01,0x11,0x0E}  // 9
};

const uint8_t *g_p_font_digit = &font_digit_data[0][0];


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

