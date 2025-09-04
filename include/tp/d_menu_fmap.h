/**	@file d_menu_fmap.h
 *	@brief Symbols of the d_menu_fmap field
 *
 *	@author Isaac
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_FMAP_H
#define TP_D_MENU_FMAP_H

#include "tp/d_msg_flow.h"
#include "tp/JKRArchive.h"
#include "tp/m_Do_dvd_thread.h"
#include "tp/d_menu_fmap2D.h"

namespace libtp::tp::d_menu_fmap
{
    struct dMenu_Fmap
    {
        /* 0x000 */ void* vtable;
        /* 0x004 */ void* mpHeap;     // JKRExpHeap*
        /* 0x008 */ void* mpTalkHeap; // JKRExpHeap*
        /* 0x00C */ void* mpStick;    // STControl*
        /* 0x010 */ void* mpCStick;   // CSTControl*
        /* 0x014 */ libtp::tp::d_menu_fmap2D::dMenu_Fmap2DBack_c* mpDraw2DBack;
        /* 0x018 */ void* mpDraw2DTop; // dMenu_Fmap2DTop_c*
        /* 0x01C */ libtp::tp::m_Do_dvd_thread::mDoDvdThd_mountArchive_c* mpMountArchive;
        /* 0x020 */ void* mpWorldData;     // dMenu_Fmap_world_data_c*
        /* 0x024 */ void* mpRegionData[8]; // dMenu_Fmap_region_data_c*
        /* 0x044 */ void* mpStageData[8];  // dMenu_Fmap_stage_data_c*
        /* 0x064 */ void* mpMapArchive;    // JKRAramArchive*
        /* 0x068 */ libtp::tp::JKRArchive::JKRArchive* mpResArchive;
        /* 0x06C */ void* mpRoomData[8];     // dMenuMapCommon_c::RoomData_c*
        /* 0x08C */ void* mpFieldDat;        // dMenu_Fmap_field_data_c*
        /* 0x090 */ void* mpPortalDat;       // dMenu_Fmap_portal_data_c*
        /* 0x094 */ void* mRegionTexture[8]; // ResTIMG*
        /* 0x0B4 */ int32_t field_0xb4;
        /* 0x0B8 */ void* mpMenuFmapMap; // dMenu_FmapMap_c*
        /* 0x0BC */ void* mpFmapMapRes;
        /* 0x0C0 */ uint8_t* mFlashRooms;
        /* 0x0C4 */ libtp::tp::d_msg_flow::dMsgFlow mMsgFlow;
        /* 0x110 */ cXyz mPlayerPos;
        /* 0x11C */ float mTransX;
        /* 0x120 */ float mTransY;
        /* 0x124 */ float mAlphaRatio;
        /* 0x128 */ float field_0x128[8];
        /* 0x148 */ float field_0x148[8];
        /* 0x168 */ float field_0x168[8];
        /* 0x188 */ float field_0x188[8];
        /* 0x1A8 */ float mSpotTextureFadeAlpha;
        /* 0x1AC */ float mRegionOffsetX[8];
        /* 0x1CC */ float mRegionOffsetZ[8];
        /* 0x1EC */ float field_0x1ec;
        /* 0x1F0 */ float mOldStageTransX;
        /* 0x1F4 */ float mOldStageTransZ;
        /* 0x1F8 */ uint32_t mRoomDataBits[2];
        /* 0x200 */ uint32_t field_0x200;
        /* 0x204 */ int32_t mStageCursor;
        /* 0x208 */ int32_t mRoomCursor;
        /* 0x20C */ int32_t mStayStageNo;
        /* 0x210 */ int16_t field_0x210;
        /* 0x212 */ int16_t mDisplayFrame;
        /* 0x214 */ int16_t mZoomLevel;
        /* 0x216 */ uint16_t mAllTitleName;
        /* 0x218 */ uint16_t mTitleName[8];
        /* 0x228 */ uint16_t mAreaName[20];
        /* 0x250 */ char mMarkedStageName[8];
        /* 0x258 */ char mTmpStageName[8];
        /* 0x260 */ char mStageName[20][8];
        /* 0x300 */ uint8_t mProcess;
        /* 0x301 */ uint8_t mPrevProcess;
        /* 0x302 */ uint8_t mPrevProcessAlt;
        /* 0x303 */ uint8_t mDataNumMax;
        /* 0x304 */ uint8_t mPanDirection;
        /* 0x305 */ bool field_0x305;
        /* 0x306 */ uint8_t mSpotNum;
        /* 0x307 */ bool mIsWarpMap;
        /* 0x308 */ uint8_t mPortalNo;
        /* 0x309 */ bool mErrorSound;
        /* 0x30A */ uint8_t mStartStageNo;
        /* 0x30B */ bool field_0x30b;
        /* 0x30C */ uint8_t mOldRegionCursor;
        /* 0x30D */ uint8_t mOldStageCursor;
        /* 0x30E */ uint8_t mFlashRoomCount;
        /* 0x30F */ uint8_t field_0x30f;
        /* 0x310 */ uint8_t field_0x310;
        /* 0x311 */ uint8_t mRegionNo;
        /* 0x312 */ bool mResetAreaName;
        /* 0x313 */ bool mAreaNameSet;
    } __attribute__((__packed__));

    extern "C"
    {
        /**
         *  @brief Handles execution of map while zoomed in on a region with portals hidden.
         *
         *  @param mapPtr A pointer to the dMenu_Fmap.
         */
        void region_map_proc(dMenu_Fmap* mapPtr);

        /**
         *  @brief Handles execution of map while zoomed in twice such that you can pan.
         *
         *  @param mapPtr A pointer to the dMenu_Fmap.
         */
        void spot_map_proc(dMenu_Fmap* mapPtr);
    }
} // namespace libtp::tp::d_menu_fmap
#endif