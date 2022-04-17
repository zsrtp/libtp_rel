/**	@file m_do_printf.h
 *	@brief Holds symbols of the m_do_printf field
 *
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_EXT_H
#define TP_M_DO_EXT_H

#include <cstdarg>

namespace libtp::tp::m_Do_printf
{
    extern "C"
    {
        void OSReport( const char* string, ... );
    }
}     // namespace libtp::tp::m_Do_printf

#endif