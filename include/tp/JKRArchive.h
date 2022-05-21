#ifndef TP_JKRARCHIVE_H
#define TP_JKRARCHIVE_H

#include <cstdint>

namespace libtp::tp::JKRArchive
{
    extern "C"
    {
        void* JKRArchive_getResource2( void* JKRArchive, uint32_t type, const char* file );
    }
}     // namespace libtp::tp::JKRArchive
#endif