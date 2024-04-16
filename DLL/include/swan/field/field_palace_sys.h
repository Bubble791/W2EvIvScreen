#ifndef __FIELD_PALACE_SYS_H
#define __FIELD_PALACE_SYS_H

#include "swantypes.h"

STRUCT_DECLARE(FieldPalaceSys)

#include "system/gamesystem.h"
#include "field/fieldmap.h"

struct FieldPalaceSys
{
    GameSystem* m_GameSystem;
    Field* m_Field;
    u8* LuminanceTable;
};

#endif //__FIELD_PALACE_SYS_H
// Tchaikovsky code generator
