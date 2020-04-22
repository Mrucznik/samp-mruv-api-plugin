/*
# natives.cpp

This source file contains the bridge between natives and implementations. I
prefer to keep the actual implementation separate. The implementation contains
no instances of `cell` or `AMX*` and is purely C++ and external library code.
The code here acts as the translation between AMX data types and native types.
*/

#include <grpcpp/create_channel.h>
#include <items/items.grpc.pb.h>
#include "natives.hpp"

using namespace mruv;
using grpc::Channel;
using grpc::Status;
using grpc::StatusCode;
using grpc::ClientContext;

std::shared_ptr<Channel> channel;
std::unique_ptr<MruVItemService::Stub> items;

cell Natives::mruv_connect(AMX *amx, cell *params) {
    channel = grpc::CreateChannel("localhost:3001", grpc::InsecureChannelCredentials());

    channel->WaitForConnected(gpr_time_add(
        gpr_now(GPR_CLOCK_REALTIME),gpr_time_from_seconds(5, GPR_TIMESPAN))
    );
    if(channel->GetState(false) != grpc_connectivity_state::GRPC_CHANNEL_READY) {
        logprintf("Couldn't connect to mruv-api");
        return 0;
    }

    items = MruVItemService::NewStub(channel);

    logprintf("Connected to mruv-api.");
    return 1;
}

cell Natives::mruv_close(AMX *amx, cell *params) {
    logprintf("Closed connection to mruv-api.");
    return 1;
}

cell Natives::mruv_itemTypes_create(AMX *amx, cell *params) {
    ItemType request;
    ItemTypeID response;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = items->CreateItemType(new ClientContext, request, &response);;

    // Act upon its status.
    if (status.ok()) {
        return response.id();
    } else {
        //error
        return 0;
    }
    return response.id();
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
