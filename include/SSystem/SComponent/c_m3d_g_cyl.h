/**	@file c_m3d_g_cyl.h
 *	@brief See https://github.com/zeldaret/tp/blob/main/include/SSystem/SComponent/c_m3d_g_cyl.h
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_C_M3D_G_CYL_H
#define TP_C_M3D_G_CYL_H

#include <cstdint>
#include "dolphin/mtx/vec.h"

namespace libtp::tp
{
    struct cM3dGCylS
    {
        /* 0x00 */ Vec mCenter;
        /* 0x0C */ float mRadius;
        /* 0x10 */ float mHeight;
    } __attribute__((__packed__)); // Size = 0x14

    static_assert(sizeof(cM3dGCylS) == 0x14);

} // namespace libtp::tp
#endif