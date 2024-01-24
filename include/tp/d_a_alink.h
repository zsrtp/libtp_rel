/**	@file d_a_alink.h
 *	@brief Holds definitions about the d_a_alink field
 *
 *	The d_a_alink field holds various functions and variables about Link
 *	and his current state
 *
 *	@author AECX
 *	@author Zephiles
 *	@author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_A_ALINK_H
#define TP_D_A_ALINK_H

#include <cstdint>
#include "tp/J3DAnimation.h"
#include "tp/f_op_actor.h"
#include "tp/d_a_player.h"
#include "tp/d_msg_flow.h"
#include "tp/J3DAnimation.h"
#include "tp/J3DShape.h"
#include "SSystem/SComponent/c_phase.h"
#include "tp/J3DModel.h"
#include "tp/m_do_ext.h"

namespace libtp::tp::d_a_alink
{
    enum daAlink_PROC
    {
        /* 0x000 */ PROC_PREACTION_UNEQUIP,
        /* 0x001 */ PROC_SERVICE_WAIT,
        /* 0x002 */ PROC_TIRED_WAIT,
        /* 0x003 */ PROC_WAIT,
        /* 0x004 */ PROC_MOVE,
        /* 0x005 */ PROC_ATN_MOVE,
        /* 0x006 */ PROC_ATN_ACTOR_WAIT,
        /* 0x007 */ PROC_ATN_ACTOR_MOVE,
        /* 0x008 */ PROC_WAIT_TURN,
        /* 0x009 */ PROC_MOVE_TURN,
        /* 0x00A */ PROC_SIDESTEP,
        /* 0x00B */ PROC_SIDESTEP_LAND,
        /* 0x00C */ PROC_SLIDE,
        /* 0x00D */ PROC_SLIDE_LAND,
        /* 0x00E */ PROC_FRONT_ROLL,
        /* 0x00F */ PROC_FRONT_ROLL_CRASH,
        /* 0x010 */ PROC_FRONT_ROLL_SUCCESS,
        /* 0x011 */ PROC_SIDE_ROLL,
        /* 0x012 */ PROC_BACK_JUMP,
        /* 0x013 */ PROC_BACK_JUMP_LAND,
        /* 0x014 */ PROC_SLIP,
        /* 0x015 */ PROC_AUTO_JUMP,
        /* 0x016 */ PROC_DIVE_JUMP,
        /* 0x017 */ PROC_ROLL_JUMP,
        /* 0x018 */ PROC_FALL,
        /* 0x019 */ PROC_LAND,
        /* 0x01A */ PROC_SMALL_JUMP,
        /* 0x01B */ PROC_STEP_MOVE,
        /* 0x01C */ PROC_CROUCH,
        /* 0x01D */ PROC_GUARD_SLIP,
        /* 0x01E */ PROC_GUARD_ATTACK,
        /* 0x01F */ PROC_GUARD_BREAK,
        /* 0x020 */ PROC_TURN_MOVE,
        /* 0x021 */ PROC_CUT_NORMAL,
        /* 0x022 */ PROC_CUT_FINISH,
        /* 0x023 */ PROC_CUT_FINISH_JUMP_UP,
        /* 0x024 */ PROC_CUT_FINISH_JUMP_UP_LAND,
        /* 0x025 */ PROC_CUT_REVERSE,
        /* 0x026 */ PROC_CUT_JUMP,
        /* 0x027 */ PROC_CUT_JUMP_LAND,
        /* 0x028 */ PROC_CUT_TURN,
        /* 0x029 */ PROC_CUT_TURN_CHARGE,
        /* 0x02A */ PROC_CUT_TURN_MOVE,
        /* 0x02B */ PROC_CUT_DOWN,
        /* 0x02C */ PROC_CUT_DOWN_LAND,
        /* 0x02D */ PROC_CUT_HEAD,
        /* 0x02E */ PROC_CUT_HEAD_LAND,
        /* 0x02F */ PROC_CUT_LARGE_JUMP_CHARGE,
        /* 0x030 */ PROC_CUT_LARGE_JUMP,
        /* 0x031 */ PROC_CUT_LARGE_JUMP_LAND,
        /* 0x032 */ PROC_DAMAGE,
        /* 0x033 */ PROC_LARGE_DAMAGE_UP,
        /* 0x034 */ PROC_LAND_DAMAGE,
        /* 0x035 */ PROC_CRAWL_START,
        /* 0x036 */ PROC_CRAWL_MOVE,
        /* 0x037 */ PROC_CRAWL_AUTO_MOVE,
        /* 0x038 */ PROC_CRAWL_END,
        /* 0x039 */ PROC_PULL_MOVE,
        /* 0x03A */ PROC_HORSE_RIDE,
        /* 0x03B */ PROC_HORSE_GETOFF,
        /* 0x03C */ PROC_HORSE_WAIT,
        /* 0x03D */ PROC_HORSE_TURN,
        /* 0x03E */ PROC_HORSE_JUMP,
        /* 0x03F */ PROC_HORSE_LAND,
        /* 0x040 */ PROC_HORSE_SUBJECTIVITY,
        /* 0x041 */ PROC_HORSE_CUT,
        /* 0x042 */ PROC_HORSE_CUT_CHARGE_READY,
        /* 0x043 */ PROC_HORSE_CUT_TURN,
        /* 0x044 */ PROC_HORSE_DAMAGE,
        /* 0x045 */ PROC_HORSE_BOW_SUBJECT,
        /* 0x046 */ PROC_HORSE_BOW_MOVE,
        /* 0x047 */ PROC_HORSE_GRAB_MOVE,
        /* 0x048 */ PROC_HORSE_BOOMERANG_SUBJECT,
        /* 0x049 */ PROC_HORSE_BOOMERANG_MOVE,
        /* 0x04A */ PROC_HORSE_HOOKSHOT_SUBJECT,
        /* 0x04B */ PROC_HORSE_HOOKSHOT_MOVE,
        /* 0x04C */ PROC_HORSE_BOTTLE_DRINK,
        /* 0x04D */ PROC_HORSE_COMEBACK,
        /* 0x04E */ PROC_HORSE_KANDELAAR_POUR,
        /* 0x04F */ PROC_HORSE_RUN,
        /* 0x050 */ PROC_HORSE_HANG,
        /* 0x051 */ PROC_HORSE_GET_KEY,
        /* 0x052 */ PROC_HORSE_LOOK_DOWN,
        /* 0x053 */ PROC_BOAR_RUN,
        /* 0x054 */ PROC_SWORD_UNEQUIP_SP,
        /* 0x055 */ PROC_HANG_START,
        /* 0x056 */ PROC_HANG_FALL_START,
        /* 0x057 */ PROC_HANG_UP,
        /* 0x058 */ PROC_HANG_WAIT,
        /* 0x059 */ PROC_HANG_MOVE,
        /* 0x05A */ PROC_HANG_CLIMB,
        /* 0x05B */ PROC_HANG_WALL_CATCH,
        /* 0x05C */ PROC_HANG_READY,
        /* 0x05D */ PROC_HANG_LEVER_DOWN,
        /* 0x05E */ PROC_BOW_SUBJECT,
        /* 0x05F */ PROC_BOW_MOVE,
        /* 0x060 */ PROC_BOOMERANG_SUBJECT,
        /* 0x061 */ PROC_BOOMERANG_MOVE,
        /* 0x062 */ PROC_BOOMERANG_CATCH,
        /* 0x063 */ PROC_COPY_ROD_SUBJECT,
        /* 0x064 */ PROC_COPY_ROD_MOVE,
        /* 0x065 */ PROC_COPY_ROD_SWING,
        /* 0x066 */ PROC_COPY_ROD_REVIVE,
        /* 0x067 */ PROC_LADDER_UP_START,
        /* 0x068 */ PROC_LADDER_UP_END,
        /* 0x069 */ PROC_LADDER_DOWN_START,
        /* 0x06A */ PROC_LADDER_DOWN_END,
        /* 0x06B */ PROC_LADDER_MOVE,
        /* 0x06C */ PROC_GRAB_READY,
        /* 0x06D */ PROC_GRAB_UP,
        /* 0x06E */ PROC_GRAB_MISS,
        /* 0x06F */ PROC_GRAB_THROW,
        /* 0x070 */ PROC_GRAB_PUT,
        /* 0x071 */ PROC_GRAB_WAIT,
        /* 0x072 */ PROC_GRAB_REBOUND,
        /* 0x073 */ PROC_GRAB_STAND,
        /* 0x074 */ PROC_INSECT_CATCH,
        /* 0x075 */ PROC_PICK_UP,
        /* 0x076 */ PROC_PICK_PUT,
        /* 0x077 */ PROC_HUMAN_ST_ESCAPE,
        /* 0x078 */ PROC_DK_CAUGHT,
        /* 0x079 */ PROC_SWIM_UP,
        /* 0x07A */ PROC_SWIM_WAIT,
        /* 0x07B */ PROC_SWIM_MOVE,
        /* 0x07C */ PROC_SWIM_DIVE,
        /* 0x07D */ PROC_SWIM_HOOKSHOT_SUBJECT,
        /* 0x07E */ PROC_SWIM_HOOKSHOT_MOVE,
        /* 0x07F */ PROC_SWIM_DAMAGE,
        /* 0x080 */ PROC_CLIMB_UP_START,
        /* 0x081 */ PROC_CLIMB_DOWN_START,
        /* 0x082 */ PROC_CLIMB_MOVE_UPDOWN,
        /* 0x083 */ PROC_CLIMB_MOVE_SIDE,
        /* 0x084 */ PROC_CLIMB_WAIT,
        /* 0x085 */ PROC_CLIMB_TO_ROOF,
        /* 0x086 */ PROC_ROOF_HANG_START,
        /* 0x087 */ PROC_ROOF_HANG_WAIT,
        /* 0x088 */ PROC_ROOF_HANG_FRONT_MOVE,
        /* 0x089 */ PROC_ROOF_HANG_SIDE_MOVE,
        /* 0x08A */ PROC_ROOF_HANG_TURN,
        /* 0x08B */ PROC_ROOF_SWITCH_HANG,
        /* 0x08C */ PROC_CANOE_RIDE,
        /* 0x08D */ PROC_CANOE_JUMP_RIDE,
        /* 0x08E */ PROC_CANOE_GETOFF,
        /* 0x08F */ PROC_CANOE_WAIT,
        /* 0x090 */ PROC_CANOE_ROW,
        /* 0x091 */ PROC_CANOE_PADDLE_SHIFT,
        /* 0x092 */ PROC_CANOE_PADDLE_PUT,
        /* 0x093 */ PROC_CANOE_PADDLE_GRAB,
        /* 0x094 */ PROC_CANOE_ROD_GRAB,
        /* 0x095 */ PROC_CANOE_FISHING_WAIT,
        /* 0x096 */ PROC_CANOE_FISHING_REEL,
        /* 0x097 */ PROC_CANOE_FISHING_GET,
        /* 0x098 */ PROC_CANOE_SUBJECTIVITY,
        /* 0x099 */ PROC_CANOE_BOW_SUBJECT,
        /* 0x09A */ PROC_CANOE_BOW_MOVE,
        /* 0x09B */ PROC_CANOE_GRAB_MOVE,
        /* 0x09C */ PROC_CANOE_BOOMERANG_SUBJECT,
        /* 0x09D */ PROC_CANOE_BOOMERANG_MOVE,
        /* 0x09E */ PROC_CANOE_HOOKSHOT_SUBJECT,
        /* 0x09F */ PROC_CANOE_HOOKSHOT_MOVE,
        /* 0x0A0 */ PROC_CANOE_BOTTLE_DRINK,
        /* 0x0A1 */ PROC_CANOE_KANDELAAR_POUR,
        /* 0x0A2 */ PROC_FISHING_CAST,
        /* 0x0A3 */ PROC_FISHING_FOOD,
        /* 0x0A4 */ PROC_SPINNER_READY,
        /* 0x0A5 */ PROC_SPINNER_WAIT,
        /* 0x0A6 */ PROC_BOARD_RIDE,
        /* 0x0A7 */ PROC_BOARD_WAIT,
        /* 0x0A8 */ PROC_BOARD_ROW,
        /* 0x0A9 */ PROC_BOARD_TURN,
        /* 0x0AA */ PROC_BOARD_JUMP,
        /* 0x0AB */ PROC_BOARD_SUBJECTIVITY,
        /* 0x0AC */ PROC_BOARD_CUT,
        /* 0x0AD */ PROC_BOARD_CUT_TURN,
        /* 0x0AE */ PROC_CHAIN_UP,
        /* 0x0AF */ PROC_CHAIN_STRONG_PULL,
        /* 0x0B0 */ PROC_DOOR_OPEN,
        /* 0x0B1 */ PROC_MONKEY_MOVE,
        /* 0x0B2 */ PROC_DEMO_BOOMERANG_CATCH,
        /* 0x0B3 */ PROC_BOTTLE_DRINK,
        /* 0x0B4 */ PROC_BOTTLE_OPEN,
        /* 0x0B5 */ PROC_BOTTLE_SWING,
        /* 0x0B6 */ PROC_BOTTLE_GET,
        /* 0x0B7 */ PROC_KANDELAAR_SWING,
        /* 0x0B8 */ PROC_KANDELAAR_POUR,
        /* 0x0B9 */ PROC_GRASS_WHISTLE_GET,
        /* 0x0BA */ PROC_GRASS_WHISTLE_WAIT,
        /* 0x0BB */ PROC_HAWK_CATCH,
        /* 0x0BC */ PROC_HAWK_SUBJECT,
        /* 0x0BD */ PROC_FLOOR_DOWN_REBOUND,
        /* 0x0BE */ PROC_GORON_RIDE_WAIT,
        /* 0x0BF */ PROC_GOAT_MOVE,
        /* 0x0C0 */ PROC_GOAT_CATCH,
        /* 0x0C1 */ PROC_GOAT_STROKE,
        /* 0x0C2 */ PROC_GORON_MOVE,
        /* 0x0C3 */ PROC_BOSS_ATN_WAIT,
        /* 0x0C4 */ PROC_HOOKSHOT_SUBJECT,
        /* 0x0C5 */ PROC_HOOKSHOT_MOVE,
        /* 0x0C6 */ PROC_HOOKSHOT_FLY,
        /* 0x0C7 */ PROC_HOOKSHOT_ROOF_WAIT,
        /* 0x0C8 */ PROC_HOOKSHOT_ROOF_SHOOT,
        /* 0x0C9 */ PROC_HOOKSHOT_ROOF_BOOTS,
        /* 0x0CA */ PROC_HOOKSHOT_WALL_WAIT,
        /* 0x0CB */ PROC_HOOKSHOT_WALL_SHOOT,
        /* 0x0CC */ PROC_MAGNE_BOOTS_FLY,
        /* 0x0CD */ PROC_BOOTS_EQUIP,
        /* 0x0CE */ PROC_SUMOU_READY,
        /* 0x0CF */ PROC_SUMOU_MOVE,
        /* 0x0D0 */ PROC_SUMOU_SIDE_MOVE,
        /* 0x0D1 */ PROC_SUMOU_ACTION,
        /* 0x0D2 */ PROC_SUMOU_STAGGER,
        /* 0x0D3 */ PROC_SUMOU_WIN_LOSE,
        /* 0x0D4 */ PROC_SUMOU_SHIKO,
        /* 0x0D5 */ PROC_LOOK_UP,
        /* 0x0D6 */ PROC_LOOK_UP_TO_GET_ITEM,
        /* 0x0D7 */ PROC_HAND_PAT,
        /* 0x0D8 */ PROC_IRON_BALL_SUBJECT,
        /* 0x0D9 */ PROC_IRON_BALL_MOVE,
        /* 0x0DA */ PROC_IRON_BALL_THROW,
        /* 0x0DB */ PROC_IRON_BALL_RETURN,
        /* 0x0DC */ PROC_BOSS_BODY_HANG,
        /* 0x0DD */ PROC_OCTAIEAL_SPIT,
        /* 0x0DE */ PROC_SCREAM_WAIT,
        /* 0x0DF */ PROC_GOAT_STOP_READY,
        /* 0x0E0 */ PROC_ZORA_MOVE,
        /* 0x0E1 */ PROC_LOOK_AROUND_TURN,
        /* 0x0E2 */ PROC_TRADE_ITEM_OUT,
        /* 0x0E3 */ PROC_NOT_USE_ITEM,
        /* 0x0E4 */ PROC_SWORD_READY,
        /* 0x0E5 */ PROC_SWORD_PUSH,
        /* 0x0E6 */ PROC_GANON_FINISH,
        /* 0x0E7 */ PROC_CUT_FAST_READY,
        /* 0x0E8 */ PROC_MASTER_SWORD_STICK,
        /* 0x0E9 */ PROC_MASTER_SWORD_PULL,
        /* 0x0EA */ PROC_DUNGEON_WARP_READY,
        /* 0x0EB */ PROC_DUNGEON_WARP,
        /* 0x0EC */ PROC_DUNGEON_WARP_SCN_START,
        /* 0x0ED */ PROC_WOLF_HOWL_DEMO,
        /* 0x0EE */ PROC_WOLF_SERVICE_WAIT,
        /* 0x0EF */ PROC_WOLF_TIRED_WAIT,
        /* 0x0F0 */ PROC_WOLF_MIDNA_RIDE_SHOCK,
        /* 0x0F1 */ PROC_WOLF_WAIT,
        /* 0x0F2 */ PROC_WOLF_MOVE,
        /* 0x0F3 */ PROC_WOLF_DASH,
        /* 0x0F4 */ PROC_WOLF_DASH_REVERSE,
        /* 0x0F5 */ PROC_WOLF_WAIT_TURN,
        /* 0x0F6 */ PROC_WOLF_ATN_AC_MOVE,
        /* 0x0F7 */ PROC_WOLF_SIDESTEP,
        /* 0x0F8 */ PROC_WOLF_SIDESTEP_LAND,
        /* 0x0F9 */ PROC_WOLF_BACKJUMP,
        /* 0x0FA */ PROC_WOLF_BACKJUMP_LAND,
        /* 0x0FB */ PROC_WOLF_HOWL,
        /* 0x0FC */ PROC_WOLF_AUTO_JUMP,
        /* 0x0FD */ PROC_WOLF_FALL,
        /* 0x0FE */ PROC_WOLF_LAND,
        /* 0x0FF */ PROC_WOLF_SIT,
        /* 0x100 */ PROC_WOLF_LIE_START,
        /* 0x101 */ PROC_WOLF_LIE_MOVE,
        /* 0x102 */ PROC_WOLF_LIE_AUTO_MOVE,
        /* 0x103 */ PROC_WOLF_HANG_READY,
        /* 0x104 */ PROC_WOLF_STEP_MOVE,
        /* 0x105 */ PROC_WOLF_HANG_WALL_CATCH,
        /* 0x106 */ PROC_WOLF_HANG_FALL_START,
        /* 0x107 */ PROC_WOLF_DAMAGE,
        /* 0x108 */ PROC_WOLF_LARGE_DAMAGE_UP,
        /* 0x109 */ PROC_WOLF_LAND_DAMAGE,
        /* 0x10A */ PROC_WOLF_SCREAM_WAIT,
        /* 0x10B */ PROC_WOLF_SLIP,
        /* 0x10C */ PROC_WOLF_SLIP_TURN,
        /* 0x10D */ PROC_WOLF_SLIP_TURN_LAND,
        /* 0x10E */ PROC_WOLF_SLIDE_READY,
        /* 0x10F */ PROC_WOLF_SLIDE,
        /* 0x110 */ PROC_WOLF_SLIDE_LAND,
        /* 0x111 */ PROC_WOLF_WAIT_SLIP,
        /* 0x112 */ PROC_WOLF_SLOPE_START,
        /* 0x113 */ PROC_WOLF_ROPE_MOVE,
        /* 0x114 */ PROC_WOLF_ROPE_HANG,
        /* 0x115 */ PROC_WOLF_ROPE_TURN,
        /* 0x116 */ PROC_WOLF_ROPE_STAGGER,
        /* 0x117 */ PROC_WOLF_ROPE_SUBJECTIVITY,
        /* 0x118 */ PROC_WOLF_TAG_JUMP,
        /* 0x119 */ PROC_WOLF_TAG_JUMP_LAND,
        /* 0x11A */ PROC_WOLF_ROLL_ATTACK_CHARGE,
        /* 0x11B */ PROC_WOLF_ROLL_ATTACK_MOVE,
        /* 0x11C */ PROC_WOLF_JUMP_ATTACK,
        /* 0x11D */ PROC_WOLF_JUMP_AT_KICK,
        /* 0x11E */ PROC_WOLF_JUMP_AT_SLIDE_LAND,
        /* 0x11F */ PROC_WOLF_JUMP_AT_NORMAL_LAND,
        /* 0x120 */ PROC_WOLF_WAIT_ATTACK,
        /* 0x121 */ PROC_WOLF_ROLL_ATTACK,
        /* 0x122 */ PROC_WOLF_DOWN_ATTACK,
        /* 0x123 */ PROC_WOLF_DOWN_AT_LAND,
        /* 0x124 */ PROC_WOLF_DOWN_AT_MISS_LAND,
        /* 0x125 */ PROC_WOLF_LOCK_ATTACK,
        /* 0x126 */ PROC_WOLF_LOCK_ATTACK_TURN,
        /* 0x127 */ PROC_WOLF_SWIM_UP,
        /* 0x128 */ PROC_WOLF_SWIM_WAIT,
        /* 0x129 */ PROC_WOLF_SWIM_MOVE,
        /* 0x12A */ PROC_WOLF_SWIM_END_WAIT,
        /* 0x12B */ PROC_WOLF_GRAB_UP,
        /* 0x12C */ PROC_WOLF_GRAB_PUT,
        /* 0x12D */ PROC_WOLF_GRAB_THROW,
        /* 0x12E */ PROC_WOLF_CHAIN_UP,
        /* 0x12F */ PROC_WOLF_PUSH,
        /* 0x130 */ PROC_WOLF_CHAIN_READY,
        /* 0x131 */ PROC_WOLF_CHAIN_WAIT,
        /* 0x132 */ PROC_WOLF_DIG,
        /* 0x133 */ PROC_WOLF_DIG_THROUGH,
        /* 0x134 */ PROC_WOLF_ATTACK_REVERSE,
        /* 0x135 */ PROC_WOLF_ENEMY_THROW,
        /* 0x136 */ PROC_WOLF_ENEMY_HANG_BITE,
        /* 0x137 */ PROC_WOLF_GIANT_PUZZLE,
        /* 0x138 */ PROC_WOLF_CARGO_CARRY,
        /* 0x139 */ PROC_WOLF_GET_SMELL,
        /* 0x13A */ PROC_WOLF_SMELL_WAIT,
        /* 0x13B */ PROC_WOLF_SNOW_ESCAPE,
        /* 0x13C */ PROC_WOLF_GANON_CATCH,
        /* 0x13D */ PROC_TOOL_DEMO,
        /* 0x13E */ PROC_SUBJECTIVITY,
        /* 0x13F */ PROC_SWIM_SUBJECTIVITY,
        /* 0x140 */ PROC_PEEP_SUBJECTIVITY,
        /* 0x141 */ PROC_POLY_DAMAGE,
        /* 0x142 */ PROC_ELEC_DAMAGE,
        /* 0x143 */ PROC_PUSH_PULL_WAIT,
        /* 0x144 */ PROC_PUSH_MOVE,
        /* 0x145 */ PROC_TALK,
        /* 0x146 */ PROC_OPEN_TREASURE,
        /* 0x147 */ PROC_UNEQUIP,
        /* 0x148 */ PROC_GET_ITEM,
        /* 0x149 */ PROC_TURN_BACK,
        /* 0x14A */ PROC_LOOK_WAIT,
        /* 0x14B */ PROC_DEMO_PUSH_PULL_WAIT,
        /* 0x14C */ PROC_DEMO_PUSH_MOVE,
        /* 0x14D */ PROC_METAMORPHOSE,
        /* 0x14E */ PROC_METAMORPHOSE_ONLY,
        /* 0x14F */ PROC_WARP,
        /* 0x150 */ PROC_DEAD,
        /* 0x151 */ PROC_FOG_DEAD,
        /* 0x152 */ PROC_LOOK_AROUND,
        /* 0x153 */ PROC_CAUGHT,
        /* 0x154 */ PROC_SAND_WALL_HIT,
        /* 0x155 */ PROC_LAVA_RETURN,
        /* 0x156 */ PROC_SWIM_FREEZE_RETURN,
        /* 0x157 */ PROC_GET_READY_SIT,
        /* 0x158 */ PROC_TW_GATE,
        /* 0x159 */ PROC_LARGE_DAMAGE,
        /* 0x15A */ PROC_LARGE_DAMAGE_WALL,
        /* 0x15B */ PROC_NOD,
        /* 0x15C */ PROC_EYE_AWAY,
        /* 0x15D */ PROC_GLARE,
        /* 0x15E */ PROC_HORSE_CALL_WAIT,
        /* 0x15F */ PROC_QUAKE_WAIT,
    };
    struct daAlink_footData
    {
        /* 0x00 */ uint8_t field_0x00[2];
        /* 0x02 */ uint16_t field_0x2;
        /* 0x04 */ uint16_t field_0x4;
        /* 0x06 */ uint16_t field_0x6;
        /* 0x08 */ cXyz field_0x8;
        /* 0x14 */ uint8_t field_0x14[0x30]; // Mtx
        /* 0x44 */ uint8_t field_0x44[0x30]; // Mtx
        /* 0x74 */ uint8_t field_0x74[0x30]; // Mtx
    } __attribute__((__packed__));

    struct daAlink: libtp::tp::d_a_player::daPy_py
    {
        /* 0x0062C */ request_of_phase_process_class mPhaseReq;
        /* 0x00634 */ char* mArcName;
        /* 0x00638 */ void* field_0x0638; // JKRExpHeap*
        /* 0x0063C */ request_of_phase_process_class mShieldPhaseReq;
        /* 0x00644 */ char* mShieldArcName;
        /* 0x00648 */ void* field_0x0648; // JKRExpHeap*
        /* 0x0064C */ void* field_0x064C; // J3DModelData*
        /* 0x00650 */ libtp::tp::J3DModel::J3DModel* mpLinkModel;
        /* 0x00654 */ libtp::tp::J3DModel::J3DModel* mpLinkFaceModel;
        /* 0x00658 */ libtp::tp::J3DModel::J3DModel* mpLinkHatModel;
        /* 0x0065C */ libtp::tp::J3DModel::J3DModel* mpLinkHandModel;
        /* 0x00660 */ libtp::tp::J3DModel::J3DModel* mpSwAModel;       // Ordon Sword model
        /* 0x00664 */ libtp::tp::J3DModel::J3DModel* mpSwASheathModel; // Ordon Sword sheath model
        /* 0x00668 */ libtp::tp::J3DModel::J3DModel* mpSwMModel;       // Master Sword model
        /* 0x0066C */ libtp::tp::J3DModel::J3DModel* mpSwMSheathModel; // Master Sword sheath model
        /* 0x00670 */ libtp::tp::J3DModel::J3DModel* mWoodSwordModel;
        /* 0x00674 */ libtp::tp::J3DModel::J3DModel* mpWlChangeModel;
        /* 0x00678 */ libtp::tp::J3DModel::J3DModel* mShieldModel;
        /* 0x0067C */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mMagicArmorBodyBrk;
        /* 0x00680 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mMagicArmorHeadBrk;
        /* 0x00684 */ libtp::tp::J3DModel::J3DModel* mpDemoFCBlendModel;
        /* 0x00688 */ libtp::tp::J3DModel::J3DModel* mpDemoFCTongueModel;
        /* 0x0068C */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* field_0x068c;
        /* 0x00690 */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoFCTmpBck;
        /* 0x00694 */ void* mpDemoFCTmpBls; // J3DDeformData*
        /* 0x00698 */ libtp::tp::J3DAnimation::J3DAnmCluster* field_0x0698;
        /* 0x0069C */ void* field_0x069c; // mDoExt_blkAnm*
        /* 0x006A0 */ libtp::tp::J3DModel::J3DModel* mpDemoHLTmpModel;
        /* 0x006A4 */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoHLTmpBck;
        /* 0x006A8 */ libtp::tp::J3DModel::J3DModel* mpDemoHRTmpModel;
        /* 0x006AC */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoHRTmpBck;
        /* 0x006B0 */ libtp::tp::m_Do_ext::mDoExt_bckAnm* mpDemoHDTmpBck;
        /* 0x006B4 */ libtp::tp::J3DAnimation::J3DAnmTransform* field_0x06b4;
        /* 0x006B8 */ libtp::tp::J3DModel::J3DModel* mSwordModel;
        /* 0x006BC */ libtp::tp::J3DModel::J3DModel* mSheathModel;
        /* 0x006C0 */ void* field_0x06c0; // J3DModelData*
        /* 0x006C4 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* m_nSwordBtk;
        /* 0x006C8 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* m_mSwordBtk;
        /* 0x006CC */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* m_mSwordBrk;
        /* 0x006D0 */ libtp::tp::J3DShape::J3DShape* field_0x06d0;
        /* 0x006D4 */ libtp::tp::J3DShape::J3DShape* field_0x06d4;
        /* 0x006D8 */ libtp::tp::J3DShape::J3DShape* field_0x06d8;
        /* 0x006DC */ libtp::tp::J3DShape::J3DShape* field_0x06dc;
        /* 0x006E0 */ libtp::tp::J3DShape::J3DShape* field_0x06e0;
        /* 0x006E4 */ libtp::tp::J3DShape::J3DShape* field_0x06e4;
        /* 0x006E8 */ libtp::tp::J3DShape::J3DShape* field_0x06e8;
        /* 0x006EC */ libtp::tp::J3DShape::J3DShape* field_0x06ec;
        /* 0x006F0 */ libtp::tp::J3DShape::J3DShape* field_0x06f0;
        /* 0x006F4 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* field_0x06f4;
        /* 0x006F8 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* field_0x06f8;
        /* 0x006FC */ libtp::tp::J3DModel::J3DModel* mpKanteraModel;
        /* 0x00700 */ libtp::tp::J3DModel::J3DModel* mpKanteraGlowModel;
        /* 0x00704 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpKanteraGlowBtk;
        /* 0x00708 */ libtp::tp::J3DModel::J3DModel* mHeldItemModel;
        /* 0x0070C */ libtp::tp::J3DModel::J3DModel* mpHookTipModel; // related to held item
        /* 0x00710 */ libtp::tp::J3DModel::J3DModel* field_0x0710;   // related to held item
        /* 0x00714 */ libtp::tp::J3DModel::J3DModel* field_0x0714;   // related to held item
        /* 0x00718 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* field_0x0718;
        /* 0x0071C */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* field_0x071c;
        /* 0x00720 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* field_0x0720;
        /* 0x00724 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* field_0x0724;
        /* 0x00728 */ libtp::tp::J3DAnimation::J3DAnmBase* field_0x0728;
        /* 0x0072C */ libtp::tp::J3DAnimation::J3DAnmTexPattern* field_0x072c;
        /* 0x00730 */ libtp::tp::m_Do_ext::mDoExt_bckAnm mItemBck;
        /* 0x0074C */ libtp::tp::m_Do_ext::mDoExt_bckAnm mHookTipBck;
        /* 0x00768 */ void* mpHookKusariModelData; // J3DModelData
        /* 0x0076C */ void* mpHookSound;           // Z2SoundObjSimple
        /* 0x00770 */ void* mpHookChain;           // hsChainShape_c
        /* 0x00774 */ uint8_t field_0x0774[0x8];
        /* 0x0077C */ void* mpHookshotLinChk; // dBgS_ObjLinChk
        /* 0x00780 */ uint8_t field_0x780[4];
        /* 0x00784 */ libtp::tp::J3DModel::J3DModel* mpLinkBootModels[2];
        /* 0x0078C */ libtp::tp::J3DModel::J3DModel* mpWlChainModels[4];
        /* 0x0079C */ libtp::tp::J3DModel::J3DModel* mpWlMidnaModel;
        /* 0x007A0 */ libtp::tp::J3DModel::J3DModel* mpWlMidnaMaskModel;
        /* 0x007A4 */ libtp::tp::J3DModel::J3DModel* mpWlMidnaHandModel;
        /* 0x007A8 */ libtp::tp::J3DModel::J3DModel* mpWlMidnaHairModel;
        /* 0x007AC */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpDMidnaBrk;
        /* 0x007B0 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpDMidnaMaskBrk;
        /* 0x007B4 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpDMidnaHandBrk;
        /* 0x007B8 */ libtp::tp::J3DAnimation::J3DAnmTevRegKey* mpDMidnaHairHandBrk;
        /* 0x007BC */ libtp::tp::m_Do_ext::mDoExt_bckAnm* m_sWindowBck;
        /* 0x007C0 */ uint32_t mpWarpTexData;
        /* 0x007C4 */ libtp::tp::d_a_player::daPy_actorKeep mWolfLockAcKeep[10];
        /* 0x00814 */ uint8_t field_0x814[0x3C];      // dCcD_Stts
        /* 0x00850 */ uint8_t field_0x850[0x3B4];     // dCcD_Cyl field_0x850[3];
        /* 0x00C04 */ uint8_t field_0xC04[0x3B4];     // dCcD_Cyl field_0xC04[3];
        /* 0x00FB8 */ uint8_t field_0xFB8[0x138];     // dCcD_Sph
        /* 0x010F0 */ uint8_t mAtCyl[0x13C];          // dCcD_Cyl
        /* 0x0122C */ uint8_t mAtCps[0x3CC];          // dCcD_Cps mAtCps[3];
        /* 0x015F8 */ uint8_t mGuardAtCps[0x144];     // dCcD_Cps
        /* 0x0173C */ uint8_t field_0x173c[0x3C];     // related to ball and chain - dCcD_Stts
        /* 0x01778 */ uint8_t field_0x1778[0x138];    // dCcD_Sph
        /* 0x018B0 */ uint8_t field_0x18B0[0xC0];     // dBgS_AcchCir field_0x18B0[3];
        /* 0x01970 */ uint8_t mLinkAcch[0x1D8];       // dBgS_LinkAcch
        /* 0x01B48 */ uint8_t mLinkLinChk[0x70];      // dBgS_LinkLinChk
        /* 0x01BB8 */ uint8_t mRopeLinChk[0x70];      // dBgS_RopeLinChk
        /* 0x01C28 */ uint8_t mBoomerangLinChk[0x70]; // dBgS_BoomerangLinChk
        /* 0x01C98 */ uint8_t mArrowLinChk[0x70];     // dBgS_ArrowLinChk
        /* 0x01D08 */ uint8_t mLinkGndChk[0x54];      // dBgS_LinkGndChk
        /* 0x01D5C */ uint8_t mLinkRoofChk[0x50];     // dBgS_LinkRoofChk
        /* 0x01DAC */ uint8_t mMagneLineChk[0x70];    // dBgS_LinkLinChk
        /* 0x01E1C */ uint8_t mPolyInfo1[0x10];       // cBgS_PolyInfo
        /* 0x01E2C */ uint8_t mPolyInfo2[0x10];       // cBgS_PolyInfo
        /* 0x01E3C */ uint8_t mPolyInfo3[0x10];       // cBgS_PolyInfo
        /* 0x01E4C */ uint8_t mPolyInfo4[0x10];       // cBgS_PolyInfo
        /* 0x01E5C */ uint8_t mObjLinChk[0x70];       // dBgS_ObjLinChk
        /* 0x01ECC */ uint8_t mObjGndChk[0x54];       // dBgS_ObjGndChk
        /* 0x01F20 */ void* field_0x1f20;             // mDoExt_MtxCalcAnmBlendTbl*
        /* 0x01F24 */ void* field_0x1f24;             // mDoExt_MtxCalcAnmBlendTblOld*
        /* 0x01F28 */ libtp::tp::m_Do_ext::mDoExt_AnmRatioPack mNowAnmPackUnder[3];
        /* 0x01F40 */ libtp::tp::m_Do_ext::mDoExt_AnmRatioPack mNowAnmPackUpper[3];
        /* 0x01F58 */ libtp::tp::d_a_player::daPy_anmHeap mUnderAnmHeap[3];
        /* 0x01F94 */ libtp::tp::d_a_player::daPy_anmHeap mUpperAnmHeap[3];
        /* 0x01FD0 */ uint8_t mUnderFrameCtrl[0x48]; // daPy_frameCtrl_c mUnderFrameCtrl[3];
        /* 0x02018 */ uint8_t mUpperFrameCtrl[0x48]; // daPy_frameCtrl_c mUpperFrameCtrl[3];
        /* 0x02060 */ void* field_0x2060;            // mDoExt_MtxCalcOldFrame*
        /* 0x02064 */ uint8_t mSight[0x8C];          // daAlink_sight_c
        /* 0x020F0 */ libtp::tp::d_a_player::daPy_anmHeap mAnmHeap3;
        /* 0x02104 */ libtp::tp::d_a_player::daPy_anmHeap mAnmHeap4;
        /* 0x02118 */ libtp::tp::d_a_player::daPy_anmHeap mFaceBtpHeap;
        /* 0x0212C */ libtp::tp::d_a_player::daPy_anmHeap mFaceBtkHeap;
        /* 0x02140 */ libtp::tp::d_a_player::daPy_anmHeap mFaceBckHeap;
        /* 0x02154 */ libtp::tp::J3DAnimation::J3DAnmTexPattern* field_0x2154;
        /* 0x02158 */ libtp::tp::J3DAnimation::J3DAnmTextureSRTKey* mpFaceBtk;
        /* 0x0215C */ void* field_0x215c; // daPy_frameCtrl_c*
        /* 0x02160 */ int8_t* field_0x2160;
        /* 0x02164 */ libtp::tp::m_Do_ext::mDoExt_bckAnm field_0x2164;
        /* 0x02180 */ void* field_0x2180[2]; // daAlink_matAnm_c*
        /* 0x02188 */ uint8_t mEyeHL1[0x14]; // dEyeHL_c
        /* 0x0219C */ uint8_t mEyeHL2[0x14]; // dEyeHL_c
        /* 0x021B0 */ libtp::tp::d_a_player::daPy_anmHeap mItemHeap[2];
        /* 0x021D8 */ libtp::tp::d_a_player::daPy_anmHeap mAnmHeap9;
        /* 0x021EC */ void* mpHIO;                // daAlinkHIO_c*
        /* 0x021F0 */ uint8_t m_swordBlur[0x5D8]; // daAlink_blur_c
        /* 0x027C8 */ uint8_t field_0x27c8[0x18]; // dAlink_bottleWaterPcallBack_c
        /* 0x027E0 */ void* mAttention;           // dAttention_c*
        /* 0x027E4 */ void* mAttList;             // dAttList_c
        /* 0x027E8 */ void* mAttList2;            // dAttList_c*
        /* 0x027EC */ fopAc_ac_c* mTargetedActor;
        /* 0x027F0 */ fopAc_ac_c* field_0x27f0;
        /* 0x027F4 */ fopAc_ac_c* field_0x27f4;
        /* 0x027F8 */ fopAc_ac_c* field_0x27f8;
        /* 0x027FC */ fopAc_ac_c* field_0x27fc;
        /* 0x02800 */ void* mMidnaMsg; // daTagMmsg_c*
        /* 0x02804 */ fopAc_ac_c* field_0x2804;
        /* 0x02808 */ void* mpScnChg; // daScex_c*
        /* 0x0280C */ libtp::tp::d_a_player::daPy_actorKeep field_0x280c;
        /* 0x02814 */ libtp::tp::d_a_player::daPy_actorKeep mRideAcKeep;
        /* 0x0281C */ libtp::tp::d_a_player::daPy_actorKeep field_0x281c;
        /* 0x02824 */ libtp::tp::d_a_player::daPy_actorKeep mItemAcKeep;
        /* 0x0282C */ libtp::tp::d_a_player::daPy_actorKeep mGrabItemAcKeep;
        /* 0x02834 */ libtp::tp::d_a_player::daPy_actorKeep mThrowBoomerangAcKeep;
        /* 0x0283C */ libtp::tp::d_a_player::daPy_actorKeep mCopyRodAcKeep;
        /* 0x02844 */ libtp::tp::d_a_player::daPy_actorKeep field_0x2844;
        /* 0x0284C */ libtp::tp::d_a_player::daPy_actorKeep mHookTargetAcKeep;
        /* 0x02854 */ libtp::tp::d_a_player::daPy_actorKeep mCargoCarryAcKeep;
        /* 0x0285C */ libtp::tp::d_a_player::daPy_actorKeep field_0x285c;
        /* 0x02864 */ libtp::tp::d_msg_flow::dMsgFlow mMsgFlow;
        /* 0x028B0 */ int32_t field_0x28b0[0x10];
        /* 0x028F0 */ uint32_t mMsgClassID;
        /* 0x028F4 */ int32_t mAtnActorID;
        /* 0x028F8 */ int32_t field_0x28f8;
        /* 0x028FC */ int32_t field_0x28fc;
        /* 0x02900 */ uint32_t field_0x2900;
        /* 0x02904 */ uint8_t mFootData1[0x148]; // daAlink_footData_c mFootData1[2];
        /* 0x02A4C */ uint8_t mFootData2[0x148]; // daAlink_footData_c mFootData2[2];
        /* 0x02B94 */ float* field_0x2b94;
        /* 0x02B98 */ float field_0x2b98;
        /* 0x02B9C */ float field_0x2b9c;
        /* 0x02BA0 */ float* field_0x2ba0;
        /* 0x02BA4 */ float field_0x2ba4;
        /* 0x02BA8 */ float mSinkShapeOffset;
        /* 0x02BAC */ float field_0x2bac[3];
        /* 0x02BB8 */ uint8_t mInvMtx[0x30];          // Mtx
        /* 0x02BE8 */ uint8_t field_0x2be8[0x30];     // Mtx
        /* 0x02C18 */ uint8_t mRootMtx[0x30];         // Mtx
        /* 0x02C48 */ uint8_t mMagneBootMtx[0x30];    // Mtx
        /* 0x02C78 */ uint8_t mMagneBootInvMtx[0x30]; // Mtx
        /* 0x02CA8 */ uint8_t mZ2Link[0xD0];          // Z2CreatureLink
        /* 0x02D78 */ void* field_0x2d78;
        /* 0x02D7C */ void* field_0x2d7c; // daPy_frameCtrl_c*
        /* 0x02D80 */ int32_t field_0x2d80;
        /* 0x02D84 */ uint8_t mZ2WolfHowlMgr[0xC0]; // Z2WolfHowlMgr
        /* 0x02E44 */ uint8_t field_0x2e44[0x10];   // dJntCol_c
        /* 0x02E54 */ uint8_t field_0x2e54[0xC8];   // dPaPoF_c
        /* 0x02F1C */ void* field_0x2f1c;           // dPaPo_c*
        /* 0x02F20 */ uint8_t field_0x2f20[0x18];   // dPa_hermiteEcallBack_c
        /* 0x02F38 */ uint8_t field_0x2f38[0x18];   // dPa_hermiteEcallBack_c
        /* 0x02F50 */ const Vec* field_0x2f50;
        /* 0x02F54 */ const Vec* field_0x2f54;
        /* 0x02F58 */ uint16_t* field_0x2f58;
        /* 0x02F5C */ uint8_t field_0x2f5c[0x20]; // LIGHT_INFLUENCE
        /* 0x02F7C */ uint8_t field_0x2f7c[0x10];
        /* 0x02F8C */ uint8_t field_0x2f8c;
        /* 0x02F8D */ uint8_t mItemTrigger;
        /* 0x02F8E */ uint8_t mItemButton;
        /* 0x02F8F */ uint8_t field_0x2f8f;
        /* 0x02F90 */ uint8_t field_0x2f90;
        /* 0x02F91 */ uint8_t field_0x2f91;
        /* 0x02F92 */ uint8_t field_0x2f92;
        /* 0x02F93 */ uint8_t field_0x2f93;
        /* 0x02F94 */ uint8_t field_0x2f94;
        /* 0x02F95 */ uint8_t field_0x2f95;
        /* 0x02F96 */ uint8_t field_0x2f96;
        /* 0x02F97 */ uint8_t field_0x2f97;
        /* 0x02F98 */ uint8_t field_0x2f98;
        /* 0x02F99 */ uint8_t field_0x2f99;
        /* 0x02F9A */ int8_t mVoiceReverbIntensity;
        /* 0x02F9B */ uint8_t field_0x2f9b;
        /* 0x02F9C */ uint8_t mSelectItemId;
        /* 0x02F9D */ uint8_t field_0x2f9d;
        /* 0x02F9E */ uint8_t field_0x2f9e;
        /* 0x02F9F */ uint8_t field_0x2f9f;
        /* 0x02FA0 */ uint8_t field_0x2fa0;
        /* 0x02FA1 */ uint8_t mRunCutComboCount;
        /* 0x02FA2 */ uint8_t mActiveBombNum;
        /* 0x02FA3 */ uint8_t field_0x2fa3;
        /* 0x02FA4 */ uint8_t mRollCrashFlg;
        /* 0x02FA5 */ uint8_t mPolySound;
        /* 0x02FA6 */ uint8_t field_0x2fa6;
        /* 0x02FA7 */ uint8_t field_0x2fa7;
        /* 0x02FA8 */ uint8_t field_0x2fa8;
        /* 0x02FA9 */ uint8_t mWolfEyeUpTimer;
        /* 0x02FAA */ uint8_t mRideStatus;
        /* 0x02FAB */ uint8_t field_0x2fab;
        /* 0x02FAC */ uint8_t mExitDirection;
        /* 0x02FAD */ uint8_t mPeepExitID;
        /* 0x02FAE */ uint8_t field_0x2fae;
        /* 0x02FAF */ uint8_t field_0x2faf;
        /* 0x02FB0 */ uint8_t field_0x2fb0;
        /* 0x02FB1 */ uint8_t mWolfLockNum;
        /* 0x02FB2 */ uint8_t mMidnaTalkDelayTimer;
        /* 0x02FB3 */ uint8_t field_0x2fb3;
        /* 0x02FB4 */ uint8_t field_0x2fb4;
        /* 0x02FB5 */ uint8_t mDamageColorTime;
        /* 0x02FB6 */ uint8_t field_0x2fb6;
        /* 0x02FB7 */ uint8_t field_0x2fb7;
        /* 0x02FB8 */ uint8_t field_0x2fb8;
        /* 0x02FB9 */ uint8_t field_0x2fb9;
        /* 0x02FBA */ uint8_t mHotspringRecoverTimer;
        /* 0x02FBB */ uint8_t field_0x2fbb;
        /* 0x02FBC */ uint8_t field_0x2fbc;
        /* 0x02FBD */ uint8_t field_0x2fbd;
        /* 0x02FBE */ uint8_t field_0x2fbe;
        /* 0x02FBF */ uint8_t mClothesChangeWaitTimer;
        /* 0x02FC0 */ uint8_t field_0x2fc0;
        /* 0x02FC1 */ uint8_t field_0x2fc1;
        /* 0x02FC2 */ uint8_t field_0x2fc2;
        /* 0x02FC3 */ uint8_t field_0x2fc3;
        /* 0x02FC4 */ uint8_t field_0x2fc4;
        /* 0x02FC5 */ uint8_t field_0x2fc5;
        /* 0x02FC6 */ uint8_t field_0x2fc6;
        /* 0x02FC7 */ uint8_t field_0x2fc7;
        /* 0x02FC8 */ uint8_t field_0x2fc8;
        /* 0x02FC9 */ uint8_t field_0x2fc9;
        /* 0x02FCA */ uint8_t field_0x2fca;
        /* 0x02FCB */ uint8_t field_0x2fcb;
        /* 0x02FCC */ uint8_t field_0x2fcc;
        /* 0x02FCD */ uint8_t field_0x2fcd;
        /* 0x02FCE */ uint8_t field_0x2fce;
        /* 0x02FCF */ uint8_t field_0x2fcf;
        /* 0x02FD0 */ uint8_t field_0x2fd0;
        /* 0x02FD1 */ uint8_t mShieldChangeWaitTimer;
        /* 0x02FD2 */ uint8_t field_0x2fd2;
        /* 0x02FD3 */ uint8_t field_0x2fd3;
        /* 0x02FD4 */ uint8_t field_0x2fd4;
        /* 0x02FD5 */ uint8_t field_0x2fd5;
        /* 0x02FD6 */ uint8_t mSwordChangeWaitTimer;
        /* 0x02FD7 */ uint8_t field_0x2fd7;
        /* 0x02FD8 */ uint8_t field_0x2fd8;
        /* 0x02FD9 */ uint8_t field_0x2fd9[3];
        /* 0x02FDC */ uint16_t mEquipItem;
        /* 0x02FDE */ uint16_t field_0x2fde;
        /* 0x02FE0 */ int16_t mStickAngle;
        /* 0x02FE2 */ int16_t field_0x2fe2; // related to current stick angle
        /* 0x02FE4 */ int16_t field_0x2fe4;
        /* 0x02FE6 */ int16_t field_0x2fe6;
        /* 0x02FE8 */ uint16_t mProcID;
        /* 0x02FEA */ uint16_t field_0x2fea;
        /* 0x02FEC */ int16_t field_0x2fec;
        /* 0x02FEE */ int16_t field_0x2fee;
        /* 0x02FF0 */ int16_t field_0x2ff0;
        /* 0x02FF2 */ int16_t field_0x2ff2;
        /* 0x02FF4 */ int16_t field_0x2ff4;
        /* 0x02FF6 */ int16_t field_0x2ff6;
        /* 0x02FF8 */ int16_t field_0x2ff8;
        /* 0x02FFA */ int16_t field_0x2ffa;
        /* 0x02FFC */ int16_t field_0x2ffc;
        /* 0x02FFE */ int16_t field_0x2ffe;
        /* 0x03000 */ int16_t field_0x3000;
        /* 0x03002 */ int16_t field_0x3002;
        /* 0x03004 */ int16_t field_0x3004;
        /* 0x03006 */ int16_t field_0x3006;
        // `mProcVar`'s are variables that are context dependent for each `PROC` action.
        // (The exact setup may need to be simplified later)
        union
        {
            /* 0x03008 */ int16_t field_0x3008;
            /* 0x03008 */ int16_t mHowlExitID;
        } mProcVar0;
        union
        {
            /* 0x0300A */ int16_t field_0x300a;
        } mProcVar1;
        union
        {
            /* 0x0300C */ int16_t field_0x300c;
            /* 0x0300C */ int16_t mPuzzleAimAngle;
        } mProcVar2;
        union
        {
            /* 0x0300E */ csXyz field_0x300e;
        } mProcVar3;
        /* 0x03014 */ int16_t mFallVoiceInit;
        /* 0x03016 */ uint8_t field_0x3016[2];
        union
        {
            /* 0x03018 */ int16_t field_0x3018;
            /* 0x03018 */ int16_t mBottleItemHealAmount;
        } mItemVar0;
        /* 0x0301A */ int16_t mItemMode;
        /* 0x0301C */ int16_t field_0x301c;
        /* 0x0301E */ int16_t field_0x301e;
        /* 0x03020 */ int16_t field_0x3020;
        /* 0x03022 */ int16_t field_0x3022;
        /* 0x03024 */ int16_t field_0x3024;
        /* 0x03026 */ int16_t field_0x3026;
        /* 0x03028 */ int16_t field_0x3028;
        /* 0x0302A */ uint8_t field_0x302a[2];
        /* 0x0302C */ int16_t field_0x302c[0xA];
        /* 0x03040 */ int16_t field_0x3040[0xA];
        /* 0x03054 */ int16_t field_0x3054[3];
        /* 0x0305A */ int16_t field_0x305a[3];
        /* 0x03060 */ int16_t field_0x3060;
        /* 0x03062 */ int16_t field_0x3062;
        /* 0x03064 */ int16_t field_0x3064;
        /* 0x03066 */ int16_t field_0x3066;
        /* 0x03068 */ uint8_t field_0x3068[4];
        /* 0x0306C */ int16_t field_0x306c;
        /* 0x0306E */ int16_t field_0x306e;
        /* 0x03070 */ int16_t field_0x3070;
        /* 0x03072 */ int16_t field_0x3072;
        /* 0x03074 */ int16_t field_0x3074;
        /* 0x03076 */ int16_t field_0x3076;
        /* 0x03078 */ int16_t field_0x3078;
        /* 0x0307A */ int16_t mStickSpinTimer;
        /* 0x0307C */ int16_t mPrevStickAngle;
        /* 0x0307E */ int16_t field_0x307e;
        /* 0x03080 */ int16_t field_0x3080;
        /* 0x03082 */ int16_t field_0x3082;
        /* 0x03084 */ uint16_t field_0x3084;
        /* 0x03086 */ uint16_t field_0x3086;
        /* 0x03088 */ int16_t field_0x3088;
        /* 0x0308A */ int16_t field_0x308a;
        /* 0x0308C */ int16_t field_0x308c;
        /* 0x0308E */ int16_t mFastShotTime;
        /* 0x03090 */ int16_t field_0x3090;
        /* 0x03092 */ int16_t field_0x3092;
        /* 0x03094 */ int16_t field_0x3094[3];
        /* 0x0309A */ int16_t field_0x309a[3];
        /* 0x030A0 */ int16_t field_0x30a0;
        /* 0x030A2 */ int16_t field_0x30a2;
        /* 0x030A4 */ int16_t field_0x30a4;
        /* 0x030A6 */ int16_t field_0x30a6;
        /* 0x030A8 */ uint16_t field_0x30a8;
        /* 0x030AA */ uint16_t field_0x30aa;
        /* 0x030AC */ int16_t mWolfEyeUp;
        /* 0x030AE */ uint16_t field_0x30ae;
        /* 0x030B0 */ int16_t field_0x30b0;
        /* 0x030B2 */ int16_t field_0x30b2;
        /* 0x030B4 */ uint16_t field_0x30b4;
        /* 0x030B6 */ uint16_t field_0x30b6;
        /* 0x030B8 */ uint16_t field_0x30b8;
        /* 0x030BA */ uint16_t field_0x30ba;
        /* 0x030BC */ uint16_t field_0x30bc;
        /* 0x030BE */ uint16_t field_0x30be;
        /* 0x030C0 */ uint16_t field_0x30c0;
        /* 0x030C2 */ uint16_t field_0x30c2;
        /* 0x030C4 */ uint16_t field_0x30c4;
        /* 0x030C6 */ uint16_t field_0x30c6;
        /* 0x030C8 */ int16_t field_0x30c8;
        /* 0x030CA */ int16_t field_0x30ca;
        /* 0x030CC */ int16_t field_0x30cc;
        /* 0x030CE */ uint16_t mKeepItem;
        /* 0x030D0 */ int16_t field_0x30d0;
        /* 0x030D2 */ int16_t field_0x30d2;
        /* 0x030D4 */ uint16_t field_0x30d4;
        /* 0x030D6 */ int16_t field_0x30d6;
        /* 0x030D8 */ uint8_t field_0x30d8[0x14];
        /* 0x030EC */ int16_t field_0x30ec;
        /* 0x030EE */ int16_t field_0x30ee;
        /* 0x030F0 */ uint16_t field_0x30f0;
        /* 0x030F2 */ uint8_t field_0x30f2[2];
        /* 0x030F4 */ int16_t mSwordFlourishTimer;
        /* 0x030F6 */ int16_t field_0x30f6;
        /* 0x030F8 */ int16_t field_0x30f8;
        /* 0x030FA */ int16_t field_0x30fa;
        /* 0x030FC */ uint16_t field_0x30fc;
        /* 0x030FE */ uint16_t field_0x30fe;
        /* 0x03100 */ int16_t field_0x3100;
        /* 0x03102 */ int16_t field_0x3102;
        /* 0x03104 */ int16_t field_0x3104;
        /* 0x03106 */ uint16_t field_0x3106;
        /* 0x03108 */ int16_t field_0x3108;
        /* 0x0310A */ int16_t field_0x310a;
        /* 0x0310C */ int16_t field_0x310c;
        /* 0x0310E */ int16_t field_0x310e;
        /* 0x03110 */ int16_t field_0x3110;
        /* 0x03112 */ uint16_t mExitID;
        /* 0x03114 */ int16_t field_0x3114;
        /* 0x03116 */ int16_t field_0x3116;
        /* 0x03118 */ int16_t field_0x3118;
        /* 0x0311A */ int16_t field_0x311a;
        /* 0x0311C */ int16_t field_0x311c;
        /* 0x0311E */ int16_t field_0x311e;
        /* 0x03120 */ uint16_t mMidnaMsgNum;
        /* 0x03122 */ int16_t field_0x3122;
        /* 0x03124 */ int16_t field_0x3124;
        /* 0x03126 */ int16_t field_0x3126;
        /* 0x03128 */ int16_t field_0x3128;
        /* 0x0312A */ csXyz field_0x312a[2];
        /* 0x03136 */ csXyz field_0x3136[2];
        /* 0x03142 */ csXyz field_0x3142[4];
        /* 0x0315A */ csXyz mFishingArm1Angle;
        /* 0x03160 */ csXyz field_0x3160;
        /* 0x03166 */ csXyz field_0x3166;
        /* 0x0316C */ csXyz field_0x316c;
        /* 0x03172 */ uint8_t field_0x3172[2];
        /* 0x03174 */ int32_t field_0x3174;
        /* 0x03178 */ int32_t field_0x3178;
        /* 0x0317C */ int32_t field_0x317c;
        /* 0x03180 */ int32_t field_0x3180;
        /* 0x03184 */ int32_t field_0x3184;
        /* 0x03188 */ int32_t field_0x3188;
        /* 0x0318C */ int32_t field_0x318c;
        /* 0x03190 */ int32_t field_0x3190;
        /* 0x03194 */ int32_t field_0x3194;
        /* 0x03198 */ int32_t field_0x3198;
        /* 0x0319C */ int32_t field_0x319c;
        /* 0x031A0 */ uint32_t mModeFlg;
        /* 0x031A4 */ int32_t field_0x31a4;
        /* 0x031A8 */ uint8_t field_0x31a8[8];
        /* 0x031B0 */ int32_t field_0x31b0;
        /* 0x031B4 */ uint8_t field_0x31b4[8];
        /* 0x031BC */ uint32_t field_0x31bc;
        /* 0x031C0 */ uint32_t field_0x31c0;
        /* 0x031C4 */ uint32_t field_0x31c4;
        /* 0x031C8 */ uint32_t field_0x31c8;
        /* 0x031CC */ uint32_t field_0x31cc;
        /* 0x031D0 */ uint32_t field_0x31d0;
        /* 0x031D4 */ uint32_t field_0x31d4;
        /* 0x031D8 */ uint8_t field_0x31d8[12];
        /* 0x031E4 */ uint32_t field_0x31e4;
        /* 0x031E8 */ uint8_t field_0x31e8[16];
        /* 0x031F8 */ uint32_t field_0x31f8;
        /* 0x031FC */ uint32_t field_0x31fc;
        /* 0x03200 */ uint32_t field_0x3200;
        /* 0x03204 */ uint32_t field_0x3204;
        /* 0x03208 */ uint32_t field_0x3208;
        /* 0x0320C */ uint8_t field_0x320c[16];
        /* 0x0321C */ uint32_t field_0x321c;
        /* 0x03220 */ uint32_t field_0x3220;
        /* 0x03224 */ uint32_t field_0x3224;
        /* 0x03228 */ uint32_t field_0x3228[2][3];
        /* 0x03240 */ uint32_t field_0x3240[6];
        /* 0x03258 */ uint32_t field_0x3258;
        /* 0x0325C */ uint32_t field_0x325c;
        /* 0x03260 */ uint32_t field_0x3260[2];
        /* 0x03268 */ uint8_t field_0x3268[0x20];
        /* 0x03288 */ uint32_t field_0x3288;
        /* 0x0328C */ uint32_t field_0x328c;
        /* 0x03290 */ uint32_t field_0x3290;
        /* 0x03294 */ uint32_t field_0x3294;
        /* 0x03298 */ uint8_t field_0x3298[8];
        /* 0x032A0 */ uint8_t field_0x32a0[0x10]; // J3DGXColorS10 field_0x32a0[2];
        /* 0x032B0 */ uint8_t field_0x32b0[0x10]; // J3DGXColorS10 field_0x32b0[2];
        /* 0x032C0 */ int16_t field_0x32c0[2];
        /* 0x032C4 */ uint16_t field_0x32c4;
        /* 0x032C6 */ uint16_t field_0x32c6;
        /* 0x032C8 */ uint32_t field_0x32c8;
        /* 0x032CC */ uint32_t field_0x32cc;
        /* 0x032D0 */ uint32_t field_0x32d0;
        /* 0x032D4 */ uint32_t field_0x32d4;
        /* 0x032D8 */ uint8_t field_0x32d8[0xC0]; // firePointEff_c field_0x32d8[4];
        /* 0x03398 */ float mNormalSpeed;
        /* 0x0339C */ float mSpeedModifier;
        /* 0x033A0 */ float field_0x33a0;
        /* 0x033A4 */ float field_0x33a4;
        /* 0x033A8 */ float field_0x33a8;
        /* 0x033AC */ float field_0x33ac;
        /* 0x033B0 */ float field_0x33b0;
        /* 0x033B4 */ float mWaterY;
        /* 0x033B8 */ float field_0x33b8;
        /* 0x033BC */ float field_0x33bc;
        /* 0x033C0 */ float field_0x33c0;
        /* 0x033C4 */ float mFallHeight;
        /* 0x033C8 */ float field_0x33c8;
        /* 0x033CC */ float field_0x33cc;
        /* 0x033D0 */ float field_0x33d0;
        /* 0x033D4 */ float field_0x33d4;
        /* 0x033D8 */ float field_0x33d8;
        /* 0x033DC */ float field_0x33dc;
        /* 0x033E0 */ float field_0x33e0;
        /* 0x033E4 */ float field_0x33e4;
        /* 0x033E8 */ float field_0x33e8;
        /* 0x033EC */ float field_0x33ec;
        /* 0x033F0 */ float field_0x33f0;
        /* 0x033F4 */ float field_0x33f4;
        /* 0x033F8 */ float field_0x33f8;
        /* 0x033FC */ float field_0x33fc;
        /* 0x03400 */ float field_0x3400;
        /* 0x03404 */ float field_0x3404;
        /* 0x03408 */ float field_0x3408;
        /* 0x0340C */ float field_0x340c;
        /* 0x03410 */ float field_0x3410;
        /* 0x03414 */ float field_0x3414;
        /* 0x03418 */ float field_0x3418;
        /* 0x0341C */ float field_0x341c;
        /* 0x03420 */ float field_0x3420;
        /* 0x03424 */ float field_0x3424;
        /* 0x03428 */ float field_0x3428;
        /* 0x0342C */ float field_0x342c;
        /* 0x03430 */ float field_0x3430;
        /* 0x03434 */ float mHeavySpeedMultiplier;
        /* 0x03438 */ float field_0x3438;
        /* 0x0343C */ float field_0x343c;
        /* 0x03440 */ float field_0x3440;
        /* 0x03444 */ float field_0x3444;
        /* 0x03448 */ float field_0x3448;
        /* 0x0344C */ float field_0x344c;
        /* 0x03450 */ uint8_t field_0x3450[4];
        /* 0x03454 */ float field_0x3454;
        /* 0x03458 */ float field_0x3458;
        /* 0x0345C */ float field_0x345c;
        /* 0x03460 */ float field_0x3460;
        /* 0x03464 */ float field_0x3464;
        /* 0x03468 */ float field_0x3468;
        /* 0x0346C */ float field_0x346c;
        /* 0x03470 */ float field_0x3470;
        /* 0x03474 */ float mSwordUpColorIntensity;
        /* 0x03478 */ float field_0x3478;
        /* 0x0347C */ float field_0x347c;
        /* 0x03480 */ float field_0x3480;
        /* 0x03484 */ float field_0x3484;
        /* 0x03488 */ float field_0x3488;
        /* 0x0348C */ float field_0x348c;
        /* 0x03490 */ float mSearchBallScale;
        /* 0x03494 */ float field_0x3494;
        /* 0x03498 */ cXyz field_0x3498;
        /* 0x034A4 */ cXyz field_0x34a4;
        /* 0x034B0 */ cXyz field_0x34b0;
        /* 0x034BC */ cXyz field_0x34bc;
        /* 0x034C8 */ cXyz field_0x34c8;
        /* 0x034D4 */ cXyz field_0x34d4;
        /* 0x034E0 */ cXyz field_0x34e0;
        /* 0x034EC */ cXyz field_0x34ec;
        /* 0x034F8 */ cXyz mLastJumpPos;
        /* 0x03504 */ cXyz field_0x3504;
        /* 0x03510 */ cXyz field_0x3510;
        /* 0x0351C */ cXyz field_0x351c;
        /* 0x03528 */ cXyz field_0x3528;
        /* 0x03534 */ cXyz field_0x3534;
        /* 0x03540 */ cXyz field_0x3540;
        /* 0x0354C */ cXyz field_0x354c[4];
        /* 0x0357C */ cXyz mLookPosFromOut;
        /* 0x03588 */ cXyz field_0x3588;
        /* 0x03594 */ cXyz field_0x3594;
        /* 0x035A0 */ cXyz field_0x35a0;
        /* 0x035AC */ cXyz field_0x35ac;
        /* 0x035B8 */ cXyz field_0x35b8;
        /* 0x035C4 */ cXyz field_0x35c4;
        /* 0x035D0 */ cXyz field_0x35d0;
        /* 0x035DC */ cXyz field_0x35dc;
        /* 0x035E8 */ cXyz field_0x35e8;
        /* 0x035F4 */ cXyz mMidnaAtnPos;
        /* 0x03600 */ cXyz field_0x3600;
        /* 0x0360C */ cXyz mKandelaarFlamePos;
        /* 0x03618 */ cXyz field_0x3618;
        /* 0x03624 */ cXyz field_0x3624;
        /* 0x03630 */ cXyz field_0x3630;
        /* 0x0363C */ cXyz field_0x363c[4];
        /* 0x0366C */ cXyz field_0x366c[4];
        /* 0x0369C */ cXyz field_0x369c;
        /* 0x036A8 */ cXyz mMagneBootsTopVec;
        /* 0x036B4 */ cXyz field_0x36b4;
        /* 0x036C0 */ cXyz field_0x36c0[4];
        /* 0x036F0 */ cXyz field_0x36f0[4];
        /* 0x03720 */ cXyz field_0x3720;
        /* 0x0372C */ cXyz field_0x372c;
        /* 0x03738 */ cXyz field_0x3738;
        /* 0x03744 */ cXyz field_0x3744;
        /* 0x03750 */ cXyz field_0x3750;
        /* 0x0375C */ cXyz field_0x375c;
        /* 0x03768 */ cXyz field_0x3768;
        /* 0x03774 */ cXyz mForcePutPos;
        /* 0x03780 */ cXyz field_0x3780;
        /* 0x0378C */ cXyz field_0x378c;
        /* 0x03798 */ cXyz field_0x3798;
        /* 0x037A4 */ cXyz field_0x37a4;
        /* 0x037B0 */ cXyz field_0x37b0[2];
        /* 0x037C8 */ cXyz field_0x37c8;
        /* 0x037D4 */ cXyz field_0x37d4;
        /* 0x037E0 */ cXyz mHeldItemRootPos;
        /* 0x037EC */ cXyz mHookshotTopPos;
        /* 0x037F8 */ cXyz mIronBallCenterPos;
        /* 0x03804 */ cXyz mIronBallBgChkPos;
        /* 0x03810 */ cXyz field_0x3810;
        /* 0x0381C */ cXyz field_0x381c;
        /* 0x03828 */ cXyz field_0x3828;
        /* 0x03834 */ cXyz field_0x3834;
        /* 0x03840 */ cXyz* mIronBallChainPos;
        /* 0x03844 */ csXyz* mIronBallChainAngle;
        /* 0x03848 */ void* field_0x3848;
        /* 0x0384C */ cXyz* field_0x384c;
        /* 0x03850 */ uint8_t mpProcFunc[0xC]; // daAlink_procFunc
    } __attribute__((__packed__));

    /**
     *	@brief These values define the speed of various climbing actions
     *
     *	@todo Fill missing vars.
     */
    struct ClimbVars
    {
        uint8_t unk_0[0x28];
        float ladderClimbInitSpeed;
        uint8_t unk_2c[0x4];
        float ladderReachTopClimbUpSpeed;
        uint8_t unk_30[0x4];
        float ladderTopStartClimbDownSpeed;
        uint8_t unk_34[0x4];
        float ladderBottomGetOffSpeed;
        uint8_t unk_38[0x8];
        float ladderClimbSpeed;
        uint8_t unk_40[0x10];
        float wallClimbHorizontalSpeed;
        uint8_t unk_58[0x4];
        float wallClimbVerticalSpeed;
        uint8_t unk_5c[0x4];
    } __attribute__((__packed__));

    struct daAlinkHIO_anm_c
    {
        /* 0x00 */ int16_t field_0x00; // end f?
        /* 0x02 */ uint16_t padding_0x02;
        /* 0x04 */ float field_0x04; // speed?
        /* 0x08 */ float field_0x08; // start?
        /* 0x0C */ float field_0x0c; // interpolation?
        /* 0x10 */ float field_0x10; // CF?
    } __attribute__((__packed__));   // size = 0x14

    struct WallMoveVars
    {
        float moveSidewaysStickNotHeld; // default = 0.8
        float movesidewaysStickHeld;    // default = 1.1
        uint8_t unk[0xC];
    } __attribute__((__packed__));

    struct daAlinkHIO_huLight_c0
    {
        uint32_t unk_0;
        uint16_t lanternAmbienceR;
        uint16_t lanternAmbienceG;
        uint16_t lanternAmbienceB;
        uint8_t unk_A[0x12];
    } __attribute__((__packed__));

    struct daAlinkHIO_kandelaar_c0
    {
        /* 0x00 */ daAlinkHIO_anm_c mShakeAnm;
        /* 0x14 */ daAlinkHIO_anm_c mBeginUnkAnm;
        /* 0x28 */ daAlinkHIO_anm_c mEndUnkAnm;
        /* 0x3C */ uint16_t innerSphereR;
        /* 0x3E */ uint16_t innerSphereG;
        /* 0x40 */ uint16_t innerSphereB;
        /* 0x42 */ uint16_t outerSphereR;
        /* 0x44 */ uint16_t outerSphereG;
        /* 0x46 */ uint16_t outerSphereB;
        /* 0x48 */ uint16_t mNormalOilLoss;
        /* 0x4A */ uint16_t mShakeOilLoss;
        /* 0x4C */ float mFlameTrackRate;

    } __attribute__((__packed__));

    struct daAlinkHIO_magneBoots_c0
    {
        uint8_t unk_0[0x14];
        float heavyStateSpeed;
        uint8_t unk_18[0x34];

    } __attribute__((__packed__));

    static_assert(sizeof(daAlink) == 0x385C);
    static_assert(sizeof(daAlink_footData) == 0xA4);
    static_assert(sizeof(ClimbVars) == 0x70);
    static_assert(sizeof(daAlinkHIO_kandelaar_c0) == 0x50);
    static_assert(sizeof(daAlinkHIO_magneBoots_c0) == 0x4C);
    static_assert(sizeof(WallMoveVars) == 0x14);
    static_assert(sizeof(daAlinkHIO_huLight_c0) == 0x1C);
    static_assert(sizeof(daAlinkHIO_anm_c) == 0x14);

    extern "C"
    {
        /**
         *	@brief Checks if the specified stage is equal to the current stage.
         *
         *  @return Bool Returns True if the stages match, otherwise returns False.
         */
        bool checkStageName(const char* name);

        /**
         *	@brief Runs when Link is about to walk in a direction.
         */
        void setStickData();

        /**
         *	@brief Determines whether Link is in heavy state (Iron boots, Ball and
         *Chain, ...)
         *
         *	@return Bool returns True if Link is in a heavy state, otherwise returns False.
         */
        bool checkHeavyStateOn(int32_t unk1, int32_t unk2);

        /**
         *	@brief Initializes the animation that causes Link to transform.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if the process completed successfully, otherwise returns False.
         */
        bool procCoMetamorphoseInit(daAlink* linkActrPtr);

        /**
         *	@brief Checks whether a chest-rupee doesn't fit in Link's wallet.
         *
         *	@param linkActrPtr A pointer to Link's Actor
         *	@param itemID The ID of the rupee to check.
         *
         *	@return Bool returns True if the rupee doesn't fit in Links wallet, otherwise returns False.
         */
        bool checkTreasureRupeeReturn(daAlink* unk1, int32_t item);

        /**
         *	@brief Checks to see if Link is in an event (cutscene/animation/etc.)
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is in an event, otherwise returns False.
         */
        bool checkEventRun(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently snowboarding.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is on a snowboard, otherwise returns False.
         */
        bool checkBoardRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding in a canoe.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is in a canoe, otherwise returns False.
         */
        bool checkCanoeRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding on Epona.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is riding Epona, otherwise returns False.
         */
        bool checkHorseRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding on a boar.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is riding a Boar, otherwise returns False.
         */
        bool checkBoarRide(daAlink* linkActrPtr);

        /**
         *	@brief Checks to see if Link is currently riding on the spinner.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is riding on the Spinner, otherwise returns False.
         */
        bool checkSpinnerRide(daAlink* linkActrPtr);

        /**
         *  @brief Initializes the process used when delivering the final blow to Ganondorf.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if the action was successful, otherwise returns False.
         */
        bool procGanonFinishInit(daAlink* linkActrPtr);

        /**
         *  @brief Runs when delivering the final blow to Ganondorf.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if the action was successful, otherwise returns False.
         */
        bool procGanonFinish(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if link should be taking damage.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link should be taking damage, otherwise returns False.
         */
        bool checkDamageAction(daAlink* linkActrPtr);

        /**
         *  @brief Sets link's facial expression when getting an item
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param itemID The item to be checked.
         */
        void setGetItemFace(daAlink* linkActrPtr, uint16_t itemID);

        /**
         *  @brief Causes Human Link to take damage based on his interaction with certain things.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param obj A pointer to the object causing the damage.
         *  @param unk3 Unknown.
         *
         *  @return Bool returns True if Link successfully took damage, otherwise returns False.
         */
        bool procDamageInit(daAlink* linkActrPtr, void* obj, int32_t unk3);

        /**
         *  @brief Causes Wolf Link to take damage based on his interaction with certain things.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param obj A pointer to the object causing the damage.
         *
         *  @return Bool returns True if Link successfully took damage, otherwise returns False.
         */
        bool procWolfDamageInit(daAlink* linkActrPtr, void* obj);

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset | Flag
         *
         *  @return Bool returns True if the flag is set, otherwise returns False.
         */
        bool dComIfGs_isEventBit(uint16_t flag);

        /**
         *  @brief Checks to see if the currently targeted actor is able to be finished with the Ending Blow.
         *
         *  @param linkActrPtr A pointer to Link's Actor.
         *
         *  @return Bool returns True if the enemy can be finished, otherwise returns False.
         */
        bool checkDownAttackState(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link is moving while in a heavy state.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is moving while heavy, otherwise returns False.
         */
        bool checkBootsMoveAnime(daAlink* linkActrPtr, int32_t param_1);

        /**
         *  @brief Initializes the process that runs when Link talks to a character.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void procCoTalkInit(daAlink* linkActrPtr);

        /**
         *  @brief The function process that runs when Link collects an item.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void procCoGetItem(daAlink* linkActrPtr);

        /**
         *  @brief Increases Link's maximum health by a determined amount and sets the currently filled hearts to the stated
         * count.
         *
         *  @param amount The amount in which to increase Link's maximum heart count (in 1/4 hearts).
         *  @param count The amount of filled hearts in which to increase Link's current health (in 1/4 hearts).
         */
        void dComIfGp_setItemLifeCount(float amount, uint8_t count);

        /**
         *  @brief Checks to see if Link is currently voiding out.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *
         *  @return Bool returns True if Link is voiding, otherwise returns False.
         */
        bool checkRestartRoom(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link has begun the warping process, either in the overworld or in a dungeon.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void checkWarpStart(daAlink* linkActrPtr);

        /**
         *  @brief Sets the model information for the Midna Charge attack including color, size, etc.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        void setWolfLockDomeModel(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link is riding the Spinner and if so, returns a pointer to the Spinner's actor
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        libtp::tp::f_op_actor::fopAc_ac_c* getSpinnerActor(daAlink* linkActrPtr);

        /**
         *  @brief Checks to see if Link is trying to open a door near Bo
         *
         *  @param actrPtr A pointer to an actor near Link
         */
        libtp::tp::f_op_actor::fopAc_ac_c* searchBouDoor(libtp::tp::f_op_actor::fopAc_ac_c* actrPtr);

        /**
         *	@brief Checks for any factors that could increase the damage Link takes.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         *  @param param_1 Unknown
         *  @param param_2 Unknown
         *
         *  @return Returns a float that is the multiplier for the damage Link takes.
         */
        float damageMagnification(daAlink* linkActrPtr, int32_t param_1, int32_t param_2);

        /**
         *  @brief Checks to see if an eventBit for the currently active save is set.
         *
         *  @param flag Offset+Flag
         */
        bool dComIfGs_isEventBit(uint16_t flag);

        /**
         *  @brief Checks to see if Link can use an item
         *
         *  @param item_id  id of the item
         */
        bool checkCastleTownUseItem(uint16_t item_id);

        /**
         *  @brief Initializes the animation for Link to bonk into something.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        bool procFrontRollCrashInit(daAlink* linkActrPtr);

        /**
         *  @brief Initializes the animation for Wolf Link when he bonks into a wall via a dash.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        bool procWolfDashReverseInit(daAlink* linkActrPtr, bool param_1);

        /**
         *  @brief Initializes the animation for Wolf Link when he bonks into a wall via an attack.
         *
         *  @param linkActrPtr A pointer to Link's Actor
         */
        bool procWolfAttackReverseInit(daAlink* linkActrPtr);

        extern ClimbVars climbVars;
        extern WallMoveVars wallMoveVars;
        extern uint8_t getSeType[0x100];
        extern daAlinkHIO_kandelaar_c0 lanternVars;
        extern daAlinkHIO_magneBoots_c0 ironBootsVars;
        extern daAlinkHIO_huLight_c0 huLightVars;
    }
} // namespace libtp::tp::d_a_alink
#endif