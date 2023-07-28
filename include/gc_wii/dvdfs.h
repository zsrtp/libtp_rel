/**	@file dvdfs.h
 *	@brief Holds function defintions for the DVD Filesystem
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef GC_WII_DVDFS_H
#define GC_WII_DVDFS_H

#include <cstdint>

namespace libtp::gc_wii::dvdfs
{
    extern "C"
    {
        int32_t DVDConvertPathToEntrynum(const char* fileName);
    }
} // namespace libtp::gc_wii::dvdfs
#endif