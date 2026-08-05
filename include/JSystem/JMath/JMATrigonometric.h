/**	@file JMATrigonometric.h
 *	@brief Contains functions for handling various aspects of the game
 *
 * @author Captain Kitty Cat
 *	@bug No known bugs.
 */
#ifndef JMATRIGONOMETRIC_H
#define JMATRIGONOMETRIC_H

#include <cstdint>
#include <utility.h>

namespace libtp::tp
{
    struct TSinCosTable
    {
        libtp::pair<float, float> table[0x2000];

    } __attribute__((__packed__));

    extern "C"
    {
        extern TSinCosTable sincosTable_;
    }
} // namespace libtp::tp
#endif