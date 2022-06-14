#ifndef TP_JKRARCHIVEPUB_H
#define TP_JKRARCHIVEPUB_H

#include <cstdint>

namespace libtp::tp::JKRArchivePub
{
    extern "C"
    {
        // Passing in nullptr for JKRArchive will search through all archives for the file
        void* JKRArchivePub_getGlbResource( uint32_t tag, const char* file, void* JKRArchive );
    }
}     // namespace libtp::tp::JKRArchivePub
#endif