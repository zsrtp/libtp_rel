/**	@file d_menu_fmap2D.h
 *	@brief Symbols of the d_menu_fmap2D field
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_FMAP2D_H
#define TP_D_MENU_FMAP2D_H

#include <cstdint>
#include "tp/J2DPicture.h"
#include "tp/d_pane_class.h"

namespace libtp::tp::d_menu_fmap2D
{
    struct dMenu_Fmap2DBack_c
    {
        /* 0x0000 */ uint8_t unk_0x0[0xD18];
        /* 0x0D18 */ void* mpBackScreen; // J2DScreen*
        /* 0x0D1C */ void* mpBaseScreen; // J2DScreen*
        /* 0x0D20 */ void* mpBaseRoot;   // CPaneMgrAlphaMorf*
        /* 0x0D24 */ libtp::tp::d_pane_class::CPaneMgr* mpMapArea;
        /* 0x0D28 */ libtp::tp::d_pane_class::CPaneMgr* mpMapBlack;
        /* 0x0D2C */ libtp::tp::d_pane_class::CPaneMgr* mpPointParent;
        /* 0x0D30 */ libtp::tp::J2DPicture::J2DPicture* mpBackTex;
        /* 0x0D34 */ libtp::tp::J2DPicture::J2DPicture* mpAreaTex[8];
        /* 0x0D54 */ libtp::tp::J2DPicture::J2DPicture* mpSpotTexture;
        /* 0x0D58 */ void* mpPointScreen;     // J2DScreen*
        /* 0x0D5C */ void* mpMenuFmapMap;     // dMenu_FmapMap_c*
        /* 0x0D60 */ void* mpMeterHaihai;     // dMeterHaihai_c*
        /* 0x0D64 */ void* mpBaseAnm;         // J2DAnmTextureSRTKey*
        /* 0x0D68 */ void* mRegionTexData[8]; // RegionTexData*
        /* 0x0D88 */ void* mpStages;          // Stage_c*
        /* 0x0D8C */ float mRegionScrollMinX[8];
        /* 0x0DAC */ float mRegionScrollMinZ[8];
        /* 0x0DCC */ float mRegionScrollMaxX[8];
        /* 0x0DEC */ float mRegionScrollMaxZ[8];
        /* 0x0E0C */ float mRegionScrollMapMinX[8];
        /* 0x0E2C */ float mRegionScrollMapMinY[8];
        /* 0x0E4C */ float mRegionScrollMapMaxX[8];
        /* 0x0E6C */ float mRegionScrollMapMaxY[8];
        /* 0x0E8C */ float mRegionMinMapX[8];
        /* 0x0EAC */ float mRegionMinMapY[8];
        /* 0x0ECC */ float mRegionMapSizeX[8];
        /* 0x0EEC */ float mRegionMapSizeY[8];
        /* 0x0F0C */ float field_0xf0c[8];
        /* 0x0F2C */ float field_0xf2c[8];
        /* 0x0F4C */ float field_0xf4c[8];
        /* 0x0F6C */ float field_0xf6c[8];
        /* 0x0F8C */ float mRenderingPosX;
        /* 0x0F90 */ float mRenderingPosZ;
        /* 0x0F94 */ float mRenderingScale;
        /* 0x0F98 */ float field_0xf98;
        /* 0x0F9C */ float mZoom;
        /* 0x0FA0 */ float mMapZoomRate;
        /* 0x0FA4 */ float field_0xfa4;
        /* 0x0FA8 */ float field_0xfa8;
        /* 0x0FAC */ float mAnmFrame;
        /* 0x0FB0 */ float field_0xfb0;
        /* 0x0FB4 */ float field_0xfb4;
        /* 0x0FB8 */ float field_0xfb8;
        /* 0x0FBC */ float mTransX;
        /* 0x0FC0 */ float mTransZ;
        /* 0x0FC4 */ float mAlphaRate;
        /* 0x0FC8 */ float mStageTransX;
        /* 0x0FCC */ float mStageTransZ;
        /* 0x0FD0 */ float field_0xfd0;
        /* 0x0FD4 */ float field_0xfd4;
        /* 0x0FD8 */ float field_0xfd8;
        /* 0x0FDC */ float field_0xfdc;
        /* 0x0FE0 */ float mTexMinX;
        /* 0x0FE4 */ float mTexMinZ;
        /* 0x0FE8 */ float mTexMaxX;
        /* 0x0FEC */ float mTexMaxZ;
        /* 0x0FF0 */ float mAllMapScaleRate;
        /* 0x0FF4 */ float mWorldMinX;
        /* 0x0FF8 */ float mWorldMinZ;
        /* 0x0FFC */ float mWorldMaxX;
        /* 0x1000 */ float mWorldMaxZ;
        /* 0x1004 */ float mRegionOriginX[8];
        /* 0x1024 */ float mRegionOriginZ[8];
        /* 0x1044 */ float mStageOriginX[20];
        /* 0x1094 */ float mStageOriginZ[20];
        /* 0x10E4 */ float mStageOriginPathX[20];
        /* 0x1134 */ float mStageOriginPathZ[20];
        /* 0x1184 */ float field_0x1184;
        /* 0x1188 */ float field_0x1188;
        /* 0x118C */ float mArrowPos3DX;
        /* 0x1190 */ float mArrowPos3DZ;
        /* 0x1194 */ float mArrowPos2DX;
        /* 0x1198 */ float mArrowPos2DY;
        /* 0x119C */ float control_xpos;
        /* 0x11A0 */ float control_ypos;
        /* 0x11A4 */ float field_0x11a4;
        /* 0x11A8 */ float field_0x11a8;
        /* 0x11AC */ float field_0x11ac;
        /* 0x11B0 */ float field_0x11b0;
        /* 0x11B4 */ float field_0x11b4;
        /* 0x11B8 */ float field_0x11b8;
        /* 0x11BC */ float field_0x11bc;
        /* 0x11C0 */ float field_0x11c0;
        /* 0x11C4 */ float field_0x11c4;
        /* 0x11C8 */ float field_0x11c8;
        /* 0x11CC */ float field_0x11cc;
        /* 0x11D0 */ float field_0x11d0;
        /* 0x11D4 */ float mArrowAlpha;
        /* 0x11D8 */ float mSpotTextureFadeAlpha;
        /* 0x11DC */ float field_0x11dc;
        /* 0x11E0 */ float field_0x11e0;
        /* 0x11E4 */ float mBackAlpha;
        /* 0x11E8 */ float field_0x11e8;
        /* 0x11EC */ float field_0x11ec;
        /* 0x11F0 */ JUtility::TColor mSelectedRegionBlack;
        /* 0x11F4 */ JUtility::TColor mSelectedRegionWhite;
        /* 0x11F8 */ JUtility::TColor mUnselectedRegionBlack;
        /* 0x11FC */ JUtility::TColor mUnselectedRegionWhite;
        /* 0x1200 */ JUtility::TColor mUnreachedRegionBlack;
        /* 0x1204 */ JUtility::TColor mUnreachedRegionWhite;
        /* 0x1208 */ JUtility::TColor field_0x1208;
        /* 0x120C */ JUtility::TColor field_0x120c;
        /* 0x1210 */ float field_0x1210;
        /* 0x1214 */ float field_0x1214;
        /* 0x1218 */ int16_t field_0x1218;
        /* 0x121A */ int16_t field_0x121a;
        /* 0x121C */ uint8_t mRegionTextureReadNum[8];
        /* 0x1224 */ uint8_t mSpotNum;
        /* 0x1225 */ uint8_t mStageDataNum;
        /* 0x1226 */ uint8_t mSelectRegion;
        /* 0x1227 */ uint8_t mRegionCursor;
        /* 0x1228 */ uint8_t field_0x1228;
        /* 0x1229 */ uint8_t mSpotCursor;
        /* 0x122A */ uint8_t field_0x122a;
        /* 0x122B */ uint8_t field_0x122b;
        /* 0x122C */ uint8_t mRegionFlag;
        /* 0x122D */ uint8_t field_0x122d;
        /* 0x122E */ bool field_0x122e;
        /* 0x122F */ bool mAllPathShowFlag;
        /* 0x1230 */ uint8_t field_0x1230[8];
        /* 0x1238 */ uint8_t field_0x1238;
        /* 0x1239 */ bool mMapDrawFlag;
        /* 0x123A */ bool mArrowDrawFlag;
        /* 0x123B */ uint8_t field_0x123b;
        /* 0x123C */ void* mpFmapMap;    // dMenu_FmapMap_c*
        /* 0x1240 */ void* mpRegionData; // dMenu_Fmap_region_data_c*
        /* 0x1244 */ int32_t field_0x1244;
    } __attribute__((__packed__));

    static_assert(sizeof(dMenu_Fmap2DBack_c) == 0x1248);

    extern "C"
    {
        /**
         *  @brief Checks whether or not the map background of a region should be rendered.
         *
         *  @param fmap2DBackPtr A pointer to a `dMenu_Fmap2DBack_c`.
         *  @param i_region ID of region (1 for Ordona, 2 for Faron, etc.)
         *
         *  @return int32_t Returns 1 if should show, else returns 0.
         */
        int32_t isShowRegion(dMenu_Fmap2DBack_c* fmap2DBackPtr, int32_t i_region);

        /**
         *	@brief Checks to see if the player is trying to map warp.
         *
         *	@param fmap2DTopPtr A pointer to a `dMenu_Fmap2DTop_c`.
         *
         *  @return Bool returns True if the player is trying to warp, otherwise returns False.
         */
        bool checkPlayerWarpAccept(void* fmap2DTopPtr);
    }
} // namespace libtp::tp::d_menu_fmap2D
#endif