#ifndef GC_WII_DVD_H
#define GC_WII_DVD_H

#include <cstdint>

namespace libtp::gc_wii::dvd
{
    struct DVDFileInfo;
    struct DVDCommandBlock;
    typedef void ( *DVDCallback )( int32_t result, DVDFileInfo* info );
    typedef void ( *DVDCBCallback )( int32_t result, DVDCommandBlock* block );

#define DVD_STATE_FATAL_ERROR -1
#define DVD_STATE_END 0
#define DVD_STATE_BUSY 1
#define DVD_STATE_WAITING 2
#define DVD_STATE_COVER_CLOSED 3
#define DVD_STATE_NO_DISK 4
#define DVD_STATE_COVER_OPEN 5
#define DVD_STATE_WRONG_DISK 6
#define DVD_STATE_MOTOR_STOPPED 7
#define DVD_STATE_MOTOR_PAUSING 8
#define DVD_STATE_IGNORED 9
#define DVD_STATE_CANCELED 10
#define DVD_STATE_RETRY 11

#define DVD_READ_SIZE 32
#define DVD_OFFSET_SIZE 4

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

    struct DVDFileInfo
    {
        DVDCommandBlock block;
        uint32_t start_address;
        uint32_t length;
        DVDCallback callback;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( DVDDiskID ) == 0x20 );
    static_assert( sizeof( DVDCommandBlock ) == 0x30 );
    static_assert( sizeof( DVDFileInfo ) == 0x3C );

    extern "C"
    {
        /**
         *  @brief Opens a file.
         *
         *  @param fileName Pointer to file name to be opened
         *  @param fileInfo Pointer to file info to be used
         */
        bool DVDOpen( const char* fileName, DVDFileInfo* fileInfo );

        /**
         *  @brief Closes a file.
         *
         *  @param fileInfo Pointer to file info of the file to be closed
         */
        bool DVDClose( DVDFileInfo* fileInfo );

        /**
         *  @brief Reads data from a file synchronously.
         *
         *  @param fileInfo Pointer to file info of the file to be read
         *  @param buffer Pointer to buffer address (32 bytes aligned)
         *  @param length Number of bytes to be read (multiple of DVD_READ_SIZE)
         *  @param offset File position at which to start the read (multiple of DVD_OFFSET_SIZE)
         *  @param priority Priority of the read request. Goes from 0 to 3, with 0 being highest and 3 being lowest. Most
         * standard reads use 2.
         */
        int32_t DVDReadPrio( DVDFileInfo* fileInfo, void* buffer, int32_t length, int32_t offset, int32_t priority );
    }
}     // namespace libtp::gc_wii::dvd
#endif