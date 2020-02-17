/**	@file tools.h
 *  @brief Various basic functions that can be useful
 *
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "types.h"

namespace libtp::tools
{
    s32 indexOf(void** arr, void* data, s32 chunkSize = sizeof(char));
}