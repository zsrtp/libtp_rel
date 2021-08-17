/**	@file control.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *  @author Zephiles
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_CONTROL_H
#define TP_CONTROL_H

#include <cstdint>

namespace libtp::tp::control
{
    extern "C"
    {
        bool render( void* TControl );
    }
}     // namespace libtp::tp::control
#endif