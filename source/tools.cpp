#include "tools.h"

#include <cstdio>
#include <cstring>

#include "display/console.h"
#include "memory.h"
#include "tp/d_com_inf_game.h"
#include "types.h"

namespace libtp::tools
{
    s32 indexOf(const void* haystack, void* needle, s32 length, s32 chunkSize)
    {
        // return, -1 = err
        s32 r = -1;

        // Helper variables
        u32 baseAddress = reinterpret_cast<u32>(haystack);
        s32 numElements = length / chunkSize;

        sprintf(libtp::display::print(17, ""), "Size: %d", sizeof(haystack));

        for (s32 n = 0; n < numElements; n++)
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

    void triggerSaveLoad(char* stage, u8 room, u8 spawn, u8 state, u8 event)
    {
        libtp::tp::d_com_inf_game::GameInfo gameInfo = tp::d_com_inf_game::dComIfG_gameInfo;
        strcpy(gameInfo.nextStageVars.nextStage, stage);
        gameInfo.nextStageVars.nextRoom = room;
        gameInfo.nextStageVars.nextSpawnPoint = spawn;
        gameInfo.nextStageVars.nextState = state;

        gameInfo.eventSystem.nextEventID = event;
        gameInfo.respawnAnimation = 0;
        gameInfo.nextStageVars.isVoidorWarp = 0;
        gameInfo.respawnCutscene = 0;
        gameInfo.eventSystem.immediateControl = 0xFFFF;
        gameInfo.nextStageVars.fadeType = 0x13;

        gameInfo.nextStageVars.triggerLoad = true;
    }
}  // namespace libtp::tools