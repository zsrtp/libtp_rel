/**	@file d_item_data.h
 *	@brief Holds structs that contain values for item data
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_ITEM_DATA_H
#define TP_D_ITEM_DATA_H

#include <cstdint>

#include "tp/d_stage.h"

namespace libtp::tp::d_item_data
{
    struct ItemResource
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

    struct FieldItemRes
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
        extern ItemResource item_resource[255];
        extern FieldItemRes field_item_res[255];
        extern ItemInfo item_info[255];
    }
} // namespace libtp::tp::d_item_data
#endif