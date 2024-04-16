#ifndef __FIELD_SUBSCREEN_H
#define __FIELD_SUBSCREEN_H

#include "swantypes.h"

STRUCT_DECLARE(FieldSubscreen)

ENUM_DECLARE(FieldSubscreenID)
ENUM_DECLARE(FieldSubscreenState)

typedef void (*FieldSubscreenCallback)(void* data);

enum FieldSubscreenID
#ifdef __cplusplus
: u32
#endif
{
    FLD_SUBSCREEN_ID_DEFAULT = 0x0,
    FLD_SUBSCREEN_ID_FIELD_MENU = 0x1,
    FLD_SUBSCREEN_ID_UNION_ROOM_STANDBY = 0x2,
    FLD_SUBSCREEN_ID_BLANK_STANDBY = 0x3,
    FLD_SUBSCREEN_ID_ENTRALINK = 0x4,
    FLD_SUBSCREEN_ID_BLANK_STANDBY_2 = 0x5,
    FLD_SUBSCREEN_ID_DOWSING = 0x6,
    FLD_SUBSCREEN_ID_SAVE_REPORT = 0x7,
    FLD_SUBSCREEN_ID_CGEAR_WELCOME = 0x8,
    FLD_SUBSCREEN_ID_CGEAR_POWEROFF = 0x9,
    FLD_SUBSCREEN_ID_FUNFEST = 0xA,
    FLD_SUBSCREEN_ID_PWT = 0xB,
    FLD_SUBSCREEN_ID_12 = 0xC,
    FLD_SUBSCREEN_ID_MAX = 0xD,
};

enum FieldSubscreenState
#ifdef __cplusplus
: u32
#endif
{
    FLD_SUBSCREEN_STATE_IDLE = 0x0,
    FLD_SUBSCREEN_STATE_FADE_OUT_SET = 0x1,
    FLD_SUBSCREEN_STATE_SWAP = 0x2,
    FLD_SUBSCREEN_STATE_FADE_IN_SET = 0x3,
    FLD_SUBSCREEN_STATE_NEW_ENTER_WAIT = 0x4,
    FLD_SUBSCREEN_STATE_MAX = 0x5,
};

#include "gfl/core/gfl_heap.h"
#include "field/fieldmap.h"

struct FieldSubscreen
{
    FieldSubscreenID ScreenID;
    FieldSubscreenID NextScreenID;
    FieldSubscreenState State;
    HeapID m_HeapID;
    u16 _padHeapID;
    FieldSubscreenID ReturnSubscreenID;
    Field* m_Field;
    FieldSubscreenCallback* Callback;
    void* CallbackData;
    void* WorkData;
};

#endif //__FIELD_SUBSCREEN_H
// Tchaikovsky code generator
