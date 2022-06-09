#ifndef C_XYZ_H
#define C_XYZ_H

#include "symbol_defines.h"
#include "dolphin/mtx/vec.h"

#include <cstdint>
#include <cmath>

// Declare classes/structs so that other stuff can use them
struct cXyz;

extern "C"
{
    // Variables
    extern const cXyz cXyz_Zero;
    extern const cXyz cXyz_BaseX;
    extern const cXyz cXyz_BaseY;
    extern const cXyz cXyz_BaseZ;
    extern const cXyz cXyz_BaseXY;
    extern const cXyz cXyz_BaseXZ;
    extern const cXyz cXyz_BaseYZ;
    extern const cXyz cXyz_BaseXYZ;

    // Functions
    cXyz* cXyz_dt( cXyz* cXyzThis, int16_t freeThis );                                                        // Destructor
    cXyz* cXyz_operator_plus_vec( cXyz* __return_storage_ptr, const cXyz* cXyzThis, const Vec& vec );         // Operator
    cXyz* cXyz_operator_minus_vec( cXyz* __return_storage_ptr, const cXyz* cXyzThis, const Vec& vec );        // Operator
    cXyz* cXyz_operator_multiply_float( cXyz* __return_storage_ptr, const cXyz* cXyzThis, float value );      // Operator
    cXyz* cXyz_operator_multiply_vec( cXyz* __return_storage_ptr, const cXyz* cXyzThis, const Vec& vec );     // Operator
    cXyz* cXyz_operator_divide_float( cXyz* __return_storage_ptr, const cXyz* cXyzThis, float value );        // Operator
    cXyz* cXyz_getCrossProduct( cXyz* __return_storage_ptr, const cXyz* cXyzThis, const Vec& vec );
    cXyz* cXyz_outprod( cXyz* __return_storage_ptr, const cXyz* cXyzThis, const Vec& vec );
    cXyz* cXyz_norm( cXyz* __return_storage_ptr, const cXyz* cXyzThis );
    cXyz* cXyz_normZP( cXyz* __return_storage_ptr, const cXyz* cXyzThis );
    cXyz* cXyz_normZC( cXyz* __return_storage_ptr, const cXyz* cXyzThis );
    cXyz* cXyz_normalize( cXyz* __return_storage_ptr, cXyz* cXyzThis );
    cXyz* cXyz_normalizeZP( cXyz* __return_storage_ptr, cXyz* cXyzThis );
    bool cXyz_normalizeRS( cXyz* cXyzThis );
    bool cXyz_operator_equal_equal_vec( const cXyz* cXyzThis, const Vec& vec );     // Operator
    bool cXyz_operator_not_equal_vec( const cXyz* cXyzThis, const Vec& vec );       // Operator
    bool cXyz_isZero( const cXyz* cXyzThis );
    int16_t cXyz_atan2sX_Z( const cXyz* cXyzThis );
    int16_t cXyz_atan2sY_XZ( const cXyz* cXyzThis );
}

struct cXyz: Vec
{
    /*
    static const cXyz Zero;
    static const cXyz BaseX;
    static const cXyz BaseY;
    static const cXyz BaseZ;
    static const cXyz BaseXY;
    static const cXyz BaseXZ;
    static const cXyz BaseYZ;
    static const cXyz BaseXYZ;
    */

    // ~cXyz() {}
    cXyz() {}

    cXyz( float x, float y, float z )
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }

    cXyz( const cXyz& vec )
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
    }

    cXyz( const Vec& vec )
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
    }

    void operator=( const Vec& vec )
    {
        this->x = vec.x;
        this->y = vec.y;
        this->z = vec.z;
    }

    // cXyz operator+( Vec const& ) const;
    // cXyz operator-( Vec const& ) const;
    // cXyz operator*( float ) const;
    // cXyz operator*( Vec const& ) const;
    // cXyz operator/( float ) const;

    void operator+=( float f )
    {
        x += f;
        y += f;
        z += f;
    }

    void operator-=( float f )
    {
        x -= f;
        y -= f;
        z -= f;
    }

    void operator-=( const Vec& other ) { PSVECSubtract( this, &other, this ); }

    void operator+=( const Vec& vec )
    {
        x += vec.x;
        y += vec.y;
        z += vec.z;
    }

    void operator*=( float scale ) { PSVECScale( this, this, scale ); }

    // cXyz getCrossProduct(Vec const&) const;
    // cXyz outprod(Vec const&) const;
    // cXyz norm() const;
    // cXyz normZP() const;
    // cXyz normZC() const;
    // cXyz normalize();
    // cXyz normalizeZP();

    bool normalizeRS() { return cXyz_normalizeRS( this ); }
    bool operator==( const Vec& vec ) const { return cXyz_operator_equal_equal_vec( this, vec ); }
    bool operator!=( const Vec& vec ) const { return cXyz_operator_not_equal_vec( this, vec ); }
    bool isZero() const { return cXyz_isZero( this ); }
    int16_t atan2sX_Z() const { return cXyz_atan2sX_Z( this ); }
    int16_t atan2sY_XZ() const { return cXyz_atan2sY_XZ( this ); }

    void setAll( float f )
    {
        z = f;
        y = f;
        x = f;
    }

    void setMin( const cXyz& other )
    {
        if ( x > other.x )
        {
            x = other.x;
        }

        if ( y > other.y )
        {
            y = other.y;
        }

        if ( z > other.z )
        {
            z = other.z;
        }
    }

    void setMax( const cXyz& other )
    {
        if ( x < other.x )
        {
            x = other.x;
        }

        if ( y < other.y )
        {
            y = other.y;
        }

        if ( z < other.z )
        {
            z = other.z;
        }
    }

    float getSquareMag() const { return PSVECSquareMag( this ); }
    float getSquareDistance( const Vec& other ) const { return PSVECSquareDistance( this, &other ); }

    static float getNearZeroValue() { return 8e-11f; }

    bool isNearZeroSquare() const { return ( this->getSquareMag() < getNearZeroValue() ); }
    float abs2() const { return this->getSquareMag(); }
    float abs2( const Vec& other ) const { return this->getSquareDistance( other ); }

    float abs2XZ() const
    {
        cXyz tmp( this->x, 0, this->z );
        return tmp.abs2();
    }

    float abs2XZ( const Vec& other ) const
    {
        cXyz tmp( this->x, 0, this->z );
        cXyz tmp2( other.x, 0, other.z );
        return tmp.abs2( tmp2 );
    }

    float abs() const { return sqrtf( this->abs2() ); }
    float abs( const Vec& other ) const { return sqrtf( this->abs2( other ) ); }
    float absXZ() const { return sqrtf( this->abs2XZ() ); }
    float absXZ( const Vec& other ) const { return sqrtf( this->abs2XZ( other ) ); }
    float getMagXZ() const { return cXyz( this->x, 0, this->z ).getSquareMag(); }
} __attribute__( ( __packed__ ) );

static_assert( sizeof( cXyz ) == 0xC );

#endif