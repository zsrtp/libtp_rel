/**	@file d_event.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::d_event
{
    struct dEvt_order
    {
        /*  0x00 */ uint16_t mEventType;
        /*  0x02 */ uint16_t mFlag;
        /*  0x04 */ int32_t field_0x04;
        /*  0x08 */ void* mActor1; // fopAc_ac_c* mActor1;
        /*  0x0C */ void* mActor2; // fopAc_ac_c* mActor2;
        /*  0x10 */ int16_t mEventId;
        /*  0x12 */ int16_t mPriority;
        /*  0x14 */ uint8_t mNextOrderIdx;
        /*  0x15 */ uint8_t mEventInfoIdx;
        /*  0x16 */ uint8_t padding_0x16[2];
    } __attribute__((__packed__));

    struct dEvt_control
    {
       public:
        /* 0x000 */ uint8_t field_0x0[4];
        /* 0x004 */ dEvt_order mOrder[8];
        /* 0x0C4 */ uint32_t mPt1;
        /* 0x0C8 */ uint32_t mPt2;
        /* 0x0CC */ uint32_t mPtT;
        /* 0x0D0 */ uint32_t mPtI;
        /* 0x0D4 */ uint32_t mPtd;
        /* 0x0D8 */ uint16_t mEventFlag;
        /* 0x0DA */ uint16_t mFlag2;
        /* 0x0DC */ uint16_t mHindFlag;
        /* 0x0DE */ int16_t mSpecifiedEvent; // name maybe wrong
        /* 0x0E0 */ int16_t field_0xe0;
        /* 0x0E2 */ uint8_t mNum;
        /* 0x0E3 */ uint8_t field_0xe3;
        /* 0x0E4 */ uint8_t mMode;
        /* 0x0E5 */ uint8_t field_0xe5;
        /* 0x0E6 */ uint8_t field_0xe6;
        /* 0x0E7 */ uint8_t field_0xe7;
        /* 0x0E8 */ uint8_t field_0xe8;
        /* 0x0E9 */ uint8_t mDebugStb;
        /* 0x0EA */ uint8_t field_0xea;
        /* 0x0EB */ uint8_t mMapToolId;
        /* 0x0EC */ uint8_t field_0xec;
        /* 0x0ED */ uint8_t field_0xed;
        /* 0x0EE */ uint8_t mPreItemNo;
        /* 0x0EF */ uint8_t mGtItm;
        /* 0x0F0 */ float mCullRate;
        /* 0x0F4 */ void* mStageEventDt;
        /* 0x0F8 */ void* mChangeOK;
        /* 0x0FC */ uint8_t field_0xfc[4];
        /* 0x100 */ uint8_t field_0x100[4]; // SkipFunc mSkipFunc;
        /* 0x104 */ uint32_t field_0x104;
        /* 0x108 */ uint32_t field_0x108;
        /* 0x10C */ uint32_t field_0x10c;
        /* 0x110 */ int32_t mSkipFade;
        /* 0x114 */ char mSkipEventName[20];
        /* 0x128 */ uint8_t mCompulsory;
        /* 0x129 */ bool field_0x129;
        /* 0x12A */ uint16_t padding;
        /* 0x12C */ int32_t field_0x12c;
    } __attribute__((__packed__)); // Size = 0x130

    extern "C"
    {
        /**
         *  @brief Ends the current conversation with a NPC.
         *
         *  @param eventPtr A pointer to the current event system.
         */
        void talkEnd(void* eventPtr);

        /**
         *  @brief Sets the item to be obtained in the upcoming event.
         *
         *  @param eventPtr A pointer to the current event system.
         *  @param itemID The ID of the item to be given.
         */
        void setGtItm(void* eventPtr, uint8_t itemID);

        /**
         *  @brief Skips the current cutscene if it can be skipped
         *
         *  @param eventPtr A pointer to the current event system.
         *
         *  @return Bool returns True if the action was successful, otherwise returns False.
         */
        bool skipper(void* eventPtr);
    }
} // namespace libtp::tp::d_event