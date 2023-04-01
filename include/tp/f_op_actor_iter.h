/**	@file f_op_actor_iter.h
 *	@brief Contains functions used for iterating through and searching for actors.
 *
 *	@author Lunar Soap
 *	@bug
 */
#ifndef TP_F_OP_ACTOR_ITER_H
#define TP_F_OP_ACTOR_ITER_H

#include <cstdint>

namespace libtp::tp::f_op_actor_iter
{
    typedef void* ( *fopAcIt_JudgeFunc )( void*, void* );
    extern "C"
    {
        /**
         *	@brief Checks to see if the specified actor exists on the stage.
         *	@return Returns a pointer to the actor if it exists, otherwise returns a nullptr.
         */
        void* fopAcIt_Judge( fopAcIt_JudgeFunc, void* );
    }
}     // namespace libtp::tp::f_op_actor_iter

#endif