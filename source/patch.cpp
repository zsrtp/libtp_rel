#include "patch.h"

#include <cstdint>

#include "memory.h"

namespace libtp::patch
{
    void writeBranch(void* ptr, void* destination)
    {
        uint32_t branch = 0x48000000; // b
        writeBranchMain(ptr, destination, branch);
    }

    void writeBranchBL(void* ptr, void* destination)
    {
        uint32_t branch = 0x48000001; // bl
        writeBranchMain(ptr, destination, branch);
    }

    void writeBranchMain(void* ptr, void* destination, uint32_t branch)
    {
        uint32_t delta = reinterpret_cast<uint32_t>(destination) - reinterpret_cast<uint32_t>(ptr);

        branch |= (delta & 0x03FFFFFC);

        uint32_t* p = reinterpret_cast<uint32_t*>(ptr);
        *p = branch;

        memory::clear_DC_IC_Cache(ptr, sizeof(uint32_t));
    }

    void writeStandardBranches(void* ptr, void* funcStart, void* funcEnd)
    {
        // Write the main branch
        writeBranch(ptr, funcStart);

        // Write the returning branch
        writeBranch(funcEnd, reinterpret_cast<void*>(reinterpret_cast<uint32_t>(ptr) + 0x4));
    }
} // namespace libtp::patch