#include "tools.h"

#include <cstring>

#include "types.h"

namespace libtp::tools
{
    s32 indexOf(void** arr, void* data, s32 chunkSize)
    {
        s32 i = -1;
        while (memcmp(arr[i], data, chunkSize))
        {
            i++;
        }
        return i;
    }
}  // namespace libtp::tools