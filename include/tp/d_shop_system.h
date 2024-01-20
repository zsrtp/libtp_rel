/**	@file d_shop_system.h
 *	@brief Holds data and definitions related to the structs and functions used by the shop system
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_SHOP_SYSTEM_H
#define TP_D_SHOP_SYSTEM_H

#include <cstdint>
#include "tp/f_op_actor.h"
#include "tp/d_a_npc.h"
#include "tp/d_shop_item_ctrl.h"

namespace libtp::tp::d_shop_system
{
    enum : uint8_t
    {
        /* 0x0 */ SEQ_WAIT,
        /* 0x1 */ SEQ_START,
        /* 0x2 */ SEQ_SELECT_WAIT,
        /* 0x3 */ SEQ_SELECT_START,
        /* 0x4 */ SEQ_SELECT,
        /* 0x5 */ SEQ_MOVING,
        /* 0x6 */ SEQ_DECIDE,
        /* 0x7 */ SEQ_CHOOSE,
        /* 0x8 */ SEQ_DECIDE_YES,
        /* 0x9 */ SEQ_DECIDE_NO,
        /* 0xA */ SEQ_FINISH,
    };

    struct ShopCam_action_c
    {
        /* 0x00 */ int field_0x0;
        /* 0x04 */ int field_0x4;
        /* 0x08 */ void* mCamActionFunc; // ShopCam_actionFunc
        /* 0x0C */ uint8_t field_0xc[0xC];
        /* 0x18 */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x18;
        /* 0x1C */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x1c;
        /* 0x20 */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x20;
        /* 0x24 */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x24;
        /* 0x28 */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x28;
        /* 0x2C */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x2c;
        /* 0x30 */ libtp::tp::f_op_actor::fopAc_ac_c* field_0x30;
        /* 0x34 */ float field_0x34;
        /* 0x38 */ cXyz field_0x38;
        /* 0x44 */ cXyz field_0x44;
        /* 0x50 */ float field_0x50;
        /* 0x54 */ cXyz field_0x54;
        /* 0x60 */ cXyz field_0x60;
        /* 0x6C */ float field_0x6c;
        /* 0x70 */ cXyz field_0x70;
        /* 0x7C */ cXyz field_0x7c;
        /* 0x88 */ cXyz field_0x88;
        /* 0x94 */ float field_0x94;
        /* 0x98 */ cXyz field_0x98;
        /* 0xA4 */ cXyz field_0xa4;
        /* 0xB0 */ cXyz field_0xb0;
        /* 0xBC */ float field_0xbc;
        /* 0xC0 */ float field_0xc0;
        /* 0xC4 */ float field_0xc4;
        /* 0xC8 */ float field_0xc8;
        /* 0xCC */ float field_0xcc;
        /* 0xD0 */ uint8_t field_0xd0[4];
        /* 0xD4 */ int16_t mSelectIdx;
        /* 0xD6 */ int16_t field_0xd6;
        /* 0xD8 */ int16_t field_0xd8;
        /* 0xDA */ uint8_t field_0xda;
        /* 0xDB */ uint8_t padding;
    } __attribute__((__packed__));

    struct dShopSystem: libtp::tp::d_a_npc::daNpcT
    {
        /* 0xE40 */ void* mpStick;      // STControl*
        /* 0xE44 */ void* mpDrawCursor; // dSelect_cursor_c*
        /* 0xE48 */ libtp::tp::d_shop_item_ctrl::dShopItemCtrl mItemCtrl;
        /* 0xE78 */ ShopCam_action_c mShopCamAction;
        /* 0xF54 */ uint32_t mEventParam;
        /* 0xF58 */ int field_0xf58;
        /* 0xF5C */ int field_0xf5c;
        /* 0xF60 */ int field_0xf60;
        /* 0xF64 */ int field_0xf64;
        /* 0xF68 */ int16_t field_0xf68;
        /* 0xF6A */ uint16_t mFlag;
        /* 0xF6C */ uint16_t field_0xf6c;
        /* 0xF6E */ uint8_t mCursorPos;
        /* 0xF6F */ uint8_t mLastCursorPos;
        /* 0xF70 */ uint8_t mSeq;
        /* 0xF71 */ uint8_t field_0xf71;
        /* 0xF72 */ uint8_t mWaitTimer;
        /* 0xF73 */ uint8_t mSoldOutFlag;
        /* 0xF74 */ uint8_t mSoldOutItemFlags;
        /* 0xF75 */ uint8_t mSpMode;
        /* 0xF76 */ uint8_t field_0xf76;
        /* 0xF77 */ uint8_t field_0xf77;
        /* 0xF78 */ uint8_t field_0xf78;
        /* 0xF79 */ uint8_t field_0xf79;
        /* 0xF7A */ uint8_t field_0xf7a;
        /* 0xF7B */ uint8_t padding;
    } __attribute__((__packed__));

    static_assert(sizeof(dShopSystem) == 0xF7C);
    static_assert(sizeof(ShopCam_action_c) == 0xDC);

    extern "C"
    {
        /**
         *	@brief Runs when the player selects the affirmative choice to buy an item from a shop
         *
         *  @param shopPtr The pointer to current shop system process
         *  @param actor The pointer to the current shop item actor
         *  @param flowPtr The pointer to the current Message Flow process.
         *  @returns 0 if complete, if currently processing a createItem process.
         */
        int seq_decide_yes(dShopSystem* shopPtr, libtp::tp::f_op_actor::fopAc_ac_c* actor, void* flowPtr);

        /**
         *	@brief Sets the flag of the shop item that is either currentlly being bought or being processed
         *
         *  @param shopPtr The pointer to current shop system process
         *  @param flag The flag to be set
         */
        void offFlag(dShopSystem* shopPtr, int32_t flag);

        /**
         *	@brief Initializes the process to remove the current shop actor's model and replace it with a sold out sign.
         *
         *  @param shopPtr The pointer to current shop system process
         */
        void setSoldOutItemHide(dShopSystem* shopPtr);

        /**
         *	@brief Sets the mSoldOutFlag of the shop system process to be the flag that is stored in the TGSPITM actor
         *
         *  @param shopPtr The pointer to current shop system process
         */
        void setSoldOutFlag(dShopSystem* shopPtr);

        /**
         *	@brief Sets the next event sequence to be performed in the shop system.
         *
         *  @param shopPtr The pointer to current shop system process
         *  @param seqId The sequence ID to be set.
         */
        void setSeq(dShopSystem* shopPtr, uint8_t seqId);
    }
} // namespace libtp::tp::d_shop_system
#endif