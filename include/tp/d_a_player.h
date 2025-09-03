/**	@file d_a_player.h
 *	@brief Contains functions and values that relate to the player and its interactions.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_PLAYER_H
#define TP_D_A_PLAYER_H

#include "tp/f_op_actor.h"
#include "dolphin/gx/GXStruct.h"
#include "tp/J3DModel.h"
#include "tp/m_do_ext.h"
#include "tp/J3DShape.h"
#include "tp/d_msg_flow.h"
#include "dolphin/gx/GXStruct.h"
#include "SSystem/SComponent/c_phase.h"
#include <cstdint>

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
        uint8_t unk_field0[4]; // might be part of fopAc_ac_c, fix later
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

    struct daMidna_c: libtp::tp::f_op_actor::fopAc_ac_c
    {
        /* 0x568 */ libtp::tp::request_of_phase_process_class mPhase;
        /* 0x570 */ libtp::tp::J3DModel::J3DModel* mpModel;
        /* 0x574 */ libtp::tp::J3DModel::J3DModel* mpShadowModel;
        /* 0x578 */ void* mpMorf;         // mDoExt_McaMorfSO
        /* 0x57C */ uint8_t mMorfCB[0x8]; // daMidna_McaMorfCB1_c
        /* 0x584 */ libtp::tp::m_Do_ext::mDoExt_bckAnm mUpperBck;
        /* 0x5A0 */ libtp::tp::m_Do_ext::mDoExt_bckAnm mFaceBck;
        /* 0x5BC */ libtp::tp::J3DAnimation::J3DAnmTexPattern* mpFaceBtp;
        /* 0x5C0 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpFaceBtk;
        /* 0x5C4 */ uint8_t mInvModel[0x8];         // mDoExt_invisibleModel
        /* 0x5CC */ uint8_t mMaskInvModel[0x8];     // mDoExt_invisibleModel
        /* 0x5D4 */ uint8_t mHandsInvModel[0x8];    // mDoExt_invisibleModel
        /* 0x5DC */ uint8_t mHairhandInvModel[0x8]; // mDoExt_invisibleModel
        /* 0x5E4 */ uint8_t mBckHeap[0x3C];         // daPy_anmHeap_c[3]
        /* 0x620 */ uint8_t mBtpHeap[0x14];         // daPy_anmHeap_c
        /* 0x634 */ uint8_t mBtkHeap[0x14];         // daPy_anmHeap_c
        /* 0x648 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpMoyaBtk;
        /* 0x64C */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpMaskMoyaBtk;
        /* 0x650 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpHandsMoyaBtk;
        /* 0x654 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpHairhandMoyaBtk;
        /* 0x658 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpAppearBrk;
        /* 0x65C */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpMaskAppearBrk;
        /* 0x660 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpHairhandAppearBrk;
        /* 0x664 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpGokouAppearBrk;
        /* 0x668 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* field_0x668;
        /* 0x66C */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpDemoFCBlendBrk;
        /* 0x670 */ libtp::tp::J3DModel::J3DModel* mpMaskBmd;
        /* 0x674 */ libtp::tp::J3DModel::J3DModel* mpShadowMaskBmd;
        /* 0x678 */ libtp::tp::J3DModel::J3DModel* mpHandsBmd;
        /* 0x67C */ libtp::tp::J3DModel::J3DModel* mpShadowHandsBmd;
        /* 0x680 */ libtp::tp::J3DModel::J3DModel* mpHairhandBmd;
        /* 0x684 */ libtp::tp::J3DModel::J3DModel* mpShadowHairhandBmd;
        /* 0x688 */ libtp::tp::J3DModel::J3DModel* mpDemoBDTmpBmd;
        /* 0x68C */ libtp::tp::J3DModel::J3DModel* mpDemoBDMaskBmd;
        /* 0x690 */ libtp::tp::J3DModel::J3DModel* mpDemoBDHandsBmd;
        /* 0x694 */ libtp::tp::J3DModel::J3DModel* mpDemoBDHairhandBmd;
        /* 0x698 */ libtp::tp::J3DModel::J3DModel* mpGokouBmd;
        /* 0x69C */ libtp::tp::J3DShape::J3DShape* mpLeftHandShape;
        /* 0x6A0 */ libtp::tp::J3DShape::J3DShape* mpRightHandShape;
        /* 0x6A4 */ libtp::tp::J3DShape::J3DShape* mpShadowLeftHandShape;
        /* 0x6A8 */ libtp::tp::J3DShape::J3DShape* mpShadowRightHandShape;
        /* 0x6AC */ libtp::tp::J3DModel::J3DModel* mpDemoFCBlendBmd;
        /* 0x6B0 */ libtp::tp::J3DModel::J3DModel* mpDemoFCTongueBmd;
        /* 0x6B4 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpDemoFCTongueBtk;
        /* 0x6B8 */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoFCTmpBck;
        /* 0x6BC */ void* mpDemoFCTmpBls; // J3DDeformData*
        /* 0x6C0 */ libtp::tp::J3DAnimation::J3DAnmCluster* mpDemoFCTmpCluster;
        /* 0x6C4 */ void* mpDemoFCTmpBlk; // mDoExt_blkAnm*
        /* 0x6C8 */ libtp::tp::J3DModel::J3DModel* mpDemoHLTmpBmd;
        /* 0x6CC */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoHLTmpBck;
        /* 0x6D0 */ libtp::tp::J3DModel::J3DModel* mpDemoHRTmpBmd;
        /* 0x6D4 */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoHRTmpBck;
        /* 0x6D8 */ libtp::tp::J3DModel::J3DModel* mpDemoHDTmpBmd;
        /* 0x6DC */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoHDTmpBck;
        /* 0x6E0 */ GXColorS10 field_0x6e0;
        /* 0x6E8 */ GXColor field_0x6e8;
        /* 0x6EC */ GXColor field_0x6ec;
        /* 0x6F0 */ void* mpEyeMatAnm[2]; // daMidna_matAnm_c
        /* 0x6F8 */ void* mpHIO;          // daMidna_hio_c0
        /* 0x6FC */ uint8_t mSound[0x90]; // Z2Creature
        /* 0x78C */ libtp::tp::d_msg_flow::dMsgFlow mMsgFlow;
        /* 0x7D8 */ uint8_t mLinChk[0x70]; // dBgS_LinkLinChk
        /* 0x848 */ uint8_t mMotionNum;
        /* 0x849 */ uint8_t mFaceNum;
        /* 0x84A */ uint8_t field_0x84a;
        /* 0x84B */ uint8_t mFaceBckTimer;
        /* 0x84C */ uint8_t mEyeMoveTimer;
        /* 0x84D */ int8_t mReverb;
        /* 0x84E */ uint8_t field_0x84e;
        /* 0x84F */ uint8_t mDemoType;
        /* 0x850 */ uint8_t field_0x850;
        /* 0x851 */ uint8_t field_0x851;
        /* 0x852 */ uint8_t field_0x852[8];
        /* 0x85A */ int16_t field_0x85a;
        /* 0x85C */ int16_t mHairAngleZ[5];
        /* 0x866 */ int16_t mHairAngleY[5];
        /* 0x870 */ uint8_t field_0x870[2];
        /* 0x872 */ int16_t field_0x872;
        /* 0x874 */ int16_t mBackboneAngleZ;
        /* 0x876 */ int16_t field_0x876;
        /* 0x878 */ uint16_t mLeftHandShapeIdx;
        /* 0x87A */ uint16_t mRightHandShapeIdx;
        /* 0x87C */ int16_t mDemoAngle;
        /* 0x87E */ int16_t field_0x87e;
        /* 0x880 */ csXyz mNeckAngle;
        /* 0x886 */ uint8_t field_0x886[6];
        /* 0x88C */ int32_t mStaffID;
        /* 0x890 */ uint32_t mStateFlg0;
        /* 0x894 */ uint32_t mStateFlg1;
        /* 0x898 */ uint32_t mEndResetStateFlg0;
        /* 0x89C */ uint32_t mShadowKey;
        /* 0x8A0 */ uint32_t mParticleKey1;
        /* 0x8A4 */ uint32_t mParticleKey2;
        /* 0x8A8 */ uint32_t mThroughEffectKey[6];
        /* 0x8C0 */ uint32_t mDemoMode;
        /* 0x8C4 */ uint32_t mSoundID;
        /* 0x8C8 */ float mVoiceFrame;
        /* 0x8CC */ float mEyeMoveX;
        /* 0x8D0 */ float mEyeMoveY;
        /* 0x8D4 */ float field_0x8d4;
        /* 0x8D8 */ float mDemoSpeed;
        /* 0x8DC */ float field_0x8dc;
        /* 0x8E0 */ cXyz mHairPos[5];
        /* 0x91C */ cXyz mHairDir[5];
        /* 0x958 */ cXyz mHeadCenterPos;
        /* 0x964 */ cXyz mHairScale[5];
        /* 0x9A0 */ cXyz field_0x9a0;
        /* 0x9AC */ cXyz mTagWaitPos;
        /* 0x9B8 */ cXyz mDemoPos;
        /* 0x9C4 */ cXyz mForceNeckAimPos;
        /* 0x9D0 */ void* mpKago;        // daKago_c*
        /* 0x9D4 */ uint8_t mpFunc[0xC]; // daMidna_func
    } __attribute__((__packed__));

    static_assert(sizeof(daPy_demo) == 0x24);
    static_assert(sizeof(daPy_actorKeep) == 0x8);
    static_assert(sizeof(daPy_anmHeap) == 0x14);
#ifndef PLATFORM_WII
    static_assert(sizeof(daPy_py) == 0x62C);
#else
    static_assert(sizeof(daPy_py) == 0x630);
#endif

    static_assert(sizeof(daMidna_c) == 0x9E0);

    extern "C"
    {
        extern daMidna_c* m_midnaActor;
    }
} // namespace libtp::tp::d_a_player
#endif