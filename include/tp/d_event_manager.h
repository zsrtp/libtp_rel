/**	@file d_event_manager.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::d_event_manager
{
    struct dEvent_manager
    {
        /* 0x0000 */ uint8_t field_0x0[0x18C]; // dEvDtBase_c mEventList[11];
        /* 0x018C */ int32_t mCameraPlay;
        /* 0x0190 */ uint8_t field_0x190[0xC]; // dEvent_exception_c mEventException;
        /* 0x019C */ uint8_t field_0x19c[0xC]; // cXyz mGoal;
        /* 0x01A8 */ uint8_t field_0x1a8[2];
        /* 0x01AA */ uint16_t field_0x1aa;
        /* 0x01AC */ uint8_t field_0x1ac[4];
        /* 0x01B0 */ uint32_t mRoomNo;
        /* 0x01B4 */ uint32_t field_0x1b4;
        /* 0x01B8 */ uint32_t field_0x1b8;
        /* 0x01BC */ uint8_t field_0x1bc[0x500]; // dEvDtFlag_c mFlags;
        /* 0x06BC */ bool mDataLoaded;
        /* 0x06BD */ uint8_t padding[0x3];
    } __attribute__((__packed__));

    extern "C"
    {
        /**
         *	@brief Gets the index of the specified event in the current event flow.
         *
         *	@param eventManager A pointer to the event manager
         *  @param actrPtr The actor that is managing the specified event
         *  @param eventID A pointer to the current event name
         *  @param mapToolId The ID number of the current map tool being used
         *
         *  @returns The index of the specified event based on the actor and event being referenced.
         */
        int16_t getEventIdx(dEvent_manager* eventManger,
                            libtp::tp::f_op_actor::fopAc_ac_c* actrPtr,
                            const char* eventID,
                            uint8_t mapToolId);
    }
} // namespace libtp::tp::d_event_manager