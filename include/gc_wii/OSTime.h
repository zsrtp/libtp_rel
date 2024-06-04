/**	@file OSTime.h
 *	@brief Holds OSTime definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Lunar Soap
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef GC_WII_OSTIME_H
#define GC_WII_OSTIME_H

#include <cstdint>

typedef int64_t OSTime;

namespace libtp::gc_wii::os_time
{
    extern "C"
    {
        uint32_t OSGetTick();
        int64_t OSGetTime();
    }
} // namespace libtp::gc_wii::os_time
#endif
