/**	@file dvdfs.h
 *	@brief Holds functions that use the dvd files
 *
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef GC_WII_DVDFS_H
#define GC_WII_DVDFS_H

#include <cstdint>

namespace libtp::gc_wii::dvdfs
{
    extern "C"
    {
        int32_t DVDConvertPathToEntrynum( const char* fileName );
    }
}     // namespace libtp::gc_wii::dvdfs
#endif