/*
# natives.hpp

Contains all the `PAWN_NATIVE_DECL` for native function declarations.
*/

#ifndef MRUVAPI_NATIVES_H
#define MRUVAPI_NATIVES_H

#include <string>
#include <amx/amx2.h>
#include "common.hpp"

#define AMX_DEFINE_NATIVE(native) \
	{#native, Natives::native},

namespace Natives {

    cell mvis_CreateItem(AMX *amx, cell *params);

    cell mvis_GetItem(AMX *amx, cell *params);

    cell mvis_DeleteItem(AMX *amx, cell *params);

    cell mvis_GetItems(AMX *amx, cell *params);

    cell mvis_CreateItemType(AMX *amx, cell *params);

    cell mvis_GetItemType(AMX *amx, cell *params);

    cell mvis_DeleteItemType(AMX *amx, cell *params);

    cell mvis_GetItemTypes(AMX *amx, cell *params);

    cell mvis_CreateContainer(AMX *amx, cell *params);

    cell mvis_GetContainer(AMX *amx, cell *params);

    cell mvis_DeleteContainer(AMX *amx, cell *params);

    cell mvis_GetContainers(AMX *amx, cell *params);

    cell mvis_CreateContainerType(AMX *amx, cell *params);

    cell mvis_GetContainerType(AMX *amx, cell *params);

    cell mvis_DeleteContainerType(AMX *amx, cell *params);

    cell mvis_GetContainerTypes(AMX *amx, cell *params);

    cell mvis_GetContainerItems(AMX *amx, cell *params);

    cell mvis_PullItem(AMX *amx, cell *params);

    cell mvis_PutItem(AMX *amx, cell *params);

    cell mvis_SortItems(AMX *amx, cell *params);

    cell mvis_GetNearestItems(AMX *amx, cell *params);

    cell mvis_UseItem(AMX *amx, cell *params);

    cell mvas_RegisterAccount(AMX *amx, cell *params);

    cell mvas_LogIn(AMX *amx, cell *params);

    cell mvas_GetAccount(AMX *amx, cell *params);

    cell mvas_GetAccountCharacters(AMX *amx, cell *params);

    cell mvcs_CreateCharacter(AMX *amx, cell *params);

    cell mvcs_GetCharacter(AMX *amx, cell *params);

    cell mvcs_RemoveCharacter(AMX *amx, cell *params);

    cell mvcs_PermanentCharacterKill(AMX *amx, cell *params);

    cell mvcs_GetServiceStatus(AMX *amx, cell *params);

    cell mvcs_GetServiceVersion(AMX *amx, cell *params);

    cell mvdts_GetPositions(AMX *amx, cell *params);

    cell mvdts_SavePosition(AMX *amx, cell *params);

    cell mvdts_DeletePosition(AMX *amx, cell *params);

    cell mvdts_GetOutfits(AMX *amx, cell *params);

    cell mvdts_SaveOutfit(AMX *amx, cell *params);

    cell mvdts_GetAnimations(AMX *amx, cell *params);

    cell mvdts_GetAnimation(AMX *amx, cell *params);

    cell mvdts_SaveAnimation(AMX *amx, cell *params);

    cell mvdts_GetServiceStatus(AMX *amx, cell *params);

    cell mvdts_GetServiceVersion(AMX *amx, cell *params);

    cell mvgs_CreateGroup(AMX *amx, cell *params);

    cell mvgs_GetGroup(AMX *amx, cell *params);

    cell mvgs_DeleteGroup(AMX *amx, cell *params);

    cell mvgs_GetGroups(AMX *amx, cell *params);

    cell mvgs_AddGroupMember(AMX *amx, cell *params);

    cell mvgs_RemoveGroupMember(AMX *amx, cell *params);

    cell mvgs_GetServiceStatus(AMX *amx, cell *params);

    cell mvgs_GetServiceVersion(AMX *amx, cell *params);

    cell mvis_GetServiceStatus(AMX *amx, cell *params);

    cell mvis_GetServiceVersion(AMX *amx, cell *params);

    cell mvss_RegisterServer(AMX *amx, cell *params);

    cell mvss_GetServerStatus(AMX *amx, cell *params);

    cell mvcs_GetServiceStatus(AMX *amx, cell *params);

    cell mvcs_GetServiceVersion(AMX *amx, cell *params);

    cell mvdts_GetPositions(AMX *amx, cell *params);

    cell mvdts_SavePosition(AMX *amx, cell *params);

    cell mvdts_DeletePosition(AMX *amx, cell *params);

    cell mvdts_GetOutfits(AMX *amx, cell *params);

    cell mvdts_SaveOutfit(AMX *amx, cell *params);

    cell mvdts_GetAnimations(AMX *amx, cell *params);

    cell mvdts_GetAnimation(AMX *amx, cell *params);

    cell mvdts_SaveAnimation(AMX *amx, cell *params);

    cell mvdts_GetServiceStatus(AMX *amx, cell *params);

    cell mvdts_GetServiceVersion(AMX *amx, cell *params);

    cell mvgs_CreateGroup(AMX *amx, cell *params);

    cell mvgs_GetGroup(AMX *amx, cell *params);

    cell mvgs_DeleteGroup(AMX *amx, cell *params);

    cell mvgs_GetGroups(AMX *amx, cell *params);

    cell mvgs_AddGroupMember(AMX *amx, cell *params);

    cell mvgs_RemoveGroupMember(AMX *amx, cell *params);

    cell mvgs_GetServiceStatus(AMX *amx, cell *params);

    cell mvgs_GetServiceVersion(AMX *amx, cell *params);

    cell mvis_GetServiceStatus(AMX *amx, cell *params);
}

#endif
