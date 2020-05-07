/*
# impl.cpp

As with the header, this is the actual implementation of the plugin's
functionality with no AMX specific code or includes.

Including `common.hpp` for access to `logprintf` is useful for debugging but for
production debug logging, it's best to use a dedicated logging library such as
log-core by maddinat0r.
*/

#include "impl.hpp"
#include "common.hpp"

Impl::API::API() {

    _channel = grpc::CreateChannel("localhost:3001", grpc::InsecureChannelCredentials());
}

const std::unique_ptr<MruVAccountsService::Stub> &Impl::API::MruVAccountsServiceStub() const {
    return _accounts;
}

const std::unique_ptr<MruVCharactersService::Stub> &Impl::API::MruVCharactersServiceStub() const {
    return _characters;
}

const std::unique_ptr<MruVDevToolsService::Stub> &Impl::API::MruVDevToolsServiceStub() const {
    return _devtools;
}

const std::unique_ptr<MruVGroupsService::Stub> &Impl::API::MruVGroupsServiceStub() const {
    return _groups;
}

const std::unique_ptr<MruVItemService::Stub> &Impl::API::MruVItemServiceStub() const {
    return _items;
}

const std::unique_ptr<MruVServerService::Stub> &Impl::API::MruVServerServiceStub() const {
    return _server;
}


bool Impl::API::Connect(int timeout) {
    _channel->WaitForConnected(gpr_time_add(
            gpr_now(GPR_CLOCK_REALTIME),gpr_time_from_seconds(timeout, GPR_TIMESPAN))
    );
    if(_channel->GetState(false) != grpc_connectivity_state::GRPC_CHANNEL_READY) {
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

const Status &Impl::API::getLastStatus() const {
    return _lastStatus;
}

void Impl::API::setLastStatus(const Status &lastStatus) {
    _lastStatus = lastStatus;
}
