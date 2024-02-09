/**	@file bmgres.h
 *	@brief Contains structures to handle BMG files.
 *
 *	This helps when intercepting text the game is trying to load.
 *
 *	@author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_BMGRES_H
#define TP_BMGRES_H

#include <cstdint>

namespace libtp::tp::bmgres
{
    struct FileHeader
    {
        uint8_t misc[0x100]; // Very start of the file; Should define at some point
    } __attribute__((__packed__));

    struct BMGHeader
    {
        char signature[4];
        char identifier[4];
        uint32_t dataSize;
        uint32_t numBlocks;
        uint8_t charset;
        uint8_t unk_11;
        uint16_t unk_12;
        int32_t unk_14[2];
        int32_t unk_1c;
    } __attribute__((__packed__));

    struct MessageEntry
    {
        uint32_t offsetToMessage;
        uint16_t messageId;
        uint8_t unk[0xE];
    } __attribute__((__packed__));

    struct TextIndexTable
    {
        char kind[4]; // Should be INF1 in ASCII
        uint32_t size;
        uint16_t numEntries;
        uint16_t entrySize;
        uint16_t groupId;
        uint8_t defaultColor;
        uint8_t unk;
        MessageEntry entry[]; // Amount of entries is numEntries
    } __attribute__((__packed__));

    static_assert(sizeof(FileHeader) == 0x100);
    static_assert(sizeof(BMGHeader) == 0x20);
    static_assert(sizeof(MessageEntry) == 0x14);
} // namespace libtp::tp::bmgres
#endif