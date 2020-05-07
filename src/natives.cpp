/*
# natives.cpp

This source file contains the bridge between natives and implementations. I
prefer to keep the actual implementation separate. The implementation contains
no instances of `cell` or `AMX*` and is purely C++ and external library code.
The code here acts as the translation between AMX data types and native types.
*/

#include "natives.hpp"
#include "impl.hpp"

using namespace Impl;
using grpc::ClientContext;


// native mvas_RegisterAccount(const i_Account[Account], const i_Password[], &o_Success, &o_AccountId);
cell Natives::mvas_RegisterAccount(AMX *amx, cell *params) {
    RegisterAccountRequest request;
    RegisterAccountResponse response;
    ClientContext context;
    
	// construct request from params
	// TODO: message
	request.set_password(amx_GetCppString(amx, params[2]));

    // RPC call.
    Status status = API::Get().MruVAccountsServiceStub()->RegisterAccount(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[4], &addr);
		*addr = response.account_id();

	}
    return status.ok();
}

// native mvas_LogIn(const i_Login[], const i_Password[], &o_Success, &o_AccountId);
cell Natives::mvas_LogIn(AMX *amx, cell *params) {
    LogInRequest request;
    LogInResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_login(amx_GetCppString(amx, params[1]));
	request.set_password(amx_GetCppString(amx, params[2]));

    // RPC call.
    Status status = API::Get().MruVAccountsServiceStub()->LogIn(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[4], &addr);
		*addr = response.account_id();

	}
    return status.ok();
}

// native mvas_GetAccount(const i_Id, &o_Id, o_Login[], o_Nick[], o_Email[]);
cell Natives::mvas_GetAccount(AMX *amx, cell *params) {
    AccountID request;
    Account response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVAccountsServiceStub()->GetAccount(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_SetCppString(amx, params[3], response.login(), 256);
		amx_SetCppString(amx, params[4], response.nick(), 256);
		amx_SetCppString(amx, params[5], response.email(), 256);

	}
    return status.ok();
}

