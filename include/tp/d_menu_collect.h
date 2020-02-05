/**	@file d_menu_collect.h
 *	@brief Symbols of the d_menu_collect field
 *
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "../types.h"

namespace libtp::tp::d_menu_collect
{
    extern "C"
    {
        /**
         *	@brief Sets the maximum number of rupees
         *
         *	Automatically gets the wallet size and fills it
         */
        void setWalletMaxNum();
    }
}  // namespace libtp::tp::d_menu_collect