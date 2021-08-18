/**	@file d_com_inf_game.h
 *	@brief Holds general game information
 *
 *	d_com_inf_game is one of the most crucial fields
 *	with various data about the current game state
 *
 *	@author Zephiles
 *	@author AECX
 *	@bug No known bugs.
 */
#pragma once
#include <cstdint>

#include "evt_control.h"
#include "..\data\items.h"

namespace libtp::tp::d_com_inf_game
{
    /**
     *	@brief Holds 1:1 save-file data
     *
     *	@todo Fill missing vars.
     *	@todo Make bitfields actual bitwise variables for easier access.
     *(https://en.cppreference.com/w/cpp/language/bit_field)
     */
    struct GameInfo
    {
        Save save_file; //ScratchPad
        Memory memory;
        DanBit dungeon_bit;
        Zone zones[32];
        Restart restart;
        Event events;
        TurnRestart turn_restart;
    };

    struct Save
    {
        Player player;
        uint8_t field_0x1ec[4];
        Memory area_flags[32];
        Memory ordon_area_flags;
        Memory sewers_area_flags;
        Memory faron_area_flags;
        Memory eldin_area_flags;
        Memory lanayru_area_flags;
        Memory unk5;
        Memory hyrule_field_flags;
        Memory sacred_grove_flags;
        Memory snowpeak_flags;
        Memory castle_town_flags;
        Memory gerudo_desert_flags;
        Memory fishing_hole_flags;
        Memory unk12[4];
        Memory forest_temple_flags;
        Memory goron_mines_flags;
        Memory lakebed_temple_flags;
        Memory arbiters_grounds_flags;
        Memory snowpeak_ruins_flags;
        Memory temple_of_time_flags;
        Memory city_in_the_sky_flags;
        Memory palace_of_twilight_flags;
        Memory hyrule_castle_flags;
        Memory cave_flags;
        Memory lake_hylia_lantern_cave_flags;
        Memory grotto_flags;
        Memory unk28[4];
        Memory2 ordon_ranch_map_flags;
        Memory2 ordon_village_map_flags;
        Memory2 ordon_spring_map_flags;
        Memory2 ordon_interiors_map_flags;
        Memory2 unk4;
        Memory2 sewers_map_flags;
        Memory2 faron_woods_map_flags;
        Memory2 coro_shop_map_flags;
        Memory2 sacred_grove_map_flags;
        Memory2 kakariko_village_map_flags;
        Memory2 death_mountain_map_flags;
        Memory2 kakariko_graveyard_map_flags;
        Memory2 kakariko_interiors_map_flags;
        Memory2 zoras_river_map_flags;
        Memory2 zoras_domain_map_flags;
        Memory2 snowpeak_map_flags;
        Memory2 lake_hylia_map_flags;
        Memory2 castle_town_map_flags;
        Memory2 desert_map_flags;
        Memory2 unk19[2];
        Memory2 hyrule_field_map_flags;
        Memory2 forest_temple_map_flags;
        Memory2 goron_mines_map_flags;
        Memory2 lakebed_temple_map_flags;
        Memory2 arbiters_grounds_map_flags;
        Memory2 snowpeak_ruins_map_flags;
        Memory2 temple_of_time_map_flags;
        Memory2 city_in_the_sky_map_flags;
        Memory2 palace_of_twilight_map_flags;
        Memory2 hyrule_castle_map_flags;
        Memory2 death_mountain_interiors_map_flags;
        Memory2 castle_town_interiors_map_flags;
        Memory2 fishing_pond_map_flags;
        Memory2 hidden_village_map_flags;
        Memory2 hidden_village_interiors_map_flags;
        Memory2 light_arrow_cutscene_map_flags;
        Memory2 hyrule_castle_cutscene_map_flags;
        Memory2 shades_realm_map_flags;
        Memory2 fishing_pond_interiors_map_flags;
        Memory2 ice_block_cave_map_flags;
        Memory2 cave_of_ordeals_map_flags;
        Memory2 gorge_lantern_cave_map_flags;
        Memory2 lake_hylia_lantern_cave_map_flags;
        Memory2 goron_stockcave_map_flags;
        Memory2 grotto_map_flags;
        Memory2 unk46[4];
        Memory2 faron_woods_cave_map_flags;
        Memory2 unk51[13];
        Event event_flags;
        uint8_t unk2288[80];
        MiniGame minigame_flags;
    };

