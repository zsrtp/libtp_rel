/**	@file GXStruct.h
 *	@brief Holds generic graphics related structures.
 *
 *	GXStruct contains structures that are used by most
 *	graphic-related code.
 *
 *	@author TakaRikka
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef DOLPHIN_GX_GXSTRUCT_H
#define DOLPHIN_GX_GXSTRUCT_H

#include <cstdint>

struct GXColor
{
    /* 0x0 */ uint8_t r;
    /* 0x1 */ uint8_t g;
    /* 0x2 */ uint8_t b;
    /* 0x3 */ uint8_t a;
} __attribute__((__packed__));

struct GXColorS10
{
    /* 0x0 */ int16_t r;
    /* 0x2 */ int16_t g;
    /* 0x4 */ int16_t b;
    /* 0x6 */ int16_t a;
} __attribute__((__packed__));

#endif /* DOLPHIN_GX_GXSTRUCT_H */