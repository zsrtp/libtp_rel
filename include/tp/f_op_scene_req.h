/**	@file f_op_scene_req.h
 *	@brief Holds symbols of the f_op_scene_req field
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef TP_F_OP_SCENE_REQ_H
#define TP_F_OP_SCENE_REQ_H

#include <cstdint>

namespace libtp::tp::f_op_scene_req
{
    extern "C"
    {
        extern bool freezeActors;     // Freezes all actors
        extern int32_t isLoading;     // Current loading status
    }
}     // namespace libtp::tp::f_op_scene_req
#endif