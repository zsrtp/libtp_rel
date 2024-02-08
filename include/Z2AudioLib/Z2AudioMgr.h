/**	@file Z2AudioMgr.h
 *	@brief Contains structure definitions and functions for handling game audio
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef Z2AUDIOLIB_Z2AUDIOMGR_H
#define Z2AUDIOLIB_Z2AUDIOMGR_H

#include <cstdint>

#include "Z2AudioLib/Z2SceneMgr.h"
#include "Z2AudioLib/Z2SeMgr.h"
#include "gc_wii/bmgres.h"

namespace libtp::z2audiolib::z2audiomgr
{
#ifndef PLATFORM_WII
    struct Z2AudioMgr
    {
        /* 0x0000 */ libtp::z2audiolib::z2semgr::Z2SeMgr mSeMgr;
        /* 0x03D0 */ uint8_t mSeqMgr[0xD4];
        /* 0x04A4 */ libtp::z2audiolib::z2scenemgr::Z2SceneMgr mSceneMgr;
        /* 0x04C4 */ uint8_t mStatusMgr[0x30];
        /* 0x04F4 */ uint8_t mSoundObjMgr[0x20];
        /* 0x0514 */ void* vtable; // remove later
        /* 0x0518 */ bool mResettingFlag;
        /* 0x0519 */ bool field_0x519;
        /* 0x051A */ uint8_t padding[2];
        /* 0x051C */ uint8_t mAudioReseter[0x10];
        /* 0x052C */ uint32_t mSoundStarter;
        /* 0x0530 */ uint8_t mSoundMgr[0x810];
        /* 0x0D40 */ void* mSoundInfo[3]; // remove later
        /* 0x0D4C */ uint8_t mAudience[0x1E0];
        /* 0x0F2C */ uint8_t mSpeechMgr[0x444];
        /* 0x1370 */ uint8_t mFxLineMgr[0x1C];

    } __attribute__((__packed__));

    static_assert(sizeof(Z2AudioMgr) == 0x138C);
#else
    struct Z2AudioMgr {
        /* 0x0000 */ libtp::z2audiolib::z2semgr::Z2SeMgr mSeMgr;
        /* 0x03E4 */ uint8_t mSeqMgr[0xD0];
#ifndef TP_WUS0
        uint8_t _p1[0x4];
#endif
        /* 0x04B4 */ libtp::z2audiolib::z2scenemgr::Z2SceneMgr mSceneMgr;
        /* 0x04D4 */ uint8_t mStatusMgr[0x30];
        /* 0x0504 */ uint8_t mSoundObjMgr[0x20];
        /* 0x0524 */ void* vtable;
        /* 0x0528 */ bool mResettingFlag;
        /* 0x0529 */ bool field_0x519;
        /* 0x052C */ uint8_t mAudioReseter[0x10];
        /* 0x053C */ uint32_t mSoundStarter;
        /* 0x0540 */ uint8_t mSoundMgr[0x81C];
        /* 0x0D58 */                       // Z2SoundInfo mSoundInfo;
        /* 0x0D58 */ void* mSoundInfo[3];  // remove later
        /* 0x0D64 */ uint8_t mAudience[0x1E0];
        /* 0x0F44 */ uint8_t mSpeechMgr[0x444];
        /* 0x1388 */ uint8_t mFxLineMgr[0x1C];
    };

#ifdef TP_WUS0
    static_assert(sizeof(Z2AudioMgr) == 0x13A8);
#else
    static_assert(sizeof(Z2AudioMgr) == 0x13AC);
#endif
#endif

    extern "C"
    {
        extern Z2AudioMgr g_mDoAud_zelAudio;
    };

} // namespace libtp::z2audiolib::z2audiomgr
#endif