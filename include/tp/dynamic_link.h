/**	@file dynamic_link.h
 *	@brief DynamicModuleControl field
 *
 *  @author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_DYNAMIC_LINK_H
#define TP_DYNAMIC_LINK_H

#include <cstdint>

#include "gc_wii/OSModule.h"

namespace libtp::tp::dynamic_link
{
    // Should try to fill in the variables at some point
    struct DynamicModuleControl
    {
        uint8_t unk_0[0x10];
        gc_wii::os_module::OSModuleInfo* moduleInfo;
        uint8_t unk_10[0x18];
    } __attribute__( ( __packed__ ) );

    // This size may not be correct
    static_assert( sizeof( DynamicModuleControl ) == 0x2C );

    extern "C"
    {
        bool do_link( DynamicModuleControl* dmc );
        bool do_unlink( DynamicModuleControl* dmc );
    }
}     // namespace libtp::tp::dynamic_link
#endif