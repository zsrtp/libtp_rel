/** @file resource.h
 *  @brief Contains functions that help process Message values.
 *
 *  @author Zephiles
 *  @author Lunar Soap
 *	@bug No known bugs.
 */

namespace libtp::tp::resource
{
	extern "C"
	{
        /**
         *  @brief Parses through the current character
         * 
         *  @returns char to be processed
        */
		char parseCharacter_1Byte(const char** text);
	}

	 // Macros for custom messages
    #define MSG_BEGIN(name) \
        char* name = 
    
    #define MSG_BEGIN_CONST(name) \
        const char* name = 
    
    #define MSG_END() \
        ;
    
    #define MSG_SPEED(speed) \
        "\x1A\x05\x00\x00" speed
    
    #define MSG_COLOR(id) \
        "\x1A\x06\xFF\x00\x00" id
	
	 //Message Text Color Values
    #define MSG_COLOR_WHITE "\x00"
	#define MSG_COLOR_RED "\x01"
    #define MSG_COLOR_GREEN "\x02"
    #define MSG_COLOR_DARK_BLUE "\x03"
    #define MSG_COLOR_YELLOW "\x04"
    #define MSG_COLOR_PURPLE "\x06"
    #define MSG_COLOR_ORANGE "\x08"
}