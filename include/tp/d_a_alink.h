/**	@file d_a_alink.h
 *	@brief Holds definitions about the d_a_alink field
 *
 *	The d_a_alink field holds various functions and variables about Link
 *	and his current state
 *
 *	@author AECX
 *	@author Zephiles
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_ALINK_H
#define TP_D_A_ALINK_H

#include <cstdint>

#include "tp/d_com_inf_game.h"

namespace libtp::tp::d_a_alink
{
    /**
     *	@brief These values define the speed of various climbing actions
     *
     *	@todo Fill missing vars.
     */
    struct ClimbVars
    {
        uint8_t unk_0[0x28];
        float ladderClimbInitSpeed;
        uint8_t unk_2c[0x4];
        float ladderReachTopClimbUpSpeed;
        uint8_t unk_30[0x4];
        float ladderTopStartClimbDownSpeed;
        uint8_t unk_34[0x4];
        float ladderBottomGetOffSpeed;
        uint8_t unk_38[0x8];
        float ladderClimbSpeed;
        uint8_t unk_40[0x10];
        float wallClimbHorizontalSpeed;
        uint8_t unk_58[0x4];
        float wallClimbVerticalSpeed;
        uint8_t unk_5c[0x4];
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( ClimbVars ) == 0x70 );

    /**
     *	@brief These values contain the values for Link's state
     *
     *	@todo Fill missing vars.
     */
    struct LinkStatus
    {
        uint8_t unk_0[0xA2];
        uint8_t status;
    } __attribute__( ( __packed__ ) );

    extern "C"
    {
        /**
         *	@brief Checks if dComIfG_gameInfo.curentStage is equal to name
         *
         *  @return Bool if the stages match
         */
        bool checkStageName( const char* name );

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
        bool checkHeavyStateOn( int32_t unk1, int32_t unk2 );

        /**
         *	@brief Initializes the animation that causes Link to transform
         *
         *  @return Bool if link is transforming
         */
        bool procCoMetamorphoseInit( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *	@brief Checks whether a chest-rupee doesn't fit in Link's wallet
         *
         *	@param unk1 Unknown pointer (perhaps to the treasure struct?)
         *	@param item Item id (1 through 7)
         *
         *	@return True if the rupee doesn't fit in Links wallet, otherwise false
         */
        bool checkTreasureRupeeReturn( void* unk1, int32_t item );

        /**
         *	@brief Checks to see if Link is in an event (cutscene/animation/etc.)
         *
         *  @return False if he isnt, True if he is.
         */
        bool checkEventRun( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently snowboarding
         *
         *  @return Bool if he is or isn't
         */
        bool checkBoardRide( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding in a canoe
         *
         *  @return Bool if he is or isn't
         */
        bool checkCanoeRide( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding on Epona
         *
         *  @return Bool if he is or isn't
         */
        bool checkHorseRide( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding on a boar
         *
         *  @return Bool if he is or isn't
         */
        bool checkBoarRide( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding on the spinner
         *
         *  @return Bool if he is or isn't
         */
        bool checkSpinnerRide( tp::d_com_inf_game::LinkMapVars* linkMapPtr );

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinishInit( void* d_a_alink );

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinish( void* d_a_alink );

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset+Flag
         */
        bool dComIfGs_isEventBit( uint16_t flag );

        extern ClimbVars climbVars;
        extern LinkStatus* linkStatus;
    }
}     // namespace libtp::tp::d_a_alink
#endif