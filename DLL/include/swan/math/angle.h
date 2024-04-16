#ifndef __ANGLE_H
#define __ANGLE_H

#include "swantypes.h"

#define FX_ANGLE_DEG(value) ((fxangle)((value) * 65535.0f / 360.0f))
#define FX_ANGLE_RAD(value) ((fxangle)((value) * 65535.0f / 3.1415926f))

STRUCT_DECLARE(SinCosEntry)

typedef u16 fxangle;

#include "math/fixed.h"

C_DECL_BEGIN

extern fxangle fx_acos(fx32 cos);
extern fxangle fx_atan2(fx32 x, fx32 y);

C_DECL_END

struct SinCosEntry
{
    fx16 Sin;
    fx16 Cos;
};

extern SinCosEntry FX_SIN_COS_TABLE[4096];

#endif //__ANGLE_H
// Tchaikovsky code generator
