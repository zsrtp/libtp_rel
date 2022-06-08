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

namespace libtp::tp::d_a_alink
{
    struct daAlink
    {
        /* 0x0062C */ uint8_t unk0[0x2FDC];
        /* 0x02FDC */ uint16_t mEquipItem;
        /* 0x02FDE */ uint8_t unk2FDE[0x87A];
    } __attribute__( ( __packed__ ) );
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

    struct WallMoveVars
    {
        float moveSidewaysStickNotHeld;     // default = 0.8
        float movesidewaysStickHeld;        // default = 1.1
        uint8_t unk[0xC];
    } __attribute__( ( __packed__ ) );

    struct daAlinkHIO_kandelaar_c0
    {
        uint8_t unk_0[0x3C];
        uint16_t innerSphereR;
        uint16_t innerSphereG;
        uint16_t innerSphereB;
        uint16_t outerSphereR;
        uint16_t outerSphereG;
        uint16_t outerSphereB;
        uint8_t unk_48[0x8];

    } __attribute__( ( __packed__ ) );

    struct daAlinkHIO_magneBoots_c0
    {
        uint8_t unk_0[0x14];
        float heavyStateSpeed;
        uint8_t unk_18[0x34];

    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( ClimbVars ) == 0x70 );
    static_assert( sizeof( daAlinkHIO_kandelaar_c0 ) == 0x50 );
    static_assert( sizeof( daAlinkHIO_magneBoots_c0 ) == 0x4C );
    static_assert( sizeof( WallMoveVars ) == 0x14 );

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
        bool procCoMetamorphoseInit( daAlink* linkMapPtr );

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
        bool checkEventRun( daAlink* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently snowboarding
         *
         *  @return Bool if he is or isn't
         */
        bool checkBoardRide( daAlink* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding in a canoe
         *
         *  @return Bool if he is or isn't
         */
        bool checkCanoeRide( daAlink* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding on Epona
         *
         *  @return Bool if he is or isn't
         */
        bool checkHorseRide( daAlink* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding on a boar
         *
         *  @return Bool if he is or isn't
         */
        bool checkBoarRide( daAlink* linkMapPtr );

        /**
         *	@brief Checks to see if Link is currently riding on the spinner
         *
         *  @return Bool if he is or isn't
         */
        bool checkSpinnerRide( daAlink* linkMapPtr );

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinishInit( daAlink* d_a_alink );

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinish( daAlink* d_a_alink );

        /**
         *  @brief Checks to see if link should be taking damage
         */
        bool checkDamageAction( daAlink* d_a_alink );

        /**
         *  @brief Sets link's facial expression when getting an item
         */
        void setGetItemFace( daAlink* d_a_alink, uint16_t itemID );

        /**
         *  @brief Causes link to take damage based on his interaction with certain things.
         */
        bool procDamageInit( daAlink* d_a_alink, void* obj, int32_t unk3 );

        /**
         *  @brief Causes link to take damage based on his interaction with certain things.
         */
        bool procWolfDamageInit( daAlink* d_a_alink, void* obj );

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset+Flag
         */
        bool dComIfGs_isEventBit( uint16_t flag );

        bool checkDownAttackState( daAlink* d_a_alink );

        bool checkBootsMoveAnime( daAlink* d_a_alink, int param_1 );

        void procCoTalkInit( daAlink* d_a_alink );

        void procCoGetItem( daAlink* d_a_alink );

        void dComIfGp_setItemLifeCount( float amount, uint8_t count );

        extern ClimbVars climbVars;
        extern LinkStatus* linkStatus;
        extern WallMoveVars wallMoveVars;     // US Address = 0x8038E1E0
        extern uint8_t getSeType[0x100];
        extern daAlinkHIO_kandelaar_c0 lanternVars;
        extern daAlinkHIO_magneBoots_c0 ironBootsVars;
    }
}     // namespace libtp::tp::d_a_alink
#endif