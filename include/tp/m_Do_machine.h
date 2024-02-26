/**	@file m_Do_machine.h
 *	@brief Holds function definitions for exception management
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_MACHINE_H
#define TP_M_DO_MACHINE_H

#include <cstdint>
#include "gc_wii/OSContext.h"

namespace libtp::tp::m_Do_machine
{
    extern "C"
    {
        void myExceptionCallback(uint16_t error, libtp::gc_wii::os_context::OSContext* context, uint32_t dsisr, uint32_t dar);
    }
} // namespace libtp::tp::m_Do_machine
#endif