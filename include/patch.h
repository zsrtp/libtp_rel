/** @file patch.h
 * @author PistonMiner
 * @brief Useful for function hooking
 *
 * @bug No known bugs
 */
#ifndef LIBTP_PATCH_H
#define LIBTP_PATCH_H

#include <cstdint>

#include "memory.h"

namespace libtp::patch
{
    void writeBranch( void* ptr, void* destination );
    void writeBranchLR( void* ptr, void* destination );
    void writeBranchMain( void* ptr, void* destination, uint32_t branch );

    template<typename Func, typename Dest>
    Func hookFunction( Func function, Dest destination )
    {
        uint32_t* instructions = reinterpret_cast<uint32_t*>( function );

        uint32_t* trampoline = new uint32_t[2];

        // Original instruction
        trampoline[0] = instructions[0];
        memory::clear_DC_IC_Cache( &trampoline[0], sizeof( uint32_t ) );

        // Branch to original function past hook
        writeBranch( &trampoline[1], &instructions[1] );

        // Write actual hook
        writeBranch( &instructions[0], reinterpret_cast<void*>( static_cast<Func>( destination ) ) );

        return reinterpret_cast<Func>( trampoline );
    }
}     // namespace libtp::patch
#endif