/**	@file m_do_audio.h
 *	@brief Holds function definitions for audio calls
 *
 *	@author Lunar Soap
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_AUDIO_H
#define TP_M_DO_AUDIO_H

#include "dolphin/mtx/vec.h"

#include <cstdint>

namespace libtp::tp::m_Do_Audio
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
        void mDoAud_seStartLevel(uint32_t sfxID, const Vec* i_sePos, uint32_t unk5, int8_t i_reverb);

        /**
         * @brief WIP
         * 
         *  @param sfxID The ID of the sound effect to be played.
         *  @param i_sePos Unknown.
         *  @param unk5 Unknown.
         *  @param i_reverb Unknown.
         */
        void mDoAud_seStart(uint32_t sfxID, const Vec* i_sePos, uint32_t unk5, int8_t i_reverb);
    }
} // namespace libtp::tp::m_Do_Audio
#endif
