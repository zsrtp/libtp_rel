/**	@file OSContext.h
 *	@brief Holds OSContext definitions from dolphin OS
 *
 *	For additional information check the dolphin OS manual
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef GC_WII_OSCONTEXT_H
#define GC_WII_OSCONTEXT_H

#include <cstdint>

namespace libtp::gc_wii::os_context
{
    struct OSContext
    {
        uint32_t gpr[32];
        uint32_t cr;
        uint32_t lr;
        uint32_t ctr;
        uint32_t xer;
        double fpr[32];
        uint32_t fpscrPad;
        uint32_t fpscr;
        uint32_t srr0;
        uint32_t srr1;
        uint16_t mode;
        uint16_t state;
        uint32_t gqr[8];
        uint32_t psfPad;
        double psf[32];
    } __attribute__((__packed__));

    static_assert(sizeof(OSContext) == 0x2C8);
} // namespace libtp::gc_wii::os_context

#endif