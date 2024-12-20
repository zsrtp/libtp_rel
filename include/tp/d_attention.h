#ifndef D_D_ATTENTION_H
#define D_D_ATTENTION_H
#include <cstdint>
#include <tp/f_op_actor.h>
#include <tp/m_do_ext.h>
// #include <SSystem/SComponent/c_angle.h>

namespace libtp::tp::d_attention{
// struct dist_entry {
//     float field_0x0;
//     float field_0x4;
//     float field_0x8;
//     float field_0xc;
//     float field_0x10;
//     float field_0x14;
//     uint32_t field_0x18;
// };  // Size: 0x1C

// struct type_tbl_entry {
//     int16_t field_0x0;
//     uint16_t field_0x2;
// };

// class dAttention_c {
// public:
//     enum EState {
//         ST_NONE,
//         ST_LOCK,
//         ST_RELEASE,
//     };

//     /* 80070198 */ dAttention_c(libtp::tp::f_op_actor::fopAc_ac_c*, uint32_t);
//     /* 80070A70 */ int chkAttMask(uint32_t, uint32_t);
//     /* 80070E90 */ float calcWeight(int, libtp::tp::f_op_actor::fopAc_ac_c*, float, int16_t, int16_t, uint32_t*);
//     /* 800710C0 */ void setList(int, libtp::tp::f_op_actor::fopAc_ac_c*, float, float, cSAngle, uint32_t);
//     /* 80071240 */ void initList(uint32_t);
//     /* 800713CC */ int makeList();
//     /* 80071424 */ void setOwnerAttentionPos();
//     /* 80071488 */ int SelectAttention(libtp::tp::f_op_actor::fopAc_ac_c*);
//     /* 800716B8 */ void sortList();
//     /* 800718A4 */ void stockAttention();
//     /* 80071960 */ libtp::tp::f_op_actor::fopAc_ac_c* nextAttention();
//     /* 80071A68 */ int freeAttention();
//     /* 80071A98 */ bool chaseAttention();
//     /* 80071CC0 */ float EnemyDistance(libtp::tp::f_op_actor::fopAc_ac_c*);
//     /* 80071DEC */ void runSoundProc();
//     /* 80071E84 */ void runDrawProc();
//     /* 800720F4 */ void runDebugDisp();
//     /* 800720F8 */ void checkButton();
//     /* 800722A0 */ bool triggerProc();
//     /* 800722EC */ int lostCheck();
//     /* 80072344 */ void judgementStatus4Hold();
//     /* 800725F0 */ void judgementStatus4Switch();
//     /* 80072924 */ int Run();
//     /* 80072BD4 */ void Draw();
//     /* 80072D80 */ void lockSoundStart(uint32_t);
//     /* 8007353C */ libtp::tp::f_op_actor::fopAc_ac_c* LockonTarget(int32_t);
//     /* 800736CC */ uint32_t LockonTargetPId(int32_t);
//     /* 80073734 */ libtp::tp::f_op_actor::fopAc_ac_c* ActionTarget(int32_t);
//     /* 8007378C */ libtp::tp::f_op_actor::fopAc_ac_c* CheckObjectTarget(int32_t);
//     /* 800737E4 */ bool LockonTruth();
//     /* 80073838 */ int checkDistance(cXyz*, int16_t, cXyz*, float, float, float, float);
//     /* 8016E424 */ void LockEdge();
//     /* 80182994 */ void GetCheckObjectCount();
//     /* 80182AD0 */ void keepLock(int);
//     /* 8014B010 */ static dist_entry& getDistTable(int);
// };
extern "C"{
    /**
     * @brief gets the actor that is targeted
     * @param dAttentionPointer a pointer to the dAttention instance 
     * @param attentionIndex the index of the targeted actor
     * @return the actor pointer that is targeted
    */
    libtp::tp::f_op_actor::fopAc_ac_c* LockonTarget(void* dAttentionPointer, int32_t attentionIndex);
}}
#endif