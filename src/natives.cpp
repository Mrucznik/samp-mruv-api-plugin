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

cell Natives::mruv_itemTypes_create(AMX *amx, cell *params) {
    ItemType request;
    ItemTypeID response;
    ClientContext context;

    // The actual RPC.
    Status status = API::Get().ItemsStub()->CreateItemType(&context, request, &response);
    API::Get().setLastStatus(status);

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

cell Natives::mruv_itemsService_version(AMX *amx, cell *params) {
    VersionRequest req;
    VersionResponse res;
    ClientContext ctx;

    Status status = API::Get().ItemsStub()->GetServiceVersion(&ctx, req, &res);
    return status.ok();
}

cell Natives::mruv_itemsService_status(AMX *amx, cell *params) {
    ServiceStatusRequest req;
    ServiceStatusResponse res;
    ClientContext ctx;

    Status status = API::Get().ItemsStub()->GetServiceStatus(&ctx, req, &res);
    return status.ok();
}
