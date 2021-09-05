/**	@file OSCache.h
 *	@brief Holds OSCache definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef GC_WII_OSCACHE_H
#define GC_WII_OSCACHE_H

#include <cstdint>

namespace libtp::gc_wii::os_cache
{
    extern "C"
    {
        // DCEnable
        // DCInvalidateRange
        void DCFlushRange( void* startAddr, uint32_t nBytes );
        // DCStoreRange
        // DCFlushRangeNoSync
        // DCStoreRangeNoSync
        // DCZeroRange
        void ICInvalidateRange( void* startAddr, uint32_t nBytes );
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
}     // namespace libtp::gc_wii::os_cache
#endif