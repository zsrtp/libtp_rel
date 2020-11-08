/**	@file d_a_shop_item_static.h
 *	@brief Holds definitions about the d_a_alink field
 *
 *	The d_a_alink field holds various functions and variables about Link
 *	and his current state
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::d_a_shop_item_static
{
	enum ShopItemDataIndex : uint8_t
	{
		Sold_Out =             0x0,
		Lantern_Oil =          0x1, // Item Id = 0x66
		Red_Potion =           0x2, // Item Id = 0x61
		Milk =                 0x3, // Item Id = 0x64
		Sera_Bottle =          0x4, // Item Id = 0x65
		Arrows =               0x5, // Item Id = 0xE to 0x10
		Wooden_Shield =        0x6, // Item Id = 0x2B
		Hylian_Shield =        0x7, // Item Id = 0x2C
		Bombs =                0x8, // Item Id = 0xA to 0xD
		Bomb_Bag_Water_Bombs = 0x9, // Item Id = 0x71 -- Uses Water Bomb model
		Bomb_Bag_Bomblings =   0xA, // Item Id = 0x72 -- Uses Bombling model
		Empty_Bomb_Bag =       0xB, // Item Id = 0x50 -- Possibly handles multiple different bomb bags
		Giant_Bomb_Bag =       0xC, // Item Id = 0x4F
		Land_Mine =            0xD, // Unused in getShopArcname
		Bottle =               0xE, // Unused in getShopArcname
		Bee_Larva =            0xF, // Item Id = 0x76
		Slingshot =            0x10, // Item Id = 0x4B
		Blue_Potion =          0x11, // Item Id = 0x63
		Hawkeye =              0x12, // Item Id = 0x3E
		Magic_Armor =          0x13, // Item Id = 0x30
		Magic_Armor_Sold_Out = 0x14,
		Green_Potion =         0x15, // Item Id = 0x62
		Jovani_Bottle =        0x16, // Item Id = 0x75
	};
	
	struct ShopItemData
	{
		const char* arcName;
		int16_t modelResIdx;
		int16_t wBtkResIdx;
		int16_t unk_8;
		int16_t wBckResIdx;
		int16_t unk_C;
		int16_t wBrkResIdx;
		int16_t wBtpResIdx;
		int16_t unk_12;
		float posY;
		float scale;
		int16_t wRot[4];
		uint32_t mFlags;
		uint8_t mShadowSize;
		uint8_t mCollisionH;
		uint8_t mCollisionR;
		uint8_t tevFrm;
		uint8_t btpFrm;
		uint8_t unk_2D[3];
	} __attribute__((__packed__));

	static_assert(sizeof(ShopItemData) == 0x30);

	extern "C"
	{
		extern ShopItemData shopItemData[23]; // mData__12daShopItem_c
	}
}