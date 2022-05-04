/**	@file Z2AudioMgr.h
 *	@brief Contains structure definitions and functions for handling game audio
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef Z2AUDIOLIB_Z2AUDIOMGR_H
#define Z2AUDIOLIB_Z2AUDIOMGR_H

#include <cstdint>

#include "Z2AudioLib/Z2SeMgr.h"
#include "gc_wii/bmgres.h"

namespace libtp::tp::control
{
    struct Z2AudioMgr
    {
        libtp::Z2AudioLib::Z2SeMgr mSeMgr;
        uint8_t unk3D0[0xFBC];
    } __attribute__( ( __packed__ ) );

    extern "C"
    {
        bool setMessageCode_inSequence( TControl* control, const void* TProcessor, uint16_t unk3, uint16_t msgId );
    }
}     // namespace libtp::tp::control
#endif