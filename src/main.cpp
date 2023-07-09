#include "sdk.hpp"

#include "version.hpp"
#include "common.hpp"
#include "natives.hpp"

logprint_f logprint;

AMX_NATIVE_INFO NATIVES[] =
{
    AMX_DEFINE_NATIVE(BigNumber_AddFloatNumber)
    AMX_DEFINE_NATIVE(BigNumber_FormatFloatNumber)
    AMX_DEFINE_NATIVE(BigNumber_IsFloatNumberGreater)

    AMX_DEFINE_NATIVE(BigNumber_AddIntNumber)
    AMX_DEFINE_NATIVE(BigNumber_FormatIntNumber)
    AMX_DEFINE_NATIVE(BigNumber_IsIntNumberGreater)

    { NULL, NULL }
};

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprint = reinterpret_cast<logprintf_t>(ppData[PLUGIN_DATA_LOGPRINTF]);
    logprint(" >> plugin.pawn-big-numbers: " PLUGIN_VERSION " successfully loaded.");
    return true;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
    logprint(" >> plugin.pawn-big-numbers: Plugin unloaded.");
}

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    return amx_Register(amx, NATIVES, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
    return AMX_ERR_NONE;
}