//
// Created by mrucznik on 21.05.2020.
//

#include "API.h"

#include "common.hpp"
#include "AsyncClientCall.h"

API::API() {
    _channel = grpc::CreateChannel("localhost:3001", grpc::InsecureChannelCredentials());

    _completionQueueThread = new std::thread([this]() {
        logprintf("start thread");
        void *got_tag;
        bool ok = false;

        // Block until the next result is available in the completion queue "cq".
        while (this->completionQueue.Next(&got_tag, &ok)) {
            // The tag in this example is the memory location of the call object
            auto call = static_cast<AsyncClientCallCallback*>(got_tag);
            call->Execute();

            // Once we're complete, deallocate the call object.
            delete call;
        }
        logprintf("end of thread");
    });
}

API::~API() {
    logprintf("destruct begin");
    completionQueue.Shutdown();
    _completionQueueThread->join();
    logprintf("destruct end");
}

const std::unique_ptr<MruVAccountsService::Stub> &API::MruVAccountsServiceStub() const {
    return _accounts;
}

const std::unique_ptr<MruVCharactersService::Stub> &API::MruVCharactersServiceStub() const {
    return _characters;
}

const std::unique_ptr<MruVDevToolsService::Stub> &API::MruVDevToolsServiceStub() const {
    return _devtools;
}

const std::unique_ptr<MruVGroupsService::Stub> &API::MruVGroupsServiceStub() const {
    return _groups;
}

const std::unique_ptr<MruVItemService::Stub> &API::MruVItemServiceStub() const {
    return _items;
}

const std::unique_ptr<MruVServerService::Stub> &API::MruVServerServiceStub() const {
    return _server;
}


bool API::Connect(int timeout) {
    _channel->WaitForConnected(gpr_time_add(
            gpr_now(GPR_CLOCK_REALTIME), gpr_time_from_seconds(timeout, GPR_TIMESPAN))
    );
    if (_channel->GetState(false) != grpc_connectivity_state::GRPC_CHANNEL_READY) {
        logprintf("Couldn't connect to mruv-api");
        return false;
    }

    _accounts = MruVAccountsService::NewStub(_channel);
    _characters = MruVCharactersService::NewStub(_channel);
    _devtools = MruVDevToolsService::NewStub(_channel);
    _groups = MruVGroupsService::NewStub(_channel);
    _items = MruVItemService::NewStub(_channel);
    _server = MruVServerService::NewStub(_channel);

    logprintf("Connected to mruv-api.");
    return true;
}

const Status &API::getLastStatus() const {
    return _lastStatus;
}

void API::setLastStatus(const Status &lastStatus) {
    _lastStatus = lastStatus;
}
