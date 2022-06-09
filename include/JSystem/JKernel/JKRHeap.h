#ifndef JKRHEAP_H
#define JKRHEAP_H

#include "symbol_defines.h"
#include "JSystem/JKernel/JKRDisposer.h"
#include "JSystem/JSupport/JSUList.h"
#include "dolphin/os/OS.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRHeap;

typedef void ( *JKRErrorHandler )( void*, uint32_t, int32_t );

extern "C"
{
    // Variables
    extern void* JKRHeap_vt[];     // Vtable
    extern JKRHeap* JKRHeap_sSystemHeap;
    extern JKRHeap* JKRHeap_sCurrentHeap;
    extern JKRHeap* JKRHeap_sRootHeap;
    extern JKRErrorHandler JKRHeap_mErrorHandler;
    extern void* JKRHeap_mCodeStart;
    extern void* JKRHeap_mCodeEnd;
    extern void* JKRHeap_mUserRamStart;
    extern void* JKRHeap_mUserRamEnd;
    extern uint32_t JKRHeap_mMemorySize;

    // Functions
    JKRHeap* JKRHeap_ct( JKRHeap* JKRHeapThis,
                         void* start,
                         uint32_t size,
                         JKRHeap* parent,
                         bool use_error_handler );     // Constructor

    JKRHeap* JKRHeap_dt( JKRHeap* JKRHeapThis, int16_t freeThis );     // Destructor

    JKRHeap* JKRHeap_becomeSystemHeap( JKRHeap* JKRHeapThis );
    JKRHeap* JKRHeap_becomeCurrentHeap( JKRHeap* JKRHeapThis );
    void JKRHeap_destroy( JKRHeap* JKRHeapThis );
    void* JKRHeap_alloc2( JKRHeap* JKRHeapThis, uint32_t size, int32_t alignment );
    void JKRHeap_free2( JKRHeap* JKRHeapThis, void* ptr );
    void JKRHeap_freeAll( JKRHeap* JKRHeapThis );
    void JKRHeap_freeTail( JKRHeap* JKRHeapThis );
    int32_t JKRHeap_resize2( JKRHeap* JKRHeapThis, void* ptr, uint32_t size );
    int32_t JKRHeap_getSize2( JKRHeap* JKRHeapThis, void* ptr );
    int32_t JKRHeap_getFreeSize( JKRHeap* JKRHeapThis );
    void* JKRHeap_getMaxFreeBlock( JKRHeap* JKRHeapThis );
    int32_t JKRHeap_getTotalFreeSize( JKRHeap* JKRHeapThis );
    int32_t JKRHeap_changeGroupID( JKRHeap* JKRHeapThis, uint8_t newGroupId );

    uint32_t JKRHeap_getMaxAllocatableSize( JKRHeap* JKRHeapThis, int32_t alignment );
    JKRHeap* JKRHeap_find( const JKRHeap* JKRHeapThis, void* ptr );
    JKRHeap* JKRHeap_findAllHeap( const JKRHeap* JKRHeapThis, void* ptr );

    void JKRHeap_dispose_subroutine( JKRHeap* JKRHeapThis, uint32_t start, uint32_t end );
    bool JKRHeap_dispose1( JKRHeap* JKRHeapThis, void* ptr, uint32_t size );
    void JKRHeap_dispose2( JKRHeap* JKRHeapThis, void* begin, void* end );
    void JKRHeap_dispose3( JKRHeap* JKRHeapThis );

    bool JKRHeap_setErrorFlag( JKRHeap* JKRHeapThis, bool errorFlag );
    bool JKRHeap_isSubHeap( const JKRHeap* JKRHeapThis, JKRHeap* heap );

    /* vt[03] */ void JKRHeap_callAllDisposer( JKRHeap* JKRHeapThis );
    /* vt[19] */ int32_t JKRHeap_do_changeGroupID( JKRHeap* JKRHeapThis, uint8_t newGroupID );
    /* vt[20] */ uint8_t JKRHeap_do_getCurrentGroupId( JKRHeap* JKRHeapThis );
    /* vt[21] */ void JKRHeap_state_register( const JKRHeap* JKRHeapThis, void* state, uint32_t groupId );
    /* vt[22] */ bool JKRHeap_state_compare( const JKRHeap* JKRHeapThis, const void* state1, const void* state2 );
    /* vt[23] */ void JKRHeap_state_dump( const JKRHeap* JKRHeapThis, const void* state );

    bool JKRHeap_initArena( char** unk1, uint32_t* unk2, int32_t numHeaps );
    void* JKRHeap_alloc1( uint32_t size, int32_t alignment, JKRHeap* heap );
    void JKRHeap_free1( void* ptr, JKRHeap* heap );
    int32_t JKRHeap_resize1( void* ptr, uint32_t size, JKRHeap* heap );
    int32_t JKRHeap_getSize1( void* ptr, JKRHeap* heap );
    JKRHeap* JKRHeap_findFromRoot( void* ptr );

    void JKRHeap_copyMemory( void* dst, void* src, uint32_t size );
    void JKRHeap_JKRDefaultMemoryErrorRoutine( void* heap, uint32_t size, int32_t alignment );
    // void JKRHeap_fillMemory( void* dst, uint32_t size, uint8_t value );     // NOTE: never used
    // bool JKRHeap_checkMemoryFilled( void* src, uint32_t size, uint8_t value );
    JKRErrorHandler JKRHeap_setErrorHandler( JKRErrorHandler errorHandler );

    inline void* JKRHeap_getCodeStart( void ) { return JKRHeap_mCodeStart; }
    inline void* JKRHeap_getCodeEnd( void ) { return JKRHeap_mCodeEnd; }
    inline void* JKRHeap_getUserRamStart( void ) { return JKRHeap_mUserRamStart; }
    inline void* JKRHeap_getUserRamEnd( void ) { return JKRHeap_mUserRamEnd; }
    inline uint32_t JKRHeap_getMemorySize( void ) { return JKRHeap_mMemorySize; }
    inline JKRHeap* JKRHeap_getRootHeap() { return JKRHeap_sRootHeap; }

    inline JKRHeap* JKRHeap_getSystemHeap() { return JKRHeap_sSystemHeap; }
    inline JKRHeap* JKRHeap_getCurrentHeap() { return JKRHeap_sCurrentHeap; }
    inline void JKRHeap_setSystemHeap( JKRHeap* heap ) { JKRHeap_sSystemHeap = heap; }
    inline void JKRHeap_setCurrentHeap( JKRHeap* heap ) { JKRHeap_sCurrentHeap = heap; }

    inline void JKRHeap_setState_u32ID_( void* state, uint32_t id )
    {
        // state->mId = id;
        *reinterpret_cast<uint32_t*>( reinterpret_cast<uint32_t>( state ) + 0x14 ) = id;
    }

    inline void JKRHeap_setState_uUsedSize_( void* state, uint32_t usedSize )
    {
        // state->mUsedSize = usedSize;
        *reinterpret_cast<uint32_t*>( reinterpret_cast<uint32_t>( state ) + 0x0 ) = usedSize;
    }

    inline void JKRHeap_setState_u32CheckCode_( void* state, uint32_t checkCode )
    {
        // state->mCheckCode = checkCode;
        *reinterpret_cast<uint32_t*>( reinterpret_cast<uint32_t>( state ) + 0x4 ) = checkCode;
    }

    inline void* JKRHeap_getState_buf_( void* state )
    {
        // return &state->mBuf;
        return *reinterpret_cast<void**>( reinterpret_cast<uint32_t>( state ) + 0x8 );
    }

    inline void* JKRHeap_getState_( void* state ) { return JKRHeap_getState_buf_( state ); }

    void* JKRHeap_operator_new( uint32_t size );
    void* JKRHeap_operator_new_alignment( uint32_t size, int32_t alignment );
    void* JKRHeap_operator_new_heap( uint32_t size, JKRHeap* heap, int32_t alignment );

    void* JKRHeap_operator_new_array( uint32_t size );
    void* JKRHeap_operator_new_alignment_array( uint32_t size, int32_t alignment );
    void* JKRHeap_operator_new_heap_array( uint32_t size, JKRHeap* heap, int32_t alignment );

    void JKRHeap_operator_delete( void* ptr );
    void JKRHeap_operator_delete_array( void* ptr );
}

