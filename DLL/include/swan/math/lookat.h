#ifndef __LOOKAT_H
#define __LOOKAT_H

#include "swantypes.h"

STRUCT_DECLARE(FxLookAt)

SWAN_CPPTYPE_EX(math, LookAt, FxLookAt)

#include "math/fixed.h"

struct FxLookAt
{
    VecFx32 Position;
    VecFx32 UpVector;
    VecFx32 Target;
};

#endif //__LOOKAT_H
// Tchaikovsky code generator
