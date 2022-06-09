#ifndef JKRFILEFINDER_H
#define JKRFILEFINDER_H

#include "symbol_defines.h"
#include "JSystem/JKernel/JKRArchive.h"
#include "dolphin/dvd/dvd.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRFileFinder;
class JKRArcFinder;
class JKRDvdFinder;
class JKRArchive;

extern "C"
{
    // Variables
    extern void* JKRDvdFinder_vt[];      // Vtable
    extern void* JKRArcFinder_vt[];      // Vtable
    extern void* JKRFileFinder_vt[];     // Vtable

    // Functions
    // JKRFileFinder
    JKRFileFinder* JKRFileFinder_dt( JKRFileFinder* JKRFileFinderThis, int16_t freeThis );     // Destructor

    // JKRArcFinder
    JKRArcFinder* JKRArcFinder_ct( JKRArcFinder* JKRArcFinderThis,
                                   JKRArchive* archive,
                                   int32_t startIndex,
                                   int32_t numEntries );     // Constructor

    JKRArcFinder* JKRArcFinder_dt( JKRArcFinder* JKRArcFinderThis, int16_t freeThis );     // Destructor

    bool JKRArcFinder_findNextFile( JKRArcFinder* JKRArcFinderThis );

    // JKRDvdFinder
    JKRDvdFinder* JKRDvdFinder_ct( JKRDvdFinder* JKRDvdFinderThis, const char* directory );     // Constructor
    JKRDvdFinder* JKRDvdFinder_dt( JKRDvdFinder* JKRDvdFinderThis, int16_t freeThis );          // Destructor

    bool JKRDvdFinder_findNextFile( JKRDvdFinder* JKRDvdFinderThis );
}

struct JKRFileFinder_UnknownBase
{
    const char* mEntryName;
    int32_t mEntryFileIndex;
    uint16_t mEntryId;
    uint16_t mEntryTypeFlags;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRFileFinder_UnknownBase ) == 0xC );

class JKRFileFinder: public JKRFileFinder_UnknownBase
{
   public:
    JKRFileFinder()
    {
        mIsAvailable = false;
        mIsFileOrDirectory = false;
    }

    // inline virtual ~JKRFileFinder();

    bool isAvailable() const { return mIsAvailable; }
    bool isFile() const { return mIsFileOrDirectory; }
    bool isDirectory() const { return mIsFileOrDirectory; }

   public:
    /* vt[3] */     // virtual bool findNextFile( void ) = 0;

   protected:
    /* 0x00 */     // JKRFileFinder_UnknownBase
    /* 0x0C */ void* vtable;
    /* 0x10 */ bool mIsAvailable;
    /* 0x11 */ bool mIsFileOrDirectory;
    /* 0x12 */ uint8_t field_0x12[2];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRFileFinder ) == 0x14 );

class JKRArcFinder: public JKRFileFinder
{
   public:
    JKRArcFinder( JKRArchive* archive, int32_t startIndex, int32_t numEntries )
    {
        JKRArcFinder_ct( this, archive, startIndex, numEntries );
    }

    // inline virtual ~JKRArcFinder();

   public:
    /* vt[3] */     // virtual bool findNextFile( void ) { return JKRArcFinder_findNextFile( this ); }

   private:
    /* 0x00 */     // JKRFileFinder_UnknownBase
    /* 0x0C */     // vtable
    /* 0x10 */     // JKRFileFinder
    /* 0x14 */ JKRArchive* mArchive;
    /* 0x18 */ int32_t mStartIndex;
    /* 0x1C */ int32_t mEndIndex;
    /* 0x20 */ int32_t mNextIndex;
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRArcFinder ) == 0x24 );

class JKRDvdFinder: public JKRFileFinder
{
   public:
    JKRDvdFinder( const char* directory ) { JKRDvdFinder_ct( this, directory ); }
    // virtual ~JKRDvdFinder();

   public:
    /* vt[3] */     // virtual bool findNextFile( void ) { return JKRDvdFinder_findNextFile( this ); }

   private:
    /* 0x00 */     // JKRFileFinder_UnknownBase
    /* 0x0C */     // vtable
    /* 0x10 */     // JKRFileFinder
    /* 0x14 */ DVDDirectory mDvdDirectory;
    /* 0x20 */ bool mDvdIsOpen;
    /* 0x21 */ uint8_t field_0x21[3];
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRDvdFinder ) == 0x24 );

#endif