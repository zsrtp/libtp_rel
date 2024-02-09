/**	@file d_a_player.h
 *	@brief Contains functions and values that relate to the player and its interactions.
 *
 *	@author Lunar Soap
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
    };

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

    static_assert(sizeof(daPy_demo) == 0x24);
#ifndef PLATFORM_WII
    static_assert(sizeof(daPy_py) == 0x62C);
#else
    static_assert(sizeof(daPy_py) == 0x630);
#endif
    static_assert(sizeof(daPy_actorKeep) == 0x8);
    static_assert(sizeof(daPy_anmHeap) == 0x14);
    extern "C"
    {
        extern void* m_midnaActor;
    }
} // namespace libtp::tp::d_a_player
#endif