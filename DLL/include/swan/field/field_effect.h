#ifndef __FIELD_EFFECT_H
#define __FIELD_EFFECT_H

#include "swantypes.h"

STRUCT_DECLARE(FieldEffects)
STRUCT_DECLARE(FieldEffectHandle)
STRUCT_DECLARE(FieldEffectTCBStore)
STRUCT_DECLARE(FieldTerrainEffectTCB)

typedef void (*FieldTerrainEffectTCBFunc)(FieldTerrainEffectTCB* tcb, void* data);

#include "gfl/core/gfl_tcb.h"
#include "gfl/fs/gfl_archive.h"
#include "field/fieldmap.h"
#include "gfl/core/gfl_heap.h"
#include "math/vector.h"

struct FieldEffects
{
    u32 EffectCapacity;
    HeapID m_HeapID;
    u16 _padHeapID;
    Field* m_Field;
    ArcTool* EffectArc;
    FieldEffectHandle* m_EffectHandles;
    u16 TCBLimit;
    u8 Season;
    u8 AreaIsExterior;
    void* TCBManagerAlloc;
    TCBManager* m_TCBManager;
    FieldEffectTCBStore* m_TCBStore;
    u8* m_LuminanceTable;
};

struct FieldEffectHandle
{
    u32 EffectID;
    void* Data;
};

struct FieldEffectTCBStore
{
    u32 Capacity;
    HeapID m_HeapID;
    u16 _padHeapID;
    FieldTerrainEffectTCB* m_TCBHeap;
    TCBManager* m_TCBManager;
    FieldEffects* m_FieldFX;
};

struct FieldTerrainEffectTCB
{
    u32 IsUsed;
    u32 field_4;
    void* InitParam;
    VecFx32 Pos;
    u8 Data[160];
    u32 field_B8;
    FieldTerrainEffectTCBFunc InitFunc;
    FieldTerrainEffectTCBFunc EndFunc;
    FieldTerrainEffectTCBFunc UpdateFunc;
    FieldTerrainEffectTCBFunc DrawFunc;
    FieldEffectTCBStore* m_TCBStore;
    TCB* BaseTCB;
};

#endif //__FIELD_EFFECT_H
// Tchaikovsky code generator
