#pragma once

#include <cstddef>
#include <cstdint>
namespace libtp::memory
{
    extern "C"
    {
        void* clearMemory(void* ptr, size_t size);
        void clear_DC_IC_Cache(void* ptr, uint32_t size);
    }
}  // namespace libtp::memory