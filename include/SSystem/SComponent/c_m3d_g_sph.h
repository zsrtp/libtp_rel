/**	@file c_m3d_g_sph.h
 *	@brief See https://github.com/zeldaret/tp/blob/main/include/SSystem/SComponent/c_m3d_g_sph.h
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_C_M3D_G_SPH_H
#define TP_C_M3D_G_SPH_H

#include <cstdint>
#include "dolphin/mtx/vec.h"

namespace libtp::tp
{
    struct cM3dGSphS
    {
        Vec mCenter;
        float mRadius;
    } __attribute__((__packed__));

    static_assert(sizeof(cM3dGSphS) == 0x10);

} // namespace libtp::tp
#endif