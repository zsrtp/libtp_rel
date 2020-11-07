/**	@file d_item_data.h
 *	@brief Holds structs that contain values for item data
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */

#pragma once

#include "d_stage.h"
#include <cstdint>

namespace tp::d_item_data
{

	struct ItemResource // d_item_data.h
	{
		const char* arcName;
		int16_t modelResIdx;
		int16_t btkResIdx;
		int16_t bckResIdx;
		int16_t brkResIdx;
		int16_t btpResIdx;
		uint8_t tevFrm;
		uint8_t btpFrm;
		int16_t ringTexResIdx;
		int16_t unk_12[3];
	} __attribute__((__packed__));

	struct FieldItemRes // d_item_data.h
	{
		const char* arcName;
		int16_t modelResIdx;
		int16_t bckAnmResIdx;
		int16_t brkAnmResIdx;
		int16_t unk_a;
		int16_t heapSize;
		int16_t unk_e;
	} __attribute__((__packed__));

	struct ItemInfo // d_item_data.h
	{
		uint8_t mShadowSize;
		uint8_t mCollisionH;
		uint8_t mCollisionR;
		uint8_t mFlags;
	} __attribute__((__packed__));

	

	

	static_assert(sizeof(ItemResource) == 0x18);
	static_assert(sizeof(FieldItemRes) == 0x10);
	static_assert(sizeof(ItemInfo) == 0x4);

	extern "C"
	{
		extern ItemResource item_resource[255]; // 0x803AC5A0 in US
		extern FieldItemRes field_item_res[255]; // 0x803ADD88 in US
		extern ItemInfo item_info[255]; // 0x803AED78 in US
	}
}