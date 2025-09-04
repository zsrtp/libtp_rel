/** @file GXStruct.h
 *  @brief Contains structs for the color manager that many classes use.
 *
 *  @author TP Decomp Team
 *  @author Lunar Soap
 *	@bug No known bugs.
 */

#ifndef TP_GXSTRUCT_H
#define TP_GXSTRUCT_H

#include <cstdint>

namespace libtp::tp::GXStruct
{
    typedef struct _GXColor
    {
        /* 0x0 */ uint8_t r;
        /* 0x1 */ uint8_t g;
        /* 0x2 */ uint8_t b;
        /* 0x3 */ uint8_t a;
    } GXColor;

    static_assert(sizeof(GXColor) == 0x4);

} // namespace libtp::tp::GXStruct

#endif