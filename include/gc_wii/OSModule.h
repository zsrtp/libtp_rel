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
    } __attribute__( ( __packed__ ) );

}     // namespace libtp::gc_wii::os_module
#endif