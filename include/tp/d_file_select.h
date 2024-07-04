#ifndef TP_D_FILESELECT_H
#define TP_D_FILESELECT_H

#include <cstdint>

namespace libtp::tp::d_file_select
{
    class dFile_select_c;

    extern "C"
    {
        void dFile_select_c___create(dFile_select_c* thisPtr);
    }
} // namespace libtp::tp::d_file_select

#endif