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
         *  @param sfxID The ID of the sound effect to be played.
         *  @param i_sePos Unknown.
         *  @param unk5 Unknown.
         *  @param i_reverb Unknown.
         */
        void JAISeMgr_start_ID(void* JAISeMgr, libtp::z2audiolib::z2scenemgr::JAISoundID soundID, void* param_2, void* param_3);
    }
} // namespace libtp::tp::JAudio2
#endif