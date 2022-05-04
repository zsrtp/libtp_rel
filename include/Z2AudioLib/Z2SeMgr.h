/**	@file Z2SeMgr.h
 *	@brief Contains structure definitions and functions for handling game audio
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef Z2AUDIOLIB_Z2SEMGR_H
#define Z2AUDIOLIB_Z2SEMGR_H

#include <cstdint>

#include "gc_wii/bmgres.h"

namespace libtp::z2audiolib::z2semgr
{
    struct Z2SeMgr
    {
        /* 0x000 */ uint8_t mSoundHandle[0x60];     // JAISoundHandle mSoundHandle[24]
        /* 0x060 */ uint8_t field_0x60[0x8];        // JAISoundHandles field_0x60
        /* 0x068 */ uint8_t mLevelObjSe[0x168];     // Z2MultiSeObj mLevelObjSe[10]
        /* 0x1D0 */ uint32_t mLevelObjectSeCount;
        /* 0x1D4 */ uint8_t mMultiTriggerSe[0x168];     // Z2MultiSeObj mMultiTriggerSe[10]
        /* 0x33C */ uint8_t mMultiTriggerSeCount;
        /* 0x33D */ uint8_t field_0x33d[0x60];
        /* 0x3A0 */ uint32_t mModY[8];
        /* 0x3C0 */ uint8_t field_0x3c0;
        /* 0x3C1 */ uint8_t field_0x3c1;
        /* 0x3C2 */ uint8_t field_0x3c2;
        /* 0x3C3 */ uint8_t field_0x3c3;
        /* 0x3C4 */ uint8_t field_0x3c4;
        /* 0x3C5 */ uint8_t field_0x3c5;
        /* 0x3C6 */ uint8_t field_0x3c6;
        /* 0x3C7 */ uint8_t field_0x3c7;
        /* 0x3C8 */ uint8_t field_0x3c8;
        /* 0x3C9 */ uint8_t field_0x3c9;
        /* 0x3CA */ uint8_t field_0x3ca;
        /* 0x3CB */ uint8_t field_0x3cb;
        /* 0x3CC */ uint8_t mCrowdSize;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( Z2SeMgr ) == 0x3D0 );
}     // namespace libtp::z2audiolib::z2semgr
#endif