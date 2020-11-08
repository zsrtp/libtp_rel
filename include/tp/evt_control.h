/**	@file evt_control.h
 *	@brief Holds members event & cutscene control field
 *
 *	@author AECX
 *	@author dragonbane0
 *	@bug No known bugs.
 */

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
        /**
         *	@brief Runs when attempting to skip a function
         *
         *	@param eventPtr Current event
         *	@return Unknown use.
         */
        int32_t skipper(void* eventPtr);

        int32_t defaultSkipStb(void* unk, int32_t unk2);

        csSkipFunction defaultSkipStb;
    }
}  // namespace libtp::tp::evt_control