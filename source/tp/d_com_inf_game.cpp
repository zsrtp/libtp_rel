#include "tp/d_com_inf_game.h"
#include "tp/d_kankyo.h"

#include <cstdint>

namespace libtp::tp::d_com_inf_game
{
#ifdef PLATFORM_WII
    void dComIfG_get_timelayer(int32_t* pLayer)
    {
        if (libtp::tp::d_kankyo::dKy_daynight_check())
        {
            *pLayer += 1;
        }
    }

    bool dComIfGs_isItemFirstBit(uint8_t itemID)
    {
        return isFirstBit(&dComIfG_gameInfo.save.save_file.player.player_get_item, itemID);
    }

    bool dComIfGs_isEventBit(uint16_t flag)
    {
        return libtp::tp::d_save::isEventBit(&dComIfG_gameInfo.save.save_file.mEvent, flag);
    }
#endif
} // namespace libtp::tp::d_com_inf_game
