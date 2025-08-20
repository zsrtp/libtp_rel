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
#include "TColor.h"
#include "jGeometry.h"
namespace libtp::tp::d_pane_class
{
    class CPaneMgr: public libtp::tp::d_pane_class_alpha::CPaneMgrAlpha
    {
        /* 0x1C */ void* mpFirstStackSize;
        /* 0x20 */ void* field_0x20;
        /* 0x24 */ JGeometry::TVec2<float> mInitPos;   // JGeometry::TVec2<float>
        /* 0x2C */ JGeometry::TVec2<float> mGlobalPos; // JGeometry::TVec2<float>
        /* 0x34 */ JGeometry::TVec2<float> mInitSize;  // JGeometry::TVec2<float>
        /* 0x3C */ JGeometry::TVec2<float> mInitScale; // JGeometry::TVec2<float>
        /* 0x44 */ JGeometry::TVec2<float> mInitTrans; // JGeometry::TVec2<float>
        /* 0x4C */ float mRotateZ;
        /* 0x50 */ JGeometry::TVec2<float> mRotateOffset; // JGeometry::TVec2<float>
        /* 0x58 */ JUtility::TColor mInitWhite; // JUtility::TColor
        /* 0x5C */ JUtility::TColor mInitBlack; // JUtility::TColor
        /* 0x60 */ int16_t field_0x60;
        /* 0x62 */ int16_t field_0x62;
        /* 0x64 */ int16_t mScaleAnime;
        /* 0x66 */ int16_t field_0x66;
        /* 0x68 */ int16_t field_0x68;
        /* 0x6A */ int16_t mColorAnime;
    public:
        float getInitPosX() { return mInitPos.x; }
        float getInitPosY() { return mInitPos.y; }
        float getInitSizeX() { return mInitSize.x; }
        float getInitSizeY() { return mInitSize.y; }
    };


    extern "C"
    {
        /**
         *	@brief Updates the referenced CPaneMgr's color values with the specified color structs.
         *
         *  @param panePtr The pointer to the currently referenced CPaneMgr.
         *  @param black The pointer to the primary color structure.
         *  @param white The pointer to the secondary color structure.
         */
        void setBlackWhite(libtp::tp::d_pane_class::CPaneMgr* panePtr,
                           libtp::tp::JUtility::TColor* black,
                           libtp::tp::JUtility::TColor* white);
    }
} // namespace libtp::tp::d_pane_class
#endif