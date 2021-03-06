// ---------- Messages ----------
enum RegisterAccountRequest
{
		eAccount_msg,
		ePassword[256]
};

enum RegisterAccountResponse
{
		eSuccess,
		eAccountId
};

enum LogInRequest
{
		eLogin[256],
		ePassword[256]
};

enum LogInResponse
{
		eSuccess,
		eAccountId
};

enum GetAccountCharactersResponse
{
		eCharacters_msg[256]
};

// ---------- Messages ----------
enum AccountID
{
		eId
};

enum Account
{
		eId,
		eLogin[256],
		eNick[256],
		eEmail[256]
};

// ---------- Messages ----------
//requests & response messages
enum DeathStreamRequest
{
		DeathType:eDeathTypes[256]
};

enum DeathStreamResponse
{
		eCharacter_msg,
		DeathType:eDeathType
};

// ---------- Enums ----------
enum DeathType
{
		DEATH_TYPE_NONE = 0, 
		DEATH_TYPE_BW = 1, 
		DEATH_TYPE_BW_KILL = 2, 
		DEATH_TYPE_CK = 3
};
// ---------- Messages ----------
enum Character
{
		eId,
		eOwnerId,
		eFirstName[256],
		eSecondName[256],
		eAge,
		eSex,
		ePosition_msg
};

enum CharacterID
{
		eId
};

// ---------- Messages ----------
enum ServiceStatusRequest
{
};

enum ServiceStatusResponse
{
		eStatus[256]
};

enum VersionRequest
{
};

enum VersionResponse
{
		eVersion[256],
		eBuildDate[256],
		eCommit[256],
		eOsArch[256]
};

// ---------- Messages ----------
enum Position
{
		Float:eX,
		Float:eY,
		Float:eZ
};

enum Rotation
{
		Float:eRx,
		Float:eRy,
		Float:eRz
};

// ---------- Messages ----------
enum GetGroupsRequest
{
		eLimit
};

enum GetGroupsResponse
{
		eGroups_msg[256]
};

enum AddGroupMemberRequest
{
};

enum AddGroupMemberResponse
{
};

enum RemoveGroupMemberRequest
{
};

enum RemoveGroupMemberResponse
{
};

// ---------- Messages ----------
enum PermissionID
{
		eId
};

enum Permission
{
		eId,
		eName[256],
		eRole[256]
};

enum GroupID
{
		eId
};

enum Group
{
		eId,
		eName[256],
		eDescription[256],
		ePermissions_msg[256],
		eMembers[256]
};

// ---------- Messages ----------
// Request message for `MruVItemsService.GetItems`.
enum GetItemsRequest
{
	// Limit of the returned items.
	eLimit
};

// Response message for `MruVItemsService.GetItems`.
enum GetItemsResponse
{
	// List of items.
	eItems_msg[256]
};

// Request message for `MruVItemsService.GetItemTypes`.
enum GetItemTypesRequest
{
	// Limit of the returned item types.
	eLimit
};

//Response message for `MruVItemsService.GetItemTypes`.
enum GetItemTypesResponse
{
	//List of item types.
	eItemTypes_msg[256]
};

//Request message for `MruVItemsService.GetContainers`.
enum GetContainersRequest
{
	//Limit of the returned containers.
	eLimit
};

//Response message for `MruVItemsService.GetContainers`.
enum GetContainersResponse
{
	//List of containers.
	eContainers_msg[256]
};

//Request message for `MruVItemsService.GetContainerTypes`.
enum GetContainerTypesRequest
{
	//Limit of the returned container types.
	eLimit
};

//Response message for `MruVItemsService.GetContainers`.
enum GetContainerTypesResponse
{
	//List of container types.
	eContainerTypes_msg[256]
};

//Request message for `MruVItemsService.PutItem`.
enum PutItemRequest
{
	//ID of container where to put item.
	eContainerId,
	//ID of item we wan to put in.
	eItemId,
	//Position used for sorting items
	eSlot
};

//Response message for `MruVItemsService.PutItem`
enum PutItemResponse
{
	//Container with items inside.
	eInsideItem_msg
};

