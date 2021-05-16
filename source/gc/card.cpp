#include "gc/card.h"

#include <cstring>

namespace libtp::gc::card
{
    int32_t __CARDFreeBlock( int32_t chan, uint16_t block, CARDCallback callback )
    {
        uint32_t card = reinterpret_cast<uint32_t>( &__CARDBlock[chan] );
        if ( *reinterpret_cast<int32_t*>( card ) == 0 )
        {
            return CARD_RESULT_NOCARD;
        }

        uint16_t cardVar = *reinterpret_cast<uint16_t*>( card + 0x10 );     // Maximum number of blocks?
        uint16_t* fatBlock = *reinterpret_cast<uint16_t**>( card + 0x88 );

        while ( block != 0xFFFF )
        {
            uint32_t tempBlock = static_cast<uint32_t>( block );
            if ( ( tempBlock < 5 ) || ( tempBlock >= cardVar ) )
            {
                return CARD_RESULT_BROKEN;
            }

            block = fatBlock[tempBlock];
            fatBlock[tempBlock] = 0;
            fatBlock[3] += 1;
        }

        return __CARDUpdateFatBlock( chan, fatBlock, callback );
    }

    void DeleteCallback( int32_t chan, int32_t result )
    {
        uint32_t card = reinterpret_cast<uint32_t>( &__CARDBlock[chan] );
        CARDCallback* cardApiCbAddress = reinterpret_cast<CARDCallback*>( card + 0xD0 );

        CARDCallback cb = *cardApiCbAddress;
        *cardApiCbAddress = nullptr;

        int32_t ret = result;
        if ( ret >= CARD_RESULT_READY )
        {
            uint16_t* currFileBlockAddr = reinterpret_cast<uint16_t*>( card + 0xBE );

            ret = __CARDFreeBlock( chan, *currFileBlockAddr, cb );
            if ( ret >= CARD_RESULT_READY )
            {
                return;
            }
        }

        __CARDPutControlBlock( reinterpret_cast<void*>( card ), ret );

        if ( cb )
        {
            cb( chan, ret );
        }
    }

    int32_t __CARDGetFileNo( void* card, const char* fileName, int32_t* fileNo )
    {
        int32_t cardIsAttached = *reinterpret_cast<int32_t*>( reinterpret_cast<uint32_t>( card ) );
        if ( cardIsAttached == 0 )
        {
            return CARD_RESULT_NOCARD;
        }

        uint32_t dirBlock = reinterpret_cast<uint32_t>( __CARDGetDirBlock( card ) );

        int32_t i;
        for ( i = 0; i < 127; i++ )
        {
            uint8_t* currentDirBlock = reinterpret_cast<uint8_t*>( dirBlock + ( i * 0x40 ) );
            const char* currentFileName = reinterpret_cast<const char*>( &currentDirBlock[0x8] );

            if ( strncmp( fileName, currentFileName, 32 ) == 0 )
            {
                if ( __CARDAccess( card, currentDirBlock ) >= CARD_RESULT_READY )
                {
                    *fileNo = i;
                    break;
                }
            }
        }

        if ( i >= 127 )
        {
            return CARD_RESULT_NOFILE;
        }

        return CARD_RESULT_READY;
    }

    int32_t CARDDeleteAsync( int32_t chan, const char* fileName, CARDCallback callback )
    {
        uint32_t card;
        int32_t ret = __CARDGetControlBlock( chan, reinterpret_cast<void**>( &card ) );
        if ( ret < CARD_RESULT_READY )
        {
            return ret;
        }

        int32_t fileNo;
        ret = __CARDGetFileNo( reinterpret_cast<void*>( card ), fileName, &fileNo );
        if ( ret < CARD_RESULT_READY )
        {
            __CARDPutControlBlock( reinterpret_cast<void*>( card ), ret );
            return ret;
        }

        uint32_t dirBlock = reinterpret_cast<uint32_t>( __CARDGetDirBlock( reinterpret_cast<void*>( card ) ) );
        uint32_t entry = dirBlock + ( fileNo * 0x40 );

        uint16_t* blockAddr = reinterpret_cast<uint16_t*>( entry + 0x36 );
        uint16_t* currFileBlockAddr = reinterpret_cast<uint16_t*>( card + 0xBE );
        *currFileBlockAddr = *blockAddr;

        memset( reinterpret_cast<void*>( entry ), -1, 0x40 );

        CARDCallback cb = callback;
        if ( !cb )
        {
            cb = __CARDDefaultApiCallback;
        }

        CARDCallback* cardApiCbAddress = reinterpret_cast<CARDCallback*>( card + 0xD0 );
        *cardApiCbAddress = cb;

        ret = __CARDUpdateDir( chan, DeleteCallback );
        if ( ret >= CARD_RESULT_READY )
        {
            return ret;
        }

        __CARDPutControlBlock( reinterpret_cast<void*>( card ), ret );
        return ret;
    }

    int32_t CARDDelete( int32_t chan, const char* fileName )
    {
        int32_t ret = CARDDeleteAsync( chan, fileName, __CARDSyncCallback );
        if ( ret >= CARD_RESULT_READY )
        {
            ret = __CARDSync( chan );
        }
        return ret;
    }
}     // namespace libtp::gc::card