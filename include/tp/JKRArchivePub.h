/**	@file JKRArchivePub.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_JKRARCHIVEPUB_H
#define TP_JKRARCHIVEPUB_H

#include <cstdint>

namespace libtp::tp::JKRArchivePub
{
    extern "C"
    {
        /**
         *	@brief Retrieves the specified resource from an archive.
         *
         *  @param tag The tag of the resource to be used.
         *  @param file The name of the file
         *  @param JKRArchive A pointer to the JKR Archive to search.
         */
        // Passing in nullptr for JKRArchive will search through all archives for the file
        void* JKRArchivePub_getGlbResource(uint32_t tag, const char* file, void* JKRArchive);
    }
} // namespace libtp::tp::JKRArchivePub
#endif