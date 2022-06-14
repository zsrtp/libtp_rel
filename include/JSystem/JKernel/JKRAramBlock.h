#ifndef JKRARAMBLOCK_H
#define JKRARAMBLOCK_H

#include "symbol_defines.h"
#include "JSystem/JKernel/JKRAramHeap.h"
#include "JSystem/JSupport/JSUList.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRAramBlock;
class JKRAramHeap;

extern "C"
{
    // Variables
    extern void* JKRAramBlock_vt[];     // Vtable

    // Functions
    JKRAramBlock* JKRAramBlock_ct( JKRAramBlock* JKRAramBlockThis,
                                   uint32_t address,
                                   uint32_t size,
                                   uint32_t freeSize,
                                   uint8_t groupId,
                                   bool isTempMemory );     // Constructor

    JKRAramBlock* JKRAramBlock_dt( JKRAramBlock* JKRAramBlockThis, int16_t freeThis );     // Destructor

    JKRAramBlock* JKRAramBlock_allocHead( JKRAramBlock* JKRAramBlockThis, uint32_t size, uint8_t groupId, JKRAramHeap* heap );
    JKRAramBlock* JKRAramBlock_allocTail( JKRAramBlock* JKRAramBlockThis, uint32_t size, uint8_t groupId, JKRAramHeap* heap );
}

class JKRAramBlock
{
   public:
    /*
    JKRAramBlock( uint32_t address, uint32_t size, uint32_t freeSize, uint8_t groupId, bool isTempMemory )
    {
        JKRAramBlock_ct( this, address, size, freeSize, groupId, isTempMemory );
    }
    */

    // virtual ~JKRAramBlock();

    JKRAramBlock* allocHead( uint32_t size, uint8_t groupId, JKRAramHeap* heap )
    {
        return JKRAramBlock_allocHead( this, size, groupId, heap );
    }

    JKRAramBlock* allocTail( uint32_t size, uint8_t groupId, JKRAramHeap* heap )
    {
        return JKRAramBlock_allocTail( this, size, groupId, heap );
    }

    uint32_t getAddress() const { return mAddress; }

    uint32_t getSize() const { return mSize; }

    uint32_t getFreeSize() const { return mFreeSize; }

    bool isTempMemory() const { return mIsTempMemory; }

    void newGroupID( uint8_t groupId ) { mGroupId = groupId; }

   public:
    /* 0x00 */ void* vtable;
    /* 0x04 */ JSULink<JKRAramBlock> mBlockLink;
    /* 0x14 */ uint32_t mAddress;
    /* 0x18 */ uint32_t mSize;
    /* 0x1C */ uint32_t mFreeSize;
    /* 0x20 */ uint8_t mGroupId;
    /* 0x21 */ uint8_t mIsTempMemory;
    /* 0x22 */ uint8_t padding[2];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRAramBlock ) == 0x24 );

#endif