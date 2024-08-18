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
         *	@brief Resizes memory used in a heap
         *
         *	@param ptr The pointer to the memory to resize
         *	@param size The size to resize the memory to
         *	@param heap heap The heap pointer. If nullptr, then the function will search through all of the heaps to find ptr.
         *
         *	@returns The size of the memory
         */
        uint32_t resize1_JKRHeap(void* ptr, uint32_t size, void* heap);

        /**
         *	@brief Allocates a number of bytes in a given heap
         *
         *	@param size The number of bytes to be allocated
         *	@param heap The heap pointer
         *	@param alignment The alignment to use for the address of the allocated memory
         */
        void* __nw_JKRHeap(uint32_t size, void* heap, int32_t alignment);

        /**
         *	@brief Frees memory used in any of the game's vanilla heaps
         *
         *	@param ptr The pointer to the memory to free
         */
        void __dl_JKRHeap(void* ptr);
    }
} // namespace libtp::tp::jkr_heap
#endif