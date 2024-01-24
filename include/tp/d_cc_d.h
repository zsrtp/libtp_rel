/**	@file d_cc_d.h
 *	@brief Contains defintions and functions that relate to Drawn 3D Objects
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_CC_D_H
#define TP_D_CC_D_H

#include <cstdint>
#include "dolphin/mtx/vec.h"
#include "SSystem/SComponent/c_cc_d.h"
#include "SSystem/SComponent/c_m3d_g_cyl.h"

namespace libtp::tp::J3DModel
{
    struct dCcD_SrcGAtTgCoCommonBase
    {
        /* 0x0 */ uint32_t mGFlag;
    } __attribute__((__packed__)); // Size: 0x4

    struct dCcD_SrcGObjAt
    {
        /* 0x0 */ uint8_t mSe;      // Sound Effect ID
        /* 0x1 */ uint8_t mHitMark; // Hit Mark particle ID
        /* 0x2 */ uint8_t mSpl;
        /* 0x3 */ uint8_t mMtrl;
        /* 0x4 */ dCcD_SrcGAtTgCoCommonBase mBase;
    } __attribute__((__packed__)); // Size: 0x8

    struct dCcD_SrcGObjTg
    {
        /* 0x0 */ uint8_t mSe;      // Sound Effect ID
        /* 0x1 */ uint8_t mHitMark; // Hit Mark particle ID
        /* 0x2 */ uint8_t mSpl;
        /* 0x3 */ uint8_t mMtrl;
        /* 0x4 */ dCcD_SrcGAtTgCoCommonBase mBase;
    } __attribute__((__packed__)); // Size: 0x8

    struct dCcD_SrcGObjCo
    {
        /* 0x0 */ dCcD_SrcGAtTgCoCommonBase mBase;
    } __attribute__((__packed__)); // Size: 0x4

    struct dCcD_SrcGObjInf
    {
        /* 0x00 */ cCcD_SrcObj mObj;
        /* 0x1C */ dCcD_SrcGObjAt mGObjAt;
        /* 0x24 */ dCcD_SrcGObjTg mGObjTg;
        /* 0x2C */ dCcD_SrcGObjCo mGObjCo;
    } __attribute__((__packed__)); // Size: 0x30

    struct dCcD_SrcSph
    {
        /* 0x00 */ dCcD_SrcGObjInf mObjInf;
        /* 0x30 */ cCcD_SrcSphAttr mSphAttr;
    } __attribute__((__packed__)); // Size: 0x40

    struct dCcD_SrcTri
    {
        /* 0x00 */ dCcD_SrcGObjInf mObjInf;
        /* 0x30 */ cCcD_SrcTriAttr mTriAttr;
    } __attribute__((__packed__)); // Size: 0x54

    struct dCcD_SrcCyl
    {
        /* 0x00 */ dCcD_SrcGObjInf mObjInf;
        /* 0x30 */ cM3dGCylS mCyl;
    } __attribute__((__packed__)); // Size: 0x44

    struct dCcD_SrcCps
    {
        /* 0x00 */ dCcD_SrcGObjInf mObjInf;
        /* 0x30 */ cCcD_SrcCpsAttr mCpsAttr;
    } __attribute__((__packed__));

    static_assert(sizeof(dCcD_SrcGAtTgCoCommonBase) == 0x4);
    static_assert(sizeof(dCcD_SrcGObjAt) == 0x8);
    static_assert(sizeof(dCcD_SrcGObjTg) == 0x8);
    static_assert(sizeof(dCcD_SrcGObjCo) == 0x4);
    static_assert(sizeof(dCcD_SrcGObjInf) == 0x30);
    static_assert(sizeof(dCcD_SrcSph) == 0x40);
    static_assert(sizeof(dCcD_SrcTri) == 0x54);
    static_assert(sizeof(dCcD_SrcCyl) == 0x44);
    static_assert(sizeof(dCcD_SrcCps) == 0x4C);

} // namespace libtp::tp::J3DModel
#endif