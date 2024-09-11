/**	@file d_menu_ring.h
 *	@brief Contains functions that handle events related to the item wheel.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MENU_RING_H
#define TP_D_MENU_RING_H

#include <cstdint>

namespace libtp::tp::d_menu_ring
{
    extern "C"
    {
        /**
         *	@brief Creates the resources needed for the Item Wheel.
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         */
        void dMenuRing__create(void* dMenuRing);

        /**
         *	@brief Removes the resources needed for the Item Wheel in preparation for destruction.
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         */
        void dMenuRing__delete(void* dMenuRing);

        /**
         *	@brief Draws the Item Wheel on the screen.
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         */
        void dMenuRing__draw(void* dMenuRing);

        /**
         *	@brief Constructor for the item wheel class
         *
         *	@param dMenuRing A pointer to the item wheel resources.
         *  @param param_1 a pointer to the current JKRExpHeap
         *  @param param_2 unk
         *  @param param_3 unk
         *  @param param_4 unk
         */
        void dMenuRing_ct(void* dMenuRing, void* param_1, void* param_2, void* param_3, uint8_t param_4);
    }
} // namespace libtp::tp::d_menu_ring
#endif