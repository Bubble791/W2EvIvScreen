#ifndef __FIELD_DAYCARE_H
#define __FIELD_DAYCARE_H

#include "swantypes.h"

STRUCT_DECLARE(DayCare)

#include "gfl/core/gfl_heap.h"
#include "field/fieldmap.h"

struct DayCare
{
    HeapID m_HeapID;
    u16 _padHeapID;
    Field* m_Field;
    void* m_DayCareSave;
    u16 EggSpawnCycleCounter;
    u16 _padEggSpawnCycleCounter;
};

#endif //__FIELD_DAYCARE_H
// Tchaikovsky code generator
