#ifndef __OVERLAY_H
#define __OVERLAY_H

#include "swantypes.h"

STRUCT_DECLARE(OvlHeader)
STRUCT_DECLARE(OvlLoaderState)

ENUM_DECLARE(OverlayFlag)

typedef void (*OvlStaticInitializer)(void);

enum OverlayFlag 
#ifdef __cplusplus
: u32
#endif
{
    OVLFLAG_COMPRESSED = 0x1000000,
    OVLFLAG_SIGNED = 0x2000000,
};
SWAN_CPPTYPE(nn::os, OverlayFlag)

SWAN_CPPTYPE_EX(nn::os, OverlayHeader, OvlHeader)
SWAN_CPPTYPE_EX(nn::os, Overlay, OvlLoaderState)

C_DECL_BEGIN

extern b32     sys_load_overlay(int cpu, u32 ovlId);
extern b32     sys_unload_overlay(int cpu, u32 ovlId);
extern b32     sys_read_overlay_header(OvlLoaderState* dest, int cpu, u32 ovlId);
extern void    sys_prepare_overlay_area(OvlLoaderState* ovl);
extern void    sys_get_overlay_file_id(FSFileID* dest, OvlLoaderState* ovl);
extern u32     sys_get_overlay_size(OvlLoaderState* ovl);
extern b32     sys_mount_overlay(OvlLoaderState* ovl);
extern b32     sys_unmount_overlay(OvlLoaderState* ovl);
extern void    sys_start_overlay(OvlLoaderState* ovl);
extern void    sys_call_ovl_dtors(OvlLoaderState* ovl);

C_DECL_END

struct OvlHeader
{
    int OvlID;
    char* MountAddress;
    int MountSize;
    int BSSSize;
    OvlStaticInitializer* StaticInitStart;
    OvlStaticInitializer* StaticInitEnd;
    int FileID;
    int Extra;
};

struct OvlLoaderState
{
    OvlHeader Header;
    u32 Target;
    u32 FileOffset;
    u32 FileLength;
  
    #ifdef __cplusplus
  
    INLINE b32 LoadHeader(int cpu, u32 ovlId) {
        return sys_read_overlay_header(this, cpu, ovlId);
    }

    INLINE b32 Mount() {
        return sys_mount_overlay(this);
    }

    INLINE b32 Unmount() {
        return sys_unmount_overlay(this);
    }

    INLINE void Start() {
        sys_start_overlay(this);
    }

    INLINE void CallDtors() {
        sys_call_ovl_dtors(this);
    }

    INLINE u32 GetCodeSize() {
        return sys_get_overlay_size(this);
    }

    INLINE void GetFileID(FSFileID* dest) {
        sys_get_overlay_file_id(dest, this);
    }

    INLINE void PrepareArea() {
        sys_prepare_overlay_area(this);
    }

    INLINE static b32 Load(int cpu, u32 ovlId) {
        return sys_load_overlay(cpu, ovlId);
    }

    INLINE static b32 Unload(int cpu, u32 ovlId) {
        return sys_unload_overlay(cpu, ovlId);
    }

    #endif
};

#endif //__OVERLAY_H
// Tchaikovsky code generator
