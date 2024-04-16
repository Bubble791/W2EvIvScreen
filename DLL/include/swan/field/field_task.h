#ifndef __FIELD_TASK_H
#define __FIELD_TASK_H

#include "swantypes.h"

STRUCT_DECLARE(FieldTask)
STRUCT_DECLARE(FieldTaskManager)

typedef b32 (*FieldTaskCallback)(void* data);

struct FieldTask
{
    u32 State;
    void* Data;
    FieldTaskCallback Callback;
};

struct FieldTaskManager
{
    u8 TaskLimit;
    u8 _padTaskLimit1;
    u16 _padTaskLimit2;
    FieldTask** Tasks;
    FieldTask** ParentTasks;
};

#endif //__FIELD_TASK_H
// Tchaikovsky code generator
