/**	@file d_item.h
 *	@brief Holds item specific functions and vars
 *
 *	@author AECX
 *	@bug
 */

#pragma once

#include "../types.h"

namespace libtp::tp::d_item {
  extern "C" {
  /**
   *	@brief Unknown
   *
   *	@param item Item id to check (?)
   *	@param defaultValue Default if unsuccessful
   *
   *	@return Probably(!) the correct item id to use (for progressive items
   *like clawshot)
   */
  s32 checkItemGet(u8 item, s32 defaultValue);
  }
}