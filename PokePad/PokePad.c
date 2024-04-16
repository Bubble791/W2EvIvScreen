#include "types.h"
#include "files.h"
#include "arc_id.h"
#include "gfl/gfl_g2d.h"
#include "gfl/gfl_tcb.h"
#include "gfl/gfl_procsys.h"

void LONG_CALL sub_2023304(void);
void* LONG_CALL GFL_WordSetSystemCreateDefault(u16);
void* LONG_CALL GFL_MsgSysLoadData(int, int, int, int);
void* LONG_CALL GFL_FontCreate(int, int, int, int, int);
void* LONG_CALL GFL_TCBExMgrCreate(int, int, int, int);
void* LONG_CALL sub_20219C4(int);
ArcTool* LONG_CALL GFL_ArcSysCreateFileHandle(int, u16);
void* LONG_CALL sub_204BF48(int, int, u16);
void* LONG_CALL GameData_GetParty(void*);
void* LONG_CALL ClActSys_LoadOamSprites(void*, int, int, int, u16);
u8 LONG_CALL PokeParty_GetPkmCount(void*);
int LONG_CALL sub_2021148();
int LONG_CALL getOBJTileMapping_MainEng();
int LONG_CALL sub_204BC74(void*, int, int, int, u16);
void* LONG_CALL LoadNCERWithNANR(void*, int, int, u16);
void* LONG_CALL PokeParty_GetPkm(void*, u8);
int LONG_CALL PokeIcon_GetPokeIconNarcFile(void*);
int LONG_CALL sub_20210EC(void*);
void LONG_CALL GFL_ArcToolFree(void*);
void LONG_CALL ClactSys_SetOamPalSlot(void*, u8, u8);
void LONG_CALL sub_204C16C(void*, u16*, int);
void LONG_CALL ClactSys_SetAnimEnable(void*, int);
void LONG_CALL sub_204C150(void*, int);
void LONG_CALL gfxSetEngineModeA(int, int, int);
void LONG_CALL sub_2027B78(int);
void LONG_CALL GFL_BGSysSetBGEnabledA(int, int);
void LONG_CALL GFL_BGSysSetBGEnabledB(int, int);
void LONG_CALL DrawWifiIcon(int, int);
void LONG_CALL GFL_BGSysQueueScrLoad(int);
void LONG_CALL sub_0204C044(void*);
void LONG_CALL ClActSys_Create(int*, BGSysVRAMConfig*, u16);
void LONG_CALL sub_204C4B4(void*, int);
void LONG_CALL sub_204C500(void*, int);
void LONG_CALL sub_0204C054(void*);
void LONG_CALL GFL_G2DIOReadNSCRArc(void*, int, int, int, int);
void* LONG_CALL sub_204BEC8(u32*, int, int);
void LONG_CALL sub_204C044(void*, void*);
void LONG_CALL sub_204B7C0(void);
void LONG_CALL BmpWin_InitAllocator(u16);
void* LONG_CALL BmpWin_CreateDynamic(int, u16, u16, int, int, u8, u8);
void* LONG_CALL BmpWin_GetBitmap(void*);
void LONG_CALL GFL_BitmapFill(void*, int);
void LONG_CALL BmpWin_FlushChar(void*);
void* LONG_CALL GFL_StrBufCreate(int, u16);
void LONG_CALL GFL_MsgDataLoadStrbuf(void*, int, void*);
void LONG_CALL loadPokemonNicknameToStrbuf(void*, int, void*);
void LONG_CALL PrintSys_TextPrint(void*, void*, int, int, void*, void*, int);
void LONG_CALL GFL_StrBufFree(void*);
void LONG_CALL sub_2021A68(void*);
int LONG_CALL BmpWin_GetBGIndex(void*);
void LONG_CALL BmpWin_FlushMap(void*);
void LONG_CALL sub_2021C48(void*, void*);
void LONG_CALL GFL_BGSysLoadNCLRDefault(int, int, int, int, int, int);
void LONG_CALL GFL_WordSetSystemFree(void*);
void* LONG_CALL GFL_MsgDataLoadStrbufNew(void*, int);
void LONG_CALL WordSetNumber(void* wordSys, int buffId, int num, int magnitude, int, int);
int LONG_CALL PokeParty_GetParam(void*, int, int);
void LONG_CALL GFL_WordSetFormatStrbuf(void*, void*, void*);
void LONG_CALL GFL_StrBufClear(void*);
int LONG_CALL sub_203DA38(RECT_HIT_TBL* keyPad);
void LONG_CALL GFL_SndSEPlay(int se);
int LONG_CALL LoadNCLRNoOffset(void*, int, int, int, int);
int LONG_CALL sub_204C58C(void*);
void LONG_CALL GFL_MsgDataFree(void*);
void LONG_CALL GFL_FontFree(void*);
void LONG_CALL sub_2021A44(void*);
void LONG_CALL ClactSys_Remove(void*);
void LONG_CALL sub_2021C70(void*);
void LONG_CALL sub_2021A44(void*);
void LONG_CALL ClactSys_FreeOamNcer(void*);
void LONG_CALL ClactSys_FreeOamNclr(int);
void LONG_CALL ClactSys_FreeOamNcgr(void*);
void LONG_CALL ClactSys_DestroyOam(void*);
void LONG_CALL ClactSys_Free(void);
void LONG_CALL GFL_BGSysReleaseBG(int);
void LONG_CALL GFL_BGSysFree(void);
void LONG_CALL BmpWin_Free(void*);
void LONG_CALL BmpWin_FreeAllocator(void);

