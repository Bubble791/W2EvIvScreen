#ifndef __MATRIX_H
#define __MATRIX_H

#include "swantypes.h"

STRUCT_DECLARE(Mat3)
STRUCT_DECLARE(Mat2)
STRUCT_DECLARE(Mat4x3)
STRUCT_DECLARE(Mat4)

SWAN_CPPTYPE(math, Mat3)
SWAN_CPPTYPE(math, Mat2)
SWAN_CPPTYPE(math, Mat4x3)
SWAN_CPPTYPE(math, Mat4)

#include "math/fixed.h"
#include "math/vector.h"

C_DECL_BEGIN

extern void    MAT3_Identity(Mat3* matrix);
extern void    MAT3_Copy(Mat3* src, Mat3* dest);
extern void    MAT3_Invert(Mat3* matrix, Mat3* inverse);
extern void    MAT3_Mul(Mat3* right, Mat3* left, Mat3* ab);
extern void    MAT3_Scaling(Mat3* matrix, fx32 x, fx32 y, fx32 z);
extern void    MAT3_Scale(Mat3* matrix, fx32 x, fx32 y, fx32 z);
extern void    MAT3_RotationX(Mat3* matrix, fx32 angleSin, fx32 angleCos);
extern void    MAT3_RotationY(Mat3* matrix, fx32 angleSin, fx32 angleCos);
extern void    MAT3_RotationZ(Mat3* matrix, fx32 angleSin, fx32 angleCos);
extern void    MAT3_RotationEulerZYX(fx32 rotX, fx32 rotY, fx32 rotZ, Mat3* matrix);
extern void    MAT3_RotationDir(VecFx32* dirVec, Mat3* matrix);
extern void    MAT3_RotationAxisAngle(Mat3* matrix, VecFx32* axis, fx32 angleSin, fx32 angleCos);
extern void    MAT3_MulVec(VecFx32* vec, Mat3* matrix, VecFx32* dst);
extern void    MAT3_To4x4(Mat3* src, Mat4* dest);
extern void    MAT2_Identity(Mat2* matrix);
extern void    MAT2_Rotation(Mat2* matrix, fx32 sin, fx32 cos);
extern void    MAT2_Scaling(Mat2* matrix, fx32 x, fx32 y);
extern void    MAT2_Scale(Mat2* src, Mat2* dest, fx32 scaleX, fx32 scaleY);
extern void    MAT43_Identity(Mat4x3* matrix);
extern void    MAT43_Copy(Mat4x3* src, Mat4x3* dst);
extern void    MAT43_Scaling(Mat4x3* matrix, fx32 x, fx32 y, fx32 z);
extern void    MAT43_Scale(Mat4x3* src, Mat4x3* dest, fx32 x, fx32 y, fx32 z);
extern void    MAT43_RotationY(Mat4x3* matrix, fx32 sin, fx32 cos);
extern void    MAT43_RotationAxisAngle(Mat4x3* matrix, VecFx32* axis, fx32 angleSin, fx32 angleCos);
extern void    MAT43_Invert(Mat4x3* src, Mat4x3* dst);
extern void    MAT43_Mul(Mat4x3* right, Mat4x3* left, Mat4x3* dest);
extern void    MAT43_MulVec(VecFx32* vec, Mat4x3* matrix, VecFx32* dest);
extern void    MAT43_LookAt(VecFx32* eye, VecFx32* up, VecFx32* target, Mat4x3* dest);
extern void    MAT43_To4x4(Mat4x3* src, Mat4* dest);
extern void    MAT4_Identity(Mat4* matrix);
extern void    MAT4_Copy(Mat4* src, Mat4* dst);
extern void    MAT4_SetPerspective(fx32 fovSin, fx32 fovCos, fx32 aspect, fx32 near, fx32 far, fx32 ndcRange, Mat4* dest);
extern void    MAT4_SetOrtho(fx32 top, fx32 bottom, fx32 left, fx32 right, fx32 near, fx32 far, fx32 ndcRange, Mat4* dest);
extern void    MAT4_SetFrustum(fx32 top, fx32 bottom, fx32 left, fx32 right, fx32 near, fx32 far, fx32 ndcRange, Mat4* dest);
extern void    MAT4_Mul(Mat4* right, Mat4* left, Mat4* dest);
extern void    MAT4_To4x3(Mat4* src, Mat4x3* dest);

C_DECL_END

struct Mat3
{
    fx32 M00;
    fx32 M01;
    fx32 M02;
    fx32 M10;
    fx32 M11;
    fx32 M12;
    fx32 M20;
    fx32 M21;
    fx32 M22;
  
    #ifdef __cplusplus
  
    INLINE void Identity() {
        MAT3_Identity(this);
    }

    INLINE void Invert() {
        MAT3_Invert(this, this);
    }

    INLINE void Invert(math::Mat3* inverse) {
        MAT3_Invert(this, inverse);
    }

    INLINE void Mul(math::Mat3* right) {
        MAT3_Mul(right, this, this);
    }

    INLINE void Mul(math::Mat3* right, math::Mat3* ab) {
        MAT3_Mul(right, this, ab);
    }

    INLINE void Scaling(fx32 x, fx32 y, fx32 z) {
        MAT3_Scaling(this, x, y, z);
    }

    INLINE void Scale(fx32 x, fx32 y, fx32 z) {
        MAT3_Scale(this, x, y, z);
    }

    INLINE void RotationX(fx32 angleSin, fx32 angleCos) {
        MAT3_RotationX(this, angleSin, angleCos);
    }

    INLINE void RotationY(fx32 angleSin, fx32 angleCos) {
        MAT3_RotationY(this, angleSin, angleCos);
    }

