/**	@file f_pc_executor.h
 *	@brief Contains functions that handle actor process events
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_F_PC_EXECUTOR_H
#define TP_F_PC_EXECUTOR_H

#include <cstdint>

namespace libtp::tp::f_pc_executor
{
    extern "C"
    {
        /**
         *	@brief Checks to see if the actor process exists
         *
         *	@param id The id of the actor process event.
         *  @return BOOL returns True if found, otherwise returns False
         */
        int32_t fpcEx_IsExist(uint32_t id);
    }
} // namespace libtp::tp::f_pc_executor
#endif