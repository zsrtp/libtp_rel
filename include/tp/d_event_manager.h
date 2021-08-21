/**	@file d_event_manager.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>
#include "c_xyz.h"

namespace libtp::tp::d_event_manager
{
    struct dEvent_manager
    {
        /* 0x0000 */ uint8_t field_0x0[0x18C]; //dEvDtBase_c mEventList[11];
        /* 0x018C */ int32_t  mCameraPlay;
        /* 0x0190 */ uint8_t field_0x190[0xC]; //dEvent_exception_c mEventException;
        /* 0x019C */ libtp::tp::c_xyz::cXyz mGoal;
        /* 0x01A8 */ uint8_t  field_0x1a8[2];
        /* 0x01AA */ uint16_t  field_0x1aa;
        /* 0x01AC */ uint8_t  field_0x1ac[4];
        /* 0x01B0 */ uint32_t  field_0x1b0;
        /* 0x01B4 */ uint32_t  field_0x1b4;
        /* 0x01B8 */ uint32_t  field_0x1b8;
        /* 0x01BC */ uint8_t field_0x1bc[0x500]; //dEvDtFlag_c mFlags;
        /* 0x06BC */ bool mDataLoaded;
    } __attribute__((__packed__));
}// namespace libtp::tp::d_event_manager