/** @file stages.h
 *  @brief Constants and definitions to work with stages
 *
 *  @author AECX
 *  @bug No known bugs.
 */
#ifndef LIBTP_STAGES_H
#define LIBTP_STAGES_H

#include <cstdint>

namespace libtp::data::stage
{
    // AreaIDs used by the game, excluding 0xFF (title screen, KB temp map, ...)
    const uint8_t regions[24] = { 0x00, 0x01, 0x02, 0x03, 0x04, 0x06, 0x07, 0x08, 0x09, 0x0A, 0x0B, 0x10,
                                  0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x1A, 0x1B, 0x1E };

    const uint8_t regionID[78] {
        0x12,     // 0
        0x12,     // 1
        0x12,     // 2
        0x11,     // 3
        0x11,     // 4
        0x11,     // 5
        0x10,     // 6
        0x10,     // 7
        0x10,     // 8
        0x15,     // 9
        0x15,     // 10
        0x15,     // 11
        0x16,     // 12
        0x16,     // 13
        0x16,     // 14
        0x17,     // 15
        0x17,     // 16
        0x17,     // 17
        0x17,     // 18
        0x17,     // 19
        0x18,     // 20
        0x18,     // 21
        0x18,     // 22
        0x18,     // 23
        0x13,     // 24
        0x13,     // 25
        0x13,     // 26
        0x14,     // 27
        0x14,     // 28
        0x14,     // 29
        0x19,     // 30
        0x19,     // 31
        0x19,     // 32
        0x1A,     // 33
        0x1A,     // 34
        0x1B,     // 35
        0x1B,     // 36
        0x1B,     // 37
        0x1B,     // 38
        0x1B,     // 39
        0x02,     // 40
        0x00,     // 41
        0xFF,     // 42
        0x00,     // 43
        0x00,     // 44
        0x02,     // 45
        0x03,     // 46
        0x03,     // 47
        0x03,     // 48
        0x04,     // 49
        0x04,     // 50
        0x08,     // 51
        0x04,     // 52
        0x09,     // 53
        0x07,     // 54
        0x0A,     // 55
        0x05,     // 56
        0x06,     // 57
        0xFF,     // 58
        0x0A,     // 59
        0x0A,     // 60
        0x04,     // 61
        0x0B,     // 62
        0x03,     // 63
        0x06,     // 64
        0x00,     // 65
        0x01,     // 66
        0x02,     // 67
        0x03,     // 68
        0x03,     // 69
        0x09,     // 70
        0x0B,     // 71
        0x03,     // 72
        0x09,     // 73
        0x09,     // 74
        0x03,     // 75
        0xFF,     // 76
        0xFF      // 77
    };

    // Stage strings (ids)
    const char allStages[78][8] = {
        "D_MN01",      // 0
        "D_MN01A",     // 1
        "D_MN01B",     // 2
        "D_MN04",      // 3
        "D_MN04A",     // 4
        "D_MN04B",     // 5
        "D_MN05",      // 6
        "D_MN05A",     // 7
        "D_MN05B",     // 8
        "D_MN06",      // 9
        "D_MN06A",     // 10
        "D_MN06B",     // 11
        "D_MN07",      // 12
        "D_MN07A",     // 13
        "D_MN07B",     // 14
        "D_MN08",      // 15
        "D_MN08A",     // 16
        "D_MN08B",     // 17
        "D_MN08C",     // 18
        "D_MN08D",     // 19
        "D_MN09",      // 20
        "D_MN09A",     // 21
        "D_MN09B",     // 22
        "D_MN09C",     // 23
        "D_MN10",      // 24
        "D_MN10A",     // 25
        "D_MN10B",     // 26
        "D_MN11",      // 27
        "D_MN11A",     // 28
        "D_MN11B",     // 29
        "D_SB00",      // 30
        "D_SB01",      // 31
        "D_SB02",      // 32
        "D_SB03",      // 33
        "D_SB04",      // 34
        "D_SB05",      // 35
        "D_SB06",      // 36
        "D_SB07",      // 37
        "D_SB08",      // 38
        "D_SB09",      // 39
        "D_SB10",      // 40
        "F_SP00",      // 41
        "F_SP102",     // 42
        "F_SP103",     // 43
        "F_SP104",     // 44
        "F_SP108",     // 45
        "F_SP109",     // 46
        "F_SP110",     // 47
        "F_SP111",     // 48
        "F_SP112",     // 49
        "F_SP113",     // 50
        "F_SP114",     // 51
        "F_SP115",     // 52
        "F_SP116",     // 53
        "F_SP117",     // 54
        "F_SP118",     // 55
        "F_SP121",     // 56
        "F_SP122",     // 57
        "F_SP123",     // 58
        "F_SP124",     // 59
        "F_SP125",     // 60
        "F_SP126",     // 61
        "F_SP127",     // 62
        "F_SP128",     // 63
        "F_SP200",     // 64
        "R_SP01",      // 65
        "R_SP107",     // 66
        "R_SP108",     // 67
        "R_SP109",     // 68
        "R_SP110",     // 69
        "R_SP116",     // 70
        "R_SP127",     // 71
        "R_SP128",     // 72
        "R_SP160",     // 73
        "R_SP161",     // 74
        "R_SP209",     // 75
        "R_SP300",     // 76
        "R_SP301"      // 77
    };

