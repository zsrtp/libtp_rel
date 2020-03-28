/**	@file d_stage.h
 *	@brief Stage related functions and fields
 *
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "../types.h"

namespace libtp::tp::d_stage
{
    extern "C"
    {
        /**
         *	@brief Used for treasure initialisation (not just chests)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        void setTresure(void* unk1);  // Yes they spell it Tresure
    }
}  // namespace libtp::tp::d_stage