class JKRHeap
{
   public:
    class TState
    {
       public:
        uint32_t mUsedSize;
        uint32_t mCheckCode;
        uint32_t mBuf;
        uint32_t field_0xc;
        JKRHeap* mHeap;
        uint32_t mId;

       public:
        uint32_t getUsedSize() const { return mUsedSize; }
        uint32_t getCheckCode() const { return mCheckCode; }
        JKRHeap* getHeap() const { return mHeap; }
        uint32_t getId() const { return mId; }
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( TState ) == 0x18 );

   public:
    /* JKRHeap( void* start, uint32_t size, JKRHeap* parent, bool use_error_handler )
    {
        JKRHeap_ct( this, start, size, parent, use_error_handler );
    } */

    // virtual ~JKRHeap();

    JKRHeap* becomeSystemHeap() { return JKRHeap_becomeSystemHeap( this ); }
    JKRHeap* becomeCurrentHeap() { return JKRHeap_becomeCurrentHeap( this ); }
    void destroy() { JKRHeap_destroy( this ); }
    void* alloc( uint32_t size, int32_t alignment ) { return JKRHeap_alloc2( this, size, alignment ); }
    void free( void* ptr ) { JKRHeap_free2( this, ptr ); }
    void freeAll() { JKRHeap_freeAll( this ); }
    void freeTail() { JKRHeap_freeTail( this ); }
    int32_t resize( void* ptr, uint32_t size ) { return JKRHeap_resize2( this, ptr, size ); }
    int32_t getSize( void* ptr ) { return JKRHeap_getSize2( this, ptr ); }
    int32_t getFreeSize() { return JKRHeap_getFreeSize( this ); }
    void* getMaxFreeBlock() { return JKRHeap_getMaxFreeBlock( this ); }
    int32_t getTotalFreeSize() { return JKRHeap_getTotalFreeSize( this ); }
    int32_t changeGroupID( uint8_t newGroupId ) { return JKRHeap_changeGroupID( this, newGroupId ); }