//Request message for `MruVItemsService.GetContainerItems`.
enum GetContainerItemsRequest
{
	//ID of container with items.
	eContainerId,
	//Limit of the returned items.
	eLimit
};

//Request message for `MruVItemsService.GetContainerItems`.
enum GetContainerItemsResponse
{
	//List of items inside containers.
	eItems_msg[256]
};

//Request message for `MruVItemsService.PullItem`.
enum PullItemRequest
{
	//ID of the container from which we pull out a item.
	eContainerId,
	//ID of the item we want to pull out.
//That item must be inside the container.
	eItemId
};

//Request message for `MruVItemsService.SortItems`.
enum SortItemsRequest
{
	//ID of the container which contain items.
	eContainerId,
	//Sorting mode.
	SortingMode:eSortBy
};

//Response message for `MruVItemsService.SortItems`.
enum SortItemsResponse
{
	//Container with sorted items inside.
	eContainer_msg
};

//Request message for `MruVItemsService.GetNearestItems`.
enum GetNearestItemsRequest
{
	//Position from which to calculate the distance
	ePosition_msg,
	//ID of container that contains items.
	eContainerId,
	//The distance over which the items are ignored.
	Float:eDistanceLimit
};

//Response message for `MruVItemsService.GetNearestItems`.
enum GetNearestItemsResponse
{
	//List of items sorted from nearest to farthest.
	eItem_msg[256]
};

//Request message for `MruVItemsService.UseItem`.
enum UseItemRequest
{
		eItemId
};

//Response message for `MruVItemsService.UseItem`.
enum UseItemResponse
{
	//Is item usage was successful.
	eSuccess
};

// ---------- Enums ----------
//Sorting modes for container items.
enum SortingMode
{
	//undefined behaviour
	UNKNOWN = 0, 
	//sort by weight descending
	WEIGHT_DESC = 1, 
	//sort by weight ascending
	WEIGHT_ASC = 2, 
	//sort by volume descending
	VOLUME_DESC = 3, 
	//sort by volume ascending
	VOLUME_ASC = 4
};
// ---------- Messages ----------
//Item type data structure
enum ItemType
{
		eId,
	//Short name of item type.
	eName[256],
	//Description of item type.
	eDescription[256],
	//Default weight of items created with that item type.
	Float:eBaseWeight,
	//Default volume of items created with that item type.
	Float:eBaseVolume,
	//GTA V model name.
	eModelName[256],
	//GTA V model hash.
	eModelHash
};

//Item type ID.
enum ItemTypeID
{
		eId
};

//Item data structure.
enum Item
{
		eId,
	//ID of an item type.
	eItemTypeId,
	//Current weight of the item.
	Float:eWeight,
	//Current volume of the item.
	Float:eVolume
};

//Item ID.
enum ItemID
{
		eId
};

//Container type data structure.
enum ContainerType
{
		eId,
	//ID of an item type.
	eContainerItemTypeId,
	//Max items in the container.
	eMaxNumber,
	//Max volume of items in the container.
	Float:eMaxVolume,
	//Max weight of items in the container.
	Float:eMaxWeight,
		eValidItemTypes[256]
};

//Container type ID.
enum ContainerTypeID
{
		eId
};

//Container data structure.
enum Container
{
		eId,
	//ID of an container type.
	eTypeId,
	//ID of container item representing container.
	eItemId,
	//Number of items inside container.
	eItemsInside,
	//List of items inside container.
	eItems_msg[256]
};

//Container ID.
enum ContainerID
{
		eId
};

//Item inside container data structure.
enum InsideItem
{
	//ID of container containing the item.
	eContainerId,
		eItemId,
		eItem_msg,
	//Position representing order in container. In ascending manner.
	ePosition
};

// ---------- Messages ----------
// Request message for `MruVServerService.GetRegisteredServers`.
enum GetRegisteredServersRequest
{
};

// Response message for `MruVServerService.GetRegisteredServers`.
enum GetRegisteredServersResponse
{
		eServers_msg[256]
};

