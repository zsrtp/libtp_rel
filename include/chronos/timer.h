/**	@file timer.h
 *  @brief Simple timer classes to schedule function calls
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef LIBTP_CHRONOS_H
#define LIBTP_CHRONOS_H

#include <cstdint>

namespace libtp::chronos
{
    class Timer
    {
       public:
        /**
         *  @brief Advance this timer by 1
         */
        virtual void tick();

        // Number of ticks
        uint32_t m_TotalTicks;
        // Number of executions
        uint32_t m_ExecCount;
    };

    // Handler Function for Timers
    typedef void ( *handler )( Timer* );

    class IntervalTimer: public Timer
    {
       public:
        /**
         *  @brief Simple timer to schedule periodic function calls.
         *
         *  A timer that calls a function periodically at a given rate
         *
         *  @param interval When m_TotalTicks is a multiple of interval it will trigger the function
         *  @param function The function that handles this timer event
         */
        IntervalTimer( uint32_t interval, handler hanlder );

        void tick() override;

       private:
        uint32_t m_Interval;
        handler m_Handler;
    };
}     // namespace libtp::chronos
#endif