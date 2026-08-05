/**	@file J3DMatBlock.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_J3DMATBLOCK_H
#define TP_J3DMATBLOCK_H

#include <cstdint>

namespace libtp::tp
{

    struct J3DTevBlock {
        uint32_t field_0x0;
        uint32_t mTexNoOffset;
    } __attribute__((__packed__));

extern "C" {
    //void setTevColor(libtp::tp::J3DTevBlock amog, uint32_t param_0, const GXColorS10* icolor);
}
}
#endif /* TP_J3DMATBLOCK_H */