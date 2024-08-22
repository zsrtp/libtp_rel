/**	@file d_meter2.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_D_METER2_H
#define TP_D_METER2_H

#include <cstdint>

#include "tp/d_meter2_draw.h"

namespace libtp::tp::d_meter2
{
    struct dMeter2_c
    {
        /* 0x000 */ uint8_t field_0x0[0x100];
        /* 0x100 */ void* mpHeap;    // JKRExpHeap*
        /* 0x104 */ void* mpSubHeap; // JKRExpHeap*
        /* 0x108 */ void* field_0x108;
        /* 0x10C */ libtp::tp::d_meter2_draw::dMeter2Draw_c* mpMeterDraw;
        /* 0x110 */ void* field_0x110; // dDlst_base_c*
        /* 0x114 */ void* field_0x114; // dDlst_base_c*
        /* 0x118 */ void* field_0x118; // dDlst_base_c*
        /* 0x11C */ void* field_0x11c;
        /* 0x120 */ void* mpMap;       // dMeterMap_c*
        /* 0x124 */ uint32_t mStatus;
        /* 0x128 */ int32_t field_0x128;
        /* 0x12C */ int32_t field_0x12c;
        /* 0x130 */ float field_0x130;
        /* 0x134 */ float field_0x134[2];
        /* 0x13C */ float field_0x13c[2];
        /* 0x144 */ float field_0x144;
        /* 0x148 */ float field_0x148[2];
        /* 0x150 */ float field_0x150[2];
        /* 0x158 */ float field_0x158;
        /* 0x15C */ float field_0x15c;
        /* 0x160 */ float field_0x160[4];
        /* 0x170 */ uint8_t field_0x170[4];
        /* 0x174 */ float field_0x174[4];
        /* 0x184 */ uint8_t field_0x184[4];
        /* 0x188 */ float field_0x188;
        /* 0x18C */ float field_0x18c;
        /* 0x190 */ int16_t field_0x190;
        /* 0x192 */ int16_t mNowLifeGauge;
#if defined(TP_WUS2) || defined(TP_WJP)
        /* 0x194 */ uint8_t unk0[0xC]; //heart UI related maybe?
        /* 0x1A0 */ int16_t mMaxLife;
        /* 0x1A2 */ int16_t mNowMagic;
        /* 0x1A4 */ int16_t mMaxMagic;
        /* 0x1A6 */ int16_t field_0x19a;
        /* 0x1A8 */ int32_t mNowOil;
        /* 0x1AC */ int32_t mMaxOil;
        /* 0x1B0 */ int32_t mNowOxygen;
        /* 0x1B4 */ int32_t mMaxOxygen;
#else
        /* 0x194 */ int16_t mMaxLife;
        /* 0x196 */ int16_t mNowMagic;
        /* 0x198 */ int16_t mMaxMagic;
        /* 0x19A */ int16_t field_0x19a;
        /* 0x19C */ int32_t mNowOil;
        /* 0x1A0 */ int32_t mMaxOil;
        /* 0x1A4 */ int32_t mNowOxygen;
        /* 0x1A8 */ int32_t mMaxOxygen;
        /* 0x1AC */ int32_t field_0x1ac;
        /* 0x1B0 */ uint16_t mRupeeNum;
        /* 0x1B2 */ uint16_t mKeyNum;
        /* 0x1B4 */ uint16_t field_0x1b4;
        /* 0x1B6 */ uint16_t mSubContentsStringType;
#endif
        /* 0x1B8 */ uint16_t field_0x1b8[5];
        /* 0x1C2 */ uint8_t mLightDropNum;
        /* 0x1C3 */ uint8_t mNeedLightDropNum;
        /* 0x1C4 */ uint8_t mDoStatus;
        /* 0x1C5 */ uint8_t mAStatus;
        /* 0x1C6 */ uint8_t field_0x1c6;
        /* 0x1C7 */ uint8_t mCollectSmell;
        /* 0x1C8 */ uint8_t mRStatus;
        /* 0x1C9 */ uint8_t mZStatus;
        /* 0x1CA */ uint8_t m3DStatus;
        /* 0x1CB */ uint8_t mCStickStatus;
        /* 0x1CC */ uint8_t mSButtonStatus;
        /* 0x1CD */ uint8_t mNunStatus;
        /* 0x1CE */ uint8_t mRemoConStatus;
        /* 0x1CF */ uint8_t mNunZStatus;
        /* 0x1D0 */ uint8_t mNunCStatus;
        /* 0x1D1 */ uint8_t mBottleStatus;
        /* 0x1D2 */ uint8_t mItemStatus[4];
        /* 0x1D6 */ uint8_t field_0x1d6[2];
        /* 0x1D8 */ uint8_t field_0x1d8[2];
#if defined(TP_WUS2) || defined(TP_WJP)
        /* 0x1DA */ uint8_t unk1;
        /* 0x1DB */ uint8_t unk11111;
#else
        /* 0x1DA */ uint8_t mArrowNum;
        /* 0x1DB */ uint8_t mPachinkoNum;
