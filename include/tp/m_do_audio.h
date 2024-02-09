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

#ifdef PLATFORM_WII
#include "Z2AudioLib/Z2AudioMgr.h"
#endif

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
#ifndef PLATFORM_WII
        void mDoAud_seStartLevel(uint32_t sfxID, const Vec* i_sePos, uint32_t unk5, int8_t i_reverb);
#else
        inline void mDoAud_seStartLevel(uint32_t sfxID, const Vec* i_sePos, uint32_t unk5, int8_t i_reverb)
        {
            libtp::z2audiolib::z2semgr::z2SeMgr_seStartLevel(sfxID, i_sePos, unk5, i_reverb, 1.0f, 1.0f, -1.0f, -1.0f, 0);
        }
#endif
    }
} // namespace libtp::tp::m_Do_Audio
#endif