    uint32_t getMaxAllocatableSize( int32_t alignment ) { return JKRHeap_getMaxAllocatableSize( this, alignment ); }
    JKRHeap* find( void* ptr ) const { return JKRHeap_find( this, ptr ); }
    JKRHeap* findAllHeap( void* ptr ) const { return JKRHeap_findAllHeap( this, ptr ); }

    void dispose_subroutine( uint32_t start, uint32_t end ) { JKRHeap_dispose_subroutine( this, start, end ); }
    bool dispose( void* ptr, uint32_t size ) { return JKRHeap_dispose1( this, ptr, size ); }
    void dispose( void* begin, void* end ) { JKRHeap_dispose2( this, begin, end ); }
    void dispose() { JKRHeap_dispose3( this ); }

    bool setErrorFlag( bool errorFlag ) { return JKRHeap_setErrorFlag( this, errorFlag ); }
    bool isSubHeap( JKRHeap* heap ) const { return JKRHeap_isSubHeap( this, heap ); }

    // clang-format off
    /* vt[03] */ // virtual void callAllDisposer() { JKRHeap_callAllDisposer( this ); }
    /* vt[04] */ // virtual uint32_t getHeapType() = 0;
    /* vt[05] */ // virtual bool check() = 0;
    /* vt[06] */ // virtual bool dump_sort();
    /* vt[07] */ // virtual bool dump() = 0;
    /* vt[08] */ // virtual void do_destroy() = 0;
    /* vt[09] */ // virtual void* do_alloc( uint32_t size, int32_t alignment ) = 0;
    /* vt[10] */ // virtual void do_free( void* ptr ) = 0;
    /* vt[11] */ // virtual void do_freeAll() = 0;
    /* vt[12] */ // virtual void do_freeTail() = 0;
    /* vt[13] */ // virtual void do_fillFreeArea() = 0;
    /* vt[14] */ // virtual int32_t do_resize( void* ptr, uint32_t size ) = 0;
    /* vt[15] */ // virtual int32_t do_getSize( void* ptr ) = 0;
    /* vt[16] */ // virtual int32_t do_getFreeSize() = 0;
    /* vt[17] */ // virtual void* do_getMaxFreeBlock() = 0;
    /* vt[18] */ // virtual int32_t do_getTotalFreeSize() = 0;

