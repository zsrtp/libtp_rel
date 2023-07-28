/**	@file JKRDisposer.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/JSystem/JKernel/JKRDisposer.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_JKRDISPOSER_H
#define TP_JKRDISPOSER_H

#include <cstdint>

namespace libtp::tp::JKRDisposer
{
    class JKRHeap;
    class JKRDisposer
    {
       public:
        /* 0x00 */ void* vtable;
        /* 0x04 */ JKRHeap* mHeap;
        /* 0x08 */ uint8_t field_0x8[0x10]; // JSULink<JKRDisposer> mLink;
        /* 0x18 */
    };
} // namespace libtp::tp::JKRDisposer

#endif