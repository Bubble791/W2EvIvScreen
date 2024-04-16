#ifndef __GAME_CONTEXT_H
#define __GAME_CONTEXT_H

#include "swantypes.h"

namespace game { struct Context; }

#include "gfl/core/gfl_procsys.h"

C_DECL_BEGIN

extern void    GCTX_ProcMgrQueueProc(int ovlId, const GameProcFunctions* vtbl, void* procData);
extern void    GCTX_ProcMgrReplaceProc(int ovlId, const GameProcFunctions* vtbl, void* procData);

C_DECL_END

#ifdef __cplusplus
struct game::Context {
    INLINE static void StartProc(int ovlId, const gfl::core::ProcVTable* vtbl, void* procData) {
        GCTX_ProcMgrQueueProc(ovlId, vtbl, procData);
    }

    INLINE static void ReplaceProc(int ovlId, const gfl::core::ProcVTable* vtbl, void* procData) {
        GCTX_ProcMgrReplaceProc(ovlId, vtbl, procData);
    }

};
#endif //__cplusplus

#endif //__GAME_CONTEXT_H
// Tchaikovsky code generator
