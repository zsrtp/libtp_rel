/**	@file cxx.h
 *	@brief Custom override of (de)allocation onto specific heaps.
 *
 *	@author Zephiles
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef LIBTP_CXX_H
#define LIBTP_CXX_H

#include <cstdint>
#include <new>

#include "tp/JKRHeap.h"

enum HeapID : int32_t
{
    HEAP_ASSERT = 0,
    HEAP_DBPRINT,
    HEAP_GAME,
    HEAP_ZELDA,

#ifdef PLATFORM_WII
    // Cannot properly allocate from the command heap on GC
    HEAP_COMMAND,
#endif

    HEAP_ARCHIVE,
    HEAP_J2D,

#ifndef PLATFORM_WII
    HEAP_HOST_IO,
#else
    HEAP_DYNAMIC_LINK,
#endif
};

void* allocateMemoryFromMainHeap(std::size_t size, int32_t alignment);
void* allocateMemoryFromMainHeap(std::size_t size);
void* allocateMemoryFromHeapId(std::size_t size, int32_t alignment, int32_t id);

inline void* operator new(std::size_t size)
{
    return allocateMemoryFromMainHeap(size);
}

inline void* operator new[](std::size_t size)
{
    return allocateMemoryFromMainHeap(size);
}

inline void* operator new(std::size_t size, int32_t alignment)
{
    return allocateMemoryFromMainHeap(size, alignment);
}

inline void* operator new[](std::size_t size, int32_t alignment)
{
    return allocateMemoryFromMainHeap(size, alignment);
}

inline void* operator new(std::size_t size, int32_t alignment, int32_t id)
{
    return allocateMemoryFromHeapId(size, alignment, id);
}

inline void* operator new[](std::size_t size, int32_t alignment, int32_t id)
{
    return allocateMemoryFromHeapId(size, alignment, id);
}

inline void operator delete(void* ptr)
{
    return libtp::tp::jkr_heap::__dl_JKRHeap(ptr);
}

inline void operator delete[](void* ptr)
{
    return libtp::tp::jkr_heap::__dl_JKRHeap(ptr);
}

inline void operator delete(void* ptr, std::size_t size)
{
    (void)size;

    return libtp::tp::jkr_heap::__dl_JKRHeap(ptr);
}

inline void operator delete[](void* ptr, std::size_t size)
{
    (void)size;

    return libtp::tp::jkr_heap::__dl_JKRHeap(ptr);
}

#endif // LIBTP_CXX_H