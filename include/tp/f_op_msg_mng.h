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
        /**
         *	@brief Manually sets the next message in a message flow.
         *
         *	@param messageIndex The index of the message to be set.
         *  @param unk2 Unknown.
         *  @return BOOL returns True if successful, otherwise returns False
         */
        int32_t fopMsgM_messageSet( uint32_t messageIndex, uint32_t unk2 );

        /**
         *	@brief Searches through the current event node to find a pointer to the current message structure.
         *
         *	@param i_msgID The ID of the message to search for.
         *
         *  @return Returns a pointer to the message struct if successfull, otherwise returns a nullptr
         */
        void* fopMsgM_SearchByID( int32_t i_msgID );
    }
}     // namespace libtp::tp::f_op_msg_mng
#endif