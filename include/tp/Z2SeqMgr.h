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

namespace libtp::tp::z2audiolib::z2seqmgr {
    struct Z2SeqMgr;

    extern "C" {
        void startBattleBgm(Z2SeqMgr* seqMgr, bool param_1);
    }
}   //  namespace libtp::tp::z2audiolib::z2seqmgr

#endif