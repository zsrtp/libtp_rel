#ifndef C_SXYZ_H
#define C_SXYZ_H

#include "symbol_defines.h"
#include "dolphin/mtx/vec.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
struct csXyz;

extern "C"
{
    csXyz* csXyz_dt( csXyz* csXyzThis, int16_t freeThis );                                                  // Destructor
    csXyz* csXyz_ct( csXyz* csXyzThis, int16_t x, int16_t y, int16_t z );                                   // Constructor
    csXyz* csXyz_operator_plus_csXyz( csXyz* __return_storage_ptr, csXyz* csXyzThis, csXyz& other );        // Operator
    void csXyz_operator_plus_equal_csXyz( csXyz* csXyzThis, csXyz& other );                                 // Operator
    csXyz* csXyz_operator_minus_csXyz( csXyz* __return_storage_ptr, csXyz* csXyzThis, csXyz& other );       // Operator
    csXyz* csXyz_operator_multiply_float( csXyz* __return_storage_ptr, csXyz* csXyzThis, float value );     // Operator
}

class csXyz: public SVec
{
   public:
    // static const csXyz Zero;

    // ~csXyz() {}
    csXyz() {}
    csXyz( const csXyz& other ): SVec( other ) {};
    csXyz( int16_t x, int16_t y, int16_t z ) { csXyz_ct( this, x, y, z ); }
    // csXyz operator+( csXyz& );
    void operator+=( csXyz& other ) { csXyz_operator_plus_equal_csXyz( this, other ); }
    // csXyz operator-( csXyz& );
    // csXyz operator*( float );
    int16_t GetX() const { return x; }
    int16_t GetY() const { return y; }
    int16_t GetZ() const { return z; }
} __attribute__( ( __packed__ ) );

static_assert( sizeof( csXyz ) == 0x6 );

#endif