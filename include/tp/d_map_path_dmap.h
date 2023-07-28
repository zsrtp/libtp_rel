/**	@file d_map_path_dmap.h
 *	@brief Symbols of the d_map_path_dmap field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_D_MAP_PATH_DMAP_H
#define TP_D_MAP_PATH_DMAP_H

#include <cstdint>

namespace libtp::tp::d_map_path_dmap
{
    extern "C"
    {
        /**
         *	@brief Gets the current XYZ coordinates for Links current position
         *
         *	@param posOut The 3 floats which will hold the respective X, Y and Z
         *coordinate
         */
        void getMapPlayerPos(float posOut[3]);

        /**
         *	@brief If Link is loaded on the stage, get the Y angle
         *
         *	@return Int of Link's angle.
         */
        uint32_t getMapPlayerAngleY();
    }
} // namespace libtp::tp::d_map_path_dmap
#endif