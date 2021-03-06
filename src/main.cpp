/*
# main.cpp

The "main" source file with most of the boilerplate code. Includes the
`NativesMain` header for initialising plugin-natives.

- `Supports` declares to the SA:MP server which features this plugin uses.
- `Load` is called when the plugin loads and sets up the `logprintf` function.
*/

#include <amx/amx.h>
#include <plugincommon.h>
#include <samplog/Api.hpp>

#include "impl.hpp"
#include "common.hpp"
#include "natives.hpp"

#include "API.h"
#include "CCallback.hpp"
#include "CLog.hpp"

logprintf_t logprintf;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports() {
    return SUPPORTS_VERSION | SUPPORTS_AMX_NATIVES;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) {
    pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
    logprintf = (logprintf_t) ppData[PLUGIN_DATA_LOGPRINTF];

    logprintf("==========================================");
    logprintf("|                                        |");
    logprintf("|            MruV API plugin             |");
    logprintf("|                 v0.0.1                 |");
    logprintf("|                                        |");
    logprintf("| * Connecting to MruV-API...            |");
    API::Get()->Connect(5);
    logprintf("| * MruV-API plugin was loaded.          |");
    logprintf("==========================================");

    CLog::Get()->Log(LogLevel::INFO, "Plugin was loaded.");
    return true;
}

extern "C" const AMX_NATIVE_INFO native_list[] = {
        AMX_DEFINE_NATIVE(mvas_RegisterAccount)
        AMX_DEFINE_NATIVE(mvas_LogIn)
        AMX_DEFINE_NATIVE(mvas_GetAccount)
        AMX_DEFINE_NATIVE(mvas_GetAccountCharacters)
        AMX_DEFINE_NATIVE(mvcs_CreateCharacter)
        AMX_DEFINE_NATIVE(mvcs_GetCharacter)
        AMX_DEFINE_NATIVE(mvcs_RemoveCharacter)
        AMX_DEFINE_NATIVE(mvcs_PermanentCharacterKill)
        AMX_DEFINE_NATIVE(mvcs_GetServiceStatus)
        AMX_DEFINE_NATIVE(mvcs_GetServiceVersion)
        AMX_DEFINE_NATIVE(mvgs_CreateGroup)
        AMX_DEFINE_NATIVE(mvgs_GetGroup)
        AMX_DEFINE_NATIVE(mvgs_DeleteGroup)
        AMX_DEFINE_NATIVE(mvgs_GetGroups)
        AMX_DEFINE_NATIVE(mvgs_AddGroupMember)
        AMX_DEFINE_NATIVE(mvgs_RemoveGroupMember)
        AMX_DEFINE_NATIVE(mvgs_GetServiceStatus)
        AMX_DEFINE_NATIVE(mvgs_GetServiceVersion)
        AMX_DEFINE_NATIVE(mvis_CreateItem)
        AMX_DEFINE_NATIVE(mvis_GetItem)
        AMX_DEFINE_NATIVE(mvis_DeleteItem)
        AMX_DEFINE_NATIVE(mvis_GetItems)
        AMX_DEFINE_NATIVE(mvis_CreateItemType)
        AMX_DEFINE_NATIVE(mvis_GetItemType)
        AMX_DEFINE_NATIVE(mvis_DeleteItemType)
        AMX_DEFINE_NATIVE(mvis_GetItemTypes)
        AMX_DEFINE_NATIVE(mvis_CreateContainer)
        AMX_DEFINE_NATIVE(mvis_GetContainer)
        AMX_DEFINE_NATIVE(mvis_DeleteContainer)
        AMX_DEFINE_NATIVE(mvis_GetContainers)
        AMX_DEFINE_NATIVE(mvis_CreateContainerType)
        AMX_DEFINE_NATIVE(mvis_GetContainerType)
        AMX_DEFINE_NATIVE(mvis_DeleteContainerType)
        AMX_DEFINE_NATIVE(mvis_GetContainerTypes)
        AMX_DEFINE_NATIVE(mvis_GetContainerItems)
        AMX_DEFINE_NATIVE(mvis_PullItem)
        AMX_DEFINE_NATIVE(mvis_PutItem)
        AMX_DEFINE_NATIVE(mvis_SortItems)
        AMX_DEFINE_NATIVE(mvis_GetNearestItems)
        AMX_DEFINE_NATIVE(mvis_UseItem)
        AMX_DEFINE_NATIVE(mvis_GetServiceStatus)
        AMX_DEFINE_NATIVE(mvis_GetServiceVersion)
        AMX_DEFINE_NATIVE(mvss_RegisterServer)
        AMX_DEFINE_NATIVE(mvss_GetRegisteredServers)
        AMX_DEFINE_NATIVE(mvss_GetServerInfo)
        AMX_DEFINE_NATIVE(mvss_UpdateServerStatus)
        {nullptr, nullptr}
};

PLUGIN_EXPORT int PLUGIN_CALL AmxLoad(AMX *amx) {
    samplog::Api::Get()->RegisterAmx(amx);
    CCallbackManager::Get()->AddAmx(amx);
    return amx_Register(amx, native_list, -1);
}

PLUGIN_EXPORT int PLUGIN_CALL Unload() {
    logprintf("==========================================");
    logprintf("|                                        |");
    logprintf("|            MruV API plugin             |");
    logprintf("|                 v0.0.1                 |");
    logprintf("|                                        |");
    logprintf("| * Unloading plugin...                  |");

    API::Destroy();
    CCallbackManager::CSingleton::Destroy();
    CLog::CSingleton::Destroy();
    samplog::Api::Destroy();

    logprintf("| * MruV-API plugin was unloaded.        |");
    logprintf("==========================================");
    return 1;
}

PLUGIN_EXPORT int PLUGIN_CALL AmxUnload(AMX *amx) {
    samplog::Api::Get()->EraseAmx(amx);
    CCallbackManager::Get()->RemoveAmx(amx);
    return 1;
}
