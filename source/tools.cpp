#include "tools.h"

#include <cstdint>
#include <cstdio>
#include <cstring>

#include "display/console.h"
#include "memory.h"
#include "tp/d_com_inf_game.h"

namespace libtp::tools
{
    int32_t indexOf(const void* haystack, void* needle, int32_t length, int32_t chunkSize)
    {
        // return, -1 = err
        int32_t r = -1;

        // Helper variables
        uint32_t baseAddress = reinterpret_cast<uint32_t>(haystack);
        int32_t numElements = length / chunkSize;

        sprintf(libtp::display::print(17, ""), "Size: %d", sizeof(haystack));

        for (int32_t n = 0; n < numElements; n++)
        {
            // Compare n'th element of haystack with needle
            if (!memcmp(reinterpret_cast<void*>(baseAddress + n * chunkSize), needle, chunkSize))
            {
                r = n;
                break;
            }
        }
        return r;
    }

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