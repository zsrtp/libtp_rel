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
    }
}     // namespace libtp::tp::d_msg_flow
#endif