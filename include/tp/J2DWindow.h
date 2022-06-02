/**	@file J2DWindow.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_J2DWINDOW_H
#define TP_J2DWINDOW_H

#include <cstdint>

#include "tp/J2DPane.h"

namespace libtp::tp::J2DWindow
{
    class J2DWindow: public libtp::tp::J2DPane::J2DPane
    {
       private:
        /* 0x100 */ uint8_t field_0x100[0x14];     // TMaterial mMaterial;
        /* 0x114 */ uint8_t field_0x114[0x10];     // JGeometry::TBox2<f32>
        /* 0x124 */ void* mPalette;                // JUTPalette*
        /* 0x128 */ uint32_t field_0x128;          // JUtility::TColor
        /* 0x12C */ uint32_t field_0x12C;          // JUtility::TColor
        /* 0x130 */ uint32_t field_0x130;          // JUtility::TColor
        /* 0x134 */ uint32_t field_0x134;          // JUtility::TColor
        /* 0x138 */ uint32_t mWhite;               // JUtility::TColor
        /* 0x13C */ uint32_t mBlack;               // JUtility::TColor
        /* 0x140 */ int16_t field_0x140;
        /* 0x142 */ int16_t field_0x142;
        /* 0x144 */ uint8_t field_0x144;
        /* 0x145 */ uint8_t field_0x145;
    } __attribute__( ( __packed__ ) );     // Size: 0x148

}     // namespace libtp::tp::J2DWindow
#endif