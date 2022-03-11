/**	@file m_do_memcard.h
 *	@brief Holds symbols of the m_do_memcard field
 *
 *	@author Zephiles
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_MEMCARD_H
#define TP_M_DO_MEMCARD_H

namespace libtp::tp::m_Do_MemCard
{
    extern "C"
    {
        extern uint8_t MemCardWorkArea0[0xA000];
    }
}     // namespace libtp::tp::m_Do_MemCard
#endif