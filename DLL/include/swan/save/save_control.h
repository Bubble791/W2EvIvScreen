#ifndef __SAVE_CONTROL_H
#define __SAVE_CONTROL_H

#include "swantypes.h"

STRUCT_DECLARE(SaveControl)

struct SaveControl
{
    u8 Status;
    u8 SaveDataAlreadyPresent;
    u8 byte2;
    u8 field_3[9];
    u32 field_C;
    void* SaveData;
    u32 SaveExtra[21];
    u32 dword68;
};

#endif //__SAVE_CONTROL_H
// Tchaikovsky code generator
