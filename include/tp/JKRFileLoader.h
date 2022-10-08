/**	@file JKRFileLoader.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/JSystem/JKernel/JKRFileLoader.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_JKRFILELOADER_H
#define TP_JKRFILELOADER_H

#include <cstdint>

#include "tp/JKRDisposer.h"

namespace libtp::tp::JKRFileLoader
{
    class JKRFileFinder;
    class JKRFileLoader: public libtp::tp::JKRDisposer::JKRDisposer
    {
       public:
        /* 0x00 */                               // vtable
        /* 0x04 */                               // JKRDisposer
        /* 0x18 */ uint8_t field_0x18[0x10];     // JSULink<JKRFileLoader> mFileLoaderLink;
        /* 0x28 */ const char* mVolumeName;
        /* 0x2C */ uint32_t mVolumeType;
        /* 0x30 */ bool mIsMounted;
        /* 0x31 */ uint8_t field_0x31[3];
        /* 0x34 */ uint32_t mMountCount;
    };
}     // namespace libtp::tp::JKRFileLoader

#endif