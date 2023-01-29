#ifndef GC_WII_OSINTERRUPT_H
#define GC_WII_OSINTERRUPT_H

#include <cstdint>

namespace libtp::gc_wii::os_interrupt
{
    extern "C"
    {
        bool OSDisableInterrupts();
        bool OSEnableInterrupts();
        bool OSRestoreInterrupts( bool enable );
    }
}     // namespace libtp::gc_wii::os_interrupt
#endif