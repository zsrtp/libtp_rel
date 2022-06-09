#ifndef VEC_H
#define VEC_H

#include <cstdint>

// Declare classes/structs so that other stuff can use them
struct Vec;

typedef Vec* VecPtr;
typedef Vec Point3d;
typedef Vec* Point3dPtr;

extern "C"
{
    // Functions
    void PSVECAdd( const Vec* a, const Vec* b, Vec* ab );
    void PSVECSubtract( const Vec* a, const Vec* b, Vec* a_b );
    void PSVECScale( const Vec* src, Vec* dst, float scale );
    void PSVECNormalize( const Vec* src, Vec* unit );
    float PSVECSquareMag( const Vec* v );
    float PSVECMag( const Vec* v );
    float PSVECDotProduct( const Vec* a, const Vec* b );
    void PSVECCrossProduct( const Vec* a, const Vec* b, Vec* axb );
    float PSVECSquareDistance( const Vec* a, const Vec* b );
    float PSVECDistance( const Vec* a, const Vec* b );
    void C_VECHalfAngle( const Vec* a, const Vec* b, Vec* half );
    void C_VECReflect( const Vec* src, const Vec* normal, Vec* dst );
}

struct Vec
{
    float x, y, z;

    float GetX() const { return x; }
    float GetY() const { return y; }
    float GetZ() const { return z; }
    float getXDiff( const Vec* other ) const { return x - other->x; }
    float getYDiff( const Vec* other ) const { return y - other->y; }
    float getZDiff( const Vec* other ) const { return z - other->z; }

    void set( float pX, float pY, float pZ )
    {
        x = pX;
        y = pY;
        z = pZ;
    }

    void set( const Vec& other )
    {
        x = other.x;
        y = other.y;
        z = other.z;
    }
} __attribute__( ( __packed__ ) );

static_assert( sizeof( Vec ) == 0xC );

struct SVec
{
    int16_t x, y, z;

    void set( int16_t oX, int16_t oY, int16_t oZ )
    {
        x = oX;
        y = oY;
        z = oZ;
    }
} __attribute__( ( __packed__ ) );

static_assert( sizeof( SVec ) == 0x6 );

#endif