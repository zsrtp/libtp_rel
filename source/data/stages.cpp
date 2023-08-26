#include "data/stages.h"

#include <cstdint>

// AreaIDs used by the game, excluding 0xFF (title screen, KB temp map, ...)
const uint8_t regions[24] = {0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x10,
                             0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1E};

// RegionID per stage, offset into regions[]
const uint8_t regionID[78] {
    0x12, // 0
    0x12, // 1
    0x12, // 2
    0x11, // 3
    0x11, // 4
    0x11, // 5
    0x10, // 6
    0x10, // 7
    0x10, // 8
    0x15, // 9
    0x15, // 10
    0x15, // 11
    0x16, // 12
    0x16, // 13
    0x16, // 14
    0x17, // 15
    0x17, // 16
    0x17, // 17
    0x17, // 18
    0x17, // 19
    0x18, // 20
    0x18, // 21
    0x18, // 22
    0x18, // 23
    0x13, // 24
    0x13, // 25
    0x13, // 26
    0x14, // 27
    0x14, // 28
    0x14, // 29
    0x19, // 30
    0x19, // 31
    0x19, // 32
    0x1A, // 33
    0x1A, // 34
    0x1B, // 35
    0x1B, // 36
    0x1B, // 37
    0x1B, // 38
    0x1B, // 39
    0x02, // 40
    0x00, // 41
    0xFF, // 42
    0x00, // 43
    0x00, // 44
    0x02, // 45
    0x03, // 46
    0x03, // 47
    0x03, // 48
    0x04, // 49
    0x04, // 50
    0x08, // 51
    0x04, // 52
    0x09, // 53
    0x07, // 54
    0x0A, // 55
    0x05, // 56
    0x06, // 57
    0xFF, // 58
    0x0A, // 59
    0x0A, // 60
    0x04, // 61
    0x0B, // 62
    0x03, // 63
    0x06, // 64
    0x00, // 65
    0x01, // 66
    0x02, // 67
    0x03, // 68
    0x03, // 69
    0x09, // 70
    0x0B, // 71
    0x03, // 72
    0x09, // 73
    0x09, // 74
    0x03, // 75
    0xFF, // 76
    0xFF  // 77
};

// Stage strings (ids)
const char allStages[78][8] = {
    "D_MN01",  // 0
    "D_MN01A", // 1
    "D_MN01B", // 2
    "D_MN04",  // 3
    "D_MN04A", // 4
    "D_MN04B", // 5
    "D_MN05",  // 6
    "D_MN05A", // 7
    "D_MN05B", // 8
    "D_MN06",  // 9
    "D_MN06A", // 10
    "D_MN06B", // 11
    "D_MN07",  // 12
    "D_MN07A", // 13
    "D_MN07B", // 14
    "D_MN08",  // 15
    "D_MN08A", // 16
    "D_MN08B", // 17
    "D_MN08C", // 18
    "D_MN08D", // 19
    "D_MN09",  // 20
    "D_MN09A", // 21
    "D_MN09B", // 22
    "D_MN09C", // 23
    "D_MN10",  // 24
    "D_MN10A", // 25
    "D_MN10B", // 26
    "D_MN11",  // 27
    "D_MN11A", // 28
    "D_MN11B", // 29
    "D_SB00",  // 30
    "D_SB01",  // 31
    "D_SB02",  // 32
    "D_SB03",  // 33
    "D_SB04",  // 34
    "D_SB05",  // 35
    "D_SB06",  // 36
    "D_SB07",  // 37
    "D_SB08",  // 38
    "D_SB09",  // 39
    "D_SB10",  // 40
    "F_SP00",  // 41
    "F_SP102", // 42
    "F_SP103", // 43
    "F_SP104", // 44
    "F_SP108", // 45
    "F_SP109", // 46
    "F_SP110", // 47
    "F_SP111", // 48
    "F_SP112", // 49
    "F_SP113", // 50
    "F_SP114", // 51
    "F_SP115", // 52
    "F_SP116", // 53
    "F_SP117", // 54
    "F_SP118", // 55
    "F_SP121", // 56
    "F_SP122", // 57
    "F_SP123", // 58
    "F_SP124", // 59
    "F_SP125", // 60
    "F_SP126", // 61
    "F_SP127", // 62
    "F_SP128", // 63
    "F_SP200", // 64
    "R_SP01",  // 65
    "R_SP107", // 66
    "R_SP108", // 67
    "R_SP109", // 68
    "R_SP110", // 69
    "R_SP116", // 70
    "R_SP127", // 71
    "R_SP128", // 72
    "R_SP160", // 73
    "R_SP161", // 74
    "R_SP209", // 75
    "R_SP300", // 76
    "R_SP301"  // 77
};

// Human readable stage translations
/* const char* stageDescs[78] = { "Lakebed Temple",
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
                               "Bulblin Camp",
                               "Hyrule Field",
                               "Outside Castle Town",
                               "Bulblin 2",
                               "Gerudo Desert",
                               "Mirror Chamber",
                               "Upper Zoras River",
                               "Fishing Pond",
                               "Hidden Village",
                               "Hidden Skill",
                               "Ordon Village Interiors",
                               "Hyrule Castle Sewers",
                               "Faron Woods Interiors",
                               "Kakariko Village Interiors",
                               "Death Mountain Interiors",
                               "Castle Town Interiors",
                               "Fishing Pond Interiors",
                               "Hidden Village Interiors",
                               "Castle Town Shops",
                               "Star Game",
                               "Kakariko Graveyard Interiors",
                               "Light Arrows Cutscene",
                               "Hyrule Castle Cutscenes" };
*/
