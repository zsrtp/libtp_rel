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
    uint16_t fletcher16(uint8_t* data, int32_t length);

    /**
     *  @brief Savely loads a given stage-room-spawnpoint-state and event combination
     *
     *  @param stage 8 char stage ID
     *  @param room Room ID
     *  @param spawn Spawnpoint
     *  @param state Current State (Link)
     *  @param event EventID to trigger
     */
    void triggerSaveLoad(const char* stage, uint8_t room, uint8_t spawn, uint8_t state = 0xFF, uint8_t event = 0xFF);

    /**
     *  @brief Spawns an actor
     *
     *  @param roomID Room id to spawn the actor
     *  @param actor The actor object to be spawned
     */
    int32_t spawnActor(uint8_t roomID, tp::dzx::ACTR& actor);

    /**
     *  @brief Spawns an actor
     *
     *  @param roomID Room id to spawn the actor
     *  @param actor The actor object to be spawned
     */
    int32_t spawnSCOB(uint8_t roomID, tp::dzx::SCOB& actor_data);

#ifndef PLATFORM_WII
    /**
     *  @brief Mounts a memory card
     *
     *  @param chan Slot to check for the memory card
     *
     *  @return One of the CARD_RESULT Constants (CARD_RESULT_READY, ...)
     */
    int32_t mountMemoryCard(int32_t chan);

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
    int32_t readGCIMounted(int32_t chan,
                           const char* fileName,
                           int32_t length,
                           int32_t offset,
                           void* buffer,
                           bool startAfterComments);

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
    int32_t readGCI(int32_t chan, const char* fileName, int32_t length, int32_t offset, void* buffer, bool startAfterComments);
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
    int32_t readNAND(const char* fileName, int32_t length, int32_t offset, void* buffer);
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
    int32_t readFile(const char* file, int32_t length, int32_t offset, void* buffer);
#ifdef DVD
    /**
     *  @brief Loads a REL file from the disc and runs it's prolog function
     *
     *  @param file File to load
     */
    bool callRelProlog(const char* file);
#elif defined PLATFORM_WII
    /**
     *  @brief Loads a REL file from the NAND flash and runs it's prolog function
     *
     *  @param file File to load
     */
    bool callRelProlog(const char* file);
#else
    /**
     *  @brief Loads a REL file from the current mod's GCI file and runs it's prolog function. If the memory card is not
     * mounted, then this function will mount it.
     *
     *  @param chan Slot to check for the file
     *  @param rel_id Module id of the REL file to load
     *  @param stayMounted If true, then this function will not unmount the memory card before running the prolog/epilog
     * functions.
     */
    bool callRelProlog(int32_t chan, uint32_t rel_id, bool stayMounted);

    /**
     *  @brief Loads a REL file from the current mod's GCI file and runs it's prolog function. This function unmounts the memory
     * card after the prolog/epilog functions have ran.
     *
     *  @param chan Slot to check for the file
     *  @param rel_id Module id of the REL file to load
     */
    bool callRelProlog(int32_t chan, uint32_t rel_id);
#endif

    /**
     * @brief Generates an unsigned 32 bit random number based on a state. This function was created by George Marsaglia, and
     * more information about it can be found here: https://www.jstatsoft.org/article/view/v008i14
     *
     * @param state A reference to the state that's being used
     */
    uint32_t xorshift32(uint32_t* state);

    /**
     * @brief Generates an unsigned 32 bit random number based on a state and a range
     *
     * @param state A reference to the state that's being used
     * @param range The maximum value that can be generated minus one. If this is 0, then the function will return 0.
     */
    uint32_t ulRand(uint32_t* state, uint32_t range);

    /**
     * @brief Converts the given stage string into an index
     *
     * @param stage The stage string to be read in.
     */
    int32_t getStageIndex(const char* stage);

    /**
     * @brief Returns the current room number (mStayNo converted to int32_t)
     */
    int32_t getCurrentRoomNo();

    /**
     * @brief Checks if the player is in a specific room in a stage
     *
     * @param room The room to be checked
     * @param stage The stage string to be read in
     */
    bool playerIsInRoomStage(int32_t room, const char* stage);

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
        uint32_t rel_id;   // Module ID
        uint32_t rel_size; // Size of the REL file excluding CARD_READ_SIZE rounding
        uint32_t offset;   // Offset to the REL file from the start of the GCI file, excluding the GCI header
    } __attribute__((__packed__));
    static_assert(sizeof(RelEntry) == 0xC);
} // namespace libtp::tools

#endif // LIBTP_TOOLS_H