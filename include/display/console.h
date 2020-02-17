/**	@file console.h
 *  @brief Wrapper functions for the
 *
 *  Provides definitions for using and interacting with the console class
 *
 *  @todo Create some sort of menuing system etc.
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#include "../tp/JFWSystem.h"
#include "../types.h"

namespace libtp::display
{
    const char* heading;
    const char* pre_description;
    const char* legalText;
    const char* github;
    const char* twitter;

    /**
     *  @brief Console wrapper class
     *
     *  @todo Add features (menu, watches, etc.)
     */
    class Console
    {
       public:
        /**
         *  @brief Wrapper class for accessing the JFW console
         *
         *  @param author Author name to display on legal stream
         *  @param title The name of your mod
         *  @param description Small description text about your mod
         *  @param version Version string (i.e. v3.1)
         */
        Console(const char* author, const char* title, const char* description, const char* version);

       private:
        const char* _author;       // Author name to display on legal screen
        const char* _title;        // Title of this mod
        const char* _description;  // Short description
        const char* _version;      // Version string to display (i.e. v3.1)
    };
    /**
     *  @brief Sets the state of the console
     *
     *  @param state If true: Enabled otherwise disabled
     *  @param lines Number of lines to enable, 0 to enable the console but hide the lines (max. 25; check: tp/JFWSystem.h)
     */
    void setConsole(bool state, u8 lines);

    /**
     *  @brief Sets the console background colour + Alpha
     */
    void setConsoleColor(u8 red, u8 green, u8 blue, u8 alpha);

    /**
     *  @brief Copies text to a console line
     *
     *  @param line The targeted line
     *  @param text The text to be printed
     *
     *  @return The pointer to the console line
     */
    char* print(u8 line, const char* text);
}  // namespace libtp::display