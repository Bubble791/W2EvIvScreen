#ifndef __BTL_RESULT_H
#define __BTL_RESULT_H

#include "swantypes.h"

ENUM_DECLARE(BattleResult)

enum BattleResult
#ifdef __cplusplus
: u32
#endif
{
    BTL_RESULT_DEFEAT = 0x0,
    BTL_RESULT_VICTORY = 0x1,
    BTL_RESULT_DRAW = 0x2,
    BTL_RESULT_FLEE = 0x3,
    BTL_RESULT_FLEE_FOE = 0x4,
    BTL_RESULT_CAPTURE = 0x5,
    BTL_RESULT_6 = 0x6,
};
SWAN_CPPTYPE_EX(battle, Result, BattleResult)

#endif //__BTL_RESULT_H
// Tchaikovsky code generator