    /* vt[19] */ /* virtual int32_t do_changeGroupID( uint8_t newGroupID )
                 {
                    return JKRHeap_do_changeGroupID( this, newGroupID );
                 } */

    /* vt[20] */ // virtual uint8_t do_getCurrentGroupId() { return JKRHeap_do_getCurrentGroupId( this ); }

    /* vt[21] */ /* virtual void state_register( JKRHeap::TState* state, uint32_t groupId ) const
                 {
                    JKRHeap_state_register( this, state, groupId );
                 } */

    /* vt[22] */ /* virtual bool state_compare( const JKRHeap::TState& state1, const JKRHeap::TState& state2 ) const
                 {
                    return JKRHeap_state_compare( this, &state1, &state2 );
                 } */

    /* vt[23] */ // virtual void state_dump( const JKRHeap::TState& state ) const { JKRHeap_state_dump(this, &state); }
    // clang-format on

    void setDebugFill( bool debugFill ) { mDebugFill = debugFill; }
    bool getDebugFill() const { return mDebugFill; }
    void* getStartAddr() const { return (void*) mStart; }
    void* getEndAddr() const { return (void*) mEnd; }
    uint32_t getSize() const { return mSize; }
    bool getErrorFlag() const { return mErrorFlag; }

    void callErrorHandler( JKRHeap* heap, uint32_t size, int32_t alignment )
    {
        if ( JKRHeap_mErrorHandler )
        {
            ( *JKRHeap_mErrorHandler )( heap, size, alignment );
        }
    }

    JKRHeap* getParent() const
    {
        JSUTree<JKRHeap>* parent = mChildTree.getParent();
        return parent->getObject();
    }

    JSUTree<JKRHeap>& getHeapTree() { return mChildTree; }
    void appendDisposer( JKRDisposer* disposer ) { mDisposerList.append( &disposer->mLink ); }
    void removeDisposer( JKRDisposer* disposer ) { mDisposerList.remove( &disposer->mLink ); }
    void lock() { OSLockMutex( &mMutex ); }
    void unlock() { OSUnlockMutex( &mMutex ); }
    uint32_t getHeapSize() { return mSize; }

   protected:
    /* 0x00 */ void* vtable;
    /* 0x04 */ JKRDisposer disposer;
    /* 0x18 */ OSMutex mMutex;
    /* 0x30 */ uint8_t* mStart;
    /* 0x34 */ uint8_t* mEnd;
    /* 0x38 */ uint32_t mSize;
    /* 0x3C */ bool mDebugFill;
    /* 0x3D */ bool mCheckMemoryFilled;
    /* 0x3E */ uint8_t mAllocationMode;     // EAllocMode?
    /* 0x3F */ uint8_t mGroupId;
    /* 0x40 */ JSUTree<JKRHeap> mChildTree;
    /* 0x5C */ JSUList<JKRDisposer> mDisposerList;
    /* 0x68 */ bool mErrorFlag;
    /* 0x69 */ bool mInitFlag;
    /* 0x6A */ uint8_t padding_0x6a[2];

