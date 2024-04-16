#ifndef __GFL_VHBLANK_H
#define __GFL_VHBLANK_H

#include "swantypes.h"

typedef void (*VBlankCallback)(void*);

#include "gfl/core/gfl_tcb.h"

C_DECL_BEGIN

extern void        GFL_HBlankTCBUpdate();
extern TCB*        GFL_HBlankTCBAdd(TCBFunc callback, void* data, u32 priority);
extern void        GFL_VBlankExecCallback();
extern b32         GFL_VBlankSetCallback(VBlankCallback callback, void* data);
extern void        GFL_VBlankResetCallback();
extern u32         GFL_VBlankUpdate();
extern TCB*        GFL_VBlankTCBAdd(TCBFunc callback, void* data, u32 priority);
extern TCBManager* GFL_VBlankGetTCBMgr();

C_DECL_END

#endif //__GFL_VHBLANK_H
// Tchaikovsky code generator
