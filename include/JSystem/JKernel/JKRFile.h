#ifndef JKRFILE_H
#define JKRFILE_H

#include "symbol_defines.h"
#include "JSystem/JKernel/JKRDisposer.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRFile;

extern "C"
{
    int32_t JKRFile_read( JKRFile* JKRFileThis, void* buffer, int32_t size, int32_t offset );
}

class JKRFile
{
   public:
    // JKRFile(): mIsAvailable( false ) {}
    // virtual ~JKRFile() {}

    int32_t read( void* buffer, int32_t size, int32_t offset ) { return JKRFile_read( this, buffer, size, offset ); }
    bool isAvailable() const { return mIsAvailable; }

   public:
    /* vt[03] */     // virtual bool open( const char* ) = 0;
    /* vt[04] */     // virtual void close() = 0;
    /* vt[05] */     // virtual int32_t readData( void*, int32_t, int32_t ) = 0;
    /* vt[06] */     // virtual int32_t writeData( const void*, int32_t, int32_t ) = 0;
    /* vt[07] */     // virtual int32_t getFileSize() const = 0;

   protected:
    /* 0x00 */ void* vtable;
    /* 0x04 */ JKRDisposer disposer;
    /* 0x18 */ bool mIsAvailable;
    /* 0x19 */ uint8_t field_0x19[3];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRFile ) == 0x1C );

#endif