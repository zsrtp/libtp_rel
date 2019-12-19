/**	@file OSCache.h
 *	@brief Holds OSCache definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */

#pragma once

#include "types.h"

namespace libtp::gc::os_cache {
  extern "C" {
  // DCEnable
  // DCInvalidateRange
  void DCFlushRange(void* startAddr, u32 nBytes);
  // DCStoreRange
  // DCFlushRangeNoSync
  // DCStoreRangeNoSync
  // DCZeroRange
  void ICInvalidateRange(void* startAddr, u32 nBytes);
  // ICFlashInvalidate
  // ICEnable
  // __LCEnable
  // LCEnable
  // LCDisable
  // LCStoreBlocks
  // LCStoreData
  // LCQueueWait
  // L2GlobalInvalidate
  // DMAErrorHandler
  // __OSCacheInit
  }
}