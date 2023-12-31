#ifndef __CSBF_BasicDataTypeDeclarations__
#define __CSBF_BasicDataTypeDeclarations__

#define _CRT_SECURE_NO_WARNINGS

/*
** Define Cross Platform Types
*/

typedef    unsigned long long  ui64;     // Should be 32-bit 4-byte sign-less
typedef    signed long long    si64;     // Should be 32-bit 4-byte sign-ful
typedef    long long            i64;     // Should be 32-bit 4-byte auto

typedef    unsigned int        ui32;     // Should be 32-bit 4-byte sign-less
typedef    signed   int        si32;     // Should be 32-bit 4-byte sign-ful
typedef    int                  i32;     // Should be 32-bit 4-byte auto

typedef    unsigned short      ui16;     // Should be 16-bit 2-byte sign-less
typedef    signed   short      si16;     // Should be 16-bit 2-byte sign-ful
typedef    short                i16;     // Should be 16-bit 2-byte auto

typedef    unsigned char        ui8;     // Should be 16-bit 2-byte sign-less
typedef    signed   char        si8;     // Should be 16-bit 2-byte sign-ful
typedef    char                  i8;     // Should be 16-bit 2-byte auto

typedef    double               f64;     // Should be 64-bit 8-byte float
typedef    float                f32;     // Should be 32-bit 4-byte float

typedef    char              csbool;     // Boolean value, no matter what
const      csbool csTrue        = 1;
const      csbool csFalse       = 0;

#define    csNull               NULL
#define    csNullPtr         nullptr


/*
** Define Basic Functions
*/

inline i32 CS_iclamp(i32 min, i32 x, i32 max)
{
	return (x < min ? min : (x >= max ? (max - 1) : x));
}

inline f32 CS_fclamp(f32 min, f32 x, f32 max)
{
	return (x < min ? min : (x > max ? max : x));
}

inline i32 CS_imin3(i32 a, i32 b, i32 c)
{
	return a < b ? (c < a ? c : a) : (c < b ? c : b);
}

inline i32 CS_imax3(i32 a, i32 b, i32 c)
{
	return a > b ? (c > a ? c : a) : (c > b ? c : b);
}

inline f32 CS_fmin3(f32 a, f32 b, f32 c)
{
	return a < b ? (c < a ? c : a) : (c < b ? c : b);
}

inline f32 CS_fmax3(f32 a, f32 b, f32 c)
{
	return a > b ? (c > a ? c : a) : (c > b ? c : b);
}

#include <iostream>
using std::endl;

#include <string>
#include <sstream>
using std::string;
using std::stringstream;

#include <vector>
using std::vector;

#include <cstring>
using std::strlen;
using std::strcpy;
using std::memset;
#define CS_Memset(ptr, fillingContent, length) (memset(ptr, fillingContent, length))

#include <cstdio>
using std::fopen;
using std::fread;
using std::fwrite;
using std::fclose;
using std::FILE;

#include <cmath>
using std::sin;
using std::cos;
using std::tan;
using std::asin;
using std::acos;
using std::atan;
using std::sqrt;
using std::abs;
using std::ceil;
using std::floor;
using std::swap;
#define  PI          3.14159265f
#define  _DEG2RAD_   PI / 180.0f
#define  _RAD2DEG_   180.0f / PI
#define  CS_cos(x)   (cos((x)*_DEG2RAD_))
#define  CS_sin(x)   (sin((x)*_DEG2RAD_))
#define  CS_tan(x)   (tan((x)*_DEG2RAD_))
#define  CS_acos(x)  (acos((x))*_RAD2DEG_)
#define  CS_asin(x)  (asin((x))*_RAD2DEG_)
#define  CS_atan(x)  (atan((x))*_RAD2DEG_)

#endif
