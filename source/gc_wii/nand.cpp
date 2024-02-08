#include "gc_wii/nand.h"

namespace libtp::gc_wii::nand
{
    int32_t NANDReadDir(const char *dirName, char *fileList, uint32_t *numFiles)
    {
        if (!nandIsInitialized())
        {
            return NAND_RESULT_FATAL_ERROR;
        }

        const int32_t ret = ISFS_ReadDir(dirName, fileList, numFiles);
        return nandConvertErrorCode(ret);
    }
} // namespace libtp::gc_wii::nand