    // Human readable stage translations
    /*const char* stageDescs[78] = { "Lakebed Temple",
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
                                   "Hyrule Castle Cutscenes" };*/

    enum stageIDs : uint8_t
    { 
        Lakebed_Temple = 0x0,
        Morpheel = 0x1,
        Deku_Toad,
        Goron_Mines,
        Fyrus,
        Dangoro,
        Forest_Temple,
        Diababa,
        Ook,
        Temple_of_Time,
        Armogohma,
        Darknut,
        City_in_the_Sky,
        Argorok,
        Aeralfos,
        Palace_of_Twilight,
        Zant_Main_Room,
        Phantom_Zant_1,
        Phantom_Zant_2,
        Zant_Fight,
        Hyrule_Castle,
        Ganondorf_Castle,
        Ganondorf_Field,
        Ganondorf_Defeated,
        Arbiters_Grounds,
        Stallord,
        Death_Sword,
        Snowpeak_Ruins,
        Blizzeta,
        Darkhammer,
        Lanayru_Ice_Puzzle_Cave,
        Cave_of_Ordeals,
        Eldin_Long_Cave,
        Lake_Hylia_Long_Cave,
        Eldin_Goron_Stockcave,
        Grotto_1,
        Grotto_2,
        Grotto_3,
        Grotto_4,
        Grotto_5,
        Faron_Woods_Cave,
        Ordon_Ranch,
        Title_Screen,
        Ordon_Village,
        Ordon_Spring,
        Faron_Woods,
        Kakariko_Village,
        Death_Mountain,
        Kakariko_Graveyard,
        Zoras_River,
        Zoras_Domain,
        Snowpeak,
        Lake_Hylia,
        Castle_Town,
        Sacred_Grove,
        Bulblin_Camp,
        Hyrule_Field,
        Outside_Castle_Town,
        Bulblin_2,
        Gerudo_Desert,
        Mirror_Chamber,
        Upper_Zoras_River,
        Fishing_Pond,
        Hidden_Village,
        Hidden_Skill,
        Ordon_Village_Interiors,
        Hyrule_Castle_Sewers,
        Faron_Woods_Interiors,
        Kakariko_Village_Interiors,
        Death_Mountain_Interiors,
        Castle_Town_Interiors,
        Fishing_Pond_Interiors,
        Hidden_Village_Interiors,
        Castle_Town_Shops,
        Star_Game,
        Kakariko_Graveyard_Interiors,
        Light_Arrows_Cutscene,
        Hyrule_Castle_Cutscenes
    };

    enum snowpeakStateIDs : uint8_t
    { 
        SPR_Northwest_Door_Unlocked = 0x1,
        SPR_West_Door_Unlocked = 0x2,
        SPR_Dungeon_Completed = 0x3
    };

    enum faronStateIDs : uint8_t
    { 
        Talo_Captured = 0x1,
        Forest_Temple_Completed = 0x2,
        MDH_Completed = 0x5
    };

    enum kakarikoStateIDs : uint8_t
    { 
        KB1_Active = 0x1,
        KB1_Completed = 0x2,
        KB1_Completed_Night = 0x3,
        Goron_Mines_Completed = 0xC,
        Zora_Escort_Cleared = 0x4
    };

    enum kakarikoInteriorStateIDs : uint8_t
    { 
        KB1_Active = 0x1,
        KB1_Completed = 0x2,
        KB1_Completed_Night = 0x3,
        Lakebed_Completed = 0x4,
        Lakebed_Completed_Night = 0x5
    };

    enum deathMountainStateIDs : uint8_t
    { 
        Goron_Mines_Completed = 0x2
    };

    enum deathMountainInteriorStateIDs : uint8_t
    { 
        Goron_Mines_Completed = 0x1,
        Master_Sword_CS_Watched = 0x2,
        Ilia_Given_Charm = 0x3,
        Temple_of_Time_Completed = 0x4
    };

