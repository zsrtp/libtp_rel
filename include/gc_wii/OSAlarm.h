#ifndef GC_WII_OSALARM_H
#define GC_WII_OSALARM_H

#include "gc_wii/OSContext.h"
#include "gc_wii/OSTime.h"

#include <cstdint>

namespace libtp::gc_wii::os_alarm
{
    // Taken from https://github.com/TakaRikka/dolsdk2004/blob/card/include/dolphin/os/OSAlarm.h
    struct OSAlarm;
    typedef void (*OSAlarmHandler)(OSAlarm* alarm, os_context::OSContext* context);

    struct OSAlarm
    {
        OSAlarmHandler handler;
        uint32_t tag;
        OSTime fire;
        OSAlarm* prev;
        OSAlarm* next;
        OSTime period;
        OSTime start;
    } __attribute__((__packed__));

    static_assert(sizeof(OSAlarm) == 0x28);
} // namespace libtp::gc_wii::os_alarm
#endif