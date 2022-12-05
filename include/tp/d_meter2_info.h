/**	@file d_meter2_info.h
 *	@brief Holds the pointers to button transparancy values (possibly more)
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_METER2_INFO_H
#define TP_D_METER2_INFO_H

#include "tp/d_com_inf_game.h"
#include "tp/d_meter2.h"
#include "tp/d_msg_object.h"

namespace libtp::tp::d_meter2_info
{
    struct G_Meter2_Info
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t unk4[4];
        /* 0x08 */ uint64_t unk8;
        /* 0x10 */ tp::d_msg_object::StringDataTable* stringDataTable;     // mMsgResource
        /* 0x14 */ void* mStageMsgResource;
        /* 0x18 */ void* mMsgUnitResource;
        /* 0x1C */ libtp::tp::d_meter2::dMeter2_c* mMeterClass;
        /* 0x20 */ void* mMeterMap;            // dMeterMap_c*
        /* 0x24 */ void* mMenuWindowClass;     // dMw_c*
        /* 0x28 */ libtp::tp::d_pane_class::CPaneMgr* mMeterItemPanePtr[4];
        /* 0x38 */ uint8_t unk38[0x1C];     // WarpInfo_c mWarpInfo;
        /* 0x54 */ float unk84;
        /* 0x58 */ float unk88;
        /* 0x5C */ float unk92;
        /* 0x60 */ float unk96;
        /* 0x64 */ float unk100;
        /* 0x68 */ float unk104;
        /* 0x6C */ float unk108;
        /* 0x70 */ float m2DWidth;
        /* 0x74 */ float m2DHeight;
        /* 0x78 */ float m2DPosH;
        /* 0x7C */ float m2DPosV;
        /* 0x80 */ float unk128;
        /* 0x84 */ uint32_t mTimeMs;
        /* 0x88 */ uint32_t mMsgTimeMs;
        /* 0x8C */ uint32_t mMeterString;
        /* 0x90 */ uint32_t mTempBits;
        /* 0x94 */ int16_t mMsgKeyWaitTimer;
        /* 0x96 */ uint16_t mHorseLifeCount;
        /* 0x98 */ uint16_t unk152;
        /* 0x9A */ uint16_t mHotSpringTimer[4];
        /* 0xA2 */ uint16_t mSub2DStatus;
        /* 0xA4 */ uint16_t mFloatingFlowID;
        /* 0xA6 */ uint16_t mFloatingMessageID;
        /* 0xA8 */ int16_t mFloatingMessageTimer;
        /* 0xAA */ uint16_t mMapKeyDirection;
        /* 0xAC */ uint16_t mBlinkButton;
        /* 0xAE */ uint16_t mUseButton;
        /* 0xB0 */ uint16_t mGameStatus;
        /* 0xB2 */ uint16_t mTouchKeyCheck;
        /* 0xB4 */ uint16_t mWindowAccept;
        /* 0xB6 */ uint16_t mOilGaugeBackUp;
        /* 0xB8 */ uint8_t mDirectUseItem;
        /* 0xB9 */ uint8_t mWindowStatus;
        /* 0xBA */ uint8_t unk186;
        /* 0xBB */ uint8_t mMaxCount;
        /* 0xBC */ uint8_t mNowCount;
        /* 0xBD */ bool mShopTalkFlag;
        /* 0xBE */ uint8_t unk190;
        /* 0xBF */ uint8_t mMapStatus;
        /* 0xC0 */ uint8_t mWarpStatus;
        /* 0xC1 */ uint8_t mPauseStatus;
        /* 0xC2 */ uint8_t mGameOverType;
        /* 0xC3 */ uint8_t mInsectSelectType;
        /* 0xC4 */ uint8_t mSaveSelItemIdx[4];
        /* 0xC8 */ uint8_t mSaveMixItemIdx[4];
        /* 0xCC */ uint8_t mSaveBombNum;
        /* 0xCD */ uint8_t mSaveArrowNum;
        /* 0xCE */ uint8_t mSaveBowItem;
        /* 0xCF */ uint8_t mSaveBombItem;
        /* 0xD0 */ uint8_t mSaveSelItemIdxMG[4];
        /* 0xD4 */ uint8_t mSaveMixItemIdxMG[4];
        /* 0xD8 */ uint8_t mSaveBombNumMG;
        /* 0xD9 */ uint8_t mSaveArrowNumMG;
        /* 0xDA */ uint8_t mSaveBowItemMG;
        /* 0xDB */ uint8_t mSaveBombItemMG;
        /* 0xDC */ uint8_t mRentalBombBag;
        /* 0xDD */ uint8_t mMiniGameItemSetFlag;     // 1: rented in game, 3: rented not in game
        /* 0xDE */ uint8_t mMiniGameCount;
        /* 0xDF */ uint8_t mCollectCursorPosX;
        /* 0xE0 */ uint8_t mCollectCursorPosY;
        /* 0xE1 */ uint8_t mTableMapRegionNo;
        /* 0xE2 */ uint8_t mGoldWolfMapType;
        /* 0xE3 */ uint8_t mLightDropGetFlag[3];
        /* 0xE6 */ uint8_t mLifeGaugeSE;
        /* 0xE7 */ uint8_t unk231;
        /* 0xE8 */ uint8_t mItemExplainWindowStatus;
        /* 0xE9 */ char mSaveStageName[8];
        /* 0xF1 */ bool mFloatingMessageWakuVisible;
        /* 0xF2 */ uint8_t mMapDrugFlag;
        /* 0xF3 */ uint8_t unk243[5];
    } __attribute__( ( __packed__ ) );

    extern "C"
    {
        /**
         *	@brief Gets a pointer to the transparancy of the Z button
         */
        extern void* wZButtonPtr;
        extern G_Meter2_Info g_meter2_info;

        void resetMiniGameItem( G_Meter2_Info* g_meter2_info_ptr, bool minigameFlag );
    }
}     // namespace libtp::tp::d_meter2_info
#endif