typedef struct
{
    void *gameData;
} BagParam;


typedef struct
{
    void *gameData;
    ArcTool *fileHandle;
    TCB *tcb;
    void* clactOam;
    int clactOamPal;
    void* clactNcer;
    void* wordSys;
    void* msgData;
    void* font;
    void* tcbExMgr;
    void* printSys;
    void* monIconNcgr[6];
    void* monClact[6];
    void* window[8];
    int selectIndex;

    int selectIconPalSlot;
    void* selectIconNcgr;
    void* selectIconNcer;
    void* selectIconClact;

    int optionIconPalSlot;
    void* optionIconNcgr;
    void* optionIconNcer;
    void* optionIconClact[2];
    int buttonRet;
} PokePad;

static void UpdataPokePad(TCB *tcb, void *wk);
static void PokePad_DrawWindow(PokePad* wk);
static bool8 PokePad_InitKeyPad(PokePad* wk);

static const BGSysVRAMConfig tbl = 
{
    GX_VRAM_BG_128_A,
    GX_VRAM_BGEXTPLTT_NONE,
    GX_VRAM_SUB_BG_128_C,
    GX_VRAM_SUB_BGEXTPLTT_NONE,
    GX_VRAM_OBJ_128_B,
    GX_VRAM_OBJEXTPLTT_NONE,
    GX_VRAM_SUB_OBJ_16_I,
    GX_VRAM_SUB_OBJEXTPLTT_NONE,
    GX_VRAM_TEX_NONE,
    GX_VRAM_TEXPLTT_NONE,
    GX_OBJVRAMMODE_CHAR_1D_128K,
    GX_OBJVRAMMODE_CHAR_1D_128K
};

static BGSysLCDConfig BGsys_data = 
{
    G2D_DISPMODE_GRAPHICS,
    G2D_BGMODE_HTTT,
    G2D_BGMODE_HTTT,
    G2D_BG0_2D,
};

