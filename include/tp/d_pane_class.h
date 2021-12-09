/**	@file d_pane_class.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_PANE_CLASS_H
#define TP_D_PANE_CLASS_H

#include <cstdint>

#include "tp/d_pane_class_alpha.h"

namespace libtp::tp::d_pane_class
{
    class CPaneMgr: public libtp::tp::d_pane_class_alpha::CPaneMgrAlpha
    {
        /* 0x1C */ void* mpFirstStackSize;
        /* 0x20 */ void* field_0x20;
        /* 0x24 */ float mInitPos;       // JGeometry::TVec2<float>
        /* 0x2C */ float mGlobalPos;     // JGeometry::TVec2<float>
        /* 0x34 */ float mInitSize;      // JGeometry::TVec2<float>
        /* 0x3C */ float mInitScale;     // JGeometry::TVec2<float>
        /* 0x44 */ float mInitTrans;     // JGeometry::TVec2<float>
        /* 0x4C */ float mRotateZ;
        /* 0x50 */ float mRotateOffset;     // JGeometry::TVec2<float>
        /* 0x58 */ uint32_t mInitWhite;     // JUtility::TColor
        /* 0x5C */ uint32_t mInitBlack;     // JUtility::TColor
        /* 0x60 */ int16_t field_0x60;
        /* 0x62 */ int16_t field_0x62;
        /* 0x64 */ int16_t mScaleAnime;
        /* 0x66 */ int16_t field_0x66;
        /* 0x68 */ int16_t field_0x68;
        /* 0x6A */ int16_t mColorAnime;
    } __attribute__( ( __packed__ ) );
}     // namespace libtp::tp::d_pane_class
#endif