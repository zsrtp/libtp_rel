/**	@file d_a_obj_Lv5Key.h
 *	@brief Snowpeak Ruins Small Key Lock object definition
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_D_A_OBJ_LV5KEY_H
#define TP_D_A_OBJ_LV5KEY_H

#include <cstdint>

#include "tp/f_op_actor.h"

// Lv5 refers to Snowpeak Ruins. It is called Key because the Japanese word
// "kagi" is generally used for both key and lock.

// There is a softlock that happens when you open a lock from the opposite side
// of the door for 3 of the 4 small key doors in Snowpeak Ruins. This happens
// because the lock never changes from the Fall animation to the Land animation
// because it doesn't collide with the ground. The Land animation is what
// handles communicating that Link can open the door. For more information, see
// https://icogn.github.io/tp-docs/docs/technical-explanations/sprlocksoftlock.

namespace libtp::tp::rel::d_a_obj_Lv5Key
{
    class daObjLv5Key_c: public libtp::tp::f_op_actor::fopAc_ac_c
    {
        uint8_t unk_568[0x3DC];

        // 0x56C Z2SoundObjSimple*
        // 0x594 J3DFrameCtrl* - used with Open animation
        //   offset 0x5 (abs 0x599) u8 - bit 0 set indicates animation finished
        // 0x5B8 dBgS_AcchCir*
        // 0x5F8 dBgS_Acch* - does Ground/Wall/Roof checks
        //   offset 0x14 (abs 0x60C) dBgS_PolyPassChk*
        //   offset 0x2C (abs 0x624) - bit 26 set indicates collided with ground
        // 0x7EC dCcD_GStts*

        // Byte which allows for communication between the door and the lock.
        // Normally, the byte sits at 0. When Link tries to open the door without a
        // key the byte is set to 1. On the next Wait call, the lock will change to
        // Shake. When Shake finishes the byte is set back to 0. If Link has a key
        // to open the door, the byte will instead be set to 2, and the next Wait
        // call will cause the lock to change to Open. Open will change to Fall, and
        // Fall will change to Land. When the Land animation ends, it changes the
        // byte to 3. When the external thing changed the byte from 0 to 2, it began
        // checking every frame for when the byte changes to 3, and once it does
        // Link opens the door. Softlock happens when this byte never changes to 3.
        uint8_t unk_945;          // 0x945 - padding?
        uint8_t status;           // 0x945
        uint8_t unk_946[0x2];     // 0x946 - padding?
        // ptmf properties used alongside activeAnimFuncPtr.
        // Used by Runtime.PPCEABI.H ptmf functions.
        uint32_t ptmf0;     // 0x948 - usually 0x00000000
        uint32_t ptmf1;     // 0x94C - usually 0xFFFFFFFF
        // Determines which function runs during Execute each frame.
        // Points to Wait, Open, etc.
        uint32_t activeAnimFuncPtr;     // 0x950
        // animationPhase varies between -1, 0, 1, and 2. Valid values are specific
        // to each animation.
        uint16_t animationPhase;     // 0x954
        // Shake phase 1 runs for 30 frames before phase 2 which is the shaking.
        uint16_t shakePhase1Timer;     // 0x956
        // Used in matrix calculations to translate lock during Land animation.
        // x value in matrix calc? Land phase 0 initializes to -17.4
        float f_958;     // 0x958
        // y value in matrix calc? Land phase 0 initializes to -74.7
        float f_95c;     // 0x95C
        // z value in matrix calc? Land phase 0 initializes to 8.7
        float f_960;     // 0x960
        // Rotational speeds control how much the lock's rotations change each
        // frame. Only certain animations use these.
        uint16_t xRotateSpd;     // 0x964
        uint16_t yRotateSpd;     // 0x966
        uint16_t zRotateSpd;     // 0x968
        // Rotational accelerations control how much the lock's rotational
        // speeds change each frame. Only certain animations use these.
        uint16_t xRotateAccel;     // 0x96A
        uint16_t yRotateAccel;     // 0x96C
        uint16_t zRotateAccel;     // 0x96E
        // Used by shake phase 2. Number of shakes remaining.
        uint8_t shakeNum;         // 0x970
        uint8_t unk_971[0xB];     // padding?
    } __attribute__( ( __packed__ ) );

    // Size to allocate generated at runtime by adding two inner offsets:
    // offset 0x11A4 of REL: {
    //   offset 0x10 (abs 0x11B4) which is 0x97C +
    //   offset 0x14 (abs 0x11B8) which is 0
    // }
    static_assert( sizeof( daObjLv5Key_c ) == 0x97C );
}     // namespace libtp::tp::rel::d_a_obj_Lv5Key

#endif