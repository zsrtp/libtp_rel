/**	@file Z2SceneMgr.h
 *	@brief Provides a funciton definition for the sceneChange function
 *
 *  @author jdflyer
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef Z2AUDIOLIB_Z2SCENEMGR_H
#define Z2AUDIOLIB_Z2SCENEMGR_H

#include <cstdint>

#include "gc_wii/bmgres.h"

namespace libtp::z2audiolib::z2scenemgr
{
    /**
     *@todo Move JAISoundID to its own file
     */
    struct JAISoundID
    {
        uint32_t id;
    };

    struct Z2SceneMgr
    {
        /* 0x00 */ uint32_t BGM_ID;
        /* 0x04 */ int32_t sceneNum;
        /* 0x08 */ int32_t timer;
        /* 0x0C */ int8_t roomNum;
        /* 0x0D */ uint8_t SeWave_1;
        /* 0x0E */ uint8_t SeWaveToErase_1;
        /* 0x0F */ uint8_t SeWave_2;
        /* 0x10 */ uint8_t SeWaveToErase_2;
        /* 0x11 */ uint8_t BgmWave_1;
        /* 0x12 */ uint8_t BgmWaveToErase_1;
        /* 0x13 */ uint8_t BgmWave_2;
        /* 0x14 */ uint8_t BgmWaveToErase_2;
        /* 0x15 */ uint8_t SeWave_3;
        /* 0x16 */ uint8_t SeWaveToErase_3;
        /* 0x17 */ uint8_t field_0x17;
        /* 0x18 */ uint8_t field_0x18;
        /* 0x19 */ uint8_t field_0x19;
        /* 0x1A */ uint8_t field_0x1a;
        /* 0x1B */ uint8_t field_0x1b;
        /* 0x1C */ bool inGame;
        /* 0x1D */ bool sceneExist;
        /* 0x1E */ bool inDarkness;
        /* 0x1F */ uint8_t padding;
    } __attribute__( ( __packed__ ) );

    static_assert( sizeof( Z2SceneMgr ) == 0x20 );

    extern "C"
    {
        /**
         * @brief sceneChange is called when the game changes the BGM playing
         */
        void sceneChange( Z2SceneMgr* sceneMgr,
                          JAISoundID id,
                          uint8_t SeWave1,
                          uint8_t SeWave2,
                          uint8_t BgmWave1,
                          uint8_t BgmWave2,
                          uint8_t DemoWave,
                          bool param_7 );
        void loadSeWave( void* Z2SceneMgr, uint32_t waveID );
        void eraseSeWave( void* Z2SceneMgr, uint32_t waveID );
        void setSceneName( const char* stageName, int32_t roomNum, int32_t layerNo );
    };
}     // namespace libtp::z2audiolib::z2scenemgr
#endif