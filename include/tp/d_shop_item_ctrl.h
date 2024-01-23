/**	@file d_shop_item_ctrl.h
 *	@brief Holds data and definitions related to the event nodes of the shop system.
 *
 *  @author Lunar Soap
 *	@bug No known bugs.
 */
#ifndef TP_D_SHOP_ITEM_CTRL_H
#define TP_D_SHOP_ITEM_CTRL_H

#include <cstdint>

namespace libtp::tp::d_shop_item_ctrl
{
    struct dShopItemCtrl
    {
        /* 0x00 */ void* vtable;
        /* 0x04 */ uint32_t mItemIndex[0x7];
        /* 0x20 */ uint16_t mMessageIndex[0x7];
        /* 0x2E */ uint16_t padding;
    } __attribute__((__packed__));

    static_assert(sizeof(dShopItemCtrl) == 0x30);
} // namespace libtp::tp::d_shop_item_ctrl
#endif