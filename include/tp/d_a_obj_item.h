/**	@file d_a_obj_item.h
 *	@brief Holds structs and functions that deal with item actors.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_OBJ_ITEM_H
#define TP_D_A_OBJ_ITEM_H

#include <cstdint>

namespace libtp::tp::d_a_obj_item
{
    extern "C"
    {
        /**
         *  @brief Calls the appropriate functions to give the player an item based on the actor.
         *
         *  @param daItem A pointer to the Item actor being referenced.
         */
        void itemGet(void* daItem);

        /**
         *  @brief Initializes the events necessary for collecting an item based on the actor.
         *
         *  @param daItem A pointer to the Item actor being referenced.
         */
        void itemGetNextExecute(void* daItem);

        /**
         *  @brief Runs code that determines how an item acts while stationary.
         *
         *  @param daItem A pointer to the Item actor being referenced.
         */
        void mode_wait(void* daItem);

        /**
         *  @brief Initializes values in the item system and the specified actor.
         *
         *  @param daItem A pointer to the Item actor being referenced.
         */
        void CreateInit(void* daItem);

        /**
         *  @brief General execution function that sets and modifies actor params
         *
         *  @param daItem A pointer to the Item actor being referenced.
         */
        int32_t daItem_execute(void* daItem);
    }
} // namespace libtp::tp::d_a_obj_item
#endif