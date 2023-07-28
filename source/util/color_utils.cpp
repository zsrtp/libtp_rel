#include <cstdint>

namespace libtp::util::color
{
    uint8_t desaturateRgb565(uint16_t rgb565Val)
    {
        const uint32_t r = (rgb565Val & 0xf800) >> 11;
        const uint32_t g = (rgb565Val & 0x7e0) >> 5;
        const uint32_t b = rgb565Val & 0x1f;

        // Here we are doing a quicker (0.22 * r + 0.72 * g + 0.06 * b) which
        // uses multiplies and shifts rather than division.
        const uint32_t combined = 30480413 * r + 49085341 * g + 8312839 * b;
        uint8_t shifted = (combined >> 24) & 0xff;

        // Check if should round up shifted value.
        if (shifted < 0xff && combined & 0x00800000)
        {
            shifted += 1;
        }

        return shifted;
    }

    uint16_t blendOverlayRgb565(uint8_t grayVal, uint8_t* rgb)
    {
        uint32_t rTimes255, gTimes255, bTimes255;

        if (grayVal <= 0x7f)
        {
            const uint32_t grayTimesTwo = 2 * grayVal;

            rTimes255 = grayTimesTwo * rgb[0];
            gTimes255 = grayTimesTwo * rgb[1];
            bTimes255 = grayTimesTwo * rgb[2];
        }
        else
        {
            const uint32_t multiplier = 2 * (255 - grayVal);

            rTimes255 = 255 * 255 - multiplier * (255 - rgb[0]);
            gTimes255 = 255 * 255 - multiplier * (255 - rgb[1]);
            bTimes255 = 255 * 255 - multiplier * (255 - rgb[2]);
        }

        // Divide each by 255
        const uint32_t r = (rTimes255 + 1 + (rTimes255 >> 8)) >> 8;
        const uint32_t g = (gTimes255 + 1 + (gTimes255 >> 8)) >> 8;
        const uint32_t b = (bTimes255 + 1 + (bTimes255 >> 8)) >> 8;

        return ((r & 0xf8) << 8) | ((g & 0xfc) << 3) | ((b & 0xf8) >> 3);
    }

} // namespace libtp::util::color