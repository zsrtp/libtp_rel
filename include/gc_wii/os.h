/**	@file os.h
 *	@brief Holds OS definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef GC_WII_OS_H_
#define GC_WII_OS_H_

#include <cstdint>

namespace libtp::gc_wii::os
{
    extern "C"
    {
        extern uint32_t __OSBusClock;
    }
} // namespace libtp::gc_wii::os
#endif
