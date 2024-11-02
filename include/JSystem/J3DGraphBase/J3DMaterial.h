/**	@file J3DMaterial.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_J3DMATERIAL_H
#define TP_J3DMATERIAL_H

#include <cstdint>
#include "J3DMatBlock.h"
#include "tp/J3DShape.h"

namespace libtp::tp
{

    class J3DMaterial {
        /* 0x00 */ uint8_t field_0x0[0x8];
        /* 0x08 */ libtp::tp::J3DShape::J3DShape* mShape;
        /* 0x0C */ uint8_t field_0x0c[0x2C-0x0C];
        /* 0x2C */ J3DTevBlock* mTevBlock;
        /* 0x30 */ uint8_t field_0x30[0x4C-0x30];
    } __attribute__((__packed__));

    static_assert(sizeof(J3DMaterial) == 0x4C);
}
#endif /* TP_J3DMATERIAL_H */