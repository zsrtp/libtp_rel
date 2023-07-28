/**	@file c_node.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/SSystem/SComponent/c_node.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_C_NODE_H
#define TP_C_NODE_H

#include <cstdint>

namespace libtp::tp
{
    typedef struct node_class
    {
        struct node_class* mpPrevNode;
        void* mpData;
        struct node_class* mpNextNode;
    } node_class;
} // namespace libtp::tp

#endif