#include <cstdint>
#include <cstring>

#include "util/color_utils.h"
#include "tp/m_do_printf.h"

namespace libtp::util::texture
{
    uint8_t* findTexHeaderInTex1Section(uint8_t* tex1Ptr, const char* textureName)
    {
        if (tex1Ptr == nullptr)
        {
            return nullptr;
        }

        const uint32_t numTextures = *reinterpret_cast<uint16_t*>(tex1Ptr + 8);
        uint8_t* strTable = tex1Ptr + *reinterpret_cast<uint32_t*>(tex1Ptr + 0x10);
        const uint32_t numStrings = *reinterpret_cast<uint16_t*>(strTable);

        for (uint32_t i = 0; i < numStrings && i < numTextures; i++)
        {
            const uint32_t offsetInStrTable = *reinterpret_cast<uint16_t*>(strTable + 6 + (4 * i));
            const char* strPtr = reinterpret_cast<char*>(strTable + offsetInStrTable);

            if (strcmp(strPtr, textureName) == 0)
            {
                return tex1Ptr + 0x20 + (i * 0x20);
            }
        }

        return nullptr;
    }

    // When left is greater than right
    // 0b00 points to the left color
    // 0b01 points to the right color
    // 0b10 is closer to left color
    // 0b11 is closer to right color

    // When left is not greater than right
    // 0b00 points to the left color
    // 0b01 points to the right color
    // 0b10 is midway between the colors
    // 0b11 is transparent

    // That means when maintaining the relative order, if we have to swap the colors:

    // in the case of left being greater than right:
    // 0b00 will swap to 0b01
    // 0b01 will swap to 0b00
    // 0b10 will swap to 0b11
    // 0b11 will swap to 0b10
    // So the left bit stays the same, and the right bit changes
    // Can do xor (^) like 0b01010101 or 0x55 for each u16

    // in the case of left not being greater than right:
    // 0b00 will swap to 0b01
    // 0b01 will swap to 0b00
    // 0b10 will stay the same
    // 0b11 will stay the same
    // so if the left bit is a 0, the right bit will change
    uint32_t swapIndexBits(bool leftIsGreater, uint32_t bits)
    {
        if (leftIsGreater)
        {
            return bits ^ 0x55555555;
        }
        else
        {
            const uint32_t mask = ((bits >> 1) & 0x55555555) ^ 0x55555555;
            return bits ^ mask;
        }
    }

