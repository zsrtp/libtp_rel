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
    enum class AreaNodesID : uint8_t
    {
        Ordon = 0,
        Sewers,
        Faron,
        Eldin,
        Lanayru,
        Unk_5,
        Hyrule_Field,
        Sacred_Grove,
        Snowpeak,
        Castle_Town,
        Gerudo_Desert,
        Fishing_Pond,
        Unk_C,
        Unk_D,
        Unk_E,
        Unk_F,
        Forest_Temple,
        Goron_Mines,
        Lakebed_Temple,
        Arbiters_Grounds,
        Snowpeak_Ruins,
        Temple_of_Time,
        City_in_the_Sky,
        Palace_of_Twilight,
        Hyrule_Castle,
        Cave_of_Ordeals, // Includes Gorge Cave and Ice Block Cave
        Lake_Hylia_Cave, // Includes Goron Stockcave
        Grottos,
        Unk_1C,
        Unk_1D,
        Unk_1E,
        Unk_1F,
    };

    enum StageIDs : uint8_t
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

    enum SnowpeakStateIDs : uint8_t
    {
        SPR_Northwest_Door_Unlocked = 0x1,
        SPR_West_Door_Unlocked = 0x2,
        SPR_Dungeon_Completed = 0x3
    };

    enum FaronStateIDs : uint8_t
    {
        Faron_Talo_Captured = 0x1,
        Faron_Forest_Temple_Completed = 0x2,
        Faron_MDH_Completed = 0x3,
        Faron_Snowpeak_Completed = 0x5
    };

    enum KakarikoStateIDs : uint8_t
    {
        Kakariko_KB1_Active = 0x1,
        Kakariko_KB1_Completed = 0x2,
        Kakariko_KB1_Completed_Night = 0x3,
        Kakariko_Goron_Mines_Completed = 0xC,
        Kakariko_Zora_Escort_Cleared = 0x4
    };

    enum KakarikoInteriorStateIDs : uint8_t
    {
        Kakariko_Int_KB1_Active = 0x1,
        Kakariko_Int_KB1_Completed = 0x2,
        Kakariko_Int_KB1_Completed_Night = 0x3,
        Kakariko_Int_Lakebed_Completed = 0x4,
        Kakariko_Int_Lakebed_Completed_Night = 0x5
    };

    enum DeathMountainStateIDs : uint8_t
    {
        Death_Mountain_Goron_Mines_Completed = 0x2
    };

    enum DeathMountainInteriorStateIDs : uint8_t
    {
        Death_Mountain_Int_Goron_Mines_Completed = 0x1,
        Death_Mountain_Int_Master_Sword_CS_Watched = 0x2,
        Death_Mountain_Int_Ilia_Given_Charm = 0x3,
        Death_Mountain_Int_Temple_of_Time_Completed = 0x4
    };

    enum LakeHyliaStateIDs : uint8_t
    {
        Lake_Hylia_Warped_Cannon_To_Lake = 0x1,
        Lake_Hylia_Lakebed_Completed = 0x2,
        Lake_Hylia_Cannon_Repaired = 0x3,
        Lake_Int_MDH_Started = 0x2,
        Lake_Int_Lakebed_Completed = 0x9
    };

    enum CastleTownStateIDs : uint8_t
    {
        Castle_Town_West_MDH_Clear = 0x0,
        Castle_Town_Finished_Zora_Escort = 0x1,
        Castle_Town_MDH_Clear = 0x1,
        Castle_Town_Lakebed_Completed = 0x2
    };

    enum ZorasDomainStateIDs : uint8_t
    {
        Domain_Snowpeak_Ruins_Completed = 0x2,
        Domain_Meteor_Warped = 0xD
    };

    enum UpperZorasRiverStateIDs : uint8_t
    {
        Upper_Zoras_River_Iza_1_Started = 0x1
    };

    enum GerudoDesertStateIDs : uint8_t
    {
        Desert_Entrance_Cutscene_Watched = 0x0,
        Desert_Entrance_Cutscene_Not_Watched = 0x8
    };

    enum ZorasRiverStateIDs : uint8_t
    {
        Zoras_River_Iza_1_Completed = 0x1,
        Zoras_River_Iza_1_Started = 0x2
    };

    enum OrdonVillageStateIDs : uint8_t
    {
        Ordon_Goats_1_Completed = 0x0,
        Ordon_Link_House_Talo_Rescued = 0x0,
        Ordon_Finished_Sewers = 0x1,
        Ordon_Faron_Twilight_Cleared = 0x2,
        Ordon_Faron_Twilight_Cleared_Night = 0x3,
        Ordon_Link_House_New_Game = 0x3,
        Ordon_Link_House_Goats_1_Completed = 0x4,
        Ordon_Epona_Tamed = 0x4,
        Ordon_Epona_Tamed_Night = 0x5,
        Ordon_New_Game = 0x6,
        Ordon_Talo_Rescued = 0x7
    };

    enum OrdonInteriorsStateIDs : uint8_t
    {
        Ordon_Int_Finished_Sewers = 0x1,
        Ordon_Int_Faron_Twilight_Cleared = 0x2,
        Ordon_Int_KB1_Completed = 0x3
    };

    enum OrdonSpringStateIDs : uint8_t
    {
        Ordon_Spring_Talo_Rescued = 0x0,
        Ordon_Spring_New_Game = 0x1,
        Ordon_Spring_Faron_Twilight_Cleared = 0x2,
        Ordon_Spring_Sword_Tutorial_Completed = 0x3,
        Ordon_Spring_Finished_Sewers = 0x4
    };

    enum OrdonRanchStateIDs : uint8_t
    {
        Ordon_Ranch_Finished_Sewers = 0x1,
        Ordon_Ranch_Faron_Twilight_Cleared = 0x2,
        Ordon_Ranch_Faron_Twilight_Cleared_Night = 0x3,
        Ordon_Ranch_Talo_Rescued = 0x9,
        Ordon_Ranch_Goats_2_Completed = 0xA,
        Ordon_Ranch_Goats_1_Completed = 0xB,
        Ordon_Ranch_New_Game = 0xC
    };

    enum HyruleFieldStateIDs : uint8_t
    {
        Hyrule_Field_New_Game = 0x0,
        Hyrule_Field_MDH_Started = 0x4,
        Hyrule_Field_MDH_Completed = 0x6,
        Hyrule_Field_Meteor_Warped = 0xD
    };

    enum OutsideCastleTownStateIDs : uint8_t
    {
        Outside_Castle_Town_New_Game = 0x0,
        Outside_Castle_Town_MDH_Completed_East = 0x0,
        Outside_Castle_Town_Talked_To_Louise_Before_Statue = 0x1,
        Outside_Castle_Town_MDH_Started = 0x4,
        Outside_Castle_Town_MDH_Completed = 0x6,
        Outside_Castle_Town_Got_Wooden_Statue_South = 0x6
    };

    enum HiddenVillageStateIDs : uint8_t
    {
        Hidden_Village_New_Game = 0x0,
        Hidden_Village_Showed_Ilia_Charm = 0x1
    };

    enum CastleTownInteriorsStateIDs : uint8_t
    {
        Castle_Town_Int_Twilight_Cleared = 0x0,
        Castle_Town_Int_Lakebed_Completed = 0x2,
        Castle_Town_Int_Watched_MS_Cutscene = 0x4
    };

    enum CastleTownShopsStateIDs : uint8_t
    {
        Castle_Town_Int_New_Game = 0x0,
        Castle_Town_Int_Jovani_MDH_Completed = 0x0,
        Castle_Town_Int_Malo_Mart = 0x1,
        Castle_Town_Int_Jovani_New_Game = 0x1,
    };

    enum SacredGroveStateIDs : uint8_t
    {
        Grove_2 = 0x2
    };

    enum BulblinCampStateIDs : uint8_t
    {
        Bulblin_Camp_New_Game = 0x0,
        Bulblin_Camp_KB3_Completed = 0x1,
        Bulblin_Camp_Stallord_Defeated = 0x2,
        Bulblin_Camp_Watched_Mirror_Cutscene = 0x3
    };

    enum FaronWoodsCaveStateIDs : uint8_t
    {
        Faron_Woods_Cave_New_Game = 0x0,
        Faron_Woods_Cave_Talo_Rescued = 0x1,
    };

    enum SewersStateIDs : uint8_t
    {
        Sewers_New_Game = 0x0,
        Sewers_First_Time = 0xB,
        Sewers_Midna_On_Back = 0xD
    };

    enum HyruleCastleStateIDs : uint8_t
    {
        Hyrule_Castle_Exterior_State = 0x0,
        Hyrule_Castle_Interior_State = 0x1
    };

    enum FishingHoleStateIDs : uint8_t
    {
        Fishing_Hole_Spring = 0x0,
        Fishing_Hole_Summer = 0x1,
        Fishing_Hole_Autumn = 0x2,
        Fishing_Hole_Winter = 0x3,
    };

    enum TwilightStateIDs : uint8_t
    {
        Default_Twilight_State = 0xE,
        Palace_of_Twilight_Zant_Fight = 0x0,
        Palace_of_Twilight_Zant_Defeated = 0x1,
    };

    // AreaIDs used by the game, excluding 0xFF (title screen, KB temp map, ...)
    extern const uint8_t regions[24];

    // RegionID per stage, offset into regions[]
    extern const uint8_t regionID[78];

    // Stage strings (ids)
    extern const char allStages[78][8];

    // Human readable stage translations
    // extern const char* stageDescs[78];
} // namespace libtp::data::stage
#endif
