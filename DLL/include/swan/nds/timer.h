#ifndef __TIMER_H
#define __TIMER_H

#include "swantypes.h"

STRUCT_DECLARE(TimerCntReg)

struct TimerCntReg {
u16 Scale:2;
u16 Cascade:1;
u16 _NotUsed:3;
u16 IRQEnabled:1;
u16 Start:1;
};

extern volatile u16 TM0CNT_L;

extern volatile TimerCntReg TM0CNT_H;

#endif //__TIMER_H
// Tchaikovsky code generator
