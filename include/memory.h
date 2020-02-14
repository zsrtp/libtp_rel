#pragma once

#include <cstddef>

#include "types.h"
namespace libtp::memory
{
    extern "C"
    {
        void* clearMemory(void* ptr, size_t size);
        void clear_DC_IC_Cache(void* ptr, u32 size);
    }
}  // namespace libtp::memory