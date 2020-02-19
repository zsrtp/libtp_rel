/**	@file d_a_alink.h
 *	@brief Holds definitions about the d_a_alink field
 *
 *	The d_a_alink field holds various functions and variables about Link
 *	and his current state
 *
 *	@author AECX
 *	@author Zephiles
 *	@bug No known bugs.
 */

#pragma once

#include "../types.h"

namespace libtp::tp::d_a_alink
{
    /**
     *	@brief These values define the speed of various climbing actions
     *
     *	@todo Fill missing vars.
     */
    struct ClimbVars
    {
        u8 unk_0[0x28];
        float ladderClimbInitSpeed;
        u8 unk_2c[0x4];
        float ladderReachTopClimbUpSpeed;
        u8 unk_30[0x4];
        float ladderTopStartClimbDownSpeed;
        u8 unk_34[0x4];
        float ladderBottomGetOffSpeed;
        u8 unk_38[0x8];
        float ladderClimbSpeed;
        u8 unk_40[0x10];
        float wallClimbHorizontalSpeed;
        u8 unk_58[0x4];
        float wallClimbVerticalSpeed;
        u8 unk_5c[0x4];
    } __attribute__((__packed__));

    static_assert(sizeof(ClimbVars) == 0x70);

    extern "C"
    {
        /**
         *	@brief Runs when Link is about to walk on magnetic wall/ceiling
         */
        void setStickData();

        /**
         *	@brief Determines whether Link is in heavy state (Iron boots, Ball and
         *Chain, ...)
         *
         *	@return Bool whether Link is, if he is some actions might be restricted
         */
        bool checkHeavyStateOn(s32 unk1, s32 unk2);

        /**
         *	@brief Checks whether a chest-rupee doesn't fit in Link's wallet
         *
         *	@param unk1 Unknown pointer (perhaps to the treasure struct?)
         *	@param item Item id (1 through 7)
         *
         *	@return True if the rupee doesn't fit in Links wallet, otherwise false
         */
        bool checkTreasureRupeeReturn(void* unk1, s32 item);

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinishInit(void* d_a_alink);

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        void procGanonFinish();

        extern ClimbVars climbVars;
    }
}  // namespace libtp::tp::d_a_alink