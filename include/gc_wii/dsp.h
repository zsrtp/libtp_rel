#ifndef GC_DSP_H
#define GC_DSP_H

#include "gc_wii/OSTime.h"

#include <cstdint>

namespace libtp::gc_wii::dsp
{
    // Taken from https://github.com/TakaRikka/dolsdk2004/blob/card/include/dolphin/dsp.h
    typedef void (*DSPCallback)(void* task);

    struct DSPTaskInfo
    {
        /*0x00*/ volatile uint32_t state;
        /*0x04*/ volatile uint32_t priority;
        /*0x08*/ volatile uint32_t flags;
        /*0x0C*/ uint16_t* iram_mmem_addr;
        /*0x10*/ uint32_t iram_length;
        /*0x14*/ uint32_t iram_addr;
        /*0x18*/ uint16_t* dram_mmem_addr;
        /*0x1C*/ uint32_t dram_length;
        /*0x20*/ uint32_t dram_addr;
        /*0x24*/ uint16_t dsp_init_vector;
        /*0x26*/ uint16_t dsp_resume_vector;
        /*0x28*/ DSPCallback init_cb;
        /*0x2C*/ DSPCallback res_cb;
        /*0x30*/ DSPCallback done_cb;
        /*0x34*/ DSPCallback req_cb;
        /*0x38*/ DSPTaskInfo* next;
        /*0x3C*/ DSPTaskInfo* prev;
        /*0x40*/ OSTime t_context;
        /*0x48*/ OSTime t_task;
    } __attribute__((__packed__));

    static_assert(sizeof(DSPTaskInfo) == 0x50);
} // namespace libtp::gc_wii::dsp
#endif