    struct Player
    {
        PlayerStatusA player_status_a;
        PlayerStatusB player_status_b;
        HorsePlace horse_place;
        PlayerReturnPlace player_return_place;
        PlayerFieldLastStayInfo player_last_stay_info;
        PlayerLastMarkInfo player_last_mark_info;
        PlayerItem player_item;
        PlayerGetItem player_get_item;
        PlayerItemRecord player_item_record;
        PlayerItemMax player_item_max;
        PlayerCollect player_collect;
        PlayerWolf player_wolf;
        LightDrop light_drop;
        LetterInfo letter_info;
        FishingInfo fishing_info;
        PlayerInfo player_info;
        PlayerConfig player_config;
    };

    struct Memory
    {
        MemBit temp_flags;
    };

    struct Memory2
    {
        uint32_t room_flags1;
        uint32_t room_flags2;
    };

    struct Event
    {
        uint8_t events[256];
    };

    struct MiniGame
    {
        uint8_t unk0;
        uint8_t
    };

    struct MemBit
    {
        uint32_t area_flags_bitfields1[2];
        uint32_t area_flags_bitfields2[4];
        uint32_t rupee_flags_bitfields;
        uint8_t small_keys;
        uint8_t dungeon_flags;
        uint8_t padding[2];
    };

    struct PlayerStatusA
    {
        uint16_t maxHealth;
        uint16_t currentHealth;
        uint16_t currentRupees;
        uint16_t maxLanternOil;
        uint16_t currentLanternOil;
        uint8_t unk10; //Possibly an unused Wii equip slot.
        libtp::data::item::Item selectItem[3];
        libtp::data::item::Item mixItem[3];
        uint8_t unk17; //Possibly an unused Wii combo equip slot.
        uint8_t unk18;
        libtp::data::item::Item equipment[6];
        Wallets currentWallet;
        uint8_t unk26;
        uint8_t unk27;
        uint8_t magicFlag;
        uint8_t unk29;
        uint8_t currentForm;
        uint8_t unk31[3];
        uint8_t padding[6];
    };

    struct PlayerStatusB
    {
        uint32_t unk0;
        uint32_t currentTime;
        uint8_t transform_level_flag; //0 is Sewers. 1 is Eldin. 2 is Lanayru. 3 is MDH
        uint8_t dark_clear_level_flag;
        uint16_t unk10;
        float skyAngle;
        uint16_t unk16;
        uint8_t unk18[3];
        uint8_t padding21[3];
    };

    struct HorsePlace
    {
        float epona_x_pos;
        float epona_y_pos;
        float epona_z_pos;
        uint16_t epona_angle;
        uint8_t epona_spawn_id;
        uint8_t epona_room_id;
    };

    struct PlayerReturnPlace
    {
        char link_current_stage[8];
        uint8_t link_spawn_point_id;
        uint8_t link_room_id;
        uint8_t unk10;
        uint8_t unk11;
    };

    struct PlayerFieldLastStayInfo
    {
        float player_last_x_pos;
        float player_last_y_pos;
        float player_last_z_pos;
        uint16_t player_last_angle;
        char player_last_stage[8];
        uint8_t player_last_spawn_id;
        uint8_t player_last_room_id;
        uint8_t unk24;
        uint8_t player_last_region;
        uint8_t unk26[2];
    };

    struct PlayerLastMarkInfo
    {
        float ooccoo_x_pos;
        float ooccoo_y_pos;
        float ooccoo_z_pos;
        uint16_t ooccoo_angle;
        char ooccoo_stage[8];
        uint8_t ooccoo_spawn_id;
        uint8_t ooccoo_room_id;
        char unk24;
        uint8_t unk25[3];
    };

    struct PlayerItem
    {
        libtp::data::item::Item item[24];
        ItemSlot item_slots[24];
    };

