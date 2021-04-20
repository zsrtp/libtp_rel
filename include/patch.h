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

    template<typename Func>
    Func unhookFunction( Func trampoline )
    {
        uint32_t* instructions = reinterpret_cast<uint32_t*>( trampoline );

        // Restore the original instruction
        uint32_t instructionAddress = reinterpret_cast<uint32_t>( &instructions[1] );
        uint32_t branchInstruction = instructions[1];
        uint32_t branchLength;
        uint32_t* address;

        if ( branchInstruction >= 0x4A000000 )
        {
            // Branch is negative
            branchLength = 0x4C000000 - branchInstruction;
            address = reinterpret_cast<uint32_t*>( instructionAddress - branchLength - 0x4 );
        }
        else
        {
            // Branch is positive
            branchLength = branchInstruction - 0x48000000;
            address = reinterpret_cast<uint32_t*>( instructionAddress + branchLength - 0x4 );
        }

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