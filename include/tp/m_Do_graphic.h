/**	@file m_Do_graphic.h
 *	@brief Holds function definitions for graphical calls
 *
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_GRAPHIC_H
#define TP_M_DO_GRAPHIC_H

#include <cstdint>

namespace libtp::tp::m_Do_graphic
{
    extern "C"
    {
#ifdef PLATFORM_WII
        /**
         * @brief Boolean value which is true when the wii is set in 16:9 mode.
         * 
         */
        extern bool m_isWide;
#endif
    }
} // namespace libtp::tp::m_Do_graphic
#endif