static BGSetup PokePadBgTemplate[] = 
{
    [G2D_BG0A] = 
    {
        .ScreenSize = 0x800,
        .Resolution = 1,
        .ScreenBaseBlock = 0x18,
        .CharBlockSize = 0x4000,
        .Priority = 3,
    },
    [G2D_BG1A] = 
    {
        .ScreenSize = 0x800,
        .Resolution = 1,
        .ScreenBaseBlock = 0x19,
        .CharBaseBlock = 0,
        .CharBlockSize = 0x4000,
        .Priority = 0,
    },
    [G2D_BG2A] = 
    {
        .ScreenSize = 0x800,
        .Resolution = 3,
        .ScreenBaseBlock = 0x1A,
        .CharBaseBlock = 4,
        .CharBlockSize = 0x4000,
        .Priority = 2,
    },
    [G2D_BG3A] = 
    {
        .ScreenSize = 0x800,
        .Resolution = 3,
        .ScreenBaseBlock = 0x1C,
        .CharBaseBlock = 6,
        .CharBlockSize = 0x4000,
        .Priority = 1,
    },
    [G2D_BG0B] = 
    {
        .ScreenSize = 0x800,
        .Resolution = 1,
        .ScreenBaseBlock = 0x1F,
        .CharBaseBlock = 0,
        .CharBlockSize = 0x8000,
        .Priority = 2,
    },
    [G2D_BG1B] = 
    {
        .ScreenSize = 0x800,
        .Resolution = 1,
        .ScreenBaseBlock = 0x1B,
        .CharBaseBlock = 1,
        .CharBlockSize = 0x8000,
        .Priority = 0,
    }
};

static void PokePad_SetUpPokePadBg(PokePad *pokePad, int heapId)
{
    u32 i;

    GFL_BGSysSetEnabledBGsA(G2D_SCREENBG_NONE); // GX_SetVisiblePlane
    GFL_BGSysSetEnabledBGsB(G2D_SCREENBG_NONE);

    reg_G2_BLDCNT = 0;
    reg_G2S_DB_BLDCNT = 0;

    sub_2027B78(0);
    sub_2027B78(1);

    gfxRegSetMasterBrightness((s16*)(0x400006C), -16);
    gfxRegSetMasterBrightness((s16*)(0x400106C), -16);

    GFL_BGSysSetDisplayLayout(0);
    pokePad->fileHandle = GFL_ArcSysCreateFileHandle(62, heapId);
    GFL_BGSysSetVRAMBanks(&tbl); //GF_Disp_SetBank
    GFL_BGSysCreate(heapId);

    GFL_BGSysSetLCDConfig(&BGsys_data); // GF_BGL_InitBG
    for (i = 0; i < NELEMS(PokePadBgTemplate); ++i)
    {
        GFL_BGSysCreateBG((G2DBG)i, &PokePadBgTemplate[i], BGMODE_TEXT);
        GFL_BGSysClearCharCore((G2DBG)i, 32, 0, heapId);
        GFL_BGSysFillScr((G2DBG)i, 0);
        GFL_BGSysSetBGEnabled((G2DBG)i, 1);
    }

    // pal
    GFL_G2DIOLoadArcNCLRDefault(pokePad->fileHandle, 0, G2D_BG0A, 0, 192, heapId); // ArcUtil_HDL_PalSet
    GFL_G2DIOLoadArcNCLRDefault(pokePad->fileHandle, 0, G2D_BG0B, 0, 192, heapId);

    // graphics
    GFL_BGSysLoadArcNCGRStatic(pokePad->fileHandle, 3, G2D_BG0A, 0, 0, 0, heapId);
    GFL_BGSysLoadArcNCGRStatic(pokePad->fileHandle, 3, G2D_BG2A, 0, 0, 0, heapId);
    GFL_BGSysLoadArcNCGRStatic(pokePad->fileHandle, 3, G2D_BG0B, 0, 0, 0, heapId);

    // tilemap
    loadBGScrToVramByFileNoReserveNegAlign(pokePad->fileHandle, 5, G2D_BG0A, 0, 0, 0, heapId);
    loadBGScrToVramByFileNoReserveNegAlign(pokePad->fileHandle, 14, G2D_BG0B, 0, 0, 0, heapId);

    gfxSetEngineModeA(1, 0, 0);
    GFL_BGSysSetBGEnabledA(16, 1);
    GFL_BGSysSetBGEnabledB(16, 1);
    GFL_ArcToolFree(pokePad->fileHandle);
}

