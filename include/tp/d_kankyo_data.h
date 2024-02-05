/**	@file d_kankyo_data.h
 *	@brief Kankyo data structures
 *
 *	The d_kankyo_data holds data structures for d_kankyo.
 *
 *	@author TakaRikka
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef TP_D_KANKYO_DATA_H
#define TP_D_KANKYO_DATA_H

#include <cstdint>

namespace libtp::tp::d_kankyo_data
{
    struct color_RGB_class
    {
        uint8_t r;
        uint8_t g;
        uint8_t b;
    };
} // namespace libtp::tp::d_kankyo_data
#endif