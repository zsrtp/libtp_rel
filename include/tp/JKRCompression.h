/**	@file JKRCompression.h
 *	@brief See https://github.com/zeldaret/tp/blob/master/include/JSystem/JKernel/JKRCompression.h
 *
 *	@author Isaac
 *	@bug
 */
#ifndef TP_JKRCOMPRESSION_H
#define TP_JKRCOMPRESSION_H

namespace libtp::tp
{
    typedef int JKRCompression;
    const JKRCompression COMPRESSION_NONE = 0;
    const JKRCompression COMPRESSION_YAY0 = 1;
    const JKRCompression COMPRESSION_YAZ0 = 2;
    const JKRCompression COMPRESSION_ASR = 3;
}     // namespace libtp::tp

#endif