extern int dword_2093F34;

OAM_TEMPLATE SelectIconTbl = 
{
    .x = 40,
    .y = 40,
    .anim = 6
};

void PokePad_LoadPokePadObj(PokePad *wk)
{
    u32 i;

    void *party = GameData_GetParty(wk->gameData);
    u8 partyCount = PokeParty_GetPkmCount(party);
    void *p_File = GFL_ArcSysCreateFileHandle(7, (HEAPID_PALPAD & 0x7FFF) | 0x8000);

    int mode = sub_2021148();
    int mapMode = getOBJTileMapping_MainEng();

    wk->clactOamPal = sub_204BC74(p_File, 0, 0, 192, HEAPID_PALPAD);
    wk->clactNcer = LoadNCERWithNANR(p_File, mode, mapMode, HEAPID_PALPAD);

    for (i = 0; i < partyCount; ++i)
    {
        OAM_TEMPLATE icon_Template = {0};

        icon_Template.x = (i % 3) * 80 + 46;
        icon_Template.y = 60 + (i / 3) * 60;
        icon_Template.anim = 1;

        void *partyPoke = PokeParty_GetPkm(party, i);
        int file = PokeIcon_GetPokeIconNarcFile(partyPoke);
        int palSlot = sub_20210EC(partyPoke);
        
        wk->monIconNcgr[i] = ClActSys_LoadOamSprites(p_File, file, 0, 0, HEAPID_PALPAD); // sub_204B848
        wk->monClact[i] = ClActSys_CreateObj(wk->clactOam, wk->monIconNcgr[i], wk->clactOamPal, wk->clactNcer, &icon_Template, 0, HEAPID_PALPAD);
        ClactSys_SetOamPalSlot(wk->monClact[i], palSlot, 1); // set pal
        ClactSys_SetAnimEnable(wk->monClact[i], 1); // setAnimEnable
    }
    GFL_ArcToolFree(p_File);
}

static void PokePad_LoadSelectIcon(PokePad *wk)
{
    // exit icon
    void *p_File = GFL_ArcSysCreateFileHandle(117, (HEAPID_PALPAD & 0x7FFF) | 0x8000);
    ClActSys_Create(&dword_2093F34, &tbl, HEAPID_PALPAD);
    wk->clactOam = sub_204BF48(9, 0, HEAPID_PALPAD); //0x204BF48

    wk->selectIconPalSlot = LoadNCLRNoOffset(p_File, 70, 0, 0, HEAPID_PALPAD);
    wk->selectIconNcer = LoadNCERWithNANR(p_File, 68, 69, HEAPID_PALPAD);

    wk->selectIconNcgr = ClActSys_LoadOamSprites(p_File, 67, 1, 0, HEAPID_PALPAD); // sub_204B848
    wk->selectIconClact = ClActSys_CreateObj(wk->clactOam, wk->selectIconNcgr, wk->selectIconPalSlot, wk->selectIconNcer, &SelectIconTbl, 0, HEAPID_PALPAD);
    ClactSys_SetAnimEnable(wk->selectIconClact, 1); // setAnimEnable

    GFL_ArcToolFree(p_File);
}

OAM_TEMPLATE OptionIconTbl[] = 
{
    {
        .x = 0xE8,
        .y = 0xA8,
        .anim = 1
    },
    {
        .x = 0xC8,
        .y = 0xA8,
        .anim = 0
    },
};

