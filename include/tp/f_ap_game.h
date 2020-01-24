/**	@file f_ap_game.h
 *	@brief Holds symbols from the f_ap_game field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */

#pragma once

#include "../types.h"

namespace tp::f_ap_game
{
    extern "C"
    {
        /**
         *	@brief Runs once per frame
         */
        void fapGm_Execute();
    }
}  // namespace tp::f_ap_game