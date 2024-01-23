/**	@file d_a_npc.h
 *	@brief Holds structs and functions that deal with NPCs and their actions.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_NPC_H
#define TP_D_A_NPC_H

#include <cstdint>
#include "tp/f_op_actor.h"

namespace libtp::tp::d_a_npc
{
    struct daNpcT: libtp::tp::f_op_actor::fopAc_ac_c
    {
        /* 0x568 */ void* field_0x568; // daNpcT_faceMotionAnmData_c*
        /* 0x56C */ void* field_0x56c; // daNpcT_motionAnmData_c*
        /* 0x570 */ void* field_0x570; // daNpcT_evtData_c
        /* 0x574 */ char** field_0x574;
        /* 0x578 */ void* mMcaMorfAnm[2];       // mDoExt_McaMorfSO
        /* 0x580 */ uint8_t field_0x580[0x90];  // Z2Creature
        /* 0x610 */ uint8_t mBckAnm[0x1C];      // mDoExt_bckAnm
        /* 0x62C */ uint8_t mBtpAnm[0x18];      // mDoExt_btpAnm
        /* 0x644 */ uint8_t mBtkAnm[0x18];      // mDoExt_btkAnm
        /* 0x65C */ uint8_t mBrkAnm[0x18];      // mDoExt_brkAnm
        /* 0x674 */ uint8_t mBpkAnm[0x18];      // mDoExt_bpkAnm
        /* 0x68C */ uint8_t field_0x68c[0x1D8]; // dBgS_ObjAcch
        /* 0x864 */ uint8_t field_0x864[0x3C];  // dCcD_Stts
        /* 0x8A0 */ uint8_t field_0x8a0[0x40];  // dBgS_AcchCir
        /* 0x8E0 */ uint8_t field_0x8e0[0x50];  // request_of_phase_process_class
        /* 0x930 */ uint8_t field_0x930[0x3C];  // cBgS_GndChk
        /* 0x96C */ uint8_t field_0xa6c[8];
        /* 0x974 */ uint8_t mFlow[0x4C];       // dMsgFlow_c
        /* 0x9C0 */ uint8_t field_0x9c0[0x80]; // dPaPoT_c
        /* 0xA40 */ uint8_t field_0xa40[0x3C]; // dCcD_Stts
        /* 0xA7C */ uint8_t field_0xa7c[4];
        /* 0xA80 */ float field_0xa80;
        /* 0xA84 */ float field_0xa84;
        /* 0xA88 */ uint8_t field_0xa88;
        /* 0xA89 */ uint8_t field_0xa89;
        /* 0xA8A */ uint8_t padding_0xa8a[2];
        /* 0xA8C */ uint8_t field_0xa8c[0x54];  // dBgS_GndChk
        /* 0xAE0 */ uint8_t field_0xae0[0x70];  // dBgS_LinChk
        /* 0xB50 */ uint8_t field_0xb50[0x24];  // daNpcT_MotionSeqMngr_c
        /* 0xB74 */ uint8_t field_0xb74[0x24];  // daNpcT_MotionSeqMngr_c
        /* 0xB98 */ uint8_t field_0xb98[0x8];   // daNpcT_ActorMngr_c
        /* 0xBA0 */ uint8_t field_0xba0[0x8];   // daNpcT_ActorMngr_c
        /* 0xBA8 */ uint8_t field_0xba8[0x160]; // daNpcT_JntAnm_c
        /* 0xD08 */ uint8_t field_0xd08[0x1C];  // daNpcT_DmgStagger_c
        /* 0xD24 */ cXyz field_0xd24;
        /* 0xD30 */ cXyz field_0xd30;
        /* 0xD3C */ cXyz field_0xd3c;
        /* 0xD48 */ cXyz field_0xd48;
        /* 0xD54 */ cXyz field_0xd54;
        /* 0xD60 */ cXyz field_0xd60;
        /* 0xD6C */ cXyz field_0xd6c;
        /* 0xD78 */ csXyz field_0xd78;
        /* 0xD7E */ csXyz field_0xd7e;
        /* 0xD84 */ csXyz field_0xd84;
        /* 0xD8A */ csXyz field_0xd8a;
        /* 0xD90 */ uint32_t field_0xd90;
        /* 0xD94 */ uint32_t field_0xd94;
        /* 0xD98 */ uint32_t field_0xd98;
        /* 0xD9C */ void* mSubMtd; // profile_method_class*
        /* 0xDA0 */ uint8_t field_0xda0[8];
        /* 0xDA8 */ uint32_t field_0xda8;
        /* 0xDAC */ int32_t field_0xdac;
        /* 0xDB0 */ int32_t mCutType;
        /* 0xDB4 */ int32_t field_0xdb4;
        /* 0xDB8 */ int32_t field_0xdb8;
        /* 0xDBC */ int32_t mTimer;
        /* 0xDC0 */ int32_t field_0xdc0;
        /* 0xDC4 */ uint8_t field_0xdc4[4];
        /* 0xDC8 */ int16_t field_0xdc8;
        /* 0xDCA */ int16_t field_0xdca;
        /* 0xDCC */ uint8_t field_0xdcc[10];
        /* 0xDD4 */ int16_t field_0xdd4;
        /* 0xDD8 */ int16_t mStepNo;
        /* 0xDDA */ int16_t field_0xdda;
        /* 0xDDC */ float field_0xddc;
        /* 0xDE0 */ float field_0xde0;
        /* 0xDE4 */ float field_0xde4;
        /* 0xDE8 */ uint8_t field_0xde8[0xC];
        /* 0xDF4 */ float field_0xdf4;
        /* 0xDF8 */ uint8_t field_0xdf8[4];
        /* 0xDFC */ float field_0xdfc;
        /* 0xE00 */ cXyz field_0xe00;
        /* 0xE0C */ cXyz field_0xe0c;
        /* 0xE18 */ int16_t field_0xe18;
        /* 0xE1A */ int16_t field_0xe1a;
        /* 0xE1C */ int16_t field_0xe1c;
        /* 0xE1E */ uint16_t field_0xe1e;
        /* 0xE20 */ uint16_t field_0xe20;
        /* 0xE22 */ uint16_t field_0xe22;
        /* 0xE24 */ int8_t field_0xe24;
        /* 0xE25 */ uint8_t field_0xe25;
        /* 0xE26 */ uint8_t field_0xe26;
        /* 0xE27 */ uint8_t field_0xe27;
        /* 0xE28 */ uint8_t field_0xe28;
        /* 0xE29 */ uint8_t field_0xe29;
        /* 0xE2A */ uint8_t field_0xe2a;
        /* 0xE2B */ uint8_t field_0xe2b;
        /* 0xE2C */ uint8_t field_0xe2c;
        /* 0xE2D */ uint8_t field_0xe2d;
        /* 0xE2E */ uint8_t field_0xe2e[2];
        /* 0xE30 */ uint16_t field_0xe30;
        /* 0xE32 */ uint8_t field_0xe32;
        /* 0xE33 */ uint8_t field_0xe33;
        /* 0xE34 */ uint8_t field_0xe34;
        /* 0xE35 */ uint8_t field_0xe35;
        /* 0xE36 */ uint8_t field_0xe36;
        /* 0xE37 */ uint8_t field_0xe37;
        /* 0xE38 */ uint8_t field_0xe38;
        /* 0xE39 */ uint8_t padding_0xe39[3];
        /* 0xE3C */ uint32_t vtable;
    } __attribute__((__packed__));

    static_assert(sizeof(daNpcT) == 0xE40);

    extern "C"
    {
        /**
         *  @brief Sets a permanent Event bit.
         *
         *  @param flag  The event flag to check as an indexed value.
         */
        void daNpcT_onEvtBit(int16_t flag);

        /**
         *  @brief Checks to see if a permanent Event bit is set.
         *
         *  @param flag  The event flag to check as an indexed value.
         *
         *  @return Bool returns True if the flag is set, otherwise returns False.
         */
        bool daNpcT_chkEvtBit(int16_t flag);

        /**
         *  @brief Checks to see if a temporary Event Bit is set.
         *
         *  @param flag  The event flag to check as an indexed value.
         *
         *  @return Bool returns True if the flag is set, otherwise returns False.
         */
        bool daNpcF_chkEvtBit(int16_t flag);

        /**
         *	@brief Updates the current event that the referenced NPC is performing
         *
         *  @param npcPtr A pointer to the currently reference NPC
         */

        void evtChange(void* npcPtr);
    }
} // namespace libtp::tp::d_a_npc

#endif