    INLINE void RotationZ(fx32 angleSin, fx32 angleCos) {
        MAT3_RotationZ(this, angleSin, angleCos);
    }

    INLINE void RotationEulerZYX(fx32 rotX, fx32 rotY, fx32 rotZ) {
        MAT3_RotationEulerZYX(rotX, rotY, rotZ, this);
    }

    INLINE void RotationDir(math::Vec3* dirVec) {
        MAT3_RotationDir(dirVec, this);
    }

    INLINE void RotationAxisAngle(math::Vec3* axis, fx32 angleSin, fx32 angleCos) {
        MAT3_RotationAxisAngle(this, axis, angleSin, angleCos);
    }

    INLINE void MulVec(math::Vec3* vec) {
        MAT3_MulVec(vec, this, vec);
    }

    INLINE void MulVec(math::Vec3* vec, math::Vec3* dst) {
        MAT3_MulVec(vec, this, dst);
    }

    INLINE void Copy(math::Mat3* dest) {
        MAT3_Copy(this, dest);
    }

    INLINE void To4x4(math::Mat4* dest) {
        MAT3_To4x4(this, dest);
    }

    #endif
};

struct Mat2
{
    fx32 M00;
    fx32 M01;
    fx32 M10;
    fx32 M11;
  
    #ifdef __cplusplus
  
    INLINE void Identity() {
        MAT2_Identity(this);
    }

    INLINE void Scaling(fx32 x, fx32 y) {
        MAT2_Scaling(this, x, y);
    }

    INLINE void Scale(math::Mat2* dest, fx32 scaleX, fx32 scaleY) {
        MAT2_Scale(this, dest, scaleX, scaleY);
    }

    INLINE void Scale(fx32 scaleX, fx32 scaleY) {
        MAT2_Scale(this, this, scaleX, scaleY);
    }

    INLINE void Rotation(fx32 sin, fx32 cos) {
        MAT2_Rotation(this, sin, cos);
    }

    #endif
};

struct Mat4x3
{
    Mat3 Rotation;
    VecFx32 Translation;
  
    #ifdef __cplusplus
  
    INLINE void Identity() {
        MAT43_Identity(this);
    }

    INLINE void Copy(math::Mat4x3* dst) {
        MAT43_Copy(this, dst);
    }

    INLINE void Invert(math::Mat4x3* dst) {
        MAT43_Invert(this, dst);
    }

    INLINE void Invert() {
        MAT43_Invert(this, this);
    }

    INLINE void Mul(math::Mat4x3* right, math::Mat4x3* dest) {
        MAT43_Mul(right, this, dest);
    }

    INLINE void Mul(math::Mat4x3* right) {
        MAT43_Mul(right, this, this);
    }

    INLINE void To4x4(math::Mat4* dest) {
        MAT43_To4x4(this, dest);
    }

    INLINE void Scaling(fx32 x, fx32 y, fx32 z) {
        MAT43_Scaling(this, x, y, z);
    }

    INLINE void Scale(math::Mat4x3* dest, fx32 x, fx32 y, fx32 z) {
        MAT43_Scale(this, dest, x, y, z);
    }

    INLINE void Scale(fx32 x, fx32 y, fx32 z) {
        MAT43_Scale(this, this, x, y, z);
    }

    INLINE void RotationY(fx32 sin, fx32 cos) {
        MAT43_RotationY(this, sin, cos);
    }

    INLINE void RotationAxisAngle(math::Vec3* axis, fx32 angleSin, fx32 angleCos) {
        MAT43_RotationAxisAngle(this, axis, angleSin, angleCos);
    }

    INLINE void LookAt(math::Vec3* eye, math::Vec3* up, math::Vec3* target) {
        MAT43_LookAt(eye, up, target, this);
    }

    INLINE void MulVec(math::Vec3* vec, math::Vec3* dest) {
        MAT43_MulVec(vec, this, dest);
    }

    INLINE void MulVec(math::Vec3* vec) {
        MAT43_MulVec(vec, this, vec);
    }

    #endif
};

struct Mat4
{
    fx32 M00;
    fx32 M01;
    fx32 M02;
    fx32 M03;
    fx32 M10;
    fx32 M11;
    fx32 M12;
    fx32 M13;
    fx32 M20;
    fx32 M21;
    fx32 M22;
    fx32 M23;
    fx32 M30;
    fx32 M31;
    fx32 M32;
    fx32 M33;
  
    #ifdef __cplusplus
  
    INLINE void Identity() {
        MAT4_Identity(this);
    }

    INLINE void Copy(math::Mat4* dst) {
        MAT4_Copy(this, dst);
    }

    INLINE void Mul(math::Mat4* right, math::Mat4* dest) {
        MAT4_Mul(right, this, dest);
    }

    INLINE void Mul(math::Mat4* right) {
        MAT4_Mul(right, this, this);
    }

    INLINE void To4x3(math::Mat4x3* dest) {
        MAT4_To4x3(this, dest);
    }

    INLINE void SetPerspective(fx32 fovSin, fx32 fovCos, fx32 aspect, fx32 near, fx32 far, fx32 ndcRange) {
        MAT4_SetPerspective(fovSin, fovCos, aspect, near, far, ndcRange, this);
    }

    INLINE void SetOrtho(fx32 top, fx32 bottom, fx32 left, fx32 right, fx32 near, fx32 far, fx32 ndcRange) {
        MAT4_SetOrtho(top, bottom, left, right, near, far, ndcRange, this);
    }

    INLINE void SetFrustum(fx32 top, fx32 bottom, fx32 left, fx32 right, fx32 near, fx32 far, fx32 ndcRange) {
        MAT4_SetFrustum(top, bottom, left, right, near, far, ndcRange, this);
    }

    #endif
};

#endif //__MATRIX_H
// Tchaikovsky code generator
