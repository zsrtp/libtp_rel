/**	@file d_stage.h
 *	@brief Stage related functions and fields
 *
 *	@author AECX
 *  @author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */

#pragma once
#include <cstdint>

namespace libtp::tp::d_stage
{
    /**
	 *  @brief Holds information about the TRES actor being loaded
	 *
	 *  Example:
	 *  tboxA0
	 *  0FF6
     *  3810.844000 
     *  -3535.530000
     *  11344.890000
     *  -180.00
     *  4
     *  FF
	 */

	struct TRES
	{
		char actorName[8];
		uint32_t flags;

		float X;
		float Y;
		float Z;

		int32_t angle;

		uint8_t item;
		uint8_t unk2[3];  // Seems to always be 0xFF

		TRES() { memset(this, 0xFF, sizeof(TRES)); }
	} __attribute__((__packed__));
    
    /**
     *  @brief Holds information about the given Actr that is being loaded
     *
     *  Example:
     *  htpiece
     *  00FF8021
     *  -2242.000000, 504.000000, 567.000000
     *  0.00, 0.00, 0.00
     *  FFFF 
     */
    struct Actr
	{
		char objectName[8];
		uint32_t parameters;
		float pos[3];
		int16_t rot[3];
		uint16_t enemyNum;
	} __attribute__((__packed__));

    /**
     *  @brief Holds information about field items (i.e rupees)
     *
     *  Example:
     *  item
     *  F3
     *  65
     *  8B
     *  01
     *  -3725.78200, -659.661100, 6770.38000
     *  0.00, 90.00, 0.35
     *  FFFF 
     */
    struct Item
	{
		char objectName[8];
		uint8_t paramOne;
		uint8_t paramTwo;
		uint8_t membitFlag;
		uint8_t item;
		float pos[3];
		int16_t rot[3];
		uint16_t enemyNum;
	} __attribute__((__packed__));
    
    /**
     *  @brief Holds information about the given dzx Chunktype
     *
     *  Example:
     *  TRES
     *  0001
     *  80401234 = 1 TRES Chunk at this address
     */
    struct dzxChunkTypeInfo
    {
        char tag[4];
        uint32_t numChunks;
        void* chunkDataPtr;
    };

    static_assert(sizeof(TRES) == 0x20);
	static_assert(sizeof(Actr) == 0x20);
    static_assert(sizeof(Item) == 0x20);
	static_assert(sizeof(dzxChunkTypeInfo) == 0xC);

    extern "C"
    {
        /**
         *	@brief Used for treasure initialisation (not just chests)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        void setTresure(void* unk1);  // Yes they spell it Tresure

        /**
         *  @brief Initialises TRES for a given room
         *
         *  @param chunkTypeInfo Pointer to the TRES chunk metadata
         */
        void roomTresureInit(void* unk1, dzxChunkTypeInfo* chunkTypeInfo, int32_t unk3, void* unk4);

        /**
		 *  @brief Initialises Actors, can run multiple times per load - Global Based on Room
		 *
		 *  @param mStatus_roomControl Pointer to roomControl data (unknown)
		 *  @param chunkTypeInfo Pointer to dzxHeader
		 *  @param unk3 unknown
		 *  @param unk4 unknown
		 */
		bool actorCommonLayerInit(void* mStatus_roomControl, dzxChunkTypeInfo* chunkTypeInfo, int unk3, void* unk4);
		
        /**
		 *  @brief Initialises Actors, can run multiple times per load - Layer Based on Stage
		 *
		 *  @param mStatus_roomControl Pointer to roomControl data (unknown)
		 *  @param chunkTypeInfo Pointer to dzxHeader
		 *  @param unk3 unknown
		 *  @param unk4 unknown
		 */
        bool actorInit(void* mStatus_roomControl, dzxChunkTypeInfo* chunkTypeInfo, int unk3, void* unk4);
		
        /**
		 *  @brief Initialises Actors, can run multiple times per load - Layer Based on Room
		 *
		 *  @param mStatus_roomControl Pointer to roomControl data (unknown)
		 *  @param chunkTypeInfo Pointer to dzxHeader
		 *  @param unk3 unknown
		 *  @param unk4 unknown
		 */
        bool roomTresureInit(void* mStatus_roomControl, dzxChunkTypeInfo* chunkTypeInfo, int unk3, void* unk4);
        
        /**
		 *  @brief Pointer to roomControl data
		 */
        extern void* mStatus_roomControl;
    }
}  // namespace libtp::tp::d_stage