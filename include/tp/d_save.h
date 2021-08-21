/**	@file d_save.h
 *	@brief Holds symbols of the d_save field
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#pragma once
#include <cstdint>

//#include "d_com_inf_game.h"
#include "c_xyz.h"

namespace libtp::tp::d_save
{
    enum Wallets : uint8_t 
	{
        Wallet = 0,
        Big_Wallet = 1,
        Giant_Wallet = 2
    } __attribute__((__packed__));

    enum ItemSlot : uint8_t 
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
    } __attribute__((__packed__));

    enum ItemTable : uint8_t
	{
		Recovery_Heart	=	0x00,
		Green_Rupee	=	0x01,
		Blue_Rupee	=	0x02,
		Yellow_Rupee	=	0x03,
		Red_Rupee	=	0x04,
		Purple_Rupee	=	0x05,
		Orange_Rupee	=	0x06,
		Silver_Rupee	=	0x07,
		/*Small Magic	=	0x08,*/
		/*Large Magic	=	0x09,*/
		Bombs_5	=	0x0A,
		Bombs_10	=	0x0B,
		Bombs_20	=	0x0C,
		Bombs_30	=	0x0D,
		Arrows_10	=	0x0E,
		Arrows_20	=	0x0F,
		Arrows_30	=	0x10,
		Arrows_1	=	0x11,
		Seeds_50	=	0x12,
		/*?	=	0x13,*/
		/*?	=	0x14,*/
		/*?	=	0x15,*/
		Water_Bombs_5	=	0x16,
		Water_Bombs_10	=	0x17,
		Water_Bombs_15	=	0x18,
		Water_Bombs_3	=	0x19,
		Bomblings_5	=	0x1A,
		Bomblings_10	=	0x1B,
		Bomblings_3	=	0x1C,
		Bombling_1	=	0x1D,
		Fairy	=	0x1E,
		Recovery_Heart_x3	=	0x1F,
		Small_Key	=	0x20,
		Piece_of_Heart	=	0x21,
		Heart_Container	=	0x22,
		Dungeon_Map	=	0x23,
		Compass	=	0x24,
		Ooccoo_FT	=	0x25,
		Big_Key	=	0x26,
		Ooccoo_Jr	=	0x27,
		Ordon_Sword	=	0x28,
		Master_Sword	=	0x29,
		Ordon_Shield	=	0x2A,
		Wooden_Shield	=	0x2B,
		Hylian_Shield	=	0x2C,
		Ooccoos_Note	=	0x2D,
		Ordon_Clothing	=	0x2E,
		Heros_Clothes	=	0x2F,
		Magic_Armor	=	0x30,
		Zora_Armor	=	0x31,
		Shadow_Crystal	=	0x32, //Does nothing in Vanilla. Is used to handle the transformation flag in the Randomizer.
		Ooccoo_Dungeon	=	0x33,
		Small_Wallet	=	0x34, //Unused
		Big_Wallet	=	0x35,
		Giant_Wallet	=	0x36,
		/*Piece_of_Heart_2?	=	0x37,*/
		/*Piece_of_Heart_3?	=	0x38,*/
		/*Piece_of_Heart_4?	=	0x39,*/
		/*Piece_of_Heart_5?	=	0x3A,*/
		/*sword?	=	0x3B,*/
		/*?	=	0x3C,*/
		Coral_Earring	=	0x3D,
		Hawkeye	=	0x3E,
		Wooden_Sword	=	0x3F,
		Boomerang	=	0x40,
		Spinner	=	0x41,
		Ball_and_Chain	=	0x42,
		Heros_Bow	=	0x43,
		Clawshot	=	0x44,
		Iron_Boots	=	0x45,
		Dominion_Rod = 0x46,
		Clawshots	=	0x47,
		Lantern	=	0x48,
		Master_Sword_Light	=	0x49,
		Fishing_Rod	=	0x4A,
		Slingshot	=	0x4B,
		Dominion_Rod_Uncharged = 0x4C,
		/*?	=	0x4D,*/
		/*?	=	0x4E,*/
		Giant_Bomb_Bag	=	0x4F,
		Empty_Bomb_Bag	=	0x50,
		Goron_Bomb_Bag	=	0x51,
		/*Giant_Bomb_Bag?	=	0x52,*/
		/*?	=	0x53,*/
		Small_Quiver	=	0x54, //Unused
		Big_Quiver	=	0x55,
		Giant_Quiver	=	0x56,
		/*?	=	0x57,*/
		Fishing_Rod_Lure	=	0x58,
		Bow_Bombs	=	0x59,
		Bow_Hawkeye	=	0x5A,
		Fishing_Rod_Bee_Larva	=	0x5B,
		Fishing_Rod_Coral_Earring	=	0x5C,
		Fishing_Rod_Worm	=	0x5D,
		Fishing_Rod_Earring_Bee_Larva	=	0x5E,
		Fishing_Rod_Earring_Worm	=	0x5F,
		Empty_Bottle	=	0x60,
		Red_Potion_Shop	=	0x61,
		Green_Potion	=	0x62,
		Blue_Potion	=	0x63,
		Milk	=	0x64,
		Sera_Bottle	=	0x65,
		Lantern_Oil_Shop	=	0x66,
		Water	=	0x67,
		Lantern_Oil_Scooped	=	0x68,
		Red_Potion_Scooped	=	0x69,
		Nasty_soup	=	0x6A,
		Hot_spring_water_Scooped	=	0x6B,
		Fairy_Bottle	=	0x6C,
		Hot_Spring_Water_Shop	=	0x6D,
		Lantern_Refill_Scooped	=	0x6E,
		Lantern_Refill_Shop	=	0x6F,
		Bomb_Bag_Regular_Bombs	=	0x70,
		Bomb_Bag_Water_Bombs	=	0x71,
		Bomb_Bag_Bomblings	=	0x72,
		Fairy_Tears	=	0x73,
		Worm	=	0x74,
		Jovani_Bottle	=	0x75,
		Bee_Larva_Scooped	=	0x76,
		Rare_Chu_Jelly	=	0x77,
		Red_Chu_Jelly	=	0x78,
		Blue_Chu_Jelly	=	0x79,
		Green_Chu_Jelly	=	0x7A,
		Yellow_Chu_Jelly	=	0x7B,
		Purple_Chu_Jelly	=	0x7C,
		Simple_Soup	=	0x7D,
		Good_Soup	=	0x7E,
		Superb_Soup	=	0x7F,
		Renardos_Letter	=	0x80,
		Invoice	=	0x81,
		Wooden_Statue	=	0x82,
		Ilias_Charm	=	0x83,
		Horse_Call	=	0x84,
		Forest_Temple_Small_Key	=	0x85, //Custom Item added for the Randomizer.
		Goron_Mines_Small_Key	=	0x86, //Custom Item added for the Randomizer.
		Lakebed_Temple_Small_Key	=	0x87, //Custom Item added for the Randomizer.
		Arbiters_Grounds_Small_Key	=	0x88, //Custom Item added for the Randomizer.
		Snowpeak_Ruins_Small_Key	=	0x89, //Custom Item added for the Randomizer.
		Temple_of_Time_Small_Key	=	0x8A, //Custom Item added for the Randomizer.
		City_in_The_Sky_Small_Key	=	0x8B, //Custom Item added for the Randomizer.
		Palace_of_Twilight_Small_Key	=	0x8C, //Custom Item added for the Randomizer.
		Hyrule_Castle_Small_Key	=	0x8D, //Custom Item added for the Randomizer.
		/*?	=	0x8E,*/
		FoolishItem	=	0x8F,
		Aurus_Memo	=	0x90,
		Asheis_Sketch	=	0x91,
		Forest_Temple_Big_Key	=	0x92, //Custom Item added for the Randomizer.
		Lakebed_Temple_Big_Key	=	0x93, //Custom Item added for the Randomizer.
		Arbiters_Grounds_Big_Key	=	0x94, //Custom Item added for the Randomizer.
		Temple_of_Time_Big_Key	=	0x95, //Custom Item added for the Randomizer.
		City_in_The_Sky_Big_Key	=	0x96, //Custom Item added for the Randomizer.
		Palace_of_Twilight_Big_Key	=	0x97, //Custom Item added for the Randomizer.
		Hyrule_Castle_Big_Key	=	0x98, //Custom Item added for the Randomizer.
		/*?	=	0x99,*/
		/*?	=	0x9A,*/
		/*?	=	0x9B,*/
		Lantern_Yellow_Chu_Chu	=	0x9C,
		Coro_Bottle	=	0x9D,
		Bee_Larva_Shop	=	0x9E,
		Black_Chu_Jelly	=	0x9F,
		/*unused*/Tear_Of_Light	=	0xA0,
		Vessel_Of_Light_Faron	=	0xA1,
		Vessel_Of_Light_Eldin	=	0xA2,
		Vessel_Of_Light_Lanayru	=	0xA3,
		/*unused*/Vessel_Of_Light_Full	=	0xA4,
		/*?	=	0xA5,*/
		/*?	=	0xA6,*/
		/*?	=	0xA7,*/
		/*?	=	0xA8,*/
		/*?	=	0xA9,*/
		/*?	=	0xAA,*/
		/*?	=	0xAB,*/
		/*?	=	0xAC,*/
		/*?	=	0xAD,*/
		/*?	=	0xAE,*/
		/*?	=	0xAF,*/
		Ilias_Scent	=	0xB0,
		/*Unused_Scent?	=	0xB1,*/
		Poe_Scent	=	0xB2,
		Reekfish_Scent	=	0xB3,
		Youths_Scent	=	0xB4,
		Medicine_Scent	=	0xB5,
		/*?	=	0xB6,*/
		/*?	=	0xB7,*/
		/*?	=	0xB8,*/
		/*?	=	0xB9,*/
		/*?	=	0xBA,*/
		/*?	=	0xBB,*/
		/*?	=	0xBC,*/
		/*?	=	0xBD,*/
		/*?	=	0xBE,*/
		/*Bottle_Insides?	=	0xBF,*/
		Male_Beetle	=	0xC0,
		Female_Beetle	=	0xC1,
		Male_Butterfly	=	0xC2,
		Female_Butterfly	=	0xC3,
		Male_Stag_Beetle	=	0xC4,
		Female_Stag_Beetle	=	0xC5,
		Male_Grasshopper	=	0xC6,
		Female_Grasshopper	=	0xC7,
		Male_Phasmid	=	0xC8,
		Female_Phasmid	=	0xC9,
		Male_Pill_Bug	=	0xCA,
		Female_Pill_Bug	=	0xCB,
		Male_Mantis	=	0xCC,
		Female_Mantis	=	0xCD,
		Male_Ladybug	=	0xCE,
		Female_Ladybug	=	0xCF,
		Male_Snail	=	0xD0,
		Female_Snail	=	0xD1,
		Male_Dragonfly	=	0xD2,
		Female_Dragonfly	=	0xD3,
		Male_Ant	=	0xD4,
		Female_Ant	=	0xD5,
		Male_Dayfly	=	0xD6,
		Female_Dayfly	=	0xD7,
		/*?	=	0xD8,*/
		/*?	=	0xD9,*/
		/*?	=	0xDA,*/
		/*?	=	0xDB,*/
		/*?	=	0xDC,*/
		/*?	=	0xDD,*/
		/*?	=	0xDE,*/
		/*?	=	0xDF,*/
		Poe_Soul	=	0xE0,
		Ending_Blow	=	0xE1,
		Shield_Attack	=	0xE2,
		Back_Slice	=	0xE3,
		Helm_Splitter	=	0xE4,
		Mortal_Draw	=	0xE5,
		Jump_Strike	=	0xE6,
		Great_Spin	=	0xE7,
		/*?	=	0xE8,*/
		Ancient_Sky_Book_empty	=	0xE9,
		Ancient_Sky_Book_partly_filled	=	0xEA,
		Ancient_Sky_Book_completed	=	0xEB,
		Ooccoo_CitS	=	0xEC,
		Purple_Rupee_Links_house	=	0xED,
		Small_Key_N_Faron_Gate	=	0xEE,
		/*Blue_Fire?	=	0xEF,*/
		/*Blue_Fire?	=	0xF0,*/
		/*Blue_Fire?	=	0xF1,*/
		/*Blue_Fire?	=	0xF2,*/
		Gate_Keys	=	0xF3,
		Ordon_Pumpkin	=	0xF4,
		Ordon_Goat_Cheese	=	0xF5,
		Bed_Key	=	0xF6,
		/*Shield?	=	0xF7,*/
		Got_Lantern_Back	=	0xF8,
		Key_Shard_1	=	0xF9,
		Key_Shard_2	=	0xFA,
		Key_Shard_3	=	0xFB,
		/*Key?	=	0xFC,*/
		Big_Key_Goron_Mines	=	0xFD,
		Coro_Key	=	0xFE,
		/*Gives_Vanilla*/NullItem	=	0xFF
	} __attribute__((__packed__));

    class dSv_info_c
    {
        private:
            dSv_save_c save_file; //ScratchPad 0 - 957
            dSv_memory_c memory; //Local Area Nodes 958 - 977
            dSv_danBit_c dungeon_bit; //978 - 9B3
            dSv_zone_c zones[32]; //9B4 - DB3
            dSv_restart_c restart; //DB4 - DD7
            dSv_event_c events; //DD8 - ED7
            dSv_turnRestart_c turn_restart; //ED8 - EEA
            uint8_t unk1[0x3D]; //EEB - F27
            uint32_t saveTotalTime; //F28
            uint32_t saveStartTime; //F2C
            uint32_t unkF30; //F30
            uint32_t unkF34; //F34
    } __attribute__((__packed__));

    class dSv_save_c
    {
        private:
            dSv_player_c player;
            uint8_t field_0x1ec[4];
            dSv_memory_c area_flags[32];
            dSv_memory_c ordon_area_flags;
            dSv_memory_c sewers_area_flags;
            dSv_memory_c faron_area_flags;
            dSv_memory_c eldin_area_flags;
            dSv_memory_c lanayru_area_flags;
            dSv_memory_c unk5;
            dSv_memory_c hyrule_field_flags;
            dSv_memory_c sacred_grove_flags;
            dSv_memory_c snowpeak_flags;
            dSv_memory_c castle_town_flags;
            dSv_memory_c gerudo_desert_flags;
            dSv_memory_c fishing_hole_flags;
            dSv_memory_c unk12[4];
            dSv_memory_c forest_temple_flags;
            dSv_memory_c goron_mines_flags;
            dSv_memory_c lakebed_temple_flags;
            dSv_memory_c arbiters_grounds_flags;
            dSv_memory_c snowpeak_ruins_flags;
            dSv_memory_c temple_of_time_flags;
            dSv_memory_c city_in_the_sky_flags;
            dSv_memory_c palace_of_twilight_flags;
            dSv_memory_c hyrule_castle_flags;
            dSv_memory_c cave_flags;
            dSv_memory_c lake_hylia_lantern_cave_flags;
            dSv_memory_c grotto_flags;
            dSv_memory_c unk28[4];
            dSv_memory2_c ordon_ranch_map_flags;
            dSv_memory2_c ordon_village_map_flags;
            dSv_memory2_c ordon_spring_map_flags;
            dSv_memory2_c ordon_interiors_map_flags;
            dSv_memory2_c unk4;
            dSv_memory2_c sewers_map_flags;
            dSv_memory2_c faron_woods_map_flags;
            dSv_memory2_c coro_shop_map_flags;
            dSv_memory2_c sacred_grove_map_flags;
            dSv_memory2_c kakariko_village_map_flags;
            dSv_memory2_c death_mountain_map_flags;
            dSv_memory2_c kakariko_graveyard_map_flags;
            dSv_memory2_c kakariko_interiors_map_flags;
            dSv_memory2_c zoras_river_map_flags;
            dSv_memory2_c zoras_domain_map_flags;
            dSv_memory2_c snowpeak_map_flags;
            dSv_memory2_c lake_hylia_map_flags;
            dSv_memory2_c castle_town_map_flags;
            dSv_memory2_c desert_map_flags;
            dSv_memory2_c unk19[2];
            dSv_memory2_c hyrule_field_map_flags;
            dSv_memory2_c forest_temple_map_flags;
            dSv_memory2_c goron_mines_map_flags;
            dSv_memory2_c lakebed_temple_map_flags;
            dSv_memory2_c arbiters_grounds_map_flags;
            dSv_memory2_c snowpeak_ruins_map_flags;
            dSv_memory2_c temple_of_time_map_flags;
            dSv_memory2_c city_in_the_sky_map_flags;
            dSv_memory2_c palace_of_twilight_map_flags;
            dSv_memory2_c hyrule_castle_map_flags;
            dSv_memory2_c death_mountain_interiors_map_flags;
            dSv_memory2_c castle_town_interiors_map_flags;
            dSv_memory2_c fishing_pond_map_flags;
            dSv_memory2_c hidden_village_map_flags;
            dSv_memory2_c hidden_village_interiors_map_flags;
            dSv_memory2_c light_arrow_cutscene_map_flags;
            dSv_memory2_c hyrule_castle_cutscene_map_flags;
            dSv_memory2_c shades_realm_map_flags;
            dSv_memory2_c fishing_pond_interiors_map_flags;
            dSv_memory2_c ice_block_cave_map_flags;
            dSv_memory2_c cave_of_ordeals_map_flags;
            dSv_memory2_c gorge_lantern_cave_map_flags;
            dSv_memory2_c lake_hylia_lantern_cave_map_flags;
            dSv_memory2_c goron_stockcave_map_flags;
            dSv_memory2_c grotto_map_flags;
            dSv_memory2_c unk46[4];
            dSv_memory2_c faron_woods_cave_map_flags;
            dSv_memory2_c unk51[13];
            dSv_event_c event_flags;
            uint8_t unk2288[80];
            dSv_MiniGame_c minigame_flags;
    } __attribute__((__packed__));

    class dSv_player_c
    {
        private:
            dSv_player_status_a_c player_status_a;
            dSv_player_status_b_c player_status_b;
            dSv_horse_place_c horse_place;
            dSv_player_return_place_c player_return_place;
            dSv_player_field_last_stay_info_c player_last_stay_info;
            dSv_player_last_mark_info_c player_last_mark_info;
            dSv_player_item_c player_item;
            dSv_player_get_item_c player_get_item;
            dSv_player_item_record_c player_item_record;
            dSv_player_item_max_c player_item_max;
            dSv_player_collect_c player_collect;
            dSv_player_wolf_c player_wolf;
            dSv_light_drop_c light_drop;
            dSv_letter_info_c letter_info;
            dSv_fishing_info_c fishing_info;
            dSv_player_info_c player_info;
            dSv_player_config_c player_config;
    } __attribute__((__packed__));

    class dSv_memory_c
    {
        private:
            dSv_memBit_c temp_flags;
    } __attribute__((__packed__));

    class dSv_memory2_c
    {
        private:
            uint32_t room_flags1;
            uint32_t room_flags2;
    } __attribute__((__packed__));

    class dSv_event_c
    {
        private:
            uint8_t events[256];
    } __attribute__((__packed__));

    class dSv_MiniGame_c
    {
        private:
            uint8_t unk0;
            uint8_t unk1[3];
            uint32_t unk4;
            uint32_t unk8;
            uint32_t unk12;
            uint32_t unk16;
            uint32_t unk20;
    } __attribute__((__packed__));

    class dSv_danBit_c
    {
        private:
            int8_t unk0;
            uint8_t unk1;
            uint8_t unk2[2];
            uint32_t unk4[6];
            uint16_t unk28[16];
    } __attribute__((__packed__));

    class dSv_zone_c
    {
        private:
            uint8_t unk0;
            uint8_t unk1;
            dSv_zoneBit_c zone_bit;
            dSv_zoneActor_c zone_actor;
    } __attribute__((__packed__));

    class dSv_restart_c
    {
        private:
            uint8_t unk0;
            uint8_t unk1[5];
            short angle;
            libtp::tp::c_xyz::cXyz position;
            uint8_t padding20[16];
    } __attribute__((__packed__));

    class dSv_turnRestart_c
    {
        private:
            libtp::tp::c_xyz::cXyz position;
            uint32_t unk12;
            short angle;
            int8_t unk18;
    } __attribute__((__packed__));

    class dSv_player_status_a_c
    {
        private:
            uint16_t maxHealth;
            uint16_t currentHealth;
            uint16_t currentRupees;
            uint16_t maxLanternOil;
            uint16_t currentLanternOil;
            uint8_t unk10; //Possibly an unused Wii equip slot.
            uint8_t selectItem[3];
            uint8_t mixItem[3];
            uint8_t unk17; //Possibly an unused Wii combo equip slot.
            uint8_t unk18;
            uint8_t equipment[6];
            Wallets currentWallet;
            uint8_t unk26;
            uint8_t unk27;
            uint8_t magicFlag;
            uint8_t unk29;
            uint8_t currentForm;
            uint8_t unk31[3];
            uint8_t padding[6];
    } __attribute__((__packed__));

    class dSv_player_status_b_c
    {
        private:
            uint32_t unk0;
            uint32_t currentTime;
            uint8_t transform_level_flag; //0 is Sewers. 1 is Eldin. 2 is Lanayru. 3 is MDH
            uint8_t dark_clear_level_flag;
            uint16_t unk10;
            float skyAngle;
            uint16_t unk16;
            uint8_t unk18[3];
            uint8_t padding21[3];
    } __attribute__((__packed__));

     class dSv_horse_place_c
    {
        private:
            float epona_x_pos;
            float epona_y_pos;
            float epona_z_pos;
            uint16_t epona_angle;
            uint8_t epona_spawn_id;
            uint8_t epona_room_id;
    } __attribute__((__packed__));

    class dSv_player_return_place_c
    {
        private:
            char link_current_stage[8];
            uint8_t link_spawn_point_id;
            uint8_t link_room_id;
            uint8_t unk10;
            uint8_t unk11;
    } __attribute__((__packed__));

    class dSv_player_field_last_stay_info_c
    {
        private:
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
    } __attribute__((__packed__));

    class dSv_player_last_mark_info_c
    {
        private:
            float ooccoo_x_pos;
            float ooccoo_y_pos;
            float ooccoo_z_pos;
            uint16_t ooccoo_angle;
            char ooccoo_stage[8];
            uint8_t ooccoo_spawn_id;
            uint8_t ooccoo_room_id;
            char unk24;
            uint8_t unk25[3];
    } __attribute__((__packed__));

    class dSv_player_item_c
    {
        uint8_t item[24];
        uint8_t item_slots[24];
    } __attribute__((__packed__));

    class dSv_player_get_item_c
    {
        private:
            uint32_t pause_menu_bit_fields[4];
            uint8_t padding[16]; //I doubt this is correct as the flags for golden bugs are in here as well.
    } __attribute__((__packed__));

    class dSv_player_item_record_c
    {
        private:
            uint8_t bow_ammo;
            uint8_t bomb_bag_1_ammo;
            uint8_t bomb_bag_2_ammo;
            uint8_t bomb_bag_3_ammo;
            uint8_t unk4_ammo[4];
            uint8_t slingshot_ammo;
            uint8_t unk5_ammo;
    } __attribute__((__packed__));

    class dSv_player_item_max_c
    {
        private:
            uint8_t max_arrow_capacity;
            uint8_t max_bomb_capacity;
            uint8_t max_water_bomb_capacity;
            uint8_t unk3;
            uint8_t unk4;
            uint8_t unk5;
            uint8_t max_bombling_capacity;
            uint8_t unk7;
    } __attribute__((__packed__));

    class dSv_player_collect_c
    {
        private:
            uint8_t equipment[8];
            uint8_t unk8;
            uint8_t crystal;
            uint8_t mirror;
            uint8_t unk11;
            uint8_t poe_count;
            uint8_t padding13[3];
    } __attribute__((__packed__));

    class dSv_player_wolf_c
    {
        private:
            uint8_t unk0[3];
            uint8_t unk3;
    } __attribute__((__packed__));

    class dSv_light_drop_c
    {
        private:
            uint8_t faron_tear_count;
            uint8_t eldin_tear_count;
            uint8_t lanayru_tear_count;
            uint8_t unk3;
            uint8_t light_drop_flag;
            uint8_t unk5[3];
    } __attribute__((__packed__));

    class dSv_letter_info_c
    {
        private:
            uint32_t letter_get_bitfields[2];
            uint32_t letter_read_bitfields[2];
            uint8_t  padding[64];
    } __attribute__((__packed__));

    class dSv_fishing_info_c
    {
        private:
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
    } __attribute__((__packed__));

    class dSv_player_info_c
    {
        private:
            uint32_t unk0;
            uint32_t unk4;
            uint64_t mTotalTime;
            uint16_t unk16;
            uint16_t mDeathCount;
            uint8_t mPlayerName[16];
            uint8_t unk36
            uint8_t mHorseName[16];
            uint8_t unk53;
            uint8_t mClearCount;
            uint8_t unk55[5];
            uint8_t padding60[4];
    } __attribute__((__packed__));

    class dSv_player_config_c
    {
        private:
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
    } __attribute__((__packed__));

    class dSv_zoneBit_c
    {
        private:
            uint8_t unk0[4];
            uint16_t room_switch;
            uint16_t unk6[2];
            uint16_t room_item;
            uint16_t unk12;
    } __attribute__((__packed__));

    class dSv_zoneActor_c
    {
        private:
            uint32_t unk0[4];
    } __attribute__((__packed__));

    class dSv_memBit_c
    {
        private:
            uint32_t area_flags_bitfields1[2];
            uint32_t area_flags_bitfields2[4];
            uint32_t rupee_flags_bitfields;
            uint8_t small_keys;
            uint8_t dungeon_flags;
            uint8_t padding[2];
    } __attribute__((__packed__));


    extern "C"
    {
        /**
         *	@brief Gets the maximum number of rupees
         *
         *	Warning! If this function is manipulated to return a higher number than
         *what
         *	the HUD can display (4 digits base 10) it causes serious issues (e.g.
         *random crashes)
         *
         *	@return Returns the maximum number of rupees Link can hold in his
         *current wallet
         */
        uint16_t getRupeeMax();

        /**
         *	@brief Sets the current AreaNode for region-specific flags
         *	by loading it from the ScratchPad/QuestLog
         *
         *	For more information about AreaNodes please refer to
         *	https://docs.google.com/spreadsheets/d/1OvlqH_OG_svcLZfuSDBjCLHFivcsBGpOD25o-_6vblA/edit#gid=0
         *
         *	@param gameInfoPtr Pointer to d_com_inf_game::gameInfo
         *	@param areaID ID of the current Area
         */
        void getSave(d_com_inf_game::GameInfo* gameInfoPtr, int32_t areaID);

        /**
         *	@brief Puts the previously set AreaNode for region-specific flags back
         *	into the ScratchPad/QuestLog
         *
         *	For more information about AreaNodes please refer to
         *	https://docs.google.com/spreadsheets/d/1OvlqH_OG_svcLZfuSDBjCLHFivcsBGpOD25o-_6vblA/edit#gid=0
         *
         *	@param gameInfoPtr Pointer to d_com_inf_game::gameInfo
         *	@param areaID ID of the current Area
         */
        void putSave(d_com_inf_game::GameInfo* gameInfoPtr, int32_t areaID);
    }
}  // namespace libtp::tp::d_save