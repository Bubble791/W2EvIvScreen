#include "global.h"
#include "pml/poke_param.h"
#include "pml/poke_party.h"
#include "pml/poke_data.h"
#include "field_event.h"
#include "battle_client.h"
#include "constant/items.h"
#include "constant/ovl.h"

C_DECL_BEGIN

static void BagItem_UsePokeView(BagView *m_bagView);

struct FieldItemData
{
    u16 item;
    u16 num;
    FieldBagItemUse itemFunc;
};

struct FieldItemData gFieldItemFuncTable[] = 
{
    {ITEM_BICYCLE, 1, (FieldBagItemUse)0x0219A395},
    {ITEM_TOWN_MAP, 1, (FieldBagItemUse)0x0219A405},
    {ITEM_PAL_PAD, 1, (FieldBagItemUse)0x0219A415},
    {ITEM_HONEY, 1, (FieldBagItemUse)0x0219A435},
    {ITEM_SUPER_ROD, 1, (FieldBagItemUse)0x0219A445},
    {ITEM_VS_RECORDER, 1, (FieldBagItemUse)0x0219A425},
    {ITEM_DOWSING_MCHN,1, (FieldBagItemUse)0x0219A481},
    {ITEM_ESCAPE_ROPE, 1, (FieldBagItemUse)0x0219A4A1},
    {ITEM_XTRANSCEIVER, 1, (FieldBagItemUse)0x0219A4C1},
    {ITEM_XTRANSCEIVER2, 1, (FieldBagItemUse)0x0219A4C1},
    {ITEM_MEDAL_BOX, 1, (FieldBagItemUse)0x0219A4D1},

    // new
    {ITEM_IV_EV_SCREEN, 1, BagItem_UsePokeView}
}; // 0x021A09C0

void THUMB_BRANCH_LINK_142_0x0219A5F6(BagView *bagView, int index)
{
    gFieldItemFuncTable[index].itemFunc(bagView);
}

int THUMB_BRANCH_142_0x0219A4E0(u16 item)
{
    for (u32 i = 0; i < NELEMS(gFieldItemFuncTable); ++i)
    {
        if (gFieldItemFuncTable[i].item <= item && gFieldItemFuncTable[i].num + gFieldItemFuncTable[i].item > item)
            return i;
    }
    return -1;
}

static void BagItem_UsePokeView(BagView *m_bagView)
{
    sub_0219a354(m_bagView, 2, 0x17, 0);
}

////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
#define EV_IV_SCREEN_PROC (0x021AA800)

