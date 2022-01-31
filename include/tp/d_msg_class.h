/**	@file d_msg_class.h
 *	@brief Contains file definitions that point to the font color table.
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_MSG_CLASS_H
#define TP_D_MSG_CLASS_H

#include <cstdint>

namespace libtp::tp::d_msg_class
{
    extern "C"
    {
        uint32_t getFontCCColorTable( uint8_t colorId, uint8_t unk );
        uint32_t getFontGCColorTable( uint8_t colorId, uint8_t unk );
    }
}     // namespace libtp::tp::d_msg_class
#endif