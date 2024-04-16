#ifndef __GFL_TRANSFORM_H
#define __GFL_TRANSFORM_H

#include "swantypes.h"

STRUCT_DECLARE(SRTMatrix)

SWAN_CPPTYPE_EX(gfl::g3d, Transform, SRTMatrix)

#include "math/matrix.h"

struct SRTMatrix
{
        VecFx32 Translation;
        VecFx32 Scale;
        Mat3 Rotation;
};

#endif //__GFL_TRANSFORM_H
// Tchaikovsky code generator
