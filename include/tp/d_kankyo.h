/**	@file d_kankyo.h
 *	@brief Kankyo field vars
 *
 *	The d_kankyo field holds lighting information
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef TP_D_KANKYO_H
#define TP_D_KANKYO_H

#include <cstdint>

namespace libtp::tp::d_kankyo
{
    /**
     *	@brief Environment infos
     *
     *	@todo Fill missing vars.
     */
    struct EnvLight
    {
        uint8_t unk_0[0x98C];
        uint8_t currentRoom;
        uint8_t unk_98d[0x983];
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( EnvLight ) == 0x1310 );

    extern "C"
    {
        extern EnvLight env_light;
    }
}     // namespace libtp::tp::d_kankyo
#endif