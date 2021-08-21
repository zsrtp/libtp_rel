/**	@file d_event.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::d_event
{
    class dEvt_control
    {
        public:
            /* 0x000 */ uint8_t  field_0x0[4];
            /* 0x004 */ uint8_t field_0x4[0xC0]; //dEvt_order_c mOrder[8];
            /* 0x0C4 */ uint32_t  mPt1;
            /* 0x0C8 */ uint32_t  mPt2;
            /* 0x0CC */ uint32_t  mPtT;
            /* 0x0D0 */ uint32_t  mPtI;
            /* 0x0D4 */ uint32_t  mPtd;
            /* 0x0D8 */ uint16_t  mEventFlag;
            /* 0x0DA */ uint16_t  mFlag2;
            /* 0x0DC */ uint16_t  mHindFlag;
            /* 0x0DE */ int16_t  mSpecifiedEvent;  // name maybe wrong
            /* 0x0E0 */ int16_t  field_0xe0;
            /* 0x0E2 */ uint8_t  mNum;
            /* 0x0E3 */ uint8_t  field_0xe3;
            /* 0x0E4 */ uint8_t  mMode;
            /* 0x0E5 */ uint8_t  field_0xe5;
            /* 0x0E6 */ uint8_t  field_0xe6;
            /* 0x0E7 */ uint8_t  field_0xe7;
            /* 0x0E8 */ uint8_t  field_0xe8;
            /* 0x0E9 */ uint8_t  mDebugStb;
            /* 0x0EA */ uint8_t  field_0xea;
            /* 0x0EB */ uint8_t  mMapToolId;
            /* 0x0EC */ uint8_t  field_0xec;
            /* 0x0ED */ uint8_t  field_0xed;
            /* 0x0EE */ uint8_t  mPreItemNo;
            /* 0x0EF */ uint8_t  mGtItm;
            /* 0x0F0 */ float mCullRate;
            /* 0x0F4 */ void* mStageEventDt;
            /* 0x0F8 */ void* mChangeOK;
            /* 0x0FC */ uint8_t  field_0xfc[4];
            /* 0x100 */ uint8_t field_0x100[4]; //SkipFunc mSkipFunc;
            /* 0x104 */ uint32_t  field_0x104;
            /* 0x108 */ uint32_t  field_0x108;
            /* 0x10C */ uint32_t  field_0x10c;
            /* 0x110 */ int32_t mSkipFade;
            /* 0x114 */ char mSkipEventName[20];
            /* 0x128 */ uint8_t  mCompulsory;
            /* 0x129 */ bool field_0x129;
            /* 0x12C */ int32_t field_0x12c;
    } __attribute__((__packed__));  // Size = 0x130
}// namespace libtp::tp::d_event