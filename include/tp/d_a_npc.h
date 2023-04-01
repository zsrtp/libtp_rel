/**	@file d_a_npc.h
 *	@brief Holds structs and functions that deal with NPCs and their actions.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_NPC_H
#define TP_D_A_NPC_H

#include <cstdint>

namespace libtp::tp::d_a_npc
{
    extern "C"
    {
        /**
         *  @brief Sets a permanent Event bit.
         *
         *  @param flag  The event flag to check as an indexed value.
         */
        void daNpcT_onEvtBit( int16_t flag );

        /**
         *  @brief Checks to see if a permanent Event bit is set.
         *
         *  @param flag  The event flag to check as an indexed value.
         *
         *  @return Bool returns True if the flag is set, otherwise returns False.
         */
        bool daNpcT_chkEvtBit( int16_t flag );

        /**
         *  @brief Checks to see if a temporary Event Bit is set.
         *
         *  @param flag  The event flag to check as an indexed value.
         *
         *  @return Bool returns True if the flag is set, otherwise returns False.
         */
        bool daNpcF_chkEvtBit( int16_t flag );
    }
}     // namespace libtp::tp::d_a_npc

#endif