/**	@file flags.h
 *  @brief Constants and definitions of various flags throughout the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef LIBTP_FLAGS_H
#define LIBTP_FLAGS_H

#include <cstdint>

namespace libtp::data::flags
{
    enum EventFlags : uint16_t
    {
        Cheese_put_in_soup = 0x0001,
        Pumpkin_put_in_soup = 0x0002,
        Lost_to_Gor_Coron_in_sumo = 0x0004,
        Talked_to_Renado_after_Goron_Mines = 0x0008,
        Yeto_took_cheese = 0x0010,
        Yeto_took_pumpkin = 0x0020,
        unk0040 = 0x0040,
        Midna_text_about_finding_Gorge_bridge = 0x0080,
        unk0101 = 0x0101,
        unk0102 = 0x0102,
        Talked_to_Colin_outside_Links_house = 0x0104,
        unk0108 = 0x0108,
        Talked_to_Fado_before_Goats_1 = 0x0110,
        Told_Yeta_about_cheese = 0x0120,
        Talked_to_Yeto_in_SPR_for_first_time = 0x0140,
        Can_fight_Twilight_Bloat = 0x0180,
        Talked_to_Sera_before_cat_rescued = 0x0201,
        Talked_to_Colin_through_spring_gate = 0x0202,
        unk0204 = 0x0204,
        unk0208 = 0x0208,
        unk0210 = 0x0210,
        Finished_slingshot_training = 0x0220,
        Finished_sword_training = 0x0240,
        Failed_to_catch_goat_at_Bo_house = 0x0280,
        Got_fishing_rod_from_Uli = 0x0301,
        Gave_wooden_sword_to_Talo = 0x0302,
        Brought_cradle_to_Uli = 0x0304,
        Talked_to_kids_outside_Links_house = 0x0308,
        Jaggle_asked_to_look_up_pillar = 0x0310,
        unk0320 = 0x0320,
        Talked_to_Pergie = 0x0340,
        Talked_to_squirrel_after_Faron_Twilight = 0x0380,
        unk0401 = 0x0401,
        unk0402 = 0x0402,
        Talked_to_Uli = 0x0404,
        Uli_ran_down_river = 0x0408,
        Talked_to_Uli_before_getting_cradle = 0x0410,
        unk0420 = 0x0420,
        Refused_sword_training = 0x0440,
        Told_yeta_about_pumpkin = 0x0480,
        Midna_charge_unlocked = 0x0501,
        Finished_sewers = 0x0502,
        Midna_text_after_entering_faron_twilight = 0x0504,
        Met_Zelda_in_sewers = 0x0508,
        Midna_cut_prison_chain = 0x0510,
        Watched_sewers_intro_cutscene = 0x0520,
        Escaped_cell_in_sewers = 0x0540,
        Entered_Ordon_spring_Day_3 = 0x0580,
    };
}     // namespace libtp::data::flags
#endif