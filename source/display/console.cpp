#include "display/console.h"

#include <cinttypes>
#include <cstddef>
#include <cstdint>
#include <cstdio>
#include <cstring>

#include "tp/JFWSystem.h"

namespace libtp::display
{
    Console::Console( uint8_t protection ): m_Protect( protection )
    {
        // Init
        libtp::display::setConsole( true, 25 );

        this->m_Line = 0;
        this->m_Col = 0;

        // Display initial information, then lock line 1 (could be overwritten manually)
        *this << _PROJECT_NAME " - v" _VERSION " " _VARIANT << "\n"
              << "Powered by github/zsrtp/libtp_rel"
              << "\n"
              << "Created by AECX & Zephiles"
              << "\n"
              << "Build ID: " << _BUILDID << "\n"
              << "Version: " << _VERSION " " _VARIANT "\n\n";
    }

    void Console::parse( const char* text )
    {
        // Store the console pointer once
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        while ( *text != '\0' )
        {
            if ( *text == '\n' )
            {
                this->m_Col = 0;
                setLine( m_Line + 1 );
            }
            else if ( *text == '\r' )
            {
                this->m_Col = 0;
            }
            else
            {
                // Adjust if otherwise out of bounds
                if ( this->m_Col >= 48 )
                {
                    // Null terminate this line
                    console->consoleLine[this->m_Line].line[this->m_Col] = '\0';

                    setLine( m_Line + 1 );
                    this->m_Col = 0;
                }

                // Print to current line and col
                console->consoleLine[this->m_Line].line[this->m_Col] = *text;
                this->m_Col++;
            }

            // Advance the pointer
            text++;
        }     // End of while

        console->consoleLine[this->m_Line].line[this->m_Col] = '\0';
    }

    void Console::setLine( uint8_t line )
    {
        m_Line = line;

        if ( this->m_Line >= 25 )
        {
            // Reset to the number of lines we want to be protected
            this->m_Line = m_Protect;
            this->m_Col = 0;
            // Clear lines
            libtp::display::clearConsole( m_Protect, 0 );
        }
    }

    Console& operator<<( Console& console, const char* text )
    {
        console.parse( text );
        return console;
    }

    Console& operator<<( Console& console, char* text )
    {
        console.parse( text );
        return console;
    }

    Console& operator<<( Console& console, char chr )
    {
        char buf[1];
        buf[0] = chr;
        console.parse( buf );
        return console;
    }

    Console& operator<<( Console& console, uint8_t n )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "%02" PRIx8, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int8_t n )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "%" PRId8, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, uint16_t n )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "%04" PRIx16, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int16_t n )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "%" PRId16, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, uint32_t n )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "%08" PRIx32, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int32_t n )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "%" PRId32, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, uint64_t n )
    {
        return console << static_cast<uint32_t>( n >> 32 ) << static_cast<uint32_t>( n );
    }

    Console& operator<<( Console& console, int64_t n )
    {
        return console << static_cast<int32_t>( n >> 32 ) << static_cast<int32_t>( n );
    }

    Console& operator<<( Console& console, float n )
    {
        // Custom print this
        char buf[15];

        // Is there a cinttype for float?
        sprintf( buf, "%.4f", n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, void* ptr )
    {
        // Custom print this
        char buf[15];

        sprintf( buf, "0x%" PRIxPTR, reinterpret_cast<uint32_t>( ptr ) );
        console.parse( buf );

        return console;
    }

    void clearConsole( uint8_t from, uint8_t count )
    {
        // Load the console as a local pointer to avoid loading it each loop
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        // If count is 0 we want to clear all lines
        std::size_t linecount = sizeof( tp::jfw_system::SystemConsole::consoleLine ) / sizeof( tp::jfw_system::ConsoleLine );

        if ( from > linecount )
        {
            from = 0;
        }

        // count = 0 ?              - remaining lines
        // from + count > linecount - remaining lines
        // else                     - count
        count = ( count == 0 ? ( linecount - from ) : ( ( from + count ) > linecount ? ( linecount - from ) : count ) );

        std::size_t lineLength = sizeof( tp::jfw_system::ConsoleLine::line );

        for ( uint8_t i = from; i < from + count; i++ )
        {
            memset( console->consoleLine[i].line, 0x0, lineLength );
        }

        return;
    }

    void setConsole( bool state, uint8_t lines )
    {
        // Load the console as a local pointer to avoid loading it each loop
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        console->consoleEnabled = state;

        for ( uint8_t line = 0; line < lines; line++ )
        {
            console->consoleLine[line].showLine = state;
        }
    }

    void setConsoleColor( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha )
    {
        // Load the console as a local pointer to save memory on each use
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        console->consoleColor[0] = red;
        console->consoleColor[1] = green;
        console->consoleColor[2] = blue;
        console->consoleColor[3] = alpha;
        return;
    }

    char* print( uint8_t line, const char* text )
    {
        // Get the max size minus one, to insure that the last char is always NULL
        std::size_t max = sizeof( tp::jfw_system::ConsoleLine::line ) - 1;
        return strncpy( tp::jfw_system::systemConsole->consoleLine[line].line, text, max );
    }
}     // namespace libtp::display
