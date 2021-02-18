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

#include "tp/dzx.h"

namespace libtp::tools
{
    /**
     *  @brief Savely loads a given stage-room-spawnpoint-state and event combination
     *
     *  @param stage 8 char stage ID
     *  @param room Room ID
     *  @param spawn Spawnpoint
     *  @param state Current State (Link)
     *  @param event EventID to trigger
     */
    void triggerSaveLoad( const char* stage, uint8_t room, uint8_t spawn, uint8_t state = 0xFF, uint8_t event = 0xFF );

    /**
     *  @brief Spawns an actor
     *
     *  @param roomID Room id to spawn the actor
     *  @param actor The actor object to be spawned
     */
    void SpawnActor( uint8_t roomID, tp::dzx::ACTR& actor );
}     // namespace libtp::tools