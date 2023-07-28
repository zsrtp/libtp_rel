
/**	@file timer.cpp
 *  @brief Simple timer classes to schedule function calls
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#include "chronos/timer.h"

namespace libtp::chronos
{
    IntervalTimer::IntervalTimer(uint32_t interval, TimerHandler handler): m_Interval(interval), m_Handler(handler) {}

    void IntervalTimer::tick()
    {
        // When ticks is a multiple of interval, trigger the handler function
        uint32_t totalTicks = m_TotalTicks;
        if (0 == totalTicks % m_Interval)
        {
            m_ExecCount++;
            m_Handler(this);
        }
        m_TotalTicks = totalTicks + 1;
    }
} // namespace libtp::chronos
