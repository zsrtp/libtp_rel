#include "tools.h"

#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cinttypes>

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

    int32_t mountMemoryCard( int32_t chan )
    {
        using namespace libtp::gc_wii::card;

        int32_t result;
        uint8_t* workArea;

        // Check if the memory card is valid
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
            // Mount the memory card
            workArea = libtp::tp::m_Do_MemCard::MemCardWorkArea0;
            result = CARDMount( chan, workArea, []( int32_t chan, int32_t result ) {
                // S
                tp::jfw_system::ConsoleLine* line = &tp::jfw_system::systemConsole->consoleLine[JFW_DEBUG_LINE];

                line->showLine = true;
                sprintf( line->line, "ReadGCI::CARDERR; Chan: %" PRId32 " Result: %" PRId32, chan, result );
            } );
        }

        return result;
    }

    int32_t ReadGCIMounted( int32_t chan,
                            const char* fileName,
                            int32_t length,
                            int32_t offset,
                            void* buffer,
                            bool startAfterComments )
    {
        using namespace libtp::gc_wii::card;

        CARDFileInfo fileInfo;
        int32_t result;

        int32_t adjustedOffset;
        int32_t adjustedLength;
        uint8_t* data;

        // Read data
        result = CARDOpen( chan, fileName, &fileInfo );
        if ( result == CARD_RESULT_READY )
        {
            // Adjust the offset if starting after the banner/icon/comments
            if ( startAfterComments )
            {
                CARDStat stat;
                result = CARDGetStatus( chan, fileInfo.fileNo, &stat );

                if ( result != CARD_RESULT_READY )
                {
                    CARDClose( &fileInfo );
                    return result;
                }

                offset += stat.commentAddr + ( CARD_FILENAME_MAX * 2 );
            }

            // Since we can only read in and at increments of CARD_READ_SIZE do this to calculate the region we require
            adjustedOffset = ( offset / CARD_READ_SIZE ) * CARD_READ_SIZE;
            adjustedLength = ( 1 + ( ( offset - adjustedOffset + length - 1 ) / CARD_READ_SIZE ) ) * CARD_READ_SIZE;

            // Buffer might not be adjusted to the new length so create a temporary data buffer
            data = new uint8_t[adjustedLength];

            result = CARDRead( &fileInfo, data, adjustedLength, adjustedOffset );
            if ( result == CARD_RESULT_READY )
            {
                // Copy data to the user's buffer
                memcpy( buffer, data + ( offset - adjustedOffset ), length );
            }

            delete[] data;
            CARDClose( &fileInfo );
        }
        // CARDOpen

        return result;
    }

    int32_t ReadGCI( int32_t chan, const char* fileName, int32_t length, int32_t offset, void* buffer, bool startAfterComments )
    {
        using namespace libtp::gc_wii::card;
        int32_t result;

        result = mountMemoryCard( chan );
        if ( result == CARD_RESULT_READY )
        {
            result = ReadGCIMounted( chan, fileName, length, offset, buffer, startAfterComments );
            CARDUnmount( chan );
        }

        return result;
    }

#else     // PLATFORM_WII

    int32_t ReadNAND( const char* fileName, int32_t length, int32_t offset, void* buffer )
    {
        using namespace libtp::gc_wii::nand;

        NANDFileInfo fileInfo;
        int32_t result;

        int32_t adjustedOffset;
        int32_t adjustedLength;
        uint8_t* data;

        // Read data
        result = NANDOpen( fileName, &fileInfo, NAND_OPEN_READ );
        if ( result == NAND_RESULT_READY )
        {
            result = NANDSeek( &fileInfo, adjustedOffset, NAND_SEEK_START );
            if ( result == NAND_RESULT_READY )
            {
                // Since we can only read in and at increments of NAND_READ_SIZE do this to calculate the region we require
                adjustedOffset = ( offset / NAND_READ_SIZE ) * NAND_READ_SIZE;
                adjustedLength = ( 1 + ( ( offset - adjustedOffset + length - 1 ) / NAND_READ_SIZE ) ) * NAND_READ_SIZE;

                // Buffer might not be adjusted to the new length so create a temporary data buffer
                data = new uint8_t[adjustedLength];

                int32_t r = NANDRead( &fileInfo, data, adjustedLength );
                result = ( r > 0 ) ? NAND_RESULT_READY : r;

                if ( result == NAND_RESULT_READY )
                {
                    // Copy data to the user's buffer
                    memcpy( buffer, data + ( offset - adjustedOffset ), length );
                }

                delete[] data;
            }
            NANDClose( &fileInfo );
        }
        // NANDOpen

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