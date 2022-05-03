/**
 * @file Z2SceneMgr.h
 * @author jdflyer
 * @brief Provides a funciton definition for the sceneChange function
 *
 * @bug No known bugs
 */

#ifndef TP_Z2SCENEMGR_H
#define TP_Z2SCENEMGR_H

#include <cstdint>

namespace libtp::tp::z2audiolib::z2scenemgr
{
    struct Z2SceneMgr;

    /**
     *@todo Move JAISoundID to its own file
     */
    struct JAISoundID
    {
        uint32_t id;
    };

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
    };
}     // namespace libtp::tp::z2audiolib::z2scenemgr

#endif