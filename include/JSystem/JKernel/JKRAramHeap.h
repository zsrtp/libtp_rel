#ifndef JKRARAMHEAP_H
#define JKRARAMHEAP_H

#include "symbol_defines.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JKernel/JKRDisposer.h"
#include "JSystem/JKernel/JKRAramBlock.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "dolphin/os/OS.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRAramHeap;
class JKRAramBlock;

extern "C"
{
    // Variables
    extern void* JKRAramHeap_vt[];                          // Vtable
    extern JSUList<JKRAramBlock> JKRAramHeap_sAramList;     // TODO: fix type

    // Functions
    JKRAramHeap* JKRAramHeap_ct( JKRAramHeap* JKRAramHeapThis, uint32_t startAddress, uint32_t size );     // Contructor
    JKRAramHeap* JKRAramHeap_dt1( JKRAramHeap* JKRAramHeapThis, int16_t freeThis );                        // Destructor
    void* JKRAramHeap_dt2( void* JSUList_JKRAramBlock_This, int16_t freeThis );                            // Destructor

    JKRAramBlock* JKRAramHeap_alloc( JKRAramHeap* JKRAramHeapThis, uint32_t size, uint32_t allocMode );
    JKRAramBlock* JKRAramHeap_allocFromHead( JKRAramHeap* JKRAramHeapThis, uint32_t size );
    JKRAramBlock* JKRAramHeap_allocFromTail( JKRAramHeap* JKRAramHeapThis, uint32_t size );
    uint32_t JKRAramHeap_getFreeSize( JKRAramHeap* JKRAramHeapThis );
    uint32_t JKRAramHeap_getTotalFreeSize( JKRAramHeap* JKRAramHeapThis );
    void JKRAramHeap_dump( JKRAramHeap* JKRAramHeapThis );
}

class JKRAramHeap
{
   public:
    enum EAllocMode
    {
        HEAD = 0,
        TAIL = 1,
    };

   public:
    // TODO: fix type
    // static JSUList<JKRAramBlock> sAramList;

    // JKRAramHeap( uint32_t startAddress, uint32_t size ) { JKRAramHeap_ct( this, startAddress, size ); }
    // virtual ~JKRAramHeap();

    JKRAramBlock* alloc( uint32_t size, EAllocMode allocMode ) { return JKRAramHeap_alloc( this, size, allocMode ); }
    JKRAramBlock* allocFromHead( uint32_t size ) { return JKRAramHeap_allocFromHead( this, size ); }
    JKRAramBlock* allocFromTail( uint32_t size ) { return JKRAramHeap_allocFromTail( this, size ); }
    uint32_t getFreeSize() { return JKRAramHeap_getFreeSize( this ); }
    uint32_t getTotalFreeSize() { return JKRAramHeap_getTotalFreeSize( this ); }
    // uint32_t getUsedSize();
    void dump() { JKRAramHeap_dump( this ); }

    uint8_t getCurrentGroupID() const { return mGroupId; }

    JKRHeap* getMgrHeap() const { return mHeap; }

   private:
    void lock() { OSLockMutex( &mMutex ); }

    void unlock() { OSUnlockMutex( &mMutex ); }

   public:
    /* 0x00 */ void* vtable;
    /* 0x04 */ JKRDisposer disposer;
    /* 0x18 */ OSMutex mMutex;
    /* 0x30 */ JKRHeap* mHeap;
    /* 0x34 */ uint32_t mHeadAddress;
    /* 0x38 */ uint32_t mTailAddress;
    /* 0x3C */ uint32_t mSize;
    /* 0x40 */ uint8_t mGroupId;
    /* 0x41 */ uint8_t padding_0x41[3];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRAramHeap ) == 0x44 );

#endif