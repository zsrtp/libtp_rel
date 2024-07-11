#include "tp/d_a_player.h"

#include <cstdint>

namespace libtp::tp::d_a_player
{
#ifdef PLATFORM_WII
void offNoResetFlg2(daPy_py* linkActrPtr, daPy_FLG2 i_flag) {
    linkActrPtr->mNoResetFlg2 &= ~i_flag;
}

void offNoResetFlg0(daPy_py* linkActrPtr, daPy_FLG0 i_flag) {
    linkActrPtr->mNoResetFlg0 &= ~i_flag;
}
#endif

void onResetFlg0(daPy_py* linkActrPtr, daPy_RFLG0 i_flag) {
    linkActrPtr->mResetFlg0 |= i_flag;
}
} // namespace libtp::tp::d_a_player
