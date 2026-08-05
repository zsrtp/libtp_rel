/**	@file J3DModelData.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_J3DMODELDATA_H
#define TP_J3DMODELDATA_H

#include <cstdint>
#include "J3DMaterialAttach.h"

namespace libtp::tp
{

    struct J3DModelData {
        /* 0x0 */ uint8_t field_0x0[0x58];
        /* 0x58 */ J3DMaterialTable mMaterialTable;
        /* 0x78 */ uint8_t unk1[0x6C];
    } __attribute__((__packed__));

    struct GXColorS10 {
        /* 0x0 */ int16_t r;
        /* 0x2 */ int16_t g;
        /* 0x4 */ int16_t b;
        /* 0x6 */ int16_t a;
    } __attribute__((__packed__));

    static_assert(sizeof(J3DModelData) == 0xE4);

    extern "C" {
        extern GXColorS10 j3dDefaultTevColor;
    }
}
#endif /* TP_J3DMODELDATA_H */