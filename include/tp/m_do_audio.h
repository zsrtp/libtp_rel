/**	@file m_do_audio.h
 *	@brief Holds function definitions for audio calls
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_AUDIO_H
#define TP_M_DO_AUDIO_H

#include <cstdint>

#include "dolphin/mtx/vec.h"

namespace libtp::tp::m_Do_Audio
{
    extern "C"
    {
        /**
         *	@brief Plays the specified audio sound effect.
         *
         *  @param sfxID The ID of the sound effect to be played.
         *  @param unk4 Unknown.
         *  @param unk5 Unknown.
         *  @param unk6 Unknown.
         */
        void mDoAud_seStartLevel( uint32_t sfxID, const Vec* unk4, uint32_t unk5, int8_t unk6 );
    }
}     // namespace libtp::tp::m_Do_Audio
#endif