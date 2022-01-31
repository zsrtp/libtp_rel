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
        void* getResource_groupID( const void* TProcessor, uint16_t unk2 );
    }
}     // namespace libtp::tp::processor
#endif