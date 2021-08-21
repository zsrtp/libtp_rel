/**	@file JKRHeap.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::JKRHeap
{
    class JKRHeap
    {
        private:
            /* 0x00 */ JKRHeap_vtable* vtable;
            /* 0x04 */ JKRDisposer_members disposer;
            /* 0x18 */ OSMutex mMutex;
            /* 0x30 */ uint8_t* mStart;
            /* 0x34 */ uint8_t* mEnd;
            /* 0x38 */ uint32_t mSize;
            /* 0x3C */ bool mDebugFill;
            /* 0x3D */ bool mCheckMemoryFilled;
            /* 0x3E */ uint8_t mAllocationMode;  // EAllocMode?
            /* 0x3F */ uint8_t mGroupId;
            /* 0x40 */ JSUTree<JKRHeap> mChildTree;
            /* 0x5C */ JSUList<JKRDisposer> mDisposerList;
            /* 0x68 */ bool mErrorFlag;
            /* 0x69 */ bool mInitFlag;
            /* 0x6A */ uint8_t padding_0x6a[2];
    } __attribute__((__packed__));

    class JKRHeap_vtable
    {
        public:
            /* vt[00] */ virtual void* field_0x0();
            /* vt[01] */ virtual void* field_0x4();
            /* vt[02] */ virtual void* dtor();
            /* vt[03] */ virtual void callAllDisposer();
            /* vt[04] */ virtual uint32_t getHeapType() = 0;
            /* vt[05] */ virtual bool check() = 0;
            /* vt[06] */ virtual bool dump_sort();
            /* vt[07] */ virtual bool dump() = 0;
            /* vt[08] */ virtual void do_destroy() = 0;
            /* vt[09] */ virtual void* do_alloc(uint32_t size, int alignment) = 0;
            /* vt[10] */ virtual void do_free(void* ptr) = 0;
            /* vt[11] */ virtual void do_freeAll() = 0;
            /* vt[12] */ virtual void do_freeTail() = 0;
            /* vt[13] */ virtual void do_fillFreeArea() = 0;
            /* vt[14] */ virtual int32_t do_resize(void* ptr, uint32_t size) = 0;
            /* vt[15] */ virtual int32_t do_getSize(void* ptr) = 0;
            /* vt[16] */ virtual int32_t do_getFreeSize() = 0;
            /* vt[17] */ virtual void* do_getMaxFreeBlock() = 0;
            /* vt[18] */ virtual int32_t do_getTotalFreeSize() = 0;
            /* vt[19] */ virtual uint8_t do_changeGroupID(uint8_t newGroupID);
            /* vt[20] */ virtual uint8_t do_getCurrentGroupId();
            /* vt[21] */ virtual void state_register(TState*, unsigned long) const;
            /* vt[22] */ virtual bool state_compare(TState const&, TState const&) const;
            /* vt[23] */ virtual void state_dump(TState const&) const;
    } __attribute__((__packed__));

    class TState
    {
        public:
            uint32_t mUsedSize;
            uint32_t mCheckCode;
            uint32_t mBuf;
            uint32_t field_0xc;
            JKRHeap* mHeap;
            uint32_t mId;
    } __attribute__((__packed__));
}// namespace libtp::tp::JKRHeap