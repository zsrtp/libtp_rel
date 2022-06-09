#ifndef DVD_H
#define DVD_H

#include <cstdint>

// Declare classes/structs so that other stuff can use them
struct DVDCommandBlock;
struct DVDFileInfo;

typedef void ( *DVDCBCallback )( int32_t result, DVDCommandBlock* block );
typedef void ( *DVDCallback )( int32_t result, DVDFileInfo* info );

enum DVDState
{
    DVD_STATE_END = 0x0,
    DVD_STATE_BUSY = 0x1,
    DVD_STATE_WAITING = 0x2,
    DVD_STATE_COVER_CLOSED = 0x3,
    DVD_STATE_NO_DISK = 0x4,
    DVD_STATE_COVER_OPEN = 0x5,
    DVD_STATE_WRONG_DISK = 0x6,
    DVD_STATE_MOTOR_STOPPED = 0x7,
    DVD_STATE_IGNORED = 0x8,
    DVD_STATE_CANCELED = 0xa,     // lmao they skipped 9
    DVD_STATE_RETRY = 0xb,
    DVD_STATE_FATAL_ERROR = -1,
};

struct DVDDirectory
{
    uint32_t entry_number;
    uint32_t location;
    uint32_t next;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( DVDDirectory ) == 0xC );

struct DVDDirectoryEntry
{
    uint32_t entry_number;
    bool is_directory;
    uint8_t padding[3];
    char* name;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( DVDDirectoryEntry ) == 0xC );

struct DVDDiskID
{
    char game_name[4];
    char company[2];
    uint8_t disk_number;
    uint8_t game_version;
    uint8_t is_streaming;
    uint8_t streaming_buffer_size;
    uint8_t padding[22];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( DVDDiskID ) == 0x20 );

struct DVDCommandBlock
{
    DVDCommandBlock* next;
    DVDCommandBlock* prev;
    uint32_t command;
    int32_t state;
    uint32_t offset;
    uint32_t length;
    void* buffer;
    uint32_t current_transfer_size;
    uint32_t transferred_size;
    DVDDiskID* disk_id;
    DVDCBCallback callback;
    void* user_data;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( DVDCommandBlock ) == 0x30 );

struct DVDFileInfo
{
    DVDCommandBlock block;
    uint32_t start_address;
    uint32_t length;
    DVDCallback callback;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( DVDFileInfo ) == 0x3C );

extern "C"
{
    int32_t DVDOpen( const char*, DVDFileInfo* );
    int32_t DVDClose( DVDFileInfo* );
    int32_t DVDReadPrio( DVDFileInfo*, void*, int32_t, int32_t, int32_t );
    DVDDiskID* DVDGetCurrentDiskID( void );
    int32_t DVDFastOpen( long, DVDFileInfo* );
    int DVDGetCommandBlockStatus( DVDCommandBlock* );
    int32_t DVDReadAsyncPrio( DVDFileInfo*, void*, long, long, DVDCallback, long );
    int32_t DVDConvertPathToEntrynum( const char* );
    DVDState DVDGetDriveStatus( void );
    int32_t DVDCheckDisk( void );

    bool DVDChangeDir( const char* );
    bool DVDCloseDir( DVDDirectory* );
    bool DVDOpenDir( const char*, DVDDirectory* );
    bool DVDReadDir( DVDDirectory*, DVDDirectoryEntry* );
}

#endif