// Request message for `MruVServerService.UpdateServerStatus`.
enum UpdateServerStatusRequest
{
	// Id of the server.
	eId,
	// Status of the server.
	ServerStatus:eStatus,
	// How many players are registered on that server.
	ePlayers
};

// Response message for `MruVServerService.UpdateServerStatus`.
enum UpdateServerStatusResponse
{
};

// Request message for `MruVServerService.ServerEventsStream`.
enum ServerEventsStreamRequest
{
	// The ID of the server from which we want to receive events.
	eId
};

// Server event.
// Response message for `MruVServerService.ServerEventsStream`.
enum ServerEvent
{
	// Type of a server event.
	ServerEvent_ServerEventType:eType
};

// ---------- Enums ----------
enum ServerStatus
{
		UNKNOWN = 0, 
		ON = 1, 
		OFF = 2
};
// ---------- Messages ----------
enum ServerID
{
		eId
};

// Data that describe server.
enum ServerInfo
{
	// Id of the server.
	eId,
	// Short name of the server.
	eName[256],
	// Host (ip) of the server.
	eHost[256],
	// Port of the server.
	ePort[256],
	// Platform of the server.
	ePlatform[256],
	// Status of the server.
	ServerStatus:eStatus,
	// How many players are playing on the server.
	ePlayers
};

// ----- MruVAccountsService Natives -----

native bool:mvas_RegisterAccount(const i_Account[Account], const i_Password[], &o_Success, &o_AccountId);

native bool:mvas_LogIn(const i_Login[], const i_Password[], &o_Success, &o_AccountId);

native bool:mvas_GetAccount(const i_Id, &o_Id, o_Login[], o_Nick[], o_Email[]);

native bool:mvas_GetAccountCharacters(const i_Id, o_Characters[][Character]);

// ----- MruVCharactersService Natives -----

//CRUD
native bool:mvcs_CreateCharacter(const i_Id, const i_OwnerId, const i_FirstName[], const i_SecondName[], const i_Age, const i_Sex, const i_Position[Position], &o_Id);

native bool:mvcs_GetCharacter(const i_Id, &o_Id, &o_OwnerId, o_FirstName[], o_SecondName[], &o_Age, &o_Sex, o_Position[Position]);

native bool:mvcs_RemoveCharacter(const i_Id, &o_Id);

//Deaths
native bool:mvcs_PermanentCharacterKill(const i_Id, &o_Id);

native bool:mvcs_DeathsStream(const DeathType:i_DeathTypes[], o_Character[Character], &DeathType:o_DeathType);

//Service status
native bool:mvcs_GetServiceStatus(o_Status[]);

native bool:mvcs_GetServiceVersion(o_Version[], o_BuildDate[], o_Commit[], o_OsArch[]);

// ----- MruVGroupsService Natives -----

//CRUD
native bool:mvgs_CreateGroup(const i_Id, const i_Name[], const i_Description[], const i_Permissions[][Permission], const i_Members[], &o_Id);

native bool:mvgs_GetGroup(const i_Id, &o_Id, o_Name[], o_Description[], o_Permissions[][Permission], o_Members[]);

native bool:mvgs_DeleteGroup(const i_Id, &o_Id);

native bool:mvgs_GetGroups(const i_Limit, o_Groups[][Group]);

native bool:mvgs_AddGroupMember();

native bool:mvgs_RemoveGroupMember();

//Service status
native bool:mvgs_GetServiceStatus(o_Status[]);

native bool:mvgs_GetServiceVersion(o_Version[], o_BuildDate[], o_Commit[], o_OsArch[]);

// ----- MruVItemService Natives -----
// The MruV items service provides procedures for managing items and containers

//Create new item.
native bool:mvis_CreateItem(const i_Id, const i_ItemTypeId, const Float:i_Weight, const Float:i_Volume, &o_Id);

//Get item by id.
native bool:mvis_GetItem(const i_Id, &o_Id, &o_ItemTypeId, &Float:o_Weight, &Float:o_Volume);

//Delete item by id.
native bool:mvis_DeleteItem(const i_Id, &o_Id);

//Gets all items.
native bool:mvis_GetItems(const i_Limit, o_Items[][Item]);

