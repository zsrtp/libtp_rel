/**	@file JAISe.h
 *	@brief Holds function definitions for audio sound effects
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_JAISE_H
#define TP_JAISE_H

#include "Z2AudioLib/Z2SceneMgr.h"

#include <cstdint>

namespace libtp::tp::JAudio2
{
    extern "C"
    {
        /**
         *	@brief Plays the specified audio sound effect.
         *
         *  @param JAISeMge Pointer to the sound effect manager
         *  @param soundID The ID of the sound being played
         *  @param param_2 Unknown.
         *  @param param_3 Unknown.
         */
        void JAISeMgr_start_ID(void* JAISeMgr, libtp::z2audiolib::z2scenemgr::JAISoundID soundID, void* param_2, void* param_3);
    }
} // namespace libtp::tp::JAudio2
#endif