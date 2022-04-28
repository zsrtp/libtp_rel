/** @file patch.h
 * @author PistonMiner
 * @brief Useful for function hooking
 *
 * @bug No known bugs
 */
#ifndef LIBTP_PATCH_H
#define LIBTP_PATCH_H

#include <cstdint>

#include "cxx.h"
#include "memory.h"

namespace libtp::patch
{
    void writeBranch( void* ptr, void* destination );
    void writeBranchLR( void* ptr, void* destination );
    void writeBranchBL( void* ptr, void* destination );
    void writeBranchMain( void* ptr, void* destination, uint32_t branch );

    template<typename Func, typename Dest>
    Func hookFunction( Func function, Dest destination )
    {
        uint32_t* instructions = reinterpret_cast<uint32_t*>( function );

#ifdef PLATFORM_WII
        uint32_t* trampoline = new ( 0x4, HEAP_ZELDA ) uint32_t[2];
#else
        uint32_t* trampoline = new uint32_t[2];
#endif

        // Original instruction
        trampoline[0] = instructions[0];
        memory::clear_DC_IC_Cache( &trampoline[0], sizeof( uint32_t ) );

        // Branch to original function past hook
        writeBranch( &trampoline[1], &instructions[1] );

        // Write actual hook
        writeBranch( &instructions[0], reinterpret_cast<void*>( static_cast<Func>( destination ) ) );

        return reinterpret_cast<Func>( trampoline );
    }

    template<typename Func>
    Func unhookFunction( Func trampoline )
    {
        if ( !trampoline )
        {
            return nullptr;
        }

        uint32_t* instructions = reinterpret_cast<uint32_t*>( trampoline );

        // Restore the original instruction
        int32_t branchLength = instructions[1] & 0x03FFFFFC;

        // Check if this is a negative branch
        if ( branchLength > 0x01FFFFFC )
        {
            const int32_t Width = 26;
            const int32_t Mask = ( 1 << ( Width - 1 ) );
            branchLength = ( branchLength ^ Mask ) - Mask - 0x4;
        }

        uint32_t instructionAddress = reinterpret_cast<uint32_t>( &instructions[1] );
        uint32_t* address = reinterpret_cast<uint32_t*>( instructionAddress + branchLength );
        *address = instructions[0];

        // Clear the cache for both the address and where the instructions were stored
        memory::clear_DC_IC_Cache( address, sizeof( uint32_t ) );
        memory::clear_DC_IC_Cache( instructions, sizeof( uint32_t ) );

        // Free the memory used by the trampoline
        delete[] instructions;
        return nullptr;
    }
}     // namespace libtp::patch
#endif