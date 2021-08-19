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
#pragma once
#include <cstdint>

#include "evt_control.h"
#include "..\data\items.h"

namespace libtp::tp::d_com_inf_game
{
    /**
     *	@brief Holds 1:1 save-file data
     *
     *	@todo Fill missing vars.
     *	@todo Make bitfields actual bitwise variables for easier access.
     *(https://en.cppreference.com/w/cpp/language/bit_field)
     */

    struct GameInfo
    {
        SaveInfo save; //0 - F38
        dComIfG_play play; // F38 - 5F63
        dDlst_list_c draw_list_list; //5F64 - 1C10F
        uint8_t field_0x1C110[0x1E8]; //1C110 - 1C2F7
        dRes_control_c mResControl; //1C2F8 - 1DDF7
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
        uint8_t padding[8]; //1DE0B - 1DE010
    }

    struct SaveInfo
    {
        Save save_file; //ScratchPad 0 - 957
        Memory memory; //Local Area Nodes 958 - 977
        DanBit dungeon_bit; //978 - 9B3
        Zone zones[32]; //9B4 - DB3
        Restart restart; //DB4 - DD7
        Event events; //DD8 - ED7
        TurnRestart turn_restart; //ED8 - EEA
        uint8_t unk1[0x3D]; //EEB - F27
        uint32_t saveTotalTime; //F28
        uint32_t saveStartTime; //F2C
        uint32_t unkF30; //F30
        uint32_t unkF34; //F34
    };

