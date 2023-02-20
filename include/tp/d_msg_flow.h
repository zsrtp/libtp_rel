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
        int32_t query022( void* unk1, void* unk2, int32_t unk3 );
        int32_t query023( void* unk1, void* unk2, int32_t unk3 );
        int32_t query025( void* unk1, void* unk2, int32_t unk3 );
        int32_t query042( void* unk1, void* unk2, int32_t unk3 );
        int32_t query004( void* unk1, void* unk2, int32_t unk3 );
        int32_t query037( void* unk1, void* unk2, int32_t unk3 );
        int32_t query049( void* unk1, void* unk2, int32_t unk3 );
        int32_t event003( void* unk1,
                          void* param_1,
                          void* param_2 );     // Runs when you dontate to Charlo. Reduces the wallet by the donated amount.
        int32_t event041( void* unk1,
                          void* param_1,
                          void* param_2 );     // Runs when you donate to Charlo. Increases the amount donated.
        int32_t event035( void* unk1, void* param_1, void* param_2 );
        int32_t event000( void* messageFlow, void* nodeEvent, void* actrPtr );
        int32_t event017( void* messageFlow, void* nodeEvent, void* actrPtr );
    }
}     // namespace libtp::tp::d_msg_flow
#endif