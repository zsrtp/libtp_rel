/**	@file d_menu_option.h
 *	@brief Contains functions that handle events related to the options menu
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_OPTION_H
#define TP_D_MENU_OPTION_H

#include <cstdint>

namespace libtp::tp::d_menu_option
{
    extern "C"
    {
        /**
         *	@brief Initializes the TV Brightness options screen menu.
         *
         *	@param dMenuOption A pointer to the options menu resources.
         */
        void dMenuOption__tv_open1_move(void* dMenuOption);
    }
} // namespace libtp::tp::d_menu_option
#endif