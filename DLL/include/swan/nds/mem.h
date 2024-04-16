#ifndef __MEM_H
#define __MEM_H

#include "swantypes.h"

C_DECL_BEGIN

extern void        sys_memset16(u16 value, void* ptr, size_t size);
extern void*       sys_memcpy16(const void* src, void* dst, size_t size);
extern void        sys_memset32(u32 value, void* ptr, size_t size);
extern void*       sys_memcpy32(const void* src, void* dest, size_t size);
extern void        sys_memcpy_volatile(const void* src, volatile int* dest, size_t size);
extern void        sys_memset32_fast(u32 value, const void* ptr, size_t size);
extern void*       sys_memcpy32_fast(const void* src, void* dst, u32 size);
extern void        sys_memset(const void* ptr, u8 value, size_t size);
extern void        sys_memset_fast(const void* ptr, u8 value, size_t size);
extern const void* sys_memcpy(const void* src, void* dst, u32 size);
extern s32         sys_memcmp(const void* src1, const void* src2, size_t size);
extern const void* sys_memcpy_fast(const void* src, void* dst, size_t size);
extern const void* sys_memcpy_ex(const void* src, void* dst, s32 size);

C_DECL_END

#endif //__MEM_H
// Tchaikovsky code generator
