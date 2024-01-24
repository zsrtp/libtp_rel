/**	@file J3DAnimation.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_J3DANIMATION_H
#define TP_J3dANIMATION_H

#include <cstdint>

namespace libtp::tp::J3DAnimation
{
    struct J3DAnmBase
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ uint8_t mAttribute;
        /* 0x05 */ uint8_t padding5;
        /* 0x06 */ uint16_t mFrameMax;
        /* 0x08 */ float mFrame;
    } __attribute__((__packed__));

    struct J3DAnmTevRegKey: J3DAnmBase
    {
        /* 0x0C */ uint16_t mCRegUpdateMaterialNum;
        /* 0x0E */ uint16_t mKRegUpdateMaterialNum;
        /* 0x10 */ uint16_t field_0x10;
        /* 0x12 */ uint16_t field_0x12;
        /* 0x14 */ uint16_t field_0x14;
        /* 0x16 */ uint16_t field_0x16;
        /* 0x18 */ uint16_t field_0x18;
        /* 0x1A */ uint16_t field_0x1a;
        /* 0x1C */ uint16_t field_0x1c;
        /* 0x1E */ uint16_t field_0x1e;
        /* 0x20 */ uint8_t mCRegUpdateMaterialID[20];
        /* 0x34 */ uint8_t mKRegUpdateMaterialID[20];
        /* 0x48 */ void* field_0x48;
        /* 0x4C */ void* field_0x4c;
        /* 0x50 */ void* chromaRPtr;
        /* 0x54 */ void* chromaGPtr;
        /* 0x58 */ void* chromaBPtr;
        /* 0x5C */ void* chromaAPtr;
        /* 0x60 */ int32_t field_0x60;
        /* 0x64 */ int32_t field_0x64;
        /* 0x68 */ int32_t field_0x68;
        /* 0x6C */ int32_t field_0x6c;
    } __attribute__((__packed__));

    struct J3DAnmTextureSRTKey: J3DAnmBase
    {
        /* 0x0C */ int32_t field_0xc;
        /* 0x10 */ int32_t field_0x10;
        /* 0x14 */ uint16_t field_0x14;
        /* 0x16 */ uint16_t field_0x16;
        /* 0x18 */ uint16_t field_0x18;
        /* 0x1A */ uint16_t field_0x1a;
        /* 0x1C */ int32_t field_0x1c;
        /* 0x20 */ int32_t field_0x20;
        /* 0x24 */ int32_t field_0x24;
        /* 0x28 */ uint8_t mUpdateTexMtxID[4];
        /* 0x2C */ uint16_t* mUpdateMaterialID;
        /* 0x30 */ uint8_t field_0x30[0x10]; // JUTNameTab
        /* 0x40 */ int32_t field_0x40;
        /* 0x44 */ uint16_t field_0x44;
        /* 0x46 */ uint16_t field_0x46;
        /* 0x48 */ uint16_t field_0x48;
        /* 0x4A */ uint16_t field_0x4a;
        /* 0x4C */ int32_t field_0x4c;
        /* 0x50 */ int32_t field_0x50;
        /* 0x54 */ int32_t field_0x54;
        /* 0x58 */ int32_t field_0x58;
        /* 0x5C */ uint8_t field_0x5c[4];
        /* 0x60 */ uint16_t* field_0x60;
        /* 0x64 */ uint8_t field_0x64[0x10]; // JUTNameTab
        /* 0x74 */ uint8_t field_0x74[4];
        /* 0x78 */ uint32_t mTexMtxCalcType;
    } __attribute__((__packed__));

    static_assert(sizeof(J3DAnmBase) == 0xC);
    static_assert(sizeof(J3DAnmTevRegKey) == 0x70);
    static_assert(sizeof(J3DAnmTextureSRTKey) == 0x7C);

} // namespace libtp::tp::J3DAnimation
#endif