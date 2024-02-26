/**	@file d_msg_unit.h
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_D_MSG_UNIT_H
#define TP_D_MSG_UNIT_H

#include <cstdint>

namespace libtp::tp::d_msg_unit
{
    extern "C"
    {
        void setTag(int32_t unk1, int32_t unk2, char* unk3, bool unk4);
    }
} // namespace libtp::tp::d_msg_unit
#endif