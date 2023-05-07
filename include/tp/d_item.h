/**	@file d_item.h
 *	@brief Holds item specific functions and vars
 *
 *	@author AECX
 *  @author Lunar Soap
 *  @bug No known bugs.
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
         *	@brief Checks to see if the player has obtained the specified item.
         *
         *	@param item Item id to check
         *	@param defaultValue Default if unsuccessful
         *
         *	@return BOOL returns True if the player has the item, otherwise returns False.
         */
        int32_t checkItemGet( uint8_t item, int32_t defaultValue );

        /**
         *	@brief Gives the specified item to the player with no cutscene.
         *
         *	@param item id of the item being recieved.
         */
        void execItemGet( uint8_t item );

        /**
         *  @brief Sets appropriate flags when the player collects the Wooden Sword.
         */
        void item_func_WOOD_STICK();

        /**
         *  @brief Sets the appropriate flags when the player collects a Heart Container.
         */
        void item_func_UTUWA_HEART();

        extern ItemFunc item_func_ptr[0x100];
        extern ItemGetCheckFunc item_getcheck_func_ptr[0x100];

         /**
         *  @brief  Sets the appropriate flag for  memo so it dosen't show in the inventory if the check is already recolted.
         */
        void item_func_ASHS_SCRIBBLING();

    }
}     // namespace libtp::tp::d_item
#endif