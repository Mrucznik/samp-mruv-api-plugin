/*
# main.cpp

The "main" source file with most of the boilerplate code. Includes the
`NativesMain` header for initialising plugin-natives.

- `Supports` declares to the SA:MP server which features this plugin uses.
- `Load` is called when the plugin loads and sets up the `logprintf` function.
*/

#include <amx/amx.h>
#include <plugincommon.h>

#include "impl.hpp"
#include "common.hpp"
#include "natives.hpp"

using Impl::API;

logprintf_t logprintf;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void** ppData)
{
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t)ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf("==========================================");
    logprintf("|                                        |");
    logprintf("|            MruV API plugin             |");
    logprintf("|                 v0.0.1                 |");
    logprintf("|                                        |");
    logprintf("| * Connecting to MruV-API...            |");
    API::Get().Connect(5);
    logprintf("| * MruV-API plugin was loaded.          |");
    logprintf("==========================================");
    return true;
}

extern "C" const AMX_NATIVE_INFO native_list[] = {
    AMX_DEFINE_NATIVE(mruv_itemsService_status)
    AMX_DEFINE_NATIVE(mruv_itemsService_version)

    AMX_DEFINE_NATIVE(mruv_itemTypes_create)
    AMX_DEFINE_NATIVE(mruv_itemTypes_get)
    AMX_DEFINE_NATIVE(mruv_itemTypes_delete)
    AMX_DEFINE_NATIVE(mruv_itemTypes_getAll)

    AMX_DEFINE_NATIVE(mruv_items_create)
    AMX_DEFINE_NATIVE(mruv_items_get)
    AMX_DEFINE_NATIVE(mruv_items_delete)
    AMX_DEFINE_NATIVE(mruv_items_getAll)

    AMX_DEFINE_NATIVE(mruv_containerTypes_create)
    AMX_DEFINE_NATIVE(mruv_containerTypes_get)
    AMX_DEFINE_NATIVE(mruv_containerTypes_delete)
    AMX_DEFINE_NATIVE(mruv_containerTypes_getAll)

    AMX_DEFINE_NATIVE(mruv_containers_create)
    AMX_DEFINE_NATIVE(mruv_containers_get)
    AMX_DEFINE_NATIVE(mruv_containers_delete)
    AMX_DEFINE_NATIVE(mruv_containers_getAll)
    { NULL, NULL }
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX* amx)
{
    return amx_Register(amx, native_list, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload()
{
    logprintf("==========================================");
    logprintf("|                                        |");
    logprintf("|            MruV API plugin             |");
    logprintf("|                 v0.0.1                 |");
    logprintf("|                                        |");
    logprintf("| * MruV-API plugin was unloaded.        |");
    logprintf("==========================================");
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX* amx)
{
    return 1;
}