// native mvas_GetAccountCharacters(const i_Id, o_Characters[][Character]);
cell Natives::mvas_GetAccountCharacters(AMX *amx, cell *params) {
    AccountID request;
    GetAccountCharactersResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVAccountsServiceStub()->GetAccountCharacters(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvcs_CreateCharacter(const i_Id, const i_OwnerId, const i_FirstName[], const i_SecondName[], const i_Age, const i_Sex, const i_Position[Position], &o_Id);
cell Natives::mvcs_CreateCharacter(AMX *amx, cell *params) {
    Character request;
    CharacterID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);
	request.set_owner_id(params[2]);
	request.set_first_name(amx_GetCppString(amx, params[3]));
	request.set_second_name(amx_GetCppString(amx, params[4]));
	request.set_age(params[5]);
	request.set_sex(params[6]);
	// TODO: message

    // RPC call.
    Status status = API::Get().MruVCharactersServiceStub()->CreateCharacter(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[8], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvcs_GetCharacter(const i_Id, &o_Id, &o_OwnerId, o_FirstName[], o_SecondName[], &o_Age, &o_Sex, o_Position[Position]);
cell Natives::mvcs_GetCharacter(AMX *amx, cell *params) {
    CharacterID request;
    Character response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVCharactersServiceStub()->GetCharacter(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_GetAddr(amx, params[3], &addr);
		*addr = response.owner_id();
		amx_SetCppString(amx, params[4], response.first_name(), 256);
		amx_SetCppString(amx, params[5], response.second_name(), 256);
		amx_GetAddr(amx, params[6], &addr);
		*addr = response.age();
		amx_GetAddr(amx, params[7], &addr);
		*addr = response.sex();
		// TODO: message

	}
    return status.ok();
}

// native mvcs_RemoveCharacter(const i_Id, &o_Id);
cell Natives::mvcs_RemoveCharacter(AMX *amx, cell *params) {
    CharacterID request;
    CharacterID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVCharactersServiceStub()->RemoveCharacter(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvcs_PermanentCharacterKill(const i_Id, &o_Id);
cell Natives::mvcs_PermanentCharacterKill(AMX *amx, cell *params) {
    CharacterID request;
    CharacterID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVCharactersServiceStub()->PermanentCharacterKill(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvcs_GetServiceStatus(o_Status[]);
cell Natives::mvcs_GetServiceStatus(AMX *amx, cell *params) {
    ServiceStatusRequest request;
    ServiceStatusResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVCharactersServiceStub()->GetServiceStatus(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_SetCppString(amx, params[1], response.status(), 256);

	}
    return status.ok();
}

// native mvcs_GetServiceVersion(o_Version[], o_BuildDate[], o_Commit[], o_OsArch[]);
cell Natives::mvcs_GetServiceVersion(AMX *amx, cell *params) {
    VersionRequest request;
    VersionResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVCharactersServiceStub()->GetServiceVersion(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_SetCppString(amx, params[1], response.version(), 256);
		amx_SetCppString(amx, params[2], response.build_date(), 256);
		amx_SetCppString(amx, params[3], response.commit(), 256);
		amx_SetCppString(amx, params[4], response.os_arch(), 256);

	}
    return status.ok();
}

// native mvgs_CreateGroup(const i_Id, const i_Name[], const i_Description[], const i_Permissions[][Permission], const i_Members[], &o_Id);
cell Natives::mvgs_CreateGroup(AMX *amx, cell *params) {
    Group request;
    GroupID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);
	request.set_name(amx_GetCppString(amx, params[2]));
	request.set_description(amx_GetCppString(amx, params[3]));
		// todo: list
		// todo: list

    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->CreateGroup(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[6], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvgs_GetGroup(const i_Id, &o_Id, o_Name[], o_Description[], o_Permissions[][Permission], o_Members[]);
cell Natives::mvgs_GetGroup(AMX *amx, cell *params) {
    GroupID request;
    Group response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->GetGroup(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_SetCppString(amx, params[3], response.name(), 256);
		amx_SetCppString(amx, params[4], response.description(), 256);
		// todo: list
		// todo: list

	}
    return status.ok();
}

// native mvgs_DeleteGroup(const i_Id, &o_Id);
cell Natives::mvgs_DeleteGroup(AMX *amx, cell *params) {
    GroupID request;
    GroupID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->DeleteGroup(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvgs_GetGroups(const i_Limit, o_Groups[][Group]);
cell Natives::mvgs_GetGroups(AMX *amx, cell *params) {
    GetGroupsRequest request;
    GetGroupsResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_limit(params[1]);

    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->GetGroups(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvgs_AddGroupMember();
cell Natives::mvgs_AddGroupMember(AMX *amx, cell *params) {
    AddGroupMemberRequest request;
    AddGroupMemberResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->AddGroupMember(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;

	}
    return status.ok();
}

// native mvgs_RemoveGroupMember();
cell Natives::mvgs_RemoveGroupMember(AMX *amx, cell *params) {
    RemoveGroupMemberRequest request;
    RemoveGroupMemberResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->RemoveGroupMember(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;

	}
    return status.ok();
}

// native mvgs_GetServiceStatus(o_Status[]);
cell Natives::mvgs_GetServiceStatus(AMX *amx, cell *params) {
    ServiceStatusRequest request;
    ServiceStatusResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->GetServiceStatus(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_SetCppString(amx, params[1], response.status(), 256);

	}
    return status.ok();
}

// native mvgs_GetServiceVersion(o_Version[], o_BuildDate[], o_Commit[], o_OsArch[]);
cell Natives::mvgs_GetServiceVersion(AMX *amx, cell *params) {
    VersionRequest request;
    VersionResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVGroupsServiceStub()->GetServiceVersion(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_SetCppString(amx, params[1], response.version(), 256);
		amx_SetCppString(amx, params[2], response.build_date(), 256);
		amx_SetCppString(amx, params[3], response.commit(), 256);
		amx_SetCppString(amx, params[4], response.os_arch(), 256);

	}
    return status.ok();
}

// native mvis_CreateItem(const i_Id, const i_ItemTypeId, const Float:i_Weight, const Float:i_Volume, &o_Id);
cell Natives::mvis_CreateItem(AMX *amx, cell *params) {
    Item request;
    ItemID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);
	request.set_item_type_id(params[2]);
	request.set_weight(amx_ctof(params[3]));
	request.set_volume(amx_ctof(params[4]));

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->CreateItem(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[5], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetItem(const i_Id, &o_Id, &o_ItemTypeId, &Float:o_Weight, &Float:o_Volume);
cell Natives::mvis_GetItem(AMX *amx, cell *params) {
    ItemID request;
    Item response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetItem(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_GetAddr(amx, params[3], &addr);
		*addr = response.item_type_id();
		amx_GetAddr(amx, params[4], &addr);
		float weight = response.weight();
		*addr = amx_ftoc(weight);
		amx_GetAddr(amx, params[5], &addr);
		float volume = response.volume();
		*addr = amx_ftoc(volume);

	}
    return status.ok();
}

// native mvis_DeleteItem(const i_Id, &o_Id);
cell Natives::mvis_DeleteItem(AMX *amx, cell *params) {
    ItemID request;
    ItemID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->DeleteItem(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetItems(const i_Limit, o_Items[][Item]);
cell Natives::mvis_GetItems(AMX *amx, cell *params) {
    GetItemsRequest request;
    GetItemsResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_limit(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetItems(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvis_CreateItemType(const i_Id, const i_Name[], const i_Description[], const Float:i_BaseWeight, const Float:i_BaseVolume, const i_ModelName[], const i_ModelHash, &o_Id);
cell Natives::mvis_CreateItemType(AMX *amx, cell *params) {
    ItemType request;
    ItemTypeID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);
	request.set_name(amx_GetCppString(amx, params[2]));
	request.set_description(amx_GetCppString(amx, params[3]));
	request.set_base_weight(amx_ctof(params[4]));
	request.set_base_volume(amx_ctof(params[5]));
	request.set_model_name(amx_GetCppString(amx, params[6]));
	request.set_model_hash(params[7]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->CreateItemType(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[8], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetItemType(const i_Id, &o_Id, o_Name[], o_Description[], &Float:o_BaseWeight, &Float:o_BaseVolume, o_ModelName[], &o_ModelHash);
cell Natives::mvis_GetItemType(AMX *amx, cell *params) {
    ItemTypeID request;
    ItemType response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetItemType(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_SetCppString(amx, params[3], response.name(), 256);
		amx_SetCppString(amx, params[4], response.description(), 256);
		amx_GetAddr(amx, params[5], &addr);
		float base_weight = response.base_weight();
		*addr = amx_ftoc(base_weight);
		amx_GetAddr(amx, params[6], &addr);
		float base_volume = response.base_volume();
		*addr = amx_ftoc(base_volume);
		amx_SetCppString(amx, params[7], response.model_name(), 256);
		amx_GetAddr(amx, params[8], &addr);
		*addr = response.model_hash();

	}
    return status.ok();
}

// native mvis_DeleteItemType(const i_Id, &o_Id);
cell Natives::mvis_DeleteItemType(AMX *amx, cell *params) {
    ItemTypeID request;
    ItemTypeID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->DeleteItemType(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetItemTypes(const i_Limit, o_ItemTypes[][ItemType]);
cell Natives::mvis_GetItemTypes(AMX *amx, cell *params) {
    GetItemTypesRequest request;
    GetItemTypesResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_limit(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetItemTypes(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvis_CreateContainer(const i_Id, const i_TypeId, const i_ItemId, const i_ItemsInside, const i_Items[][InsideItem], &o_Id);
cell Natives::mvis_CreateContainer(AMX *amx, cell *params) {
    Container request;
    ContainerID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);
	request.set_type_id(params[2]);
	request.set_item_id(params[3]);
	request.set_items_inside(params[4]);
		// todo: list

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->CreateContainer(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[6], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetContainer(const i_Id, &o_Id, &o_TypeId, &o_ItemId, &o_ItemsInside, o_Items[][InsideItem]);
cell Natives::mvis_GetContainer(AMX *amx, cell *params) {
    ContainerID request;
    Container response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetContainer(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_GetAddr(amx, params[3], &addr);
		*addr = response.type_id();
		amx_GetAddr(amx, params[4], &addr);
		*addr = response.item_id();
		amx_GetAddr(amx, params[5], &addr);
		*addr = response.items_inside();
		// todo: list

	}
    return status.ok();
}

// native mvis_DeleteContainer(const i_Id, &o_Id);
cell Natives::mvis_DeleteContainer(AMX *amx, cell *params) {
    ContainerID request;
    ContainerID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->DeleteContainer(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetContainers(const i_Limit, o_Containers[][Container]);
cell Natives::mvis_GetContainers(AMX *amx, cell *params) {
    GetContainersRequest request;
    GetContainersResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_limit(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetContainers(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvis_CreateContainerType(const i_Id, const i_ContainerItemTypeId, const i_MaxNumber, const Float:i_MaxVolume, const Float:i_MaxWeight, const i_ValidItemTypes[], &o_Id);
cell Natives::mvis_CreateContainerType(AMX *amx, cell *params) {
    ContainerType request;
    ContainerTypeID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);
	request.set_container_item_type_id(params[2]);
	request.set_max_number(params[3]);
	request.set_max_volume(amx_ctof(params[4]));
	request.set_max_weight(amx_ctof(params[5]));
		// todo: list

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->CreateContainerType(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[7], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetContainerType(const i_Id, &o_Id, &o_ContainerItemTypeId, &o_MaxNumber, &Float:o_MaxVolume, &Float:o_MaxWeight, o_ValidItemTypes[]);
cell Natives::mvis_GetContainerType(AMX *amx, cell *params) {
    ContainerTypeID request;
    ContainerType response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetContainerType(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();
		amx_GetAddr(amx, params[3], &addr);
		*addr = response.container_item_type_id();
		amx_GetAddr(amx, params[4], &addr);
		*addr = response.max_number();
		amx_GetAddr(amx, params[5], &addr);
		float max_volume = response.max_volume();
		*addr = amx_ftoc(max_volume);
		amx_GetAddr(amx, params[6], &addr);
		float max_weight = response.max_weight();
		*addr = amx_ftoc(max_weight);
		// todo: list

	}
    return status.ok();
}

// native mvis_DeleteContainerType(const i_Id, &o_Id);
cell Natives::mvis_DeleteContainerType(AMX *amx, cell *params) {
    ContainerTypeID request;
    ContainerTypeID response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->DeleteContainerType(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[2], &addr);
		*addr = response.id();

	}
    return status.ok();
}

// native mvis_GetContainerTypes(const i_Limit, o_ContainerTypes[][ContainerType]);
cell Natives::mvis_GetContainerTypes(AMX *amx, cell *params) {
    GetContainerTypesRequest request;
    GetContainerTypesResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_limit(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetContainerTypes(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvis_GetContainerItems(const i_ContainerId, const i_Limit, o_Items[][InsideItem]);
cell Natives::mvis_GetContainerItems(AMX *amx, cell *params) {
    GetContainerItemsRequest request;
    GetContainerItemsResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_container_id(params[1]);
	request.set_limit(params[2]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetContainerItems(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvis_PullItem(const i_ContainerId, const i_ItemId, &o_Id, &o_ItemTypeId, &Float:o_Weight, &Float:o_Volume);
cell Natives::mvis_PullItem(AMX *amx, cell *params) {
    PullItemRequest request;
    Item response;
    ClientContext context;
    
	// construct request from params
	request.set_container_id(params[1]);
	request.set_item_id(params[2]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->PullItem(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[3], &addr);
		*addr = response.id();
		amx_GetAddr(amx, params[4], &addr);
		*addr = response.item_type_id();
		amx_GetAddr(amx, params[5], &addr);
		float weight = response.weight();
		*addr = amx_ftoc(weight);
		amx_GetAddr(amx, params[6], &addr);
		float volume = response.volume();
		*addr = amx_ftoc(volume);

	}
    return status.ok();
}

// native mvis_PutItem(const i_ContainerId, const i_ItemId, const i_Slot, o_InsideItem[InsideItem]);
cell Natives::mvis_PutItem(AMX *amx, cell *params) {
    PutItemRequest request;
    PutItemResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_container_id(params[1]);
	request.set_item_id(params[2]);
	request.set_slot(params[3]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->PutItem(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// TODO: message

	}
    return status.ok();
}

// native mvis_SortItems(const i_ContainerId, const SortingMode:i_SortBy, o_Container[Container]);
cell Natives::mvis_SortItems(AMX *amx, cell *params) {
    SortItemsRequest request;
    SortItemsResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_container_id(params[1]);
	request.set_sort_by(static_cast<SortingMode>(params[2]));

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->SortItems(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// TODO: message

	}
    return status.ok();
}

// native mvis_GetNearestItems(const i_Position[Position], const i_ContainerId, const Float:i_DistanceLimit, o_Item[][InsideItem]);
cell Natives::mvis_GetNearestItems(AMX *amx, cell *params) {
    GetNearestItemsRequest request;
    GetNearestItemsResponse response;
    ClientContext context;
    
	// construct request from params
	// TODO: message
	request.set_container_id(params[2]);
	request.set_distance_limit(amx_ctof(params[3]));

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetNearestItems(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		// todo: list

	}
    return status.ok();
}

// native mvis_UseItem(const i_ItemId, &o_Success);
cell Natives::mvis_UseItem(AMX *amx, cell *params) {
    UseItemRequest request;
    UseItemResponse response;
    ClientContext context;
    
	// construct request from params
	request.set_item_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->UseItem(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;

	}
    return status.ok();
}

// native mvis_GetServiceStatus(o_Status[]);
cell Natives::mvis_GetServiceStatus(AMX *amx, cell *params) {
    ServiceStatusRequest request;
    ServiceStatusResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetServiceStatus(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_SetCppString(amx, params[1], response.status(), 256);

	}
    return status.ok();
}

// native mvis_GetServiceVersion(o_Version[], o_BuildDate[], o_Commit[], o_OsArch[]);
cell Natives::mvis_GetServiceVersion(AMX *amx, cell *params) {
    VersionRequest request;
    VersionResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVItemServiceStub()->GetServiceVersion(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_SetCppString(amx, params[1], response.version(), 256);
		amx_SetCppString(amx, params[2], response.build_date(), 256);
		amx_SetCppString(amx, params[3], response.commit(), 256);
		amx_SetCppString(amx, params[4], response.os_arch(), 256);

	}
    return status.ok();
}

// native mvss_RegisterServer();
cell Natives::mvss_RegisterServer(AMX *amx, cell *params) {
    RegisterServerRequest request;
    RegisterServerResponse response;
    ClientContext context;
    
    // RPC call.
    Status status = API::Get().MruVServerServiceStub()->RegisterServer(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;

	}
    return status.ok();
}

// native mvss_GetServerStatus(const i_Id, &o_Active, &o_Players);
cell Natives::mvss_GetServerStatus(AMX *amx, cell *params) {
    ServerID request;
    ServerStatus response;
    ClientContext context;
    
	// construct request from params
	request.set_id(params[1]);

    // RPC call.
    Status status = API::Get().MruVServerServiceStub()->GetServerStatus(&context, request, &response);
    API::Get().setLastStatus(status);
    
	// convert response to amx structure
	if(status.ok())
	{
		cell* addr = NULL;
		amx_GetAddr(amx, params[3], &addr);
		*addr = response.players();

	}
    return status.ok();
}
