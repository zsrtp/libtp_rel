/**	@file d_msg_flow.h
 *	@brief Contains functions that check multiple flags during conversations
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MSG_FLOW_H
#define TP_D_MSG_FLOW_H

#include <cstdint>

namespace libtp::tp::d_msg_flow
{
    extern "C"
    {
        /**
         *	@brief Checks to see if the player has a specified item that is determined by the current conversation.
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return BOOL returns 0 if the player does not have the item, otherwise returns 1
         */
        int32_t query022(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Checks to see how many Bomb bags the player has.
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return Returns the number of Bomb Bags the player has.
         */
        int32_t query023(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Checks to see how many Empty Bottles
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return BOOL returns 0 if the player does not have an empty bottle, otherwise returns 1
         */
        int32_t query025(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Checks to see if there are any NPCs around to be able to transform.
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return Returns 0 if the player can transform, 1 if a NPC is nearby, 2 if a NPC can see link from a distance, 3 if
         *he has scared someone already (like in Kak), and 4 if he is in castle town and has scared the people.
         */
        int32_t query042(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Checks to see if Link has enough rupees to complete the current action.
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return If a valid value is returned from the flow_node, returns (currentRupees - value). If there is no valid
         *value, returns (currentRupees - max rupees).
         */
        int32_t query004(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Checks to see which option has been selected when choosing multiple dialogue options.
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return If using a standard multiple choice message, return the index of the value, with 0 being the first option.
         *If it is a standard message, return 3.
         */
        int32_t query037(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Checks to see how many Poe Souls the player has to advance dialogue properly.
         *
         *  @param flow_node A pointer to the current message flow node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *  @param unk3 Unknown.
         *
         *  @return Returns 0 if player has 0 souls, 1 if player has less than 20, 2 if greater than 20 but less than 40, 3 if
         *greater than 40 but less than 60, and 4 if 60 or more.
         */
        int32_t query049(void* flow_node, void* actrPtr, int32_t unk3);

        /**
         *	@brief Removes a specified amount of rupees from Link's wallet based on the conversation.
         *
         *  @param messageFlow A pointer to the current message flow node.
         *  @param nodeEvent A pointer to the current event node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *
         *  @return Always returns 1.
         */
        int32_t event003(void* messageFlow, void* nodeEvent, void* actrPtr);

        /**
         *	@brief Adds a specified amount to the total amount of rupees donated to Charlo
         *
         *  @param messageFlow A pointer to the current message flow node.
         *  @param nodeEvent A pointer to the current event node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *
         *  @return Always returns 1.
         */
        int32_t event041(void* messageFlow, void* nodeEvent, void* actrPtr);

        /**
         *	@brief Removes Auru's Memo and Ashei's Sketch from the item wheel once they have been shown to the correct people.
         *
         *  @param messageFlow A pointer to the current message flow node.
         *  @param nodeEvent A pointer to the current event node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *
         *  @return Always returns 1.
         */
        int32_t event035(void* messageFlow, void* nodeEvent, void* actrPtr);

        /**
         *	@brief Sets a specified pair of event bits based on the current conversation.
         *
         *  @param messageFlow A pointer to the current message flow node.
         *  @param nodeEvent A pointer to the current event node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *
         *  @return Always returns 1.
         */
        int32_t event000(void* messageFlow, void* nodeEvent, void* actrPtr);

        /**
         *	@brief Gives a specified item based on the current conversation.
         *
         *  @param messageFlow A pointer to the current message flow node.
         *  @param nodeEvent A pointer to the current event node.
         *  @param actrPtr A pointer to the actor interacting with the message flow node
         *
         *  @return Always returns 1.
         */
        int32_t event017(void* messageFlow, void* nodeEvent, void* actrPtr);
    }
} // namespace libtp::tp::d_msg_flow
#endif