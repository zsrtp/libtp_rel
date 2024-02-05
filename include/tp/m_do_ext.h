/**	@file m_do_ext.h
 *	@brief Holds symbols of the m_do_ext field
 *
 *	@author Zephiles
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_EXT_H
#define TP_M_DO_EXT_H

#include "tp/J3DAnimation.h"

namespace libtp::tp::m_Do_ext
{
    struct mDoExt_baseAnm
    {
        /* 0x0 */ uint8_t mFrameCtrl[0x14]; // J3DFrameCtrl
    } __attribute__((__packed__));          // Size 0x14

    struct mDoExt_bckAnm: mDoExt_baseAnm
    {
        /* 0x14 */ void* mAnm;      // J3DAnmTransform*
        /* 0x18 */ void* mpMtxCalc; // J3DMtxCalc
    } __attribute__((__packed__));  // Size 0x1C

    struct mDoExt_AnmRatioPack
    {
        /* 0x0 */ float mRatio;
        /* 0x4 */ libtp::tp::J3DAnimation::J3DAnmTransform* mAnmTransform;
    } __attribute__((__packed__)); // Size 0x7

    static_assert(sizeof(mDoExt_baseAnm) == 0x14);
    static_assert(sizeof(mDoExt_bckAnm) == 0x1C);
    static_assert(sizeof(mDoExt_AnmRatioPack) == 0x8);
    extern "C"
    {
        extern void* AssertHeap;
        extern void* DbPrintHeap;
        extern void* gameHeap;
        extern void* zeldaHeap;
        extern void* commandHeap;
        extern void* archiveHeap; // Archive heap pointer
        extern void* j2dHeap;
#ifndef PLATFORM_WII
        extern void* HostIOHeap;
#endif  // PLATFORM_WII

        /**
         *	@brief Gets a pointer to the currently used message font.
         *
         *  @return Returns a pointer to the currently used font resources.
         */
        void* mDoExt_getMesgFont();

#ifndef PLATFORM_WII
        extern void* HostIOHeap;
#endif // PLATFORM_WII
    }
} // namespace libtp::tp::m_Do_ext
#endif