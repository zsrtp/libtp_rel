/**	@file cxx.h
 *	@brief Custom override of (de)allocation onto specific heaps.
 *
 *  @author Zephiles
 *	@bug No known bugs.
 */
#include "cxx.h"

#include <cstdint>
#include <cstring>

#include "tp/JKRExpHeap.h"
#include "tp/dynamic_link.h"
#include "tp/m_do_ext.h"

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

void* operator new( std::size_t size )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( archiveHeapPtr, size, 0x20 );
    return memset( newPtr, 0, size );
}
void* operator new[]( std::size_t size )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( archiveHeapPtr, size, 0x20 );
    return memset( newPtr, 0, size );
}
void* operator new( std::size_t size, int32_t alignment )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( archiveHeapPtr, size, alignment );
    return memset( newPtr, 0, size );
}
void* operator new[]( std::size_t size, int32_t alignment )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( archiveHeapPtr, size, alignment );
    return memset( newPtr, 0, size );
}
void operator delete( void* ptr )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( archiveHeapPtr, ptr );
}
void operator delete[]( void* ptr )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( archiveHeapPtr, ptr );
}
void operator delete( void* ptr, std::size_t size )
{
    (void)size;

    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( archiveHeapPtr, ptr );
}
void operator delete[]( void* ptr, std::size_t size )
{
    (void)size;

    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( archiveHeapPtr, ptr );
}

void* operator new( size_t size, int32_t alignment, int32_t id )
{
    void* heapPtr = getHeapPtr( id );
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( heapPtr, size, alignment );
    return memset( newPtr, 0, size );
}

void* operator new[]( size_t size, int32_t alignment, int32_t id )
{
    void* heapPtr = getHeapPtr( id );
    void* newPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap( heapPtr, size, alignment );
    return memset( newPtr, 0, size );
}

// Cannot used overloaded delete operator, so must use a generic function
void freeFromHeap( int32_t id, void* ptr )
{
    void* heapPtr = getHeapPtr( id );
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( heapPtr, ptr );
}
