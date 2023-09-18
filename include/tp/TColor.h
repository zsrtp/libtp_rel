/** @file TColor.h
 *  @brief Contains functions and structs for the color manager that many of the J2D classes use
 *
 *  @author TP Decomp Team
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_TCOLOR_H
#define TP_TCOLOR_H

#include "tp/GXStruct.h"
#include <cstdint>

namespace libtp::tp::JUtility
{
    struct TColor: public libtp::tp::GXStruct::GXColor
    {
        TColor(uint8_t rColor, uint8_t gColor, uint8_t bColor, uint8_t aColor) { set(rColor, gColor, bColor, aColor); }
        TColor() { set(0xffffffff); }
        TColor(uint32_t u32Color) { set(u32Color); }
        TColor(libtp::tp::GXStruct::GXColor color) { set(color); }

        // TColor(const TColor& other) { set(other.toUInt32()); }
        TColor& operator=(const TColor& other)
        {
            ((libtp::tp::GXStruct::GXColor*)this)->operator=(other);
            return *this;
        }

        operator uint32_t() const { return toUInt32(); }
        uint32_t toUInt32() const { return *(uint32_t*)&r; }

        void set(uint8_t cR, uint8_t cG, uint8_t cB, uint8_t cA)
        {
            r = cR;
            g = cG;
            b = cB;
            a = cA;
        }

        void set(uint32_t u32Color) { *(uint32_t*)&r = u32Color; }
        void set(libtp::tp::GXStruct::GXColor gxColor) { *(libtp::tp::GXStruct::GXColor*)&r = gxColor; }
    };
} // namespace libtp::tp::JUtility

#endif