#ifndef JKRDISPOSER_H
#define JKRDISPOSER_H

#include "symbol_defines.h"
#include "JSystem/JKernel/JKRHeap.h"
#include "JSystem/JSupport/JSUList.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRDisposer;
class JKRHeap;

extern "C"
{
    // Variables
    extern void* JKRDisposer_vt[];     // Vtable

    // Functions
    JKRDisposer* JKRDisposer_ct( JKRDisposer* JKRDisposerThis );                       // Constructor
    JKRDisposer* JKRDisposer_dt( JKRDisposer* JKRDisposerThis, int16_t freeThis );     // Destructor
}

class JKRDisposer
{
   public:
    // JKRDisposer() { JKRDisposer_ct( this ); }
    // virtual ~JKRDisposer();

   public:
    /* 0x00 */     // vtable
    /* 0x04 */ JKRHeap* mHeap;
    /* 0x08 */ JSULink<JKRDisposer> mLink;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRDisposer ) == 0x14 );

#endif