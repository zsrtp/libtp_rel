/**	@file OSTime.h
 *	@brief Holds OSTime definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef GC_WII_OSTIME_H
#define GC_WII_OSTIME_H

#include <cstdint>

namespace libtp::gc_wii::os_time
{
    extern "C"
    {
        uint32_t OSGetTick();
    }
}     // namespace libtp::gc_wii::os_time
#endif