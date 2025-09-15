/**	@file J3DShape.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Lunar Soap
 *  @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef TP_J3DSHAPE_H
#define TP_J3DSHAPE_H

#include <cstdint>
#include "dolphin/mtx/vec.h"

namespace libtp::tp::J3DShape
{
    enum J3DShpFlag {
        J3DShpFlag_Visible = 0x0001,
        J3DShpFlag_SkinPosCpu = 0x0004,
        J3DShpFlag_SkinNrmCpu = 0x0008,
        J3DShpFlag_Hidden = 0x0010,
        J3DShpFlag_EnableLod = 0x0100,
        J3DShpFlag_NoMtx = 0x0200,
    };

    struct J3DShape
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ void* mMaterial; // J3DMaterial*
        /* 0x08 */ uint16_t mIndex;
        /* 0x0A */ uint16_t mMtxGroupNum;
        /* 0x0C */ uint32_t mFlags;
        /* 0x10 */ float mRadius;
        /* 0x14 */ Vec mMin;
        /* 0x20 */ Vec mMax;
        /* 0x2C */ uint8_t* mVcdVatCmd;
        /* 0x30 */ void* mVtxDesc; // GXVtxDescList*
        /* 0x34 */ bool mHasNBT;
        /* 0x35 */ uint8_t padding35[3];
        /* 0x38 */ void** mShapeMtx;         // J3DShapeMtx**
        /* 0x3C */ void** mShapeDraw;        // J3DShapeDraw**
        /* 0x40 */ uint8_t mCurrentMtx[0x8]; // J3DCurrentMtx
        /* 0x48 */ bool mHasPNMTXIdx;
        /* 0x49 */ uint8_t padding49[3];
        /* 0x4C */ void* mVertexData;  // J3DVertexData*
        /* 0x50 */ void* mDrawMtxData; // J3DDrawMtxData*
        /* 0x54 */ uint8_t* mScaleFlagArray;
        /* 0x58 */ void** mDrawMtx; // Mtx**
        /* 0x5C */ void** mNrmMtx;  // Mtx33**
        /* 0x60 */ uint32_t* mCurrentViewNo;
        /* 0x64 */ uint32_t mBumpMtxOffset;
    } __attribute__((__packed__));

    static_assert(sizeof(J3DShape) == 0x68);

    extern "C" {
        void onFlag(J3DShape* shapePtr, uint32_t flaag);
        void offFlag(J3DShape* shapePtr, uint32_t flaag);
        void showMesh(J3DShape* shapePtr);
        void hideMesh(J3DShape* shapePtr);
    }

} // namespace libtp::tp::J3DShape
#endif
