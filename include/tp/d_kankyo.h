/**	@file d_kankyo.h
 *	@brief Kankyo field vars
 *
 *	The d_kankyo field holds lighting information
 *
 *	@author Zephiles
 *	@author AECX
 *  @author Lunar Soap
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
        /* 0x0 */ uint8_t unk_0[0x98C];
        /* 0x98C */ uint8_t currentRoom;
        /* 0x98D */ uint8_t unk_98d[0x6C3];
        /* 0x1050 */ uint8_t mEvilPacketEnabled;
        /* 0x1051 */ uint8_t unk_1051[0x1FB];
        /* 0x124C */ float mTimeSpeed;
        /* 0x1250 */ uint8_t unk_1250[0xC0];
    } __attribute__((__packed__));

    static_assert(sizeof(EnvLight) == 0x1310);

    extern "C"
    {
        extern EnvLight env_light;

        /**
         *  @brief Checks to see if the current stage should be in Twilight
         *
         *  @param stageName The current stage name.
         *  @param roomNo The current room number.
         *
         *  @return Bool returns True if the stage should be in Twilight, otherwise returns False.
         */
        bool dKy_darkworld_stage_check(char const* stageName, int32_t roomNo);

        /**
         *  @brief Checks to see it is currently day or night time.
         *
         *  @return BOOL returns 0 if it is day time and 1 if it is night time.
         */
        int32_t dKy_daynight_check();

        /**
         * @brief Check if environment is currently twilight. Aside from Faron,
         * Eldin, and Lanayru Twilights, most of Palace of Twilight is also a
         * twilight environment for example.
         *
         * @return Returns true if environment is currently twilight, else false.
         */
        bool dKy_darkworld_check();
    }
} // namespace libtp::tp::d_kankyo
#endif