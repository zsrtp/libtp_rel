  
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

namespace libtp::tp::d_stage
{
    struct dStage_roomControl
    {
        uint8_t field_0x0[164];
    } __attribute__((__packed__));

    struct dStage_startStage
    {
        
        /* 0x0 */ char mStage[8];
        /* 0x8 */ int16_t mPoint;
        /* 0xA */ int8_t mRoomNo;
        /* 0xB */ int8_t mLayer;
        /* 0xC */ int8_t mDarkArea;    
    } __attribute__((__packed__));

    struct dStage_nextStage
    {
        char mStage[8];
        int16_t mPoint;
        uint8_t mRoomNo;
        uint8_t mLayer;
        uint8_t field_0xc;
        uint8_t field_0xd;
        int8_t enabled;
        uint8_t wipe;
        uint8_t wipe_speed;
    } __attribute__((__packed__));

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
         *  @brief Pointer to roomControl data
         */
        extern void* mStatus_roomControl;
    }
}  // namespace libtp::tp::d_stage
#endif