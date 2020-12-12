#include "display/console.h"

#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "tp/JFWSystem.h"

namespace libtp::display
{
    const char* heading = "Twilight Princess - REL::%s";
    const char* pre_description = "A mod by %s:";
    const char* legalText = "Powered by libtp | (C) AECX, Zephiles";
    const char* github = "Github: zsrtp";
    const char* twitter = "Twitter: AECXTP, Zephiles_";

    Console::Console(const char* author,
                     const char* title,
                     const char* description,
                     const char* description1,
                     const char* description2,
                     const char* version)
    {
        // Display some information about this mod, the project and everything

        // Load the console as a local pointer to save memory on each use
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        // Get the max size minus one, to insure that the last char is always NULL
        std::size_t max = sizeof(tp::jfw_system::ConsoleLine::line) - 1;

        setConsole(true, 25);

        snprintf(console->consoleLine[0].line, max, heading, title);
        snprintf(console->consoleLine[2].line, max, pre_description, author);
        strncpy(console->consoleLine[4].line, description, max);
        strncpy(console->consoleLine[5].line, description1, max);
        strncpy(console->consoleLine[6].line, description2, max);

        strncpy(console->consoleLine[10].line, version, max);
        strncpy(console->consoleLine[21].line, legalText, max);
        strncpy(console->consoleLine[23].line, github, max);
        strncpy(console->consoleLine[24].line, twitter, max);

        return;
    }

    void clearConsole(uint8_t from, uint8_t count)
    {
        // Load the console as a local pointer to avoid loading it each loop
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        // If count is 0 we want to clear all lines
        std::size_t linecount = sizeof(tp::jfw_system::SystemConsole::consoleLine) / sizeof(tp::jfw_system::ConsoleLine);

        if (from > linecount)
        {
            from = 0;
        }

        // count = 0 ?              - remaining lines
        // from + count > linecount - remaining lines
        // else                     - count
        count = (count == 0 ? (linecount - from) : ((from + count) > linecount ? (linecount - from) : count));

        std::size_t lineLength = sizeof(tp::jfw_system::ConsoleLine::line);

        for (uint8_t i = from; i < from + count; i++)
        {
            memset(console->consoleLine[i].line, 0x0, lineLength);
        }

        return;
    }

    void setConsole(bool state, uint8_t lines)
    {
        // Load the console as a local pointer to avoid loading it each loop
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        console->consoleEnabled = state;

        for (uint8_t line = 0; line < lines; line++)
        {
            console->consoleLine[line].showLine = state;
        }
    }

    void setConsoleColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha)
    {
        // Load the console as a local pointer to save memory on each use
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        console->consoleColor[0] = red;
        console->consoleColor[1] = green;
        console->consoleColor[2] = blue;
        console->consoleColor[3] = alpha;
        return;
    }

    char* print(uint8_t line, const char* text)
    {
        // Get the max size minus one, to insure that the last char is always NULL
        std::size_t max = sizeof(tp::jfw_system::ConsoleLine::line) - 1;
        return strncpy(tp::jfw_system::systemConsole->consoleLine[line].line, text, max);
    }
}  // namespace libtp::display