static void PokePad_LoadBottomIcon(PokePad *wk)
{
    void *p_File = GFL_ArcSysCreateFileHandle(82, HEAPID_PALPAD);
    
    wk->optionIconNcgr = ClActSys_LoadOamSprites(p_File, 20, 0, 0, HEAPID_PALPAD);
    wk->optionIconPalSlot = LoadNCLRNoOffset(p_File, 19, 0, 64, HEAPID_PALPAD);
    wk->optionIconNcer = LoadNCERWithNANR(p_File, 23, 26, HEAPID_PALPAD);

    wk->optionIconClact[0] = ClActSys_CreateObj(wk->clactOam, wk->optionIconNcgr, wk->optionIconPalSlot, wk->optionIconNcer, &OptionIconTbl[0], 0, HEAPID_PALPAD);
    wk->optionIconClact[1] = ClActSys_CreateObj(wk->clactOam, wk->optionIconNcgr, wk->optionIconPalSlot, wk->optionIconNcer, &OptionIconTbl[1], 0, HEAPID_PALPAD);

    GFL_ArcToolFree(p_File);
}

static void PokePad_LoadPokePadFont(PokePad *wk)
{
    sub_2023304();
    BmpWin_InitAllocator(HEAPID_PALPAD);

    wk->msgData = GFL_MsgSysLoadData(0, ARCID_SYSTEM_MESSAGE, 495, HEAPID_PALPAD);
    GFL_BGSysLoadNCLRDefault(23, 5, PLTT_LOAD_BG_B, PLT_ID(14), 32, HEAPID_PALPAD);
    GFL_BGSysLoadNCLRDefault(23, 5, PLTT_LOAD_BG_A, PLT_ID(14), 32, HEAPID_PALPAD);

    wk->font = GFL_FontCreate(23, 0, 0, 0, HEAPID_PALPAD);
    wk->printSys = sub_20219C4(HEAPID_PALPAD);
}

int PokePadProc_Init(GameProc *proc, u32 *seq, void *param_2, void *param_3)
{
    PokePad *wk;
    BagParam *bagData = (BagParam *)param_2;

    // GFL_OvlLoad(139); // 
    GFL_HeapCreateChild(HEAPID_USER, HEAPID_PALPAD, 0xC0000); // size
    wk = (PokePad *)GFL_ProcInitSubsystem(proc, sizeof(PokePad), HEAPID_PALPAD);
    sys_memset(wk, 0, sizeof(PokePad));
    wk->gameData = bagData->gameData;
    wk->selectIndex = 0;
    wk->buttonRet = 0;

    PokePad_SetUpPokePadBg(wk, HEAPID_PALPAD);
    PokePad_LoadSelectIcon(wk);
    PokePad_LoadBottomIcon(wk);

    PokePad_LoadPokePadObj(wk);
    PokePad_LoadPokePadFont(wk);

    wk->tcb = GFL_VBlankTCBAdd(UpdataPokePad, wk, 16);//task

    return 1;
}

static void PokePad_Update(PokePad *wk)
{
    sub_2021A68(wk->printSys);
    sub_204B7C0(); //draw_clact
}

static void PokePad_FreeData(PokePad *wk)
{
    u32 i;
    void *party = GameData_GetParty(wk->gameData);
    u8 partyCount = PokeParty_GetPkmCount(party);

    GFL_MsgDataFree(wk->msgData);
    GFL_FontFree(wk->font);

    sub_2021C70(wk->printSys);
    sub_2021A44(wk->printSys);
    
    ClactSys_FreeOamNcer(wk->clactNcer);
    ClactSys_FreeOamNclr(wk->clactOamPal); // sub_204BCFC

    for (i = 0; i < partyCount; ++i)
    {
        ClactSys_FreeOamNcgr(wk->monIconNcgr[i]); // sub_204B9B8
        ClactSys_DestroyOam(wk->monClact[i]);
    }

    ClactSys_FreeOamNclr(wk->optionIconPalSlot);
    ClactSys_FreeOamNclr(wk->selectIconPalSlot);

    ClactSys_FreeOamNcgr(wk->optionIconNcgr);
    ClactSys_FreeOamNcgr(wk->selectIconNcgr);
    
    ClactSys_FreeOamNcer(wk->optionIconNcer);
    ClactSys_FreeOamNcer(wk->selectIconNcer);

    ClactSys_DestroyOam(wk->optionIconClact[0]); // sub_204C134
    ClactSys_DestroyOam(wk->optionIconClact[1]);
    ClactSys_DestroyOam(wk->selectIconClact);

    ClactSys_Remove(wk->clactOam);
    ClactSys_Free(); // sub_204B784

    for (i = 0; i < NELEMS(PokePadBgTemplate); i++)
    {
        GFL_BGSysReleaseBG(i);
    }
    GFL_BGSysFree();

    for (i = 0; i < 3; i++)
    {
        BmpWin_Free(wk->window[i]);
    }
    BmpWin_FreeAllocator();
}

