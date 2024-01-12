/**
 * @file Z2SeqMgr.h
 * @author jdflyer
 * @brief Provides the definition for the funciton that starts the enemy BGM
 *
 * @bug No known bugs
 */
#ifndef TP_Z2SEQMGR_H
#define TP_Z2SEQMGR_H

#include <cstdint>

namespace libtp::z2audiolib::z2seqmgr
{
    struct Z2SeqMgr;

    extern "C"
    {
        void startBattleBgm(Z2SeqMgr* seqMgr, bool param_1);

        /**
         *	@brief Checks to see whether the currently playing bgm is the specified one
         *
         *  @param seqMgr The pointer to the current z2seqmgr
         *  @param sfx_id The sound effect id to be checked
         */
        bool checkBgmIDPlaying(Z2SeqMgr* seqMgr, uint32_t sfx_id);
    }
} // namespace libtp::z2audiolib::z2seqmgr

#endif