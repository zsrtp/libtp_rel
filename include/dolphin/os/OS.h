#ifndef OS_H
#define OS_H

// at some point: we should split this up into various OS/... headers. but not
// yet, since barely any files include this atm.

#include "symbol_defines.h"
#include "dolphin/dvd/dvd.h"

#include <cstdint>
#include <cstdarg>

// Declare classes/structs so that other stuff can use them
struct OSThread;
struct OSAlarm;
struct OSContext;

typedef void ( *OSSwitchThreadCallback )( OSThread* from, OSThread* to );
typedef void ( *OSAlarmHandler )( OSAlarm* alarm, OSContext* context );
typedef void* OSMessage;
typedef uint32_t OSTick;
typedef int64_t OSTime;
typedef int32_t OSHeapHandle;
typedef uint16_t OSThreadState;

#define OS_ASSERT( ... )

#define OS_BUS_CLOCK ( *(uint32_t*) 0x800000F8 )
#define OS_CORE_CLOCK ( *(uint32_t*) 0x800000FC )
#define OS_TIMER_CLOCK ( OS_BUS_CLOCK / 4 )

#define OS_MESSAGE_NON_BLOCKING 0
#define OS_MESSAGE_BLOCKING 1

#define OS_THREAD_STATE_UNINITIALIZED 0
#define OS_THREAD_STATE_READY 1
#define OS_THREAD_STATE_RUNNING 2
#define OS_THREAD_STATE_WAITING 4
#define OS_THREAD_STATE_DEAD 8

struct OSMutex
{
    uint8_t unk[24];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSMutex ) == 0x18 );

struct OSMutexLink
{
    struct OSMutex* prev;
    struct OSMutex* next;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSMutexLink ) == 0x8 );

struct OSMutexQueue
{
    struct OSMutex* prev;
    struct OSMutex* next;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSMutexQueue ) == 0x8 );

struct OSContext
{
    uint32_t gpr[32];
    uint32_t cr;
    uint32_t lr;
    uint32_t ctr;
    uint32_t xer;
    double fpr[32];
    uint32_t padding_1;
    uint32_t fpscr;
    uint32_t srr0;
    uint32_t srr1;
    uint16_t mode;
    uint16_t state;
    uint32_t gqr[8];
    uint32_t padding_2;
    double ps[32];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSContext ) == 0x2C8 );

struct OSThreadLink
{
    struct OSThread* prev;
    struct OSThread* next;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSThreadLink ) == 0x8 );

struct OSThreadQueue
{
    struct OSThread* head;
    struct OSThread* tail;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSThreadQueue ) == 0x8 );

struct OSCond
{
    struct OSThreadQueue queue;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSCond ) == 0x8 );

struct OSMessageQueue
{
    struct OSThreadQueue sending_queue;
    struct OSThreadQueue receiving_queue;
    void** message_array;
    int32_t num_messages;
    int32_t first_index;
    int32_t num_used;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSMessageQueue ) == 0x20 );

struct OSCalendarTime
{
    int32_t seconds;
    int32_t minutes;
    int32_t hours;
    int32_t day_of_month;
    int32_t month;
    int32_t year;
    int32_t week_day;
    int32_t year_day;
    int32_t milliseconds;
    int32_t microseconds;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSCalendarTime ) == 0x28 );

enum OSSoundMode
{
    SOUND_MODE_MONO = 0,
    SOUND_MODE_STEREO = 1,
};

struct OSThread
{
    OSContext context;
    OSThreadState state;
    uint16_t attributes;
    int32_t suspend_count;
    uint32_t effective_priority;
    uint32_t base_priority;
    void* exit_value;
    OSThreadQueue* queue;
    OSThreadLink link;
    OSThreadQueue join_queue;
    OSMutex* mutex;
    OSMutexQueue owned_mutexes;
    OSThreadLink active_threads_link;
    uint8_t* stack_base;
    uint8_t* stack_end;
    uint8_t* error_code;
    void* data[2];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSThread ) == 0x318 );