   public:
    /*
     static bool initArena( char**, uint32_t*, int32_t );
     static void* alloc( uint32_t size, int32_t alignment, JKRHeap* heap );
     static void free( void* ptr, JKRHeap* heap );
     static int32_t resize( void* ptr, uint32_t size, JKRHeap* heap );
     static int32_t getSize( void* ptr, JKRHeap* heap );
     static JKRHeap* findFromRoot( void* ptr );

     static void copyMemory( void* dst, void* src, uint32_t size );
     static void fillMemory( void* dst, uint32_t size, uint8_t value );     // NOTE: never used
     static bool checkMemoryFilled( void* src, uint32_t size, uint8_t value );

     static JKRErrorHandler setErrorHandler( JKRErrorHandler errorHandler );

     static void* getCodeStart( void ) { return mCodeStart; }
     static void* getCodeEnd( void ) { return mCodeEnd; }
     static void* getUserRamStart( void ) { return mUserRamStart; }
     static void* getUserRamEnd( void ) { return mUserRamEnd; }
     static uint32_t getMemorySize( void ) { return mMemorySize; }
     static JKRHeap* getRootHeap() { return sRootHeap; }

     static JKRHeap* getSystemHeap() { return sSystemHeap; }
     static JKRHeap* getCurrentHeap() { return sCurrentHeap; }
     static void setSystemHeap( JKRHeap* heap ) { sSystemHeap = heap; }
     static void setCurrentHeap( JKRHeap* heap ) { sCurrentHeap = heap; }

     static void setState_u32ID_( TState* state, uint32_t id ) { state->mId = id; }
     static void setState_uUsedSize_( TState* state, uint32_t usedSize ) { state->mUsedSize = usedSize; }
     static void setState_u32CheckCode_( TState* state, uint32_t checkCode ) { state->mCheckCode = checkCode; }
     static void* getState_buf_( TState* state ) { return &state->mBuf; }
     static void* getState_( TState* state ) { return getState_buf_( state ); }

     static void* mCodeStart;
     static void* mCodeEnd;
     static void* mUserRamStart;
     static void* mUserRamEnd;
     static uint32_t mMemorySize;

     static JKRHeap* sRootHeap;

     static JKRHeap* sSystemHeap;
     static JKRHeap* sCurrentHeap;

     static JKRErrorHandler mErrorHandler;
    */
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRHeap ) == 0x6C );

// Custom implementations of operators are being used in cxx.h, so comment these out for now
/*
void* operator new( uint32_t size )
{
    return JKRHeap_operator_new( size );
}

void* operator new( uint32_t size, int32_t alignment )
{
    return JKRHeap_operator_new_alignment( size, alignment );
}

void* operator new( uint32_t size, JKRHeap* heap, int32_t alignment )
{
    return JKRHeap_operator_new_heap( size, heap, alignment );
}

void* operator new[]( uint32_t size )
{
    return JKRHeap_operator_new_array( size );
}

void* operator new[]( uint32_t size, int32_t alignment )
{
    return JKRHeap_operator_new_alignment_array( size, alignment );
}

void* operator new[]( uint32_t size, JKRHeap* heap, int32_t alignment )
{
    return JKRHeap_operator_new_heap_array( size, heap, alignment );
}

void operator delete( void* ptr )
{
    JKRHeap_operator_delete( ptr );
}

void operator delete[]( void* ptr )
{
    JKRHeap_operator_delete_array( ptr );
}
*/

inline void* operator new( uint32_t size, void* ptr )
{
    return ptr;
}

// void JKRDefaultMemoryErrorRoutine( void* heap, uint32_t size, int32_t alignment );

inline void* JKRAllocFromHeap( JKRHeap* heap, uint32_t size, int32_t alignment )
{
    return JKRHeap_alloc1( size, alignment, heap );
}

inline void* JKRAllocFromSysHeap( uint32_t size, int32_t alignment )
{
    JKRHeap* systemHeap = JKRHeap_getSystemHeap();
    return systemHeap->alloc( size, alignment );
}

inline void JKRFreeToHeap( JKRHeap* heap, void* ptr )
{
    JKRHeap_free1( ptr, heap );
}

inline void JKRFreeToSysHeap( void* ptr )
{
    JKRHeap* systemHeap = JKRHeap_getSystemHeap();
    systemHeap->free( ptr );
}

inline void JKRFree( void* ptr )
{
    JKRHeap_free1( ptr, nullptr );
}

inline JKRHeap* JKRGetSystemHeap()
{
    return JKRHeap_getSystemHeap();
}

inline JKRHeap* JKRGetCurrentHeap()
{
    return JKRHeap_getCurrentHeap();
}

inline uint32_t JKRGetMemBlockSize( JKRHeap* heap, void* block )
{
    return JKRHeap_getSize1( block, heap );
}

inline void* JKRAlloc( uint32_t size, int32_t alignment )
{
    return JKRHeap_alloc1( size, alignment, nullptr );
}

inline int32_t JKRResizeMemBlock( JKRHeap* heap, void* ptr, uint32_t size )
{
    return JKRHeap_resize1( ptr, size, heap );
}

#endif