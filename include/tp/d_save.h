/**	@file d_save.h
 *	@brief Holds symbols of the d_save field
 *
 *	@author AECX
 *	@bug No known bugs.
 */
#ifndef TP_D_SAVE_H
#define TP_D_SAVE_H
#include <cstdint>

#include "data/items.h"
#include "tp/c_xyz.h"

namespace libtp::tp::d_save
{
    struct dSv_memory2_c
    {
        uint32_t room_flags1;
        uint32_t room_flags2;
    } __attribute__( ( __packed__ ) );

    struct dSv_event_c
    {
        uint8_t event_flags[256];
    } __attribute__( ( __packed__ ) );

    struct dSv_MiniGame_c
    {
        uint8_t unk0;
        uint8_t unk1[3];
        uint32_t unk4;
        uint32_t unk8;
        uint32_t unk12;
        uint32_t unk16;
        uint32_t unk20;
    } __attribute__( ( __packed__ ) );

    struct dSv_danBit_c
    {
        int8_t unk0;
        uint8_t unk1;
        uint8_t unk2[2];
        uint32_t unk4[6];
        uint16_t unk28[16];
    } __attribute__( ( __packed__ ) );

    struct dSv_restart_c
    {
        /* 0x00 */ int8_t mRoomNo;
        /* 0x01 */ uint8_t field_0x01[3];
        /* 0x04 */ int16_t mStartPoint;
        /* 0x06 */ int16_t mRoomAngleY;
        /* 0x08 */ c_xyz::cXyz mRoomPos;
        /* 0x14 */ uint32_t mRoomParam;
        /* 0x18 */ float mLastSpeedF;
        /* 0x1C */ uint32_t mLastMode;
        /* 0x20 */ int16_t mLastAngleY;
    } __attribute__( ( __packed__ ) );

    struct dSv_turnRestart_c
    {
        libtp::tp::c_xyz::cXyz position;
        uint32_t unk12;
        short angle;
        int8_t unk18;
    } __attribute__( ( __packed__ ) );

    struct dSv_player_status_a_c
    {
        uint16_t maxHealth;
        uint16_t currentHealth;
        uint16_t currentRupees;
        uint16_t maxLanternOil;
        uint16_t currentLanternOil;
        uint8_t unk10;     // Possibly an unused Wii equip slot.
        uint8_t selectItem[3];
        uint8_t mixItem[3];
        uint8_t unk17;     // Possibly an unused Wii combo equip slot.
        uint8_t unk18;
        uint8_t equipment[6];
        libtp::data::items::Wallets currentWallet;
        uint8_t unk26;
        uint8_t unk27;
        uint8_t magicFlag;
        uint8_t unk29;
        uint8_t currentForm;
        uint8_t unk31[3];
        uint8_t padding[6];
    } __attribute__( ( __packed__ ) );

    struct dSv_player_status_b_c
    {
        uint32_t unk0;
        uint32_t currentTime;
        uint8_t transform_level_flag;     // 0 is Sewers. 1 is Eldin. 2 is Lanayru. 3 is MDH
        uint8_t dark_clear_level_flag;
        uint16_t unk10;
        float skyAngle;
        uint16_t unk16;
        uint8_t unk18[3];
        uint8_t padding21[3];
    } __attribute__( ( __packed__ ) );

    struct dSv_horse_place_c
    {
        float epona_x_pos;
        float epona_y_pos;
        float epona_z_pos;
        uint16_t epona_angle;
        uint8_t epona_spawn_id;
        uint8_t epona_room_id;
    } __attribute__( ( __packed__ ) );

    struct dSv_player_return_place_c
    {
        char link_current_stage[8];
        uint8_t link_spawn_point_id;
        uint8_t link_room_id;
        uint8_t unk10;
        uint8_t unk11;
    } __attribute__( ( __packed__ ) );

