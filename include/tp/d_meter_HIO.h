/**	@file d_meter_HIO.h
 *	@brief Contains definitions and functions that have to do with verious graphical and event functions.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_METER_HIO_H
#define TP_D_METER_HIO_H

#include <cstdint>

#include "SSystem/SComponent/c_xyz.h"
#include "SSystem/SComponent/c_sxyz.h"

namespace libtp::tp::d_meter_hio
{
    // Functions used by classes/structs
    extern "C"
    {
        // dMeter_menuHIO_c
        void* dMeter_menuHIO_c_ct(void* dMeter_menuHIO_c);                   // Constructor
        void* dMeter_menuHIO_c_dt(void* dMeter_menuHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawCollectHIO_c
        void* dMeter_drawCollectHIO_c_ct(void* dMeter_drawCollectHIO_c);                   // Constructor
        void* dMeter_drawCollectHIO_c_dt(void* dMeter_drawCollectHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawOptionHIO_c
        void* dMeter_drawOptionHIO_c_ct(void* dMeter_drawOptionHIO_c);                   // Constructor
        void* dMeter_drawOptionHIO_c_dt(void* dMeter_drawOptionHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawLetterHIO_c
        void* dMeter_drawLetterHIO_c_ct(void* dMeter_drawLetterHIO_c);                   // Constructor
        void* dMeter_drawLetterHIO_c_dt(void* dMeter_drawLetterHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawFishingHIO_c
        void* dMeter_drawFishingHIO_c_ct(void* dMeter_drawFishingHIO_c);                   // Constructor
        void* dMeter_drawFishingHIO_c_dt(void* dMeter_drawFishingHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawInsectHIO_c
        void* dMeter_drawInsectHIO_c_ct(void* dMeter_drawInsectHIO_c);                   // Constructor
        void* dMeter_drawInsectHIO_c_dt(void* dMeter_drawInsectHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawCalibrationHIO_c
        void* dMeter_drawCalibrationHIO_c_ct(void* dMeter_drawCalibrationHIO_c);                   // Constructor
        void* dMeter_drawCalibrationHIO_c_dt(void* dMeter_drawCalibrationHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawSkillHIO_c
        void* dMeter_drawSkillHIO_c_ct(void* dMeter_drawSkillHIO_c);                   // Constructor
        void* dMeter_drawSkillHIO_c_dt(void* dMeter_drawSkillHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawEmpButtonHIO_c
        void* dMeter_drawEmpButtonHIO_c_ct(void* dMeter_drawEmpButtonHIO_c);                   // Constructor
        void* dMeter_drawEmpButtonHIO_c_dt(void* dMeter_drawEmpButtonHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawMiniGameHIO_c
        void* dMeter_drawMiniGameHIO_c_ct(void* dMeter_drawMiniGameHIO_c);                   // Constructor
        void* dMeter_drawMiniGameHIO_c_dt(void* dMeter_drawMiniGameHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawLightDropHIO_c
        void* dMeter_drawLightDropHIO_c_ct(void* dMeter_drawLightDropHIO_c);                   // Constructor
        void* dMeter_drawLightDropHIO_c_dt(void* dMeter_drawLightDropHIO_c, int16_t freeThis); // Destructor

        // dMeter_drawHIO_c
        void* dMeter_drawHIO_c_ct(void* dMeter_drawHIO_c);                   // Constructor
        void* dMeter_drawHIO_c_dt(void* dMeter_drawHIO_c, int16_t freeThis); // Destructor

        // dMeter_ringHIO_c
        void* dMeter_ringHIO_c_ct(void* dMeter_ringHIO_c);                   // Constructor
        void* dMeter_ringHIO_c_dt(void* dMeter_ringHIO_c, int16_t freeThis); // Destructor

        // dMeter_mapIconHIO_c
        void* dMeter_mapIconHIO_c_ct(void* dMeter_mapIconHIO_c);                   // Constructor
        void* dMeter_mapIconHIO_c_dt(void* dMeter_mapIconHIO_c, int16_t freeThis); // Destructor

        // dMeter_fmapHIO_c
        void* MapBlinkAnime_ct(void* MapBlinkAnime);                         // Constructor
        void* dMeter_fmapHIO_c_ct(void* dMeter_fmapHIO_c);                   // Constructor
        void* dMeter_fmapHIO_c_dt(void* dMeter_fmapHIO_c, int16_t freeThis); // Destructor

        // dMeter_cursorHIO_c
        void* dMeter_cursorHIO_c_ct(void* dMeter_cursorHIO_c);                   // Constructor
        void* dMeter_cursorHIO_c_dt(void* dMeter_cursorHIO_c, int16_t freeThis); // Destructor
    }

    class dMeter_menuHIO_c
    {
       public:
        dMeter_menuHIO_c() { dMeter_menuHIO_c_ct(this); }

        /* 0x0 */ void* vtable;
        /* 0x4 */ uint8_t field_0x4[2];
        /* 0x6 */ int16_t mGameover;
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_menuHIO_c) == 0x8);

    class dMeter_drawCollectHIO_c
    {
       public:
        dMeter_drawCollectHIO_c() { dMeter_drawCollectHIO_c_ct(this); }

        enum
        {
            /* 0x0 */ VESSEL_HEART,
            /* 0x1 */ VESSEL_DECOR
        };

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x04[4];
        /* 0x08 */ float mUnselectItemScale;
        /* 0x0C */ float mSelectItemScale;
        /* 0x10 */ float mUnselectSaveOptionScale;
        /* 0x14 */ float mSelectSaveOptionScale;
        /* 0x18 */ float mBlueSmokePosX;
        /* 0x1C */ float mBlueSmokePosY;
        /* 0x20 */ float mBlueSmokeScale;
        /* 0x24 */ float mBlueSmokeAlpha;
        /* 0x28 */ cXyz mMaskMirrorPos;
        /* 0x34 */ float mMaskMirrorScale;
        /* 0x38 */ float mMaskMirrorAnimSpeed;
        /* 0x3C */ float mHeartVesselPosX;
        /* 0x40 */ float mHeartVesselPosY;
        /* 0x44 */ float mHeartVesselScale;
        /* 0x48 */ float mAButtonPosX;
        /* 0x4C */ float mAButtonPosY;
        /* 0x50 */ float mAButtonScale;
        /* 0x54 */ float mBButtonPosX;
        /* 0x58 */ float mBButtonPosY;
        /* 0x5C */ float mBButtonScale;
        /* 0x60 */ float mAButtonTextPosX;
        /* 0x64 */ float mAButtonTextPosY;
        /* 0x68 */ float mAButtonTextScale;
        /* 0x6C */ float mBButtonTextPosX;
        /* 0x70 */ float mBButtonTextPosY;
        /* 0x74 */ float mBButtonTextScale;
        /* 0x78 */ uint32_t mVesselBack[2];  // JUtility::TColor
        /* 0x80 */ uint32_t mVesselFront[2]; // JUtility::TColor
        /* 0x88 */ float mHeartPiecePosX;
        /* 0x8C */ float mHeartPiecePosY;
        /* 0x90 */ float mHeartPieceScale;
        /* 0x94 */ csXyz mMaskMirrorAngle;
        /* 0x9A */ bool field_0x9a;
        /* 0x9B */ bool mColorDebugON;
        /* 0x9C */ bool mButtonDebugON;
        /* 0x9D */ uint8_t padding[3];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawCollectHIO_c) == 0xA0);

    class dMeter_drawOptionHIO_c
    {
       public:
        dMeter_drawOptionHIO_c() { dMeter_drawOptionHIO_c_ct(this); }

        enum OptionType
        {
            /* 0x0 */ ATTENTION,
            /* 0x1 */ RUMBLE,
            /* 0x2 */ SOUND
        };

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x4[4];
        /* 0x08 */ float mArrowSize;
        /* 0x0C */ uint32_t mSelectNameColor; // JUtility::TColor
        /* 0x10 */ uint32_t mSelectColor;     // JUtility::TColor
        /* 0x14 */ uint32_t mUnselectColor;   // JUtility::TColor
        /* 0x18 */ float mWindowPosX;
        /* 0x1C */ float mWindowPosY;
        /* 0x20 */ float mWindowScale;
        /* 0x24 */ float mOptionTypeBGPosX[4];
        /* 0x34 */ float mTVsettingPosX;
        /* 0x38 */ float mPointerCalibrationPosX;
        /* 0x3C */ float mOptionTypeBGPosY[4];
        /* 0x4C */ float mTVsettingPosY;
        /* 0x50 */ float mPointerCalibrationPosY;
        /* 0x54 */ float mSelectBarScale;
        /* 0x58 */ float mUnselectBarScale;
        /* 0x5C */ float mBackgroundPosY;
        /* 0x60 */ float mArrowOffsetX;
        /* 0x64 */ float mArrowOffsetX_4x3;
        /* 0x68 */ int16_t mOpenFrames;
        /* 0x6A */ int16_t mCloseFrames;
        /* 0x6C */ bool mDebug;
        /* 0x6D */ uint8_t mBackgroundAlpha;
        /* 0x6E */ uint8_t padding[2];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawOptionHIO_c) == 0x70);

    class dMeter_drawLetterHIO_c
    {
       public:
        dMeter_drawLetterHIO_c() { dMeter_drawLetterHIO_c_ct(this); }

        enum
        {
            /* 0x0 */ WINDOW_FRAME,
            /* 0x1 */ LETTER_FRAME
        };

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x4[4];
        /* 0x08 */ float mSelectBarScale;
        /* 0x0C */ float mUnselectBarScale;
        /* 0x10 */ float mWindowPosX;
        /* 0x14 */ float mWindowPosY;
        /* 0x18 */ float mWindowScale;
        /* 0x1C */ float mLetterWindowPosX;
        /* 0x20 */ float mLetterWindowPosY;
        /* 0x24 */ float mLetterWindowScale;
        /* 0x28 */ float mLetterLinePosX;
        /* 0x2C */ float mLetterLinePosY;
        /* 0x30 */ int16_t mOpenFrame[2];
        /* 0x34 */ int16_t mCloseFrame[2];
        /* 0x38 */ int16_t mLetterNum;
        /* 0x3A */ uint8_t field_0x3a[2];
        /* 0x3C */ uint32_t mSelectPageIconBack;  // JUtility::TColor
        /* 0x40 */ uint32_t mSelectPageIconFront; // JUtility::TColor
        /* 0x44 */ uint32_t mSelectBarBack;       // JUtility::TColor
        /* 0x48 */ uint32_t mSelectBarFront;      // JUtility::TColor
        /* 0x4C */ uint32_t mSelectTextBack;      // JUtility::TColor
        /* 0x50 */ uint32_t mSelectTextFront;     // JUtility::TColor
        /* 0x54 */ uint32_t mLetterTextBack;      // JUtility::TColor
        /* 0x58 */ uint32_t mLetterTextFront;     // JUtility::TColor
        /* 0x5C */ uint8_t mUnselectPageIconAlpha;
        /* 0x5D */ uint8_t mWindowBGAlpha;
        /* 0x5E */ uint8_t mLetterLineAlpha;
        /* 0x5F */ bool mDebugON;
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawLetterHIO_c) == 0x60);

    class dMeter_drawFishingHIO_c
    {
       public:
        dMeter_drawFishingHIO_c() { dMeter_drawFishingHIO_c_ct(this); }

        enum
        {
            /* 0x0 */ HYLIAN_BASS,
            /* 0x1 */ HYLIAN_LOACH,
            /* 0x2 */ HYLIAN_PIKE,
            /* 0x3 */ ORDON_CATFISH,
            /* 0x4 */ REEKFISH,
            /* 0x5 */ GREENGILL
        };

        /* 0x000 */ void* vtable;
        /* 0x004 */ uint8_t field_0x4[4];
        /* 0x008 */ float mFishIconScale[6];
        /* 0x020 */ float mFishIconPosX[6];
        /* 0x038 */ float mFishIconPosY[6];
        /* 0x050 */ float mFishNameScale[6];
        /* 0x068 */ float mFishNamePosX[6];
        /* 0x080 */ float mFishNamePosY[6];
        /* 0x098 */ float mFishLineScale[6];
        /* 0x0B0 */ float mFishLinePosX[6];
        /* 0x0C8 */ float mFishLinePosY[6];
        /* 0x0E0 */ float mFishSizeScale[6];
        /* 0x0F8 */ float mFishSizePosX[6];
        /* 0x110 */ float mFishSizePosY[6];
        /* 0x128 */ float mFishCountScale[6];
        /* 0x140 */ float mFishCountPosX[6];
        /* 0x158 */ float mFishCountPosY[6];
        /* 0x170 */ float mFishCountSizeScale[6];
        /* 0x188 */ float mFishCountSizePosX[6];
        /* 0x1A0 */ float mFishCountSizePosY[6];
        /* 0x1B8 */ float mFishInfoScale[6];
        /* 0x1D0 */ float mFishInfoPosX[6];
        /* 0x1E8 */ float mFishInfoPosY[6];
        /* 0x200 */ float mMaxSizeScale;
        /* 0x204 */ float mCaughtNumScale;
        /* 0x208 */ float mMaxSizePosX;
        /* 0x20C */ float mCaughtNumPosX;
        /* 0x210 */ float mCaughtNumPosX_4x3;
        /* 0x214 */ float mMaxSizePosY;
        /* 0x218 */ float mCaughtNumPosY;
        /* 0x21C */ int16_t mOpenFrames;
        /* 0x21E */ int16_t mCloseFrames;
        /* 0x220 */ int16_t mFishNum[6];
        /* 0x22C */ uint8_t field_0x22c[0x14];
        /* 0x240 */ uint8_t mFishSize[6];
        /* 0x246 */ uint8_t field_0x246[0xA];
        /* 0x250 */ bool mDebug;
        /* 0x251 */ uint8_t padding[3];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawFishingHIO_c) == 0x254);

    class dMeter_drawInsectHIO_c
    {
       public:
        dMeter_drawInsectHIO_c() { dMeter_drawInsectHIO_c_ct(this); }

        enum Type
        {
            /* 0x0 */ DEFAULT,
            /* 0x1 */ COLLECT,
            /* 0x2 */ AGITHA
        };

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x4[4];
        /* 0x08 */ float mUnselectInsectScale;
        /* 0x0C */ float mSelectInsectScale;
        /* 0x10 */ float mDescWindowPosX;
        /* 0x14 */ float mDescWindowPosY;
        /* 0x18 */ float mGiveOptionPosX_4x3;
        /* 0x1C */ float mGiveOptionPosX;
        /* 0x20 */ float mGiveOptionPosY_4x3;
        /* 0x24 */ float mGiveOptionPosY;
        /* 0x28 */ float mConfirmOptionPosX_4x3;
        /* 0x2C */ float mConfirmOptionPosX;
        /* 0x30 */ float mConfirmOptionPosY_4x3;
        /* 0x34 */ float mConfirmOptionPosY;
        /* 0x38 */ int16_t mOpenFrame;
        /* 0x3A */ int16_t mCloseFrame;
        /* 0x3C */ uint8_t mType;
        /* 0x3D */ bool mDebugON;
        /* 0x3E */ uint8_t padding[2];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawInsectHIO_c) == 0x40);

    class dMeter_drawCalibrationHIO_c
    {
       public:
        dMeter_drawCalibrationHIO_c() { dMeter_drawCalibrationHIO_c_ct(this); }

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x4[4];
        /* 0x08 */ float mCircleScale;
        /* 0x0C */ float mCircleScale2;
        /* 0x10 */ int16_t mOpenFrames;
        /* 0x12 */ int16_t mCloseFrames;
        /* 0x14 */ int16_t mFlashFrameNum;
        /* 0x16 */ bool mDebug;
        /* 0x17 */ uint8_t padding[1];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawCalibrationHIO_c) == 0x18);

    class dMeter_drawSkillHIO_c
    {
       public:
        dMeter_drawSkillHIO_c() { dMeter_drawSkillHIO_c_ct(this); }

        enum
        {
            /* 0x0 */ WINDOW,
            /* 0x1 */ SKILL_DESC,
        };

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x4[4];
        /* 0x08 */ float mSelectBarScale;
        /* 0x0C */ float mUnselectBarScale;
        /* 0x10 */ float mSkillDescPosX;
        /* 0x14 */ float mSkillDescPosY;
        /* 0x18 */ float mSkillDescScale;
        /* 0x1C */ float mSkillTitlePosX;
        /* 0x20 */ float mSkillTitlePosY;
        /* 0x24 */ float mSkillTitleScale;
        /* 0x28 */ float mWindowLinePosX;
        /* 0x2C */ float mWindowLinePosY;
        /* 0x30 */ int16_t mOpenFrame[2];
        /* 0x34 */ int16_t mCloseFrame[2];
        /* 0x38 */ uint32_t mSelectScrollIconBlack;   // JUtility::TColor
        /* 0x3C */ uint32_t mSelectScrollIconWhite;   // JUtility::TColor
        /* 0x40 */ uint32_t mUnselectScrollIconBlack; // JUtility::TColor
        /* 0x44 */ uint32_t mUnselectScrollIconWhite; // JUtility::TColor
        /* 0x48 */ uint32_t mSelectBarBlack;          // JUtility::TColor
        /* 0x4C */ uint32_t mSelectBarWhite;          // JUtility::TColor
        /* 0x50 */ uint32_t mSelectTextBlack;         // JUtility::TColor
        /* 0x54 */ uint32_t mSelectTextWhite;         // JUtility::TColor
        /* 0x58 */ uint8_t field_0x58;
        /* 0x59 */ uint8_t mWindowBGalpha;
        /* 0x5A */ uint8_t mWindowLineAlpha;
        /* 0x5B */ bool mDebug;
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawSkillHIO_c) == 0x5C);

    class dMeter_drawEmpButtonHIO_c
    {
       public:
        dMeter_drawEmpButtonHIO_c() { dMeter_drawEmpButtonHIO_c_ct(this); }

        /* 0x000 */ void* vtable;
        /* 0x004 */ uint8_t field_0x4[4];
        /* 0x008 */ float mEmpButtonPosX;
        /* 0x00C */ float mEmpButtonPosY;
        /* 0x010 */ float mEmpButtonScale;
        /* 0x014 */ float mAButtonPosX;
        /* 0x018 */ float mAButtonPosY;
        /* 0x01C */ float mAButtonScale;
        /* 0x020 */ float mBButtonPosX;
        /* 0x024 */ float mBButtonPosY;
        /* 0x028 */ float mBButtonScale;
        /* 0x02C */ float mRButtonPosX;
        /* 0x030 */ float mRButtonPosY;
        /* 0x034 */ float mRButtonScale;
        /* 0x038 */ float mZButtonPosX;
        /* 0x03C */ float mZButtonPosY;
        /* 0x040 */ float mZButtonScale;
        /* 0x044 */ float m3DButtonPosX;
        /* 0x048 */ float m3DButtonPosY;
        /* 0x04C */ float m3DButtonScale;
        /* 0x050 */ float mCButtonPosX;
        /* 0x054 */ float mCButtonPosY;
        /* 0x058 */ float mCButtonScale;
        /* 0x05C */ float mSButtonPosX;
        /* 0x060 */ float mSButtonPosY;
        /* 0x064 */ float mSButtonScale;
        /* 0x068 */ float mXButtonPosX;
        /* 0x06C */ float mXButtonPosY;
        /* 0x070 */ float mXButtonScale;
        /* 0x074 */ float mYButtonPosX;
        /* 0x078 */ float mYButtonPosY;
        /* 0x07C */ float mYButtonScale;
        /* 0x080 */ float mNunchukPosX;
        /* 0x084 */ float mNunchukPosY;
        /* 0x088 */ float mNunchukScale;
        /* 0x08C */ float mWiimotePosX;
        /* 0x090 */ float mWiimotePosY;
        /* 0x094 */ float mWiimoteScale;
        /* 0x098 */ float mWiimoteLRPosX;
        /* 0x09C */ float mWiimoteLRPosY;
        /* 0x0A0 */ float mWiimoteLRScale;
        /* 0x0A4 */ float mNunchukZButtonPosX;
        /* 0x0A8 */ float mNunchukZButtonPosY;
        /* 0x0AC */ float mNunchukZButtonScale;
        /* 0x0B0 */ float mNunchukCButtonPosX;
        /* 0x0B4 */ float mNunchukCButtonPosY;
        /* 0x0B8 */ float mNunchukCButtonScale;
        /* 0x0BC */ float mWiimoteAPosX;
        /* 0x0C0 */ float mWiimoteAPosY;
        /* 0x0C4 */ float mWiimoteAScale;
        /* 0x0C8 */ float m3DBButtonPosX;
        /* 0x0CC */ float m3DBButtonPosY;
        /* 0x0D0 */ float m3DBButtonScale;
        /* 0x0D4 */ float mNunchukWiimotePosX;
        /* 0x0D8 */ float mNunchukWiimotePosY;
        /* 0x0DC */ float mNunchukWiimoteScale;
        /* 0x0E0 */ float mNunchukWiimoteRealPosX;
        /* 0x0E4 */ float mNunchukWiimoteRealPosY;
        /* 0x0E8 */ float mNunchukWiimoteRealScale;
        /* 0x0EC */ float mNunchukRealPosX;
        /* 0x0F0 */ float mNunchukRealPosY;
        /* 0x0F4 */ float mNunchukRealScale;
        /* 0x0F8 */ float mNunchukAttackPosX;
        /* 0x0FC */ float mNunchukAttackPosY;
        /* 0x100 */ float mNunchukAttackScale;
        /* 0x104 */ float mABButtonPosX;
        /* 0x108 */ float mABButtonPosY;
        /* 0x10C */ float mABButtonScale;
        /* 0x110 */ float mBottleIconPosX;
        /* 0x114 */ float mBottleIconPosY;
        /* 0x118 */ float mBottleIconScale;
        /* 0x11C */ float mViewChangePosX;
        /* 0x120 */ float mViewChangePosY;
        /* 0x124 */ float mViewChangeScale;
        /* 0x128 */ float mText1PosX;
        /* 0x12C */ float mText2PosX;
        /* 0x130 */ float mText1PosY;
        /* 0x134 */ float mText2PosY;
        /* 0x138 */ float mText1Scale;
        /* 0x13C */ float mText2Scale;
        /* 0x140 */ float mItemPosX;
        /* 0x144 */ float mItemPosY;
        /* 0x148 */ float mItemScale;
        /* 0x14C */ float mMidnaIconPosX;
        /* 0x150 */ float mMidnaIconPosY;
        /* 0x154 */ float mMidnaIconScale;
        /* 0x158 */ float mHawkeyePosX;
        /* 0x15C */ float mHawkeyePosY;
        /* 0x160 */ float mHawkeyeTextPosX;
        /* 0x164 */ float mHawkeyePlusPosX;
        /* 0x168 */ float mHawkeyeMinusPosX;
        /* 0x16C */ float mHawkeyeTextPosY[3];
        /* 0x178 */ float mHawkeyeZoomPosX;
        /* 0x17C */ float mHawkeyeZoomPosY;
        /* 0x180 */ float mHawkeyeZoomScale;
        /* 0x184 */ float mHawkeyeZoomScale_4x3;
        /* 0x188 */ float mHawkeyeTextIconPosX;
        /* 0x18C */ float mHawkeyeZoomTextPosX;
        /* 0x190 */ float mHawkeyeIconPosX;
        /* 0x194 */ float mHawkeyeTextIconPosY_4x3;
        /* 0x198 */ float mHawkeyeTextPosY_4x3;
        /* 0x19C */ float mHawkeyeIconPosY_4x3;
        /* 0x1A0 */ float mHawkeyeTextIconPosY;
        /* 0x1A4 */ float mHawkeyeZoomTextPosY;
        /* 0x1A8 */ float mHawkeyeIconPosY;
        /* 0x1AC */ float mHawkeyeTextIconScale;
        /* 0x1B0 */ float mHawkeyeTextScale;
        /* 0x1B4 */ float mHawkeyeIconScale;
        /* 0x1B8 */ uint32_t mPointerONBlack[2]; // JUtility::TColor
        /* 0x1C0 */ uint32_t mPointerONWhite[2]; // JUtility::TColor
        /* 0x1C8 */ uint32_t mPointerOFFBlack;   // JUtility::TColor
        /* 0x1CC */ uint32_t mPointerOFFWhite;   // JUtility::TColor
        /* 0x1D0 */ float mPointerONScale;
        /* 0x1D4 */ float mPointerOFFScale;
        /* 0x1D8 */ int16_t mPointerONAnimFrame;
        /* 0x1DA */ uint8_t padding_1da[2];
        /* 0x1DC */ float mHighlightScale;
        /* 0x1E0 */ uint32_t mHighlightFrontInner; // JUtility::TColor
        /* 0x1E4 */ uint32_t mHighlightFrontOuter; // JUtility::TColor
        /* 0x1E8 */ uint32_t mHighlightBackInner;  // JUtility::TColor
        /* 0x1EC */ uint32_t mHighlightBackOuter;  // JUtility::TColor
        /* 0x1F0 */ float mHighlightAnimSpeed;
        /* 0x1F4 */ float mHighlightFastScale;
        /* 0x1F8 */ uint32_t mHighlightFastFrontInner; // JUtility::TColor
        /* 0x1FC */ uint32_t mHighlightFastFrontOuter; // JUtility::TColor
        /* 0x200 */ uint32_t mHighlightFastBackInner;  // JUtility::TColor
        /* 0x204 */ uint32_t mHighlightFastBackOuter;  // JUtility::TColor
        /* 0x208 */ float mHighlightFastAnimSpeed;
        /* 0x20C */ float mHighlightListenScale;
        /* 0x210 */ uint32_t mHighlightListenFrontInner; // JUtility::TColor
        /* 0x214 */ uint32_t mHighlightListenFrontOuter; // JUtility::TColor
        /* 0x218 */ uint32_t mHighlightListenBackInner;  // JUtility::TColor
        /* 0x21C */ uint32_t mHighlightListenBackOuter;  // JUtility::TColor
        /* 0x220 */ float mHighlightListenAnimSpeed;
        /* 0x224 */ float mHighlightRepeatHitScale;
        /* 0x228 */ uint32_t mHighlightRepeatHitFrontInner; // JUtility::TColor
        /* 0x22C */ uint32_t mHighlightRepeatHitFrontOuter; // JUtility::TColor
        /* 0x230 */ uint32_t mHighlightRepeatHitBackInner;  // JUtility::TColor
        /* 0x234 */ uint32_t mHighlightRepeatHitBackOuter;  // JUtility::TColor
        /* 0x238 */ float mHighlightRepeatHitAnimSpeed;
        /* 0x23C */ float mRepeatHitScale;
        /* 0x240 */ int16_t mRepeatHitFrameNum;
        /* 0x242 */ uint8_t padding_242[2];
        /* 0x244 */ float mDisplaySpace;
        /* 0x248 */ uint8_t mDebugDisplayButton[17];
        /* 0x259 */ bool mHawkeyeDebugON;
        /* 0x25A */ bool mHawkeyeZoomDebugON;
        /* 0x25B */ uint8_t padding_25b[1];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawEmpButtonHIO_c) == 0x25C);

    class dMeter_drawMiniGameHIO_c
    {
       public:
        dMeter_drawMiniGameHIO_c() { dMeter_drawMiniGameHIO_c_ct(this); }

        /* 0x000 */ void* vtable;
        /* 0x004 */ uint8_t field_0x4[4];
        /* 0x008 */ float field_0x8;
        /* 0x00C */ float mRiverRideTargetCounterSizeY;
        /* 0x010 */ float field_0x10;
        /* 0x014 */ float field_0x14;
        /* 0x018 */ float mRiverRideTargetCounterPosX;
        /* 0x01C */ float field_0x1c;
        /* 0x020 */ float field_0x20;
        /* 0x024 */ float mRiverRideTargetCounterPosY;
        /* 0x028 */ float field_0x28;
        /* 0x02C */ float field_0x2c;
        /* 0x030 */ float mRiverRideTargetCounterAlpha;
        /* 0x034 */ float field_0x34;
        /* 0x038 */ float mGoatTimerSizeX;
        /* 0x03C */ float field_0x3c;
        /* 0x040 */ float field_0x40;
        /* 0x044 */ float mGoatTimerSizeY;
        /* 0x048 */ float field_0x48;
        /* 0x04C */ float field_0x4c;
        /* 0x050 */ float mGoatTimerPosX;
        /* 0x054 */ float field_0x54;
        /* 0x058 */ float field_0x58;
        /* 0x05C */ float mGoatTimerPosY;
        /* 0x060 */ float field_0x60;
        /* 0x064 */ float field_0x64;
        /* 0x068 */ float mGoatTimerAlpha;
        /* 0x06C */ float field_0x6c;
        /* 0x070 */ float field_0x70;
        /* 0x074 */ float mGoatCounterSizeX;
        /* 0x078 */ float mRiverRideCounterSizeX;
        /* 0x07C */ float mRiderGameCounterSizeX;
        /* 0x080 */ float mGoatCounterSizeY;
        /* 0x084 */ float mRiverRideCounterSizeY;
        /* 0x088 */ float mRiderGameCounterSizeY;
        /* 0x08C */ float mGoatCounterPosX;
        /* 0x090 */ float mRiverRideCounterPosX;
        /* 0x094 */ float mRiderGameCounterPosX;
        /* 0x098 */ float mGoatCounterPosY;
        /* 0x09C */ float mRiverRideCounterPosY;
        /* 0x0A0 */ float mRiderGameCounterPosY;
        /* 0x0A4 */ float mGoatCounterAlpha;
        /* 0x0A8 */ float mRiverRideCounterAlpha;
        /* 0x0AC */ float mRiderGameCounterAlpha;
        /* 0x0B0 */ float mGoatIconSizeX;
        /* 0x0B4 */ float mRiverRideTargetIconSizeX;
        /* 0x0B8 */ float mRiderGameIconSizeX;
        /* 0x0BC */ float mGoatIconSizeY;
        /* 0x0C0 */ float mRiverRideTargetIconSizeY;
        /* 0x0C4 */ float mRiderGameIconSizeY;
        /* 0x0C8 */ float mGoatIconPosX;
        /* 0x0CC */ float mRiverRideTargetIconPosX;
        /* 0x0D0 */ float mRiderGameIconPosX;
        /* 0x0D4 */ float mGoatIconPosY;
        /* 0x0D8 */ float mRiverRideTargetIconPosY;
        /* 0x0DC */ float mRiderGameIconPosY;
        /* 0x0E0 */ float mGoatIconAlpha;
        /* 0x0E4 */ float mRiverRideTargetIconAlpha;
        /* 0x0E8 */ float mRiderGameIconAlpha;
        /* 0x0EC */ float mGoatTimerSizeX_4x3;
        /* 0x0F0 */ float mGoatTimerSizeY_4x3;
        /* 0x0F4 */ float mGoatTimerPosX_4x3;
        /* 0x0F8 */ float mGoatTimerPosY_4x3;
        /* 0x0FC */ float mGoatIconPosX_4x3;
        /* 0x100 */ float mRiverRideIconPosX_4x3;
        /* 0x104 */ float mRiderGameIconPosX_4x3;
        /* 0x108 */ float mGetInTextSizeX;
        /* 0x10C */ float mGetInTextSizeY;
        /* 0x110 */ float mGetInTextPosX;
        /* 0x114 */ float mGetInTextPosY;
        /* 0x118 */ float mGetInTextAnimSpeed;
        /* 0x11C */ int16_t mGetInTextWaitFrames;
        /* 0x11E */ int16_t mGetInTextAlphaFrames;
        /* 0x120 */ float mGetInHighlightScale;
        /* 0x124 */ uint32_t mGetInHighlightFrontInner; // JUtility::TColor
        /* 0x128 */ uint32_t mGetInHighlightFrontOuter; // JUtility::TColor
        /* 0x12C */ uint32_t mGetInHighlightBackInner;  // JUtility::TColor
        /* 0x130 */ uint32_t mGetInHighlightBackOuter;  // JUtility::TColor
        /* 0x134 */ float mGetInHighlightAnimSpeed;
        /* 0x138 */ int16_t mGetInHighlightAppearFrames;
        /* 0x13A */ uint8_t mGetInTextLocation;
        /* 0x13B */ uint8_t padding_13b[1];
        /* 0x13C */ float mStartHighlightScale;
        /* 0x140 */ uint32_t mStartHighlightFrontInner; // JUtility::TColor
        /* 0x144 */ uint32_t mStartHighlightFrontOuter; // JUtility::TColor
        /* 0x148 */ uint32_t mStartHighlightBackInner;  // JUtility::TColor
        /* 0x14C */ uint32_t mStartHighlightBackOuter;  // JUtility::TColor
        /* 0x150 */ float mStartHighlightAnimSpeed;
        /* 0x154 */ int16_t mStartHighlightAppearFrames;
        /* 0x156 */ int16_t mStartHighlightDisplayFrames;
        /* 0x158 */ int16_t mReadyGo;
        /* 0x15A */ int16_t field_0x15a;
        /* 0x15C */ float mReadyFightTextSizeX;
        /* 0x160 */ float mReadyFightTextSizeY;
        /* 0x164 */ float mReadyFightTextPosX;
        /* 0x168 */ float mReadyFightTextPosY;
        /* 0x16C */ float mReadyFightTextAnimSpeed;
        /* 0x170 */ int16_t mReadyFightTextWaitFrames;
        /* 0x172 */ int16_t field_0x172;
        /* 0x174 */ float mReadyFightHighlightScale;
        /* 0x178 */ uint32_t mReadyFightHighlightFrontInner; // JUtility::TColor
        /* 0x17C */ uint32_t mReadyFightHighlightFrontOuter; // JUtility::TColor
        /* 0x180 */ uint32_t mReadyFightHighlightBackInner;  // JUtility::TColor
        /* 0x184 */ uint32_t mReadyFightHighlightBackOuter;  // JUtility::TColor
        /* 0x188 */ float mReadyFightHighlightAnimSpeed;
        /* 0x18C */ int16_t mReadyFightHighlightAppearFrames;
        /* 0x18E */ uint8_t padding_18e[2];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawMiniGameHIO_c) == 0x190);

    class dMeter_drawLightDropHIO_c
    {
       public:
        dMeter_drawLightDropHIO_c() { dMeter_drawLightDropHIO_c_ct(this); }

        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t field_0x4[4];
        /* 0x08 */ float mVesselScale;
        /* 0x0C */ float mVesselTalkScale;
        /* 0x10 */ float mVesselPosX;
        /* 0x14 */ float mVesselTalkPosX;
        /* 0x18 */ float mVesselPosY;
        /* 0x1C */ float mVesselTalkPosY;
        /* 0x20 */ float mVesselPosX_4x3;
        /* 0x24 */ float mVesselPosY_4x3;
        /* 0x28 */ float mVesselAlpha;
        /* 0x2C */ float mVesselTalkAlpha;
        /* 0x30 */ float mVesselDecorAlpha;
        /* 0x34 */ float mDropAlpha;
        /* 0x38 */ uint32_t mDropOnColorWhite;  // JUtility::TColor
        /* 0x3C */ uint32_t mDropOnColorBlack;  // JUtility::TColor
        /* 0x40 */ uint32_t mDropOffColorWhite; // JUtility::TColor
        /* 0x44 */ uint32_t mDropOffColorBlack; // JUtility::TColor
        /* 0x48 */ float mDropScale;
        /* 0x4C */ float mDropGetScale;
        /* 0x50 */ int16_t mDropGetScaleAnimFrameNum;
        /* 0x52 */ int16_t mHighlightInterval;
        /* 0x54 */ int16_t field_0x54;
        /* 0x56 */ int16_t field_0x56;
        /* 0x58 */ uint32_t mDropHighlightFrontInner; // JUtility::TColor
        /* 0x5C */ uint32_t mDropHighlightFrontOuter; // JUtility::TColor
        /* 0x60 */ uint32_t mDropHighlightBackInner;  // JUtility::TColor
        /* 0x64 */ uint32_t mDropHighlightBackOuter;  // JUtility::TColor
        /* 0x68 */ float mDropHighlightAnimSpeed;
        /* 0x6C */ float mDropHighlightAnimSpeed_Completed;
        /* 0x70 */ uint32_t mHighlightLoopFrontInner[2]; // JUtility::TColor
        /* 0x78 */ uint32_t mHighlightLoopFrontOuter[2]; // JUtility::TColor
        /* 0x80 */ uint32_t mHighlightLoopBackInner[2];  // JUtility::TColor
        /* 0x88 */ uint32_t mHighlightLoopBackOuter[2];  // JUtility::TColor
        /* 0x90 */ float mHighlightLoopAnimSpeed;
        /* 0x94 */ float mHighlightLoopBackStopFrame;
        /* 0x98 */ float mHighlightScaleNormal;
        /* 0x9C */ float mHighlightScaleComplete;
        /* 0xA0 */ float mHighlightLoopScale;
        /* 0xA4 */ float mHighlightLoopBackScale;
        /* 0xA8 */ uint8_t mAnimDebug;
        /* 0xA9 */ uint8_t padding[3];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawLightDropHIO_c) == 0xAC);

    class dMeter_drawHIO_c
    {
       public:
        dMeter_drawHIO_c() { dMeter_drawHIO_c_ct(this); }

        /* 0x000 */ void* vtable;
        /* 0x004 */ int8_t field_0x4;
        /* 0x005 */ uint8_t padding_5[3];
        /* 0x008 */ float mLifeTopPosX;
        /* 0x00C */ float mLifeTopPosY;
        /* 0x010 */ float mNoMagicPosY;
        /* 0x014 */ float mParentScale;
        /* 0x018 */ float mParentAlpha;
        /* 0x01C */ float mLifeParentScale;
        /* 0x020 */ float mLifeParentHeartAlpha;
        /* 0x024 */ float mHeartBaseAlpha;
        /* 0x028 */ float mLifeGaugePosX;
        /* 0x02C */ float mLifeGaugePosY;
        /* 0x030 */ float mHeartMarkScale;
        /* 0x034 */ float mHeartAlpha;
        /* 0x038 */ float mBigHeartScale;
        /* 0x03C */ float mBigHeartAlpha;
        /* 0x040 */ float mMagicMeterScale;
        /* 0x044 */ float mMagicMeterAlpha;
        /* 0x048 */ float mMagicMeterFrameAlpha;
        /* 0x04C */ float mMagicMeterPosX;
        /* 0x050 */ float mMagicMeterPosY;
        /* 0x054 */ float mLanternMeterScale;
        /* 0x058 */ float mLanternMeterAlpha;
        /* 0x05C */ float mLanternMeterFrameAlpha;
        /* 0x060 */ float mLanternMeterPosX;
        /* 0x064 */ float mLanternMeterPosY;
        /* 0x068 */ float mOxygenMeterScale;
        /* 0x06C */ float mOxygenMeterAlpha;
        /* 0x070 */ float mOxygenMeterFrameAlpha;
        /* 0x074 */ float mOxygenMeterPosX;
        /* 0x078 */ float mOxygenMeterPosY;
        /* 0x07C */ float mMainHUDButtonsScale;
        /* 0x080 */ float mRingHUDButtonsScale;
        /* 0x084 */ float mMainHUDButtonsAlpha;
        /* 0x088 */ float mRingHUDButtonsAlpha;
        /* 0x08C */ float mMainHUDButtonsPosX;
        /* 0x090 */ float mRingHUDButtonsPosX;
        /* 0x094 */ float mMainHUDButtonsPosY;
        /* 0x098 */ float mRingHUDButtonsPosY;
        /* 0x09C */ float mButtonDisplayBackScale;
        /* 0x0A0 */ float mButtonDisplayBackAlpha;
        /* 0x0A4 */ float mButtonAScale;
        /* 0x0A8 */ float mButtonAAlpha;
        /* 0x0AC */ float mButtonAPosX;
        /* 0x0B0 */ float mButtonAPosY;
        /* 0x0B4 */ float mButtonATalkScale[2];
        /* 0x0BC */ float mButtonATalkPosX[2];
        /* 0x0C4 */ float mButtonATalkPosY[2];
        /* 0x0CC */ float mButtonATalkAScale;
        /* 0x0D0 */ float mButtonATextTalkAScale;
        /* 0x0D4 */ float mButtonATalkAPosX[2];
        /* 0x0DC */ float mButtonATalkAPosY[2];
        /* 0x0E4 */ float mButtonAVesselPosX;
        /* 0x0E8 */ float mButtonAVesselPosY;
        /* 0x0EC */ float mButtonBScale;
        /* 0x0F0 */ float mButtonBAlpha;
        /* 0x0F4 */ float mButtonBPosX;
        /* 0x0F8 */ float mButtonBPosY;
        /* 0x0FC */ float mButtonBTalkScale[2];
        /* 0x104 */ float mButtonBTalkPosX[2];
        /* 0x10C */ float mButtonBTalkPosY[2];
        /* 0x114 */ float mButtonBWolfPosX;
        /* 0x118 */ float mButtonBWolfPosY;
        /* 0x11C */ float mButtonBVesselPosX;
        /* 0x120 */ float mButtonBVesselPosY;
        /* 0x124 */ float mMidnaIconScale;
        /* 0x128 */ float mMidnaIconAlpha;
        /* 0x12C */ float mMidnaIconPosX;
        /* 0x130 */ float mMidnaIconPosY;
        /* 0x134 */ float field_0x134;
        /* 0x138 */ float field_0x138;
        /* 0x13C */ float field_0x13c;
        /* 0x140 */ float field_0x140;
        /* 0x144 */ float mButtonXScale;
        /* 0x148 */ float mButtonXAlpha;
        /* 0x14C */ float mButtonXPosX;
        /* 0x150 */ float mButtonXPosY;
        /* 0x154 */ float mButtonYScale;
        /* 0x158 */ float mButtonYAlpha;
        /* 0x15C */ float mButtonYPosX;
        /* 0x160 */ float mButtonYPosY;
        /* 0x164 */ float field_0x164;
        /* 0x168 */ float field_0x168;
        /* 0x16C */ float field_0x16c;
        /* 0x170 */ float field_0x170;
        /* 0x174 */ float mButtonZScale;
        /* 0x178 */ float mButtonZAlpha;
        /* 0x17C */ float mButtonZPosX;
        /* 0x180 */ float mButtonZPosY;
        /* 0x184 */ float mButtonBItemPosX[3];
        /* 0x190 */ float mButtonBItemPosY[3];
        /* 0x19C */ float mButtonBItemRotation[3];
        /* 0x1A8 */ float mButtonBItemScale[3];
        /* 0x1B4 */ float mButtonXItemPosX;
        /* 0x1B8 */ float mButtonXItemPosY;
        /* 0x1BC */ float mButtonXItemScale;
        /* 0x1C0 */ float mButtonYItemPosX;
        /* 0x1C4 */ float mButtonYItemPosY;
        /* 0x1C8 */ float mButtonYItemScale;
        /* 0x1CC */ float field_0x1cc;
        /* 0x1D0 */ float field_0x1d0;
        /* 0x1D4 */ float field_0x1d4;
        /* 0x1D8 */ float mButtonZItemPosX;
        /* 0x1DC */ float mButtonZItemPosY;
        /* 0x1E0 */ float mButtonZItemScale;
        /* 0x1E4 */ float mButtonItemRotation[3];
        /* 0x1F0 */ float mXItemNumPosX;
        /* 0x1F4 */ float mYItemNumPosX;
        /* 0x1F8 */ float field_0x1f8;
        /* 0x1FC */ float mItemBNumPosX;
        /* 0x200 */ float mXItemNumPosY;
        /* 0x204 */ float mYItemNumPosY;
        /* 0x208 */ float field_0x208;
        /* 0x20C */ float mItemBNumPosY;
        /* 0x210 */ float mXItemNumScale;
        /* 0x214 */ float mYItemNumScale;
        /* 0x218 */ float field_0x218;
        /* 0x21C */ float mItemBNumScale;
        /* 0x220 */ float mItemBBaseScale[2];
        /* 0x228 */ float mItemBBasePosX[2];
        /* 0x230 */ float mItemBBasePosY[2];
        /* 0x238 */ float mItemBBaseAlpha[2];
        /* 0x240 */ float mButtonXItemBaseScale[2];
        /* 0x248 */ float mButtonXItemBasePosX[2];
        /* 0x250 */ float mButtonXItemBasePosY[2];
        /* 0x258 */ float mButtonXItemBaseAlpha[2];
        /* 0x260 */ float mButtonYItemBaseScale[2];
        /* 0x268 */ float mButtonYItemBasePosX[2];
        /* 0x270 */ float mButtonYItemBasePosY[2];
        /* 0x278 */ float mButtonYItemBaseAlpha[2];
        /* 0x280 */ float field_0x280;
        /* 0x284 */ float field_0x284;
        /* 0x288 */ float field_0x288;
        /* 0x28C */ float field_0x28c;
        /* 0x290 */ float field_0x290;
        /* 0x294 */ float field_0x294;
        /* 0x298 */ float field_0x298[2];
        /* 0x2A0 */ float mButtonZItemBaseScale;
        /* 0x2A4 */ float mButtonZItemBasePosX;
        /* 0x2A8 */ float mButtonZItemBasePosY;
        /* 0x2AC */ float mButtonZItemBaseAlpha;
        /* 0x2B0 */ float mButtonBaseAlpha;
        /* 0x2B4 */ float mButtonATextScale;
        /* 0x2B8 */ float mButtonATextPosX;
        /* 0x2BC */ float mButtonATextPosY;
        /* 0x2C0 */ uint32_t mAButtonFontColor; // JUtility::TColor
        /* 0x2C4 */ float mAButtonFontSpacing;
        /* 0x2C8 */ int32_t mButtonATextActionID;
        /* 0x2CC */ uint32_t field_0x2cc;
        /* 0x2D0 */ bool mButtonATextDebug;
        /* 0x2D1 */ uint8_t padding_2d1[3];
        /* 0x2D4 */ float mButtonBFontScale;
        /* 0x2D8 */ float mButtonBFontPosX;
        /* 0x2DC */ float mButtonBFontPosY;
        /* 0x2E0 */ uint32_t mButtonBFontColor; // JUtility::TColor
        /* 0x2E4 */ float field_0x2e4;
        /* 0x2E8 */ float field_0x2e8;
        /* 0x2EC */ float field_0x2ec;
        /* 0x2F0 */ uint32_t field_0x2f0; // JUtility::TColor
        /* 0x2F4 */ float mButtonXYTextScale;
        /* 0x2F8 */ float mButtonXYTextPosX;
        /* 0x2FC */ float mButtonXYTextPosY;
        /* 0x300 */ uint32_t mButtonXYTextColor; // JUtility::TColor
        /* 0x304 */ float field_0x304;
        /* 0x308 */ float field_0x308;
        /* 0x30C */ float field_0x30c;
        /* 0x310 */ uint32_t field_0x310; // JUtility::TColor
        /* 0x314 */ float field_0x314;
        /* 0x318 */ float field_0x318;
        /* 0x31C */ float field_0x31c;
        /* 0x320 */ float field_0x320;
        /* 0x324 */ float field_0x324;
        /* 0x328 */ float field_0x328;
        /* 0x32C */ float mButtonZFontScale;
        /* 0x330 */ float mButtonZFontPosX;
        /* 0x334 */ float mButtonZFontPosY;
        /* 0x338 */ uint32_t mButtonZFontColor; // JUtility::TColor
        /* 0x33C */ float mRupeeKeyScale;
        /* 0x340 */ float mRupeeKeyPosX;
        /* 0x344 */ float mRupeeKeyPosY;
        /* 0x348 */ float mRupeeKeyAlpha;
        /* 0x34C */ float mRupeeScale;
        /* 0x350 */ float mRupeePosX;
        /* 0x354 */ float mRupeePosY;
        /* 0x358 */ float mRupeeAlpha;
        /* 0x35C */ float mKeyScale;
        /* 0x360 */ float mKeyPosX;
        /* 0x364 */ float mKeyPosY;
        /* 0x368 */ float mKeyAlpha;
        /* 0x36C */ float mRupeeFrameScale;
        /* 0x370 */ float mRupeeFramePosX;
        /* 0x374 */ float mRupeeFramePosY;
        /* 0x378 */ float mRupeeFrameAlpha;
        /* 0x37C */ float mRupeeCountScale;
        /* 0x380 */ float mRupeeCountPosX;
        /* 0x384 */ float mRupeeCountPosY;
        /* 0x388 */ float mRupeeCountAlpha;
        /* 0x38C */ float mKeyNumScale;
        /* 0x390 */ float mKeyNumPosX;
        /* 0x394 */ float mKeyNumPosY;
        /* 0x398 */ float mKeyNumAlpha;
        /* 0x39C */ float mSpurIconScale;
        /* 0x3A0 */ float mSpurIconAlpha;
        /* 0x3A4 */ float mUsedSpurIconScale;
        /* 0x3A8 */ float mUsedSpurIconAlpha;
        /* 0x3AC */ float mSpurBarScale;
        /* 0x3B0 */ float mSpurBarPosX;
        /* 0x3B4 */ float mSpurBarPosY;
        /* 0x3B8 */ float mButtonAHorsePosX;
        /* 0x3BC */ float mButtonAHorsePosY;
        /* 0x3C0 */ float mButtonAHorseScale;
        /* 0x3C4 */ float mButtonAPikariScale;
        /* 0x3C8 */ float mButtonBPikariScale;
        /* 0x3CC */ float field_0x3cc;
        /* 0x3D0 */ float field_0x3d0;
        /* 0x3D4 */ float field_0x3d4;
        /* 0x3D8 */ float mButtonZPikariScale;
        /* 0x3DC */ float mButtonXYPikariScale;
        /* 0x3E0 */ float mSpurIconPikariScale;
        /* 0x3E4 */ float mSpurIconRevivePikariScale;
        /* 0x3E8 */ float mMidnaIconPikariScale;
        /* 0x3EC */ int16_t mMidnaIconFlashRate;
        /* 0x3EE */ uint8_t padding_3ee[2];
        /* 0x3F0 */ float field_0x3f0;
        /* 0x3F4 */ float field_0x3f4;
        /* 0x3F8 */ float field_0x3f8;
        /* 0x3FC */ float mButtonCrossScale;
        /* 0x400 */ float mButtonCrossOFFPosX;
        /* 0x404 */ float mButtonCrossOFFPosY;
        /* 0x408 */ float mButtonCrossONPosX;
        /* 0x40C */ float mButtonCrossONPosY;
        /* 0x410 */ float mButtonCrossTextScale;
        /* 0x414 */ float mButtonCrossAlpha;
        /* 0x418 */ float mButtonCrossITEMAlpha;
        /* 0x41C */ float mButtonCrossMAPAlpha;
        /* 0x420 */ int16_t mButtonCrossMoveFrame;
        /* 0x422 */ int16_t field_0x422;
        /* 0x424 */ int16_t field_0x424;
        /* 0x426 */ bool mButtonDebug[4];
        /* 0x42A */ uint8_t mButtonXYItemDimAlpha;
        /* 0x42B */ uint8_t mButtonXYBaseDimAlpha;
        /* 0x42C */ uint8_t field_0x42c;
        /* 0x42D */ uint8_t mMaxSpurAmount;
        /* 0x42E */ bool mSpurDebug;
        /* 0x42F */ bool field_0x42f;
        /* 0x430 */ uint32_t mSpurIconPikariFrontInner; // JUtility::TColor
        /* 0x434 */ uint32_t mSpurIconPikariFrontOuter; // JUtility::TColor
        /* 0x438 */ uint32_t mSpurIconPikariBackInner; // JUtility::TColor
        /* 0x43C */ uint32_t mSpurIconPikariBackOuter; // JUtility::TColor
        /* 0x440 */ float mSpurIconPikariAnimSpeed;
        /* 0x444 */ uint32_t mSpurIconRevivePikariFrontInner; // JUtility::TColor
        /* 0x448 */ uint32_t mSpurIconRevivePikariFrontOuter; // JUtility::TColor
        /* 0x44C */ uint32_t mSpurIconRevivePikariBackInner; // JUtility::TColor
        /* 0x450 */ uint32_t mSpurIconRevivePikariBackOuter; // JUtility::TColor
        /* 0x454 */ float mSpurIconRevivePikariAnimSpeed;
        /* 0x458 */ uint32_t mButtonZPikariFrontInner; // JUtility::TColor
        /* 0x45C */ uint32_t mButtonZPikariFrontOuter; // JUtility::TColor
        /* 0x460 */ uint32_t mButtonZPikariBackInner; // JUtility::TColor
        /* 0x464 */ uint32_t mButtonZPikariBackOuter; // JUtility::TColor
        /* 0x468 */ float mButtonZPikariAnimSpeed;
        /* 0x46C */ uint32_t mButtonXYPikariFrontInner; // JUtility::TColor
        /* 0x470 */ uint32_t mButtonXYPikariFrontOuter; // JUtility::TColor
        /* 0x474 */ uint32_t mButtonXYPikariBackInner; // JUtility::TColor
        /* 0x478 */ uint32_t mButtonXYPikariBackOuter; // JUtility::TColor
        /* 0x47C */ float mButtonXYPikariAnimSpeed;
        /* 0x480 */ uint32_t mButtonAPikariFrontInner; // JUtility::TColor
        /* 0x484 */ uint32_t mButtonAPikariFrontOuter; // JUtility::TColor
        /* 0x488 */ uint32_t mButtonAPikariBackInner; // JUtility::TColor
        /* 0x48C */ uint32_t mButtonAPikariBackOuter; // JUtility::TColor
        /* 0x490 */ float mButtonAPikariAnimSpeed;
        /* 0x494 */ uint32_t mButtonBPikariFrontInner; // JUtility::TColor
        /* 0x498 */ uint32_t mButtonBPikariFrontOuter; // JUtility::TColor
        /* 0x49C */ uint32_t mButtonBPikariBackInner; // JUtility::TColor
        /* 0x4A0 */ uint32_t mButtonBPikariBackOuter; // JUtility::TColor
        /* 0x4A4 */ float mButtonBPikariAnimSpeed;
        /* 0x4A8 */ uint32_t field_0x4a8; // JUtility::TColor
        /* 0x4AC */ uint32_t field_0x4ac; // JUtility::TColor
        /* 0x4B0 */ uint32_t field_0x4b0; // JUtility::TColor
        /* 0x4B4 */ uint32_t field_0x4b4; // JUtility::TColor
        /* 0x4B8 */ float field_0x4b8;
        /* 0x4BC */ uint32_t field_0x4bc; // JUtility::TColor
        /* 0x4C0 */ uint32_t field_0x4c0; // JUtility::TColor
        /* 0x4C4 */ uint32_t field_0x4c4; // JUtility::TColor
        /* 0x4C8 */ uint32_t field_0x4c8; // JUtility::TColor
        /* 0x4CC */ float field_0x4cc;
        /* 0x4D0 */ uint32_t field_0x4d0; // JUtility::TColor
        /* 0x4D4 */ uint32_t field_0x4d4; // JUtility::TColor
        /* 0x4D8 */ uint32_t field_0x4d8; // JUtility::TColor
        /* 0x4DC */ uint32_t field_0x4dc; // JUtility::TColor
        /* 0x4E0 */ float field_0x4e0;
        /* 0x4E4 */ uint32_t mMidnaIconPikariFrontInner; // JUtility::TColor
        /* 0x4E8 */ uint32_t mMidnaIconPikariFrontOuter; // JUtility::TColor
        /* 0x4EC */ uint32_t mMidnaIconPikariBackInner; // JUtility::TColor
        /* 0x4F0 */ uint32_t mMidnaIconPikariBackOuter; // JUtility::TColor
        /* 0x4F4 */ float mMidnaIconPikariAnimSpeed;
        /* 0x4F8 */ float mScrollArrowScaleX;
        /* 0x4FC */ float mScrollArrowScaleY;
        /* 0x500 */ float mScrollArrowBPKAnimSpeed;
        /* 0x504 */ float mScrollArrowBCKAnimSpeed;
        /* 0x508 */ float mScrollArrowBTKAnimSpeed;
        /* 0x50C */ float mScrollArrowPosX[2];
        /* 0x514 */ float mScrollArrowPosY[2];
        /* 0x51C */ float mScrollArrowCenterPosX;
        /* 0x520 */ float mScrollArrowCenterPosY;
        /* 0x524 */ bool mScrollArrowDisplayAll;
        /* 0x525 */ uint8_t padding_525[3];
        /* 0x528 */ float mWiiLockArrowScaleX;
        /* 0x52C */ float mWiiLockArrowScaleY;
        /* 0x530 */ float mWiiLockArrowBPKAnimSpeed;
        /* 0x534 */ float mWiiLockArrowBCKAnimSpeed;
        /* 0x538 */ float mWiiLockArrowBTKAnimSpeed;
        /* 0x53C */ float mWiiLockArrowPosX[2];
        /* 0x544 */ float mWiiLockArrowPosY[2];
        /* 0x54C */ float field_0x54c;
        /* 0x550 */ bool mWiiLockArrowDisplayAll;
        /* 0x551 */ uint8_t padding_551[3];
        /* 0x554 */ float mFloatingMessagePosX;
        /* 0x558 */ float mFloatingMessagePosY;
        /* 0x55C */ uint32_t mMessageID;
        /* 0x560 */ uint32_t mFlowID;
        /* 0x564 */ int16_t mMessageDuration;
        /* 0x566 */ bool mMessageDebug;
        /* 0x567 */ bool mFlowDebug;
        /* 0x568 */ bool mItemScaleAdjustON;
        /* 0x569 */ uint8_t mItemScalePercent;
        /* 0x56A */ uint8_t padding_56a[2];
        /* 0x56C */ float mTouchAreaUnselectScale[5];
        /* 0x580 */ float mTouchAreaSelectScale[5];
        /* 0x594 */ float mTouchAreaScale[5];
        /* 0x5A8 */ float mTouchAreaAlpha[5];
        /* 0x5BC */ float mTouchAreaPosX[5];
        /* 0x5D0 */ float mTouchAreaPosY[5];
        /* 0x5E4 */ float mDpadMAPScale;
        /* 0x5E8 */ float mDpadMAPPosX;
        /* 0x5EC */ float mDpadMAPPosY;
        /* 0x5F0 */ uint32_t mTouchAreaSelectWhite[3]; // JUtility::TColor
        /* 0x5FC */ uint32_t mTouchAreaSelectBlack[3]; // JUtility::TColor
        /* 0x608 */ int16_t mTouchAreaSelectFrameNum;
        /* 0x60A */ bool field_0x60a;
        /* 0x60B */ uint8_t padding_60b[1];
        /* 0x60C */ float mLanternIconMeterPosX;
        /* 0x610 */ float mLanternIconMeterPosY;
        /* 0x614 */ float mLanternIconMeterSize;
        /* 0x618 */ dMeter_drawCollectHIO_c mCollectScreen;
        /* 0x6B8 */ dMeter_drawOptionHIO_c mOptionScreen;
        /* 0x728 */ dMeter_drawLetterHIO_c mLetterSelectScreen;
        /* 0x788 */ dMeter_drawFishingHIO_c mFishListScreen;
        /* 0x9DC */ dMeter_drawInsectHIO_c mInsectListScreen;
        /* 0xA1C */ dMeter_drawCalibrationHIO_c mCalibration;
        /* 0xA34 */ dMeter_drawSkillHIO_c mSkillListScreen;
        /* 0xA90 */ dMeter_drawMiniGameHIO_c mMiniGame;
        /* 0xC20 */ dMeter_drawEmpButtonHIO_c mEmpButton;
        /* 0xE7C */ dMeter_drawLightDropHIO_c mLightDrop;
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_drawHIO_c) == 0xF28);

    class dMeter_ringHIO_c
    {
       public:
        dMeter_ringHIO_c() { dMeter_ringHIO_c_ct(this); }

        enum
        {
            /* 0x0 */ SET_ITEM,
            /* 0x1 */ DIRECT_SELECT,
            /* 0x3 */ ROTATE = 3,
            /* 0x4 */ COMBO_ITEM
        };

        enum
        {
            /* 0x0 */ SELECT_FRAME,
            /* 0x1 */ UNSELECT_FRAME
        };

        /* 0x000 */ void* vtable;
        /* 0x004 */ int8_t field_0x4;
        /* 0x005 */ uint8_t padding_5[3];
        /* 0x008 */ float mRingRadiusH;
        /* 0x00C */ float mRingRadiusV;
        /* 0x010 */ float field_0x10;
        /* 0x014 */ float mSelectItemScale;
        /* 0x018 */ float mSelectButtonScale;
        /* 0x01C */ float mUnselectItemScale;
        /* 0x020 */ float mUnselectButtonScale;
        /* 0x024 */ float mInactiveItemScale;
        /* 0x028 */ float mCursorScale;
        /* 0x02C */ float mItemNamePosX;
        /* 0x030 */ float mItemNamePosY;
        /* 0x034 */ float mItemNameScale;
        /* 0x038 */ float mCenterPosX;
        /* 0x03C */ float mCenterPosY;
        /* 0x040 */ float mCenterScale;
        /* 0x044 */ float field_0x44;
        /* 0x048 */ float field_0x48;
        /* 0x04C */ float field_0x4c;
        /* 0x050 */ float mOverlayAlpha;
        /* 0x054 */ float mGuidePosX[10];
        /* 0x07C */ float mGuidePosY[10];
        /* 0x0A4 */ float mGuideScale[10];
        /* 0x0CC */ float mHighlightScale;
        /* 0x0D0 */ uint32_t mHighlightFrontInner; // JUtility::TColor
        /* 0x0D4 */ uint32_t mHighlightFrontOuter; // JUtility::TColor
        /* 0x0D8 */ uint32_t mHighlightBackInner;  // JUtility::TColor
        /* 0x0DC */ uint32_t mHighlightBackOuter;  // JUtility::TColor
        /* 0x0E0 */ float mHighlightAnimSpeed;
        /* 0x0E4 */ float mSelectPosX;
        /* 0x0E8 */ float mSelectPosY;
        /* 0x0EC */ float mSelectScaleX;
        /* 0x0F0 */ float mSelectScaleY;
        /* 0x0F4 */ float mItemDescPosX;
        /* 0x0F8 */ float mItemDescPosY;
        /* 0x0FC */ float mItemDescScale;
        /* 0x100 */ float mItemDescAlpha;
        /* 0x104 */ float mItemDescTitlePosX;
        /* 0x108 */ float mItemDescTitlePosY;
        /* 0x10C */ float mItemDescTitleScale;
        /* 0x110 */ float mItemRingPosX;
        /* 0x114 */ float mItemRingPosY;
        /* 0x118 */ float mRingPosX;
        /* 0x11C */ float mRingPosY;
        /* 0x120 */ float mRingAlpha;
        /* 0x124 */ float mRingAlpha_Wolf;
        /* 0x128 */ float mRingScaleH;
        /* 0x12C */ float mRingScaleV;
        /* 0x130 */ uint32_t mItemFrame[2]; // JUtility::TColor
        /* 0x138 */ int16_t mItemAlphaFlashDuration;
        /* 0x13A */ int16_t mOpenFrames;
        /* 0x13C */ int16_t mCloseFrames;
        /* 0x13E */ int16_t field_0x13e;
        /* 0x140 */ int16_t field_0x140;
        /* 0x142 */ int16_t field_0x142;
        /* 0x144 */ int16_t mCursorMax;
        /* 0x146 */ int16_t mCursorInitSpeed;
        /* 0x148 */ int16_t mCursorAccel;
        /* 0x14A */ int16_t mCursorChangeWaitFrames;
        /* 0x14C */ int16_t mDirectSelectWaitFrames;
        /* 0x14E */ uint8_t mOffsetLineDisplay;
        /* 0x14F */ uint8_t mItemNum;
        /* 0x150 */ uint8_t field_0x150;
        /* 0x151 */ uint8_t mItemIconAlpha;
        /* 0x152 */ uint8_t mItemIconAlpha_Wolf;
        /* 0x153 */ uint8_t field_0x153;
        /* 0x154 */ uint8_t field_0x154;
        /* 0x155 */ uint8_t mItemAlphaMin;
        /* 0x156 */ uint8_t mItemAlphaMax;
        /* 0x157 */ uint8_t padding_157[1];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_ringHIO_c) == 0x158);

    class dMeter_mapIconHIO_c
    {
       public:
        dMeter_mapIconHIO_c() { dMeter_mapIconHIO_c_ct(this); }

        enum
        {
            /* 0x00 */ ICON_PORTAL,
            /* 0x01 */ ICON_LINK,
            /* 0x02 */ ICON_DUNGEON_WARP,
            /* 0x03 */ ICON_DESTINATION,
            /* 0x04 */ ICON_BOSS,
            /* 0x05 */ ICON_GANON,
            /* 0x06 */ ICON_LIGHT_DROP,
            /* 0x07 */ ICON_SOL,
            /* 0x08 */ ICON_CANNON_BALL,
            /* 0x09 */ ICON_YETO,
            /* 0x0A */ ICON_YETA,
            /* 0x0B */ ICON_GOLD_WOLF,
            /* 0x0C */ ICON_MONKEY,
            /* 0x0D */ ICON_OOCCOO_SR,
            /* 0x0E */ ICON_OOCCOO_JR,
            /* 0x0F */ ICON_COPY_STATUE,
            /* 0x10 */ ICON_WAGON,
            /* 0x11 */ ICON_SMALL_KEY,
            /* 0x12 */ ICON_CHEST,
            /* 0x13 */ ICON_STAGE_ENTRANCE,
            /* 0x14 */ ICON_ROOM_ENTRANCE,
            /* 0x15 */ ICON_LV8_ENTRANCE,
        };

        /* 0x000 */ void* vtable;
        /* 0x004 */ uint8_t field_0x4[4];
        /* 0x008 */ float mPortalCursorScale;
        /* 0x00C */ float mPortalIconScale;
        /* 0x010 */ float mDestinationScale;
        /* 0x014 */ float mDungeonDestScale;
        /* 0x018 */ float mDestinationZoomScale;
        /* 0x01C */ float mDungeonDestZoomScale;
        /* 0x020 */ float field_0x20;
        /* 0x024 */ float mBossScale;
        /* 0x028 */ float field_0x28;
        /* 0x02C */ float mBossZoomScale;
        /* 0x030 */ float field_0x30;
        /* 0x034 */ float mGanonScale;
        /* 0x038 */ float field_0x38;
        /* 0x03C */ float mGanonZoomScale;
        /* 0x040 */ float mDungeonEntranceScale;
        /* 0x044 */ float mDungeonExitScale;
        /* 0x048 */ float mDungeonEntranceZoomScale;
        /* 0x04C */ float mDungeonExitZoomScale;
        /* 0x050 */ float field_0x50;
        /* 0x054 */ float mSmallKeyScale;
        /* 0x058 */ float field_0x58;
        /* 0x05C */ float mSmallKeyZoomScale;
        /* 0x060 */ float field_0x60;
        /* 0x064 */ float mChestScale;
        /* 0x068 */ float field_0x68;
        /* 0x06C */ float mChestZoomScale;
        /* 0x070 */ float mYetoScale;
        /* 0x074 */ float field_0x74;
        /* 0x078 */ float mYetoZoomScale;
        /* 0x07C */ float field_0x7c;
        /* 0x080 */ float mYetaScale;
        /* 0x084 */ float field_0x84;
        /* 0x088 */ float mYetaZoomScale;
        /* 0x08C */ float field_0x8c;
        /* 0x090 */ float mGoldWolfScale;
        /* 0x094 */ float field_0x94;
        /* 0x098 */ float mGoldWolfZoomScale;
        /* 0x09C */ float field_0x9c;
        /* 0x0A0 */ float field_0xa0;
        /* 0x0A4 */ float mMonkeyScale;
        /* 0x0A8 */ float field_0xa8;
        /* 0x0AC */ float mMonkeyZoomScale;
        /* 0x0B0 */ float field_0xb0;
        /* 0x0B4 */ float mOoccooScale;
        /* 0x0B8 */ float field_0xb8;
        /* 0x0BC */ float mOoccooZoomScale;
        /* 0x0C0 */ float field_0xc0;
        /* 0x0C4 */ float mOoccooPotScale;
        /* 0x0C8 */ float field_0xc8;
        /* 0x0CC */ float mOoccooPotZoomScale;
        /* 0x0D0 */ float field_0xd0;
        /* 0x0D4 */ float mCopyRodStatueScale;
        /* 0x0D8 */ float field_0xd8;
        /* 0x0DC */ float mCopyRodStatueZoomScale;
        /* 0x0E0 */ float mWagonScale;
        /* 0x0E4 */ float field_0xe4;
        /* 0x0E8 */ float mWagonZoomScale;
        /* 0x0EC */ float field_0xec;
        /* 0x0F0 */ float mLinkScale;
        /* 0x0F4 */ float mDungeonLinkScale;
        /* 0x0F8 */ float mLinkZoomScale;
        /* 0x0FC */ float mDungeonLinkZoomScale;
        /* 0x100 */ float mRoomEntranceScale;
        /* 0x104 */ float mDungeonSpawnScale;
        /* 0x108 */ float mRoomEntranceZoomScale;
        /* 0x10C */ float mDungeonSpawnZoomScale;
        /* 0x110 */ float mLV8EntranceScale;
        /* 0x114 */ float field_0x114;
        /* 0x118 */ float mLV8EntranceZoomScale;
        /* 0x11C */ float field_0x11c;
        /* 0x120 */ float field_0x120;
        /* 0x124 */ float mDungeonWarpScale;
        /* 0x128 */ float field_0x128;
        /* 0x12C */ float mDungeonWarpZoomScale;
        /* 0x130 */ float mLightDropScale;
        /* 0x134 */ float field_0x134;
        /* 0x138 */ float mLightDropZoomScale;
        /* 0x13C */ float field_0x13c;
        /* 0x140 */ float field_0x140;
        /* 0x144 */ float mLightOrbScale;
        /* 0x148 */ float field_0x148;
        /* 0x14C */ float mLightOrbZoomScale;
        /* 0x150 */ float field_0x150;
        /* 0x154 */ float mCannonBallScale;
        /* 0x158 */ float field_0x158;
        /* 0x15C */ float mCannonBallZoomScale;
        /* 0x160 */ float mLightDropFlashStartScaleOut;
        /* 0x164 */ float mLightDropFlashStartScaleIn;
        /* 0x168 */ float mLightDropFlashEndScaleOut;
        /* 0x16C */ float mLightDropFlashEndScaleIn;
        /* 0x170 */ int16_t mLightDropFlashFrameNum;
        /* 0x172 */ uint8_t mLightDropFlashStartAlphaOut;
        /* 0x173 */ uint8_t mLightDropFlashStartAlphaIn;
        /* 0x174 */ uint8_t mLightDropFlashEndAlphaOut;
        /* 0x175 */ uint8_t mLightDropFlashEndAlphaIn;
        /* 0x176 */ bool mLV5DungeonItemDebug;
        /* 0x177 */ uint8_t mLV5DungeonItem;
        /* 0x178 */ bool mIconDebug;
        /* 0x179 */ bool mIconDisplay[22];
        /* 0x18F */ uint8_t padding_18f[1];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_mapIconHIO_c) == 0x190);

    class dMeter_fmapHIO_c
    {
       public:
        enum
        {
            /* 0x0 */ REGION_ORDONA,
            /* 0x1 */ REGION_FARON,
            /* 0x2 */ REGION_ELDIN,
            /* 0x3 */ REGION_LANAYRU,
            /* 0x4 */ REGION_GERUDO,
            /* 0x5 */ REGION_SNOWPEAK,
            /* 0x6 */ REGION_CASTLE,
        };

        enum
        {
            /* 0x0 */ WORLD_VIEW,
            /* 0x1 */ REGION_VIEW,
            /* 0x2 */ ZOOM_VIEW
        };

        enum
        {
            /* 0x0 */ TYPE_DEFAULT,
            /* 0x1 */ TYPE_OVERWORLD,
            /* 0x3 */ TYPE_DUNGEON,
            /* 0x2 */ TYPE_HYRULE_CASTLE,
        };

        struct BlinkAnime
        {
            /* 0x0 */ uint32_t mBlack; // JUtility::TColor
            /* 0x4 */ uint32_t mWhite; // JUtility::TColor
            /* 0x8 */ int16_t mBlinkSpeed;
            /* 0xA */ uint8_t mMax;
            /* 0xB */ uint8_t mMin;
        } __attribute__((__packed__));

        static_assert(sizeof(BlinkAnime) == 0xC);

        struct MapBlinkAnime
        {
            MapBlinkAnime() { MapBlinkAnime_ct(this); }

            /* 0x00 */ BlinkAnime mSelectedRegion;
            /* 0x0C */ BlinkAnime mUnselectedRegion;
            /* 0x18 */ uint32_t mUnreachedRegionBlack; // JUtility::TColor
            /* 0x1C */ uint32_t mUnreachedRegionWhite; // JUtility::TColor
            /* 0x20 */ uint32_t field_0x20;            // JUtility::TColor
            /* 0x24 */ uint32_t field_0x24;            // JUtility::TColor
        } __attribute__((__packed__));

        static_assert(sizeof(MapBlinkAnime) == 0x28);

        dMeter_fmapHIO_c() { dMeter_fmapHIO_c_ct(this); }

        /* 0x000 */ void* vtable;
        /* 0x004 */ int8_t field_0x4;
        /* 0x005 */ uint8_t padding_5[3];
        /* 0x008 */ void* field_0x8; // JKRArchive
        /* 0x00C */ void* field_0xc;
        /* 0x010 */ void* field_0x10;
        /* 0x014 */ void* field_0x14;
        /* 0x018 */ void* field_0x18;
        /* 0x01C */ MapBlinkAnime mMapBlink[3];
        /* 0x094 */ int16_t mDisplayFrameNum;
        /* 0x096 */ int16_t mUndisplayFrameNum;
        /* 0x098 */ uint8_t field_0x98[4];
        /* 0x09C */ float mRegionZoomRange;
        /* 0x0A0 */ float mStageZoomScale;
        /* 0x0A4 */ float mWorldGridWidth;
        /* 0x0A8 */ float mRegionGridWidth;
        /* 0x0AC */ float mMapTopLeftPosX;
        /* 0x0B0 */ float mMapTopLeftPosY;
        /* 0x0B4 */ float mMapScale;
        /* 0x0B8 */ float mBackgroundAlpha;
        /* 0x0BC */ float mBackgroundFrontAlpha;
        /* 0x0C0 */ float mScrollSpeedRegionFast;
        /* 0x0C4 */ float mScrollSpeedRegionZoomFast;
        /* 0x0C8 */ float mScrollSpeedWorldFast;
        /* 0x0CC */ float mScrollSpeedDungeonMapFast;
        /* 0x0D0 */ float mScrollSpeedRegionSlow;
        /* 0x0D4 */ float mScrollSpeedRegionZoomSlow;
        /* 0x0D8 */ float mScrollSpeedWorldSlow;
        /* 0x0DC */ float mScrollSpeedDungeonMapSlow;
        /* 0x0E0 */ float mScrollSpeedSlowBound;
        /* 0x0E4 */ float mScrollSpeedFastBound;
        /* 0x0E8 */ float mTitlePosX;
        /* 0x0EC */ float mTitlePosY;
        /* 0x0F0 */ float mTitleScale;
        /* 0x0F4 */ float mSubTitlePosX;
        /* 0x0F8 */ float mSubTitlePosY;
        /* 0x0FC */ float mSubTitleScale;
        /* 0x100 */ float mAreaMovementPosX;
        /* 0x104 */ float mAreaMovementPosY;
        /* 0x108 */ float mAreaMovementScale;
        /* 0x10C */ float mClosingPosX;
        /* 0x110 */ float mClosingPosY;
        /* 0x114 */ float mClosingScale;
        /* 0x118 */ float mDoIconPosX;
        /* 0x11C */ float mDoIconPosY;
        /* 0x120 */ float mDoIconScale;
        /* 0x124 */ float mZButtonPosX;
        /* 0x128 */ float mZButtonPosY;
        /* 0x12C */ float mZButtonScale;
        /* 0x130 */ float mAButtonPosX;
        /* 0x134 */ float mAButtonPosY;
        /* 0x138 */ float mAButtonScale;
        /* 0x13C */ float mBButtonPosX;
        /* 0x140 */ float mBButtonPosY;
        /* 0x144 */ float mBButtonScale;
        /* 0x148 */ float mZButtonTextPosX;
        /* 0x14C */ float mZButtonTextPosY;
        /* 0x150 */ float mZButtonTextScale;
        /* 0x154 */ float mAButtonTextPosX;
        /* 0x158 */ float mAButtonTextPosY;
        /* 0x15C */ float mAButtonTextScale;
        /* 0x160 */ float mBButtonTextPosX;
        /* 0x164 */ float mBButtonTextPosY;
        /* 0x168 */ float mBButtonTextScale;
        /* 0x16C */ float mRegionImagePosX[8];
        /* 0x18C */ float mRegionImagePosZ[8];
        /* 0x1AC */ float mRegionImageScale[8];
        /* 0x1CC */ float mRegionScrollRangeMinX[8];
        /* 0x1EC */ float mRegionScrollRangeMinZ[8];
        /* 0x20C */ float mRegionScrollRangeMaxX[8];
        /* 0x22C */ float mRegionScrollRangeMaxZ[8];
        /* 0x24C */ float mCursorScale;
        /* 0x250 */ float mCursorSpeed;
        /* 0x254 */ uint32_t mCursorBlack; // JUtility::TColor
        /* 0x258 */ uint32_t mCursorWhite; // JUtility::TColor
        /* 0x25C */ cXyz field_0x25c[12];
        /* 0x2EC */ bool mCursorDebugON;
        /* 0x2ED */ bool mButtonDebugON;
        /* 0x2EE */ uint8_t field_0x2ee[4];
        /* 0x2F2 */ uint8_t mMapType;
        /* 0x2F3 */ bool mDisplayWorldOrigin;
        /* 0x2F4 */ bool mDisplayRegionOrigin;
        /* 0x2F5 */ bool mDisplayStageOrigin;
        /* 0x2F6 */ bool mDisplayWorldGrid;
        /* 0x2F7 */ bool mDisplayRegionGrid;
        /* 0x2F8 */ bool mDisplayReferenceArea;
        /* 0x2F9 */ uint8_t field_0x2f9;
        /* 0x2FA */ bool mTerminalOutput;
        /* 0x2FB */ bool mPortalDataTerminalOutput;
        /* 0x2FC */ bool mAllRegionsUnlocked;
        /* 0x2FD */ bool mDisplayAllPaths;
        /* 0x2FE */ bool mRegionPrintGlobalScroll;
        /* 0x2FF */ bool mRangeCheck;
        /* 0x300 */ bool mRangeCheckDrawPriority;
        /* 0x301 */ bool mPortalWarpON;
        /* 0x302 */ bool mDrawBackground;
        /* 0x303 */ uint8_t field_0x303;
        /* 0x304 */ uint8_t mRangeCheckInterval;
        /* 0x305 */ uint8_t field_0x305;
        /* 0x306 */ bool mScrollRangeDebugON;
        /* 0x307 */ bool mScrollRangeDisplay;
        /* 0x308 */ bool field_0x308; // related to scroll range display
        /* 0x309 */ bool mRegionImageDebug;
        /* 0x30A */ bool mRegionBitTerminalOutput;
        /* 0x30B */ bool mDebugRegionBits[8];
        /* 0x313 */ uint8_t padding_313[1];
        /* 0x314 */ dMeter_mapIconHIO_c mMapIconHIO;
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_fmapHIO_c) == 0x4A4);

    class dMeter_cursorHIO_c
    {
       public:
        dMeter_cursorHIO_c() { dMeter_cursorHIO_c_ct(this); }

        /* 0x00 */ void* vtable;
        /* 0x04 */ int8_t field_0x4;
        /* 0x05 */ uint8_t padding_5[3];
        /* 0x08 */ cXyz mSeraShopObjZoom;
        /* 0x14 */ cXyz mObjZoom;
        /* 0x20 */ cXyz mMagicArmorObjZoom;
        /* 0x2C */ float mShopCursorScale;
        /* 0x30 */ float mShopCursorOffsetY;
        /* 0x34 */ float mMagicArmorCursorOffsetX;
        /* 0x38 */ float mMagicArmorCursorOffsetY;
        /* 0x3C */ int16_t mSeraShopObjZoomAngleX;
        /* 0x3E */ int16_t mShopObjZoomAngleX;
        /* 0x40 */ int16_t mMagicArmorObjZoomAngleX;
        /* 0x42 */ uint8_t padding_42[2];
    } __attribute__((__packed__));

    static_assert(sizeof(dMeter_cursorHIO_c) == 0x44);

    // Functions/variables
    extern "C"
    {
        extern dMeter_menuHIO_c g_menuHIO;
        extern dMeter_drawHIO_c g_drawHIO;
        extern dMeter_ringHIO_c g_ringHIO;
        extern dMeter_fmapHIO_c g_fmapHIO;
        extern dMeter_cursorHIO_c g_cursorHIO;
    }
} // namespace libtp::tp::d_meter_hio
#endif