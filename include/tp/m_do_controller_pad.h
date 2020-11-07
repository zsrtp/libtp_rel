/**	@file m_do_controller_pad.h
 *	@brief Holds symbols related to the controller
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once
#include <cstdint>

namespace libtp::tp::m_do_controller_pad
{
    /**
     *  @brief Controller inputs
     */
    enum PadInputs : uint32_t
    {
        Button_DPad_Left = 0x00000001,
        Button_DPad_Right = 0x00000002,
        Button_DPad_Down = 0x00000004,
        Button_DPad_Up = 0x00000008,
        Button_Z = 0x00000010,
        Button_R = 0x00000020,
        Button_L = 0x00000040,
        Button_A = 0x00000100,
        Button_B = 0x00000200,
        Button_X = 0x00000400,
        Button_Y = 0x00000800,
        Button_Start = 0x00001000,
        Stick_C_Left = 0x00010000,
        Stick_C_Right = 0x00020000,
        Stick_C_Down = 0x00040000,
        Stick_C_Up = 0x00080000,
        Stick_Left = 0x01000000,
        Stick_Right = 0x02000000,
        Stick_Down = 0x04000000,
        Stick_Up = 0x08000000
    };

    /**
     *	@todo Fill missing vars.
     */
    struct CPadInfo
    {
        uint8_t unk_0[0x30];
        uint32_t buttonInput;
        uint32_t buttonInputTrg;
        uint8_t unk_38[0xC8];
    } __attribute__((__packed__));

    static_assert(sizeof(CPadInfo) == 0x100);

    extern "C"
    {
        extern CPadInfo cpadInfo;
    }
}  // namespace libtp::tp::m_do_controller_pad