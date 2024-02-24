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

namespace libtp::gc_wii::os_time
{
    struct GCTime
    {
        uint32_t unk1;
    } __attribute__((__packed__));

    extern "C"
    {
        extern GCTime __OSBusClock;
        uint32_t OSGetTick();
        int64_t OSGetTime();
    }
} // namespace libtp::gc_wii::os_time
#endif
