/**	@file cxx.h
 *	@brief Custom override of (de)allocation onto specific heaps.
 *
 *  @author Zephiles
 *	@bug No known bugs.
 */
#include "cxx.h"

#include <cstdint>
#include <cstring>

#include "tp/m_do_ext.h"
#include "tp/JKRExpHeap.h"
#include "tp/JKRHeap.h"

#ifdef PLATFORM_WII
#include "tp/dynamic_link.h"
#endif

void* getHeapPtr( int32_t id )
{
    static void** heapPtrArray[] = {
        &libtp::tp::m_Do_ext::AssertHeap,
        &libtp::tp::m_Do_ext::DbPrintHeap,
        &libtp::tp::m_Do_ext::gameHeap,
        &libtp::tp::m_Do_ext::zeldaHeap,
        &libtp::tp::m_Do_ext::commandHeap,
        &libtp::tp::m_Do_ext::archiveHeap,
        &libtp::tp::m_Do_ext::j2dHeap,

#ifndef PLATFORM_WII
        &libtp::tp::m_Do_ext::HostIOHeap,
#else
        &libtp::tp::dynamic_link::DynamicModuleControlBase::m_heap,
#endif     // PLATFORM_WII

    };

    // Make sure the id is valid
    constexpr uint32_t heapPtrArraySize = sizeof( heapPtrArray ) / sizeof( heapPtrArray[0] );
    if ( ( id < 0 ) || ( static_cast<uint32_t>( id ) >= heapPtrArraySize ) )
    {
        // The id is invalid, so use the archive heap by default
        id = HEAP_ARCHIVE;
    }

    return *heapPtrArray[id];
}

void* allocateMemory( void* heap, std::size_t size, int32_t alignment )
{
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( heap, size, alignment );
    return memset( newPtr, 0, size );
}

void* allocateMemoryFromMainHeap( std::size_t size, int32_t alignment )
{
    void* heapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return allocateMemory( heapPtr, size, alignment );
}

void* operator new( std::size_t size )
{
    return allocateMemoryFromMainHeap( size, 0x20 );
}

void* operator new[]( std::size_t size )
{
    return allocateMemoryFromMainHeap( size, 0x20 );
}

void* operator new( std::size_t size, int32_t alignment )
{
    return allocateMemoryFromMainHeap( size, alignment );
}

void* operator new[]( std::size_t size, int32_t alignment )
{
    return allocateMemoryFromMainHeap( size, alignment );
}

void* operator new( size_t size, int32_t alignment, int32_t id )
{
    void* heapPtr = getHeapPtr( id );
    return allocateMemory( heapPtr, size, alignment );
}

void* operator new[]( size_t size, int32_t alignment, int32_t id )
{
    void* heapPtr = getHeapPtr( id );
    return allocateMemory( heapPtr, size, alignment );
}

void operator delete( void* ptr )
{
    return libtp::tp::jkr_heap::__dl_JKRHeap( ptr );
}

void operator delete[]( void* ptr )
{
    return libtp::tp::jkr_heap::__dl_JKRHeap( ptr );
}

void operator delete( void* ptr, std::size_t size )
{
    (void) size;

    return libtp::tp::jkr_heap::__dl_JKRHeap( ptr );
}

void operator delete[]( void* ptr, std::size_t size )
{
    (void) size;

    return libtp::tp::jkr_heap::__dl_JKRHeap( ptr );
}
