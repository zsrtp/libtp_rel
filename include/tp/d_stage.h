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
    /**
     *  @brief Holds information about the given dzx Chunktype
     *
     *  Example:
     *  TRES
     *  0001
     *  80401234 = 1 TRES Chunk at this address
     */
    struct dzxChunkTypeInfo
    {
        char tag[4];
        u32 numChunks;
        void* chunkDataPtr;
    };

    extern "C"
    {
        /**
         *	@brief Used for treasure initialisation (not just chests)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        void setTresure(void* unk1);  // Yes they spell it Tresure

        /**
         *  @brief Initialises TRES for a given room
         *
         *  @param chunkTypeInfo Pointer to the TRES chunk metadata
         */
        void roomTresureInit(void* unk1, dzxChunkTypeInfo* chunkTypeInfo, s32 unk3, void* unk4);
    }
}  // namespace libtp::tp::d_stage