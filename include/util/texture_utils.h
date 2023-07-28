/**	@file texture_utils.h
 *  @brief Utility methods related to textures.
 *
 *	@author Isaac
 *	@bug No known bugs.
 */
#ifndef TEXTURE_UTILS_H
#define TEXTURE_UTILS_H

#include <cstdint>

#include "util/color_utils.h"

namespace libtp::util::texture
{
    uint8_t* findTexHeaderInTex1Section(uint8_t* tex1Ptr, const char* textureName);

    uint32_t swapIndexBits(bool leftIsGreater, uint32_t bits);

    void recolorCmprTexture(uint8_t* tex1Ptr, const char* textureName, uint8_t* rgb);

    uint8_t* findTex1InBmd(uint8_t* bmdPtr);

} // namespace libtp::util::texture
#endif