#ifndef __FIELD_EVENT_H
#define __FIELD_EVENT_H

#include "swantypes.h"
#include "swan_cpp_enum_ops.h"

STRUCT_DECLARE(FieldEventCheckData)

ENUM_DECLARE(FieldInteractFlag)

enum FieldInteractFlag
#ifdef __cplusplus
: u32
#endif
{
    FLD_INTERACT_KEY_A_DOWN = 0x1,
    FLD_INTERACT_KEY_X_DOWN = 0x2,
    FLD_INTERACT_PLAYER_STEP_MARK = 0x4,
    FLD_INTERACT_PLAYER_STEP_BEGIN = 0x8,
    FLD_INTERACT_PLAYER_ACT_FINISHED = 0x10,
    FLD_INTERACT_PLAYER_MOVE_TURNING = 0x20,
    FLD_INTERACT_KEY_IN_MOVE_DIR = 0x40,
    FLD_INTERACT_KEY_Y_DOWN = 0x80,
    FLD_INTERACT_KEY_AXY_DOWN = 0x100,
    FLD_INTERACT_PLAYER_MOVE_VERTICAL_ONLY = 0x400,
    FLD_INTERACT_PLAYER_MOVE_NONE = 0x800,
};
SWAN_CPPTYPE_EX(field, EventCheckFlag, FieldInteractFlag)
DEFINE_ENUM_FLAG_OPERATORS(FieldInteractFlag)

SWAN_CPPTYPE_EX(field, EventCheckData, FieldEventCheckData)

#include "system/gamesystem.h"
#include "field/fieldmap.h"
#include "system/game_event.h"
#include "field/field_player.h"

C_DECL_BEGIN

extern void        FieldEventProvider_InitCheckData(FieldEventCheckData* dest, GameSystem* gsys, Field* field);
extern GameEvent*  FieldEventProvider_Grid(GameSystem* gsys, Field* field);
extern GameEvent*  FieldEventProvider_UnionRoom(GameSystem* gsys, Field* field);
extern GameEvent*  FieldEventProvider_NoGrid(GameSystem* gsys, Field* field);
extern GameEvent*  FieldEventProvider_Hybrid(GameSystem* gsys, Field* field);
extern GameEvent*  FieldEventProvider_Grid_CheckForEvent(GameSystem* gsys, Field* field, b32* pCancelPhenomenon, b32* pKeepCatwalkState);
extern GameEvent*  FieldEventProvider_NoGrid_CheckForEvent(GameSystem* gsys, Field* field);

C_DECL_END

struct FieldEventCheckData
{
    u32 FieldmapHeapID;
    GameSystem* m_GameSys;
    GameData* m_GameData;
    EventDataSystem* Entities;
    u16 ZoneID;
    Field* Fieldmap;
    FieldPlayer* Player;
    PlayerActionStatus m_PlayerActionStatus;
    PlayerMoveStatus m_PlayerMoveStatus;
    u16 PlayerDirection;
    u16 ReserveSCRID;
    u32 NewPressedKeys;
    u32 HeldKeys;
    u16 InputPlayerMoveDir;
    VecFx32* PlayerPos;
    TileType TileUnderPlayer;
    FieldInteractFlag Flags;
};

#endif //__FIELD_EVENT_H
// Tchaikovsky code generator
