/**	@file m_do_printf.h
 *	@brief Holds symbols of the m_do_printf field
 *
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_PRINTF_H
#define TP_M_DO_PRINTF_H

#include <cstdarg>

namespace libtp::tp::m_Do_printf
{
    extern "C"
    {
        /**
         *	@brief Prints the specified message to the OS.
         *
         *  @param string The message to print.
         */
        void OSReport(const char* string, ...);
        void OSReport_Error(const char* fmt, ...);
        void OSReport_FatalError(const char* fmt, ...);
        void OSReport_System(const char* fmt, ...);
        void OSReport_Warning(const char* fmt, ...);
        void OSReportDisable(void);
        void OSReportEnable(void);
    }
} // namespace libtp::tp::m_Do_printf

#endif