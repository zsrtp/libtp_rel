/**	@file d_resource.h
 *	@brief Contains functions for handling the loading of various archives and resources
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_RESOURCE_H
#define TP_D_RESOURCE_H

#include <cstdint>

namespace libtp::tp::d_resource
{
    struct dRes_info_c
    {
        /* 0x00 */ char mArchiveName[11];
        /* 0x0C */ uint16_t mCount;
        /* 0x0E */ uint8_t padding[2];
        /* 0x10 */ void* mDMCommand;     // mDoDvdThd_mountArchive_c*
        /* 0x14 */ void* mArchive;       // JKRArchive*
        /* 0x18 */ void* heap;           // JKRHeap*
        /* 0x1C */ void* mDataHeap;      // JKRSolidHeap*
        /* 0x20 */ void** mRes;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( dRes_info_c ) == 0x24 );

    extern "C"
    {
        void* getResInfo( const char* arcName, dRes_info_c* objectInfo, int size );
    }
}     // namespace libtp::tp::d_resource
#endif