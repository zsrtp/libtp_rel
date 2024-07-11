/**	@file d_a_player.h
 *	@brief Contains functions and values that relate to the player and its interactions.
 *
 *	@author Lunar Soap
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_D_A_PLAYER_H
#define TP_D_A_PLAYER_H
#include <cstdint>
#include "tp/f_op_actor.h"

namespace libtp::tp::d_a_player
{
    struct daPy_anmHeap
    {
        /* 0x00 */ uint16_t mIdx;
        /* 0x02 */ uint16_t mPriIdx;
        /* 0x04 */ uint16_t mArcNo;
        /* 0x06 */ uint16_t field_0x06;
        /* 0x08 */ uint32_t mBufferSize;
        /* 0x0C */ uint8_t* mBuffer;
        /* 0x10 */ void* mAnimeHeap; // JKRSolidHeap*
    } __attribute__((__packed__));

    struct daPy_actorKeep
    {
        /* 0x0 */ uint32_t mID;
        /* 0x4 */ libtp::tp::f_op_actor::fopAc_ac_c* mActor;
    } __attribute__((__packed__));

    struct daPy_demo
    {
        /* 0x00 */ uint16_t mDemoType;
        /* 0x02 */ int16_t mDemoMoveAngle;
        /* 0x04 */ int16_t mTimer;
        /* 0x06 */ int16_t mParam2;
        /* 0x08 */ int32_t mParam0;
        /* 0x0C */ int32_t mParam1;
        /* 0x10 */ uint32_t mDemoMode;
        /* 0x14 */ float mStick;
        /* 0x18 */ cXyz mDemoPos0;
    } __attribute__((__packed__));

    struct daPy_py: libtp::tp::f_op_actor::fopAc_ac_c
    {
        /* 0x0568 */ uint8_t mCutType;
        /* 0x0569 */ uint8_t mComboCutCount;
#ifdef PLATFORM_WII
        uint8_t unk_field0[4];  // might be part of fopAc_ac_c, fix later
#endif
        /* 0x056A */ uint8_t mSpecialMode; // maybe needs better name
        /* 0x056B */ uint8_t field_0x56b;
        /* 0x056C */ int16_t mDamageTimer;
        /* 0x056E */ uint16_t mSwordUpTimer;
        /* 0x0570 */ uint32_t mNoResetFlg0;
        /* 0x0574 */ uint32_t mNoResetFlg1;
        /* 0x0578 */ uint32_t mNoResetFlg2;
        /* 0x057C */ uint32_t mNoResetFlg3;
        /* 0x0580 */ uint32_t mResetFlg0;
        /* 0x0584 */ uint32_t mResetFlg1;
        /* 0x0588 */ uint32_t mEndResetFlg0;
        /* 0x058C */ uint32_t mEndResetFlg1;
        /* 0x0590 */ uint32_t mEndResetFlg2;
        /* 0x0594 */ float field_0x594;
        /* 0x0598 */ float field_0x598;
        /* 0x059C */ csXyz mBodyAngle;
        /* 0x05A4 */ cXyz mHeadTopPos;
        /* 0x05AE */ uint16_t padding5AE;
        /* 0x05B0 */ cXyz mItemPos;
        /* 0x05BC */ cXyz mSwordTopPos;
        /* 0x05C8 */ cXyz mLeftHandPos;
        /* 0x05D4 */ cXyz mRightHandPos;
        /* 0x05E0 */ cXyz mLeftFootPos;
        /* 0x05EC */ cXyz mRightFootPos;
        /* 0x05F8 */ uint8_t field_0x5f8[0xC];
        /* 0x0604 */ daPy_demo mDemo;
        /* 0x0628 */ void* vtable;
    } __attribute__((__packed__));

    enum daPy_FLG2 {
        FLG2_UNK_20000000 = 0x20000000,
        FLG2_UNK_10000000 = 0x10000000,
        FLG2_UNK_4080000 = 0x4080000,
        FLG2_UNK_2080000 = 0x2080000,
        FLG2_BOAR_SINGLE_BATTLE = 0x1800000,
        FLG2_UNK_8000000 = 0x8000000,
        FLG2_UNK_1000000 = 0x1000000,
        FLG2_UNK_800000 = 0x800000,
        FLG2_STATUS_WINDOW_DRAW = 0x400000,
        FLG2_UNK_280000 = 0x280000,
        FLG2_UNK_200000 = 0x200000,
        FLG2_UNK_100000 = 0x100000,
        FLG2_UNK_80000 = 0x80000,
        FLG2_UNK_40000 = 0x40000,
        FLG2_UNK_20000 = 0x20000,
        FLG2_UNK_10000 = 0x10000,
        FLG2_SCN_CHG_START = 0x8000,
        FLG2_UNK_4000 = 0x4000,
        FLG2_UNK_2000 = 0x2000,
        FLG2_UNK_1000 = 0x1000,
        FLG2_UNK_400 = 0x400,
        FLG2_UNK_200 = 0x200,
        FLG2_UNK_80 = 0x80,
        FLG2_UNK_40 = 0x40,
        FLG2_WOLF_ENEMY_LEFT_THROW = 0x20,
        FLG2_UNK_10 = 0x10,
        FLG2_UNK_8 = 8,
        FLG2_UNK_2 = 2,
        FLG2_UNK_1 = 1,

        FLG2_UNK_58 = FLG2_UNK_40 | FLG2_UNK_10 | FLG2_UNK_8,
    };

    enum daPy_FLG0 {
        FLG0_UNK_40000000 = 0x40000000,
        FLG0_EQUIP_HVY_BOOTS = 0x2000000,
        FLG0_PLAYER_NO_DRAW = 0x8000000,
        FLG0_UNK_10000000 = 0x10000000,
        FLG0_UNK_1000000 = 0x1000000,
        FLG0_UNDERWATER = 0x800000,
        FLG0_UNK_200000 = 0x200000,
        FLG0_UNK_100000 = 0x100000,
        FLG0_UNK_80000 = 0x80000,
        FLG0_UNK_40000 = 0x40000,
        FLG0_UNK_20000 = 0x20000,
        FLG0_UNK_10000 = 0x10000,
        FLG0_UNK_8000 = 0x8000,
        FLG0_UNK_4000 = 0x4000,
        FLG0_UNK_2000 = 0x2000,
        FLG0_MAGNE_BOOTS_ON = 0x1000,
        FLG0_PUSH_PULL_KEEP = 0x800,
        FLG0_UNK_400 = 0x400,
        FLG0_UNK_100 = 0x100,
        FLG0_UNK_80 = 0x80,
        FLG0_UNK_40 = 0x40,
        FLG0_UNK_20 = 0x20,
        FLG0_UNK_10 = 0x10,
        FLG0_UNK_8 = 0x8,
        FLG0_MIDNA_RIDE = 4,
        FLG0_UNK_2 = 2,

        FLG0_HVY_STATE = FLG0_UNK_40000000 | FLG0_EQUIP_HVY_BOOTS | FLG0_UNK_20000,
        FLG0_UNK_14000 = 0x14000,
        FLG0_UNK_10400 = 0x10400,
        FLG0_UNK_18 = FLG0_UNK_10 | FLG0_UNK_8,
    };

    enum daPy_RFLG0 {
        RFLG0_UNK_40000000 = 0x40000000,
        RFLG0_UNK_20000000 = 0x20000000,
        RFLG0_UNK_8000000 = 0x8000000,
        RFLG0_UNK_4000000 = 0x4000000,
        RFLG0_GRAB_PUT_START = 0x400000,
        RFLG0_UNK_20000 = 0x20000,
        RFLG0_UNK_10000 = 0x10000,
        RFLG0_UNK_8000 = 0x8000,
        RFLG0_UNK_4000 = 0x4000,
        RFLG0_FRONT_ROLL_CRASH = 0x2000,
        RFLG0_ENEMY_ATTN_LOCK = 0x1000,
        RFLG0_UNK_400 = 0x400,
        RFLG0_UNK_200 = 0x200,
        RFLG0_UNK_100 = 0x100,
        RFLG0_UNK_80 = 0x80,
        RFLG0_UNK_40 = 0x40,
        RFLG0_GRAB_UP_END = 0x20,
        RFLG0_UNK_10 = 0x10,
        RFLG0_UNK_8 = 0x8,
        RFLG0_UNK_2 = 0x2,
        RFLG0_UNK_1 = 0x1,
    };

    static_assert(sizeof(daPy_demo) == 0x24);
    static_assert(sizeof(daPy_actorKeep) == 0x8);
    static_assert(sizeof(daPy_anmHeap) == 0x14);
#ifndef PLATFORM_WII
    static_assert(sizeof(daPy_py) == 0x62C);
#else
    static_assert(sizeof(daPy_py) == 0x630);
#endif

    extern "C"
    {
        extern void* m_midnaActor;
        void offNoResetFlg2(daPy_py* linkActrPtr, daPy_FLG2);
        void offNoResetFlg0(daPy_py* linkActrPtr, daPy_FLG0);
        void onResetFlg0(daPy_py* linkActrPtr, daPy_RFLG0);
        uint32_t checkWolf(daPy_py* linkActrPtr);
        int32_t checkBombItem(int32_t id);
    }
} // namespace libtp::tp::d_a_player
#endif
