
/**	@file d_stage.h
 *	@brief Stage related functions and fields
 *
 *	@author AECX
 *  @author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_STAGE_H
#define TP_D_STAGE_H

#include <cstdint>

#include "dzx.h"
#include "SSystem/SComponent/c_sxyz.h"
#include "SSystem/SComponent/c_xyz.h"

namespace libtp::tp::d_stage
{
    struct dStage_roomControl
    {
        uint8_t field_0x0[164];
    } __attribute__( ( __packed__ ) );

    struct dStage_startStage
    {
        /* 0x0 */ char mStage[8];
        /* 0x8 */ int16_t mPoint;
        /* 0xA */ int8_t mRoomNo;
        /* 0xB */ int8_t mLayer;
        /* 0xC */ int8_t mDarkArea;
        /* 0xD */ uint8_t padding;
    } __attribute__( ( __packed__ ) );

    struct dStage_nextStage
    {
        dStage_startStage stageValues;
        int8_t enabled;
        uint8_t wipe;
        uint8_t wipe_speed;
    } __attribute__( ( __packed__ ) );

    struct stage_actor_data_class
    {
        /* 0x00 */ char mName[8];
        /* 0x08 */ uint32_t mParameter;
        /* 0x0C */ cXyz mSpawnPos;
        /* 0x18 */ csXyz mAngle;
        /* 0x1E */ uint16_t mEnemyNo;
    } __attribute__( ( __packed__ ) );     // Size: 0x20

    struct stage_dzr_header_entry
    {
        /* 0x00 */ char mName[4];
        /* 0x04 */ int32_t mNumEntries;
        /* 0x08 */ stage_actor_data_class* mDzrDataPointer;
    } __attribute__( ( __packed__ ) );     // size: 0xC

    struct stage_actor_class
    {
        /* 0x0 */ int32_t mEntryNum;
        /* 0x4 */ stage_actor_data_class* mEntries;
    } __attribute__( ( __packed__ ) );

    extern "C"
    {
        /**
         *	@brief Used for treasure initialisation (not just chests)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        void setTresure( void* unk1 );     // Yes they spell it Tresure

        /**
         *  @brief Initialises TRES for a given room
         *
         *  @param chunkTypeInfo Pointer to the TRES chunk metadata
         */
        void roomTresureInit( void* unk1, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4 );

        /**
         *  @brief Initialises Actors, can run multiple times per load - Global Based on Room
         *
         *  @param mStatus_roomControl Pointer to roomControl data (unknown)
         *  @param chunkTypeInfo Pointer to dzxHeader
         *  @param unk3 unknown
         *  @param unk4 unknown
         */
        bool actorCommonLayerInit( void* mStatus_roomControl, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4 );

        /**
         *  @brief Initialises Actors for current layer, can run multiple times per load
         *
         *  @param mStatus_roomControl Pointer to roomControl data (unknown)
         *  @param chunkTypeInfo Pointer to dzxHeader
         *  @param unk3 unknown
         *  @param unk4 unknown
         */
        bool actorInit( void* mStatus_roomControl, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4 );

        /**
         *  @brief Initialises Actors for global layer, can run multiple times per load
         *
         *  @param mStatus_roomControl Pointer to roomControl data (unknown)
         *  @param chunkTypeInfo Pointer to dzxHeader
         *  @param unk3 unknown
         *  @param unk4 unknown
         */
        bool actorInit_always( void* mStatus_roomControl, dzx::ChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4 );

        /**
         *  @brief Creates an actor
         *
         *  @param Actor Actor Object
         *  @param ActorMemoryPtr ActorPRMClass allocated for this Actor
         */
        void ActorCreate( dzx::ACTR* actor, dzx::ActorPRMClass* actorMemoryPtr );

        /**
         *  @brief Creates a number of SCOBs defined in a list.
         *
         *  @param stageDt The pointer to the stage data.
         *  @param i_data The pointer to the list of SCOBs to be read in.
         *  @param entryNum The number of entries to be read in.
         *  @param param_3 Unknown at this time.
         */
        int32_t tgscInfoInit( void* stageDt, void* i_data, int32_t entryNum, void* param_3 );

        void roomLoader( void* data, void* stageDt, int roomNo );

        void stageLoader( void* data, void* stageDt );

        int dStage_playerInit( void* stageDt, stage_dzr_header_entry* i_data, int num, void* raw_data );

        /**
         *  @brief Pointer to roomControl data
         */
        extern void* mStatus_roomControl;
    }
}     // namespace libtp::tp::d_stage
#endif