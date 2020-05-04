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

// native mruv_itemsService_version();
cell Natives::mruv_itemsService_version(AMX *amx, cell *params) {
    VersionRequest req;
    VersionResponse res;
    ClientContext ctx;

    Status status = API::Get().ItemsStub()->GetServiceVersion(&ctx, req, &res);
    return status.ok();
}

// native mruv_itemsService_status();
cell Natives::mruv_itemsService_status(AMX *amx, cell *params) {
    ServiceStatusRequest req;
    ServiceStatusResponse res;
    ClientContext ctx;

    Status status = API::Get().ItemsStub()->GetServiceStatus(&ctx, req, &res);
    logprintf("Service status: %s", res.status().c_str());
    return status.ok();
}

// native mruv_itemTypes_create(&id, const name[32], const description[256], const Float:weight, const Float:volume, const model);
cell Natives::mruv_itemTypes_create(AMX *amx, cell *params) {
    //ScopedDebugInfo dbg_info(amx, "mruv_itemTypes_create", params, "dssffd");

    ItemType request;
    ItemTypeID response;
    ClientContext context;

    // convert params to
    request.set_name(amx_GetCppString(amx, params[2]));
    request.set_description(amx_GetCppString(amx, params[3]));
    request.set_base_weight(params[4]);
    request.set_base_volume(params[5]);
    request.set_model_hash(params[6]);

    // RPC call.
    Status status = API::Get().ItemsStub()->CreateItemType(&context, request, &response);
    API::Get().setLastStatus(status);

    // convert response to amx structure
    if(status.ok())
    {
        cell* addr = NULL;
        amx_GetAddr(amx, params[1], &addr);
        *addr = response.id();
    }

    return status.ok();
}

cell Natives::mruv_itemTypes_get(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_itemTypes_delete(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_itemTypes_getAll(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_items_create(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_items_get(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_items_delete(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_items_getAll(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containerTypes_create(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containerTypes_get(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containerTypes_delete(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containerTypes_getAll(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containers_create(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containers_get(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containers_delete(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_containers_getAll(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_error(AMX *amx, cell *params) {
    return API::Get().getLastStatus().error_code();
}