struct OSAlarmLink
{
    /* 0x0 */ OSAlarm* prev;
    /* 0x4 */ OSAlarm* next;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSAlarmLink ) == 0x8 );

struct OSAlarm
{
    /* 0x00 */ OSAlarmHandler handler;
    /* 0x04 */ uint32_t tag;
    /* 0x08 */ OSTime fire_time;
    /* 0x10 */ OSAlarmLink link;
    /* 0x18 */ OSTime period_time;
    /* 0x20 */ OSTime start_time;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( OSAlarm ) == 0x28 );

struct GLOBAL_MEMORY
{
    DVDDiskID disk;
    uint32_t nintendo_boot_code; /* Nintendo Standard Boot Code. */
    uint32_t field_0x24;         /* 	Version (set by apploader) */
    uint32_t memory_size;        /* Memory Size (Physical) 24MB */
    uint32_t field_0x2c;         /* Production Board Model */
    uint32_t arena_low;          /* 	Arena Low */
    uint32_t arena_high;         /* 	Arena High */
    uint32_t field_0x38;         /* 	Start of FST (varies in all games) */
    uint32_t field_0x3c;         /* Maximum FST Size (varies in all games) */
    uint8_t padding_0x40[32];
    uint8_t field_0x60[36]; /* Hook is PPC assembler used by Debugger.  */
    uint8_t padding_0x84[84];
    OSContext* field_0xd8; /* Current OSContext instance. */
    OSThread* field_0xdc;  /* OSThread pointer, previously created thread. */
    OSThread* field_0xe0;  /* OSThread pointer, most recently created thread. */
    OSThread* field_0xe4;  /* Current thread pointer. */
    uint32_t field_0xe8;   /* Dev Debugger Monitor Address (If present) */
    uint32_t field_0xec;   /* Simulated Memory Size */
    uint32_t field_0xf0;   /* Pointer to data read from partition's bi2.bin, set by apploader */
    uint32_t field_0xf4;   /* Console Bus Speed */
    uint32_t field_0xf8;   /* Console CPU Speed */
    uint8_t padding_0xfc[5892];
    uint8_t field_0x1800[6144]; /* Unused Exception Vector */
    uint8_t padding_0x3000[64];
    uint32_t field_0x3040[34]; /* 	__OSInterrupt table. */
    uint32_t field_0x30c8;     /* Pointer to the first loaded REL file. */
    uint32_t field_0x30cc;     /* Pointer to the last loaded REL file. */
    uint32_t field_0x30d0;     /* Pointer to a REL module name table, or 0. */
    uint8_t padding_0x30d8[4];
    uint64_t field_0x30d8; /* System time */
    uint8_t padding_0x30e0[4];
    uint32_t field_0x30e4; /* __OSPADButton */
    uint8_t padding_0x30ec[8];
    uint32_t field_0x30f0; /* DOL Execute Parameters */
    uint8_t padding_0x30f4[12];
    uint32_t field_0x3100; /* Physical MEM1 size */
    uint32_t field_0x3104; /* Simulated MEM1 size */
    uint8_t padding_0x3108[8];
    uint32_t field_0x3110; /* Heap pointer (end of usable memory by the game) */
    uint8_t padding_0x3114[4];
    uint32_t field_0x3118; /* 	Physical MEM2 size */
    uint32_t field_0x311c; /* Simulated MEM2 size */
    uint8_t padding_0x3120[16];
    uint32_t field_0x3130; /* IOS Heap Range (start) */
    uint32_t field_0x3134; /* IOS Heap Range (end) */
    uint32_t field_0x3138; /* Hollywood Version */
    uint8_t padding_0x313c[4];
    uint32_t field_0x3140; /* 	IOS version */
    uint32_t field_0x3144; /* 	IOS Build Date */
    uint8_t padding_0x3148[16];
    uint32_t field_0x3158; /* 	GDDR Vendor Code */
    uint32_t field_0x315c; /* During the boot process, */
    uint32_t field_0x3160; /* Init semaphore (1-2 main() waits for this to clear) */
    uint32_t field_0x3164; /* GC (MIOS) mode flag? */
    uint8_t padding_0x3168[24];
    uint32_t field_0x3180; /* 	Game ID */
    uint8_t field_0x3184;  /* Application type. 0x80 for disc games, 0x81 for channels. */
    uint8_t padding_0x3185;
    uint8_t field_0x3186; /* Application type 2 */
    uint8_t padding_0x3187;
    uint32_t field_0x3188; /* Minimum IOS version */
    uint32_t field_0x318c; /* 	Title Booted from NAND (Launch Code) */
    uint32_t field_0x3190; /* 	Title Booted from NAND (Return Code) */
    uint32_t field_0x3194; /* While reading a disc, the system menu reads the first partition table (0x20
                         bytes from 0x00040020) and stores a pointer to the data partition entry.
                         When launching the disc game, it copies the partition type to 0x3194. The
                         partition type for data partitions is 0, so typically this location always
                         has 0. */
    uint32_t field_0x3198; /* While reading a disc, the system menu reads the first partition table (0x20
                         bytes from 0x00040020) and stores a pointer to the data partition entry.
                         When launching the disc game, it copies the partition offset to 0x3198. */
    uint32_t field_0x319c; /* Set by the apploader to 0x80 for single-layer discs and 0x81 for dual-layer
                         discs (determined by whether 0x7ed40000 is the value at offset 0x30 in the
                         partition's bi2.bin; it seems that that value is 0 for single-layer discs).
                         Early titles' apploaders do not set it at all, leaving the value as 0. This
                         controls the /dev/di#0x8D_DVDLowUnencryptedRead out-of-bounds Error #001
                         read for titles that do make such a read: they try to read at 0x7ed40000
                         for dual-layer discs and 0x460a0000 for single-layer discs. */
    uint8_t field_0x31a0[3424];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( GLOBAL_MEMORY ) == 0x3F00 );

