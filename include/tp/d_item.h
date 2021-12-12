/**	@file d_item.h
 *	@brief Holds item specific functions and vars
 *
 *	@author AECX
 *	@bug
 */
#ifndef TP_D_ITEM_H
#define TP_D_ITEM_H

#include <cstdint>

namespace libtp::tp::d_item
{
    typedef void ( *ItemFunc )();
    typedef int32_t ( *ItemGetCheckFunc )();

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
        int32_t checkItemGet( uint8_t item, int32_t defaultValue );

        /**
         *	@brief Initializes the dSv_player_get_item_c function with the current
         *value
         *
         *	@param item id of the item being recieved
         */
        int32_t execItemGet( uint8_t item );

        extern ItemFunc item_func_ptr[0x100];
        extern ItemGetCheckFunc item_getcheck_func_ptr[0x100];
    }
}     // namespace libtp::tp::d_item
#endif