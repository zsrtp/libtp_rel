/**	@file d_menu_window.h
 *	@brief Contains definitions that are used with the various menus
 *
 *	@author Lunar Soap
 *  @author Captain Kitty Cat
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

        /**
         * @brief checks d-pad Up button.
         * 
         * @return Bool returns 1 if DPad Up is pressed. 0 if it's not pressed.
        */
        int32_t dMw_UP_TRIGGER();

        /**
         * @brief checks d-pad Down button.
         * 
         * @return Bool returns 1 if DPad Down is pressed. 0 if it's not pressed.
        */
        int32_t dMw_DOWN_TRIGGER();

        /**
         * @brief checks d-pad Left button.
         * 
         * @return Bool returns 1 if DPad Left is pressed. 0 if it's not pressed.
        */
        int32_t dMw_LEFT_TRIGGER();

        /**
         * @brief checks d-pad Right button.
         * 
         * @return Bool returns 1 if DPad Right is pressed. 0 if it's not pressed.
        */
        int32_t dMw_RIGHT_TRIGGER();

        /**
         * @brief checks A button.
         * 
         * @return Bool returns 1 if A is pressed. 0 if it's not pressed.
        */
        int32_t dMw_A_TRIGGER();

        /**
         * @brief checks B button.
         * 
         * @return Bool returns 1 if B is pressed. 0 if it's not pressed.
        */
        int32_t dMw_B_TRIGGER();

        /**
         * @brief checks Z button.
         * 
         * @return Bool returns 1 if Z is pressed. 0 if it's not pressed.
        */
        int32_t dMw_Z_TRIGGER();

        /**
         * @brief checks Start button for GameCube and + button for Wii.
         * 
         * @return Bool returns 1 if Start/+ is pressed. 0 if it's not pressed.
        */
        int32_t dMw_START_TRIGGER();
    }
} // namespace libtp::tp::d_menu_window
#endif
