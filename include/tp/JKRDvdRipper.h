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
        /**
         *	@brief Loads a resource from the disc into RAM
         *
         *  @param fileIndex The index of the file to be loaded.
         *  @param unk2 Unknown.
         *  @param jkrExpandSwitch The expansion switch to be used.
         *  @param unk4 Unknown.
         *  @param jkrHeap A pointer to the current JKRHeap to be utilized.
         *  @param eAllocDirection The direction of the file to be read from the disc.
         *  @param unk7 Unknown.
         *  @param unk8 Unknown.
         *  @param unk9 Unknown.
         *
         *  @return Returns a pointer to the resource that has been loaded.
         */
        void* loadToMainRAM2(int32_t fileIndex,
                             uint8_t* unk2,
                             uint32_t jkrExpandSwitch,
                             uint32_t unk4,
                             void* jkrHeap,
                             uint32_t eAllocDirection,
                             uint32_t unk7,
                             int32_t* unk8,
                             uint32_t* unk9);
    }
} // namespace libtp::tp::JKRDvdRipper
#endif