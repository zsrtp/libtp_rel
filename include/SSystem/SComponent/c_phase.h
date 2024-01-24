/**	@file c_phase.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/SSystem/SComponent/c_phase.h
 *
 *	@author Lunar Soap
 *	@bug
 */
#ifndef TP_C_PHASE_H
#define TP_C_PHASE_H

#include <cstdint>

namespace libtp::tp
{
    typedef int (*cPhs__Handler)(void*);
    typedef struct request_of_phase_process_class
    {
        cPhs__Handler* mpHandlerTable;
        int32_t id;
    } request_of_phase_process_class;

    static_assert(sizeof(request_of_phase_process_class) == 0x8);
} // namespace libtp::tp

#endif