    void recolorCmprTexture(uint8_t* tex1Ptr, const char* textureName, const uint8_t* rgb)
    {
        uint8_t* texHeaderPtr = findTexHeaderInTex1Section(tex1Ptr, textureName);
        if (texHeaderPtr == nullptr)
        {
            return;
        }

        if (texHeaderPtr[0] != 0xE)
        {
            // Texture is not CMPR
            return;
        }

        uint16_t recolors[0x100];
        for (int32_t i = 0; i < 0x100; i++)
        {
            recolors[i] = libtp::util::color::blendOverlayRgb565(i, rgb);
        }

        const int32_t width = static_cast<int32_t>(*reinterpret_cast<uint16_t*>(texHeaderPtr + 2));
        const int32_t height = static_cast<int32_t>(*reinterpret_cast<uint16_t*>(texHeaderPtr + 4));

        constexpr int32_t blockWidth = 8;
        constexpr int32_t blockHeight = 8;

        const int32_t roundedWidth = width + ((blockWidth - (width % blockWidth)) % blockWidth);
        const int32_t roundedHeight = height + ((blockHeight - (height % blockHeight)) % blockHeight);

        const int32_t numBlocks = roundedWidth / blockWidth * roundedHeight / blockHeight;

        const int32_t iterations = numBlocks * 4;

        uint8_t* currentAddr = texHeaderPtr + *reinterpret_cast<int32_t*>(texHeaderPtr + 0x1C);
        for (int32_t i = 0; i < iterations; i++)
        {
            uint16_t* rgb565Ptr = reinterpret_cast<uint16_t*>(currentAddr);

            const uint16_t leftRgb565 = rgb565Ptr[0];
            const uint16_t rightRgb565 = rgb565Ptr[1];
            const bool leftIsGreater = leftRgb565 > rightRgb565;

            const uint32_t leftGrayVal = libtp::util::color::desaturateRgb565(leftRgb565);
            const uint32_t rightGrayVal = libtp::util::color::desaturateRgb565(rightRgb565);

            uint16_t leftNewRgb565 = recolors[leftGrayVal];
            uint16_t rightNewRgb565 = recolors[rightGrayVal];

            bool needsBitSwap = false;

            if (leftIsGreater)
            {
                if (leftNewRgb565 == rightNewRgb565)
                {
                    // Need to make sure that subtracting 1 does not mess
                    // everything up. For example, 0x1000 - 1 => 0x0fff which is
                    // a completely different color.
                    if ((leftNewRgb565 & 0x1f) == 0)
                    {
                        // If left value has 0 blue, we change its blue to 1.
                        leftNewRgb565 += 1;
                    }
                    rightNewRgb565 = leftNewRgb565 - 1;
                }
                else if (leftNewRgb565 < rightNewRgb565)
                {
                    needsBitSwap = true;
                }
            }
            else if (leftNewRgb565 > rightNewRgb565)
            {
                needsBitSwap = true;
            }

            if (needsBitSwap)
            {
                // The left and right colors are swapping so that their values
                // are relative in the same way. We need to update the bits
                // referencing the palette entries to handle the swap.

                const uint16_t temp = leftNewRgb565;
                leftNewRgb565 = rightNewRgb565;
                rightNewRgb565 = temp;

                uint32_t* wordPtr = reinterpret_cast<uint32_t*>(currentAddr);
                const uint32_t bits = wordPtr[1];

                const uint32_t newBits = swapIndexBits(leftIsGreater, bits);
                wordPtr[1] = newBits;
            }

            rgb565Ptr[0] = leftNewRgb565;
            rgb565Ptr[1] = rightNewRgb565;

            currentAddr += 8;
        }
    }

    uint8_t* findTex1InBmd(uint8_t* bmdPtr)
    {
        if (bmdPtr == nullptr)
        {
            return nullptr;
        }

        const uint32_t j3d2Magic = *reinterpret_cast<uint32_t*>(bmdPtr);
        if (j3d2Magic != 0x4A334432) // J3D2
        {
            // Model was not a BMD or BDL! (J3D2 magic not found)
            return nullptr;
        }

        const uint32_t modelMagic = *reinterpret_cast<uint32_t*>(bmdPtr + 4);
        if ((modelMagic != 0x62646C34) && (modelMagic != 0x626D6433)) // bmd3 and bdl4
        {
            // Model was not a BMD or BDL! (Model type was not bmd3 or bdl4)
            return nullptr;
        }

        const int32_t modelSize = *reinterpret_cast<int32_t*>(bmdPtr + 8);
        const int32_t sectionCount = *reinterpret_cast<int32_t*>(bmdPtr + 0xC);
        const uint8_t* endOfModelAddr = bmdPtr + modelSize;

        uint8_t* currentSectionAddr = bmdPtr + 0x20;
        for (int32_t i = 0; i < sectionCount; i++)
        {
            const uint32_t sectionMagic = *reinterpret_cast<uint32_t*>(currentSectionAddr);
            if (sectionMagic == 0x54455831) // TEX1
            {
                // Section is TEX1
                return currentSectionAddr;
            }

            currentSectionAddr += *reinterpret_cast<int32_t*>(currentSectionAddr + 4);

            if (currentSectionAddr >= endOfModelAddr)
            {
                break;
            }
        }

        return nullptr;
    }

} // namespace libtp::util::texture