/**	@file card.h
 *	@brief The CARD API provides file level access to memory cards.
 *
 *	Refer to the dolphin OS Reference Manual for further information
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_PROCESSOR_H
#define TP_PROCESSOR_H

#include <cstdint>

namespace libtp::tp::processor
{
    extern "C"
    {
        /**
         *	@brief Gets a pointer to the current message resource being utilized
         *
         *  @param TProcessor A pointer to the current TProccesor
         *  @param unk2 Unkown.
         *
         *  @return Returns a pointer to the currently loaded resource, if valid. Returns a nullptr otherwise.
         */
        void* getResource_groupID(const void* TProcessor, uint16_t unk2);
    }
} // namespace libtp::tp::processor
#endif