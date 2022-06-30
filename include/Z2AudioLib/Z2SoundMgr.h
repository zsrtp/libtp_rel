#ifndef Z2AUDIOLIB_Z2SOUNDMGR_H
#define Z2AUDIOLIB_Z2SOUNDMGR_H

#include "Z2AudioLib/Z2SceneMgr.h"

namespace libtp::z2audiolib::z2soundmgr {
    extern "C" void startSound( void* soungMgr, libtp::z2audiolib::z2scenemgr::JAISoundID soundId, void* soundHandle, void* pos);
}

#endif