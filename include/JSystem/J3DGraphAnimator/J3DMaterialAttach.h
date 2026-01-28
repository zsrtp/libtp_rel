/**	@file J3DMaterialAttach.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_J3DMATERIALATTACH_H
#define TP_J3DMATERIALATTACH_H

#include <cstdint>
#include <JSystem/J3DGraphBase/J3DMaterial.h>

namespace libtp::tp
{

    struct J3DMaterialTable {
        /* 0x0 */ uint8_t field_0x0[8];
        /* 0x8 */ J3DMaterial** mMaterialNodePointer;
        uint8_t unk1[0x14];
    } __attribute__((__packed__));

    static_assert(sizeof(J3DMaterialTable) == 0x20);
}
#endif /* TP_J3DMATERIALATTACH_H */