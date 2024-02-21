/**	@file m_re_controller_pad.h
 *	@brief Holds symbols related to the revolution (Wii) controller
 *
 *	@author kipcode66
 *	@bug No known bugs.
 */
#ifndef TP_M_RE_CONTROLLER_PAD_H
#define TP_M_RE_CONTROLLER_PAD_H

#include <dolphin/mtx/vec.h>

#include <cstdint>

struct Vec2
{
    float x, y;
};
static_assert(sizeof(Vec2) == 0x8);

namespace libtp::tp::m_re_controller_pad
{
    /**
     *  @brief Controller inputs
     */
    enum PadControllers
    {
        PAD_1 = 0,
        PAD_2,
        PAD_3,
        PAD_4
    };

    /**
     *  @brief Controller inputs
     */
    enum ReCPadInputs : uint32_t
    {
        Button_DPad_Left = 0x0001,
        Button_DPad_Right = 0x0002,
        Button_DPad_Down = 0x0004,
        Button_DPad_Up = 0x0008,
        Button_Plus = 0x0010,
        Button_Two = 0x0100,
        Button_One = 0x0200,
        Button_B = 0x0400,
        Button_A = 0x0800,
        Button_Minus = 0x1000,
        Button_Z = 0x2000,
        Button_C = 0x4000,
        Button_Home = 0x8000,
    };

    struct Pointer
    {
        Vec2 pos;          // 8044BB84
        uint8_t _p1[0x20]; // 8044BB8C
        float scr_dist;    // 8044BBAC // Relative distance of the remote to the sensor bar
    };
    static_assert(sizeof(Pointer) == 0x2C);

    struct ReCPad
    {
        uint32_t _unk1;             // 8044BB60
        uint32_t mButtonFlags;      // 8044BB64
        uint32_t mPressedButtonFlags; // 8044BB68
        uint32_t mRelease;          // 8044BB6C
        Vec wiimote_acc;            // 8044BB70
        float wiimote_acc_strength; // 8044BB7C
        float wiimote_shake;        // 8044BB80 // Unsure of the real meaning of this, needs more verification
        Pointer pointer;            // 8044BB84
        float _f1;                  // 8044BBB0
        float _f2;                  // 8044BBB4
        float horizontal;           // 8044BBB8 // Goes from 0.0 to 1.0, shows how much the remote is horizontal
        float vertical;    // 8044BBBC // Goes from -1.0 to 1.0, shows how much the remote is vertical (up is 1.0, down is -1.0)
        uint32_t ext_type; // 8044BBC0
        Vec2 stick;        // 8044BBC4
        Vec nunchuck_acc;  // 8044BBCC
        float nunchuck_acc_strength; // 8044BBD8
        float nunchuck_shake;        // 8044BBDC // Unsure of the real meaning of this, needs more verification
        float _f3;                   // 8044BBE0
        float _f4;                   // 8044BBE4
        uint8_t n_points;            // 8044BBE8 // Number of IR points seen by the remote
        uint8_t _p6[0x1CE7];         // 8044BBE9
        float stick_amplitude;       // 8044D8D0
        uint8_t _p7[0x94];         // 8044D8D4
    };
    static_assert(sizeof(ReCPad) == 0x1e08);

    extern "C"
    {
        namespace mReCPd
        {
            extern ReCPad m_pad[4];
        }
    }
} // namespace libtp::tp::m_re_controller_pad
#endif