    struct dComIfG_play //pulled this from decomp
    {
        /* 0x00000 */ dBgS mDBgS;
        /* 0x01404 */ dCcS mDCcS;
        /* 0x03EC8 */ dStage_startStage_c mStartStage;
        /* 0x03ED5 */ uint8_t field_0x3ed5;  // probably padding
        /* 0x03ED6 */ dStage_nextStage_c mNextStage;
        /* 0x03EE7 */ uint8_t field_0x3ee7;  // probably padding
        /* 0x03EE8 */ dStage_stageDt_c mStageData;
        /* 0x03F8C */ dStage_roomControl_c* mRoomControl;
        /* 0x03F90 */ dEvt_control_c mEvent;
        /* 0x040C0 */ dEvent_manager_c mEvtManager;
        /* 0x04780 */ dAttention_c mAttention;
        /* 0x04C9C */ dVibration_c mVibration;
        /* 0x04D2C */ uint8_t field_0x4d2c[4];
        /* 0x04D30 */ JKRArchive* mFieldMapArchive2;
        /* 0x04D34 */ JKRArchive* mMsgArchive[11];
        /* 0x04D60 */ JKRArchive* mDemoMsgArchive;
        /* 0x04D64 */ JKRArchive* mMeterButtonArchive;
        /* 0x04D68 */ void* field_0x4d68;
        /* 0x04D6C */ JKRArchive* mFontArchive;
        /* 0x04D70 */ JKRArchive* mRubyArchive;
        /* 0x04D74 */ JKRArchive* mAnmArchive;
        /* 0x04D78 */ void* field_0x4d78[2];
        /* 0x04D80 */ JKRArchive* mCollectResArchive;
        /* 0x04D84 */ JKRArchive* mFmapResArchive;
        /* 0x04D88 */ JKRArchive* mDmapResArchive;
        /* 0x04D8C */ JKRArchive* mOptionResArchive;
        /* 0x04D90 */ void* field_0x4d90[2];
        /* 0x04D98 */ JKRArchive* mItemIconArchive;
        /* 0x04D9C */ JKRArchive* mNameResArchive;
        /* 0x04DA0 */ JKRArchive* mErrorResArchive;
        /* 0x04DA4 */ void* field_0x4da4;
        /* 0x04DA8 */ JKRArchive* mAllMapArchive;
        /* 0x04DAC */ JKRArchive* mMsgCommonArchive;
        /* 0x04DB0 */ JKRArchive* mRingResArchive;
        /* 0x04DB4 */ void* field_0x4db4;
        /* 0x04DB8 */ JKRArchive* mCardIconResArchive;
        /* 0x04DBC */ JKRArchive* mMsgDtArchive[15];
        /* 0x04DF8 */ JKRArchive* mMain2DArchive;
        /* 0x04DFC */ void* field_0x4dfc[2];
        /* 0x04E04 */ void* mParticle;
        /* 0x04E08 */ void* mSimpleModel;
        /* 0x04E0C */ uint8_t mWindowNum;
        /* 0x04E0D */ uint8_t mLayerOld;
        /* 0x04E0E */ uint16_t mStatus;
        /* 0x04E10 */ dDlst_window_c mWindow;
        /* 0x04E3C */ dComIfG_camera_info_class* mCameraInfo;
        /* 0x04E40 */ int8_t mCameraWinID;
        /* 0x04E41 */ int8_t mCameraPlayer1ID;
        /* 0x04E42 */ int8_t mCameraPlayer2ID;
        /* 0x04E43 */ uint8_t field_0x4e43;
        /* 0x04E44 */ uint32_t mCameraAttentionStatus;
        /* 0x04E48 */ float mCameraZoomScale;
        /* 0x04E4C */ float mCameraZoomForcus;
        /* 0x04E50 */ void* mCameraParamFileName;
        /* 0x04E54 */ cXyz mCameraPos;
        /* 0x04E60 */ cXyz mCameraTarget;
        /* 0x04E6C */ float mCameraUnk1;
        /* 0x04E70 */ int16_t mCameraUnk2;
        /* 0x04E72 */ int16_t field_0x4e72;
        /* 0x04E74 */ daAlink_c* mPlayer;
        /* 0x04E78 */ int8_t  mPlayerCameraID[4];
        /* 0x04E7C */ daAlink_c* mPlayerPtr;
        /* 0x04E80 */ daHorse_c* mHorseActor;
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
        /* 0x04F84 */ JKRExpHeap* mExpHeap2D;
        /* 0x04F88 */ JKRExpHeap* mSubExpHeap2D[2];
        /* 0x04F90 */ JKRExpHeap* mMsgExpHeap;
        /* 0x04F94 */ char field_0x4F94[8];  // related to setWarpItemData
        /* 0x04F9C */ cXyz field_0x4f9c;     // related to setWarpItemData
        /* 0x04FA8 */ uint8_t  field_0x4fa8[2];
        /* 0x04FAA */ uint8_t  field_0x4faa;  // related to setWarpItemData
        /* 0x04FAB */ uint8_t  field_0x4fab;  // related to setWarpItemData
        /* 0x04FAC */ uint8_t  field_0x4fac;  // related to setWarpItemData
        /* 0x04FAD */ uint8_t  field_0x4fad[3];
        /* 0x04FB0 */ void* mMesgCamInfo;
        /* 0x04FB4 */ uint32_t mMesgCamInfoBasicID;
        /* 0x04FB8 */ fopAc_ac_c* mMesgCamInfoActor1;
        /* 0x04FBC */ fopAc_ac_c* mMesgCamInfoActor2;
        /* 0x04FC0 */ fopAc_ac_c* mMesgCamInfoActor3;
        /* 0x04FC4 */ fopAc_ac_c* mMesgCamInfoActor4;
        /* 0x04FC8 */ fopAc_ac_c* mMesgCamInfoActor5;
        /* 0x04FCC */ fopAc_ac_c* mMesgCamInfoActor6;
        /* 0x04FD0 */ fopAc_ac_c* mMesgCamInfoActor7;
        /* 0x04FD4 */ fopAc_ac_c* mMesgCamInfoActor8;
        /* 0x04FD8 */ fopAc_ac_c* mMesgCamInfoActor9;
        /* 0x04FDC */ fopAc_ac_c* mMesgCamInfoActor10;
        /* 0x04FE0 */ uint32_t mPlayerStatus;
        /* 0x04FE4 */ uint8_t  field_0x4fe4[0x14];
        /* 0x04FF8 */ dTimer_c* mTimerPtr;
        /* 0x04FFC */ uint32_t mTimerNowTimeMs;
        /* 0x05000 */ uint32_t mTimerLimitTimeMs;
        /* 0x05004 */ uint32_t mTimerMode;
        /* 0x05008 */ uint8_t  mTimerType;
        /* 0x0500C */ dDlst_window_c* mCurrentWindow;
        /* 0x05010 */ void* mCurrentView;
        /* 0x05014 */ void* mCurrentViewport;
        /* 0x05018 */ void* mCurrentGrafPort;
        /* 0x0501C */ void* mItemTable;
        /* 0x0501D */ uint8_t  field_0x501d[7];
        /* 0x05024 */ char mLastPlayStageName[8];
    }

