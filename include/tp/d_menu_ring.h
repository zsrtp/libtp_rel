/**	@file d_menu_ring.h
 *	@brief Contains functions that handle events related to the item wheel.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_RING_H
#define TP_D_MENU_RING_H

#include <cstdint>
#include "tp/d_com_inf_game.h"
#include "tp/J2DPicture.h"
#include "tp/d_pane_class.h"
#include "tp/d_pane_class_alpha.h"
#include "tp/J2DTextBox.h"
#include "tp/JUTTexture.h"

namespace libtp::tp::d_menu_ring
{
    struct dMenu_Ring_c
    {
        enum dMenu_Ring_Status
        {
            /* 0 */ STATUS_WAIT,
            /* 1 */ STATUS_MOVE,
            /* 2 */ STATUS_EXPLAIN,
            /* 3 */ STATUS_EXPLAIN_FORCE,
        };
        /* 0x000 */ uint8_t dDlst_base_c[0x4];
        /* 0x004 */ void* mpHeap;       // JKRExpHeap*
        /* 0x008 */ void* mpStick;      // STControl*
        /* 0x00C */ void* mpCStick;     // CSTControl*
        /* 0x010 */ void* mpDrawCursor; // dSelect_cursor_c*
        /* 0x014 */ void* mpString;     // dMsgString_c*
        /* 0x018 */ libtp::tp::d_pane_class_alpha::CPaneMgrAlpha* mpMessageParent;
        /* 0x01C */ libtp::tp::d_pane_class_alpha::CPaneMgrAlpha* mpCenterParent;
        /* 0x020 */ libtp::tp::d_pane_class_alpha::CPaneMgrAlpha* mpSpotParent;
        /* 0x024 */ libtp::tp::d_pane_class::CPaneMgr* mpTextParent[10];
        /* 0x04C */ libtp::tp::d_pane_class::CPaneMgr* mpNameParent;
        /* 0x050 */ libtp::tp::d_pane_class::CPaneMgr* mpCircle;
        /* 0x054 */ void* mpKanteraMeter; // dKantera_icon_c*
        /* 0x058 */ void* mpScreen;       // J2DScreen *
        /* 0x05C */ void* mpSpotScreen;   // J2DScreen*
        /* 0x060 */ uint8_t field_0x060[0x04];
        /* 0x064 */ void* mpCenterScreen; // J2DScreen*
        /* 0x068 */ libtp::tp::J2DPicture::J2DPicture* mpSelectItemTex[4][3];
        /* 0x098 */ libtp::tp::J2DPicture::J2DPicture* mpItemTex[MAX_ITEM_SLOTS][3];
        /* 0x1B8 */ libtp::tp::J2DPicture::J2DPicture* mpBlackTex;
        /* 0x1BC */ libtp::tp::J2DPicture::J2DPicture* mpItemNumTex[3];     // Displays digits on ammo-based items. Each index
                                                                            // represents one drawn digit
        /* 0x1C8 */ libtp::tp::J2DTextBox::J2DTextBox* mpComboOffString[5]; // Displays "Combo Off" combined bow is equipped
                                                                            // and cursor is on combinable item
        /* 0x1DC */ libtp::tp::J2DTextBox::J2DTextBox* mpBowArrowComboString[5]; // Displays "Bow & Arrow Combo" if bow is
                                                                                 // equipped and cursor is on combinable item
        /* 0x1F0 */ libtp::tp::JUTTexture::ResTIMG* mpSelectItemTexBuf[4][3][2];
        /* 0x250 */ libtp::tp::JUTTexture::ResTIMG* mpItemBuf[MAX_ITEM_SLOTS][3];
        /* 0x370 */ void* mpItemExplain;         // dMenu_ItemExplain_c*
        /* 0x374 */ void* mpResData[3];          // Contains screen data from .blo files which control e.g. the
                                                 // appearance of specific sprites and where they are on the screen
        /* 0x380 */ cXyz mDirectSelectCursorPos; // Positions the cursor with it's X and Z coordinates
                                                 // when Direct Select is active
        /* 0x38C */ float mItemSlotPosX[MAX_ITEM_SLOTS];
        /* 0x3EC */ float mItemSlotPosY[MAX_ITEM_SLOTS];
        /* 0x44C */ float mItemSlotParam1[MAX_ITEM_SLOTS];
        /* 0x4AC */ float mItemSlotParam2[MAX_ITEM_SLOTS];
        /* 0x50C */ float mRingRadiusH;
        /* 0x510 */ float mRingRadiusV;
        /* 0x514 */ float mAlphaRate; // Responsible for multiple things but especially for the
                                      // background becoming darker in a specific velocity when opening
        /* 0x518 */ float field_0x518[4];
        /* 0x528 */ float field_0x528[4];
        /* 0x538 */ float field_0x538[4];
        /* 0x548 */ float field_0x548[4];
        /* 0x558 */ float field_0x558[4];
        /* 0x568 */ float mCenterPosX;          // Controls the position in the x-axis of the whole item wheel
                                                // and moves it when opening or closing.
        /* 0x56C */ float mCenterPosY;          // Controls the position in the y-axis of the whole item wheel
                                                // and moves it when opening or closing.
        /* 0x570 */ float mPikariFlashingSpeed; // Controls the flashing speed of the combine icon (Bow &
                                                // Arrow Combo)
        /* 0x574 */ float field_0x574[3];
        /* 0x580 */ float field_0x580[3];
        /* 0x58C */ float mRingItemNamePosX;
        /* 0x590 */ float mRingItemNamePosY;
        /* 0x594 */ float mRingItemNameScale;
        /* 0x598 */ float mRingGuidePosX[10];
        /* 0x5C0 */ float mRingGuidePosY[10];
        /* 0x5E8 */ float mRingGuideScale[10];
        /* 0x610 */ float mRingCursorScale;
        /* 0x614 */ float mRingPosX;
        /* 0x618 */ float mRingPosY;
        /* 0x61C */ float mRingScaleH;
        /* 0x620 */ float mRingScaleV;
        /* 0x624 */ float mRingAlpha;     // the alpha depends on if the player is a wolf or a human
        /* 0x628 */ uint32_t field_0x628; // unused, not even initialized
        /* 0x62C */ uint32_t mPlayerIsWolf;
        /* 0x630 */ uint32_t mNameStringID;
        /* 0x634 */ int32_t field_0x634;
        /* 0x638 */ int16_t mOpenCloseFrames;
        /* 0x63A */ int16_t field_0x63a; // just gets set to zero in some functions. Unused
        /* 0x63C */ int16_t field_0x63c; // unused
        /* 0x63E */ int16_t field_0x63e[MAX_ITEM_SLOTS];
        /* 0x66E */ int16_t field_0x66e;
        /* 0x670 */ int16_t field_0x670;
        /* 0x672 */ int16_t mWaitFrames;
        /* 0x674 */ int16_t field_0x674[4];
        /* 0x67C */ uint16_t field_0x67c;
        /* 0x67E */ int16_t field_0x67e;
        /* 0x680 */ int16_t mCursorSpeed;
        /* 0x682 */ int16_t field_0x682;
        /* 0x684 */ int16_t field_0x684;
        /* 0x686 */ int16_t field_0x686[4];
        /* 0x68E */ int16_t field_0x68e;
        /* 0x690 */ uint8_t mItemSlots[MAX_ITEM_SLOTS];
        /* 0x6A8 */ uint8_t mCurrentSlot;
        /* 0x6A9 */ uint8_t field_0x6a9; // unused
        /* 0x6AA */ uint8_t mXButtonSlot;
        /* 0x6AB */ uint8_t mYButtonSlot;
        /* 0x6AC */ uint8_t field_0x6ac;
        /* 0x6AD */ uint8_t field_0x6ad;
        /* 0x6AE */ uint8_t mItemsTotal;          // Contains the amount of items which are actually obtained and in
                                                  // the item wheel
        /* 0x6AF */ uint8_t mTotalItemTexToAlloc; // Similiar to mItemsTotal but used to allocate and setup
                                                  // the item textures based on obtained items
        /* 0x6B0 */ uint8_t mStatus;
        /* 0x6B1 */ uint8_t mOldStatus;
        /* 0x6B2 */ uint8_t field_0x6b2; // used to set status but always zero
        /* 0x6B3 */ uint8_t field_0x6b3; // ends up being useless since checkCombineComb and setCombineBomb
                                         // are empty functions at least in GCN
        /* 0x6B4 */ uint8_t field_0x6b4[4];
        /* 0x6B8 */ uint8_t field_0x6b8[4];
        /* 0x6BC */ uint8_t mRingOrigin; // The value decides the origin the item wheel comes from before
                                         // it's in the center of the screen
        /* 0x6BD */ uint8_t mDrawFlag;
        /* 0x6BE */ uint8_t field_0x6be[4];
        /* 0x6C2 */ uint8_t field_0x6c2;
        /* 0x6C3 */ uint8_t field_0x6c3; // unused
        /* 0x6C4 */ uint8_t field_0x6c4; // only gets set to current slot when item explain gets opened
        /* 0x6C5 */ uint8_t field_0x6c5; // unused
        /* 0x6C6 */ uint8_t field_0x6c6; // unused
        /* 0x6C7 */ uint8_t field_0x6c7[4];
        /* 0x6CB */ uint8_t field_0x6cb;
        /* 0x6CC */ uint8_t mDoStatus;
        /* 0x6CD */ uint8_t field_0x6cd;
        /* 0x6CE */ bool mDirectSelectActive;
        /* 0x6CF */ uint8_t field_0x6cf;
        /* 0x6D0 */ uint8_t field_0x6d0;
        /* 0x6D1 */ uint8_t field_0x6d1;
        /* 0x6D2 */ uint8_t field_0x6d2;
        /* 0x6D3 */ uint8_t field_0x6d3;
    } __attribute__((__packed__));

    static_assert(sizeof(dMenu_Ring_c) == 0x6D4);
    extern "C"
    {
        /**
         *	@brief Creates the resources needed for the Item Wheel.
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         */
        void dMenuRing__create(dMenu_Ring_c* dMenuRing);

        /**
         *	@brief Removes the resources needed for the Item Wheel in preparation for destruction.
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         */
        void dMenuRing__delete(dMenu_Ring_c* dMenuRing);

        /**
         *	@brief Draws the Item Wheel on the screen.
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         */
        void dMenuRing__draw(dMenu_Ring_c* dMenuRing);

        /**
         *  @brief Constructor for the item wheel class
         *
         *  @param dMenuRing A pointer to the item wheel resources.
         *  @param param_1 a pointer to the current JKRExpHeap
         *  @param param_2 unk
         *  @param param_3 unk
         *  @param param_4 unk
         */
        void* dMenuRing_ct(dMenu_Ring_c* dMenuRing, void* param_1, void* param_2, void* param_3, uint8_t param_4);

        /**
         *	@brief Returns the current ammo count for the specified item slot
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         *  @param slotNo The slot number of the item to be checked.
         */
        uint8_t getItemNum(dMenu_Ring_c* dMenuRing, uint8_t slotNo);

        /**
         *	@brief Returns the current ammo count for the specified item slot
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         *  @param slotNo The slot number of the item to be checked.
         */
        uint8_t getItemMaxNum(dMenu_Ring_c* dMenuRing, uint8_t slotNo);
    }
} // namespace libtp::tp::d_menu_ring
#endif