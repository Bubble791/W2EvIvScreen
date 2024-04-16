#ifndef __GFL_RANDOM_H
#define __GFL_RANDOM_H

#include "swantypes.h"

STRUCT_DECLARE(RandSet)

SWAN_CPPTYPE(gfl::core, RandSet)
namespace gfl::core { struct Random; }

C_DECL_BEGIN

extern void    GFL_RandomInit();
extern void    GFL_RandomInitLC(RandSet* random);
extern void    GFL_RandomUpdateMT(u32 seed);
extern u32     GFL_RandomLC(u32 max);
extern u32     GFL_RandomLCAlt(u32 max);
extern u32     GFL_RandomMT();

C_DECL_END

struct RandSet
{
    u64 seed;
    u64 mul;
    u64 add;
};

#ifdef __cplusplus
struct gfl::core::Random {
    INLINE static void Init() {
        GFL_RandomInit();
    }

    INLINE static void InitLC(gfl::core::RandSet* random) {
        GFL_RandomInitLC(random);
    }

    INLINE static void UpdateMT(u32 seed) {
        GFL_RandomUpdateMT(seed);
    }

    INLINE static u32 GetLC(u32 max) {
        return GFL_RandomLC(max);
    }

    INLINE static u32 GetLCAlt(u32 max) {
        return GFL_RandomLCAlt(max);
    }

    INLINE static u32 GetMT() {
        return GFL_RandomMT();
    }

};
#endif //__cplusplus

#endif //__GFL_RANDOM_H
// Tchaikovsky code generator
