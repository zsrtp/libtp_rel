/**	@file c_xyz.h
 *	@brief Defines x,y,z vector structure.
 *
 *	@author Isaac
 *	@bug
 */
#ifndef SSYSTEM_SCOMPONENT_C_XYZ_H
#define SSYSTEM_SCOMPONENT_C_XYZ_H

#include <cstdint>

#include "dolphin/mtx/vec.h"

struct cXyz: Vec
{
    void set(float pX, float pY, float pZ)
    {
        x = pX;
        y = pY;
        z = pZ;
    }

    void setall(float f) { set(f, f, f); }
} __attribute__((__packed__));

#endif