//Create item type.
native bool:mvis_CreateItemType(const i_Id, const i_Name[], const i_Description[], const Float:i_BaseWeight, const Float:i_BaseVolume, const i_ModelName[], const i_ModelHash, &o_Id);

//Get item type by id.
native bool:mvis_GetItemType(const i_Id, &o_Id, o_Name[], o_Description[], &Float:o_BaseWeight, &Float:o_BaseVolume, o_ModelName[], &o_ModelHash);

//Delete item type by id.
native bool:mvis_DeleteItemType(const i_Id, &o_Id);

//Gets all item types.
native bool:mvis_GetItemTypes(const i_Limit, o_ItemTypes[][ItemType]);

//Create container.
native bool:mvis_CreateContainer(const i_Id, const i_TypeId, const i_ItemId, const i_ItemsInside, const i_Items[][InsideItem], &o_Id);

//Get container by id.
native bool:mvis_GetContainer(const i_Id, &o_Id, &o_TypeId, &o_ItemId, &o_ItemsInside, o_Items[][InsideItem]);

//Delete container by id.
native bool:mvis_DeleteContainer(const i_Id, &o_Id);

//Get all containers.
native bool:mvis_GetContainers(const i_Limit, o_Containers[][Container]);

//Create container type.
native bool:mvis_CreateContainerType(const i_Id, const i_ContainerItemTypeId, const i_MaxNumber, const Float:i_MaxVolume, const Float:i_MaxWeight, const i_ValidItemTypes[], &o_Id);

//Get container type by id.
native bool:mvis_GetContainerType(const i_Id, &o_Id, &o_ContainerItemTypeId, &o_MaxNumber, &Float:o_MaxVolume, &Float:o_MaxWeight, o_ValidItemTypes[]);

//Detele container type by id.
native bool:mvis_DeleteContainerType(const i_Id, &o_Id);

//Get all container types.
native bool:mvis_GetContainerTypes(const i_Limit, o_ContainerTypes[][ContainerType]);

//Get items inside a container.
native bool:mvis_GetContainerItems(const i_ContainerId, const i_Limit, o_Items[][InsideItem]);

//Pull item from container.
native bool:mvis_PullItem(const i_ContainerId, const i_ItemId, &o_Id, &o_ItemTypeId, &Float:o_Weight, &Float:o_Volume);

//Put item into container.
native bool:mvis_PutItem(const i_ContainerId, const i_ItemId, const i_Slot, o_InsideItem[InsideItem]);

//Sort items inside container.
//This procedure change order of items inside container.
native bool:mvis_SortItems(const i_ContainerId, const SortingMode:i_SortBy, o_Container[Container]);

//Retrieves from the container the list of items nearest to the given position.
native bool:mvis_GetNearestItems(const i_Position[Position], const i_ContainerId, const Float:i_DistanceLimit, o_Item[][InsideItem]);

//Trigger action associated with the item usage.
native bool:mvis_UseItem(const i_ItemId, &o_Success);

//Get service health status.
native bool:mvis_GetServiceStatus(o_Status[]);

//Get service current version.
native bool:mvis_GetServiceVersion(o_Version[], o_BuildDate[], o_Commit[], o_OsArch[]);

// ----- MruVServerService Natives -----
// The MruV server service provides procedures for managing game platform server actions.

// Register instance of server for further managing.
native bool:mvss_RegisterServer(const i_Id, const i_Name[], const i_Host[], const i_Port[], const i_Platform[], const ServerStatus:i_Status, const i_Players, &o_Id);

// Get all registered servers.
native bool:mvss_GetRegisteredServers(o_Servers[][ServerInfo]);

// Get game server status.
native bool:mvss_GetServerInfo(const i_Id, &o_Id, o_Name[], o_Host[], o_Port[], o_Platform[], &ServerStatus:o_Status, &o_Players);

// Update game server status.
native bool:mvss_UpdateServerStatus(const i_Id, const ServerStatus:i_Status, const i_Players);

// Stream of server events. Events are streamed back in real-time for chosen server.
native bool:mvss_ServerEventsStream(const i_Id, &ServerEvent_ServerEventType:o_Type);

