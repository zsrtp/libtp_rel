/**	@file JKRExpHeap.h
 *	@brief Holds symbols of the JKRExpHeap field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */

#pragma once

#include "../types.h"

namespace tp::jkr_exp_heap
{
    extern "C"
    {
        /**
         *	@brief Allocates a number of bytes in a given heap
         *
         *	@param heap The heap pointer
         *	@param size The number of bytes to be allocated
         */
        void* do_alloc_JKRExpHeap(void* heap, u32 size, s32 unk3);

        /**
         *	@brief Frees a number of bytes in a given heap
         *
         *	@param heap The heap pointer
         *	@param size The number of bytes to be freed
         */
        void do_free_JKRExpHeap(void* heap, void* ptr);
    }
}  // namespace tp::jkr_exp_heap