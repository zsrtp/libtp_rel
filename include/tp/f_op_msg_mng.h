/**	@file f_op_msg_mng.h
 *	@brief Contains functions that handle message events
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_F_OP_MSG_MNG_H
#define TP_F_OP_MSG_MNG_H

#include <cstdint>

namespace libtp::tp::f_op_msg_mng
{
    extern "C"
    {
        int32_t fopMsgM_messageSet( uint32_t messageIndex, uint32_t unk2 );
        void* fopMsgM_SearchByID( int32_t i_msgID );
    }
}     // namespace libtp::tp::f_op_msg_mng
#endif