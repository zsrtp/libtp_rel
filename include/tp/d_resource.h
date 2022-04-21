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
    extern "C"
    {
        void* getResInfo( const char* arcName, void* objectInfo, int size );
    }
}     // namespace libtp::tp::d_resource
#endif