int PokePadProc_Main(GameProc *proc, u32 *seq, void *param_3, void *data)
{
    u8 ret = 0;
    PokePad *wk = (PokePad*)data;

    switch (*seq)
    {
        case 0:
            GFL_WipeSet(0, 1, 1, WIPE_FADE_BLACK, 6, 1, HEAPID_PALPAD);
            PokePad_DrawWindow(wk);
            (*seq)++;
            break;
        case 1:
            if (GFL_WipeIsFinished())
                (*seq)++;
            break;
        case 2:
            ret = PokePad_InitKeyPad(wk);
            if (ret == 1)
                (*seq)++;
            else if(ret == 2)
                (*seq) = 5;
            break;
        case 3:
            GFL_WipeSet(0, 0, 0, WIPE_FADE_BLACK, 6, 1, HEAPID_PALPAD);
            (*seq)++;
            break;
        case 4:
            if (GFL_WipeIsFinished())
                return 1;
            break;
        case 5:
            if (wk->buttonRet == 6 && !sub_204C58C(wk->optionIconClact[0]))
                (*seq) = 3;
            else if (wk->buttonRet == 7 && !sub_204C58C(wk->optionIconClact[1]))
                (*seq) = 3;
            break;
        default:
            return 0;
    }
    PokePad_Update(wk);
    return 0;
}

int PokePadProc_End(GameProc *proc, u32 *seq, void *param_3, void *data)
{
    PokePad *wk = (PokePad*)data;
    GFL_TCBRemove(wk->tcb);
    wk->tcb = 0;
    PokePad_FreeData(wk);

    GFL_ProcReleaseSubsystem(proc);
    GFL_HeapDelete(HEAPID_PALPAD);
    // GFL_OvlUnload(139);

    return 1;
}

static void UpdataPokePad(TCB *tcb, void *data)
{
    sub_204B7F4();
}

void *AddWindow(int bgIndex, u16 x, u16 y, int height, u8 width, u8 paletteIndex, int fillIndex)
{
    void *win = BmpWin_CreateDynamic(bgIndex, x, y, height, width, paletteIndex, 1);
    void *bitmap = BmpWin_GetBitmap(win);
    GFL_BitmapFill(bitmap, fillIndex);
    BmpWin_FlushChar(win);
    return win;
}

static void PrintMonName(PokePad* wk, void* poke)
{
    void* wordSys = GFL_WordSetSystemCreateDefault(HEAPID_PALPAD);
    void *str = GFL_StrBufCreate(120, HEAPID_PALPAD);
    void *msg = GFL_MsgDataLoadStrbufNew(wk->msgData, 0);
    void *winMap = BmpWin_GetBitmap(wk->window[0]);

    loadPokemonNicknameToStrbuf(wordSys, 0, poke);
    GFL_WordSetFormatStrbuf(wordSys, str, msg);
    PrintSys_TextPrint(wk->printSys, winMap, 20, 11, str, wk->font, TEXT_INDICE(0, 15, 1));

    GFL_StrBufFree(msg);
    GFL_StrBufFree(str);
    GFL_WordSetSystemFree(wordSys);
}

enum
{
    PF_EvHP = 0xD,
    PF_EvATK,
    PF_EvDEF,
    PF_EvSPE,
    PF_EvSPATK,
    PF_EvSPDEF,