    struct PlayerGetItem
    {
        uint32_t pause_menu_bit_fields[4];
        uint8_t padding[16]; //I doubt this is correct as the flags for golden bugs are in here as well.
    };

    struct PlayerItemRecord
    {
        uint8_t bow_ammo;
        uint8_t bomb_bag_1_ammo;
        uint8_t bomb_bag_2_ammo;
        uint8_t bomb_bag_3_ammo;
        uint8_t unk4_ammo[4];
        uint8_t slingshot_ammo;
        uint8_t unk5_ammo;
    };

    struct PlayerItemMax
    {
        uint8_t max_arrow_capacity;
        uint8_t max_bomb_capacity;
        uint8_t max_water_bomb_capacity;
        uint8_t unk3;
        uint8_t unk4;
        uint8_t unk5;
        uint8_t max_bombling_capacity;
        uint8_t unk7;
    };

    struct PlayerCollect
    {
        uint8_t equipment[8];
        uint8_t unk8;
        uint8_t crystal;
        uint8_t mirror;
        uint8_t unk11;
        uint8_t poe_count;
        uint8_t padding13[3];
    };

    struct PlayerWolf
    {
        uint8_t unk0[3];
        uint8_t unk3;
    };

    struct LightDrop
    {
        uint8_t faron_tear_count;
        uint8_t eldin_tear_count;
        uint8_t lanayru_tear_count;
        uint8_t unk3;
        uint8_t light_drop_flag;
        uint8_t unk5[3];
    };

    struct LetterInfo
    {
        uint32_t letter_get_bitfields[2];
        uint32_t letter_read_bitfields[2];
        u8 padding[64];
    };

    struct FishingInfo
    {
        uint16_t hyrule_bass_count;
        uint16_t hylian_loach_count;
        uint16_t hylian_pike_count;
        uint16_t ordon_catfish_count;
        uint16_t reekfish_count;
        uint16_t greengill_count;
        uint16_t unk12;
        uint16_t unk14;
        uint16_t unk16;
        uint16_t unk18;
        uint16_t unk20;
        uint16_t unk22;
        uint16_t unk24;
        uint16_t unk26;
        uint16_t unk28;
        uint16_t unk30;
        uint8_t largest_hyrule_bass_size;
        uint8_t largest_hylian_loach_size;
        uint8_t largest_hylian_pike_size;
        uint8_t largest_ordon_catfish_size;
        uint8_t largest_reekfish_size;
        uint8_t largest_greengill_size;
        uint8_t unk38;
        uint8_t unk39;
        uint8_t unk40;
        uint8_t unk41;
        uint8_t unk42;
        uint8_t unk43;
        uint8_t unk44;
        uint8_t unk45;
        uint8_t unk46;
        uint8_t unk47;
        uint8_t padding48[4];
    };

    struct PlayerInfo
    {
        uint8_t unk0[4];
        uint8_t unk4[4];
        uint8_t unk8[4];
        uint8_t unk12[4];
        uint8_t unk16[2];
        uint8_t unk18[2];
        uint8_t links_name[16];
        uint8_t unk36
        uint8_t eponas_name[16];
        uint8_t unk53;
        uint8_t unk54;
        uint8_t unk55[5];
        uint8_t padding60[4];
    };

    struct PlayerConfig
    {
        uint8_t unk0;
        uint8_t sound_mode; //0 is Mono. 1 is Stereo. 2 is Surround.
        uint8_t target_mode; //0 is Hold. 1 is Switch.
        uint8_t vibration_on_off; //0 is Off. 1 is On
        uint8_t motion_controls; //0 is On. 1 is Off. 
        uint8_t brightness_level; //1 is darkest. 6 is brightest.
        uint16_t unk6;
        uint8_t unk8;
        uint8_t unk9;
        uint8_t camera_aiming_options; // Default is 8. |80 is third person aiming. |8 inverts the vertical swiming axis. |4 inverts horizontal swimming axis. |2 inverts vertical camera axis. |1 inverts horizontal axis. 
        uint8_t unk11;
    };