    struct GameInfo
    {
        Save save_file; //ScratchPad
        Memory memory;
        DanBit dungeon_bit;
        Zone zones[32];
        Restart restart;
        Event events;
        TurnRestart turn_restart;
    };

    struct Save
    {
        Player player;
        uint8_t field_0x1ec[4];
        Memory area_flags[32];
        Memory ordon_area_flags;
        Memory sewers_area_flags;
        Memory faron_area_flags;
        Memory eldin_area_flags;
        Memory lanayru_area_flags;
        Memory unk5;
        Memory hyrule_field_flags;
        Memory sacred_grove_flags;
        Memory snowpeak_flags;
        Memory castle_town_flags;
        Memory gerudo_desert_flags;
        Memory fishing_hole_flags;
        Memory unk12[4];
        Memory forest_temple_flags;
        Memory goron_mines_flags;
        Memory lakebed_temple_flags;
        Memory arbiters_grounds_flags;
        Memory snowpeak_ruins_flags;
        Memory temple_of_time_flags;
        Memory city_in_the_sky_flags;
        Memory palace_of_twilight_flags;
        Memory hyrule_castle_flags;
        Memory cave_flags;
        Memory lake_hylia_lantern_cave_flags;
        Memory grotto_flags;
        Memory unk28[4];
        Memory2 ordon_ranch_map_flags;
        Memory2 ordon_village_map_flags;
        Memory2 ordon_spring_map_flags;
        Memory2 ordon_interiors_map_flags;
        Memory2 unk4;
        Memory2 sewers_map_flags;
        Memory2 faron_woods_map_flags;
        Memory2 coro_shop_map_flags;
        Memory2 sacred_grove_map_flags;
        Memory2 kakariko_village_map_flags;
        Memory2 death_mountain_map_flags;
        Memory2 kakariko_graveyard_map_flags;
        Memory2 kakariko_interiors_map_flags;
        Memory2 zoras_river_map_flags;
        Memory2 zoras_domain_map_flags;
        Memory2 snowpeak_map_flags;
        Memory2 lake_hylia_map_flags;
        Memory2 castle_town_map_flags;
        Memory2 desert_map_flags;
        Memory2 unk19[2];
        Memory2 hyrule_field_map_flags;
        Memory2 forest_temple_map_flags;
        Memory2 goron_mines_map_flags;
        Memory2 lakebed_temple_map_flags;
        Memory2 arbiters_grounds_map_flags;
        Memory2 snowpeak_ruins_map_flags;
        Memory2 temple_of_time_map_flags;
        Memory2 city_in_the_sky_map_flags;
        Memory2 palace_of_twilight_map_flags;
        Memory2 hyrule_castle_map_flags;
        Memory2 death_mountain_interiors_map_flags;
        Memory2 castle_town_interiors_map_flags;
        Memory2 fishing_pond_map_flags;
        Memory2 hidden_village_map_flags;
        Memory2 hidden_village_interiors_map_flags;
        Memory2 light_arrow_cutscene_map_flags;
        Memory2 hyrule_castle_cutscene_map_flags;
        Memory2 shades_realm_map_flags;
        Memory2 fishing_pond_interiors_map_flags;
        Memory2 ice_block_cave_map_flags;
        Memory2 cave_of_ordeals_map_flags;
        Memory2 gorge_lantern_cave_map_flags;
        Memory2 lake_hylia_lantern_cave_map_flags;
        Memory2 goron_stockcave_map_flags;
        Memory2 grotto_map_flags;
        Memory2 unk46[4];
        Memory2 faron_woods_cave_map_flags;
        Memory2 unk51[13];
        Event event_flags;
        uint8_t unk2288[80];
        MiniGame minigame_flags;
    };

