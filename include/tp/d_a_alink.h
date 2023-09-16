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
    } __attribute__((__packed__));

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
    } __attribute__((__packed__));

    struct daAlinkHIO_anm_c
    {
        /* 0x00 */ int16_t field_0x00; // end f?
        /* 0x02 */ uint16_t padding_0x02;
        /* 0x04 */ float field_0x04; // speed?
        /* 0x08 */ float field_0x08; // start?
        /* 0x0C */ float field_0x0c; // interpolation?
        /* 0x10 */ float field_0x10; // CF?
    } __attribute__((__packed__));   // size = 0x14

    struct WallMoveVars
    {
        float moveSidewaysStickNotHeld; // default = 0.8
        float movesidewaysStickHeld;    // default = 1.1
        uint8_t unk[0xC];
    } __attribute__((__packed__));

    struct daAlinkHIO_huLight_c0
    {
        uint32_t unk_0;
        uint16_t lanternAmbienceR;
        uint16_t lanternAmbienceG;
        uint16_t lanternAmbienceB;
        uint8_t unk_A[0x12];
    } __attribute__((__packed__));

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

    } __attribute__((__packed__));

    struct daAlinkHIO_magneBoots_c0
    {
        uint8_t unk_0[0x14];
        float heavyStateSpeed;
        uint8_t unk_18[0x34];

    } __attribute__((__packed__));

    static_assert(sizeof(daAlink) == 0x38BC);
    static_assert(sizeof(ClimbVars) == 0x70);
    static_assert(sizeof(daAlinkHIO_kandelaar_c0) == 0x50);
    static_assert(sizeof(daAlinkHIO_magneBoots_c0) == 0x4C);
    static_assert(sizeof(WallMoveVars) == 0x14);
    static_assert(sizeof(daAlinkHIO_huLight_c0) == 0x1C);
    static_assert(sizeof(daAlinkHIO_anm_c) == 0x14);

    /**
     *	@brief These values contain the values for Link's state
     *
     *	@todo Fill missing vars.
     */
    struct LinkStatus
    {
        uint8_t unk_0[0xA2];
        uint8_t status;
    } __attribute__((__packed__));

    extern "C"
    {
        /**
         *	@brief Checks if the specified stage is equal to the current stage.
         *
         *  @return Bool Returns True if the stages match, otherwise returns False.
         */
        bool checkStageName(const char* name);

        /**
         *	@brief Runs when Link is about to walk in a direction.
         */
        void setStickData();

        /**
         *	@brief Determines whether Link is in heavy state (Iron boots, Ball and
         *Chain, ...)
         *
         *	@return Bool returns True if Link is in a heavy state, otherwise returns False.
         */
        bool checkHeavyStateOn(int32_t unk1, int32_t unk2);

        /**
         *	@brief Initializes the animation that causes Link to transform.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if the process completed successfully, otherwise returns False.
         */
        bool procCoMetamorphoseInit(daAlink* linkActrPtr);

        /**
         *	@brief Checks whether a chest-rupee doesn't fit in Link's wallet.
         *
         *	@param linkActrPtr A pointer to Link's Actor
         *	@param itemID The ID of the rupee to check.
         *
         *	@return Bool returns True if the rupee doesn't fit in Links wallet, otherwise returns False.
         */
        bool checkTreasureRupeeReturn(daAlink* unk1, int32_t item);

        /**
         *	@brief Checks to see if Link is in an event (cutscene/animation/etc.)
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is in an event, otherwise returns False.
         */
        bool checkEventRun(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently snowboarding.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is on a snowboard, otherwise returns False.
         */
        bool checkBoardRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding in a canoe.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is in a canoe, otherwise returns False.
         */
        bool checkCanoeRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding on Epona.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is riding Epona, otherwise returns False.
         */
        bool checkHorseRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding on a boar.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is riding a Boar, otherwise returns False.
         */
        bool checkBoarRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding on the spinner.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is riding on the Spinner, otherwise returns False.
         */
        bool checkSpinnerRide(daAlink* linkActrPtr);

        /**
         *  @brief Initializes the process used when delivering the final blow to Ganondorf.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if the action was successful, otherwise returns False.
         */
        bool procGanonFinishInit(daAlink* linkActrPtr);

        /**
         *  @brief Runs when delivering the final blow to Ganondorf.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if the action was successful, otherwise returns False.
         */
        bool procGanonFinish(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if link should be taking damage.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link should be taking damage, otherwise returns False.
         */
        bool checkDamageAction(daAlink* linkActrPtr);

        /**
         *  @brief Sets link's facial expression when getting an item
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param itemID The item to be checked.
         */
        void setGetItemFace(daAlink* linkActrPtr, uint16_t itemID);

        /**
         *  @brief Causes Human Link to take damage based on his interaction with certain things.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param obj A pointer to the object causing the damage.
         *  @param unk3 Unknown.
         *
         *  @return Bool returns True if Link successfully took damage, otherwise returns False.
         */
        bool procDamageInit(daAlink* linkActrPtr, void* obj, int32_t unk3);

        /**
         *  @brief Causes Wolf Link to take damage based on his interaction with certain things.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param obj A pointer to the object causing the damage.
         *
         *  @return Bool returns True if Link successfully took damage, otherwise returns False.
         */
        bool procWolfDamageInit(daAlink* linkActrPtr, void* obj);

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset | Flag
         *
         *  @return Bool returns True if the flag is set, otherwise returns False.
         */
        bool dComIfGs_isEventBit(uint16_t flag);

        /**
         *  @brief Checks to see if the currently targeted actor is able to be finished with the Ending Blow.
         *
         *  @param linkActrPtr A pointer to Link's Actor.
         *
         *  @return Bool returns True if the enemy can be finished, otherwise returns False.
         */
        bool checkDownAttackState(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link is moving while in a heavy state.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is moving while heavy, otherwise returns False.
         */
        bool checkBootsMoveAnime(daAlink* linkActrPtr, int32_t param_1);

        /**
         *  @brief Initializes the process that runs when Link talks to a character.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void procCoTalkInit(daAlink* linkActrPtr);

        /**
         *  @brief The function process that runs when Link collects an item.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void procCoGetItem(daAlink* linkActrPtr);

        /**
         *  @brief Increases Link's maximum health by a determined amount and sets the currently filled hearts to the stated
         * count.
         *
         *  @param amount The amount in which to increase Link's maximum heart count (in 1/4 hearts).
         *  @param count The amount of filled hearts in which to increase Link's current health (in 1/4 hearts).
         */
        void dComIfGp_setItemLifeCount(float amount, uint8_t count);

        /**
         *  @brief Checks to see if Link is currently voiding out.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is voiding, otherwise returns False.
         */
        bool checkRestartRoom(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link has begun the warping process, either in the overworld or in a dungeon.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void checkWarpStart(daAlink* linkActrPtr);

        /**
         *  @brief Sets the model information for the Midna Charge attack including color, size, etc.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void setWolfLockDomeModel(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link is riding the Spinner and if so, returns a pointer to the Spinner's actor
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        libtp::tp::f_op_actor::fopAc_ac_c* getSpinnerActor(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link is trying to open a door near Bo
         *
         *  @param actrPtr A pointer to an actor near Link
         */
        libtp::tp::f_op_actor::fopAc_ac_c* searchBouDoor(libtp::tp::f_op_actor::fopAc_ac_c* actrPtr);

        /**
         *	@brief Checks for any factors that could increase the damage Link takes.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param param_1 Unknown
         *  @param param_2 Unknown
         *
         *  @return Returns a float that is the multiplier for the damage Link takes.
         */
        float damageMagnification(daAlink* linkActrPtr, int32_t param_1, int32_t param_2);

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset+Flag
         */
        bool dComIfGs_isEventBit(uint16_t flag);

        extern ClimbVars climbVars;
        extern LinkStatus* linkStatus;
        extern WallMoveVars wallMoveVars;
        extern uint8_t getSeType[0x100];
        extern daAlinkHIO_kandelaar_c0 lanternVars;
        extern daAlinkHIO_magneBoots_c0 ironBootsVars;
        extern daAlinkHIO_huLight_c0 huLightVars;
    }
} // namespace libtp::tp::d_a_alink
#endif