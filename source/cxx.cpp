#include <cstdint>
#include <cstring>

#include "tp/JKRExpHeap.h"
#include "tp/m_do_ext.h"

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
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( archiveHeapPtr, ptr );
}
void operator delete[]( void* ptr, std::size_t size )
{
    void* archiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap( archiveHeapPtr, ptr );
}
