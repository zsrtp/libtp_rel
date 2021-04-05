/**	@file timer.cpp
 *  @brief Simple timer classes to schedule function calls
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#include "chronos/timer.h"

namespace libtp::chronos
{
    IntervalTimer::IntervalTimer( uint32_t interval, handler handler ): m_Interval( interval ), m_Handler( handler ) {}

    void IntervalTimer::tick()
    {
        // When ticks is a multiple of interval, trigger the handler function
        if ( 0 == m_TotalTicks % m_Interval )
        {
            m_ExecCount++;
            m_Handler( this );
        }
        m_TotalTicks++;
    }
}     // namespace libtp::chronos
