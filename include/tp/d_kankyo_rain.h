/**	@file d_kankyo_rain.h
 *	@brief Kankyo environment functions
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_KANKYO_RAIN_H
#define TP_D_KANKYO_RAIN_H

#include <cstdint>

namespace libtp::tp::d_kankyo_rain
{
    extern "C"
    {
        /**
         *  @brief Draws the scent path when Link uses his senses.
         *
         *  @param mtx The matrix values to be drawn.
         *  @param ResTIMG Unknown.
         */
        void dKyr_odour_draw( float mtx[3][4], uint8_t** ResTIMG );
    }
}     // namespace libtp::tp::d_kankyo_rain
#endif