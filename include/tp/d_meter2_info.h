/**	@file d_meter2_info.h
 *	@brief Holds the pointers to button transparancy values (possibly more)
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */

#pragma once

#include "d_com_inf_game.h"

namespace libtp::tp::d_meter2_info
{
	extern "C"
	{
        /**
         *	@brief Gets a pointer to the transparancy of the Z button
         */
		extern void* wZButtonPtr;
	}
}