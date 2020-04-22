/*
# natives.cpp

This source file contains the bridge between natives and implementations. I
prefer to keep the actual implementation separate. The implementation contains
no instances of `cell` or `AMX*` and is purely C++ and external library code.
The code here acts as the translation between AMX data types and native types.
*/

#include <grpcpp/create_channel.h>
#include "natives.hpp"
#include "MruVAPIClient.h"

cell Natives::mruv_connect(AMX *amx, cell *params) {
    MruVAPIClient greeter(grpc::CreateChannel(
            "localhost:3001", grpc::InsecureChannelCredentials()));
    std::string reply = greeter.GetVersion();
    std::cout << "Greeter received: " << reply << std::endl;

    logprintf("Hello world! %s", reply.c_str());
    return 0;
}

cell Natives::mruv_close(AMX *amx, cell *params) {
    return 0;
}

cell Natives::mruv_itemTypes_create(AMX *amx, cell *params) {
    return 0;
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
