/**	@file d_meter2.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_METER2_H
#define TP_D_METER2_H

#include <cstdint>

#include "tp/d_meter2_draw.h"

namespace libtp::tp::d_meter2
{
    struct dMeter2_c
    {
        /* 0x000 */ uint8_t field_0x0[0x100];
        /* 0x100 */ void* mpHeap;        // JKRExpHeap*
        /* 0x104 */ void* mpSubHeap;     // JKRExpHeap*
        /* 0x108 */ void* field_0x108;
        /* 0x10C */ libtp::tp::d_meter2_draw::dMeter2Draw_c* mpMeterDraw;
        /* 0x110 */ void* field_0x110;     // dDlst_base_c*
        /* 0x114 */ void* field_0x114;     // dDlst_base_c*
        /* 0x118 */ void* field_0x118;     // dDlst_base_c*
        /* 0x11C */ void* field_0x11c;
        /* 0x120 */ void* mpMap;     // dMeterMap_c*
        /* 0x124 */ uint32_t field_0x124;
        /* 0x128 */ int field_0x128;
        /* 0x12C */ int field_0x12c;
        /* 0x130 */ float field_0x130;
        /* 0x134 */ float field_0x134[2];
        /* 0x13C */ float field_0x13c[2];
        /* 0x144 */ float field_0x144;
        /* 0x148 */ float field_0x148[2];
        /* 0x150 */ float field_0x150[2];
        /* 0x158 */ float field_0x158;
        /* 0x15C */ float field_0x15c;
        /* 0x160 */ float field_0x160[4];
        /* 0x170 */ uint8_t field_0x170[4];
        /* 0x174 */ float field_0x174[4];
        /* 0x184 */ uint8_t field_0x184[4];
        /* 0x188 */ float field_0x188;
        /* 0x18C */ float field_0x18c;
        /* 0x190 */ int16_t field_0x190;
        /* 0x192 */ int16_t mNowLifeGauge;
        /* 0x194 */ int16_t field_0x194;
        /* 0x196 */ int16_t field_0x196;
        /* 0x198 */ int16_t field_0x198;
        /* 0x19A */ int16_t field_0x19a;
        /* 0x19C */ int field_0x19c;
        /* 0x1A0 */ int field_0x1a0;
        /* 0x1A4 */ int field_0x1a4;
        /* 0x1A8 */ int field_0x1a8;
        /* 0x1AC */ int field_0x1ac;
        /* 0x1B0 */ uint16_t field_0x1b0;
        /* 0x1B2 */ uint16_t field_0x1b2;
        /* 0x1B4 */ uint16_t field_0x1b4;
        /* 0x1B6 */ uint16_t mSubContentsStringType;
        /* 0x1B8 */ uint16_t field_0x1b8[5];
        /* 0x1C2 */ uint8_t field_0x1c2;
        /* 0x1C3 */ uint8_t field_0x1c3;
        /* 0x1C4 */ uint8_t field_0x1c4;
        /* 0x1C5 */ uint8_t field_0x1c5;
        /* 0x1C6 */ uint8_t field_0x1c6;
        /* 0x1C7 */ uint8_t field_0x1c7;
        /* 0x1C8 */ uint8_t field_0x1c8;
        /* 0x1C9 */ uint8_t field_0x1c9;
        /* 0x1CA */ uint8_t field_0x1ca;
        /* 0x1CB */ uint8_t field_0x1cb;
        /* 0x1CC */ uint8_t field_0x1cc;
        /* 0x1CD */ uint8_t field_0x1cd;
        /* 0x1CE */ uint8_t field_0x1ce;
        /* 0x1CF */ uint8_t field_0x1cf;
        /* 0x1D0 */ uint8_t field_0x1d0;
        /* 0x1D1 */ uint8_t field_0x1d1;
        /* 0x1D2 */ uint8_t field_0x1d2[4];
        /* 0x1D6 */ uint8_t field_0x1d6[2];
        /* 0x1D8 */ uint8_t field_0x1d8[2];
        /* 0x1DA */ uint8_t field_0x1da;
        /* 0x1DB */ uint8_t field_0x1db;
        /* 0x1DC */ uint8_t field_0x1dc;
        /* 0x1DD */ uint8_t field_0x1dd;
        /* 0x1DE */ uint8_t field_0x1de;
        /* 0x1DF */ uint8_t field_0x1df;
        /* 0x1E0 */ uint8_t field_0x1e0;
        /* 0x1E1 */ uint8_t field_0x1e1;
        /* 0x1E2 */ uint8_t field_0x1e2;
        /* 0x1E3 */ uint8_t field_0x1e3;
        /* 0x1E4 */ uint8_t field_0x1e4;
        /* 0x1E5 */ uint8_t mSubContents;
        /* 0x1E6 */ uint8_t field_0x1e6;
        /* 0x1E7 */ uint8_t field_0x1e7;
        /* 0x1E8 */ uint8_t field_0x1e8;
        /* 0x1E9 */ uint8_t field_0x1e9;
        /* 0x1EA */ uint8_t field_0x1ea;
        /* 0x1EB */ uint8_t field_0x1eb;
        /* 0x1EC */ uint8_t field_0x1ec;
        /* 0x1ED */ uint8_t field_0x1ed;
        /* 0x1EE */ uint8_t field_0x1ee;
        /* 0x1EF */ uint8_t field_0x1ef[4];
        /* 0x1F3 */ uint8_t field_0x1f3[3];
        /* 0x1F6 */ uint8_t field_0x1f6[3];
        /* 0x1F9 */ uint8_t field_0x1f9[4];
        /* 0x1FD */ uint8_t field_0x1fd;
        /* 0x1FE */ uint8_t field_0x1fe;
        /* 0x1FF */ uint8_t field_0x1ff;
        /* 0x200 */ uint8_t field_0x200;
        /* 0x201 */ uint8_t field_0x201;
    } __attribute__( ( __packed__ ) );

    extern "C"
    {
        uint32_t dMeter2_Create( dMeter2_c* param_1 );
    }
}     // namespace libtp::tp::d_meter2
#endif