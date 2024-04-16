#ifndef __MAIL_H
#define __MAIL_H

#include "swantypes.h"

STRUCT_DECLARE(MailData)

struct MailData
{
    u32 TID;
    u8 TrainerGender;
    u8 Region;
    u8 GameVersion;
    u8 byte7;
    char StringContent[16];
    __int16 field_18;
    __int16 field_1A;
    __int16 field_1C;
    u16 word1E;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
};

#endif //__MAIL_H
// Tchaikovsky code generator
