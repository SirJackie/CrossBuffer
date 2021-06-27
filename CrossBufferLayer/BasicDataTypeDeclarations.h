#ifndef __CSBF_BasicDataTypeDeclarations__
#define __CSBF_BasicDataTypeDeclarations__


/*
** Define Cross Platform Types
*/

typedef    unsigned int      ui32;    // Should be 32-bit 4-byte sign-less
typedef    signed   int      i32;     // Should be 32-bit 4-byte sign-ful

typedef    unsigned short    ui16;    // Should be 16-bit 2-byte sign-less
typedef    signed   short    i16;     // Should be 16-bit 2-byte sign-ful

typedef    unsigned char     ui8;     // Should be 16-bit 2-byte sign-less
typedef    signed   char     i8;      // Should be 16-bit 2-byte sign-ful

typedef    double            f64;     // Should be 64-bit 8-byte float
typedef    float             f32;     // Should be 32-bit 4-byte float


/*
** Define Mathematics Functions
*/

i32 CS_iclamp(i32 min, i32 x, i32 max);


#endif
