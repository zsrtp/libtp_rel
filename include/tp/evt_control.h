/**	@file evt_control.h
 *	@brief Holds members event & cutscene control field
 *
 *	@author AECX
 *	@author dragonbane0
 *	@bug No known bugs.
 */
#ifndef TP_EVT_CONTROL_H
#define TP_EVT_CONTROL_H

#include <cstdint>

namespace libtp::tp::evt_control
{
    /**
     *	@brief A function that runs when a cutscene skip is performed
     *
     *	@param unk Unknown pointer
     *	@param unk2 Unknown integer
     *	@return Unknown use.
     */
    typedef int32_t(csSkipFunction)(void* unk, int32_t unk2);
    extern "C"
    {
        int32_t defaultSkipStb(void* unk, int32_t unk2);

        csSkipFunction defaultSkipStb;
    }
} // namespace libtp::tp::evt_control
#endif