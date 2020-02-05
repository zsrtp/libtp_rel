/**	@file f_op_actor_mng.h
 *	@brief Holds symbols of the f_op_scene_req field
 *
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "types.h"

namespace libtp::tp::f_op_actor_mng
{
    extern "C"
    {
        /**
         *	@brief Runs when Link receives an item from a person
         *
         *	Only runs for Demo items which is indicated by Link turning towards the
         *camera
         *	with the item floating above his hands
         *
         *	@param pos XYZ of the current TRES
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@return Unknown use.
         */
        s32 createItemForPresentDemo(const float pos[3],
                                     s32 item,
                                     u8 unk3,
                                     s32 unk4,
                                     s32 unk5,
                                     const float unk6[3],
                                     const float unk7[3]);

        /**
         *	@brief Runs when Link receives an item by opening a treasure chest
         *
         *	Only runs for Demo items which is indicated by Link turning towards the
         *camera
         *	with the item floating above his hands
         *
         *	@param pos XYZ of the current TRES
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@return Unknown use.
         */
        s32 createItemForTrBoxDemo(const float pos[3], s32 item, s32 unk3, s32 unk4, const float unk5[3], const float unk6[3]);

        /**
         *	@brief Runs when the game creates a boss specific item (heart container)
         *
         *	Can only create Heart Pieces/Heart Containers since these share the same
         *actor
         *	other item ids will render the item unobtainable because the game
         *skips/aborts creation
         *
         *	@param pos XYZ of the TRES
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@param unk8 Unknown
         *	@return Unknown use.
         */
        s32 createItemForBoss(const float pos[3],
                              s32 item,
                              s32 unk3,
                              const float unk4[3],
                              const float unk5[3],
                              float unk6,
                              float unk7,
                              s32 unk8);

        /**
         *	@brief Runs when the game creates a mini-boss specific item (e.g.
         *Boomerang, Ball and Chain, etc.)
         *
         *	Similar to the createItemForBoss function this, unfortunately, doesn't
         *work with actors
         *	that weren't meant to be created via this function (although most items
         **should* work)
         *
         *	@param pos XYZ of the TRES
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@return Unknown use.
         */
        s32 createItemForMidBoss(const float pos[3],
                                 s32 item,
                                 s32 unk3,
                                 const float unk4[3],
                                 const float unk5[3],
                                 s32 unk6,
                                 s32 unk7);

        /**
         *	@brief Runs when Link picks up a minor item
         *
         *	This function will immediately handle a item pick up for items
         *	that are not being presented with a Text Box and Link turning towards
         *the camera
         *
         *	@param pos XYZ of the TRES
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@return Unknown use.
         */
        s32 createItemForDirectGet(const float pos[3],
                                   s32 item,
                                   s32 unk3,
                                   const float unk4[3],
                                   const float unk5[3],
                                   float unk6,
                                   float unk7);
    }
}  // namespace libtp::tp::f_op_actor_mng