/**	@file d_gameover.h
 *	@brief Holds data and definitions related to the Game Over part of the game.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_GAMEOVER_H
#define TP_D_GAMEOVER_H

#include <cstdint>

namespace libtp::tp::d_gameover
{
    struct dGameOver
    {
        /* 0x00*/ uint8_t msg_class[0xFC]; // msg_class
        /* 0x0FC */ void* dMs_c;           // dMenu_save_c*
        /* 0x100 */ void* dgo_screen_c;    // dDlst_GameOverScrnDraw_c*
        /* 0x104 */ void* dgo_capture_c;   // dDlst_Gameover_CAPTURE_c*
        /* 0x108 */ uint8_t mPhase[0x8];   // request_of_phase_process_class
        /* 0x110 */ void* mpHeap;          // JKRHeap*
        /* 0x114 */ int16_t mTimer;
        /* 0x116 */ int16_t field_0x116;
        /* 0x118 */ uint8_t mProc;
        /* 0x119 */ bool mIsDemoSave;
    } __attribute__((__packed__));

    extern "C"
    {
        /**
         *	@brief Sets the timer and animation values that determine how long the Game Over sequence takes.
         *
         *  @param ptr The pointer to the dGameOver struct.
         */
        void dispWait_init(dGameOver* ptr);
    }
} // namespace libtp::tp::d_gameover
#endif