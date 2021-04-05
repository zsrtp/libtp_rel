/**	@file control.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *  @author Zephiles
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#pragma once
#include <cstdint>

namespace libtp::tp::control
{
    extern "C"
    {
        bool render( void* TControl );
    }
}     // namespace libtp::tp::control