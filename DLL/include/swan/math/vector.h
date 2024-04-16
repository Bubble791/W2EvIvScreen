#ifndef __VECTOR_H
#define __VECTOR_H

#include "swantypes.h"

STRUCT_DECLARE(VecFx32)
STRUCT_DECLARE(VecFx16)

SWAN_CPPTYPE_EX(math, Vec3, VecFx32)
SWAN_CPPTYPE_EX(math, Vec3_16, VecFx16)

#include "math/fixed.h"

C_DECL_BEGIN

extern void    vecfx_mul(const VecFx32* src, const fx32 mul, VecFx32* dest);
extern void    vecfx_div(const VecFx32* src, const fx32 denom, VecFx32* dest);
extern void    vecfx_add(const VecFx32* a, const VecFx32* b, VecFx32* dest);
extern void    vecfx_sub(const VecFx32* base, const VecFx32* subtrahend, VecFx32* dest);
extern void    vecfx_add16(const VecFx16* a, const VecFx16* b, VecFx16* dest);
extern fx32    vecfx_dot(const VecFx32* a, const VecFx32* b);
extern fx32    vecfx_dot16(const VecFx16* a, const VecFx16* b);
extern void    vecfx_cross(const VecFx32* a, const VecFx32* b, VecFx32* dest);
extern void    vecfx_cross16(const VecFx16* a, const VecFx16* b, VecFx16* dest);
extern fx32    vecfx_length(const VecFx32* vec);
extern fx32    vecfx_length16(const VecFx16* vec);
extern void    vecfx_normalize(const VecFx32* vec, VecFx32* normalized);
extern void    vecfx_normalize16(const VecFx16* vec, VecFx16* normalized);
extern void    vecfx_muladd(const fx32 scalar, const VecFx32* base, const VecFx32* addend, VecFx32* dest);
extern fx32    vecfx_dist(const VecFx32* a, const VecFx32* b);

C_DECL_END

struct VecFx32
{
    fx32 x;
    fx32 y;
    fx32 z;
  
    #ifdef __cplusplus
  
    INLINE void Add(const math::Vec3* b, math::Vec3* dest) {
        vecfx_add(this, b, dest);
    }

    INLINE void Add(const math::Vec3* b) {
        vecfx_add(this, b, this);
    }

    INLINE void Sub(const math::Vec3* subtrahend, math::Vec3* dest) {
        vecfx_sub(this, subtrahend, dest);
    }

    INLINE void Sub(const math::Vec3* subtrahend) {
        vecfx_sub(this, subtrahend, this);
    }

    INLINE void Mul(const fx32 mul, math::Vec3* dest) {
        vecfx_mul(this, mul, dest);
    }

    INLINE void Mul(const fx32 mul) {
        vecfx_mul(this, mul, this);
    }

    INLINE void Div(const fx32 denom, math::Vec3* dest) {
        vecfx_div(this, denom, dest);
    }

    INLINE void Div(const fx32 denom) {
        vecfx_div(this, denom, this);
    }

    INLINE void MulAdd(const fx32 scalar, const math::Vec3* addend, math::Vec3* dest) {
        vecfx_muladd(scalar, this, addend, dest);
    }

    INLINE void MulAdd(const fx32 scalar, const math::Vec3* addend) {
        vecfx_muladd(scalar, this, addend, this);
    }

    INLINE fx32 Dot(const math::Vec3* b) {
        return vecfx_dot(this, b);
    }

    INLINE void Cross(const math::Vec3* b, math::Vec3* dest) {
        vecfx_cross(this, b, dest);
    }

    INLINE void Cross(const math::Vec3* b) {
        vecfx_cross(this, b, this);
    }

    INLINE void Normalize(math::Vec3* normalized) {
        vecfx_normalize(this, normalized);
    }

    INLINE void Normalize() {
        vecfx_normalize(this, this);
    }

    INLINE fx32 Length() {
        return vecfx_length(this);
    }

    INLINE fx32 Dist(const math::Vec3* b) {
        return vecfx_dist(this, b);
    }

    #endif
};

struct VecFx16
{
    fx16 x;
    fx16 y;
    fx16 z;
  
    #ifdef __cplusplus
  
    INLINE void Add(const math::Vec3_16* b, math::Vec3_16* dest) {
        vecfx_add16(this, b, dest);
    }

    INLINE void Add(const math::Vec3_16* b) {
        vecfx_add16(this, b, this);
    }

    INLINE fx32 Dot(const math::Vec3_16* b) {
        return vecfx_dot16(this, b);
    }

    INLINE void Cross(const math::Vec3_16* b, math::Vec3_16* dest) {
        vecfx_cross16(this, b, dest);
    }

    INLINE void Cross(const math::Vec3_16* b) {
        vecfx_cross16(this, b, this);
    }

    INLINE void Normalize(math::Vec3_16* normalized) {
        vecfx_normalize16(this, normalized);
    }

    INLINE void Normalize() {
        vecfx_normalize16(this, this);
    }

    INLINE fx32 Length() {
        return vecfx_length16(this);
    }

    #endif
};

#endif //__VECTOR_H
// Tchaikovsky code generator
