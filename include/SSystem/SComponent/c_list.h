/**	@file c_list.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/SSystem/SComponent/c_list.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_C_LIST_H
#define TP_C_LIST_H

#include <cstdint>

#include "c_node.h"

namespace libtp::tp
{
    typedef struct node_list_class
    {
        node_class* mpHead;
        node_class* mpTail;
        int32_t mSize;
    } node_list_class;
}     // namespace libtp::tp

#endif