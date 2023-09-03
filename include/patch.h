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
    void writeBranch(void* ptr, void* destination);
    void writeBranchBL(void* ptr, void* destination);
    void writeBranchMain(void* ptr, void* destination, uint32_t branch);
    void writeAbsoluteBranch(void* ptr, void* destination);
    void writeStandardBranches(void* ptr, void* funcStart, void* funcEnd);

    template<typename Func, typename Dest>
    void writeBranch(Func func, Dest dst)
    {
        writeBranch(reinterpret_cast<void*>(func), reinterpret_cast<void*>(dst));
    }

    template<typename Func, typename Dest>
    void writeBranchBL(Func func, Dest dst)
    {
        writeBranchBL(reinterpret_cast<void*>(func), reinterpret_cast<void*>(dst));
    }

    template<typename Ptr, typename FuncStart, typename FuncEnd>
    void writeStandardBranches(Ptr ptr, FuncStart funcStart, FuncEnd funcEnd)
    {
        writeStandardBranches(reinterpret_cast<void*>(ptr),
                              reinterpret_cast<void*>(funcStart),
                              reinterpret_cast<void*>(funcEnd));
    }

    template<typename Func, typename Dest>
    Func hookFunction(Func function, Dest destination, bool absoluteBranch)
    {
        uint32_t* instructions = reinterpret_cast<uint32_t*>(function);
        uint32_t instructionCount;
        uint32_t* trampoline;

        if (absoluteBranch)
        {
            instructionCount = 5;
            trampoline = new (sizeof(uint32_t)) uint32_t[instructionCount];
        }
        else
        {
            instructionCount = 2;
#ifdef PLATFORM_WII
            trampoline = new (sizeof(uint32_t), HEAP_ZELDA) uint32_t[instructionCount];
#else
            trampoline = new (sizeof(uint32_t)) uint32_t[instructionCount];
#endif
        }

        // Original instruction
        trampoline[0] = instructions[0];
        memory::clear_DC_IC_Cache(&trampoline[0], sizeof(uint32_t));

        // Write actual hook
        writeBranch(&instructions[0], reinterpret_cast<void*>(static_cast<Func>(destination)));

        // Branch to original function past hook
        if (absoluteBranch)
        {
            writeAbsoluteBranch(&trampoline[1], &instructions[1]);
        }
        else
        {
            writeBranch(&trampoline[1], &instructions[1]);
        }

        return reinterpret_cast<Func>(trampoline);
    }

    template<typename Func, typename Dest>
    Func hookFunction(Func function, Dest destination)
    {
        return hookFunction(function, destination, false);
    }

    template<typename Func, typename Dest>
    Func hookFunctionAbsolute(Func function, Dest destination)
    {
        return hookFunction(function, destination, true);
    }

    template<typename Func>
    Func unhookFunction(Func trampoline)
    {
        if (!trampoline)
        {
            return nullptr;
        }

        uint32_t* instructions = reinterpret_cast<uint32_t*>(trampoline);
        uint32_t instructionCount;
        uint32_t* address;

        // Restore the original instruction
        uint32_t firstInstruction = instructions[1];
        if ((firstInstruction >> 16) == 0x3D80) // lis r12
        {
            // Absolute branch
            instructionCount = 5;
            uint32_t instructionAddress = (firstInstruction & 0xFFFF) << 16; // Upper 16 bits
            instructionAddress |= (instructions[2] & 0xFFFF);                // Lower 16 bits
            address = reinterpret_cast<uint32_t*>(instructionAddress - 0x4);
        }
        else
        {
            // Standard branch
            instructionCount = 2;
            int32_t branchLength = firstInstruction & 0x03FFFFFC;

            // Check if this is a negative branch
            if (branchLength > 0x01FFFFFC)
            {
                const int32_t Width = 26;
                const int32_t Mask = (1 << (Width - 1));
                branchLength = (branchLength ^ Mask) - Mask - 0x4;
            }

            uint32_t instructionAddress = reinterpret_cast<uint32_t>(&instructions[1]);
            address = reinterpret_cast<uint32_t*>(instructionAddress + branchLength);
        }

        *address = instructions[0];

        // Clear the cache for both the address and where the instructions were stored
        memory::clear_DC_IC_Cache(address, sizeof(uint32_t));
        memory::clear_DC_IC_Cache(instructions, sizeof(uint32_t) * instructionCount);

        // Free the memory used by the trampoline
        delete[] instructions;
        return nullptr;
    }
} // namespace libtp::patch
#endif