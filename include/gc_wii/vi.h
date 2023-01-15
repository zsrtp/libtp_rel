/**	@file vi.h
 *	@brief Holds vi definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef GC_VI_H
#define GC_VI_H

#include <cstdint>

namespace libtp::gc_wii::vi
{
    extern "C"
    {
        void VISetNextFrameBuffer( void* fb );
    }
}     // namespace libtp::gc_wii::vi
#endif