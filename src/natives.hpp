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
    //version
    cell mruv_itemsService_version(AMX *amx, cell *params);
    cell mruv_itemsService_status(AMX *amx, cell *params);

    cell mruv_itemTypes_create(AMX *amx, cell *params);
    cell mruv_itemTypes_get(AMX *amx, cell *params);
    cell mruv_itemTypes_delete(AMX *amx, cell *params);
    cell mruv_itemTypes_getAll(AMX *amx, cell *params);

    cell mruv_items_create(AMX *amx, cell *params);
    cell mruv_items_get(AMX *amx, cell *params);
    cell mruv_items_delete(AMX *amx, cell *params);
    cell mruv_items_getAll(AMX *amx, cell *params);

    cell mruv_containerTypes_create(AMX *amx, cell *params);
    cell mruv_containerTypes_get(AMX *amx, cell *params);
    cell mruv_containerTypes_delete(AMX *amx, cell *params);
    cell mruv_containerTypes_getAll(AMX *amx, cell *params);

    cell mruv_containers_create(AMX *amx, cell *params);
    cell mruv_containers_get(AMX *amx, cell *params);
    cell mruv_containers_delete(AMX *amx, cell *params);
    cell mruv_containers_getAll(AMX *amx, cell *params);

    // utils
    cell mruv_error(AMX *amx, cell *params);
}

#endif