    enum Wallets : u8
	{
        Wallet = 0,
        Big_Wallet = 1,
        Giant_Wallet = 2
    };

    enum ItemSlot : u8
    { // The 24 useable item slots in the game
        SLOT_0 = 0;
        SLOT_1 = 1;
        SLOT_2 = 2;
        SLOT_3 = 3;
        SLOT_4 = 4;
        SLOT_5 = 5;
        SLOT_6 = 6;
        SLOT_7 = 7;
        SLOT_8 = 8;
        SLOT_9 = 9;
        SLOT_10 = 10;
        SLOT_11 = 11;
        SLOT_12 = 12;
        SLOT_13 = 13;
        SLOT_14 = 14;
        SLOT_15 = 15;
        SLOT_16 = 16;
        SLOT_17 = 17;
        SLOT_18 = 18;
        SLOT_19 = 19;
        SLOT_20 = 20;
        SLOT_21 = 21;
        SLOT_22 = 22;
        SLOT_23 = 23; 
    };


    /**
     *	@brief Holds information about the current stage
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct CurrentStageVars
    {
        char currentStage[8];
        int16_t currentSpawnPoint;
        uint8_t unknown[4];
    } __attribute__((__packed__));

    /**
     *	@brief Holds information about the next stage
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct NextStageVars
    {
        char nextStage[8];
        uint8_t isVoidorWarp;
        uint8_t nextSpawnPoint;
        uint8_t nextRoom;
        uint8_t nextState;
        uint8_t unk1;
        uint8_t unk2;
        uint8_t triggerLoad;
        uint8_t fadeType;
    } __attribute__((__packed__));

    /**
     *	@brief Cutscene and event control system
     *
     *	@todo Fill missing vars.
     */
    struct EventSystem
    {
        uint8_t unk00[0x13];
        uint16_t immediateControl;
        uint8_t unk_00[0x4];
        uint8_t nextEventID;
        uint8_t unk1A[0xD1];
        uint8_t currentEventID;
        uint8_t unk_ec[0x14];
        libtp::tp::evt_control::csSkipFunction* onSkip;  // This will run when trying to skip; if null it's unskippable
        uint8_t unk_104[0xC];
        uint32_t fadeOnSkip;  // If > 0 the screen will fade when skipping
    } __attribute__((__packed__));

    /**
     *	@brief Holds data about Links position on the current map
     *
     *	@todo Fill missing vars.
     *	@todo Get exact size.
     */
    struct LinkMapVars
    {
        uint8_t unk_0[0x4D0];
        float pos[3];
    } __attribute__((__packed__));

    /**
     *	@brief GameInfo Structure holding general and most crucial game
     *information
     *
     *	@todo Fill missing vars
     */
    struct GameInfo
    {
        ScratchPad scratchPad;         // 0 - 957
        uint8_t localAreaNodes[0x20];  // 958 - 977 holds flags about the current area
        uint8_t unk_978[0x450];        // 978 - DC7
        uint8_t respawnCutscene;       // DC8 - DC8
        uint8_t unkdc9[0xA];           // dc9 - dd2
        uint8_t respawnAnimation;      // dd3 - dd3
        uint8_t unkdd4[0x402C];        // dd4 - 4DFF
        char currentStage[8];          // 4E00 - 4E07
        uint8_t unk_4e08[6];           // 4E08 - 4E0D
        NextStageVars nextStageVars;   // 4E0E - 4E1b
        uint8_t unk_4e1c[0xAA];        // 4E19 - 4EC7
        EventSystem eventSystem;       // 4EC8 - 4FDE
        uint8_t unk_4fdd[0xDD0];       // 4FDD - 5DBF
        LinkMapVars* linkMapPtr;       // 5DA0 - 5DAB
        uint8_t unk_5dac[0x18060];
    } __attribute__((__packed__));
    static_assert(sizeof(ScratchPad) == 0x958);
    static_assert(sizeof(GameInfo) == 0x1DE10);

    extern "C"
    {
        extern GameInfo dComIfG_gameInfo;
    }
}  // namespace libtp::tp::d_com_inf_game