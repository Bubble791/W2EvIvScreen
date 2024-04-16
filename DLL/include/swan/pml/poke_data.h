#ifndef __POKE_DATA_H
#define __POKE_DATA_H

#include "swantypes.h"

STRUCT_DECLARE(PkmBufferChunk)
STRUCT_DECLARE(PkmBuffer)
STRUCT_DECLARE(BoxPkm)
STRUCT_DECLARE(BoxPkmBlock0)
STRUCT_DECLARE(BoxPkmBlock1)
STRUCT_DECLARE(BoxPkmBlock2)
STRUCT_DECLARE(BoxPkmBlock3)

SWAN_CPPTYPE_EX(pml::detail, PokeBufferChunk, PkmBufferChunk)
SWAN_CPPTYPE_EX(pml::detail, PokeBuffer, PkmBuffer)
SWAN_CPPTYPE_EX(pml, PokeData, BoxPkm)
SWAN_CPPTYPE_EX(pml::detail, PokeBlock0, BoxPkmBlock0)
SWAN_CPPTYPE_EX(pml::detail, PokeBlock1, BoxPkmBlock1)
SWAN_CPPTYPE_EX(pml::detail, PokeBlock2, BoxPkmBlock2)
SWAN_CPPTYPE_EX(pml::detail, PokeBlock3, BoxPkmBlock3)

#include "pml/poke_param.h"
#include "pml/mail.h"

C_DECL_BEGIN

extern u32     PML_PkmGetParam(BoxPkm* pPkm, PkmField field, u32 data);
extern void    PML_PkmSetParam(BoxPkm* pPkm, PkmField field, u32 data);

C_DECL_END

struct PkmBufferChunk
{
    char RawData[32];
};

struct PkmBuffer
{
    PkmBufferChunk Chunks[4];
};

struct BoxPkm
{
    u32 pid;
    u16 SanityFlags;
    u16 checksum;
    PkmBuffer ContentBuffer;
};

struct BoxPkmBlock0
{
    u16 Species;
    u16 HeldItem;
    u32 TIDSID;
    u32 Experience;
    u8 Happiness;
    u8 Ability;
    u8 Markings;
    u8 Region;
    u8 EvHP;
    u8 EvATK;
    u8 EvDEF;
    u8 EvSPE;
    u8 EvSPA;
    u8 EvSPD;
    u8 ContestCool;
    u8 ContestBeauty;
    u8 ContestCute;
    u8 ContestSmart;
    u8 ContestTough;
    u8 ContestSheen;
    u32 Ribbons1;
};

struct BoxPkmBlock1
{
    u16 Moves[4];
    u8 MovePPs[4];
    u8 MovePPUpStages[4];
    int IVBits;
    int Ribbons2;
    u8 GenderAndForme;
    u8 Nature;
    u16 HiddenAbilAndNPoke;
    int dword1C;
};

struct BoxPkmBlock2
{
    wchar_t Nickname[11];
    u8 unsigned___int816;
    u8 OriginGame;
    u64 Ribbons3;
};

struct BoxPkmBlock3
{
    __int16 OTName[8];
    u8 HatchDateYear;
    u8 HatchDateMonth;
    u8 HatchDateDay;
    u8 MetYear;
    u8 MetMonth;
    u8 MetDay;
    u16 HatchLocation;
    u16 MetLocation;
    u8 Pokerus;
    u8 Pokeball;
    u8 MetLevelAndOTGender;
    u8 CatchTerrainTileType;
    u8 unsigned___int81E;
    u8 PokeStarFame;
};

#endif //__POKE_DATA_H
// Tchaikovsky code generator