#endif
        /* 0x1DC */ uint8_t mDoSetFlag;
        /* 0x1DD */ uint8_t mASetFlag;
        /* 0x1DE */ uint8_t mRSetFlag;
        /* 0x1DF */ uint8_t mXSetFlag;
        /* 0x1E0 */ uint8_t mYSetFlag;
        /* 0x1E1 */ uint8_t field_0x1e1;
        /* 0x1E2 */ uint8_t mEquipSword;
        /* 0x1E3 */ uint8_t field_0x1e3;
        /* 0x1E4 */ uint8_t field_0x1e4;
        /* 0x1E5 */ uint8_t mSubContentType;
        /* 0x1E6 */ uint8_t field_0x1e6;
        /* 0x1E7 */ uint8_t field_0x1e7;
        /* 0x1E8 */ uint8_t field_0x1e8;
        /* 0x1E9 */ uint8_t field_0x1e9;
        /* 0x1EA */ uint8_t mRupeeSound;
#if defined(TP_WUS2) || defined(TP_WJP)
        /* 0x1EB */ uint8_t unk2;
#else
        /* 0x1EB */ uint8_t mArrowSound;
#endif
        /* 0x1EC */ uint8_t field_0x1ec;
        /* 0x1ED */ uint8_t field_0x1ed;
        /* 0x1EE */ uint8_t mLifeCountType;
#if defined(TP_WUS2) || defined(TP_WJP)
        /* 0x1EF */ uint8_t mArrowNum;
        /* 0x1F0 */ uint8_t mPachinkoNum;
        /* 0x1F1 */ uint8_t padding_0x1F1[12];
#else
        /* 0x1EF */ uint8_t mBottleNum[4];
        /* 0x1F3 */ uint8_t mBombNum[3];
        /* 0x1F6 */ uint8_t mBombMax[3];
        /* 0x1F9 */ uint8_t mItemMaxNum[4];
#endif
        /* 0x1FD */ uint8_t field_0x1fd[3];
#if defined(TP_WUS2) || defined(TP_WJP)
        /* 0x200 */ uint8_t field_0x200[2];
        /* 0x202 */ uint8_t mArrowSound;
#else
        /* 0x200 */ uint8_t field_0x200[3];
#endif
        /* 0x203 */ uint8_t padding_0x203;
        /* 0x204 */ float mLifeGuagePosX;
#if defined(TP_WUS2) || defined(TP_WJP)
        /* 0x208 */ uint8_t padding_0x208[2];
        /* 0x20A */ uint8_t mBombNum[3];
        /* 0x20D */ uint8_t mBombMax[3];
        /* 0x210 */ uint8_t unk3[2];
        /* 0x212 */ uint8_t mItemMaxNum[4];
        /* 0x216 */ uint8_t unk4[2];
        /* 0x218 */ uint8_t field_0x218[0x244 - 0x218];
        /* 0x244 */ float mLanternMeterScale;
        /* 0x248 */ float mLanternMeterPosX;
        /* 0x24C */ float mLanternMeterPosY;
        /* 0x250 */ float mOxygenMeterScale;
        /* 0x254 */ float mOxygenMeterPosX;
        /* 0x258 */ float mOxygenMeterPosY;
        /* 0x250 */ uint8_t field_0x250[0x25e - 0x25C];
        /* 0x25E */ int16_t field_0x246;
        /* 0x260 */ int16_t field_0x248;
        /* 0x260 */ uint8_t field_0x260[0x268 - 0x262];
#else
        /* 0x208 */ float mLifeGuagePosY;
        /* 0x20C */ float mLifeGuageScale;
        /* 0x210 */ float mHeartScale;
        /* 0x214 */ float mLargeHeartScale;
        /* 0x218 */ uint8_t field_0x218[0x22C - 0x218];
        /* 0x22C */ float mLanternMeterScale;
        /* 0x230 */ float mLanternMeterPosX;
        /* 0x234 */ float mLanternMeterPosY;
        /* 0x238 */ float mOxygenMeterScale;
        /* 0x23C */ float mOxygenMeterPosX;
        /* 0x240 */ float mOxygenMeterPosY;
        /* 0x244 */ uint8_t field_0x244[0x246 - 0x244];
        /* 0x246 */ int16_t field_0x246;
        /* 0x248 */ int16_t field_0x248;
        /* 0x24A */ uint8_t field_0x24a[0x268 - 0x24a];
#endif
        /* 0x268 */ float mRupeeKeyScale;
        /* 0x26C */ float mRupeeKeyPosX;
        /* 0x270 */ float mRupeeKeyPosY;
    } __attribute__((__packed__));

    extern "C"
    {
        /**
         *	@brief Initializes the values for the dMeter2 class.
         *
         *  @param dMeterPtr A pointer to the current dMeter2 structure.
         *
         *  @return Returns the status value of the class after the function runs.
         */
        uint32_t dMeter2_Create(dMeter2_c* dMeterPtr);

        /**
         * @brief Modifies the oil meter value in many ways, such as decreasing it when equipping or swinging the lantern.
         * 
         * @param dMeterPtr A pointer to the current dMeter2 structure.
        */
       void moveKantera(dMeter2_c* dMeterPtr);

        /**
        * @brief Determines whether the oil meter should be visible or not after checking multiple conditions, such as if oxygen meter is visible.
        * 
        * @param dMeterPtr A pointer to the current dMeter2 structure.
       */
       void alphaAnimeKantera(dMeter2_c* dMeterPtr);
    }
} // namespace libtp::tp::d_meter2
#endif
