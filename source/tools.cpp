#include "tools.h"

#include <cstdio>
#include <cstring>

#include "display/console.h"
#include "memory.h"
#include "types.h"

namespace libtp::tools
{
    s32 indexOf(const void* haystack, void* needle, s32 length, s32 chunkSize)
    {
        // return, -1 = err
        s32 r = -1;

        // Helper variables
        u32 baseAddress = reinterpret_cast<u32>(haystack);
        s32 numElements = length / chunkSize;

        sprintf(libtp::display::print(17, ""), "Size: %d", sizeof(haystack));

        for (s32 n = 0; n < numElements; n++)
        {
            // Compare n'th element of haystack with needle
            if (!memcmp(reinterpret_cast<void*>(baseAddress + n * chunkSize), needle, chunkSize))
            {
                r = n;
                break;
            }
        }

        return r;
    }
}  // namespace libtp::tools