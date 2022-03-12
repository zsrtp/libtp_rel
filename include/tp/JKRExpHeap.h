/**	@file JKRExpHeap.h
 *	@brief Holds symbols of the JKRExpHeap field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_JKREXPHEAP_H
#define TP_JKREXPHEAP_H

#include <cstdint>

namespace libtp::tp::jkr_exp_heap
{
    extern "C"
    {
        /**
         *	@brief Allocates a number of bytes in a given heap
         *
         *	@param heap The heap pointer
         *	@param size The number of bytes to be allocated
         *	@param alignment The amount of bytes that the address of the memory should be aligned to. Negative values will
         *allocate from the tail of the heap instead of the head.
         */
        void* do_alloc_JKRExpHeap( void* heap, uint32_t size, int32_t alignment );

        /**
         *	@brief Frees a number of bytes in a given heap
         *
         *	@param heap The heap pointer
         *	@param size The number of bytes to be freed
         */
        void do_free_JKRExpHeap( void* heap, void* ptr );
    }
}     // namespace libtp::tp::jkr_exp_heap
#endif