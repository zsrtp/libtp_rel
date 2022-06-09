#ifndef JKRFILELOADER_H
#define JKRFILELOADER_H

#include "symbol_defines.h"
#include "JSystem/JKernel/JKRFileFinder.h"
#include "JSystem/JSupport/JSUList.h"
#include "JSystem/JKernel/JKRDisposer.h"

#include <cstdint>

// Declare classes/structs so that other stuff can use them
class JKRFileLoader;
class JKRFileFinder;

extern "C"
{
    // Variables
    extern void* JKRFileLoader_vt[];     // Vtable
    JSUList<JKRFileLoader> JKRFileLoader_sVolumeList;
    JKRFileLoader* JKRFileLoader_sCurrentVolume;

    // Functions
    JKRFileLoader* JKRFileLoader_ct( JKRFileLoader* JKRFileLoaderThis );                        // Constructor
    JKRFileLoader* JKRFileLoader_dt1( JKRFileLoader* JKRFileLoaderThis, int16_t freeThis );     // Destructor
    // JKRFileLoader* JKRFileLoader_dt2( JKRFileLoader* JKRFileLoaderThis, int16_t freeThis );  // Destructor

    /* vt[03] */ void JKRFileLoader_unmount( JKRFileLoader* JKRFileLoaderThis );

    void* JKRFileLoader_getGlbResource1( const char* resource );
    void* JKRFileLoader_getGlbResource2( const char* resource, JKRFileLoader* loader );
    bool JKRFileLoader_removeResource( JKRFileLoader* JKRFileLoaderThis, void* unk2, JKRFileLoader* unk3 );
    bool JKRFileLoader_detachResource( void* resource, JKRFileLoader* loader );
    JKRFileLoader* JKRFileLoader_findVolume( const char** volumeName );
    const char* JKRFileLoader_fetchVolumeName( char* unk1, uint32_t unk2, const char* unk3 );

    inline JKRFileLoader* JKRFileLoader_getCurrentVolume() { return JKRFileLoader_sCurrentVolume; }
    inline void JKRFileLoader_setCurrentVolume( JKRFileLoader* fileLoader ) { JKRFileLoader_sCurrentVolume = fileLoader; }
    inline JSUList<JKRFileLoader>& JKRFileLoader_getVolumeList() { return JKRFileLoader_sVolumeList; }
}

class JKRFileLoader
{
   public:
    // JKRFileLoader( void ) { JKRFileLoader_ct( this ); }
    // virtual ~JKRFileLoader();

    bool isMounted() const { return this->mIsMounted; }
    uint32_t getVolumeType() const { return this->mVolumeType; }

   public:
    /* vt[03] */     // virtual void unmount( void ) { JKRFileLoader_unmount( this ); }
    /* vt[04] */     // virtual bool becomeCurrent( const char* ) = 0;
    /* vt[05] */     // virtual void* getResource( const char* ) = 0;
    /* vt[06] */     // virtual void* getResource( uint32_t, const char* ) = 0;
    /* vt[07] */     // virtual uint32_t readResource( void*, uint32_t, const char* ) = 0;
    /* vt[08] */     // virtual uint32_t readResource( void*, uint32_t, uint32_t, const char* ) = 0;
    /* vt[09] */     // virtual void removeResourceAll( void ) = 0;
    /* vt[10] */     // virtual bool removeResource( void* ) = 0;
    /* vt[11] */     // virtual bool detachResource( void* ) = 0;
    /* vt[12] */     // virtual uint32_t getResSize( const void* ) const = 0;
    /* vt[13] */     // virtual uint32_t countFile( const char* ) const = 0;
    /* vt[14] */     // virtual JKRFileFinder* getFirstFile( const char* ) const = 0;

   protected:
    /* 0x00 */ void* vtable;
    /* 0x04 */ JKRDisposer disposer;
    /* 0x18 */ JSULink<JKRFileLoader> mFileLoaderLink;
    /* 0x28 */ const char* mVolumeName;
    /* 0x2C */ uint32_t mVolumeType;
    /* 0x30 */ bool mIsMounted;
    /* 0x31 */ uint8_t field_0x31[3];
    /* 0x34 */ uint32_t mMountCount;

   public:
    /*
    static void* getGlbResource( const char* );
    static void* getGlbResource( const char*, JKRFileLoader* );
    static bool removeResource( void*, JKRFileLoader* );
    static bool detachResource( void*, JKRFileLoader* );
    static JKRFileLoader* findVolume( const char** );
    static const char* fetchVolumeName( char*, int32_t, const char* );

    static JKRFileLoader* getCurrentVolume() { return sCurrentVolume; }
    static void setCurrentVolume( JKRFileLoader* fileLoader ) { sCurrentVolume = fileLoader; }
    static JSUList<JKRFileLoader>& getVolumeList() { return sVolumeList; }

    static JKRFileLoader* sCurrentVolume;
    static JSUList<JKRFileLoader> sVolumeList;
    */
} __attribute__( ( __packed__ ) );

static_assert( sizeof( JKRFileLoader ) == 0x38 );

inline bool JKRDetachResource( void* resource, JKRFileLoader* fileLoader )
{
    return JKRFileLoader_detachResource( resource, fileLoader );
}

inline void* JKRGetNameResource( const char* name, JKRFileLoader* loader )
{
    return JKRFileLoader_getGlbResource2( name, loader );
}

inline void* JKRGetResource( const char* name )
{
    return JKRFileLoader_getGlbResource1( name );
}

#endif