    PF_IvHP = 0x46,
    PF_IvATK,
    PF_IvDEF,
    PF_IvSPE,
    PF_IvSPATK,
    PF_IvSPDEF,
};

static void PrintMonIvAndEv(PokePad* wk, void* poke)
{
    u32 i;
    void* wordSys = GFL_WordSetSystemCreateDefault(HEAPID_PALPAD);
    void *str = GFL_StrBufCreate(100, HEAPID_PALPAD);
    void *msg = GFL_MsgDataLoadStrbufNew(wk->msgData, 1);
    void *winMap = BmpWin_GetBitmap(wk->window[1]);

    int data = 0;

    /////////////////////////////////////////////////////////////////////
    for (i = 0; i < 3; i++)
    {
        data = PokeParty_GetParam(poke, PF_EvHP + i, 0);
        WordSetNumber(wordSys, i, data, 3, 2, 1); // 2 padding
    }

    GFL_WordSetFormatStrbuf(wordSys, str, msg);
    PrintSys_TextPrint(wk->printSys, winMap, 20, 5, str, wk->font, TEXT_INDICE(0, 15, 1));
    GFL_StrBufFree(msg);

    GFL_StrBufClear(str);
    msg = GFL_MsgDataLoadStrbufNew(wk->msgData, 2);
    for (i = 0; i < 3; i++)
    {
        data = PokeParty_GetParam(poke, PF_EvSPE + i, 0);
        WordSetNumber(wordSys, i, data, 3, 2, 1); // 2 padding
    }

    GFL_WordSetFormatStrbuf(wordSys, str, msg);
    PrintSys_TextPrint(wk->printSys, winMap, 20, 40, str, wk->font, TEXT_INDICE(0, 15, 1));
    GFL_StrBufFree(msg);

    /////////////////////////////////////////////////////////////////////
    GFL_StrBufClear(str);
    msg = GFL_MsgDataLoadStrbufNew(wk->msgData, 3);
    for (i = 0; i < 3; i++)
    {
        data = PokeParty_GetParam(poke, PF_IvHP + i, 0);
        WordSetNumber(wordSys, i, data, 3, 2, 1); // 2 padding
    }

    GFL_WordSetFormatStrbuf(wordSys, str, msg);
    PrintSys_TextPrint(wk->printSys, winMap, 20, 65, str, wk->font, TEXT_INDICE(0, 15, 1));
    GFL_StrBufFree(msg);

    GFL_StrBufClear(str);
    msg = GFL_MsgDataLoadStrbufNew(wk->msgData, 4);
    for (i = 0; i < 3; i++)
    {
        data = PokeParty_GetParam(poke, PF_IvSPE + i, 0);
        WordSetNumber(wordSys, i, data, 3, 2, 1); // 2 padding
    }

    GFL_WordSetFormatStrbuf(wordSys, str, msg);
    PrintSys_TextPrint(wk->printSys, winMap, 20, 100, str, wk->font, TEXT_INDICE(0, 15, 1));

    GFL_StrBufFree(msg);
    GFL_StrBufFree(str);
    GFL_WordSetSystemFree(wordSys);
}

static void PokePad_FlushMonInfo(PokePad* wk)
{
    u32 i;

    void *party = GameData_GetParty(wk->gameData);
    void *partyPoke = PokeParty_GetPkm(party, wk->selectIndex);
    ClAct_228 *sprite = (ClAct_228*)(wk->selectIconClact);

    i = wk->selectIndex;
    sprite->x = (i % 3) * 80 + 50;
    sprite->y = 52 + (i / 3) * 60;

    for (i = 0; i < 2; i++)
    {
        void *bitmap = BmpWin_GetBitmap(wk->window[i]);
        GFL_BitmapFill(bitmap, 0);
    }

    if (wk->selectIndex < PokeParty_GetPkmCount(party))
    {
        PrintMonName(wk, partyPoke);
        PrintMonIvAndEv(wk, partyPoke);
    }

    for (i = 0; i < 2; i++)
    {
        BmpWin_FlushMap(wk->window[i]);
        BmpWin_FlushChar(wk->window[i]);
    }
}

