#ifndef __FIELD_STATUS_H
#define __FIELD_STATUS_H

#include "swantypes.h"

STRUCT_DECLARE(FieldStatus)

ENUM_DECLARE(FieldStatusBusyFlag)
ENUM_DECLARE(FlashPermsFlag)

enum FieldStatusBusyFlag
#ifdef __cplusplus
: u32
#endif
{
    FLD_STATUS_BUSY_NONE = 0x0,
    FLD_STATUS_BUSY_BATTLE = 0x1,
    FLD_STATUS_BUSY_LOADING = 0x2,
};

enum FlashPermsFlag
#ifdef __cplusplus
: u32
#endif
{
    FLD_FLASH_NONE = 0x0,
    FLD_FLASH_ALLOW = 0x1,
    FLD_FLASH_ACTIVE = 0x2,
};

struct FieldStatus
{
    int field_0;
    u8 NewLoadFlag;
    u8 ContinueFlag;
    u8 IsFlashUsed;
    char field_7;
    u16 FlashPerms;
    __int16 field_A;
    int field_C;
    char field_10;
    u8 BusyFlag;
    u16 ReserveSCRID;
};

#endif //__FIELD_STATUS_H
// Tchaikovsky code generator
