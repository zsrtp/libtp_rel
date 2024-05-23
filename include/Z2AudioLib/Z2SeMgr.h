/**	@file Z2SeMgr.h
 *	@brief Contains structure definitions and functions for handling game audio
 *
 *	@author Lunar Soap
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef Z2AUDIOLIB_Z2SEMGR_H
#define Z2AUDIOLIB_Z2SEMGR_H

#include <cstdint>

#include "dolphin/mtx/vec.h"
#include "tp/bmgres.h"

namespace libtp::z2audiolib::z2semgr
{
    struct Z2SeMgr
    {
        /* 0x000 */ uint8_t mSoundHandle[0x60]; // JAISoundHandle mSoundHandle[24]
        /* 0x060 */ uint8_t field_0x60[0x8];    // JAISoundHandles field_0x60
#ifdef PLATFORM_WII
        /* 0x68 */ uint32_t field_0x68;
        /* 0x6C */ uint8_t field_0x6c[0x10];
#endif
        /* 0x068 */ uint8_t mLevelObjSe[0x168]; // Z2MultiSeObj mLevelObjSe[10]
        /* 0x1D0 */ uint32_t mLevelObjectSeCount;
        /* 0x1D4 */ uint8_t mMultiTriggerSe[0x168]; // Z2MultiSeObj mMultiTriggerSe[10]
        /* 0x33C */ uint8_t mMultiTriggerSeCount;
        /* 0x33D */ uint8_t field_0x33d[0x63];
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
        /* 0x3CD */ uint8_t padding[3];
    } __attribute__((__packed__));

#ifndef PLATFORM_WII
    static_assert(sizeof(Z2SeMgr) == 0x3D0);
#else
    static_assert(sizeof(Z2SeMgr) == 0x3E4);
#endif

    extern "C"
    {
        extern Z2SeMgr* mAudioMgrPtr;

        void z2SeMgr_seStartLevel(Z2SeMgr* audioMgr,
                                  uint32_t* sfxID,
                                  const Vec* unk4,
                                  uint32_t unk5,
                                  int8_t unk6,
                                  float f1,
                                  float f2,
                                  float f3,
                                  float f4,
                                  uint8_t unk7);

        void z2SeMgr_seStart(Z2SeMgr* audioMgr,
                             uint32_t* sfxID,
                             const Vec* unk4,
                             uint32_t unk5,
                             int8_t unk6,
                             float f1,
                             float f2,
                             float f3,
                             float f4,
                             uint8_t unk7);
    };
} // namespace libtp::z2audiolib::z2semgr
#endif
