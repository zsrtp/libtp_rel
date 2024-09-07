/**	@file color_utils.h
 *  @brief Utility methods related to color.
 *
 *	@author Isaac
 *	@bug No known bugs.
 */
#ifndef COLOR_UTILS_H
#define COLOR_UTILS_H

#include <cstdint>

namespace libtp::util::color
{
    // Desaturates an RGB565 color to a u8 gray value (0xFF being white and 0x00
    // being black).
    uint8_t desaturateRgb565(uint16_t rgb565Val);

    // Performs an "Overlay" blend of a u8 gray value and a pointer to a u8
    // array of {r,g,b}. Returns the result as an RGB565.
    uint16_t blendOverlayRgb565(uint8_t grayVal, const uint8_t* rgb);
} // namespace libtp::util::color
#endif