/**	@file JKRArchive.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/JSystem/JKernel/JKRArchive.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_JKRARCHIVE_H
#define TP_JKRARCHIVE_H

#include <cstdint>

#include "tp/JKRFileLoader.h"
#include "tp/JKRHeap.h"

namespace libtp::tp::JKRArchive
{
    struct SArcHeader
    {
        /* 0x00 */ uint32_t signature;
        /* 0x04 */ uint32_t file_length;
        /* 0x08 */ uint32_t header_length;
        /* 0x0C */ uint32_t file_data_offset;
        /* 0x10 */ uint32_t file_data_length;
        /* 0x14 */ uint32_t field_0x14;
        /* 0x18 */ uint32_t field_0x18;
        /* 0x1C */ uint32_t field_0x1c;
    };

    struct SArcDataInfo
    {
        /* 0x00 */ uint32_t num_nodes;
        /* 0x04 */ uint32_t node_offset;
        /* 0x08 */ uint32_t num_file_entries;
        /* 0x0C */ uint32_t file_entry_offset;
        /* 0x10 */ uint32_t string_table_length;
        /* 0x14 */ uint32_t string_table_offset;
        /* 0x18 */ uint16_t next_free_file_id;
        /* 0x1A */ bool sync_file_ids_and_indices;
        /* 0x1B */ uint8_t field_1b[5];
    };

    class JKRArchive: public libtp::tp::JKRFileLoader::JKRFileLoader
    {
       public:
        struct SDirEntry
        {
            union
            {
                uint32_t type;
                struct
                {
                    uint8_t flags;
                    uint8_t padding;
                    uint16_t id;
                } other;
            };

            const char* name;
            uint16_t field_0x8;
            uint16_t num_entries;
            int32_t first_file_index;
        };

        struct SDIFileEntry
        {
            uint16_t file_id;
            uint16_t name_hash;
            uint32_t type_flags_and_name_offset;
            uint32_t data_offset;
            uint32_t data_size;
            void* data;
        };

        enum EMountMode
        {
            UNKNOWN_MOUNT_MODE = 0,
            MOUNT_MEM = 1,
            MOUNT_ARAM = 2,
            MOUNT_DVD = 3,
            MOUNT_COMP = 4,
        };

        enum EMountDirection
        {
            UNKNOWN_MOUNT_DIRECTION = 0,
            MOUNT_DIRECTION_HEAD = 1,
            MOUNT_DIRECTION_TAIL = 2,
        };

        /* 0x00 */              // vtable
        /* 0x04 */              // JKRFileLoader
        /* 0x38 */ void* mHeap; // JKRHeap* mHeap;
        /* 0x3C */ uint8_t mMountMode;
        /* 0x3D */ uint8_t field_0x3d[3];
        /* 0x40 */ int32_t mEntryNum;
        /* 0x44 */ SArcDataInfo* mArcInfoBlock;
        /* 0x48 */ SDirEntry* mNodes;
        /* 0x4C */ SDIFileEntry* mFiles;
        /* 0x50 */ int32_t* mExpandedSize;
        /* 0x54 */ char* mStringTable;
        /* 0x58 */ uint32_t field_0x58;
    };
    extern "C"
    {
        /**
         *	@brief Retrieves a resource from an archive.
         *
         *	@param JKRArchive A pointer to the archive to be searched.
         * @param type The type of resource to be loaded.
         *  @param file The name of the file to be searched.
         *
         *  @return Returns a pointer to the resource if successfully loaded. Returns a nullptr otherwise.
         */
        void* JKRArchive_getResource2(void* JKRArchive, uint32_t type, const char* file);

        /**
         *	@brief Locates a file resource in memory.
         *
         *	@param _this A pointer to the archive to be searched.
         *  @param name The name of the resource to be located
         *  @param param_2 Unknown
         *
         *  @return Returns a pointer to the resource if successfully found. Returns a nullptr otherwise.
         */
        JKRArchive::SDIFileEntry* JKRArchive_findFsResource(JKRArchive* _this, const char* name, uint32_t param_2);
    }
} // namespace libtp::tp::JKRArchive
#endif