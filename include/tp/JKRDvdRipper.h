/**	@file JKRDvdRipper.h
 *	@brief Contains function definitions that read data from the game disc.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_JKRDVDRIPPER_H
#define TP_JKRDVDRIPPER_H

#include <cstdint>

namespace libtp::tp::JKRDvdRipper
{
    extern "C"
    {
        void* loadToMainRAM2( int32_t fileIndex,
                              uint8_t* unk2,
                              uint32_t jkrExpandSwitch,
                              uint32_t unk4,
                              void* jkrHeap,
                              uint32_t eAllocDirection,
                              uint32_t unk7,
                              int32_t* unk8,
                              uint32_t* unk9 );
    }
}     // namespace libtp::tp::JKRDvdRipper
#endif