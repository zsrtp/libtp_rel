/**	@file d_a_itembase.h
 *	@brief Holds structs and functions that deal with item actors.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_ITEMBASE_H
#define TP_D_A_ITEMBASE_H

#include <cstdint>

#include "tp/f_op_actor.h"

namespace libtp::tp::d_a_itembase
{
    struct ItemBase: libtp::tp::f_op_actor::fopAc_ac_c
    {
        /* 0x568 */ uint32_t padding00;
        /* 0x56C */ uint8_t mPhase[8];            // request_of_phase_process_class mPhase
        /* 0x574 */ void* mpModel;                // J3DModel* mpModel
        /* 0x578 */ void* mpBtkAnm;               // mDoExt_btkAnm* mpBtkAnm
        /* 0x57C */ void* mpBpkAnm;               // mDoExt_bpkAnm* mpBpkAnm
        /* 0x580 */ void* mpBrkAnm;               // mDoExt_brkAnm* mpBrkAnm
        /* 0x584 */ void* mpBckAnm;               // mDoExt_bckAnm* mpBckAnm
        /* 0x588 */ void* mpBtpAnm;               // mDoExt_btpAnm* mpBtpAnm
        /* 0x58C */ uint8_t mAcch[0x1D8];         // dBgS_ObjAcch mAcch
        /* 0x764 */ uint8_t mAcchCir[0x40];       // dBgS_AcchCir mAcchCir
        /* 0x7A4 */ uint8_t mColStatus[0x3C];     // dCcD_Stts mColStatus
        /* 0x7E0 */ uint8_t mCollider[0x13C];     // dCcD_Cyl mCollider
        /* 0x91C */ uint32_t field_0x91c;
        /* 0x920 */ uint32_t field_0x920;
        /* 0x924 */ int32_t field_0x924;
        /* 0x928 */ int16_t field_0x928;
        /* 0x92A */ uint8_t m_itemNo;
        /* 0x92B */ uint8_t field_0x92b;
    } __attribute__( ( __packed__ ) );

    extern "C"
    {
        /**
         *  @brief Allocates the heap for the model of a freestanding item.
         *
         *  @param actor A pointer to the Item actor being referenced.
         */
        void CheckFieldItemCreateHeap( libtp::tp::f_op_actor::fopAc_ac_c* actor );

        /**
         *  @brief Allocates the heap for the model of an item that Link holds in his hand
         *
         *  @param actor A pointer to the Item actor being referenced.
         */
        void CheckItemCreateHeap( libtp::tp::f_op_actor::fopAc_ac_c* actor );
    }
}     // namespace libtp::tp::d_a_itembase
#endif