    struct Player
    {
        PlayerStatusA player_status_a;
        PlayerStatusB player_status_b;
        HorsePlace horse_place;
        PlayerReturnPlace player_return_place;
        PlayerFieldLastStayInfo player_last_stay_info;
        PlayerLastMarkInfo player_last_mark_info;
        PlayerItem player_item;
        PlayerGetItem player_get_item;
        PlayerItemRecord player_item_record;
        PlayerItemMax player_item_max;
        PlayerCollect player_collect;
        PlayerWolf player_wolf;
        LightDrop light_drop;
        LetterInfo letter_info;
        FishingInfo fishing_info;
        PlayerInfo player_info;
        PlayerConfig player_config;
    };

    struct Memory
    {
        MemBit temp_flags;
    };

    struct Memory2
    {
        uint32_t room_flags1;
        uint32_t room_flags2;
    };

    struct Event
    {
        uint8_t events[256];
    };

    struct MiniGame
    {
        uint8_t unk0;
        uint8_t unk1[3];
        uint32_t unk4;
        uint32_t unk8;
        uint32_t unk12;
        uint32_t unk16;
        uint32_t unk20;
    };

    struct DanBit
    {
        int8_t unk0;
        uint8_t unk1;
        uint8_t unk2[2];
        uint32_t unk4[6];
        uint16_t unk28[16];
    };

    struct Zone
    {
        uint8_t unk0;
        uint8_t unk1;
        ZoneBit zone_bit;
        ZoneActor zone_actor;
    };

    struct ZoneBit
    {
        uint8_t unk0[4];
        uint16_t room_switch;
        uint16_t unk6[2];
        uint16_t room_item;
        uint16_t unk12;
    };

    struct ZoneActor
    {
        uint32_t unk0[4];
    };

    struct Restart
    {
        uint8_t unk0;
        uint8_t unk1[5];
        short angle;
        cXyz position;
        uint8_t padding20[16];
    };

    struct cXyz
    {
        float x;
        float y;
        float z;
    };

    struct TurnRestart
    {
        cXyz position;
        uint32_t unk12;
        short angle;
        int8_t unk18;
    };

    struct MemBit
    {
        uint32_t area_flags_bitfields1[2];
        uint32_t area_flags_bitfields2[4];
        uint32_t rupee_flags_bitfields;
        uint8_t small_keys;
        uint8_t dungeon_flags;
        uint8_t padding[2];
    };

    struct PlayerStatusA
    {
        uint16_t maxHealth;
        uint16_t currentHealth;
        uint16_t currentRupees;
        uint16_t maxLanternOil;
        uint16_t currentLanternOil;
        uint8_t unk10; //Possibly an unused Wii equip slot.
        libtp::data::item::Item selectItem[3];
        libtp::data::item::Item mixItem[3];
        uint8_t unk17; //Possibly an unused Wii combo equip slot.
        uint8_t unk18;
        libtp::data::item::Item equipment[6];
        Wallets currentWallet;
        uint8_t unk26;
        uint8_t unk27;
        uint8_t magicFlag;
        uint8_t unk29;
        uint8_t currentForm;
        uint8_t unk31[3];
        uint8_t padding[6];
    };

    struct PlayerStatusB
    {
        uint32_t unk0;
        uint32_t currentTime;
        uint8_t transform_level_flag; //0 is Sewers. 1 is Eldin. 2 is Lanayru. 3 is MDH
        uint8_t dark_clear_level_flag;
        uint16_t unk10;
        float skyAngle;
        uint16_t unk16;
        uint8_t unk18[3];
        uint8_t padding21[3];
    };

    struct HorsePlace
    {
        float epona_x_pos;
        float epona_y_pos;
        float epona_z_pos;
        uint16_t epona_angle;
        uint8_t epona_spawn_id;
        uint8_t epona_room_id;
    };

    struct PlayerReturnPlace
    {
        char link_current_stage[8];
        uint8_t link_spawn_point_id;
        uint8_t link_room_id;
        uint8_t unk10;
        uint8_t unk11;
    };

    struct PlayerFieldLastStayInfo
    {
        float player_last_x_pos;
        float player_last_y_pos;
        float player_last_z_pos;
        uint16_t player_last_angle;
        char player_last_stage[8];
        uint8_t player_last_spawn_id;
        uint8_t player_last_room_id;
        uint8_t unk24;
        uint8_t player_last_region;
        uint8_t unk26[2];
    };

