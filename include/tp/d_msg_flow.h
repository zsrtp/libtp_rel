/**	@file d_msg_flow.h
 *	@brief Contains functions that check multiple flags during conversations
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MSG_FLOW_H
#define TP_D_MSG_FLOW_H

#include <cstdint>

namespace libtp::tp::d_msg_flow
{
    extern "C"
    {
        bool query022( void* unk1, void* unk2, int32_t unk3 );
        bool query023( void* unk1, void* unk2, int32_t unk3 );
        bool query025( void* unk1, void* unk2, int32_t unk3 );
        bool query042( void* unk1, void* unk2, int32_t unk3 );
        int query004( void* unk1, void* unk2, int32_t unk3 );
        int event003( void* unk1,
                      void* param_1,
                      void* param_2 );     // Runs when you dontate to Charlo. Reduces the wallet by the donated amount.
        int event041( void* unk1,
                      void* param_1,
                      void* param_2 );     // Runs when you donate to Charlo. Increases the amount donated.
        void event035( void* unk1, void* param_1, void* param_2 );
        bool chkEvtBit( uint32_t flag );
        bool chkEvtBitF( uint32_t flag );
        uint32_t event000( void* messageFlow, void* nodeEvent, void* actrPtr );
    }
}     // namespace libtp::tp::d_msg_flow
#endif