EventFieldAppTable FIELD_PROC_LINK_LIST[] = 
{
    [0] = 
    {
        .OvlID = OVERLAY_PARTY_MENU,
        .ProcFuncs = (GameProcFunctions *)0x21A4D20,
        .ProcDataMakeFunc = (ProcData)0x215B819,
        .CreateResult = (CreatProc)0x215BA0D,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [1] = 
    {
        .OvlID = OVERLAY_POKE_DEX,
        .ProcFuncs = (GameProcFunctions *)0x21AE41C,
        .ProcDataMakeFunc = (ProcData)0x215BB15,
        .CreateResult = (CreatProc)0x215BB85,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [2] = 
    {
        .OvlID = OVERLAY_BAG_MENU,
        .ProcFuncs = (GameProcFunctions *)0x21A0950,
        .ProcDataMakeFunc = (ProcData)0x215BD89,
        .CreateResult = (CreatProc)0x215BE11,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [3] = 
    {
        .OvlID = OVERLAY_BADGE_VIEW,
        .ProcFuncs = (GameProcFunctions *)0x216DDB8,
        .ProcDataMakeFunc = (ProcData)0x215BF35,
        .CreateResult = (CreatProc)0x215BF99,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [4] = 
    {
        .OvlID = 0,
        .ProcFuncs = (GameProcFunctions *)0x0,
        .ProcDataMakeFunc = (ProcData)0x0,
        .CreateResult = (CreatProc)0x0,
        .field_10 = (FieldProc)0x215C11D,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [5] = 
    {
        .OvlID = 140,
        .ProcFuncs = (GameProcFunctions *)0x219EF0C,
        .ProcDataMakeFunc = (ProcData)0x215C0D5,
        .CreateResult = (CreatProc)0x215C10D,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [6] = 
    {
        .OvlID = 0,
        .ProcFuncs = (GameProcFunctions *)0x0,
        .ProcDataMakeFunc = (ProcData)0x0,
        .CreateResult = (CreatProc)0x0,
        .field_10 = (FieldProc)0x215C5B5,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [7] = 
    {
        .OvlID = 207,
        .ProcFuncs = (GameProcFunctions *)0x21BB6E0,
        .ProcDataMakeFunc = (ProcData)0x215BBB1,
        .CreateResult = (CreatProc)0x215BD31,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215c5d5
    },
    [8] = 
    {
        .OvlID = OVERLAY_TOWN_MAP,
        .ProcFuncs = (GameProcFunctions *)0x219F7B4,
        .ProcDataMakeFunc = (ProcData)0x215BFCD,
        .CreateResult = (CreatProc)0x215C039,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [9] = 
    {
        .OvlID = 204,
        .ProcFuncs = (GameProcFunctions *)0x21AE07C,
        .ProcDataMakeFunc = (ProcData)0x215C14D,
        .CreateResult = (CreatProc)0x215C179,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [10] = 
    {
        .OvlID = 0xFFFFFFFF,
        .ProcFuncs = (GameProcFunctions *)0x21AB05C,
        .ProcDataMakeFunc = (ProcData)0x215C1A1,
        .CreateResult = (CreatProc)0x215C259,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C309
    },
    [11] = 
    {
        .OvlID = 284,
        .ProcFuncs = (GameProcFunctions *)0x21E7DDC,
        .ProcDataMakeFunc = (ProcData)0x215C329,
        .CreateResult = (CreatProc)0x215C3E5,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [12] = 
    {
        .OvlID = 272,
        .ProcFuncs = (GameProcFunctions *)0x21F82F8,
        .ProcDataMakeFunc = (ProcData)0x215C411,
        .CreateResult = (CreatProc)0x215C43D,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [13] = 
    {
        .OvlID = 259,
        .ProcFuncs = (GameProcFunctions *)0x21A03DC,
        .ProcDataMakeFunc = (ProcData)0x215C479,
        .CreateResult = (CreatProc)0x215C4B5,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [14] = 
    {
        .OvlID = 145,
        .ProcFuncs = (GameProcFunctions *)0x21A1020,
        .ProcDataMakeFunc = (ProcData)0x215C4C9,
        .CreateResult = (CreatProc)0x215C4F5,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
    [15] = 
    {
        .OvlID = 345,
        .ProcFuncs = (GameProcFunctions *)EV_IV_SCREEN_PROC,
        .ProcDataMakeFunc = (ProcData)0x215C4C9,
        .CreateResult = (CreatProc)0x215C4F5,
        .field_10 = 0x0,
        .FreeSubprocDataFunc = (FreeProc)0x215C5D5
    },
};

/*
#define SUBAPP_RESULT_CALL_CHILD_APP 4
#define SUBAPP_RESULT_RETRY 0
#define SEASON_SPRING 0
// extern int sub_215B7E8(int*);
// extern void EventFieldAppCall_ConvAppResultToEventType(int, EventTypes*);
// extern int FieldAppCallParam_CanRetry(int*);
// extern GameEvent* CallFieldMapEntranceOutTransitionDefault(GameSystem*, Field*, int, int);
// extern void GameEvent_ChainNext(GameEvent*, GameEvent*);
// extern GameEvent* CreateFieldCloseEvent(GameSystem*, Field*);
// extern void sub_215B800(int*);
// extern GameEvent* EventFieldOpen_CreateHeadless(GameSystem*);
// extern void FieldG2D_SetLCDConfig(void);
// extern void FieldG2D_Prepare3DSurface(Field*);
// extern GameEvent* CallFieldMapEntranceInTransition(GameSystem*, Field*, int, int, int, int, int);
// extern void sub_215B794(EventFieldAppCall*);

// // https://decomp.me/scratch/GeZae
// int EventFieldAppCall_Callback(GameEvent *event, u32 *pState, EventFieldAppCall *data)
// {
//     GameEvent *v8;
//     GameEvent *FieldCloseEvent;
//     GameEvent *Headless;
//     GameEvent *v11;
//     void *subprocData;
//     void *oldSubprocData;
//     u32 AppID;
//     GameProcFunctions *ProcFuncs;
//     int subprocResult;
//     AppCallFramework *m_AppCallFramework;
//     void *v18;

//     switch (*pState)
//     {
//     case 0:
//         (*pState) = 1;
//         break;
//     case 1:
//         if (data->SubprocResult == SUBAPP_RESULT_CALL_CHILD_APP)
//         {
//             if (!FIELD_PROC_LINK_LIST[data->AppID].field_10)
//             {
//                 (*pState) = 6;
//             }
//             else
//             {
//                 (*pState) = 3;
//             }
//         }
//         else
//         {
//             (*pState) = 2;
//         }
//         break;
//     case 2:
//         return 1;
//     case 3:
//         if (!sub_215B7E8(&data->m_Param[0]))
//         {
//             break;
//         }
//         FIELD_PROC_LINK_LIST[data->AppID].field_10(
//             data,
//             data->m_AppCallFramework->SubprocParam);
//         (*pState) = 4;
//         break;
//     case 4:
//         EventFieldAppCall_ConvAppResultToEventType(data->SubprocResult, &data->m_AppCallFramework->EventType);
//         (*pState) = 5;
//         break;
//     case 5:
//         if (data->SubprocResult == SUBAPP_RESULT_RETRY)
//         {
//             if (FieldAppCallParam_CanRetry(&data->m_Param[0]))
//             {
//                 (*pState) = 1;
//             }
//             break;
//         }
//         (*pState) = 1;
//         break;
//     case 6:
//         v8 = CallFieldMapEntranceOutTransitionDefault(
//             data->m_AppCallFramework->GameSystem,
//             data->m_AppCallFramework->Field,
//             0,
//             0);
//         GameEvent_ChainNext(event, v8);
//         (*pState) = 7;
//         break;
//     case 7:
//         if (!sub_215B7E8(&data->m_Param[0]))
//         {
//             break;
//         }
//         FieldCloseEvent = CreateFieldCloseEvent(data->m_AppCallFramework->GameSystem, data->m_AppCallFramework->Field);
//         GameEvent_ChainNext(event, FieldCloseEvent);
//         (*pState) = 11;
//         break;
//     case 8:
//         sub_215B800(&data->m_Param[0]);
//         Headless = EventFieldOpen_CreateHeadless(data->m_AppCallFramework->GameSystem);
//         GameEvent_ChainNext(event, Headless);
//         (*pState) = 9;
//         break;
//     case 9:
//         data->m_AppCallFramework->Field = GSYS_GetField(data->m_AppCallFramework->GameSystem);
//         FieldG2D_SetLCDConfig();
//         FieldG2D_Prepare3DSurface(data->m_AppCallFramework->Field);
//         (*pState) = 10;
//         break;
//     case 10:
//         if (!FieldAppCallParam_CanRetry(&data->m_Param[0]))
//         {
//             break;
//         }
//         v11 = CallFieldMapEntranceInTransition(
//             data->m_AppCallFramework->GameSystem,
//             data->m_AppCallFramework->Field,
//             0,
//             0,
//             0,
//             SEASON_SPRING,
//             SEASON_SPRING);
//         GameEvent_ChainNext(event, v11);
//         (*pState) = 1;
//         break;
//     case 11:
//         subprocData = FIELD_PROC_LINK_LIST[data->AppID].ProcDataMakeFunc(
//             data,
//             data->m_AppCallFramework->SubprocParam,
//             data->LastAppID,
//             data->SubprocData);
//         oldSubprocData = data->SubprocData;
//         if (oldSubprocData)
//         {
//             FIELD_PROC_LINK_LIST[data->LastAppID].FreeSubprocDataFunc(oldSubprocData);
//             data->SubprocData = 0;
//         }
//         AppID = data->AppID;
//         data->SubprocData = subprocData;
//         ProcFuncs = FIELD_PROC_LINK_LIST[AppID].ProcFuncs;
//         if (!ProcFuncs)
//         {
//             break;
//         }
//         GSYS_QueueProc(data->m_AppCallFramework->GameSystem, FIELD_PROC_LINK_LIST[AppID].OvlID, ProcFuncs, subprocData);
//         (*pState) = 12;
//         break;
//     case 12:
//         if (GSYS_GetProcMgrState(data->m_AppCallFramework->GameSystem))
//         {
//             break;
//         }
//         (*pState) = 13;
//         break;
//     case 13:
//         subprocResult = FIELD_PROC_LINK_LIST[data->AppID].CreateResult(data, data->SubprocData);
//         m_AppCallFramework = data->m_AppCallFramework;
//         data->SubprocResult = subprocResult;
//         EventFieldAppCall_ConvAppResultToEventType(subprocResult, &m_AppCallFramework->EventType);
//         if (data->SubprocResult == SUBAPP_RESULT_CALL_CHILD_APP)
//         {
//             data->LastAppID = data->AppID;
//             data->AppID = data->ChildAppID;
//             (*pState) = 11;
//         }
//         else
//         {
//             sub_215B794(data);
//             v18 = data->SubprocData;
//             if (v18)
//             {
//                 GFL_HeapFree(v18);
//                 data->SubprocData = 0;
//             }
//             (*pState) = 8;
//         }
//         break;
//     }

//     return 0;
// }
*/

void __attribute__((noreturn)) FULL_COPY_12_0x0215B740(void)
{
    __asm(".word FIELD_PROC_LINK_LIST + 0x10");
    __asm(".word FIELD_PROC_LINK_LIST + 0x8");
    __asm(".word FIELD_PROC_LINK_LIST + 0x14");
    __asm(".word FIELD_PROC_LINK_LIST + 0x4");
    __asm(".word FIELD_PROC_LINK_LIST");
    __asm(".word FIELD_PROC_LINK_LIST + 0xC");
}

// https://decomp.me/scratch/rf6l6
int THUMB_BRANCH_12_0x0215BE10(FIELD_PARAM *param_1, BAG_RETURN_PARAM *param_2)
{
    void *party;
    void *poke;
    
    switch (param_2->unk44)
    {
        // new
    case 23:
        param_1->EventFieldAppId = 15;
        return ITEMUSE_EVENT_NEW_APP;
    case 0:
        return ITEMUSE_EVENT_CANCEL;
    case 1:
        if (param_2->unk38 == 2)
        {
            param_1->EventFieldAppId = 0;
            return ITEMUSE_EVENT_NEW_APP;
        }
        return 0;
    case 12:
        param_1->EventFieldAppId = 0;
        return ITEMUSE_EVENT_NEW_APP;

    case ITEM_EVENT_BICYCLE_0:
    case ITEM_EVENT_BICYCLE_1:
        (param_1->unk18->fieldId) = 0;
        return ITEMUSE_EVENT_FIELD;

    case 13:
        (param_1->unk18->fieldId) = 1;
        return ITEMUSE_EVENT_FIELD;

    case ITEM_EVENT_HONEY:
        (param_1->unk18->fieldId) = 3;
        return ITEMUSE_EVENT_FIELD;

    case ITEM_EVENT_SUPER_ROD:
        (param_1->unk18->fieldId) = 4;
        return ITEMUSE_EVENT_FIELD;

    case 14:
        (param_1->unk18->fieldId) = 2;
        return ITEMUSE_EVENT_FIELD;

    case ITEM_EVENT_PAL_PAD:
        param_1->EventFieldAppId = 9;
        return ITEMUSE_EVENT_NEW_APP;

    case ITEM_EVENT_TOWN_MAP:
        param_1->EventFieldAppId = 8;
        return ITEMUSE_EVENT_NEW_APP;

    case 22:
        param_1->EventFieldAppId = 0xe;
        return ITEMUSE_EVENT_NEW_APP;

    case ITEM_EVENT_VS_RECORDER:
        param_1->EventFieldAppId = 12;
        return ITEMUSE_EVENT_NEW_APP;

    case 21:
        param_1->EventFieldAppId = 0xd;
        return ITEMUSE_EVENT_NEW_APP;

    case 19:
        param_1->EventFieldAppId = 0xa;
        return ITEMUSE_EVENT_NEW_APP;

    case ITEM_EVEMT_MAIL:
        party = GameData_GetParty(GSYS_GetGameData(param_1->unk18->unk0));
        poke = PokeParty_GetPkm(party, (param_1->unk18->unk30));
        if (PokeParty_GetParam(poke, 6, 0) != 0)
        {
            param_1->EventFieldAppId = 0;
        }
        else
        {
            param_1->EventFieldAppId = 10;
        }
        param_1->unk70 = 2;
        return ITEMUSE_EVENT_NEW_APP;

    case 20:
        (param_1->unk18->fieldId) = 5;
        return ITEMUSE_EVENT_FIELD;
    case 2:
        if (PML_ItemIsMail((u16)param_2->unk48) == 1)
        {
            param_1->unk70 = 0;
        }
        param_1->EventFieldAppId = 0;
        return ITEMUSE_EVENT_NEW_APP;
    default:
        param_1->EventFieldAppId = 0;
        return ITEMUSE_EVENT_NEW_APP;

    }
}

C_DECL_END