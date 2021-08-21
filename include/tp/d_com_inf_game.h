/**	@file d_com_inf_game.h
 *	@brief Holds general game information
 *
 *	d_com_inf_game is one of the most crucial fields
 *	with various data about the current game state
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef TP_D_COM_INF_GAME_H
#define TP_D_COM_INF_GAME_H


#include "evt_control.h"
#include "d_stage.h"
#include "d_event.h"
#include "d_event_manager.h"
#include "d_save.h"

#include <cstdint>

namespace libtp::tp::d_com_inf_game
{
    /**
     *	@brief Holds 1:1 save-file data
     *
     *	@todo Fill missing vars.
     *	@todo Make bitfields actual bitwise variables for easier access.
     *(https://en.cppreference.com/w/cpp/language/bit_field)
     */

    struct dComIfG_play 
    {
        /* 0x00000 */ uint8_t field_0x0[0x1404]; //dBgS mDBgS;
        /* 0x01404 */ uint8_t field_0x1404[0x2AC4]; //dCcS mDCcS;
        /* 0x03EC8 */ libtp::tp::d_stage::dStage_startStage mStartStage; //Possibly currentStageVars
        /* 0x03ED5 */ uint8_t field_0x3ed5;  // probably padding
        /* 0x03ED6 */ libtp::tp::d_stage::dStage_nextStage mNextStage; //Probably nextStageVars
        /* 0x03EE7 */ uint8_t field_0x3ee7;  // probably padding
        /* 0x03EE8 */ uint8_t field_0x3ee8[0xA4]; //dStage_stageDt mStageData; 
        /* 0x03F8C */ libtp::tp::d_stage::dStage_roomControl* mRoomControl;
        /* 0x03F90 */ libtp::tp::d_event::dEvt_control mEvent; //Probably EventSystem
        /* 0x040C0 */ libtp::tp::d_event_manager::dEvent_manager mEvtManager; 
        /* 0x04780 */ uint8_t field_0x4780[0x51C]; //dAttention_c mAttention;
        /* 0x04C9C */ uint8_t field_0x4c9c[0x90]; //dVibration_c mVibration;
        /* 0x04D2C */ uint8_t field_0x4d2c[4];
        /* 0x04D30 */ uint8_t field_0x4d30[4]; //JKRArchive* mFieldMapArchive2;
        /* 0x04D34 */ uint8_t field_0x4d34[0x2C]; //JKRArchive* mMsgArchive[11];
        /* 0x04D60 */ uint8_t field_0x4d60[4]; //JKRArchive* mDemoMsgArchive;
        /* 0x04D64 */ uint8_t field_0x4d64[4]; //JKRArchive* mMeterButtonArchive;
        /* 0x04D68 */ void* field_0x4d68;
        /* 0x04D6C */ uint8_t field_0x4d6C[4]; //JKRArchive* mFontArchive;
        /* 0x04D70 */ uint8_t field_0x4d70[4]; //JKRArchive* mRubyArchive;
        /* 0x04D74 */ uint8_t field_0x4d74[4]; //JKRArchive* mAnmArchive;
        /* 0x04D78 */ void* field_0x4d78[2];
        /* 0x04D80 */ uint8_t field_0x4d80[4]; //JKRArchive* mCollectResArchive;
        /* 0x04D84 */ uint8_t field_0x4d84[4]; //JKRArchive* mFmapResArchive;
        /* 0x04D88 */ uint8_t field_0x4d88[4]; //JKRArchive* mDmapResArchive;
        /* 0x04D8C */ uint8_t field_0x4d8c[4]; //JKRArchive* mOptionResArchive;
        /* 0x04D90 */ void* field_0x4d90[2];
        /* 0x04D98 */ uint8_t field_0x4d98[4]; //JKRArchive* mItemIconArchive;
        /* 0x04D9C */ uint8_t field_0x4d9C[4]; //JKRArchive* mNameResArchive;
        /* 0x04DA0 */ uint8_t field_0x4da0[4]; //JKRArchive* mErrorResArchive;
        /* 0x04DA4 */ void* field_0x4da4;
        /* 0x04DA8 */ uint8_t field_0x4da8[4]; //JKRArchive* mAllMapArchive;
        /* 0x04DAC */ uint8_t field_0x4dac[4]; //JKRArchive* mMsgCommonArchive;
        /* 0x04DB0 */ uint8_t field_0x4db0[4]; //JKRArchive* mRingResArchive;
        /* 0x04DB4 */ void* field_0x4db4;
        /* 0x04DB8 */ uint8_t field_0x4db8[4]; //JKRArchive* mCardIconResArchive;
        /* 0x04DBC */ uint8_t field_0x4dbc[0x3C]; //JKRArchive* mMsgDtArchive[15];
        /* 0x04DF8 */ uint8_t field_0x4df8[4]; //JKRArchive* mMain2DArchive;
        /* 0x04DFC */ void* field_0x4dfc[2];
        /* 0x04E04 */ void* mParticle;
        /* 0x04E08 */ void* mSimpleModel;
        /* 0x04E0C */ uint8_t mWindowNum;
        /* 0x04E0D */ uint8_t mLayerOld;
        /* 0x04E0E */ uint16_t mStatus;
        /* 0x04E10 */ uint8_t field_0x4e10[0x2C]; //dDlst_window_c mWindow;
        /* 0x04E3C */ uint8_t field_0x4e3c[4]; //dComIfG_camera_info_class* mCameraInfo;
        /* 0x04E40 */ int8_t mCameraWinID;
        /* 0x04E41 */ int8_t mCameraPlayer1ID;
        /* 0x04E42 */ int8_t mCameraPlayer2ID;
        /* 0x04E43 */ uint8_t field_0x4e43;
        /* 0x04E44 */ uint32_t mCameraAttentionStatus;
        /* 0x04E48 */ float mCameraZoomScale;
        /* 0x04E4C */ float mCameraZoomForcus;
        /* 0x04E50 */ void* mCameraParamFileName;
        /* 0x04E54 */ libtp::tp::c_xyz::cXyz mCameraPos;
        /* 0x04E60 */ libtp::tp::c_xyz::cXyz mCameraTarget; //I think LinkMapVars is stored in here
        /* 0x04E6C */ float mCameraUnk1;
        /* 0x04E70 */ int16_t mCameraUnk2;
        /* 0x04E72 */ int16_t field_0x4e72;
        /* 0x04E74 */ uint8_t field_0x4e74[4]; //daAlink_c* mPlayer;
        /* 0x04E78 */ int8_t  mPlayerCameraID[4];
        /* 0x04E7C */ uint8_t field_0x4e7c[4]; //daAlink_c* mPlayerPtr;
        /* 0x04E80 */ uint8_t field_0x4e80[4]; //daHorse_c* mHorseActor;
        /* 0x04E84 */ void* mMsgObjectClass;
        /* 0x04E88 */ float mItemLifeCount;
        /* 0x04E8C */ uint32_t mItemRupeeCount;
        /* 0x04E90 */ int16_t  mItemKeyNumCount;
        /* 0x04E92 */ int16_t  mItemMaxLifeCount;
        /* 0x04E94 */ int16_t  mItemMagicCount;
        /* 0x04E96 */ int16_t  mItemNowMagicCount;
        /* 0x04E98 */ int16_t  mItemMaxMagicCount;
        /* 0x04E9A */ int16_t  field_0x4e9a;
        /* 0x04E9C */ uint32_t mItemOilCount;
        /* 0x04EA0 */ uint32_t mItemNowOil;
        /* 0x04EA4 */ uint32_t mItemMaxOilCount;
        /* 0x04EA8 */ uint32_t mOxygen;
        /* 0x04EAC */ uint32_t mNowOxygen;
        /* 0x04EB0 */ uint32_t mMaxOxygen;
        /* 0x04EB4 */ uint32_t mOxygenCount;
        /* 0x04EB8 */ uint32_t mMaxOxygenCount;
        /* 0x04EBC */ int16_t  mItemArrowNumCount;
        /* 0x04EBE */ int16_t  mItemPachinkoNumCount;
        /* 0x04EC0 */ int16_t  mItemMaxArrowNumCount;
        /* 0x04EC2 */ int16_t  mItemBombNumCount[3];
        /* 0x04EC8 */ uint8_t  field_0x4ec8[4];
        /* 0x04ECC */ int16_t  mItemMaxBombNumCount1;
        /* 0x04ECE */ int16_t  mItemMaxBombNumCount2;
        /* 0x04ED0 */ uint8_t  field_0x4ed0[6];
        /* 0x04ED6 */ int16_t  mItemMaxBombNumCount3;
        /* 0x04ED8 */ uint8_t  field_0x4ed8[6];
        /* 0x04EDE */ uint16_t  mItemNowLife;
        /* 0x04EE0 */ uint8_t  field_0x4ee0[2];
        /* 0x04EE2 */ uint8_t  mMesgStatus;
        /* 0x04EE3 */ uint8_t  field_0x4ee3;
        /* 0x04EE4 */ uint8_t  mRStatus;
        /* 0x04EE5 */ uint8_t  mAStatus;  // B button
        /* 0x04EE6 */ uint8_t  field_0x4ee6;
        /* 0x04EE7 */ uint8_t  mNunStatus;
        /* 0x04EE8 */ uint8_t  mBottleStatus;
        /* 0x04EE9 */ uint8_t  mRemoConStatus;
        /* 0x04EEA */ uint8_t  field_0x4eea[2];
        /* 0x04EEC */ uint8_t  mDoStatus;  // A button
        /* 0x04EED */ uint8_t  field_0x4eed;
        /* 0x04EEE */ uint8_t  m3DStatus;
        /* 0x04EEF */ uint8_t  field_0x4eef;  // related to NunStatusForce
        /* 0x04EF0 */ uint8_t  field_0x4ef0;  // related to NunStatus
        /* 0x04EF1 */ uint8_t  field_0x4ef1;  // related to RemoConStatusForce
        /* 0x04EF2 */ uint8_t  field_0x4ef2;  // related to RemoConStatus
        /* 0x04EF3 */ uint8_t  field_0x4ef3[2];
        /* 0x04EF5 */ uint8_t  m3DDirection;
        /* 0x04EF6 */ uint8_t  m3DDirectionForce;
        /* 0x04EF7 */ uint8_t  mCStickStatus;
        /* 0x04EF8 */ uint8_t  mCStickDirection;
        /* 0x04EF9 */ uint8_t  mCStickDirectionForce;
        /* 0x04EFA */ uint8_t  mSButtonStatus;
        /* 0x04EFB */ uint8_t  mZStatus;
        /* 0x04EFC */ uint8_t  mRStatusForce;
        /* 0x04EFD */ uint8_t  mAStatusForce;
        /* 0x04EFE */ uint8_t  field_0x4efe;
        /* 0x04EFF */ uint8_t  field_0x4eff;  // related to NunStatusForce
        /* 0x04F00 */ uint8_t  mBottleStatusForce;
        /* 0x04F01 */ uint8_t  field_0x4f01;  // related to RemoConStatusForce
        /* 0x04F02 */ uint8_t  field_0x4f02[2];
        /* 0x04F04 */ uint8_t  mDoStatusForce;
        /* 0x04F05 */ uint8_t  mTouchStatusForce;
        /* 0x04F06 */ uint8_t  m3DStatusForce;
        /* 0x04F07 */ uint8_t  mCStickStatusForce;
        /* 0x04F08 */ uint8_t  mSButtonStatusForce;
        /* 0x04F09 */ uint8_t  mZStatusForce;
        /* 0x04F0A */ uint8_t  mRSetFlag;
        /* 0x04F0B */ uint8_t  mASetFlag;
        /* 0x04F0C */ uint8_t  field_0x4f0c;
        /* 0x04F0D */ uint8_t  mNunSetFlag;
        /* 0x04F0E */ uint8_t  mBottleSetFlag;
        /* 0x04F0F */ uint8_t  mRemoConSetFlag;
        /* 0x04F10 */ uint8_t  field_0x4f10[2];
        /* 0x04F12 */ uint8_t  mDoSetFlag;
        /* 0x04F13 */ uint8_t  m3DSetFlag;
        /* 0x04F14 */ uint8_t  mCStickSetFlag;
        /* 0x04F15 */ uint8_t  mSButtonSetFlag;
        /* 0x04F16 */ uint8_t  mZSetFlag;
        /* 0x04F17 */ uint8_t  mRSetFlagForce;
        /* 0x04F18 */ uint8_t  mASetFlagForce;
        /* 0x04F19 */ uint8_t  field_0x4f19;
        /* 0x04F1A */ uint8_t  field_0x4f1a;  // related to NunStatusForce
        /* 0x04F1B */ uint8_t  mBottleSetFlagForce;
        /* 0x04F1C */ uint8_t  field_0x4f1c;  // related to RemoConStatusForce
        /* 0x04F1D */ uint8_t  field_0x4f1d[2];
        /* 0x04F1F */ uint8_t  mDoSetFlagForce;
        /* 0x04F20 */ uint8_t  m3DSetFlagForce;
        /* 0x04F21 */ uint8_t  mCStickSetFlagForce;
        /* 0x04F22 */ uint8_t  mSButtonSetFlagForce;
        /* 0x04F23 */ uint8_t  mZSetFlagForce;
        /* 0x04F24 */ uint8_t  mXStatus;
        /* 0x04F25 */ uint8_t  mXStatusForce;
        /* 0x04F26 */ uint8_t  field_0x4fbe;  // related to XStatus
        /* 0x04F27 */ uint8_t  mXSetFlagForce;
        /* 0x04F28 */ uint8_t  mYStatus;
        /* 0x04F29 */ uint8_t  mYStatusForce;
        /* 0x04F2A */ uint8_t  mYSetFlag;
        /* 0x04F2B */ uint8_t  mYSetFlagForce;
        /* 0x04F2C */ uint8_t  mNunZStatus;
        /* 0x04F2D */ uint8_t  mNunZSetFlag;
        /* 0x04F2E */ uint8_t  field_0x4fc6;  // related to NunZStatusForce
        /* 0x04F2F */ uint8_t  field_0x4fc7;  // related to NunZStatusForce
        /* 0x04F30 */ uint8_t  mNunCStatus;
        /* 0x04F31 */ uint8_t  mNunCSetFlag;
        /* 0x04F32 */ uint8_t  field_0x4fca;  // related to NunCStatusForce
        /* 0x04F33 */ uint8_t  field_0x4fcb;  // related to NunCStatusForce
        /* 0x04F34 */ uint8_t  mSelectItem[8];
        /* 0x04F3C */ uint8_t  mSelectEquip[6];
        /* 0x04F42 */ uint8_t  mBaseAnimeID;
        /* 0x04F43 */ uint8_t  mFaceAnimeID;
        /* 0x04F44 */ uint8_t  mNowAnimeID;
        /* 0x04F45 */ uint8_t  mItemSlot;
        /* 0x04F46 */ uint8_t  mItemID;
        /* 0x04F47 */ uint8_t  field_0x4f47[2];
        /* 0x04F49 */ uint8_t  mDirection;
        /* 0x04F4A */ uint8_t  field_0x4f4a;
        /* 0x04F4B */ uint8_t  field_0x4f4b;  // related to itemInit
        /* 0x04F4C */ uint8_t  field_0x4f4c;  // related to itemInit
        /* 0x04F4D */ uint8_t  field_0x4f4d;
        /* 0x04F4E */ uint8_t  mMesgCancelButton;
        /* 0x04F4F */ uint8_t  field_0x4f4f[2];
        /* 0x04F51 */ uint8_t  mGameoverStatus;
        /* 0x04F52 */ uint8_t  field_0x4f52[5];
        /* 0x04F57 */ uint8_t  mHeapLockFlag;
        /* 0x04F58 */ uint8_t  mSubHeapLockFlag[2];
        /* 0x04F5A */ uint8_t  mNowVibration;
        /* 0x04F5B */ uint8_t  field_0x4f5b[2];
        /* 0x04F5D */ uint8_t  mWolfAbility;
        /* 0x04F5E */ uint8_t  field_0x4f5e[11];
        /* 0x04F69 */ uint8_t  mNeedLightDropNum;
        /* 0x04F6A */ uint8_t  field_0x4f6a[18];
        /* 0x04F7C */ uint8_t  mMesgBgm;
        /* 0x04F7D */ bool mPauseFlag;
        /* 0x04F7E */ uint8_t  mItemLifeCountType;
        /* 0x04F7F */ uint8_t  mOxygenShowFlag;
        /* 0x04F80 */ uint8_t  mShow2D;
        /* 0x04F81 */ uint8_t  field_0x4f81[3];
        /* 0x04F84 */ uint8_t field_0x4f84[4]; //JKRExpHeap* mExpHeap2D;
        /* 0x04F88 */ uint8_t field_0x4f88[4]; //JKRExpHeap* mSubExpHeap2D[2];
        /* 0x04F90 */ uint8_t field_0x4f90[4]; //JKRExpHeap* mMsgExpHeap;
        /* 0x04F94 */ char field_0x4F94[8];  // related to setWarpItemData
        /* 0x04F9C */ libtp::tp::c_xyz::cXyz field_0x4f9c;     // related to setWarpItemData
        /* 0x04FA8 */ uint8_t  field_0x4fa8[2];
        /* 0x04FAA */ uint8_t  field_0x4faa;  // related to setWarpItemData
        /* 0x04FAB */ uint8_t  field_0x4fab;  // related to setWarpItemData
        /* 0x04FAC */ uint8_t  field_0x4fac;  // related to setWarpItemData
        /* 0x04FAD */ uint8_t  field_0x4fad[3];
        /* 0x04FB0 */ void* mMesgCamInfo;
        /* 0x04FB4 */ uint32_t mMesgCamInfoBasicID;
        /* 0x04FB8 */ uint8_t field_0x4fb8[4]; //fopAc_ac_c* mMesgCamInfoActor1;
        /* 0x04FBC */ uint8_t field_0x4fbc[4]; //fopAc_ac_c* mMesgCamInfoActor2;
        /* 0x04FC0 */ uint8_t field_0x4fc0[4]; //fopAc_ac_c* mMesgCamInfoActor3;
        /* 0x04FC4 */ uint8_t field_0x4fc4[4]; //fopAc_ac_c* mMesgCamInfoActor4;
        /* 0x04FC8 */ uint8_t field_0x4fc8[4]; //fopAc_ac_c* mMesgCamInfoActor5;
        /* 0x04FCC */ uint8_t field_0x4fcc[4]; //fopAc_ac_c* mMesgCamInfoActor6;
        /* 0x04FD0 */ uint8_t field_0x4fd0[4]; //fopAc_ac_c* mMesgCamInfoActor7;
        /* 0x04FD4 */ uint8_t field_0x4fd4[4]; //fopAc_ac_c* mMesgCamInfoActor8;
        /* 0x04FD8 */ uint8_t field_0x4fd8[4]; //fopAc_ac_c* mMesgCamInfoActor9;
        /* 0x04FDC */ uint8_t field_0x4fdc[4]; //fopAc_ac_c* mMesgCamInfoActor10;
        /* 0x04FE0 */ uint32_t mPlayerStatus;
        /* 0x04FE4 */ uint8_t  field_0x4fe4[0x14];
        /* 0x04FF8 */ uint8_t field_0x4ff8[4]; //dTimer_c* mTimerPtr;
        /* 0x04FFC */ uint32_t mTimerNowTimeMs;
        /* 0x05000 */ uint32_t mTimerLimitTimeMs;
        /* 0x05004 */ uint32_t mTimerMode;
        /* 0x05008 */ uint8_t  mTimerType;
        /* 0x0500C */ uint8_t field_0x500c[4]; //dDlst_window_c* mCurrentWindow;
        /* 0x05010 */ void* mCurrentView;
        /* 0x05014 */ void* mCurrentViewport;
        /* 0x05018 */ void* mCurrentGrafPort;
        /* 0x0501C */ void* mItemTable;
        /* 0x0501D */ uint8_t  field_0x501d[7];
        /* 0x05024 */ char mLastPlayStageName[8];
    } __attribute__((__packed__));

     struct dComIfG_inf_c //Game Info
    {
        libtp::tp::d_save::dSv_info_c save; //0 - F38
        dComIfG_play play; // F39 - 5F63
        uint8_t field_0x5f64[0x161AC]; //dDlst_list_c draw_list_list; 5F64 - 1C10F
        uint8_t field_0x1c110[0x1E8]; //1C110 - 1C2F7
        uint8_t field_0x1c2f8[0x1B00]; //dRes_control_c mResControl; 1C2F8 - 1DDF7
        uint8_t field_0x1ddf8; //1DDF8
        uint8_t mWorldDark; //1DDF9
        uint8_t field_0x1ddfa; //1DDFA
        uint8_t field_0x1ddfb; //1DDFB
        uint8_t field_0x1ddfc; //1DDFC
        uint8_t padding[3]; //1DDFD - 1DDFF
        uint32_t field_0x1de00; //1DE00 - 1DE03
        uint32_t field_0x1de04; //1DE04 -  1DE07
        uint8_t field_0x1de08; //1DE08
        uint8_t field_0x1de09; //1DE09
        uint8_t field_0x1de0a; //1DE0A
        uint8_t padding_0x1DE0B[8]; //1DE0B - 1DE010
    } __attribute__((__packed__));

    extern "C"
    {
        extern dComIfG_inf_c dComIfG_gameInfo;
    }
}  // namespace libtp::tp::d_com_inf_game
#endif