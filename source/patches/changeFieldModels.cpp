#include "patches/changeFieldModels.h"

#include <cstdint>
#include <cstring>

#include "items.h"
#include "tp/d_item_data.h"

namespace libtp::patches
{
    void changeFieldModels()
    {
        libtp::tp::d_item_data::ItemResource* itemResPtr = &libtp::tp::d_item_data::item_resource[0];
        libtp::tp::d_item_data::FieldItemRes* fieldItemResPtr = &libtp::tp::d_item_data::field_item_res[0];

        uint32_t loopCount = sizeof( itemsWithNoFieldModel ) / sizeof( itemsWithNoFieldModel[0] );
        for ( uint32_t i = 0; i < loopCount; i++ )
        {
            uint32_t item = itemsWithNoFieldModel[i];     // Retrieve as u32 to prevent rlwinm shenanigans
            fieldItemResPtr[item].arcName = itemResPtr[item].arcName;
            fieldItemResPtr[item].modelResIdx = itemResPtr[item].modelResIdx;
        }

        // For items that dont have a field model, use rupee item info to allow the item to be collected and whatnot
        // Using the yellow rupee because thats what i used in testing
        libtp::tp::d_item_data::ItemInfo* itemInfoPtr = &libtp::tp::d_item_data::item_info[items::Piece_of_Heart];

        for ( uint32_t i = 0; i < loopCount; i++ )
        {
            uint32_t item = itemsWithNoFieldModel[i];     // Retrieve as u32 to prevent rlwinm shenanigans
            itemInfoPtr[item].mShadowSize = itemInfoPtr->mShadowSize;
            itemInfoPtr[item].mCollisionH = itemInfoPtr->mCollisionH;
            itemInfoPtr[item].mCollisionR = itemInfoPtr->mCollisionR;
            itemInfoPtr[item].mFlags = itemInfoPtr->mFlags;
        }

        // Modify a branch in itemGetNextExecute to allow the item get cutscene to play with items past 0x40
        // If you already have the item it gives you, then itll act like a rupee and appear over your head. This could be
        // changed though.
        uint32_t* address;
#ifdef TP_US
        address = reinterpret_cast<uint32_t*>( 0x8015CF64 );
#elif defined TP_JP
        address = reinterpret_cast<uint32_t*>( 0x8015CFB0 );
#elif defined TP_EU
        address = reinterpret_cast<uint32_t*>( 0x8015D170 );
#endif

        *address = 0x48000018;     // b 0x18
    }

    uint8_t itemsWithNoFieldModel[0x6A] = {
        0xA,  0xB,  0xC,  0xD,  0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1C, 0x1D, 0x29, 0x2B, 0x2C, 0x32, 0x35, 0x36,
        0x3D, 0x3E, 0x40, 0x41, 0x42, 0x43, 0x44, 0x45, 0x46, 0x47, 0x49, 0x4A, 0x4B, 0x4C, 0x4F, 0x50, 0x51, 0x55,
        0x56, 0x60, 0x61, 0x63, 0x64, 0x65, 0x66, 0x67, 0x6D, 0x6F, 0x75, 0x80, 0x81, 0x83, 0x84, 0x90, 0x91, 0x9D,
        0x9E, 0xA1, 0xA2, 0xA3, 0xA5, 0xA6, 0xA7, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4, 0xB5, 0xC0, 0xC1, 0xC2, 0xC3, 0xC4,
        0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0xD5, 0xD6,
        0xD7, 0xE0, 0xE9, 0xEA, 0xEB, 0xED, 0xEE, 0xF3, 0xF4, 0xF5, 0xF6, 0xF9, 0xFA, 0xFB, 0xFD, 0xFE };
}     // namespace libtp::patches