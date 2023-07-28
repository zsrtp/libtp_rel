/**	@file cxx.h
 *	@brief Custom override of (de)allocation onto specific heaps.
 *
 *  @author Zephiles
 *	@bug No known bugs.
 */
#include "cxx.h"

#include <cstdint>
#include <cstring>

#include "gc_wii/OSCache.h"
#include "tp/m_do_ext.h"
#include "tp/JKRHeap.h"

#ifdef PLATFORM_WII
#include "tp/dynamic_link.h"
#endif

void* getHeapPtr(int32_t id)
{
    static void** heapPtrArray[] = {
        &libtp::tp::m_Do_ext::AssertHeap,
        &libtp::tp::m_Do_ext::DbPrintHeap,
        &libtp::tp::m_Do_ext::gameHeap,
        &libtp::tp::m_Do_ext::zeldaHeap,

#ifdef PLATFORM_WII
        // Cannot properly allocate from the command heap on GC
        &libtp::tp::m_Do_ext::commandHeap,
#endif

        &libtp::tp::m_Do_ext::archiveHeap,
        &libtp::tp::m_Do_ext::j2dHeap,

#ifndef PLATFORM_WII
        &libtp::tp::m_Do_ext::HostIOHeap,
#else
        &libtp::tp::dynamic_link::m_heap,
#endif
    };

    // Make sure the id is valid
    constexpr uint32_t heapPtrArraySize = sizeof(heapPtrArray) / sizeof(heapPtrArray[0]);
    if ((id < 0) || (static_cast<uint32_t>(id) >= heapPtrArraySize))
    {
        // The id is invalid, so use the archive heap by default
        id = HEAP_ARCHIVE;
    }

    return *heapPtrArray[id];
}

void* allocateMemory(std::size_t size, void* heap, int32_t alignment)
{
    // Make sure the heap exists
    if (!heap)
    {
        return nullptr;
    }

    void* ptr = libtp::tp::jkr_heap::__nw_JKRHeap(size, heap, alignment);
    ptr = memset(ptr, 0, size);
    libtp::gc_wii::os_cache::DCFlushRange(ptr, size);
    return ptr;
}

void* allocateMemoryFromMainHeap(std::size_t size, int32_t alignment)
{
    void* heapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return allocateMemory(size, heapPtr, alignment);
}

void* allocateMemoryFromMainHeap(std::size_t size)
{
    return allocateMemoryFromMainHeap(size, 0x20);
}

void* allocateMemoryFromHeapId(std::size_t size, int32_t alignment, int32_t id)
{
    void* heapPtr = getHeapPtr(id);
    return allocateMemory(size, heapPtr, alignment);
}
