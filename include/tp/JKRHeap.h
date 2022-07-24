/**	@file JKRHeap.h
 *	@brief Holds symbols of the JKRHeap field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_JKRHEAP_H
#define TP_JKRHEAP_H

#include <cstdint>

namespace libtp::tp::jkr_heap
{
    extern "C"
    {
        /**
         *	@brief Frees memory used in any of the game's vanilla heaps
         *
         *	@param ptr The pointer to the memory to free
         */
        void __dl_JKRHeap( void* ptr );
    }
}     // namespace libtp::tp::jkr_heap
#endif