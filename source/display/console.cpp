#include "display/console.h"


#include <cstddef>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <cinttypes>

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
              << "Build ID: " << _BUILDID << "\n\n";
    }

    void Console::parse( const char* text )
    {
        // Store the console line pointer once
        tp::jfw_system::ConsoleLine* linePtr = &tp::jfw_system::systemConsole->consoleLine[0];

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
                const uint32_t col = this->m_Col;
                if ( col >= 48 )
                {
                    // Null terminate this line
                    const uint32_t line = this->m_Line;
                    linePtr[line].line[col] = '\0';

                    setLine( line + 1 );
                    this->m_Col = 0;
                }

                // Print to current line and col
                linePtr[this->m_Line].line[this->m_Col] = *text;
                this->m_Col++;
            }

            // Advance the pointer
            text++;
        }     // End of while

        linePtr[this->m_Line].line[this->m_Col] = '\0';
    }

    void Console::setLine( uint8_t line )
    {
        // Clear following lines
        uint32_t mLine = this->m_Line;
        if ( line < mLine )
        {
            display::clearConsole( line, 0 );
        }

        mLine = line;

        tp::jfw_system::ConsoleLine* linePtr = &tp::jfw_system::systemConsole->consoleLine[0];
        if ( mLine >= 25 )
        {
            mLine = 24;

            // Move all lines up by one starting at protected + 1
            for ( uint8_t i = m_Protect + 1; i < 25; i++ )
            {
                strncpy( linePtr[i - 1].line, linePtr[i].line, 48 );
            }
        }

        this->m_Line = static_cast<uint8_t>( mLine );
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
        char buf[2];
        buf[0] = chr;
        buf[1] = '\0';

        console.parse( buf );
        return console;
    }

    Console& operator<<( Console& console, uint8_t n )
    {
        // Custom print this
        char buf[16];

        snprintf( buf, sizeof( buf ), "%02" PRIx8, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int8_t n )
    {
        // Custom print this
        char buf[16];

        snprintf( buf, sizeof( buf ), "%" PRId8, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, uint16_t n )
    {
        // Custom print this
        char buf[16];

        snprintf( buf, sizeof( buf ), "%04" PRIx16, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int16_t n )
    {
        // Custom print this
        char buf[16];

        snprintf( buf, sizeof( buf ), "%" PRId16, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, uint32_t n )
    {
        // Custom print this
        char buf[16];

        snprintf( buf, sizeof( buf ), "%08" PRIx32, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int32_t n )
    {
        // Custom print this
        char buf[32];

        snprintf( buf, sizeof( buf ), "%" PRId32, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, uint64_t n )
    {
        // Custom print this
        char buf[64];

        snprintf( buf, sizeof( buf ), "%" PRIu64, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, int64_t n )
    {
        // Custom print this
        char buf[64];

        snprintf( buf, sizeof( buf ), "%" PRId64, n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, float n )
    {
        // Custom print this
        char buf[64];

        snprintf( buf, sizeof( buf ), "%.4f", n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, double n )
    {
        // Custom print this
        char buf[64];

        snprintf( buf, sizeof( buf ), "%.4f", n );
        console.parse( buf );

        return console;
    }

    Console& operator<<( Console& console, void* ptr )
    {
        // Custom print this
        char buf[16];

        sprintf( buf, "0x%" PRIxPTR, reinterpret_cast<uint32_t>( ptr ) );
        console.parse( buf );

        return console;
    }

    void clearConsole( uint8_t from, uint8_t count )
    {
        // If count is 0 we want to clear all lines; -1 because last line is debug info
        constexpr uint32_t linecount =
            sizeof( tp::jfw_system::SystemConsole::consoleLine ) / sizeof( tp::jfw_system::ConsoleLine ) - 1;

        if ( from > linecount )
        {
            from = 0;
        }

        // count = 0 ?              - remaining lines
        // from + count > linecount - remaining lines
        // else                     - count
        count = ( count == 0 ? ( linecount - from ) : ( ( from + count ) > linecount ? ( linecount - from ) : count ) );

        // Load the console line as a local pointer to avoid loading it each loop
        tp::jfw_system::ConsoleLine* linePtr = &tp::jfw_system::systemConsole->consoleLine[0];

        constexpr uint32_t lineLength = sizeof( tp::jfw_system::ConsoleLine::line );

        for ( uint32_t i = from; i < from + count; i++ )
        {
            memset( linePtr[i].line, 0x0, lineLength );
        }

        return;
    }

    void setConsole( bool state, uint8_t lines )
    {
        // Load the console as a local pointer to avoid loading it each loop
        tp::jfw_system::SystemConsole* console = tp::jfw_system::systemConsole;

        console->consoleEnabled = state;

        tp::jfw_system::ConsoleLine* linePtr = &console->consoleLine[0];
        for ( uint32_t line = 0; line < lines; line++ )
        {
            linePtr[line].showLine = state;
        }
    }

    void setConsoleColor( uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha )
    {
        uint8_t* consoleColorPtr = &tp::jfw_system::systemConsole->consoleColor[0];

        consoleColorPtr[0] = red;
        consoleColorPtr[1] = green;
        consoleColorPtr[2] = blue;
        consoleColorPtr[3] = alpha;
        return;
    }

    char* print( uint8_t line, const char* text )
    {
        // Get the max size minus one, to insure that the last char is always NULL
        constexpr uint32_t max = sizeof( tp::jfw_system::ConsoleLine::line ) - 1;
        return strncpy( tp::jfw_system::systemConsole->consoleLine[line].line, text, max );
    }
}     // namespace libtp::display
