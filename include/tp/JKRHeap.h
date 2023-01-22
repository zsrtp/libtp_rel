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
         *	@brief Allocates a number of bytes in a given heap
         *
         *	@param size The number of bytes to be allocated
         *	@param heap The heap pointer
         *	@param alignment The alignment to use for the address of the allocated memory
         */
        void* __nw_JKRHeap( uint32_t size, void* heap, int32_t alignment );

        /**
         *	@brief Frees memory used in any of the game's vanilla heaps
         *
         *	@param ptr The pointer to the memory to free
         */
        void __dl_JKRHeap( void* ptr );
    }
}     // namespace libtp::tp::jkr_heap
#endif