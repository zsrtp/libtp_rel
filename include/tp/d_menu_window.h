/**	@file d_menu_window.h
 *	@brief Contains definitions that are used with the various menus
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_WINDOW_H
#define TP_D_MENU_WINDOW_H

#include <cstdint>

namespace libtp::tp::d_menu_window
{
    extern "C"
    {
        /**
         *	@brief Runs when the game needs to open the save menu from the item collection screen.
         *
         *  @param param_1 unknown
         */
        void collect_save_open_init(uint8_t param_1);
    }
} // namespace libtp::tp::d_menu_window
#endif