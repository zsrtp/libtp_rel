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
    struct DynamicModuleControlBase
    {
        uint16_t mLinkCount;
        uint16_t mDoLinkCount;
        DynamicModuleControlBase* mPrev;
        DynamicModuleControlBase* mNext;
        void* vtable;
    } __attribute__( ( __packed__ ) );

    struct DynamicModuleControl: DynamicModuleControlBase
    {
        gc_wii::os_module::OSModuleInfo* mModule;
        void* mBss;
        uint32_t unk_24;
        const char* mName;
        uint8_t mResourceType;
        uint8_t unk_33;
        uint16_t mChecksum;
        int32_t mSize;
        void* mAsyncLoadCallback;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( DynamicModuleControlBase ) == 0x10 );
    static_assert( sizeof( DynamicModuleControl ) == 0x2C );

    extern "C"
    {
        DynamicModuleControl* DynamicModuleControl_ct( DynamicModuleControl* dmc, const char* name );
        bool do_link( DynamicModuleControl* dmc );
        bool do_unlink( DynamicModuleControl* dmc );

        extern void* m_heap;
    }

    namespace DynamicModuleControlBase
    {
        extern "C"
        {
            extern void* m_heap;
        }
    }     // namespace DynamicModuleControlBase
}     // namespace libtp::tp::dynamic_link
#endif