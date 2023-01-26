#ifndef TP_D_A_NPC_H
#define TP_D_A_NPC_H

#include <cstdint>

namespace libtp::tp::d_a_npc
{
    extern "C"
    {
        void daNpcT_onEvtBit( int16_t flag );
        bool daNpcT_chkEvtBit( int16_t flag );
        bool daNpcF_chkEvtBit( int16_t flag );
    }
}     // namespace libtp::tp::d_a_npc

#endif