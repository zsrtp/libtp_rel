/**	@file OSModule.h
 *	@brief Holds OSModule definitions (REL)
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef GC_WII_OSMODULE_H
#define GC_WII_OSMODULE_H

#include <cstdint>

namespace libtp::gc_wii::os_module
{
    struct OSModuleInfo
    {
        uint32_t id;
        OSModuleInfo* next;
        OSModuleInfo* prev;
        uint32_t numSections;
        uint32_t sectionInfoOffset;
        uint32_t nameOffset;
        uint32_t nameSize;
        uint32_t version;
        uint32_t bssSize;
        uint32_t relOffset;
        uint32_t impOffset;
        uint32_t impSize;
        uint8_t prologSection;
        uint8_t epilogSection;
        uint8_t unresolvedSection;
        uint8_t bssSection;
        uint32_t prologFuncOffset;
        uint32_t epilogFuncOffset;
        uint32_t unresolvedFuncOffset;
        uint32_t moduleAlignment;
        uint32_t bssAlignment;
        uint32_t fixSize;
    } __attribute__( ( __packed__ ) );

    struct OSModuleList
    {
        OSModuleInfo* first;
        OSModuleInfo* last;
        const char* unk;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( OSModuleInfo ) == 0x4C );
    static_assert( sizeof( OSModuleList ) == 0xC );

    extern "C"
    {
        bool OSLink( OSModuleInfo* newModule, void* bss );
        bool OSUnlink( OSModuleInfo* module );

        extern OSModuleList osModuleList;
    }
}     // namespace libtp::gc_wii::os_module
#endif