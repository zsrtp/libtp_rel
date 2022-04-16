#include "tools.h"

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>

#ifndef PLATFORM_WII

#include "gc_wii/card.h"

#else

#include "cxx.h"
#include "gc_wii/nand.h"

#endif

#include "display/console.h"
#include "memory.h"
#include "tp/JFWSystem.h"
#include "tp/d_com_inf_game.h"
#include "tp/d_stage.h"
#include "tp/dzx.h"
#include "tp/f_op_actor_mng.h"
#include "tp/m_do_memcard.h"

namespace libtp::tools
{
    uint16_t fletcher16( uint8_t* data, int32_t length )
    {
        uint16_t sum1 = 0;
        uint16_t sum2 = 0;

        for ( int32_t index = 0; index < length; ++index )
        {
            sum1 = ( sum1 + data[index] ) % 0xFF;
            sum2 = ( sum2 + sum1 ) % 0xFF;
        }

        return ( sum2 << 8 ) | sum1;
    }

    void TriggerSaveLoad( const char* stage, uint8_t room, uint8_t spawn, uint8_t state, uint8_t event )
    {
        using namespace libtp::tp::d_com_inf_game;

        GameInfo* gameInfo = &dComIfG_gameInfo;
        strcpy( gameInfo->nextStageVars.nextStage, stage );
        gameInfo->nextStageVars.nextRoom = room;
        gameInfo->nextStageVars.nextSpawnPoint = spawn;
        gameInfo->nextStageVars.nextState = state;

        gameInfo->eventSystem.nextEventID = event;
        gameInfo->respawnAnimation = 0;
        gameInfo->nextStageVars.isVoidorWarp = 0;
        gameInfo->respawnCutscene = 0;
        gameInfo->eventSystem.immediateControl = 0xFFFF;
        gameInfo->nextStageVars.fadeType = 0x13;

        gameInfo->nextStageVars.triggerLoad = true;
    }

    void SpawnActor( uint8_t roomID, tp::dzx::ACTR& actor )
    {
        using namespace libtp::tp::dzx;
        using namespace libtp::tp::f_op_actor_mng;

        ActorPRMClass* actorMemoryPtr = CreateAppend();

        actorMemoryPtr->params = actor.parameters;

        actorMemoryPtr->pos[0] = actor.pos[0];
        actorMemoryPtr->pos[1] = actor.pos[1];
        actorMemoryPtr->pos[2] = actor.pos[2];

        actorMemoryPtr->xRot = actor.rot[0];
        actorMemoryPtr->yRot = actor.rot[1];

        actorMemoryPtr->flag = actor.flag;
        actorMemoryPtr->enemy_id = actor.enemyID;
        actorMemoryPtr->room_id = roomID;

        tp::d_stage::ActorCreate( &actor, actorMemoryPtr );
    }

#ifndef PLATFORM_WII

    int32_t ReadGCI( int32_t chan, const char* fileName, int32_t length, int32_t offset, void* buffer )
    {
        using namespace libtp::gc_wii::card;

        CARDFileInfo fileInfo;
        uint8_t* workArea = libtp::tp::m_Do_MemCard::MemCardWorkArea0;
        int32_t result;

        // Since we can only read in and at increments of CARD_READ_SIZE do this to calculate the region we require

        int32_t adjustedOffset = ( offset / CARD_READ_SIZE ) * CARD_READ_SIZE;
        int32_t adjustedLength = ( 1 + ( ( offset - adjustedOffset + length - 1 ) / CARD_READ_SIZE ) ) * CARD_READ_SIZE;

        // Buffer might not be adjusted to the new length so create a temporary data buffer
        uint8_t* data = new uint8_t[adjustedLength];

        // Check if card is valid
        for ( uint32_t i = 0; i < 1000000; i++ )
        {
            result = CARDProbeEx( chan, NULL, NULL );
            if ( result != CARD_RESULT_BUSY )
            {
                break;
            }
        }

        if ( result == CARD_RESULT_READY )
        {
            result = CARDMount( chan,
                                workArea,
                                []( int32_t chan, int32_t result )
                                {
                                    // S
                                    tp::jfw_system::ConsoleLine* line =
                                        &tp::jfw_system::systemConsole->consoleLine[JFW_DEBUG_LINE];

                                    line->showLine = true;
                                    sprintf( line->line, "ReadGCI::CARDERR; Chan: %" PRId32 " Result: %" PRId32, chan, result );
                                } );

            if ( result == CARD_RESULT_READY )
            {
                // Read data
                result = CARDOpen( chan, const_cast<char*>( fileName ), &fileInfo );

                if ( result == CARD_RESULT_READY )
                {
                    result = CARDRead( &fileInfo, data, adjustedLength, adjustedOffset );
                    CARDClose( &fileInfo );

                    // Copy data to the user's buffer
                    memcpy( buffer, data + ( offset - adjustedOffset ), length );
                }
                // CARDOpen
                CARDUnmount( chan );
            }
            // CARDMount
        }
        // CARDProbeEx

        // Clean up
        delete[] data;

        return result;
    }

#else     // PLATFORM_WII

    int32_t ReadNAND( const char* fileName, int32_t length, int32_t offset, void* buffer )
    {
        using namespace libtp::gc_wii::nand;

        NANDFileInfo fileInfo;
        int32_t result = NAND_RESULT_READY;

        // Since we can only read in and at increments of NAND_READ_SIZE do this to calculate the region we require

        int32_t adjustedOffset = ( offset / NAND_READ_SIZE ) * NAND_READ_SIZE;
        int32_t adjustedLength = ( 1 + ( ( offset - adjustedOffset + length - 1 ) / NAND_READ_SIZE ) ) * NAND_READ_SIZE;

        // Buffer might not be adjusted to the new length so create a temporary data buffer
        uint8_t* data = new ( 0x20 ) uint8_t[adjustedLength];

        memset( buffer, 0, length );
        memset( data, 0, adjustedLength );

        // Read data
        result = NANDOpen( const_cast<char*>( fileName ), &fileInfo, NAND_OPEN_READ );

        if ( result == NAND_RESULT_READY )
        {
            // result = storage_read( &fileInfo, data, adjustedLength, adjustedOffset, NAND_OPEN_READ );
            result = NANDSeek( &fileInfo, adjustedOffset, 0 );
            if ( result == NAND_RESULT_READY )
            {
                int32_t r = NANDRead( &fileInfo, data, adjustedLength );
                result = ( r > 0 ) ? NAND_RESULT_READY : r;
            }
            NANDClose( &fileInfo );

            // Copy data to the user's buffer
            memcpy( buffer, data + ( offset - adjustedOffset ), length );
        }
        // NANDOpen

        // Clean up
        delete[] data;

        return result;
    }

#endif     // PLATFORM_WII

    uint32_t getRandom( uint64_t* seed, uint32_t max )
    {
        uint64_t z = ( *seed += 0x9e3779b97f4a7c15 );
        z = ( z ^ ( z >> 30 ) ) * 0xbf58476d1ce4e5b9;
        z = ( z ^ ( z >> 27 ) ) * 0x94d049bb133111eb;

        return ( z % max );
    }
}     // namespace libtp::tools