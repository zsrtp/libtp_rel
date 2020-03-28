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
         *	@brief Initialises treasure (not just chests)
         *
         *	Takes a pointer to 8 bytes; first 4 are numEntries followed by a pointer to
         *the actual entry data of Type TRES
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        void setTresure(void* pEntryMetaData);  // Yes they spell it Tresure
    }
}  // namespace libtp::tp::d_stage