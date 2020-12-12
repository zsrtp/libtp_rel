#include "tools.h"

#include <cstdint>
#include <cstdio>
#include <cstring>

#include "display/console.h"
#include "memory.h"
#include "tp/d_com_inf_game.h"

namespace libtp::tools
{
    void triggerSaveLoad(const char* stage, uint8_t room, uint8_t spawn, uint8_t state, uint8_t event)
    {
        libtp::tp::d_com_inf_game::GameInfo* gameInfo = &tp::d_com_inf_game::dComIfG_gameInfo;
        strcpy(gameInfo->nextStageVars.nextStage, stage);
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
}  // namespace libtp::tools