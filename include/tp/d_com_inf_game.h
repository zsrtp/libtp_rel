/**	@file d_com_inf_game.h
 *	@brief Holds general game information
 *
 *	d_com_inf_game is one of the most crucial fields
 *	with various data about the current game state
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "evt_control.h"
#include <cstdint>

namespace libtp::tp::d_com_inf_game
{
    /**
     *	@brief Holds 1:1 save-file data
     *
     *	@todo Fill missing vars.
     *	@todo Make bitfields actual bitwise variables for easier access.
     *(https://en.cppreference.com/w/cpp/language/bit_field)
     */
    struct ScratchPad
    {
        uint8_t wQuestLogData[0x7F0];
        uint8_t eventBits[0x150];    // Bitfield (QuestLogOffset - 7F0)
        uint8_t miniGameBits[0x18];  // Bitfield
    } __attribute__((__packed__));

    /**
     *	@brief Holds information about the current stage
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct CurrentStageVars
    {
        char currentStage[8];
        int16_t currentSpawnPoint;
        uint8_t unknown[4];
    } __attribute__((__packed__));

    /**
     *	@brief Holds information about the next stage
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct NextStageVars
    {
        char nextStage[8];
        uint8_t isVoidorWarp;
        uint8_t nextSpawnPoint;
        uint8_t nextRoom;
        uint8_t nextState;
        uint8_t unk1;
        uint8_t unk2;
        uint8_t triggerLoad;
        uint8_t fadeType;
    } __attribute__((__packed__));

    /**
     *	@brief Cutscene and event control system
     *
     *	@todo Fill missing vars.
     */
    struct EventSystem
    {
        uint8_t unk00[0x13];
        uint16_t immediateControl;
        uint8_t unk_00[0x4];
        uint8_t nextEventID;
        uint8_t unk1A[0xD1];
        uint8_t currentEventID;
        uint8_t unk_ec[0x14];
        libtp::tp::evt_control::csSkipFunction* onSkip;  // This will run when trying to skip; if null it's unskippable
        uint8_t unk_104[0xC];
        uint32_t fadeOnSkip;  // If > 0 the screen will fade when skipping
    } __attribute__((__packed__));

    /**
     *	@brief Holds data about Links position on the current map
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct LinkMapVars
    {
        uint8_t unk_0[0x4D0];
        float pos[3];
    } __attribute__((__packed__));

    /**
     *	@brief GameInfo Structure holding general and most crucial game
     *information
     *
     *	@todo Fill missing vars
     */
    struct GameInfo
    {
        ScratchPad scratchPad;        // 0 - 957
        uint8_t localAreaNodes[0x20];      // 958 - 977 holds flags about the current area
        uint8_t unk_978[0x450];            // 978 - DC7
        uint8_t respawnCutscene;           // DC8 - DC8
        uint8_t unkdc9[0xA];               // dc9 - dd2
        uint8_t respawnAnimation;          // dd3 - dd3
        uint8_t unkdd4[0x402C];            // dd4 - 4DFF
        char currentStage[8];         // 4E00 - 4E07
        uint8_t unk_4e08[6];               // 4E08 - 4E0D
        NextStageVars nextStageVars;  // 4E0E - 4E1b
        uint8_t unk_4e1c[0xAA];            // 4E19 - 4EC7
        EventSystem eventSystem;      // 4EC8 - 4FDE
        uint8_t unk_4fdd[0xDD0];           // 4FDD - 5DBF
        LinkMapVars* linkMapPtr;      // 5DA0 - 5DAB
        uint8_t unk_5dac[0x18060];
    } __attribute__((__packed__));
    static_assert(sizeof(ScratchPad) == 0x958);
    static_assert(sizeof(GameInfo) == 0x1DE10);

    extern "C"
    {
        extern GameInfo dComIfG_gameInfo;
    }
}  // namespace libtp::tp::d_com_inf_game