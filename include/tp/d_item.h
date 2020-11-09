/**	@file d_item.h
 *	@brief Holds item specific functions and vars
 *
 *	@author AECX
 *	@bug
 */
#pragma once
#include <cstdint>

namespace libtp::tp::d_item
{
    extern "C"
    {
        /**
         *	@brief Unknown
         *
         *	@param item Item id to check (?)
         *	@param defaultValue Default if unsuccessful
         *
         *	@return Probably(!) the correct item id to use (for progressive items
         *like clawshot)
         */
        int32_t checkItemGet(uint8_t item, int32_t defaultValue);

        /**
         *	@brief Initializes the dSv_player_get_item_c function with the current value
         *
         *	@param item id of the item being recieved
         */
        int32_t execItemGet(uint8_t item);

        /**
         *	@brief Sets the flag for the heart container being recieved
         */
        void item_func_UTUWA_HEART();
    }
}  // namespace libtp::tp::d_item