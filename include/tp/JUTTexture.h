/**	@file JUTTexture.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/JSystem/JUtility/JUTTexture.h
 *
 *	@author Lunar Soap
 *	@bug
 */
#ifndef TP_JUTTEXTURE_H
#define TP_JUTTEXTURE_H

#include <cstdint>

namespace libtp::tp::JUTTexture
{
    struct ResTIMG
    {
        /* 0x00 */ uint8_t format;
        /* 0x01 */ uint8_t alphaEnabled;
        /* 0x02 */ uint16_t width;
        /* 0x04 */ uint16_t height;
        /* 0x06 */ uint8_t wrapS;
        /* 0x07 */ uint8_t wrapT;
        /* 0x08 */ uint8_t indexTexture;
        /* 0x09 */ uint8_t colorFormat;
        /* 0x0A */ uint16_t numColors;
        /* 0x0C */ uintptr_t paletteOffset;
        /* 0x10 */ uint8_t mipmapEnabled;
        /* 0x11 */ uint8_t doEdgeLOD;
        /* 0x12 */ uint8_t biasClamp;
        /* 0x13 */ uint8_t maxAnisotropy;
        /* 0x14 */ uint8_t minFilter;
        /* 0x15 */ uint8_t magFilter;
        /* 0x16 */ int8_t minLOD;
        /* 0x17 */ int8_t maxLOD;
        /* 0x18 */ uint8_t mipmapCount;
        /* 0x19 */ uint8_t unknown;
        /* 0x1A */ int16_t LODBias;
        /* 0x1C */ uintptr_t imageOffset;
    } __attribute__((__packed__)); // Size: 0x20

    static_assert(sizeof(ResTIMG) == 0x20);
} // namespace libtp::tp::JUTTexture

#endif