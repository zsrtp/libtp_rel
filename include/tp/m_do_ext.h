/**	@file m_do_ext.h
 *	@brief Holds symbols of the m_do_ext field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_EXT_H
#define TP_M_DO_EXT_H

namespace libtp::tp::m_Do_ext
{
    extern "C"
    {
        extern void* AssertHeap;
        extern void* DbPrintHeap;
        extern void* gameHeap;
        extern void* zeldaHeap;
        extern void* commandHeap;
        extern void* archiveHeap;     // Archive heap pointer
        extern void* j2dHeap;

        void* mDoExt_getMesgFont();

#ifndef PLATFORM_WII
        extern void* HostIOHeap;
#endif     // PLATFORM_WII
    }
}     // namespace libtp::tp::m_Do_ext
#endif