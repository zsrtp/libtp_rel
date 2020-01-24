/**	@file d_kankyo.h
 *	@brief Kankyo field vars
 *
 *	The d_kankyo field holds lighting information
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "../types.h"

namespace libtp::tp::d_kankyo
{
    /**
     *	@brief Environment infos
     *
     *	@todo Fill missing vars.
     */
    struct EnvLight
    {
        u8 unk_0[0x98C];
        u8 currentRoom;
        u8 unk_98d[0x983];
    } __attribute__((__packed__));

    static_assert(sizeof(EnvLight) == 0x1310);

    extern "C"
    {
        extern EnvLight env_light;
    }
}  // namespace libtp::tp::d_kankyo