    struct PlayerLastMarkInfo
    {
        float ooccoo_x_pos;
        float ooccoo_y_pos;
        float ooccoo_z_pos;
        uint16_t ooccoo_angle;
        char ooccoo_stage[8];
        uint8_t ooccoo_spawn_id;
        uint8_t ooccoo_room_id;
        char unk24;
        uint8_t unk25[3];
    };

    struct PlayerItem
    {
        libtp::data::item::Item item[24];
        ItemSlot item_slots[24];
    };

    struct PlayerGetItem
    {
        uint32_t pause_menu_bit_fields[4];
        uint8_t padding[16]; //I doubt this is correct as the flags for golden bugs are in here as well.
    };

    struct PlayerItemRecord
    {
        uint8_t bow_ammo;
        uint8_t bomb_bag_1_ammo;
        uint8_t bomb_bag_2_ammo;
        uint8_t bomb_bag_3_ammo;
        uint8_t unk4_ammo[4];
        uint8_t slingshot_ammo;
        uint8_t unk5_ammo;
    };

    struct PlayerItemMax
    {
        uint8_t max_arrow_capacity;
        uint8_t max_bomb_capacity;
        uint8_t max_water_bomb_capacity;
        uint8_t unk3;
        uint8_t unk4;
        uint8_t unk5;
        uint8_t max_bombling_capacity;
        uint8_t unk7;
    };

    struct PlayerCollect
    {
        uint8_t equipment[8];
        uint8_t unk8;
        uint8_t crystal;
        uint8_t mirror;
        uint8_t unk11;
        uint8_t poe_count;
        uint8_t padding13[3];
    };

    struct PlayerWolf
    {
        uint8_t unk0[3];
        uint8_t unk3;
    };

    struct LightDrop
    {
        uint8_t faron_tear_count;
        uint8_t eldin_tear_count;
        uint8_t lanayru_tear_count;
        uint8_t unk3;
        uint8_t light_drop_flag;
        uint8_t unk5[3];
    };

    struct LetterInfo
    {
        uint32_t letter_get_bitfields[2];
        uint32_t letter_read_bitfields[2];
        uint8_t  padding[64];
    };

    struct FishingInfo
    {
        uint16_t hyrule_bass_count;
        uint16_t hylian_loach_count;
        uint16_t hylian_pike_count;
        uint16_t ordon_catfish_count;
        uint16_t reekfish_count;
        uint16_t greengill_count;
        uint16_t unk12;
        uint16_t unk14;
        uint16_t unk16;
        uint16_t unk18;
        uint16_t unk20;
        uint16_t unk22;
        uint16_t unk24;
        uint16_t unk26;
        uint16_t unk28;
        uint16_t unk30;
        uint8_t largest_hyrule_bass_size;
        uint8_t largest_hylian_loach_size;
        uint8_t largest_hylian_pike_size;
        uint8_t largest_ordon_catfish_size;
        uint8_t largest_reekfish_size;
        uint8_t largest_greengill_size;
        uint8_t unk38;
        uint8_t unk39;
        uint8_t unk40;
        uint8_t unk41;
        uint8_t unk42;
        uint8_t unk43;
        uint8_t unk44;
        uint8_t unk45;
        uint8_t unk46;
        uint8_t unk47;
        uint8_t padding48[4];
    };

    struct PlayerInfo
    {
        uint8_t unk0[4];
        uint8_t unk4[4];
        uint8_t unk8[4];
        uint8_t unk12[4];
        uint8_t unk16[2];
        uint8_t unk18[2];
        uint8_t links_name[16];
        uint8_t unk36
        uint8_t eponas_name[16];
        uint8_t unk53;
        uint8_t unk54;
        uint8_t unk55[5];
        uint8_t padding60[4];
    };

    struct PlayerConfig
    {
        uint8_t unk0;
        uint8_t sound_mode; //0 is Mono. 1 is Stereo. 2 is Surround.
        uint8_t target_mode; //0 is Hold. 1 is Switch.
        uint8_t vibration_on_off; //0 is Off. 1 is On
        uint8_t motion_controls; //0 is On. 1 is Off. 
        uint8_t brightness_level; //1 is darkest. 6 is brightest.
        uint16_t unk6;
        uint8_t unk8;
        uint8_t unk9;
        uint8_t camera_aiming_options; // Default is 8. |80 is third person aiming. |8 inverts the vertical swiming axis. |4 inverts horizontal swimming axis. |2 inverts vertical camera axis. |1 inverts horizontal axis. 
        uint8_t unk11;
    };

