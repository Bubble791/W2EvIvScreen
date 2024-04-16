#ifndef __GLOBAL_H
#define __GLOBAL_H

#include "swan/swantypes.h"
#include "nds/mem.h"
#include "data/arcid_def.h"
#include "swan/math/fixed.h"
#include "swan/pml/poke_party.h"
#include "swan/gfl/core/gfl_heap.h"
#include "swan/system/game_data.h"
#include "swan/save/savedata_eventwork.h"

enum
{
    FX32_INT_SIZE = 19,
    FX32_DEC_SIZE = 12,
    FX32_SHIFT = FX32_DEC_SIZE,

    FX32_DEC_MASK = ((1 << FX32_SHIFT) - 1),
};

#define FX32_CONST(x)    ((fx32)(((x) > 0) ? \
                                     ((x) * (1 << FX32_SHIFT) + 0.5f ) : \
                                     ((x) * (1 << FX32_SHIFT) - 0.5f )))

#endif