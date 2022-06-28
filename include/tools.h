/**	@file tools.h
 *  @brief Various basic functions that can be useful
 *
 *	@author AECX
 *	@bug No known bugs.
 *  @todo At some point we might want to seperate functions into different namespaces
 * i.e. tools::array, tools::hashing, etc.; for now there aren't enough functions for this to make sense
 */
#ifndef LIBTP_TOOLS_H
#define LIBTP_TOOLS_H
#include <cstdint>

#include "tp/dzx.h"

namespace libtp::tools
{
    /**
     *  @brief Fletcher16 checksum
     *
     *  @param data Data to calculate the checksum from
     *  @param length How many bytes of data should be considered
     *  @return Checksum in 2 bytes
     */
    uint16_t fletcher16( uint8_t* data, int32_t length );

    /**
     *  @brief Savely loads a given stage-room-spawnpoint-state and event combination
     *
     *  @param stage 8 char stage ID
     *  @param room Room ID
     *  @param spawn Spawnpoint
     *  @param state Current State (Link)
     *  @param event EventID to trigger
     */
    void TriggerSaveLoad( const char* stage, uint8_t room, uint8_t spawn, uint8_t state = 0xFF, uint8_t event = 0xFF );

    /**
     *  @brief Spawns an actor
     *
     *  @param roomID Room id to spawn the actor
     *  @param actor The actor object to be spawned
     */
    void SpawnActor( uint8_t roomID, tp::dzx::ACTR& actor );

    /**
     *  @brief Spawns an actor
     *
     *  @param roomID Room id to spawn the actor
     *  @param actor The actor object to be spawned
     */
    void SpawnSCOB( uint8_t roomID, tp::dzx::SCOB& actor_data );

#ifndef PLATFORM_WII
    /**
     *  @brief Mounts a memory card
     *
     *  @param chan Slot to check for the memory card
     *
     *  @return One of the CARD_RESULT Constants (CARD_RESULT_READY, ...)
     */
    int32_t mountMemoryCard( int32_t chan );

    /**
     *  @brief Reads GCI data from offset to offset + length into buffer. This function assumes that the memory card is already
     * mounted, and does not unmount the memory card upon ending.
     *
     *  @param chan Slot to check for the file
     *  @param fileName GCI Filename to load
     *  @param length Maximum length to read
     *  @param offset GCI fileOffset to read
     *  @param[out] buffer Buffer to save the data
     *  @param startAfterComments Whether to start reading after the comments section of the file. This assumes that the banner,
     * icon, and comments are all directly next to each other in the file, and that the comments come last.
     *
     *  @return One of the CARD_RESULT Constants (CARD_RESULT_READY, ...)
     */
    int32_t ReadGCIMounted( int32_t chan,
                            const char* fileName,
                            int32_t length,
                            int32_t offset,
                            void* buffer,
                            bool startAfterComments );

    /**
     *  @brief Reads GCI data from offset to offset + length into buffer. This function mounts and unmounts the memory card upon
     * starting and ending respectively.
     *
     *  @param chan Slot to check for the file
     *  @param fileName GCI Filename to load
     *  @param length Maximum length to read
     *  @param offset GCI fileOffset to read
     *  @param[out] buffer Buffer to save the data
     *  @param startAfterComments Whether to start reading after the comments section of the file. This assumes that the banner,
     * icon, and comments are all directly next to each other in the file, and that the comments come last.
     *
     *  @return One of the CARD_RESULT Constants (CARD_RESULT_READY, ...)
     */
    int32_t ReadGCI( int32_t chan,
                     const char* fileName,
                     int32_t length,
                     int32_t offset,
                     void* buffer,
                     bool startAfterComments );
#else
    /**
     *  @brief Reads NAND data from offset to offset + length into buffer
     *
     *  @param fileName NAND Filename to load
     *  @param length Maximum length to read
     *  @param offset NAND fileOffset to read
     *  @param[out] buffer Buffer to save the data
     *
     *  @return One of the NAND_RESULT Constants (NAND_RESULT_READY, ...)
     */
    int32_t ReadNAND( const char* fileName, int32_t length, int32_t offset, void* buffer );
#endif
    /**
     *  @brief Reads file data from offset to offset + length into buffer.
     *
     *  @param file File to load
     *  @param length Maximum length to read
     *  @param offset File offset to read
     *  @param[out] buffer Buffer to save the data
     *
     *  @return One of the DVD_STATE Constants (DVD_STATE_END, ...)
     */
    int32_t ReadFile( const char* file, int32_t length, int32_t offset, void* buffer );
#ifdef DVD
    /**
     *  @brief Loads a REL file from the disc and runs it's prolog function
     *
     *  @param file File to load
     */
    bool callRelProlog( const char* file );
#else
    /**
     *  @brief Loads a REL file from the current mod's GCI file and runs it's prolog function
     *
     *  @param chan Slot to check for the file
     *  @param rel_id Module id of the REL file to load
     *  @param isMounted If true, then the function will try to mount the memory card. If false, then it is assumed that the
     * memory card is already mounted.
     *  @param stayMounted If true, then the function will not unmount the memory card before exiting.
     */
    bool callRelProlog( int32_t chan, uint32_t rel_id, bool isMounted, bool stayMounted );
#endif

    /**
     * @brief Generates a random number based on a seed and a maximum number
     *
     * @param seed A reference to the seed that's being used
     * @param max The maximum number to be generated by the function
     */
    uint32_t getRandom( uint64_t* seed, uint32_t max );

    /**
     * @brief Converts the given stage string into an index
     *
     * @param stage The stage string to be read in.
     */
    int32_t getStageIndex( const char* stage );

    /**
     * @brief Checks if the player is in a specific room in a stage
     *
     * @param room The room to be checked. If set to a negative value or higher than 255, then the room is not checked.
     * @param stage The stage string to be read in. If set to nullptr, then it is assumed that the room is for any stage.
     * If neither room nor stage are valid inputs, then the function will return true.
     */
    bool playerIsInRoomStage( int32_t room, const char* stage );

    // Allows to transform data as bytes 1:1 from A<-->B and vice versa
    template<typename A, typename B>
    union typeTransform
    {
        A a;
        B b;
    };

/**
 * @brief Structure for how REL files are handled in the GCI
 */
#define MAX_REL_ENTRIES 37
    struct RelEntry
    {
        uint32_t rel_id;       // Module ID
        uint32_t rel_size;     // Size of the REL file excluding CARD_READ_SIZE rounding
        uint32_t offset;       // Offset to the REL file from the start of the GCI file, excluding the GCI header
    } __attribute__( ( __packed__ ) );
    static_assert( sizeof( RelEntry ) == 0xC );
}     // namespace libtp::tools

#endif     // LIBTP_TOOLS_H