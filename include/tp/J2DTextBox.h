#ifndef TP_J2DTEXTBOX_H
#define TP_J2DTEXTBOX_H

#include <cstdint>
#include <cstdarg>
#include <cstring>

#include "tp/J2DPane.h"
#include "cxx.h"

namespace libtp::tp::J2DTextBox
{
    enum J2DTextBoxVBinding
    {
        /* 0x0 */ VBIND_CENTER = 0,
        /* 0x1 */ VBIND_BOTTOM,
        /* 0x2 */ VBIND_TOP
    };

    enum J2DTextBoxHBinding
    {
        /* 0x0 */ HBIND_CENTER = 0,
        /* 0x1 */ HBIND_RIGHT,
        /* 0x2 */ HBIND_LEFT
    };

    extern "C"
    {
        void* J2DTextBox_ct1( void* J2DTextBox );                      // Constructor
        void* J2DTextBox_dt( void* J2DTextBox, int16_t freeThis );     // Destructor
        void J2DTextBox_setFont( void* J2DTextBox, void* font );
        void J2DTextBox_draw1( void* J2DTextBox, float x, float y );
        void J2DTextBox_draw2( void* J2DTextBox, float x, float y, float maxScreenHorizontalSize, J2DTextBoxHBinding hBind );
        int32_t J2DTextBox_setString1( void* J2DTextBox, const char* format, ... );
    }

    class J2DTextBox: public libtp::tp::J2DPane::J2DPane
    {
       public:
        struct TFontSize
        {
            /* 0x0 */ float mSizeX;
            /* 0x4 */ float mSizeY;
        };

        J2DTextBox() { J2DTextBox_ct1( this ); }

        void setFontSize( float sizeX, float sizeY )
        {
            float x;
            if ( sizeX > 0.0f )
            {
                x = sizeX;
            }
            else
            {
                x = 0.0f;
            }
            field_0x11c = x;

            float y;
            if ( sizeY > 0.0f )
            {
                y = sizeY;
            }
            else
            {
                y = 0.0f;
            }
            field_0x120 = y;
        }

        void setFontSize( TFontSize size ) { setFontSize( size.mSizeX, size.mSizeY ); }

        void setSolidColor( uint32_t color )
        {
            mCharColor = color;
            mGradientColor = color;
        }

        void setLineSpacing( float spacing )
        {
            if ( spacing > 0.0f )
            {
                mLineSpacing = spacing;
            }
            else
            {
                mLineSpacing = 0.0f;
            }
        }

        // Custom implementation of setString to avoid possible fragmentation when allocating memory for the string
        int32_t setString( const char* string )
        {
            // Make sure memory isn't already allocated for the string
            delete[] mStringPtr;

            // Get the length of the string, as well as the size that will be used by it
            const uint32_t len = strlen( string );
            const uint32_t size = len + 1;

            // Allocate the memory to the back of the heap to avoid possible fragmentation
            // Align to char, as strings don't have specific alignment requirements
            char* buf = new ( -sizeof( char ) ) char[size];
            strcpy( buf, string );

            // Assign the variables
            mStringLength = static_cast<int16_t>( size );
            mStringPtr = buf;
            return len;
        }

       private:
        /* 0x0100 */ void* mFont;
        /* 0x0104 */ uint32_t mCharColor;
        /* 0x0108 */ uint32_t mGradientColor;
        /* 0x010C */ float field_0x10c;
        /* 0x0110 */ float field_0x110;
        /* 0x0114 */ float mCharSpacing;
        /* 0x0118 */ float mLineSpacing;
        /* 0x011C */ float field_0x11c;
        /* 0x0120 */ float field_0x120;
        /* 0x0124 */ char* mStringPtr;
        /* 0x0128 */ uint32_t mWhiteColor;
        /* 0x012C */ uint32_t mBlackColor;
        /* 0x0130 */ uint8_t mFlags;
        /* 0x0131 */ bool mTextFontOwned;
        /* 0x0132 */ int16_t mStringLength;
    };
}     // namespace libtp::tp::J2DTextBox
#endif