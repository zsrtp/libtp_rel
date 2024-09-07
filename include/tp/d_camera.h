/**	@file d_camera.h
 *	@brief Contains functions and values that control how the camera behaves.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_CAMERA_H
#define TP_D_CAMERA_H
#include <cstdint>

#include "tp/d_a_alink.h"
#include "tp/f_op_actor.h"

namespace libtp::tp::d_camera
{
    extern "C"
    {

        class dCamera_c
        {
           public:
            class dCamInfo_c
            {
               public:
                /* 0x00 */ cXyz mCenter;
                /* 0x0C */ cXyz mEye;
                /* 0x18 */ float mFovy;
                /* 0x1C */ void* mBank;
                /* 0x1E */ int16_t field_0x1e;
            }; // Size: 0x20

            struct dCamera_pad_info
            {
                struct _stick
                {
                    /* 0x00 */ float mLastPosX;
                    /* 0x04 */ float mLastPosY;
                    /* 0x08 */ float mLastValue;
                    /* 0x0C */ float mPosXDelta;
                    /* 0x10 */ float mPosYDelta;
                    /* 0x14 */ float mValueDelta;
                    /* 0x18 */ void* field_0x18;
                };

                /* 0x00 */ _stick mMainStick;
                /* 0x1C */ _stick mCStick;
            };

            struct BG
            {
                class
                {
                   public:
                    /* 0x00 */ uint8_t field_0x0;
                    /* 0x04 */ void* field_0x4;
                    /* 0x58 */ float field_0x58;
                } /* 0x000 */ field_0x0;
                class
                {
                   public:
                    /* 0x00 */ uint8_t field_0x0;
                    /* 0x04 */ void* field_0x4;
                    /* 0x58 */ float field_0x58;
                } /* 0x05C */ field_0x5c;
                /* 0x0B8 */ uint8_t field_0xb8[0xC0 - 0xB8];
                class
                {
                   public:
                    /* 0x00 */ uint8_t field_0x0;
                    /* 0x01 */ uint8_t field_0x1;
                    /* 0x04 */ cXyz field_0x4;
                    /* 0x10 */ cXyz field_0x10;
                    /* 0x1C */ void* field_0x1c;
                    /* 0x1E */ void* field_0x1e;
                    /* 0x20 */ int32_t field_0x20;
                    /* 0x24 */ void* field_0x24;
                    /* 0x2C */ void* field_0x2c;
                    /* 0x34 */ int32_t field_0x34;
                    /* 0x38 */ float field_0x38;
                    /* 0x3C */ int32_t field_0x3c;
                    /* 0x40 */ int32_t field_0x40;
                    /* 0x44 */ int32_t field_0x44;
                } /* 0x0C0 */ field_0xc0;
                class
                {
                   public:
                    /* 0x0 */ int32_t field_0x0;
                    /* 0x4 */ float field_0x4;
                    /* 0x8 */ cXyz field_0x8;
                } /* 0x108 */ field_0x108;
            };

            struct Shake
            {
                /* 0x00 */ uint8_t field_0x0[12];
                /* 0x0C */ int32_t field_0xc;
                /* 0x10 */ int32_t field_0x10;
                /* 0x14 */ uint8_t field_0x14[4];
                /* 0x18 */ cXyz field_0x18;
                /* 0x24 */ cXyz field_0x24;
                /* 0x30 */ cXyz field_0x30;
                /* 0x3C */ float field_0x3c;
                /* 0x40 */ void* field_0x40;
            }; // Size: 0x44

            /* 0x000 */ void** field_0x0;
            /* 0x004 */ int32_t mRoomNo;
            /* 0x008 */ uint8_t field_0x8[0x20 - 0x8];
            /* 0x020 */ uint8_t field_0x20;
            /* 0x021 */ uint8_t field_0x21;
            /* 0x022 */ uint8_t field_0x22[2];
            /* 0x024 */ int32_t field_0x24;
            /* 0x028 */ void* field_0x28;
            /* 0x030 */ cXyz mCenter;
            /* 0x03C */ cXyz mEye;
            /* 0x048 */ cXyz mUp;
            /* 0x054 */ void* mBank;
            /* 0x058 */ float mFovY;
            class
            {
               public:
                /* 0x00 */ void* field_0x0;
                /* 0x08 */ cXyz field_0x8;
                /* 0x14 */ cXyz field_0x14;
                /* 0x20 */ void* field_0x20;
            }
            /* 0x05C */ field_0x5c;
            /* 0x080 */ float field_0x80;
            /* 0x084 */ float field_0x84;
            /* 0x088 */ uint32_t field_0x88;
            /* 0x08C */ void* field_0x8c;
            /* 0x090 */ cXyz field_0x90;
            /* 0x09C */ cXyz field_0x9c;
            /* 0x0A8 */ int32_t field_0xa8;
            /* 0x0AC */ uint32_t field_0xac;
            /* 0x0B0 */ dCamInfo_c field_0xb0;
            /* 0x0D0 */ dCamInfo_c field_0xd0[2];
            class
            {
               public:
                /* 0x00 */ int32_t field_0x0;
                /* 0x04 */ uint16_t field_0x4;
                /* 0x08 */ dCamInfo_c field_0x8;
                /* 0x28 */ cXyz field_0x28;
            }
            /* 0x110 */ field_0x110;
            class
            {
               public:
                /* 0x0 */ cXyz field_0x0;
                /* 0xC */ csXyz field_0xc;
            }
            /* 0x144 */ field_0x144;
            class
            {
               public:
                /* 0x0 */ bool field_0x0;
                /* 0x2 */ void* field_0x2;
                /* 0x4 */ void* field_0x4;
            }
            /* 0x158 */ field_0x158;
            /* 0x160 */ int32_t field_0x160;
            /* 0x164 */ uint8_t field_0x164[0x170 - 0x164];
            /* 0x170 */ int32_t field_0x170;
            /* 0x174 */ uint32_t mCurCamTypeTimer;
            /* 0x178 */ uint32_t mCameraID;
            /* 0x17C */ uint32_t mPadID;
            /* 0x180 */ libtp::tp::f_op_actor::fopAc_ac_c* mpPlayerActor;
            /* 0x184 */ libtp::tp::f_op_actor::fopAc_ac_c* mpLockonTarget;
            /* 0x188 */ uint8_t field_0x188[0x190 - 0x188];
            /* 0x190 */ int32_t field_0x190;
            /* 0x194 */ uint8_t field_0x194;
            /* 0x198 */ uint32_t field_0x198;
            /* 0x19C */ uint32_t field_0x19c;
            /* 0x1A0 */ int32_t mCurMode;
            /* 0x1A4 */ int32_t mNextMode;
            /* 0x1A8 */ int32_t field_0x1a8;
            /* 0x1AC */ int32_t field_0x1ac;
            /* 0x1B0 */ void* field_0x1b0;
            /* 0x1B4 */ float field_0x1b4;
            /* 0x1B8 */ uint8_t field_0x1b8[4];
            /* 0x1BC */ dCamera_pad_info mPadInfo;
            /* 0x1F4 */ int32_t field_0x1f4;
            /* 0x1F8 */ int32_t field_0x1f8;
            /* 0x1FC */ int32_t field_0x1fc;
            /* 0x200 */ float mTriggerLeftLast;
            /* 0x204 */ float mTriggerLeftDelta;
            /* 0x208 */ uint8_t field_0x208;
            /* 0x209 */ uint8_t field_0x209;
            /* 0x20A */ uint8_t field_0x20a;
            /* 0x20B */ uint8_t field_0x20b;
            /* 0x20C */ float mTriggerRightLast;
            /* 0x210 */ float mTriggerRightDelta;
            /* 0x214 */ uint8_t field_0x214;
            /* 0x215 */ uint8_t field_0x215;
            /* 0x216 */ uint8_t field_0x216;
            /* 0x217 */ uint8_t field_0x217;
            /* 0x218 */ uint8_t mHoldX;
            /* 0x219 */ uint8_t mTrigX;
            /* 0x21A */ uint8_t mHoldY;
            /* 0x21B */ uint8_t mTrigY;
            /* 0x21C */ bool mHoldZ;
            /* 0x21D */ uint8_t mTrigZ;
            /* 0x21E */ uint8_t field_0x21e;
            /* 0x21F */ uint8_t field_0x21f;
            /* 0x220 */ uint8_t mHoldB;
            /* 0x221 */ uint8_t mTrigB;
            /* 0x222 */ uint8_t field_0x222;
            /* 0x223 */ uint8_t field_0x223;
            /* 0x224 */ uint8_t field_0x224;
            /* 0x228 */ void* mFocusLine;
            /* 0x298 */ void* mFakeAngleSys;
            /* 0x2A0 */ void* mMonitor;
            /* 0x2C0 */ float field_0x2c0;
            /* 0x2C4 */ int32_t field_0x2c4;
            /* 0x2C8 */ float field_0x2c8;
            /* 0x2CC */ BG mBG;
            /* 0x3E8 */ uint8_t field_0x3e8;
            /* 0x3EC */ int32_t field_0x3ec;
            /* 0x3F0 */ int32_t field_0x3f0;
            /* 0x3F4 */ uint8_t field_0x3f4[0x4E8 - 0x3F4];
            /* 0x4E8 */ void* mEventData;
            /* 0x60C */ uint32_t mEventFlags;
            /* 0x610 */ uint8_t field_0x610;
            /* 0x611 */ uint8_t field_0x611;
            /* 0x612 */ uint8_t field_0x612[2];
            class
            {
               public:
                /* 0x00 */ uint8_t field_0x0[8];
                /* 0x08 */ void* field_0x8;
                /* 0x10 */ uint8_t field_0x10[4];
            }
            /* 0x614 */ field_0x614[4];
            /* 0x664 */ uint8_t field_0x664[4];
            /* 0x668 */ int32_t field_0x668;
            /* 0x66C */ int32_t field_0x66c;
            /* 0x670 */ int32_t field_0x670;
            /* 0x674 */ int32_t field_0x674;
            /* 0x678 */ uint8_t field_0x678;
            /* 0x67C */ int32_t mCamStyle;
            /* 0x680 */ int32_t field_0x680;
            /* 0x684 */ void** mCamTypeData;
            /* 0x688 */ int32_t mCamTypeNum;
            /* 0x68C */ int32_t mCurType;
            /* 0x690 */ int32_t mNextType;
            /* 0x694 */ int32_t mMapToolType;
            /* 0x698 */ int32_t field_0x698;
            /* 0x69C */ int32_t field_0x69c;
            /* 0x6A0 */ uint8_t field_0x6a0[0x6b8 - 0x6a0];
            /* 0x6B8 */ Shake mShake;
            /* 0x6FC */ int32_t field_0x6fc;
            class
            {
               public:
                /* 0x00 */ uint8_t field_0x0[4];
                /* 0x04 */ int32_t field_0x4;
                /* 0x08 */ csXyz field_0x8;
                /* 0x10 */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x10;
                /* 0x14 */ int32_t field_0x14;
                /* 0x18 */ cXyz mBlurePosition;
                /* 0x24 */ cXyz mBlureScale;
            }
            /* 0x700 */ field_0x700;
            /* 0x730 */ float mBlureAlpha;
            /* 0x734 */ float field_0x734;
            /* 0x738 */ float field_0x738;
            /* 0x73C */ float field_0x73c;
            class
            {
               public:
                /* 0x00 */ cXyz field_0x0;
                /* 0x0C */ cXyz field_0xc;
                /* 0x18 */ cXyz field_0x18;
                /* 0x24 */ void* field_0x24;
            }
            /* 0x740 */ field_0x740;
            /* 0x76C */ uint8_t field_0x76c[0x79c - 0x76c];
            class
            {
               public:
                /* 0x0 */ uint8_t field_0x0[4];
                /* 0x4 */ cXyz field_0x4;
            }
            /* 0x79C */ field_0x79c;
            /* 0x7AC */ void* field_0x7ac;
            /* 0x7E8 */ void* field_0x7e8;
            /* 0x824 */ void* field_0x824;
            /* 0x860 */ void* field_0x860;
            /* 0x89C */ void* field_0x89c;
            /* 0x8D8 */ void* field_0x8d8;
            /* 0x914 */ uint8_t field_0x914[0x91c - 0x914];
            /* 0x91C */ float field_0x91c;
            /* 0x920 */ float mTrimHeight;
            /* 0x924 */ int32_t mTrimSize;
            /* 0x928 */ int32_t mTrimTypeForce;
            /* 0x92C */ uint8_t field_0x92c[0x934 - 0x92c];
            /* 0x934 */ float field_0x934;
            /* 0x938 */ uint8_t field_0x938[0x93C - 0x938];
            /* 0x93C */ int32_t field_0x93c;
            /* 0x940 */ int32_t field_0x940;
            /* 0x944 */ uint8_t field_0x944;
            /* 0x948 */ int32_t field_0x948;
            /* 0x94C */ void* field_0x94c;
            /* 0x950 */ int32_t field_0x950;
            /* 0x954 */ uint8_t field_0x954[0x958 - 0x954];
            /* 0x958 */ int32_t field_0x958;
            /* 0x95C */ cXyz field_0x95c;
            /* 0x968 */ uint8_t field_0x968[0x970 - 0x968];
            /* 0x970 */ void* mCamSetup;
            /* 0xAEC */ void* mCamParam;
            /* 0xB0C */ uint8_t field_0xb0c;
            /* 0xB0D */ uint8_t field_0xb0d[0xd58 - 0xb0d];
        };
        static_assert(sizeof(dCamera_c) == 0xD58);

        /**
         *  @brief Checks to see if Link is riding something (Spinner/Boar/Snowboard/etc.).
         *
         *  @param d_a_alink  A pointer to Link's actor
         *
         *  @return Bool returns True if Link is riding something, otherwise returns False.
         */
        bool checkRide(d_a_alink::daAlink* d_a_alink);

        /**
         *  @brief Change Camera orientation
         *
         */
        void updatePad(libtp::tp::d_camera::dCamera_c* d_camera_c);
    }
} // namespace libtp::tp::d_camera
#endif