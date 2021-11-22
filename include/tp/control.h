/**	@file control.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *  @author Zephiles
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_CONTROL_H
#define TP_CONTROL_H

#include <cstdint>

namespace libtp::tp::control
{
    // Message command stuff
#define MSG_BEGIN( name ) const char* name =

#define MSG_END() ;

#define MSG_SPEED( speed ) "\x1A\x05\x00\x00" speed

#define MSG_COLOR( id ) "\x1A\x06\xFF\x00\x00" id

// Message Text Color Values
#define MSG_COLOR_WHITE "\x00"
#define MSG_COLOR_RED "\x01"
#define MSG_COLOR_GREEN "\x02"
#define MSG_COLOR_DARK_BLUE "\x03"
#define MSG_COLOR_YELLOW "\x04"
#define MSG_COLOR_PURPLE "\x06"
#define MSG_COLOR_ORANGE "\x08"

    extern "C"
    {
        bool render( void* TControl );
    }
}     // namespace libtp::tp::control
#endif