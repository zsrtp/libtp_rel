/**	@file d_menu_ring.h
 *	@brief Contains functions that handle message events
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_RING_H
#define TP_D_MENU_RING_H

#include <cstdint>

namespace libtp::tp::d_menu_ring
{
    extern "C"
    {
        void _create( void* dMenuRing );
        void _delete( void* dMenuRing );
    }
}     // namespace libtp::tp::d_menu_ring
#endif