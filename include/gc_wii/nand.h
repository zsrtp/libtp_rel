/**	@file nand.h
 *	@brief The NAND API provides file level access to the Wii's nand flash.
 *
 *	Refer to the dolphin OS Reference Manual for further information
 *
 *	@author kipcode66
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
    } NANDFileInfo;

    extern "C"
    {
        int32_t NANDCreate( const char* fileName, uint32_t unk2, int32_t unk3 );
        int32_t NANDDelete( const char* fileName );
        int32_t NANDOpen( const char* fileName, NANDFileInfo* fileInfo, uint32_t mode );
        int32_t NANDSafeOpen( const char* fileName, NANDFileInfo* fileInfo, uint32_t mode, void* safeCopyBuf, uint32_t size );
        int32_t NANDClose( NANDFileInfo* fileInfo );
        int32_t NANDSafeClose( NANDFileInfo* fileInfo );
        int32_t NANDRead( NANDFileInfo* fileInfo, void* dest, uint32_t length );
        int32_t NANDWrite( NANDFileInfo* fileInfo, void* src, uint32_t length );
        int32_t NANDSeek( NANDFileInfo* fileInfo, uint32_t offset, int32_t unk1 );

        extern uint8_t l_safeCopyBuf[0x4000];
    }

}     // namespace libtp::gc_wii::nand

#endif