    enum lakeHyliaStateIDs : uint8_t
    { 
        Warped_Cannon_To_Lake = 0x1,
        Lakebed_Completed = 0x2,
        Cannon_Repaired = 0x3
    };

    enum lakeHyliaInteriorStateIDs : uint8_t
    { 
        MDH_Started = 0x2,
        Lakebed_Completed = 0x9
    };

    enum castleTownStateIDs : uint8_t
    { 
        West_MDH_Clear = 0x0,
        Finished_Zora_Escort = 0x1,
        Town_MDH_Clear = 0x1,
        Lakebed_Completed = 0x2
    };

    enum zorasDomainStateIDs : uint8_t
    { 
        Snowpeak_Ruins_Completed = 0x2
    };

    enum upperZorasRiverStateIDs : uint8_t
    { 
        Iza_1_Started = 0x1
    };

    enum gerudoDesertStateIDs : uint8_t
    { 
        Entrance_Cutscene_Watched = 0x0,
        Entrance_Cutscene_Not_Watched = 0x8
    };

    enum zorasRiverStateIDs : uint8_t
    { 
        Iza_1_Completed = 0x1,
        Iza_1_Started = 0x2
    };

    enum ordonVillageStateIDs : uint8_t
    { 
        Goats_1_Completed = 0x0,
        Link_House_Talo_Rescued = 0x0,
        Finished_Sewers = 0x1,
        Faron_Twilight_Cleared = 0x2,
        Faron_Twilight_Cleared_Night = 0x3,
        Link_House_New_Game = 0x3,
        Link_House_Goats_1_Completed = 0x4,
        Epona_Tamed = 0x4,
        Epona_Tamed_Night = 0x5,
        New_Game = 0x6,
        Talo_Rescued = 0x7
    };

    enum ordonInteriorsStateIDs : uint8_t
    { 
        Finished_Sewers = 0x1,
        Faron_Twilight_Cleared = 0x2,
        KB1_Completed = 0x3
    };

    enum ordonSpringStateIDs : uint8_t
    { 
        Talo_Rescued = 0x0,
        New_Game = 0x1,
        Faron_Twilight_Cleared = 0x2,
        Sword_Tutorial_Completed = 0x3,
        Finished_Sewers = 0x4
    };

    enum ordonRanchStateIDs : uint8_t
    { 
        Finished_Sewers = 0x1,
        Faron_Twilight_Cleared = 0x2,
        Faron_Twilight_Cleared_Night = 0x3,
        Talo_Rescued = 0x9,
        Goats_2_Completed = 0xA,
        Goats_1_Completed = 0xB,
        New_Game = 0xC
    };

    enum hyruleFieldStateIDs : uint8_t
    { 
        New_Game = 0x0,
        MDH_Started = 0x4,
        MDH_Completed = 0x6

    };

    enum outsideCastleTownStateIDs : uint8_t
    { 
        New_Game = 0x0,
        MDH_Completed_West = 0x0,
        Talked_To_Louise_Before_Statue = 0x1,
        MDH_Started = 0x4,
        MDH_Completed = 0x6,
        Got_Wooden_Statue_South = 0x6
    };

    enum hiddenVillageStateIDs : uint8_t
    { 
        New_Game = 0x0,
        Showed_Ilia_Charm = 0x1

    };

    enum castleTownInteriorsStateIDs : uint8_t
    { 
        New_Game = 0x0,
        Jovani_MDH_Completed = 0x0,
        Castle_Town_Malo_Mart = 0x1,
        Jovani_New_Game = 0x1

    };

    enum sacredGroveStateIDs : uint8_t
    { 
        Grove_2 = 0x2
    };

    enum bulblinCampStateIDs : uint8_t
    { 
        New_Game = 0x0,
        KB3_Completed = 0x1,
        Watched_Mirror_Cutscene = 0x3

    };

    enum faronWoodsCaveStateIDs : uint8_t
    { 
        New_Game = 0x0,
        Talo_Rescued = 0x1,
    };

    enum sewersStateIDs : uint8_t
    { 
        New_Game = 0x0,
        Midna_On_Back = 0xD

    };

    enum hyruleCastleStateIDs : uint8_t
    { 
        Exterior_State = 0x0,
        Interior_State = 0x1

    };

    enum fishingHoleStateIDs : uint8_t
    { 
        Fishing_Hole_Spring = 0x0,
        Fishing_Hole_Summer = 0x1,
        Fishing_Hole_Autumn = 0x2,
        Fishing_Hole_Winter = 0x3,

    };
}     // namespace libtp::data::stage
#endif