/**	@file JUTNameTab.h
 *	@brief Holds symbols of the JKRHeap field
 *
 *	@author Jasper St. Pierre
 *	@author lepelog
 *	@bug No known bugs.
 */
#ifndef TP_JUTNAMETAB_H
#define TP_JUTNAMETAB_H

#include <cstdint>

namespace libtp::tp::JUTNameTab
{
    struct ResNTAB
    {
        uint16_t mEntryNum;
        uint16_t mPad0;
        struct Entry
        {
            uint16_t mKeyCode;
            uint16_t mOffs;
        } mEntries[1];

        inline const char* getName(uint32_t index) const { return reinterpret_cast<const char*>(mEntries) + mEntries[index].mOffs - 4; }
    } __attribute__((__packed__));

    struct JUTNameTab
    {
        /* 0x0 */ void* vtable;
        /* 0x4 */ const ResNTAB* mNameTable;
        /* 0x8 */ const char* mpStrData;
        /* 0xC */ uint16_t mNameNum;
    } __attribute__((__packed__)); // Size: 0xE

    static_assert(sizeof(JUTNameTab) == 0xE);

} // namespace libtp::tp::JUTNameTab

#endif /* TP_JUTNAMETAB_H */