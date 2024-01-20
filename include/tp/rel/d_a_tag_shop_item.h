/**	@file d_a_tag_shop_item.h
 *	@brief Contains tag definitions for the shop item rel.
 *
 *	@author Lunar Soap
 *	@bug
 */
#ifndef TP_D_A_TAG_SHOP_ITEM_H
#define TP_D_A_TAG_SHOP_ITEM_H

#include <cstdint>

#include "tp/f_op_actor.h"

namespace libtp::tp::rel::d_a_tag_shop_item
{
    class daTag_ShopItem: public libtp::tp::f_op_actor::fopAc_ac_c
    {
        /* 0x568 */ void* vtable;
        /* 0x56C */ uint32_t mProcessID;
        /* 0x570 */ int16_t mCreateTimer;
        /* 0x572 */ uint8_t field_0x572;
        /* 0x573 */ uint8_t padding;
    } __attribute__((__packed__));
    static_assert(sizeof(daTag_ShopItem) == 0x574);
} // namespace libtp::tp::rel::d_a_tag_shop_item

#endif