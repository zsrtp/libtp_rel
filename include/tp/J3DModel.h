/**	@file J3DModel.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_J3DMODEL_H
#define TP_J3DMODEL_H

#include <cstdint>
#include "dolphin/mtx/vec.h"

namespace libtp::tp::J3DModel
{
    struct J3DModel
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ void* mModelData; // J3DModelData*
        /* 0x08 */ uint32_t mFlags;
        /* 0x0C */ uint32_t mDiffFlag;
        /* 0x10 */ uint32_t mCalcCallBack; // J3DCalcCallBack
        /* 0x14 */ uint32_t mUserArea;
        /* 0x18 */ Vec mBaseScale;
        /* 0x24 */ uint8_t mBaseTransformMtx[0x30]; // Mtx
        /* 0x54 */ uint8_t mInternalView[0x30];     // Mtx
        /* 0x84 */ void* mMtxBuffer;                // J3DMtxBuffer*
        /* 0x88 */ uint8_t mVertexBuffer[0x38];     // J3DVertexBuffer
        /* 0xC0 */ void* mMatPacket;                // J3DMatPacket
        /* 0xC4 */ void* mShapePacket;              // J3DShapePacket
        /* 0xC8 */ void* mDeformData;               // J3DDeformData*
        /* 0xCC */ void* mSkinDeform;               // J3DSkinDeform*
        /* 0xD0 */ void* mVtxColorCalc;             // J3DVtxColorCalc*
        /* 0xD4 */ void* mUnkCalc1;                 // J3DUnkCalc1*
        /* 0xD8 */ void* mUnkCalc2;                 // J3DUnkCalc2*
    } __attribute__((__packed__));

    static_assert(sizeof(J3DModel) == 0xDC);

} // namespace libtp::tp::J3DModel
#endif