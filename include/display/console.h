/**	@file console.h
 *  @brief Wrapper functions for the console
 *
 *  Provides definitions for using and interacting with the console class
 *
 *  @todo Create some sort of menuing system etc.
 *	@author AECX
 *	@bug No known bugs.
 */
#pragma once
#include <cstdint>

#include "../tp/JFWSystem.h"

namespace libtp::display
{
    /**
     *  @brief Console wrapper class
     *
     *  @todo Add features (menu, watches, etc.)
     */
    class Console
    {
       public:
        /**
         *  @brief Simple console class
         *
         * Warning: This is NOT a proper output buffer like cout! This is just meant for
         * easier access to the console and isn't as feature rich as a proper cout.
         */
        Console();

        /**
         *  @brief Reads a string and outputs it directly
         *
         *  @param text The char array to be parsed and displayed
         */
        void parse( const char* text );

       private:
        // Current line (should be < 25)
        uint8_t m_Line;
        // Current Column (should be < linewidth)
        uint8_t m_Col;

        // Operators
        friend Console& operator<<( Console& console, const char* text );
        friend Console& operator<<( Console& console, char* text );
        friend Console& operator<<( Console& console, char chr );
        // Output unsigned (hex) int
        friend Console& operator<<( Console& console, uint8_t n );
        // Output unsigned (hex) int
        friend Console& operator<<( Console& console, uint16_t n );
        // Output unsigned (hex) int
        friend Console& operator<<( Console& console, uint32_t n );
        // Output unsigned (hex) int
        friend Console& operator<<( Console& console, uint64_t n );
        // Output signed (dec) int
        friend Console& operator<<( Console& console, int8_t n );
        // Output signed (dec) int
        friend Console& operator<<( Console& console, int16_t n );
        // Output signed (dec) int
        friend Console& operator<<( Console& console, int32_t n );
        // Output signed (dec) int
        friend Console& operator<<( Console& console, int64_t n );
        // Output signed float
        friend Console& operator<<( Console& console, float n );
        // Prints the address of a given pointer
        friend Console& operator<<( Console& console, void* ptr );
    };

    /**
     *  @brief Clears all console lines in a given range i.e. clearConsole(0, 10)
     *
     *  @param from First line index to be cleared (inclusive)
     *  @param count Number of lines to be cleared, 0 = all
     */
    void clearConsole( uint8_t from, uint8_t count = 0 );

    /**
     *  @brief Sets the state of the console
     *
     *  @param state If true: Enabled otherwise disabled
     *  @param lines Number of lines to enable, 0 to enable the console but hide the lines (max. 25; check: tp/JFWSystem.h)
     */
    void setConsole( bool state, uint8_t lines );

    /**
     *  @brief Sets the console background colour + Alpha
     */
    void setConsoleColor( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha );

    /**
     *  @brief Copies text to a console line
     *
     *  @param line The targeted line
     *  @param text The text to be printed
     *
     *  @return The pointer to the console line
     */
    char* print( uint8_t line, const char* text );
}     // namespace libtp::display