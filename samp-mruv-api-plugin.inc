// built-in include guard removal
// just in case the user has a local dependency with the same file name
#if defined _inc_SAMP_MRUV_API_PLUGIN
	#undef _inc_SAMP_MRUV_API_PLUGIN
#endif
// custom include-guard to ensure we don't duplicate
#if defined _SAMP_MRUV_API_PLUGIN_included
	#endinput
#endif
#define _SAMP_MRUV_API_PLUGIN_included

// Enums

// Items service
native mruv_itemsService_status();
native mruv_itemsService_version();

native mruv_itemTypes_create(&id, const name[], const description[], const Float:weight, const Float:volume, const model);
native mruv_itemTypes_create_async(const callback[], const name[], const description[], const Float:weight, const Float:volume, const model);
native mruv_itemTypes_get(const id);
native mruv_itemTypes_delete();
native mruv_itemTypes_getAll();

native mruv_items_create();
native mruv_items_get();
native mruv_items_delete();
native mruv_items_getAll();

native mruv_containerTypes_create();
native mruv_containerTypes_get();
native mruv_containerTypes_delete();
native mruv_containerTypes_getAll();

native mruv_containers_create();
native mruv_containers_get();
native mruv_containers_delete();
native mruv_containers_getAll();

// Accounts service

// Characters service

// Groups service

// Server service

