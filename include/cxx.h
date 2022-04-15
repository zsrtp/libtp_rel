/**	@file cxx.h
 *	@brief Custom override of (de)allocation onto specific heaps.
 *
 *  @author Zephiles
 *	@bug No known bugs.
 */
#pragma once

#include <new>
#include <cstdint>

enum HeapID : int32_t
{
    HEAP_ASSERT = 0,
    HEAP_DBPRINT,
    HEAP_GAME,
    HEAP_ZELDA,
    HEAP_COMMAND,
    HEAP_ARCHIVE,
    HEAP_J2D,
};

void* operator new(size_t size);
void* operator new[](size_t size);
void* operator new(size_t size, int32_t alignment);
void* operator new[](size_t size, int32_t alignment);
void* operator new(std::size_t size, int32_t alignment, int32_t heapId);
void* operator new[](std::size_t size, int32_t alignment, int32_t heapId);
void operator delete(void* ptr);
void operator delete[](void* ptr);
void operator delete(void* ptr, size_t size);
void operator delete[](void* ptr, size_t size);
void freeFromHeap(int32_t id, void* ptr);