inline void* OSPhysicalToCached( uint32_t offset )
{
    OS_ASSERT( offset <= 0x1fffffff );
    return (void*) ( offset + 0x80000000 );
}

extern "C"
{
    // Functions
    int32_t OSEnableScheduler( void );
    int32_t OSDisableScheduler( void );
    int32_t OSCheckActiveThreads( void );
    OSThread* OSGetCurrentThread( void );

    int32_t OSSuspendThread( OSThread* thread );
    int32_t OSSetThreadPriority( OSThread* thread, uint32_t pri );
    int32_t OSGetThreadPriority( OSThread* thread );
    bool OSCreateThread( OSThread* thread,
                         void* func,
                         void* param,
                         void* stack,
                         uint32_t stackSize,
                         int32_t priority,
                         int32_t attr );
    void OSCancelThread( OSThread* thread );
    void OSDetachThread( OSThread* thread );
    int32_t OSResumeThread( OSThread* thread );
    void OSExitThread( void* exit_val );
    bool OSIsThreadSuspended( OSThread* thread );
    bool OSIsThreadTerminated( OSThread* thread );
    OSSwitchThreadCallback OSSetSwitchThreadCallback( OSSwitchThreadCallback callback );

    void OSInitMessageQueue( OSMessageQueue* queue, OSMessage* messages, int32_t message_count );
    bool OSReceiveMessage( OSMessageQueue* queue, OSMessage* message, int32_t flags );
    bool OSSendMessage( OSMessageQueue* queue, OSMessage message, int32_t flags );
    bool OSJamMessage( OSMessageQueue* queue, OSMessage message, int32_t flags );

    int32_t OSGetConsoleType( void );
    uint32_t OSGetResetCode( void );

    uint32_t OSGetSoundMode( void );
    void OSSetSoundMode( OSSoundMode mode );

    void OSAttention( const char* msg, ... );
    void OSPanic( const char* file, int32_t line, const char* fmt, ... );
    void OSReport( const char* fmt, ... );
    void OSReport_Error( const char* fmt, ... );
    void OSReport_FatalError( const char* fmt, ... );
    void OSReport_System( const char* fmt, ... );
    void OSReport_Warning( const char* fmt, ... );
    void OSReportDisable( void );
    void OSReportEnable( void );
    void OSReportForceEnableOff( void );
    void OSReportForceEnableOn( void );
    void OSVReport( const char* format, va_list list );

    void OSTicksToCalendarTime( OSTime ticks, OSCalendarTime* out_time );
    OSTime OSGetTime( void );
    OSTick OSGetTick( void );

    uint32_t OSGetArenaLo();
    uint32_t OSGetArenaHi();
    uint32_t OSInitAlloc( uint32_t low, uint32_t high, int32_t maxHeaps );
    void OSSetArenaLo( uint32_t newLo );
    void OSSetArenaHi( uint32_t newHi );
    void* OSAllocFromArenaLo( uint32_t size, int32_t alignment );

    void OSInitMutex( OSMutex* mutex );
    void OSLockMutex( OSMutex* mutex );
    bool OSTryLockMutex( OSMutex* mutex );
    void OSUnlockMutex( OSMutex* mutex );

    bool OSDisableInterrupts();
    bool OSEnableInterrupts();
    bool OSRestoreInterrupts( int32_t level );

    void OSResetSystem( int32_t param_1, uint32_t param_2, int32_t param_3 );

    void OSSetSaveRegion( void* start, void* end );

    void LCDisable( void );

    void mDoPrintf_OSReportInit( void );

    uint8_t* OSGetStackPointer( void );

    void OSCreateAlarm( OSAlarm* alarm );
    void OSCancelAlarm( OSAlarm* alarm );
    void OSSetAlarm( OSAlarm* alarm, OSTime time, OSAlarmHandler handler );
    void OSSetPeriodicAlarm( OSAlarm*, OSTime, OSTime, OSAlarmHandler );

    void OSInitCond( OSCond* cond );
    void OSWaitCond( OSCond* cond, OSMutex* mutex );
    void OSSignalCond( OSCond* cond );

    void mDoPrintf_OSSwitchFiberEx( uint32_t, uint32_t, uint32_t, uint32_t, uint32_t, uint32_t );
    void mDoPrintf_OSVAttention( const char* fmt, va_list args );

    /*
    inline int16_t __OSf32tos16(register float inF) {
        register int16_t out;
        uint32_t tmp;
        register uint32_t* tmpPtr = &tmp;
        // clang-format off
        asm {
            psq_st inF, 0(tmpPtr), 0x1, 5
            lha out, 0(tmpPtr)
        }
        // clang-format on

        return out;
    }

    inline void OSf32tos16(float* f, int16_t* out) {
        *out = __OSf32tos16(*f);
    }

    inline uint8_t __OSf32tou8(register float inF) {
        register uint8_t out;
        uint32_t tmp;
        register uint32_t* tmpPtr = &tmp;
        // clang-format off
        asm {
            psq_st inF, 0(tmpPtr), 0x1, 2
            lbz out, 0(tmpPtr)
        }
        // clang-format on

        return out;
    }

    inline void OSf32tou8(float* f, uint8_t* out) {
        *out = __OSf32tou8(*f);
    }

    inline void OSInitFastCast(void) {
        // clang-format off
        asm {
            li r3, 4
            oris r3, r3, 4
            mtspr 0x392, r3
            li r3, 5
            oris r3, r3, 5
            mtspr 0x393, r3
            li r3, 6
            oris r3, r3, 6
            mtspr 0x394, r3
            li r3, 7
            oris r3, r3, 7
            mtspr 0x395, r3
        }
        // clang-format on
    }
    */
}

#endif