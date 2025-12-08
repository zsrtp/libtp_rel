/**	@file J2DPane.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_J2DPANE_H
#define TP_J2DPANE_H

#include <cstdint>

namespace libtp::tp::J2DPane
{

    enum J2DBasePosition
    {
        J2DBasePosition_0,
        J2DBasePosition_1,
        J2DBasePosition_2,
        J2DBasePosition_3,
        J2DBasePosition_4
    };

    class J2DPane
    {
       private:
        /* 0x00 */ void* vtable;
        /* 0x04 */ uint16_t _4;
        /* 0x06 */ uint8_t _6[2];
        /* 0x08 */ int32_t id;
        /* 0x0C */ uint8_t _c[4];
        /* 0x10 */ uint64_t mInfoTag;
        /* 0x18 */ uint64_t mUserInfoTag;
        /* 0x20 */ uint8_t field_0x20[0x10]; // JGeometry::TBox2<float> mBounds;
        /* 0x30 */ uint8_t field_0x30[0x10]; // JGeometry::TBox2<float> mGlobalBounds;
        /* 0x40 */ uint8_t field_0x40[0x10]; // JGeometry::TBox2<float> mClipRect;
        /* 0x50 */ uint8_t field_0x50[0x30]; // Mtx mPositionMtx;
        /* 0x80 */ uint8_t field_0x80[0x30]; // Mtx mGlobalMtx;
        /* 0xB0 */ bool mVisible;
        /* 0xB1 */ uint8_t mCullMode;
        /* 0xB2 */ uint8_t mAlpha;
        /* 0xB3 */ uint8_t mColorAlpha;
        /* 0xB4 */ bool mIsInfluencedAlpha;
        /* 0xB5 */ bool mConnected;
        /* 0xB6 */ char mRotAxis;
        /* 0xB7 */ uint8_t mBasePosition;
        /* 0xB8 */ float mRotateX;
        /* 0xBC */ float mRotateY;
        /* 0xC0 */ float mRotateZ;
        /* 0xC4 */ float mRotateOffsetX;
        /* 0xC8 */ float mRotateOffsetY;
        /* 0xCC */ float mScaleX;
        /* 0xD0 */ float mScaleY;
        /* 0xD4 */ float mTranslateX;
        /* 0xD8 */ float mTranslateY;
        /* 0xDC */ uint8_t field[0x1C]; // JSUTree<J2DPane> mPaneTree;
        /* 0xF8 */ void* field_0xF8;    // const J2DAnmTransform* mTransform;
#ifndef PLATFORM_WII
        /* 0xFC */ uint32_t _fc;
#endif
    } __attribute__((__packed__));

    static_assert(sizeof(J2DPane) == 0x100);

    extern "C"
    {
        void setBasePosition(J2DPane* panePtr, J2DBasePosition basePosition);
    }

} // namespace libtp::tp::J2DPane
#endif