#ifndef __COMPRESSION_H
#define __COMPRESSION_H

#include "swantypes.h"

C_DECL_BEGIN

extern void    sys_uncomp_blz(void* address);
extern void    sys_uncomp_lz1x(void* src, void* dest);

C_DECL_END

#endif //__COMPRESSION_H
// Tchaikovsky code generator
