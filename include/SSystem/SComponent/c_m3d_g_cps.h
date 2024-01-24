/**	@file c_m3d_g_cps.h
 *	@brief See https://github.com/zeldaret/tp/blob/main/include/SSystem/SComponent/c_m3d_g_cps.h
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_C_M3D_G_CPS_H
#define TP_C_M3D_G_CPS_H

#include <cstdint>
#include "dolphin/mtx/vec.h"

namespace libtp::tp
{
    struct cM3dGCpsS
    {
        /* 0x00 */ Vec mStart;
        /* 0x0C */ Vec mEnd;
        /* 0x18 */ float mRadius;
    } __attribute__((__packed__)); // Size: 0x1C

    static_assert(sizeof(cM3dGCpsS) == 0x1C);

} // namespace libtp::tp
#endif