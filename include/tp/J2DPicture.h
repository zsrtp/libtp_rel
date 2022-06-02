#ifndef TP_J2DPICTURE_H
#define TP_J2DPICTURE_H

#include <cstdint>

#include "tp/J2DPane.h"

namespace libtp::tp::J2DPicture
{
    extern "C"
    {
        void* J2DPicture_ct4( void* J2DPicture, const void* ResTIMG );     // Constructor
        void* J2DPicture_dt( void* J2DPicture, int16_t freeThis );         // Destructor
        void J2DPicture_draw( void* J2DPicture, float x, float y, float width, float height, bool unk5, bool unk6, bool unk7 );
    }

    class J2DPicture: public libtp::tp::J2DPane::J2DPane
    {
       public:
        J2DPicture( const void* ResTIMG ) { J2DPicture_ct4( this, ResTIMG ); }

        void setWhiteColor( uint32_t color ) { mWhite = color; }
        void setBlackColor( uint32_t color ) { mBlack = color; }

       private:
        /* 0x100 */ void* mTexture[2];
        /* 0x108 */ uint8_t mTextureCount;
        /* 0x109 */ uint8_t field_0x109;
        // /* 0x10A */ JGeometry::TVec2<s16> field_0x10a[4];
        /* 0x10A */ uint8_t field_0x10a[0x12];
        /* 0x11C */ float field_0x11c[4];
        /* 0x12C */ void* field_0x12c;
        /* 0x130 */ uint32_t mWhite;
        /* 0x134 */ uint32_t mBlack;
        /* 0x138 */ uint32_t mCornerColor[4];
        /* 0x148 */ uint32_t field_0x148;
        /* 0x14C */ uint32_t field_0x14c;
    };

}     // namespace libtp::tp::J2DPicture
#endif