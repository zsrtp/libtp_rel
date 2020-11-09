/**	@file stages.h
 *  @brief Constants and definitions to work with stages
 *
 *	@author AECX
 *	@bug No known bugs.
 */

#pragma once

#ifndef _LIBTP_STAGE_CONSTANTS
#define _LIBTP_STAGE_CONSTANTS

namespace libtp::data::stage
{
    // Stage strings (ids)
    const char allStages[78][8] = {
        "D_MN01",  "D_MN01A", "D_MN01B", "D_MN04",  "D_MN04A", "D_MN04B", "D_MN05",  "D_MN05A", "D_MN05B", "D_MN06",
        "D_MN06A", "D_MN06B", "D_MN07",  "D_MN07A", "D_MN07B", "D_MN08",  "D_MN08A", "D_MN08B", "D_MN08C", "D_MN08D",
        "D_MN09",  "D_MN09A", "D_MN09B", "D_MN09C", "D_MN10",  "D_MN10A", "D_MN10B", "D_MN11",  "D_MN11A", "D_MN11B",
        "D_SB00",  "D_SB01",  "D_SB02",  "D_SB03",  "D_SB04",  "D_SB05",  "D_SB06",  "D_SB07",  "D_SB08",  "D_SB09",
        "D_SB10",  "F_SP00",  "F_SP102", "F_SP103", "F_SP104", "F_SP108", "F_SP109", "F_SP110", "F_SP111", "F_SP112",
        "F_SP113", "F_SP114", "F_SP115", "F_SP116", "F_SP117", "F_SP118", "F_SP121", "F_SP122", "F_SP123", "F_SP124",
        "F_SP125", "F_SP126", "F_SP127", "F_SP128", "F_SP200", "R_SP01",  "R_SP107", "R_SP108", "R_SP109", "R_SP110",
        "R_SP116", "R_SP127", "R_SP128", "R_SP160", "R_SP161", "R_SP209", "R_SP300", "R_SP301"};

    // Human readable stage translations
    const char* stageDescs[78] = {"Lakebed Temple",
                                  "Morpheel",
                                  "Deku Toad",
                                  "Goron Mines",
                                  "Fyrus",
                                  "Dangoro",
                                  "Forest Temple",
                                  "Diababa",
                                  "Ook",
                                  "Temple of Time",
                                  "Armogohma",
                                  "Darknut",
                                  "City in the Sky",
                                  "Argorok",
                                  "Aeralfos",
                                  "Palace of Twilight",
                                  "Zant Main Room",
                                  "Phantom Zant 1",
                                  "Phantom Zant 2",
                                  "Zant Fight",
                                  "Hyrule Castle",
                                  "Ganondorf Castle",
                                  "Ganondorf Field",
                                  "Ganondorf Defeated",
                                  "Arbiters Grounds",
                                  "Stallord",
                                  "Death Sword",
                                  "Snowpeak Ruins",
                                  "Blizzeta",
                                  "Darkhammer",
                                  "Lanayru Ice Puzzle Cave",
                                  "Cave of Ordeals",
                                  "Eldin Long Cave",
                                  "Lake Hylia Long Cave",
                                  "Eldin Goron Stockcave",
                                  "Grotto 1",
                                  "Grotto 2",
                                  "Grotto 3",
                                  "Grotto 4",
                                  "Grotto 5",
                                  "Faron Woods Cave",
                                  "Ordon Ranch",
                                  "Title Screen",
                                  "Ordon Village",
                                  "Ordon Spring",
                                  "Faron Woods",
                                  "Kakariko Village",
                                  "Death Mountain",
                                  "Kakariko Graveyard",
                                  "Zoras River",
                                  "Zoras Domain",
                                  "Snowpeak",
                                  "Lake Hylia",
                                  "Castle Town",
                                  "Sacred Grove",
                                  "Bublin Camp",
                                  "Hyrule Field",
                                  "Outside Castle Town",
                                  "Bublin 2",
                                  "Gerudo Desert",
                                  "Mirror Chamber",
                                  "Upper Zoras River",
                                  "Fishing Pond",
                                  "Hidden Village",
                                  "Hidden Skill",
                                  "Ordon Village",
                                  "Hyrule Castle Sewers",
                                  "Faron Woods",
                                  "Kakariko Village",
                                  "Death Mountain",
                                  "Telmas Bar",
                                  "Fishing Pond",
                                  "Hidden Village",
                                  "Castle Town",
                                  "Star Game",
                                  "Kakariko Graveyard",
                                  "Light Arrows Cutscene",
                                  "Hyrule Castle Cutscenes"};
}  // namespace libtp::data::stage
#endif