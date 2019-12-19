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

#include "../types.h"
#include "evt_control.h"

namespace libtp::tp::d_com_inf_game {
  /**
   *	@brief Holds 1:1 save-file data
   *
   *	@todo Fill missing vars.
   *	@todo Make bitfields actual bitwise variables for easier access.
   *(https://en.cppreference.com/w/cpp/language/bit_field)
   */
  struct ScratchPad {
    u8 wQuestLogData[0x7F0];
    u8 eventBits[0x150];    // Bitfield (QuestLogOffset - 7F0)
    u8 miniGameBits[0x18];  // Bitfield
  } __attribute__((__packed__));

  /**
   *	@brief Holds information about the current stage
   *
   *	@todo Fill missing vars.
   *	@todo Get exact size.
   */
  struct CurrentStageVars {
    char currentStage[8];
    s16 currentSpawnPoint;
    u8 unknown[4];
  } __attribute__((__packed__));

  /**
   *	@brief Holds information about the next stage
   *
   *	@todo Fill missing vars.
   *	@todo Get exact size.
   */
  struct NextStageVars {
    char nextStage[8];
    u8 isVoidorWarp;
    u8 nextSpawnPoint;
    u8 nextRoom;
    u8 nextState;
    u8 unk1;
    u8 unk2;
    u8 triggerLoad;
    u8 fadeType;
  } __attribute__((__packed__));

  /**
   *	@brief Cutscene and event control system
   *
   *	@todo Fill missing vars.
   */
  struct EventSystem {
    u8 unk00[0x13];
    u16 immediateControl;
    u8 unk_00[0x4];
    u8 nextEventID;
    u8 unk1A[0xD1];
    u8 currentEventID;
    u8 unk_ec[0x14];
    libtp::tp::evt_control::csSkipFunction*
        onSkip;  // This will run when trying to skip; if null it's unskippable
    u8 unk_104[0xC];
    u32 fadeOnSkip;  // If > 0 the screen will fade when skipping
  } __attribute__((__packed__));

  /**
   *	@brief Holds data about Links position on the current map
   *
   *	@todo Fill missing vars.
   *	@todo Get exact size.
   */
  struct LinkMapVars {
    u8 unk_0[0x4D0];
    float pos[3];
  } __attribute__((__packed__));

  /**
   *	@brief GameInfo Structure holding general and most crucial game
   *information
   *
   *	@todo Fill missing vars
   */
  struct GameInfo {
    ScratchPad scratchPad;        // 0 - 957
    u8 unk_958[0x470];            // 958 - DC7
    u8 respawnCutscene;           // DC8 - DC8
    u8 unkdc9[0xA];               // dc9 - dd2
    u8 respawnAnimation;          // dd3 - dd3
    u8 unkdd4[0x402C];            // dd4 - 4DFF
    char currentStage[8];         // 4E00 - 4E07
    u8 unk_4e08[6];               // 4E08 - 4E0D
    NextStageVars nextStageVars;  // 4E0E - 4E1b
    u8 unk_4e1c[0xAA];            // 4E19 - 4EC7
    EventSystem eventSystem;      // 4EC8 - 4FDE
    u8 unk_4fdd[0xDD0];           // 4FDD - 5DBF
    LinkMapVars* linkMapPtr;      // 5DA0 - 5DAB
    u8 unk_5dac[0x18060];
  } __attribute__((__packed__));
  static_assert(sizeof(ScratchPad) == 0x958);
  static_assert(sizeof(GameInfo) == 0x1DE10);

  extern "C" {
  extern GameInfo dComIfG_gameInfo;
  }
}