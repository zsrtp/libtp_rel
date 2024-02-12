/**	@file f_op_actor_mng.h
 *	@brief Holds symbols of the f_op_scene_req field
 *
 *	@author AECX
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_F_OP_ACTOR_MNG_H
#define TP_F_OP_ACTOR_MNG_H

#include <cstdint>

#include "tp/dzx.h"

namespace libtp::tp::f_op_actor_mng
{
    extern "C"
    {
        /**
         *	@brief Runs when Link holds an item in front of him.
         *
         *	@param pos Position of the current item.
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItemForPresentDemo(const float pos[3],
                                         int32_t item,
                                         uint8_t unk3,
                                         int32_t unk4,
                                         int32_t unk5,
                                         const float unk6[3],
                                         const float unk7[3]);

        /**
         *	@brief Runs when Link receives an item by opening a treasure chest
         *
         *	@param pos The position of the item.
         *	@param item Item ID
         *	@param itemPickupFlag The flag to be set upon receiving the item.
         *	@param roomNo The current room.
         *	@param rot The rotation of the item.
         *	@param scale The scale of the item.
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItemForTrBoxDemo(const float pos[3],
                                       int32_t item,
                                       int32_t itemPickupFlag,
                                       int32_t roomNo,
                                       const int16_t rot[3],
                                       const float scale[3]);

        /**
         *	@brief Runs when the game creates a boss specific item (heart container)
         *
         *	@param pos The position of the item.
         *	@param item Item ID
         *	@param roomNo The current room number.
         *	@param rot The rotation of the item.
         *	@param scale The scale of the item.
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@param parameters The parameters of the item, including the flags, type, etc.
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItemForBoss(const float pos[3],
                                  int32_t item,
                                  int32_t roomNo,
                                  const int16_t rot[3],
                                  const float scale[3],
                                  float unk6,
                                  float unk7,
                                  int32_t parameters);

        /**
         *	@brief Runs when the game creates a mini-boss specific item (e.g.
         *Boomerang, Ball and Chain, etc.)
         *
         *	@param pos The position of the item.
         *	@param item Item ID
         *	@param roomNo The current room
         *	@param rot The rotation of the item.
         *	@param scale The scale of the item.
         *	@param unk6 Unknown
         *	@param itemPickupFlag The flag to be set once the item is received.
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItemForMidBoss(const float pos[3],
                                     int32_t item,
                                     int32_t roomNo,
                                     const int16_t rot[3],
                                     const float scale[3],
                                     int32_t unk6,
                                     int32_t itemPickupFlag);

        /**
         *	@brief Runs when Link picks up a minor item
         *
         *	This function will immediately handle a item pick up for items
         *	that are not being presented with a Text Box and Link turning towards
         *the camera
         *
         *	@param pos Position of the item.
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param unk4 Unknown
         *	@param unk5 Unknown
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItemForDirectGet(const float pos[3],
                                       int32_t item,
                                       int32_t unk3,
                                       const float unk4[3],
                                       const float unk5[3],
                                       float unk6,
                                       float unk7);

        /**
         *  @brief Prepares the game for spawning an actor
         */
        dzx::ActorPRMClass* CreateAppend(void);

        /**
         *	@brief Runs when Link receives up a minor item
         *
         *	@param pos Position of the item.
         *	@param item Item ID
         *	@param unk3 Unknown
         *	@param rot The rotation of the item.
         *	@param scale The scale of the item.
         *	@param unk6 Unknown
         *	@param unk7 Unknown
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItemForSimpleDemo(const float pos[3],
                                        int32_t item,
                                        int32_t unk3,
                                        const int16_t rot[3],
                                        const float scale[3],
                                        float unk6,
                                        float unk7);

        /**
         *	@brief Creates the resources for an item that is to be displayed
         *
         *	@param pos Position of the item.
         *	@param item Item ID
         *	@param itemPickupFlag The flags to be set when the item is collected.
         *	@param roomNo The current room number.
         *	@param rot The rotation of the item.
         *	@param scale The scale of the item.
         *	@param itemAction The ID of the action to be performed.
         *	@return The process ID to be used in the event flow.
         */
        int32_t createItem(const float pos[3],
                           int32_t item,
                           int32_t itemPickupFlag,
                           int32_t roomNo,
                           const int16_t rot[3],
                           const float scale[3],
                           int32_t itemAction);

        /**
         *	@brief Spawns an actor given a specific index
         *
         *	@param type type of item being spawned
         *	@param params paramOne, paramTwo, membitFlag, item; Different for each type
         *	@param pos the position of the the actor spawned
         *	@param roomNo the current room number
         *	@param rot the rotation of the actor
         *	@param scale the scale of the actor
         *	@param unk9 Unknown
         *	@return The process ID to be used in the event flow.
         */
        int32_t fopAcM_create(int16_t type,
                              uint32_t params,
                              const float pos[3],
                              int32_t roomNo,
                              const int16_t rot[3],
                              const float scale[3],
                              int8_t unk9);

        /**
         *	@brief Checks if Link is currently talking to the specified actor
         *
         *	@param actrPtr The actor being verified.
         *
         *  @return BOOL returns True if Link is talking to the specified actor, otherwise returns False.
         */
        int32_t fopAcM_getTalkEventPartner(void* actrPtr);

        /**
         *	@brief Changes the order of the current event node.
         *
         *	@param actrPtr The actor that is executing the event.
         *  @param eventID The ID of the event we want to change the order of.
         *  @param param_3 unknown.
         *  @param param_4 unknown.
         */
        void fopAcM_orderChangeEventId(void* actorPtr, int16_t eventID, uint16_t param_3, uint16_t param_4);
    }
} // namespace libtp::tp::f_op_actor_mng
#endif