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
#include "tp/J3DAnimation.h"
#include "tp/f_op_actor.h"

namespace libtp::tp::d_a_alink
{
    struct daAlink
    {
        /* 0x00000 */ uint8_t unk0[0x4D0];
        /* 0x004D0 */ float playerPos[3];
        /* 0x004DC */ uint8_t unk4dc[0x94];
        /* 0x00570 */ uint32_t mNoResetFlg0;
        /* 0x00574 */ uint8_t unk574[0x1B0];
        /* 0x00724 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* tevRegKey;
        /* 0x00728 */ uint8_t unk728[0x28B4];
        /* 0x02FDC */ uint16_t mEquipItem;
        /* 0x02FDE */ uint8_t unk2FDE[0x8DE];
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

    struct daAlinkHIO_anm_c
    {
        /* 0x00 */ int16_t field_0x00;     // end f?
        /* 0x02 */ uint16_t padding_0x02;
        /* 0x04 */ float field_0x04;       // speed?
        /* 0x08 */ float field_0x08;       // start?
        /* 0x0C */ float field_0x0c;       // interpolation?
        /* 0x10 */ float field_0x10;       // CF?
    } __attribute__( ( __packed__ ) );     // size = 0x14

    struct WallMoveVars
    {
        float moveSidewaysStickNotHeld;     // default = 0.8
        float movesidewaysStickHeld;        // default = 1.1
        uint8_t unk[0xC];
    } __attribute__( ( __packed__ ) );

    struct daAlinkHIO_huLight_c0
    {
        uint32_t unk_0;
        uint16_t lanternAmbienceR;
        uint16_t lanternAmbienceG;
        uint16_t lanternAmbienceB;
        uint8_t unk_A[0x12];
    } __attribute__( ( __packed__ ) );

    struct daAlinkHIO_kandelaar_c0
    {
        /* 0x00 */ daAlinkHIO_anm_c mShakeAnm;
        /* 0x14 */ daAlinkHIO_anm_c mBeginUnkAnm;
        /* 0x28 */ daAlinkHIO_anm_c mEndUnkAnm;
        /* 0x3C */ uint16_t innerSphereR;
        /* 0x3E */ uint16_t innerSphereG;
        /* 0x40 */ uint16_t innerSphereB;
        /* 0x42 */ uint16_t outerSphereR;
        /* 0x44 */ uint16_t outerSphereG;
        /* 0x46 */ uint16_t outerSphereB;
        /* 0x48 */ uint16_t mNormalOilLoss;
        /* 0x4A */ uint16_t mShakeOilLoss;
        /* 0x4C */ float mFlameTrackRate;

    } __attribute__( ( __packed__ ) );

    struct daAlinkHIO_magneBoots_c0
    {
        uint8_t unk_0[0x14];
        float heavyStateSpeed;
        uint8_t unk_18[0x34];

    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( daAlink ) == 0x38BC );
    static_assert( sizeof( ClimbVars ) == 0x70 );
    static_assert( sizeof( daAlinkHIO_kandelaar_c0 ) == 0x50 );
    static_assert( sizeof( daAlinkHIO_magneBoots_c0 ) == 0x4C );
    static_assert( sizeof( WallMoveVars ) == 0x14 );
    static_assert( sizeof( daAlinkHIO_huLight_c0 ) == 0x1C );
    static_assert( sizeof( daAlinkHIO_anm_c ) == 0x14 );

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
        bool checkEventRun( daAlink* linkActrPtr );

        /**
         *	@brief Checks to see if Link is currently snowboarding
         *
         *  @return Bool if he is or isn't
         */
        bool checkBoardRide( daAlink* linkActrPtr );

        /**
         *	@brief Checks to see if Link is currently riding in a canoe
         *
         *  @return Bool if he is or isn't
         */
        bool checkCanoeRide( daAlink* linkActrPtr );

        /**
         *	@brief Checks to see if Link is currently riding on Epona
         *
         *  @return Bool if he is or isn't
         */
        bool checkHorseRide( daAlink* linkActrPtr );

        /**
         *	@brief Checks to see if Link is currently riding on a boar
         *
         *  @return Bool if he is or isn't
         */
        bool checkBoarRide( daAlink* linkActrPtr );

        /**
         *	@brief Checks to see if Link is currently riding on the spinner
         *
         *  @return Bool if he is or isn't
         */
        bool checkSpinnerRide( daAlink* linkActrPtr );

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinishInit( daAlink* linkActrPtr );

        /**
         *  @brief Runs when delivering the final blow to Ganondorf
         */
        bool procGanonFinish( daAlink* linkActrPtr );

        /**
         *  @brief Checks to see if link should be taking damage
         */
        bool checkDamageAction( daAlink* linkActrPtr );

        /**
         *  @brief Sets link's facial expression when getting an item
         */
        void setGetItemFace( daAlink* linkActrPtr, uint16_t itemID );

        /**
         *  @brief Causes link to take damage based on his interaction with certain things.
         */
        bool procDamageInit( daAlink* linkActrPtr, void* obj, int32_t unk3 );

        /**
         *  @brief Causes link to take damage based on his interaction with certain things.
         */
        bool procWolfDamageInit( daAlink* linkActrPtr, void* obj );

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset+Flag
         */
        bool dComIfGs_isEventBit( uint16_t flag );

        bool checkDownAttackState( daAlink* linkActrPtr );

        bool checkBootsMoveAnime( daAlink* linkActrPtr, int32_t param_1 );

        void procCoTalkInit( daAlink* linkActrPtr );

        void procCoGetItem( daAlink* linkActrPtr );

        void dComIfGp_setItemLifeCount( float amount, uint8_t count );

        bool checkRestartRoom( daAlink* linkActrPtr );

        void checkWarpStart( daAlink* linkActrPtr );

        void setWolfLockDomeModel( daAlink* linkActrPtr );

        /**
         *  @brief Checks to see if Link is riding the Spinner and if so, returns a pointer to the Spinner's actor
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        libtp::tp::f_op_actor::fopAc_ac_c* getSpinnerActor( daAlink* linkActrPtr );

        /**
         *  @brief Checks to see if Link is trying to open a door near Bo
         *
         *  @param actrPtr A pointer to an actor near Link
         */
        libtp::tp::f_op_actor::fopAc_ac_c* searchBouDoor( libtp::tp::f_op_actor::fopAc_ac_c* actrPtr );

        extern ClimbVars climbVars;
        extern LinkStatus* linkStatus;
        extern WallMoveVars wallMoveVars;     // US Address = 0x8038E1E0
        extern uint8_t getSeType[0x100];
        extern daAlinkHIO_kandelaar_c0 lanternVars;
        extern daAlinkHIO_magneBoots_c0 ironBootsVars;
        extern daAlinkHIO_huLight_c0 huLightVars;
    }
}     // namespace libtp::tp::d_a_alink
#endif