static void PokePad_DrawWindow(PokePad* wk)
{
    void *winMap;
    void *msg = GFL_MsgDataLoadStrbufNew(wk->msgData, 5);

    wk->window[0] = AddWindow(5, 0, 0, 20, 4, 14, 0);
    wk->window[1] = AddWindow(5, 0, 4, 30, 20, 14, 0);
    wk->window[2] = AddWindow(G2D_BG1A, 1, 0, 10, 4, 14, 0);
    
    winMap = BmpWin_GetBitmap(wk->window[2]);
    PrintSys_TextPrint(wk->printSys, winMap, 0, 5, msg, wk->font, TEXT_INDICE(0, 15, 1));
    GFL_StrBufFree(msg);

    BmpWin_FlushMap(wk->window[2]);
    BmpWin_FlushChar(wk->window[2]);

    PokePad_FlushMonInfo(wk);

    GFL_BGSysQueueScrLoad(G2D_BG1B);
    GFL_BGSysQueueScrLoad(G2D_BG1A);
}

static RECT_HIT_TBL PokePadChooseMon[] = 
{
    // up  down  left  right
    {40, 40 + 50, 40, 40 + 40},
    {40, 40 + 50, 106, 106 + 40},
    {40, 40 + 50, 180, 180 + 40},
    {100, 100 + 50, 40, 40 + 40},
    {100, 100 + 50, 106, 106 + 40},
    {100, 100 + 50, 180, 180 + 40},

    {0xA8, 0xBF, 0xE8, 0xFF},
    {0xA8, 0xBF, 0xC8, 0xDF},

    {0xFF, 0x00, 0x00, 0x00},
};

static bool8 PokePad_InitKeyPad(PokePad* wk)
{
    /// touch
    int ret = sub_203DA38(PokePadChooseMon);

    if (ret != -1 && ret != wk->selectIndex && ret < 6)
    {
        GFL_SndSEPlay(1356);
        wk->selectIndex = ret;
        PokePad_FlushMonInfo(wk);
    }
    else if (ret >= 6)
    {
        if (ret == 6)
        {
            sub_204C500(wk->optionIconClact[0], 0);
            sub_204C4B4(wk->optionIconClact[0], 9);
            ClactSys_SetAnimEnable(wk->optionIconClact[0], 1);
            GFL_SndSEPlay(1361);
        }
        else
        {
            sub_204C500(wk->optionIconClact[1], 0);
            sub_204C4B4(wk->optionIconClact[1], 8);
            ClactSys_SetAnimEnable(wk->optionIconClact[1], 1);
            GFL_SndSEPlay(1366);
        }
        wk->buttonRet = ret;
        return 2;
    }
    else
    {
        int key = GCTX_HIDGetPressedKeys();
        if (key & KEY_B)
        {
            GFL_SndSEPlay(1361);
            return 1;
        }
        if (key & (KEY_DOWN | KEY_UP))
        {
            if (wk->selectIndex < 3)
                wk->selectIndex += 3;
            else
                wk->selectIndex -= 3;
            GFL_SndSEPlay(1356);
            PokePad_FlushMonInfo(wk);
        }
        else if (key & KEY_LEFT)
        {
            if (wk->selectIndex == 0)
                wk->selectIndex = 5;
            else
                wk->selectIndex -= 1;
            GFL_SndSEPlay(1356);
            PokePad_FlushMonInfo(wk);
        }
        else if (key & KEY_RIGHT)
        {
            if (wk->selectIndex == 5)
                wk->selectIndex = 0;
            else
                wk->selectIndex += 1;
            GFL_SndSEPlay(1356);
            PokePad_FlushMonInfo(wk);
        }
    }
    return 0;
}

GameProcFunctions PokePadProcData =
{
    PokePadProc_Init,
    PokePadProc_Main,
    PokePadProc_End,
};
