/** @file resource.h
 *  @brief Contains functions that help process Message values.
 *
 *  @author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_RESOURCE_H
#define TP_RESOURCE_H

// Message commands
#define MSG_BEGIN_PTR( name ) const char* name =
#define MSG_BEGIN_ARRAY( name ) char name[] =

#define MSG_END() ;
#define MSG_SPEED( speed ) "\x1A\x05\x00\x00" speed
#define MSG_COLOR( id ) "\x1A\x06\xFF\x00\x00" id
#define MSG_ICON( icon ) "\x1A\x05\x00\x00" icon
#define MSG_PLYR_NAME "\x1A\x05\x00\x00\x00"
#define MSG_OPTION_LIST( option ) "\x1A\x06\x00\x00\x09" option

// Special Characters
#define MSG_SP_CHAR_KYO "\x1A\x05\x04\x00\x0A"

// Message Speeds
#define MSG_SPEED_FAST "\x01"
#define MSG_SPEED_SLOW "\x02"

// Message colors
#define MSG_COLOR_WHITE "\x00"
#define MSG_COLOR_RED "\x01"
#define MSG_COLOR_GREEN "\x02"
#define MSG_COLOR_LIGHT_BLUE "\x03"
#define MSG_COLOR_YELLOW "\x04"
#define MSG_COLOR_PURPLE "\x06"
#define MSG_COLOR_ORANGE "\x08"

// Custom message colors
#define CUSTOM_MSG_COLOR_DARK_GREEN "\x09"
#define CUSTOM_MSG_COLOR_BLUE "\x0A"
#define CUSTOM_MSG_COLOR_SILVER "\x0B"

// Standard hex values for message colors
#define MSG_COLOR_WHITE_HEX 0x0
#define MSG_COLOR_RED_HEX 0x1
#define MSG_COLOR_GREEN_HEX 0x2
#define MSG_COLOR_LIGHT_BLUE_HEX 0x3
#define MSG_COLOR_YELLOW_HEX 0x4
#define MSG_COLOR_PURPLE_HEX 0x6
#define MSG_COLOR_ORANGE_HEX 0x8

// Standard hex values for custom message colors
// Needed for the getFontCCColorTable and getFontGCColorTable hooks
#define CUSTOM_MSG_COLOR_DARK_GREEN_HEX 0x9
#define CUSTOM_MSG_COLOR_BLUE_HEX 0xA
#define CUSTOM_MSG_COLOR_SILVER_HEX 0xB

// Message Icon Values
#define MSG_ICON_R "\x0E"
#define MSG_ICON_A "\x0A"
#define MSG_ICON_X "\x0F"
#define MSG_ICON_Y "\x10"

// Message Option Values
#define MSG_OPTION_1 "\x01"
#define MSG_OPTION_2 "\x02"
#define MSG_OPTION_3 "\x03"

namespace libtp::tp::resource
{
    extern "C"
    {
        /**
         *  @brief Parses through the current character
         *
         *  @returns char to be processed
         */
        char parseCharacter_1Byte( const char** text );
    }

}     // namespace libtp::tp::resource
#endif