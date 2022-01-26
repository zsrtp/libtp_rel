/**	@file vec.h
 *	@brief Defines vector structures.
 *
 *	@author Isaac
 *	@bug
 */
#ifndef DOLPHIN_MTX_VECR_H
#define DOLPHIN_MTX_VECR_H

#include <cstdint>

struct Vec
{
    float x, y, z;
};

struct SVec
{
    int16_t x, y, z;
};

#endif