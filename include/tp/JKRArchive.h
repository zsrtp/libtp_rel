/**	@file JKRArchive.h
 *	@brief Contains functions for handling various aspects of the game
 *
 *	@author Lunar Soap
 *	@bug No known bugs.
 */

#include <cstdint>
#include "JKRFileLoader.h"
#include "JKRHeap.h"

namespace libtp::tp::JKRArchive
{
    class JKRArchive
    {
        protected:
            JKRArchive_vtable* vtable;
            libtp::tp::JKRFileLoader::JKRFileLoader base;
            libtp::tp::JKRHeap::JKRHeap* mHeap;
            uint8_t mMountMode;
            uint8_t field_0x39[3]; // padding
            int32_t archive_number;
            SArcDataInfo* mArcInfoBlock;
            SDirEntry* mDirs;
            SDIFileEntry* mFiles;
            int32_t* mExpandedSize;
            char* mStringTable;
            uint32_t field_0x54;
    } __attribute__((__packed__));

    class JKRArchive_vtable
    {
        public:
            /* vt[00] */ virtual void* field_0x0();
            /* vt[01] */ virtual void* field_0x4();
            /* vt[02] */ virtual void* dtor();
            /* vt[04] */ virtual bool becomeCurrent(const char*);                /* override */
            /* vt[05] */ virtual void* getResource(const char*);                 /* override */
            /* vt[06] */ virtual void* getResource(u32, const char*);            /* override */
            /* vt[07] */ virtual uint32_t readResource(void*, uint32_t, const char*);      /* override */
            /* vt[08] */ virtual uint32_t readResource(void*, uint32_t, uint32_t, const char*); /* override */
            /* vt[09] */ virtual void removeResourceAll(void);                   /* override */
            /* vt[10] */ virtual bool removeResource(void*);                     /* override */
            /* vt[11] */ virtual bool detachResource(void*);                     /* override */
            /* vt[12] */ virtual uint32_t getResSize(const void*) const;              /* override */
            /* vt[13] */ virtual uint32_t countFile(const char*) const;               /* override */
            /* vt[14] */ virtual JKRFileFinder* getFirstFile(const char*) const; /* override */
            /* vt[15] */ virtual uint32_t getExpandedResSize(const void*) const;
            /* vt[16] */ virtual void* fetchResource(SDIFileEntry*, uint32_t*) = 0;
            /* vt[17] */ virtual void* fetchResource(void*, u32, SDIFileEntry*, uint32_t*) = 0;
            /* vt[18] */ virtual void setExpandSize(SDIFileEntry*, uint32_t);
            /* vt[19] */ virtual uint32_t getExpandSize(SDIFileEntry*) const;
    } __attribute__((__packed__));
}// namespace libtp::tp::JKRArchive