    enum Wallets : uint8_t 
	{
        Wallet = 0,
        Big_Wallet = 1,
        Giant_Wallet = 2
    };

    enum ItemSlot : uint8_t 
    { // The 24 useable item slots in the game
        SLOT_0 = 0;
        SLOT_1 = 1;
        SLOT_2 = 2;
        SLOT_3 = 3;
        SLOT_4 = 4;
        SLOT_5 = 5;
        SLOT_6 = 6;
        SLOT_7 = 7;
        SLOT_8 = 8;
        SLOT_9 = 9;
        SLOT_10 = 10;
        SLOT_11 = 11;
        SLOT_12 = 12;
        SLOT_13 = 13;
        SLOT_14 = 14;
        SLOT_15 = 15;
        SLOT_16 = 16;
        SLOT_17 = 17;
        SLOT_18 = 18;
        SLOT_19 = 19;
        SLOT_20 = 20;
        SLOT_21 = 21;
        SLOT_22 = 22;
        SLOT_23 = 23; 
    };


    /**
     *	@brief Holds information about the current stage
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct CurrentStageVars
    {
        char currentStage[8];
        int16_t currentSpawnPoint;
        uint8_t unknown[4];
    } __attribute__((__packed__));

    /**
     *	@brief Holds information about the next stage
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct NextStageVars
    {
        char nextStage[8];
        uint8_t isVoidorWarp;
        uint8_t nextSpawnPoint;
        uint8_t nextRoom;
        uint8_t nextState;
        uint8_t unk1;
        uint8_t unk2;
        uint8_t triggerLoad;
        uint8_t fadeType;
    } __attribute__((__packed__));

    /**
     *	@brief Cutscene and event control system
     *
     *	@todo Fill missing vars.
     */
    struct EventSystem
    {
        uint8_t unk00[0x13];
        uint16_t immediateControl;
        uint8_t unk_00[0x4];
        uint8_t nextEventID;
        uint8_t unk1A[0xD1];
        uint8_t currentEventID;
        uint8_t unk_ec[0x14];
        libtp::tp::evt_control::csSkipFunction* onSkip;  // This will run when trying to skip; if null it's unskippable
        uint8_t unk_104[0xC];
        uint32_t fadeOnSkip;  // If > 0 the screen will fade when skipping
    } __attribute__((__packed__));

    /**
     *	@brief Holds data about Links position on the current map
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct LinkMapVars
    {
        uint8_t unk_0[0x4D0];
        float pos[3];
    } __attribute__((__packed__));

    /**
     *	@brief GameInfo Structure holding general and most crucial game
     *information
     *
     *	@todo Fill missing vars
     */
    struct GameInfo
    {
        ScratchPad scratchPad;         // 0 - 957
        uint8_t localAreaNodes[0x20];  // 958 - 977 holds flags about the current area
        uint8_t unk_978[0x450];        // 978 - DC7
        uint8_t respawnCutscene;       // DC8 - DC8
        uint8_t unkdc9[0xA];           // dc9 - dd2
        uint8_t respawnAnimation;      // dd3 - dd3
        uint8_t unkdd4[0x402C];        // dd4 - 4DFF
        char currentStage[8];          // 4E00 - 4E07
        uint8_t unk_4e08[6];           // 4E08 - 4E0D
        NextStageVars nextStageVars;   // 4E0E - 4E1b
        uint8_t unk_4e1c[0xAA];        // 4E19 - 4EC7
        EventSystem eventSystem;       // 4EC8 - 4FDE
        uint8_t unk_4fdd[0xDD0];       // 4FDD - 5DBF
        LinkMapVars* linkMapPtr;       // 5DA0 - 5DAB
        uint8_t unk_5dac[0x18060];
    } __attribute__((__packed__));
    static_assert(sizeof(ScratchPad) == 0x958);
    static_assert(sizeof(GameInfo) == 0x1DE10);

    extern "C"
    {
        extern GameInfo dComIfG_gameInfo;
    }
}  // namespace libtp::tp::d_com_inf_game