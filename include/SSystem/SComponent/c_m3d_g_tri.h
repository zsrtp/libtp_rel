/**	@file c_m3d_g_tri.h
 *	@brief See https://github.com/zeldaret/tp/blob/main/include/SSystem/SComponent/c_m3d_g_tri.h
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_C_M3D_G_TRI_H
#define TP_C_M3D_G_TRI_H

#include <cstdint>
#include "dolphin/mtx/vec.h"

namespace libtp::tp
{
    struct cM3dGTriS
    {
        Vec a;
        Vec b;
        Vec c;
    } __attribute__((__packed__));

    static_assert(sizeof(cM3dGTriS) == 0x24);

} // namespace libtp::tp
#endif