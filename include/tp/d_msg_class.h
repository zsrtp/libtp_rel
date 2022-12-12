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
        void jmessage_tSequenceProcessor__do_begin( void* seqProcessor, const void* unk2, const char* text );
        bool jmessage_tSequenceProcessor__do_tag( void* seqProcessor, uint32_t unk2, const void* currentText, uint32_t unk4 );
    }
}     // namespace libtp::tp::d_msg_class
#endif