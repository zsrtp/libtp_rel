#include "tp/m_do_audio.h"
#include "dolphin/mtx/vec.h"
#include "Z2AudioLib/Z2SeMgr.h"

#include <cstdint>

namespace libtp::tp::m_Do_Audio
{
#ifdef PLATFORM_WII
    void mDoAud_seStartLevel(uint32_t sfxID, const Vec* i_sePos, uint32_t unk5, int8_t i_reverb)
    {
        using namespace libtp::z2audiolib::z2semgr;
        z2SeMgr_seStartLevel(mAudioMgrPtr, &sfxID, i_sePos, unk5, i_reverb, 1.0f, 1.0f, -1.0f, -1.0f, 0);
    }
#endif

    void mDoAud_seStart(uint32_t sfxID, const Vec* i_sePos, uint32_t unk5, int8_t i_reverb) {
        using namespace libtp::z2audiolib::z2semgr;
        z2SeMgr_seStart(mAudioMgrPtr, &sfxID, i_sePos, unk5, i_reverb, 1.0f, 1.0f, -1.0f, -1.0f, 0);
    }

} // namespace libtp::tp::m_Do_Audio
