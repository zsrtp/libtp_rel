/**	@file nand.h
 *	@brief The NAND API provides file level access to the Wii's nand flash.
 *
 *	Refer to the dolphin OS Reference Manual for further information
 *
 *	@author kipcode66
 *  @author Zephiles
 *	@bug No known bugs.
 */
#ifndef GC_WII_NAND_H
#define GC_WII_NAND_H

#include <cstdint>

#define NAND_FILENAME_MAX 32
#define SECTOR_SIZE 0x200

#define NAND_OPEN_READ 0x01
#define NAND_OPEN_WRITE 0x02
#define NAND_OPEN_RW ( NAND_OPEN_READ | NAND_OPEN_WRITE )

#define NAND_PERM_OTHER_READ   0x01
#define NAND_PERM_OTHER_WRITE  0x02
#define NAND_PERM_GROUP_READ   0x04
#define NAND_PERM_GROUP_WRITE  0x08
#define NAND_PERM_OWNER_READ   0x10
#define NAND_PERM_OWNER_WRITE  0x20

#define NAND_RESULT_UNLOCKED 1
#define NAND_RESULT_READY 0
#define NAND_RESULT_BUSY -1
#define NAND_RESULT_WRONGDEVICE -2
#define NAND_RESULT_NOCARD -3
#define NAND_RESULT_NOFILE -4
#define NAND_RESULT_IOERROR -5
#define NAND_RESULT_BROKEN -6
#define NAND_RESULT_EXIST -7
#define NAND_RESULT_NOENT -8
#define NAND_RESULT_INSSPACE -9
#define NAND_RESULT_NOPERM -10
#define NAND_RESULT_LIMIT -11
#define NAND_RESULT_NAMETOOLONG -12
#define NAND_RESULT_ENCODING -13
#define NAND_RESULT_FATAL_ERROR -128

#define NAND_READ_SIZE 0x200

namespace libtp::gc_wii::nand
{
    typedef struct NANDFileInfo
    {
        uint8_t unk[0x90];
    } __attribute__( ( __packed__ ) ) NANDFileInfo;

    extern "C"
    {
        // Variables
        /**
         *  @brief No decent description at this time
         */
        extern uint8_t l_safeCopyBuf[0x4000];

        // Functions
        /**
         *  @brief Initializes NAND API control blocks. Must be called once before using any other NAND API functions.
         */
        void NANDInit( void );

        /**
         * @brief Creates a new file on the NAND memory file system.
         * 
         * @param fileName Path to the file
         * @param permissions Permissions of the file
         * @param attributes Unknown usage. Default to 0
         * @return int32_t Error code of the execution
         */
        int32_t NANDCreate(const char *fileName, uint8_t permissions, int8_t attributes);
        
        /**
         * @brief Deletes a file from the NAND memory file system.
         * 
         * @param fileName Path to the file
         * @return int32_t Error code of the execution
         */
        int32_t NANDDelete(const char *fileName);

        /**
         * @brief Opens a file on the NAND memory file system.
         * 
         * @param fileName Path to the file
         * @param fileInfo Pointer to file info to be used
         * @param mode Open mode for the file (Read/Write/RW)
         * @return int32_t Error code of the operation
         */
        int32_t NANDOpen(const char *fileName, NANDFileInfo *fileInfo, uint32_t mode);

        /**
         * @brief Safely opens a file on the NAND memory file system.
         * 
         * @param fileName Path to the file
         * @param fileInfo Pointer to file info to be used
         * @param mode Open mode for the file (Read/Write/RW)
         * @param safeCopyBuf Buffer to use when interacting with the file
         * @param size Size of the buffer
         * @return int32_t Error code of the operation
         */
        int32_t NANDSafeOpen(const char *fileName, NANDFileInfo *fileInfo, uint32_t mode, void* safeCopyBuf, uint32_t size);

        /**
         * @brief Closes a file on the NAND memory file system.
         * 
         * @param fileInfo Pointer to file info to be closed
         * @return int32_t Error code of the operation
         */
        int32_t NANDClose(NANDFileInfo *fileInfo);

        /**
         * @brief Safely closes a file on the NAND memory file system
         * 
         * @param fileInfo Pointer to file info to be closed
         * @return int32_t Error code of the operation
         */
        int32_t NANDSafeClose(NANDFileInfo *fileInfo);

        /**
         * @brief Reads from a file synchronously.
         * 
         * @param fileInfo Pointer to the file info of the file to be read
         * @param dest Buffer address (32 bytes aligned)
         * @param length Number of bytes to be read (multiple of NAND_READ_SIZE)
         * @return int32_t Number of bytes read from the file
         */
        int32_t NANDRead(NANDFileInfo *fileInfo, void *dest, uint32_t length);

        /**
         * @brief Writes data to a file synchronously.
         * 
         * @param fileInfo Pointer to the file info of the file to be written
         * @param src buffer address (32 bytes aligned)
         * @param length number of bytes to write. The length must be multiple of the card sector size
         * @return int32_t Number of bytes written to the file
         */
        int32_t NANDWrite(NANDFileInfo *fileInfo, void *src, uint32_t length);

        /**
         * @brief Seeks to a given offset of a file.
         * 
         * @param fileInfo Pointer to the file info of the file to seek into
         * @param offset File position to seek to
         * @param unk1 Unknown (maybe the seek mode? from Start ?= 0). Default to 0
         * @return int32_t 
         */
        int32_t NANDSeek(NANDFileInfo *fileInfo, uint32_t offset, int32_t unk1);
    }

}     // namespace libtp::gc_wii::nand

#endif