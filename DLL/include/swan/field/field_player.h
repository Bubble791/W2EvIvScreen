#ifndef __FIELD_PLAYER_H
#define __FIELD_PLAYER_H

#include "swantypes.h"

STRUCT_DECLARE(PlayerState)
STRUCT_DECLARE(FieldPlayer)
STRUCT_DECLARE(FieldPlayerCore)
STRUCT_DECLARE(FieldPlayerGrid)
STRUCT_DECLARE(FieldPlayerRail)

ENUM_DECLARE(PlayerExState)
ENUM_DECLARE(PlayerMoveStatus)
ENUM_DECLARE(PlayerActionStatus)
ENUM_DECLARE(FieldPlayerGridStatus)
ENUM_DECLARE(FieldPlayerGridCommand)

enum PlayerExState
#ifdef __cplusplus
: u32
#endif
{
    FLD_PLAYER_EXSTATE_NONE = 0x0,
    FLD_PLAYER_EXSTATE_CYCLING = 0x1,
    FLD_PLAYER_EXSTATE_SURF = 0x2,
    FLD_PLAYER_EXSTATE_DIVE = 0x3,
};

enum PlayerMoveStatus
#ifdef __cplusplus
: u32
#endif
{
    FLD_PLAYER_MVSTATUS_STAND = 0x0,
    FLD_PLAYER_MVSTATUS_MOVE = 0x1,
    FLD_PLAYER_MVSTATUS_TURN = 0x2,
};

enum PlayerActionStatus
#ifdef __cplusplus
: u32
#endif
{
    FLD_PLAYER_ACTSTATUS_IDLE = 0x0,
    FLD_PLAYER_ACTSTATUS_BEGIN = 0x1,
    FLD_PLAYER_ACTSTATUS_PERFORMING = 0x2,
    FLD_PLAYER_ACTSTATUS_FINISHED = 0x3,
};

enum FieldPlayerGridStatus
#ifdef __cplusplus
: u32
#endif
{
    FLD_PLR_GRID_STAT_IDLE = 0x0,
    FLD_PLR_GRID_STAT_MOVE = 0x1,
    FLD_PLR_GRID_STAT_TURN = 0x2,
    FLD_PLR_GRID_STAT_BRAKE = 0x3,
    FLD_PLR_GRID_STAT_CATWALK = 0x4,
    FLD_PLR_GRID_STAT_CATWALK_EXIT = 0x5,
    FLD_PLR_GRID_STAT_CATWALK_EXIT_WAIT = 0x6,
    FLD_PLR_GRID_STAT_FALL = 0x7,
};

enum FieldPlayerGridCommand
#ifdef __cplusplus
: u32
#endif
{
    FLD_PLR_GRID_CMD_BUSY = 0x0,
    FLD_PLR_GRID_CMD_IDLE = 0x1,
    FLD_PLR_GRID_CMD_MOVE = 0x2,
    FLD_PLR_GRID_CMD_TURN = 0x3,
    FLD_PLR_GRID_CMD_BRAKE = 0x4,
    FLD_PLR_GRID_CMD_JUMP = 0x5,
    FLD_PLR_GRID_CMD_CATWALK_BALANCE = 0x6,
    FLD_PLR_GRID_CMD_CATWALK_EXIT = 0x7,
    FLD_PLR_GRID_CMD_CATWALK_EXIT_WAIT = 0x8,
    FLD_PLR_GRID_CMD_FALL = 0x9,
};

#include "math/fixed.h"
#include "math/angle.h"
#include "math/vector.h"
#include "field/field_mmodel.h"
#include "system/gamesystem.h"
#include "field/fieldmap.h"
#include "field/field_rail_system.h"
#include "field/field_effect.h"

struct PlayerState
{
    u16 ZoneID;
    VecFx32 VecPos;
    RailPosition RailPos;
    fxangle RotationAngle;
    u8 field_1A;
    u8 IsPosRail;
    u16 NowOBJCODE;
    __int16 field_1E;
    int field_20;
    int field_24;
    int field_28;
    int field_2C;
    int field_30;
    int field_34;
    int field_38;
    int field_3C;
    PlayerExState ExState;
};

struct FieldPlayer
{
    Field* m_Field;
    FieldPlayerCore* m_Core;
    FieldPlayerGrid* m_GridCtl;
    FieldPlayerRail* m_RailCtl;
};

struct FieldPlayerCore
{
    u32 field_0;
    GameSystem* m_GameSystem;
    Field* m_Field;
    PlayerState* State;
    PlayerActionStatus ActionStatus;
    PlayerMoveStatus MoveStatus;
    u32 Sex;
    FieldActor* Actor;
    u16 KeyMoveDirH;
    u16 KeyMoveDirV;
    u32 SpecialSequence;
    FieldTerrainEffectTCB* m_TerrainFXTCB;
    u16 field_2C;
    u16 field_2E;
    u16 StateChangeFuncIdx;
    u16 IsStateChangeDone;
};

struct FieldPlayerGrid
{
    FieldPlayerGridStatus Status;
    FieldPlayerGridCommand LastCommand;
    u32 Flags;
    FieldPlayerCore* m_PlayerCore;
    Field* m_Field;
    u16 CatwalkFocusBreakCounter;
    u8 IsCatwalkBalanceInterruptedByMenu;
    u8 _padCatwalk;
    u16 NowSFX;
    u16 SFXCounter;
    b32 IsVerticalMoveOnly;
};

struct FieldPlayerRail
{
    u32 field_0;
    int field_4;
    int field_8;
    int field_C;
    int field_10;
    FieldPlayerCore* m_PlayerCore;
    Field* m_Field;
    FieldActor* m_Actor;
    RailUnit* m_PlayerRailUnit;
};

#endif //__FIELD_PLAYER_H
// Tchaikovsky code generator
