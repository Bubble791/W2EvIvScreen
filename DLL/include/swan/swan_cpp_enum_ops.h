#ifndef __SWAN_CPP_ENUM_OPS_H
#define __SWAN_CPP_ENUM_OPS_H

#ifndef CPP_ENUM_OPS_DEFINED
#define CPP_ENUM_OPS_DEFINED

#ifdef __cplusplus

#include <stdint.h>
#include <stddef.h>

template <size_t S>
struct _ENUM_FLAG_INTEGER_FOR_SIZE;

template <>
struct _ENUM_FLAG_INTEGER_FOR_SIZE<1>
{
    typedef uint8_t type;
};

template <>
struct _ENUM_FLAG_INTEGER_FOR_SIZE<2>
{
    typedef uint16_t type;
};

template <>
struct _ENUM_FLAG_INTEGER_FOR_SIZE<4>
{
    typedef uint32_t type;
};

template <class T>
struct _ENUM_FLAG_SIZED_INTEGER
{
    typedef typename _ENUM_FLAG_INTEGER_FOR_SIZE<sizeof(T)>::type type;
};

#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE) \
inline constexpr ENUMTYPE operator | (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) | ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); } \
inline constexpr ENUMTYPE &operator |= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type &)a) |= ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); } \
inline constexpr ENUMTYPE operator & (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) & ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); } \
inline constexpr ENUMTYPE &operator &= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type &)a) &= ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); } \
inline constexpr ENUMTYPE operator ~ (ENUMTYPE a) { return ENUMTYPE(~((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a)); } \
inline constexpr ENUMTYPE operator ^ (ENUMTYPE a, ENUMTYPE b) { return ENUMTYPE(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)a) ^ ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); } \
inline constexpr ENUMTYPE &operator ^= (ENUMTYPE &a, ENUMTYPE b) { return (ENUMTYPE &)(((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type &)a) ^= ((_ENUM_FLAG_SIZED_INTEGER<ENUMTYPE>::type)b)); } \

#else
#define DEFINE_ENUM_FLAG_OPERATORS(ENUMTYPE)
#endif

#endif

#endif