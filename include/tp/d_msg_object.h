/**	@file d_msg_object.h
 *	@brief Contains some of the functions used in getting the values for a message
 *
 *	@author Lunar Soap
 *  @author Zephiles
 *	@bug No known bugs.
 */
#pragma once
#include <cstdint>

namespace libtp::tp::d_msg_object
{
    struct StringDataTableEntry
    {
        uint32_t offsetToString;
        uint16_t stringId;
        uint8_t unk[0xE];
    } __attribute__((__packed__));

    struct StringDataTable
    {
        uint8_t unk_0[0x20];
        uint8_t unk_20[0x4];
        uint32_t stringsStartOffset;
        uint16_t totalEntries; // Should always be 5000
        uint16_t entrySize; // Should always be 0x14
        uint8_t unk_2c[0x4];
        StringDataTableEntry entry[5000];
    } __attribute__((__packed__));

    static_assert(sizeof(StringDataTableEntry) == 0x14);

    extern "C"
    {
        /**
         *	@brief Gets a pointer to the transparancy of the Z button
         *
         * @param param_1 - Unknown
         * @param itemIndex - The itemId of the item received + 0x65
         * @param param_3 - Unknown. I think it checks for a valid message but more research is needed
         */
        void setMessageIndex(uint32_t param_1, uint32_t itemIndex, bool param_3);
    }
}  // namespace libtp::tp::d_msg_object