/**	@file d_pane_class_alpha.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_PANE_CLASS_ALPHA_H
#define TP_D_PANE_CLASS_ALPHA_H

#include <cstdint>

#include "tp/J2DWindow.h"

namespace libtp::tp::d_pane_class_alpha
{
    class CPaneMgrAlpha
    {
       public:
        /* 0x00 */ void* vtable;
        /* 0x04 */ libtp::tp::J2DWindow::J2DWindow* mWindow;
        /* 0x08 */ void* heap; // JKRExpHeap
        /* 0x0C */ void* mpFirstStackAlpha;
        /* 0x10 */ void* field_0x10;
        /* 0x14 */ int16_t mChildPaneCount;
        /* 0x16 */ int16_t mAlphaTimer;
        /* 0x18 */ uint8_t mInitAlpha;
        /* 0x19 */ uint8_t mFlags;
        /* 0x1A */ uint8_t padding[2];
    } __attribute__((__packed__));

} // namespace libtp::tp::d_pane_class_alpha
#endif