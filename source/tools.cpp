#include "tools.h"

#include <cinttypes>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "display/console.h"
#include "gc/card.h"
#include "memory.h"
#include "tp/d_com_inf_game.h"
#include "tp/d_stage.h"
#include "tp/dzx.h"
#include "tp/f_op_actor_mng.h"

namespace libtp::tools
{
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

    int32_t ReadGCI( int32_t chan, const char* fileName, int32_t length, int32_t offset, uint8_t* buffer )
    {
        using namespace libtp::gc::card;

        // Helper variable
        // uint8_t level = 0;

        // Must use at least once before using any of the CARD functions
        CARDInit();

        CARDFileInfo* fileInfo = new CARDFileInfo();
        uint8_t* workArea = new uint8_t[CARD_WORKAREA_SIZE];
        int32_t result;

        // Check if card is valid
        result = CARDProbeEx( chan, NULL, NULL );

        if ( result == CARD_RESULT_READY )
        {
            // level = 1;
            result = CARDMount( chan, workArea, []( int32_t chan, int32_t result ) {
                // TODO: Handler for cardDetach
            } );

            if ( result == CARD_RESULT_READY )
            {
                // level = 2;
                // Read data
                result = CARDOpen( chan, const_cast<char*>( fileName ), fileInfo );

                if ( result == CARD_RESULT_READY )
                {
                    // level = 3;
                    result = CARDRead( fileInfo, buffer, length, offset );

                    CARDClose( fileInfo );
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

        return result;
    }
}     // namespace libtp::tools