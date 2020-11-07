/**	@file tools.h
 *  @brief Various basic functions that can be useful
 *
 *	@author AECX
 *	@bug No known bugs.
 *  @todo At some point we might want to seperate functions into different namespaces
 * i.e. tools::array, tools::hashing, etc.; for now there aren't enough functions for this to make sense
 */

#pragma once
#include <cstdint>

namespace libtp::tools
{
    /**
     *  @brief Returns the index of needle in haystack, -1 if error
     *
     *  @param haystack The array for which you need the index
     *  @param needle The data to find in haystack
     *  @param length Length (in bytes) of haystack
     *  @param chunkSize Length (in bytes) of one individual element (haystack[0])
     */
    int32_t indexOf(const void* haystack, void* needle, int32_t length, int32_t chunkSize = sizeof(char));

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
}  // namespace libtp::tools