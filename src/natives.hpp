#pragma once

#include "sdk.hpp"

#define AMX_DECLARE_NATIVE(native) \
    cell AMX_NATIVE_CALL native(AMX *amx, cell *params)

#define AMX_DEFINE_NATIVE(native) \
    {#native, Native::native},

namespace Native
{
    AMX_DECLARE_NATIVE(BigNumber_AddFloatNumber);
    AMX_DECLARE_NATIVE(BigNumber_FormatFloatNumber);
    AMX_DECLARE_NATIVE(BigNumber_IsFloatNumberGreater);

    AMX_DECLARE_NATIVE(BigNumber_AddIntNumber);
    AMX_DECLARE_NATIVE(BigNumber_FormatIntNumber);
    AMX_DECLARE_NATIVE(BigNumber_IsIntNumberGreater);
}