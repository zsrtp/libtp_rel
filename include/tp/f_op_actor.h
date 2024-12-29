/**	@file f_op_actor.h
 *	@brief Defines structure of generic Actor.
 *
 *	@author Isaac
 *	@author Lunar Soap
 *	@bug
 */
#ifndef TP_F_OP_ACTOR_H
#define TP_F_OP_ACTOR_H

#include <cstdint>

#include "SSystem/SComponent/c_sxyz.h"
#include "SSystem/SComponent/c_xyz.h"

namespace libtp::tp::f_op_actor
{
    struct dEvt_info
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ uint16_t mCommand;
        /* 0x06 */ uint16_t mCondition;
        /* 0x08 */ int16_t mEventId;
        /* 0x0A */ uint8_t mMapToolId;
        /* 0x0B */ int8_t mIndex;
        /* 0x0C */ char* mArchiveName;
        /* 0x10 */ uint8_t field_0x10;
        /* 0x11 */ uint8_t padding11[3];
        /* 0x14 */ void* field_0x14;
    } __attribute__((__packed__));

    struct actor_place
    {
        cXyz mPosition;
        csXyz mAngle;
        int16_t mRoomNo;
    } __attribute__((__packed__));

    static_assert(sizeof(actor_place) == 0x14);

    struct actor_attention_types
    {
        /* 0x00 */ uint32_t mDistance1;
        /* 0x04 */ uint32_t mDistance2;
        /* 0x08 */ uint32_t mDistance3;
        /* 0x0C */ cXyz mPosition;
        /* 0x18 */ uint32_t mFlags;
    } __attribute__((__packed__));

    static_assert(sizeof(actor_attention_types) == 0x1C);

    class fopAc_ac_c
    {
       public:
        uint8_t unk_0x0[0xEC];
        // /* 0x0C0 */ int32_t mAcType;
        // /* 0x0C4 */ create_tag_class mAcTg;
        // /* 0x0D8 */ create_tag_class mDwTg;
        /* 0x0EC */ void* mSubMtd; // profile_method_class*
        /* 0x0F0 */ void* mHeap;   // JKRSolidHeap*
        /* 0x0F4 */ dEvt_info mEvtInfo;
        /* 0x10C */ uint8_t mTevStr[0x388]; // dKy_tevstr_c
        /* 0x494 */ int16_t mSetID;
        /* 0x496 */ uint8_t mGroup;
        /* 0x497 */ uint8_t mCullType;
        /* 0x498 */ uint8_t mDemoActorId;
        /* 0x499 */ int8_t mSubtype;
        /* 0x49A */ uint8_t mCarryType;
        /* 0x49B */ uint8_t padding49B;
        /* 0x49C */ uint32_t mStatus;
        /* 0x4A0 */ uint32_t mCondition;
        /* 0x4A4 */ uint32_t mParentPcId;
        /* 0x4A8 */ actor_place mOrig;
        /* 0x4BC */ actor_place mNext;
        // Notes on mCurrent:
        // - mPosition is position.
        // - mAngle.y is the speed angle of actor (direction on X-Z plane)
        /* 0x4D0 */ actor_place mCurrent;

        // Visible rotation of actor; x and z rotation axis is relative to actor
        /* 0x4E4 */ csXyz mCollisionRot;
        /* 0x4EA */ uint16_t padding4EA;
        /* 0x4EC */ cXyz mScale;
        /* 0x4F8 */ cXyz mSpeed;            // x,y,z velocities
        /* 0x504 */ uint8_t unk_0x504[0x4]; // MtxP mCullMtx;

        union
        {
            struct
            {
                /* 0x508 */ Vec mMin;
                /* 0x514 */ Vec mMax;
            } mBox;

            struct
            {
                /* 0x508 */ Vec mCenter;
                /* 0x514 */ float mRadius;
                /* 0x518 */ uint8_t padding518[0x8];
            } mSphere;
        } mCull;

        /* 0x520 */ float mCullSizeFar;
        /* 0x524 */ void* field_0x524;   // Possibly J3DModel*
        /* 0x528 */ void* unk_0x528;     //  dJntCol_c* mJntCol;
        /* 0x52C */ float mSpeedF;       // acceleration on X-Z plane (horizontal)
        /* 0x530 */ float mGravity;      //  acceleration on Y axis (vertical)
        /* 0x534 */ float mMaxFallSpeed; //  minimum y velocity (expect this to be negative)
        /* 0x538 */ cXyz mEyePos;
        /* 0x544 */ actor_attention_types mAttentionInfo;
        /* 0x560 */ int16_t field_0x560;
        /* 0x562 */ int16_t mHealth;
        /* 0x564 */ uint8_t field_0x564;
        /* 0x565 */ uint8_t field_0x565;
        /* 0x566 */ uint8_t field_0x566;
        /* 0x567 */ int8_t field_0x567;
    } __attribute__((__packed__));

    static_assert(sizeof(fopAc_ac_c) == 0x568);
    static_assert(sizeof(actor_place) == 0x14);
    static_assert(sizeof(actor_attention_types) == 0x1C);
    static_assert(sizeof(dEvt_info) == 0x18);
} // namespace libtp::tp::f_op_actor

#endif