    struct dSv_player_field_last_stay_info_c
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
    } __attribute__( ( __packed__ ) );

    struct dSv_player_last_mark_info_c
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
    } __attribute__( ( __packed__ ) );

    struct dSv_player_item_c
    {
        uint8_t item[24];
        uint8_t item_slots[24];
    } __attribute__( ( __packed__ ) );

    struct dSv_player_get_item_c
    {
        uint32_t pause_menu_bit_fields[4];
        uint8_t padding[16];     // I doubt this is correct as the flags for golden bugs are in here as well.
    } __attribute__( ( __packed__ ) );

    struct dSv_player_item_record_c
    {
        uint8_t bow_ammo;
        uint8_t bomb_bag_1_ammo;
        uint8_t bomb_bag_2_ammo;
        uint8_t bomb_bag_3_ammo;
        uint8_t unk4_ammo[4];
        uint8_t slingshot_ammo;
        uint8_t unk5_ammo;
    } __attribute__( ( __packed__ ) );

    struct dSv_player_item_max_c
    {
        uint8_t max_arrow_capacity;
        uint8_t max_bomb_capacity;
        uint8_t max_water_bomb_capacity;
        uint8_t unk3;
        uint8_t unk4;
        uint8_t unk5;
        uint8_t max_bombling_capacity;
        uint8_t unk7;
    } __attribute__( ( __packed__ ) );

    struct dSv_player_collect_c
    {
        uint8_t equipment[8];
        uint8_t unk8;
        uint8_t crystal;
        uint8_t mirror;
        uint8_t unk11;
        uint8_t poe_count;
        uint8_t padding13[3];
    } __attribute__( ( __packed__ ) );

    struct dSv_player_wolf_c
    {
        uint8_t unk0[3];
        uint8_t unk3;
    } __attribute__( ( __packed__ ) );

    struct dSv_light_drop_c
    {
        uint8_t faron_tear_count;
        uint8_t eldin_tear_count;
        uint8_t lanayru_tear_count;
        uint8_t unk3;
        uint8_t light_drop_flag;
        uint8_t unk5[3];
    } __attribute__( ( __packed__ ) );

    struct dSv_letter_info_c
    {
        uint32_t letter_get_bitfields[2];
        uint32_t letter_read_bitfields[2];
        uint8_t padding[64];
    } __attribute__( ( __packed__ ) );

    struct dSv_fishing_info_c
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
    } __attribute__( ( __packed__ ) );

    struct dSv_player_info_c
    {
        uint32_t unk0;
        uint32_t unk4;
        uint64_t mTotalTime;
        uint16_t unk16;
        uint16_t mDeathCount;
        uint8_t mPlayerName[16];
        uint8_t unk36;
        uint8_t mHorseName[16];
        uint8_t unk53;
        uint8_t mClearCount;
        uint8_t unk55[5];
        uint8_t padding60[4];
    } __attribute__( ( __packed__ ) );

    struct dSv_player_config_c
    {
        uint8_t unk0;
        uint8_t sound_mode;           // 0 is Mono. 1 is Stereo. 2 is Surround.
        uint8_t target_mode;          // 0 is Hold. 1 is Switch.
        uint8_t vibration_on_off;     // 0 is Off. 1 is On
        uint8_t motion_controls;      // 0 is On. 1 is Off.
        uint8_t brightness_level;     // 1 is darkest. 6 is brightest.
        uint16_t unk6;
        uint8_t unk8;
        uint8_t unk9;
        uint8_t camera_aiming_options;     // Default is 8. |80 is third person aiming. |8 inverts the vertical swiming axis. |4
                                           // inverts horizontal swimming axis. |2 inverts vertical camera axis. |1 inverts
                                           // horizontal axis.
        uint8_t unk11;
    } __attribute__( ( __packed__ ) );

    struct dSv_zoneBit_c
    {
        uint8_t unk0[4];
        uint16_t room_switch;
        uint16_t unk6[2];
        uint16_t room_item;
        uint16_t unk12;
    } __attribute__( ( __packed__ ) );

    struct dSv_zoneActor_c
    {
        uint32_t unk0[4];
    } __attribute__( ( __packed__ ) );

    struct dSv_zone_c
    {
        uint8_t unk0;
        uint8_t unk1;
        dSv_zoneBit_c zone_bit;
        dSv_zoneActor_c zone_actor;
    } __attribute__( ( __packed__ ) );

    struct dSv_memBit_c
    {
        uint32_t area_flags_bitfields1[2];
        uint32_t area_flags_bitfields2[4];
        uint32_t rupee_flags_bitfields;
        uint8_t small_keys;
        uint8_t dungeon_flags;
        uint8_t padding[2];
    } __attribute__( ( __packed__ ) );

    struct dSv_memory_c
    {
        dSv_memBit_c temp_flags;
    } __attribute__( ( __packed__ ) );

    struct dSv_player_c
    {
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
    } __attribute__( ( __packed__ ) );

    struct dSv_save_c
    {
        dSv_player_c player;
        uint8_t field_0x1ec[4];
        dSv_memory_c area_flags[32];
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
    } __attribute__( ( __packed__ ) );

    struct dSv_info_c
    {
        dSv_save_c save_file;               // ScratchPad 0 - 957
        dSv_memory_c memory;                // Local Area Nodes 958 - 977
        dSv_danBit_c dungeon_bit;           // 978 - 9B3
        dSv_zone_c zones[32];               // 9B4 - DB3
        dSv_restart_c restart;              // DB4 - DD7
        dSv_event_c events;                 // DD8 - ED7
        dSv_turnRestart_c turn_restart;     // ED8 - EEA
        uint8_t unk1[0x3D];                 // EEB - F27
        uint32_t saveTotalTime;             // F28
        uint32_t saveStartTime;             // F2C
        uint32_t unkF30;                    // F30
        uint32_t unkF34;                    // F34
    } __attribute__( ( __packed__ ) );

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
        void getSave( dSv_info_c* gameInfoPtr, int32_t areaID );

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
        void putSave( dSv_info_c* gameInfoPtr, int32_t areaID );

        /**
         *  @brief Sets an eventBit for the currently active save
         *
         *  @param eventPtr The pointer to the event bits.
         *  @param flag Offset+Flag
         */

        void onEventBit( dSv_event_c* eventPtr, uint16_t flag );

        /**
         *  @brief Unsets an eventBit for the currently active save
         *
         *  @param eventPtr The pointer to the event bits.
         *  @param flag Offset+Flag
         */
        void offEventBit( dSv_event_c* eventPtr, uint16_t flag );

        /**
         *  @brief Checks whether the player has cleared the specified twilight.
         *
         *  @param playerStatusPtr The pointer to the PlayerStatus struct.
         *  @param twilightNode The twilight instance to be checked.
         */
        bool isDarkClearLV( void* playerStatusPtr, int32_t twilightNode );

        /**
         *  @brief Checks whether or not Link has been transformed into wolf by a twilight CS
         *
         *  @param playerStatusPtr The pointer to the PlayerStatus struct.
         *  @param twilightEvent The twilight cutscene event to be checked.
         */
        bool isTransformLV( void* playerStatusPtr, int32_t twilightEvent );

        extern uint16_t saveBitLabels[0x336];     // saveBitLabels__16dSv_event_flag_c
    }
}     // namespace libtp::tp::d_save
#endif