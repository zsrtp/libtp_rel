#include <tp/JKRExpHeap.h>
#include <tp/m_Do_ext.h>

#include <cstring>

void* operator new(size_t size)
{
    void* ArchiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    void* NewPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap(ArchiveHeapPtr, size, 0x20);
    return memset(NewPtr, 0, size);
}
void* operator new[](size_t size)
{
    void* ArchiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    void* NewPtr = libtp::tp::jkr_exp_heap::do_alloc_JKRExpHeap(ArchiveHeapPtr, size, 0x20);
    return memset(NewPtr, 0, size);
}
void operator delete(void* ptr)
{
    void* ArchiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap(ArchiveHeapPtr, ptr);
}
void operator delete[](void* ptr)
{
    void* ArchiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap(ArchiveHeapPtr, ptr);
}
void operator delete(void* ptr, std::size_t size)
{
    void* ArchiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap(ArchiveHeapPtr, ptr);
}
void operator delete[](void* ptr, std::size_t size)
{
    void* ArchiveHeapPtr = libtp::tp::m_Do_ext::archiveHeap;
    return libtp::tp::jkr_exp_heap::do_free_JKRExpHeap(ArchiveHeapPtr, ptr);
}