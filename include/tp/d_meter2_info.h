/**	@file d_meter2_info.h
 *	@brief Holds the pointers to button transparancy values (possibly more)
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_METER2_INFO_H
#define TP_D_METER2_INFO_H

#include "tp/d_com_inf_game.h"

namespace libtp::tp::d_meter2_info
{
    struct G_Meter2_Info
    {
        uint8_t unk_0[0x10];
        tp::d_msg_object::StringDataTable* stringDataTable;
        uint8_t unk_14[0xE4];
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( G_Meter2_Info ) == 0xF8 );

    extern "C"
    {
        /**
         *	@brief Gets a pointer to the transparancy of the Z button
         */
        extern void* wZButtonPtr;
        extern G_Meter2_Info g_meter2_info;
    }
}     // namespace libtp::tp::d_meter2_info
#endif