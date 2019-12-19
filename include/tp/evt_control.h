/**	@file evt_control.h
 *	@brief Holds members event & cutscene control field
 *
 *	@author AECX
 *	@author dragonbane0
 *	@bug No known bugs.
 */

#pragma once

#include "types.h"

namespace libtp::tp::evt_control {
  /**
   *	@brief A function that runs when a cutscene skip is performed
   *
   *	@param unk Unknown pointer
   *	@param unk2 Unknown integer
   *	@return Unknown use.
   */
  typedef s32(csSkipFunction)(void* unk, s32 unk2);
  extern "C" {
  /**
   *	@brief Runs when attempting to skip a function
   *
   *	@param eventPtr Current event
   *	@return Unknown use.
   */
  s32 skipper(void* eventPtr);

  csSkipFunction defaultSkipStb;
  }
}