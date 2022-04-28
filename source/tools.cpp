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
#include "data/stages.h"
#include "display/console.h"
#include "gc_wii/card.h"
#include "memory.h"
#include "tp/JFWSystem.h"
#include "tp/d_com_inf_game.h"
#include "tp/d_stage.h"
#include "tp/dzx.h"
#include "tp/f_op_actor_mng.h"

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

    // This entire function will need to be re-looked at now that a lot of defintions are different. UPDATE: should be better.
    // updated data types in libtp
    void TriggerSaveLoad( const char* stage, uint8_t room, uint8_t spawn, uint8_t state, uint8_t event )
    {
        using namespace libtp::tp::d_com_inf_game;

        dComIfG_inf_c* gameInfo = &dComIfG_gameInfo;
        strcpy( gameInfo->play.mNextStage.stageValues.mStage, stage );
        gameInfo->play.mNextStage.stageValues.mRoomNo = room;
        gameInfo->play.mNextStage.stageValues.mPoint = spawn;
        gameInfo->play.mNextStage.stageValues.mLayer = state;

        gameInfo->play.mEvent.mOrder[0].mEventInfoIdx = event;
        gameInfo->save.restart.mLastMode = 0;
        gameInfo->play.mNextStage.stageValues.mPoint = 0;
        gameInfo->save.restart.mRoomParam = 0;
        gameInfo->play.mEvent.mOrder[0].mEventId = 0xFFFF;     // immediateControl
        gameInfo->play.mNextStage.wipe_speed = 0x13;

        gameInfo->play.mNextStage.wipe = true;
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

    void SpawnSCOB( uint8_t roomID, tp::dzx::SCOB& actor_data )
    {
        using namespace libtp::tp::dzx;
        using namespace libtp::tp::f_op_actor_mng;

        ActorPRMClass* actorMemoryPtr = CreateAppend();

        actorMemoryPtr->params = actor_data.parameters;

        actorMemoryPtr->pos[0] = actor_data.pos[0];
        actorMemoryPtr->pos[1] = actor_data.pos[1];
        actorMemoryPtr->pos[2] = actor_data.pos[2];

        actorMemoryPtr->xRot = actor_data.rot[0];
        actorMemoryPtr->yRot = actor_data.rot[1];

        actorMemoryPtr->flag = actor_data.flag;
        actorMemoryPtr->enemy_id = actor_data.enemyID;
        actorMemoryPtr->room_id = roomID;
        actorMemoryPtr->mScale[0] = actor_data.xScale;
        actorMemoryPtr->mScale[1] = actor_data.yScale;
        actorMemoryPtr->mScale[2] = actor_data.zScale;

        tp::d_stage::ActorCreate( &actor_data, actorMemoryPtr );
    }
#ifndef PLATFORM_WII
    int32_t ReadGCI( int32_t chan, const char* fileName, int32_t length, int32_t offset, void* buffer )
    {
        using namespace libtp::gc_wii::card;

        CARDFileInfo* fileInfo = new CARDFileInfo();
        uint8_t* workArea = new uint8_t[CARD_WORKAREA_SIZE];
        int32_t result;

        // Since we can only read in and at increments of CARD_READ_SIZE do this to calculate the region we require

        int32_t adjustedOffset = ( offset / CARD_READ_SIZE ) * CARD_READ_SIZE;
        int32_t adjustedLength = ( 1 + ( ( offset - adjustedOffset + length - 1 ) / CARD_READ_SIZE ) ) * CARD_READ_SIZE;

        // Buffer might not be adjusted to the new length so create a temporary data buffer
        uint8_t* data = new uint8_t[adjustedLength];

        // Check if card is valid
        result = checkForMemoryCard( chan );
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
                result = CARDOpen( chan, const_cast<char*>( fileName ), fileInfo );

                if ( result == CARD_RESULT_READY )
                {
                    result = CARDRead( fileInfo, data, adjustedLength, adjustedOffset );
                    CARDClose( fileInfo );

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
        delete fileInfo;
        delete[] workArea;
        delete[] data;

        return result;
    }
#else
    int32_t ReadNAND( const char* fileName, int32_t length, int32_t offset, void* buffer )
    {
        using namespace libtp::gc_wii::nand;

        NANDFileInfo fileInfo;
        int32_t result = NAND_RESULT_READY;

        // Since we can only read in and at increments of NAND_READ_SIZE do this to calculate the region we require

        int32_t adjustedOffset = ( offset / NAND_READ_SIZE ) * NAND_READ_SIZE;
        int32_t adjustedLength = ( 1 + ( ( offset - adjustedOffset + length - 1 ) / NAND_READ_SIZE ) ) * NAND_READ_SIZE;

        // Buffer might not be adjusted to the new length so create a temporary data buffer
        uint8_t* data = new uint8_t[adjustedLength];

        memset( buffer, 0, length );
        memset( data, 0, adjustedLength );

        // Read data
        result = NANDOpen( const_cast<char*>( fileName ), &fileInfo, NAND_OPEN_READ );

        if ( result == NAND_RESULT_READY )
        {
            // result = storage_read( &fileInfo, data, adjustedLength, adjustedOffset, NAND_OPEN_READ );
            result = NANDSeek( &fileInfo, adjustedOffset, NAND_SEEK_START );
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
#endif
    uint32_t getRandom( uint64_t* seed, uint32_t max )
    {
        uint64_t z = ( *seed += 0x9e3779b97f4a7c15 );
        z = ( z ^ ( z >> 30 ) ) * 0xbf58476d1ce4e5b9;
        z = ( z ^ ( z >> 27 ) ) * 0x94d049bb133111eb;

        return ( z % max );
    }

    int32_t checkForMemoryCard( int32_t chan )
    {
        int32_t ret;
        for ( uint32_t i = 0; i < 1000000; i++ )
        {
            ret = gc_wii::card::CARDProbeEx( chan, nullptr, nullptr );
            if ( ret != CARD_RESULT_BUSY )
            {
                break;
            }
        }
        return ret;
    }

    int32_t getStageIndex( const char* stage )
    {
        // Find the index of this stage
        for ( uint32_t stageIDX = 0; stageIDX < sizeof( data::stage::allStages ) / sizeof( data::stage::allStages[0] );
              stageIDX++ )
        {
            if ( strcmp( stage, libtp::data::stage::allStages[stageIDX] ) == 0 )
            {
                return static_cast<int32_t>( stageIDX );
            }
        }

        // Did not find a valid stage
        return -1;
    }
}     // namespace libtp::tools