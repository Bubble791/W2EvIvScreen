#ifndef __FIXED_H
#define __FIXED_H

#include "swantypes.h"

#define FX_SCALE_I 4096
#define FX_SCALE_F 4096.0f

#define FX32_ONE FX_SCALE_I

#define FX32(value) ((fx32)((value) * FX_SCALE_F))

typedef s32 fx32;
typedef s16 fx16;

C_DECL_BEGIN

extern fx32    fx_mul_round(fx32 a, fx32 b);
extern fx32    fx_div(fx32 numerator, fx32 denominator);
extern void    fx_div_req(fx32 numerator, fx32 denominator);
extern fx32    fx_recip(fx32 value);
extern void    fx_recip_req(fx32 denominator);
extern fx32    fx_div_get_result();
extern fx32    fx_sqrt(fx32 num);
extern fx32    fx_invSqrt(fx32 num);
extern void    fx_sqrt_req(fx32 num);
extern fx32    fx_sqrt_get_result();

C_DECL_END

#endif //__FIXED_H
// Tchaikovsky code generator
