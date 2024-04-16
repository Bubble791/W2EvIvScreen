#ifndef __FIELD_MMODEL_G3DOBJ_H
#define __FIELD_MMODEL_G3DOBJ_H

#include "swantypes.h"

STRUCT_DECLARE(FieldActorG3DSystem)
STRUCT_DECLARE(FieldActorG3DObjEntry)

#include "field/field_g3dobj.h"
#include "field/field_mmodel.h"

struct FieldActorG3DSystem
{
    FieldActorSystem* m_ActorSystem;
    FieldG3DObjSystem* m_G3DObjSystem;
    u16 ActorCapacity;
    u16 _padActorCapacity;
    FieldActorG3DObjEntry* ObjEntries;
};

struct FieldActorG3DObjEntry
{
    u16 ResGroupIndex;
    u16 ObjCode;
};

#endif //__FIELD_MMODEL_G3DOBJ_H
// Tchaikovsky code generator
