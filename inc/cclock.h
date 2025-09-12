#ifndef CCLOCK_H
#define CCLOCK_H

// Includes
#include <stdint.h>
#include <stdbool.h>
#include "../inc/main.h"
#include "../inc/constant.h"


bool CCLOCK_Wait1sSignal();
void CCLOCK_UpdateTime();
void CCLOCK_DisplayClock();

#endif /* __CCLOCK_H */
