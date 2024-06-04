#ifndef GC_WII_OSTHREAD_H
#define GC_WII_OSTHREAD_H

#include <cstdint>

namespace libtp::gc_wii::os_thread
{
    // Taken from https://github.com/TakaRikka/dolsdk2004/blob/card/include/dolphin/os/OSThread.h
    struct OSThread;

    struct OSThreadQueue
    {
        OSThread* head;
        OSThread* tail;
    } __attribute__((__packed__));

    static_assert(sizeof(OSThreadQueue) == 0x8);
} // namespace libtp::gc_wii::os_thread
#endif