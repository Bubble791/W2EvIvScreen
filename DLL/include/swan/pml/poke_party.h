#ifndef __POKE_PARTY_H
#define __POKE_PARTY_H

#include "swantypes.h"

STRUCT_DECLARE(PartyPkm)
STRUCT_DECLARE(PokeParty)

SWAN_CPPTYPE_EX(pml, PartyPoke, PartyPkm)
SWAN_CPPTYPE_EX(pml, Party, PokeParty)

#include "pml/poke_data.h"

struct PartyPkm
{
    BoxPkm Base;
    u32 StatusCond;
    u8 Level;
    u8 field_8D;
    u16 NowHP;
    u16 MaxHP;
    u16 ATK;
    u16 DEF;
    u16 SPE;
    u16 SPA;
    u16 SPD;
    MailData Mail;
    u32 field_D4;
    u32 field_D8;
};

struct PokeParty
{
    u32 PokemonCapacity;
    u32 PokemonCount;
    PartyPkm Pokemon[6];
    u8 PresentMemberBits;
    u8 _pad1;
    u16 _pad2;
};

#endif //__POKE_PARTY_H
// Tchaikovsky code generator
