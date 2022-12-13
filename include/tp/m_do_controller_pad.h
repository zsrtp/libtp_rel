/**	@file m_do_controller_pad.h
 *	@brief Holds symbols related to the controller
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef TP_M_DO_CONTROLLER_PAD_H
#define TP_M_DO_CONTROLLER_PAD_H

#include <cstdint>

namespace libtp::tp::m_do_controller_pad
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
     *	@todo Properly set up mDoCPd_c class, c_API_controller_pad header, and other headers
     */
    struct CPadInfo
    {
        /* 0x00 */ float mMainStickPosX;
        /* 0x04 */ float mMainStickPosY;
        /* 0x08 */ float mMainStickValue;
        /* 0x0C */ int16_t mMainStickAngle;
        /* 0x0E */ uint8_t field_0xe;
        /* 0x0F */ uint8_t field_0xf;
        /* 0x10 */ float mCStickPosX;
        /* 0x14 */ float mCStickPosY;
        /* 0x18 */ float mCStickValue;
        /* 0x1C */ int16_t mCStickAngle;
        /* 0x1E */ uint8_t field_0x1e;
        /* 0x1F */ uint8_t field_0x1f;
        /* 0x20 */ float mAnalogA;
        /* 0x24 */ float mAnalogB;
        /* 0x28 */ float mTriggerLeft;
        /* 0x2C */ float mTriggerRight;
        /* 0x30 */ uint32_t mButtonFlags;
        /* 0x34 */ uint32_t mPressedButtonFlags;
        /* 0x38 */ uint8_t mGamepadErrorFlags;
        /* 0x39 */ uint8_t mHoldLockL;
        /* 0x3A */ uint8_t mTrigLockL;
        /* 0x3B */ uint8_t mHoldLockR;
        /* 0x3C */ uint8_t mTrigLockR;
        /* 0x3D */ uint8_t field_0x3d;
        /* 0x3E */ uint8_t field_0x3e;
        /* 0x3F */ uint8_t field_0x3f;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( CPadInfo ) == 0x40 );

    extern "C"
    {
        extern CPadInfo cpadInfo[4];     // One for each controller port
    }
}     // namespace libtp::tp::m_do_controller_pad
#endif