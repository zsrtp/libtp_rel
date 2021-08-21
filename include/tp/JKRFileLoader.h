/**	@file JKRFileLoader.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>

namespace libtp::tp::JKRFileLoader
{
    class JKRFileLoader
    {
        protected:
        /* 0x00 */ JKRFileLoader_vtable* vtable;
        /* 0x04 */ JKRDisposer_members base;
        /* 0x18 */ JSULink<JKRFileLoader> mFileLoaderLink;
        /* 0x28 */ const char* mVolumeName;
        /* 0x2C */ uint32_t mVolumeType;
        /* 0x30 */ bool mIsMounted;
        /* 0x31 */ uint8_t field_0x31[3]; //Padding
        /* 0x34 */ uint32_t mMountCount;
    } __attribute__((__packed__));

    class JKRFileLoader_vtable
    {
        public:
            /* vt[00] */ virtual void* field_0x0();
            /* vt[01] */ virtual void* field_0x4();
            /* vt[02] */ virtual void* dtor();
            /* vt[03] */ virtual void unmount(void);
            /* vt[04] */ virtual bool becomeCurrent(const char*) = 0;
            /* vt[05] */ virtual void* getResource(const char*) = 0;
            /* vt[06] */ virtual void* getResource(u32, const char*) = 0;
            /* vt[07] */ virtual uint32_t readResource(void*, uint32_t, const char*) = 0;
            /* vt[08] */ virtual uint32_t readResource(void*, uint32_t, uint32_t, const char*) = 0;
            /* vt[09] */ virtual void removeResourceAll(void) = 0;
            /* vt[10] */ virtual bool removeResource(void*) = 0;
            /* vt[11] */ virtual bool detachResource(void*) = 0;
            /* vt[12] */ virtual uint32_t getResSize(const void*) const = 0;
            /* vt[13] */ virtual uint32_t countFile(const char*) const = 0;
            /* vt[14] */ virtual JKRFileFinder* getFirstFile(const char*) const = 0;
    } __attribute__((__packed__));
}// namespace libtp::tp::JKRFileLoader