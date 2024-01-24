/**	@file c_cc_d.h
 *	@brief See https://github.com/zeldaret/tp/blob/main/include/SSystem/SComponent/c_cc_d.h
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_C_CC_D_H
#define TP_C_CC_D_H

#include <cstdint>
#include "dolphin/mtx/vec.h"
#include "SSystem/SComponent/c_m3d_g_tri.h"
#include "SSystem/SComponent/c_m3d_g_sph.h"
#include "SSystem/SComponent/c_m3d_g_cps.h"

namespace libtp::tp
{
    struct cCcD_SrcObjCommonBase
    {
        /* 0x0 */ int32_t mSPrm;
    } __attribute__((__packed__));

    struct cCcD_SrcObjTg
    {
        /* 0x0 */ int32_t mType;
        /* 0x4 */ cCcD_SrcObjCommonBase mBase;
    } __attribute__((__packed__)); // Size: 0x8

    struct cCcD_SrcObjAt
    {
        /* 0x0 */ int32_t mType;
        /* 0x4 */ uint8_t mAtp;
        /* 0x5 */ uint8_t padding[3];
        /* 0x8 */ cCcD_SrcObjCommonBase mBase;
    } __attribute__((__packed__)); // Size: 0xC

    struct cCcD_SrcObjCo
    {
        /* 0x0 */ cCcD_SrcObjCommonBase mBase;
    } __attribute__((__packed__)); // Size: 0x4

    struct cCcD_SrcObjHitInf
    {
        /* 0x00 */ cCcD_SrcObjAt mObjAt;
        /* 0x0C */ cCcD_SrcObjTg mObjTg;
        /* 0x14 */ cCcD_SrcObjCo mObjCo;
    } __attribute__((__packed__)); // Size: 0x18

    struct cCcD_SrcObj
    {
        /* 0x0 */ int mFlags;
        /* 0x4 */ cCcD_SrcObjHitInf mSrcObjHitInf;
    } __attribute__((__packed__)); // Size: 0x1C

    struct cCcD_SrcTriAttr
    {
        cM3dGTriS mTri;
    } __attribute__((__packed__));

    struct cCcD_SrcSphAttr
    {
        cM3dGSphS mSph;
    } __attribute__((__packed__));

    struct cCcD_SrcCpsAttr
    {
        cM3dGCpsS mCps;
    } __attribute__((__packed__));

    static_assert(sizeof(cCcD_SrcObjCommonBase) == 0x4);
    static_assert(sizeof(cCcD_SrcObjTg) == 0x8);
    static_assert(sizeof(cCcD_SrcObjAt) == 0xC);
    static_assert(sizeof(cCcD_SrcObjCo) == 0x4);
    static_assert(sizeof(cCcD_SrcObjHitInf) == 0x18);
    static_assert(sizeof(cCcD_SrcObj) == 0x1C);
    static_assert(sizeof(cCcD_SrcSphAttr) == 0x10);
    static_assert(sizeof(cCcD_SrcCpsAttr) == 0x1C);

} // namespace libtp::tp
#endif