/**	@file d_meter2_draw.h
 *	@brief Holds data about drawn objects.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_METER2_DRAW_H
#define TP_D_METER2_DRAW_H

#include <cstdint>

#include "tp/d_pane_class.h"

namespace libtp::tp::d_meter2_draw
{
    struct dMeter2Draw_c
    {
        /* 0x000 */ void* vtable;
        /* 0x004 */ float field_0x4;
        /* 0x008 */ float field_0x8;
        /* 0x00C */ float field_0xc;
        /* 0x010 */ float field_0x10;
        /* 0x014 */ float field_0x14;
        /* 0x028 */ float field_0x18;
        /* 0x01C */ float field_0x1c;
        /* 0x020 */ float field_0x20;
        /* 0x024 */ float field_0x24;
        /* 0x028 */ float field_0x28;
        /* 0x02C */ float field_0x2c;
        /* 0x030 */ float field_0x30;
        /* 0x034 */ float field_0x34;
        /* 0x038 */ float field_0x38;
        /* 0x03C */ float field_0x3c;
        /* 0x040 */ float field_0x40;
        /* 0x044 */ float field_0x44;
        /* 0x048 */ float field_0x48;
        /* 0x04C */ float field_0x4c;
        /* 0x050 */ float field_0x50;
        /* 0x054 */ float field_0x54;
        /* 0x058 */ float field_0x58;
        /* 0x05C */ float field_0x5c;
        /* 0x060 */ float field_0x60;
        /* 0x064 */ float field_0x64;
        /* 0x068 */ float field_0x68;
        /* 0x06C */ float field_0x6c;
        /* 0x070 */ float field_0x70;
        /* 0x074 */ void* mp_heap;            // JKRExpHeap*
        /* 0x078 */ void* mpScreen;           // J2DScreen*
        /* 0x07C */ void* mpKanteraScreen;    // J2DScreen*
        /* 0x080 */ void* mpPikariScreen;     // J2DScreen*
        /* 0x084 */ void* mpItemNumTex[2][3]; // J2DScreen*
        /* 0x09C */ int32_t field_0x9c[3];
        /* 0x0A8 */ int32_t field_0xa8;
        /* 0x0AC */ void* mpKanteraMeter[2]; // dKantera_icon_c*
        /* 0x0B4 */ uint8_t field_0xb4[8];
        /* 0x0BC */ void* mpParent;
        /* 0x0C0 */ libtp::tp::d_pane_class::CPaneMgr* mpAText[5];
        /* 0x0D4 */ libtp::tp::d_pane_class::CPaneMgr* mpBText[5];
        /* 0x0E8 */ libtp::tp::d_pane_class::CPaneMgr* mpXYText[5][3];
        /* 0x124 */ libtp::tp::d_pane_class::CPaneMgr* mpLifeParent;
        /* 0x128 */ libtp::tp::d_pane_class::CPaneMgr* mpLifeParts[20];
        /* 0x178 */ libtp::tp::d_pane_class::CPaneMgr* mpHeartMask[20];
        /* 0x1C8 */ libtp::tp::d_pane_class::CPaneMgr* mpBigHeart; // Big heart that displays highest heart value.
        /* 0x1CC */ libtp::tp::d_pane_class::CPaneMgr* mpMagicParent;
        /* 0x1D0 */ libtp::tp::d_pane_class::CPaneMgr* mpMagicBase;
        /* 0x1D4 */ libtp::tp::d_pane_class::CPaneMgr* mpMagicFrameL;
        /* 0x1D8 */ libtp::tp::d_pane_class::CPaneMgr* mpMagicMeter;
        /* 0x1DC */ libtp::tp::d_pane_class::CPaneMgr* mpMagicFrameR;
        /* 0x1E0 */ libtp::tp::d_pane_class::CPaneMgr* mpLightDropParent;
        /* 0x1E4 */ int32_t field_0x1e4;
        /* 0x1E8 */ libtp::tp::d_pane_class::CPaneMgr* mpSIParent[2];
        /* 0x1F0 */ libtp::tp::d_pane_class::CPaneMgr* mpSIParts[16][3];
        /* 0x2B0 */ libtp::tp::d_pane_class::CPaneMgr* mpRupeeKeyParent;
        /* 0x2B4 */ libtp::tp::d_pane_class::CPaneMgr* mpRupeeParent[3];
        /* 0x2C0 */ libtp::tp::d_pane_class::CPaneMgr* mpRupeeTexture[4][2];
        /* 0x2E0 */ libtp::tp::d_pane_class::CPaneMgr* mpKeyParent;
        /* 0x2E4 */ libtp::tp::d_pane_class::CPaneMgr* mpKeyTexture[5];
        /* 0x2F8 */ libtp::tp::d_pane_class::CPaneMgr* mpButtonParent;
        /* 0x2FC */ int32_t field_0x2fc;
        /* 0x300 */ libtp::tp::d_pane_class::CPaneMgr* mpButtonA;
        /* 0x304 */ libtp::tp::d_pane_class::CPaneMgr* mpButtonB;
        /* 0x308 */ libtp::tp::d_pane_class::CPaneMgr* mpButtonMidona;
        /* 0x30C */ libtp::tp::d_pane_class::CPaneMgr* mpButtonXY[3];
        /* 0x318 */ libtp::tp::d_pane_class::CPaneMgr* mpLightB;
        /* 0x31C */ libtp::tp::d_pane_class::CPaneMgr* mpLightXY[3];
        /* 0x328 */ libtp::tp::d_pane_class::CPaneMgr* mpItemB;
        /* 0x32C */ libtp::tp::d_pane_class::CPaneMgr* mpItemXY[2];
        /* 0x334 */ libtp::tp::d_pane_class::CPaneMgr* mpItemR;
        /* 0x338 */ libtp::tp::d_pane_class::CPaneMgr* mpBTextA;
        /* 0x33C */ libtp::tp::d_pane_class::CPaneMgr* mpBTextB;
        /* 0x340 */ libtp::tp::d_pane_class::CPaneMgr* mpBTextXY[2];
        /* 0x348 */ int32_t field_0x348;
        /* 0x34C */ libtp::tp::d_pane_class::CPaneMgr* mpTextA;
        /* 0x350 */ libtp::tp::d_pane_class::CPaneMgr* mpTextB;
        /* 0x354 */ libtp::tp::d_pane_class::CPaneMgr* mpTextXY[3];
        /* 0x360 */ libtp::tp::d_pane_class::CPaneMgr* mpTextI;
        /* 0x364 */ libtp::tp::d_pane_class::CPaneMgr* mpTextM;
        /* 0x368 */ libtp::tp::d_pane_class::CPaneMgr* mpButtonCrossParent;
        /* 0x36C */ int32_t field_0x36c;
        /* 0x370 */ uint8_t field_0x370[0x2C];
        /* 0x39C */ libtp::tp::d_pane_class::CPaneMgr* mpPikariParent;
        /* 0x3A0 */ libtp::tp::d_pane_class::CPaneMgr* mpLifeTexture[20][2];
        /* 0x440 */ libtp::tp::d_pane_class::CPaneMgr* mpHeartBase[20];
        /* 0x490 */ libtp::tp::d_pane_class::CPaneMgr* mpJujiI[5];
        /* 0x4A4 */ libtp::tp::d_pane_class::CPaneMgr* mpJujiM[5];
        /* 0x4B8 */ libtp::tp::d_pane_class::CPaneMgr* mpUzu;
        /* 0x4BC */ uint8_t field_0x4bc[0x28];
        /* 0x4E4 */ void* mpItemBTex[2][2];     // JKRHeap*
        /* 0x4F4 */ void* mpItemXYTex[2][2][2]; // JKRHeap*
        /* 0x514 */ void* mpItemBPane;          // J2DPicture*
        /* 0x518 */ void* mpItemXYPane[3];      // J2DPicture*
        /* 0x524 */ int32_t field_0x524[2][2];
        /* 0x534 */ uint8_t field_0x534[8];
        /* 0x53C */ void* field_0x53c;
        /* 0x540 */ void* field_0x540; // bpk //J2DAnmBase*
        /* 0x544 */ void* field_0x544; // bpk //J2DAnmBase*
        /* 0x548 */ uint8_t field_0x548[8];
        /* 0x550 */ float field_0x550;
        /* 0x554 */ float field_0x554;
        /* 0x558 */ float field_0x558;
        /* 0x55C */ float field_0x55c;
        /* 0x560 */ float field_0x560;
        /* 0x564 */ float field_0x564;
        /* 0x568 */ float field_0x568;
        /* 0x56C */ float field_0x56c;
        /* 0x570 */ float field_0x570;
        /* 0x574 */ float field_0x574;
        /* 0x578 */ float field_0x578;
        /* 0x57C */ float field_0x57c;
        /* 0x580 */ float field_0x580;
        /* 0x584 */ uint8_t field_0x584[0x78];
        /* 0x5FC */ float field_0x5fc[3];
        /* 0x608 */ float field_0x608;
        /* 0x60C */ float field_0x60c;
        /* 0x610 */ float field_0x610[3];
        /* 0x61C */ float field_0x61c;
        /* 0x620 */ float field_0x620[3];
        /* 0x62C */ float field_0x62c[16];
        /* 0x66C */ float field_0x66c[16];
        /* 0x6AC */ float field_0x6ac[3];
        /* 0x6B8 */ float field_0x6b8[3];
        /* 0x6C4 */ float field_0x6c4[3];
        /* 0x6D0 */ float field_0x6d0[3];
        /* 0x6DC */ float field_0x6dc;
        /* 0x6E0 */ float field_0x6e0;
        /* 0x6E4 */ float field_0x6e4;
        /* 0x6E8 */ float field_0x6e8;
        /* 0x6EC */ float field_0x6ec;
        /* 0x6F0 */ float field_0x6f0;
        /* 0x6F4 */ float field_0x6f4;
        /* 0x6F8 */ float field_0x6f8;
        /* 0x6FC */ float field_0x6fc;
        /* 0x700 */ uint8_t field_0x700[0x18];
        /* 0x718 */ float field_0x718;
        /* 0x71C */ uint8_t field_0x71c[4];
        /* 0x720 */ float mZButtonAlpha;
        /* 0x724 */ float field_0x724;
        /* 0x728 */ float field_0x728;
        /* 0x72C */ float field_0x72c;
        /* 0x730 */ float field_0x730;
        /* 0x734 */ float field_0x734;
        /* 0x738 */ float field_0x738;
        /* 0x73C */ uint8_t field_0x73c[4];
        /* 0x740 */ uint16_t field_0x740;
        /* 0x742 */ uint16_t field_0x742[3];
        /* 0x748 */ uint8_t field_0x748[0xE];
        /* 0x756 */ uint16_t field_0x754;
        /* 0x756 */ uint16_t field_0x756;
        /* 0x758 */ uint8_t field_0x758;
        /* 0x759 */ uint8_t field_0x759;
        /* 0x75A */ uint8_t field_0x75a;
        /* 0x75B */ uint8_t field_0x75b;
        /* 0x75C */ uint8_t field_0x75c[3];
        /* 0x75F */ uint8_t field_0x75f;
        /* 0x760 */ uint8_t field_0x760;
        /* 0x761 */ uint8_t field_0x761;
        /* 0x762 */ uint8_t field_0x762;
        /* 0x763 */ uint8_t field_0x763;
        /* 0x764 */ uint8_t field_0x764;
        /* 0x765 */ uint8_t field_0x765;
        /* 0x766 */ uint8_t field_0x766;
        /* 0x767 */ uint8_t field_0x767;
        /* 0x768 */ uint8_t field_0x768[3];
        /* 0x76B */ uint8_t field_0x76b;
        /* 0x76C */ uint8_t field_0x76c[2];
        /* 0x76E */ uint8_t field_0x76e;
        /* 0x76F */ uint8_t field_0x76f;
        /* 0x770 */ uint8_t field_0x770;
        /* 0x771 */ uint8_t field_0x771;
        /* 0x772 */ uint8_t field_0x772;
        /* 0x773 */ uint8_t field_0x773[2];
        /* 0x778 */ float field_0x778;
        /* 0x77C */ float field_0x77c;
        /* 0x780 */ float field_0x780;
        /* 0x784 */ float field_0x784;
        /* 0x788 */ float field_0x788;
        /* 0x78C */ float field_0x78c;
        /* 0x790 */ float field_0x790;
        /* 0x794 */ float field_0x794;
        /* 0x798 */ float field_0x798;
        /* 0x79C */ float field_0x79c;
        /* 0x7A0 */ float field_0x7a0;
        /* 0x7A4 */ float field_0x7a4;
        /* 0x7A8 */ float field_0x7a8;
        /* 0x7AC */ float field_0x7ac;
        /* 0x7B0 */ float field_0x7b0;
        /* 0x7B4 */ float field_0x7b4;
        /* 0x7B8 */ float field_0x7b8;
        /* 0x7BC */ float field_0x7bc;
        /* 0x7C0 */ float field_0x7c0;
        /* 0x7C4 */ float field_0x7c4;
        /* 0x7C8 */ float field_0x7c8;
        /* 0x7CC */ float field_0x7cc;
        /* 0x7D0 */ float field_0x7d0;
        /* 0x7D4 */ float field_0x7d4;
        /* 0x7D8 */ float field_0x7d8;
        /* 0x7DC */ float field_0x7dc;
        /* 0x7E0 */ float field_0x7e0;
        /* 0x7E4 */ float field_0x7e4;
        /* 0x7E8 */ float field_0x7e8;
        /* 0x7EC */ float field_0x7ec;
        /* 0x7F0 */ float field_0x7f0;
        /* 0x7F4 */ float field_0x7f4;
        /* 0x7F8 */ float field_0x7f8;
        /* 0x7FC */ float field_0x7fc;
        /* 0x800 */ float field_0x800;
        /* 0x804 */ float field_0x804;
        /* 0x808 */ float field_0x808;
        /* 0x80C */ float field_0x80c;
        /* 0x810 */ float field_0x810;
        /* 0x814 */ float field_0x814[2];
        /* 0x81C */ float field_0x81c[2];
        /* 0x824 */ float field_0x824[2];
        /* 0x82C */ float field_0x82c[2];
        /* 0x834 */ float field_0x834;
        /* 0x838 */ float field_0x838;
        /* 0x83C */ float field_0x83c;
        /* 0x840 */ float field_0x840;
        /* 0x844 */ float field_0x844;
        /* 0x848 */ float field_0x848;
        /* 0x84C */ uint8_t field_0x84c;
        /* 0x84D */ uint8_t field_0x84d;
        /* 0x84E */ uint8_t field_0x84e;
        /* 0x84F */ uint8_t field_0x84f;
        /* 0x850 */ uint8_t field_0x850;
        /* 0x851 */ uint8_t field_0x851;
        /* 0x852 */ uint8_t field_0x852;
        /* 0x853 */ uint8_t field_0x853;
        /* 0x854 */ uint8_t field_0x854;
        /* 0x855 */ uint8_t field_0x855;
        /* 0x856 */ uint8_t field_0x856;
        /* 0x857 */ uint8_t field_0x857;
        /* 0x858 */ uint8_t field_0x858;
        /* 0x859 */ uint8_t field_0x859;
        /* 0x85A */ uint8_t field_0x85a;
        /* 0x85B */ uint8_t field_0x85b;
        /* 0x85C */ uint8_t field_0x85c;
        /* 0x85D */ uint8_t field_0x85d;
        /* 0x85E */ uint8_t field_0x85e;
        /* 0x85F */ uint8_t field_0x85f;
        /* 0x860 */ uint8_t field_0x860;
        /* 0x861 */ uint8_t field_0x861;
        /* 0x862 */ uint8_t padding[0x2];
    } __attribute__((__packed__));
} // namespace libtp::tp::d_meter2_draw
#endif