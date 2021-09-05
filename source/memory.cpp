
#include "memory.h"

#include <cstring>

#include "gc_wii/OSCache.h"

namespace libtp::memory
{
    void* clearMemory( void* ptr, size_t size ) { return memset( ptr, 0, size ); }

    void clear_DC_IC_Cache( void* ptr, uint32_t size )
    {
        gc_wii::os_cache::DCFlushRange( ptr, size );
        gc_wii::os_cache::ICInvalidateRange( ptr, size );
    }
}     // namespace libtp::memory