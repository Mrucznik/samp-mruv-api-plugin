/*
# impl.hpp

From here on, it's just regular C++ code, no AMX/Pawn/SA:MP stuff. This header
is for declaring implementation functions for the plugin's core functionality.
*/

#ifndef MRUVAPI_IMPL_H
#define MRUVAPI_IMPL_H

#include <grpcpp/create_channel.h>
#include <accounts/accounts.grpc.pb.h>
#include <characters/characters.grpc.pb.h>
#include <devtools/devtools.grpc.pb.h>
#include <groups/groups.grpc.pb.h>
#include <items/items.grpc.pb.h>
#include <server/server.grpc.pb.h>

using namespace mruv;
using namespace mruv::devtools;
using grpc::Channel;
using grpc::Status;
using grpc::StatusCode;
using grpc::CompletionQueue;

namespace Impl {

    class API {
    public:
        static API &Get() {
            static API singleton;
            return singleton;
        }

        bool Connect(int);

        const std::unique_ptr<MruVAccountsService::Stub> &MruVAccountsServiceStub() const;
        const std::unique_ptr<MruVCharactersService::Stub> &MruVCharactersServiceStub() const;
        const std::unique_ptr<MruVDevToolsService::Stub> &MruVDevToolsServiceStub() const;
        const std::unique_ptr<MruVGroupsService::Stub> &MruVGroupsServiceStub() const;
        const std::unique_ptr<MruVItemService::Stub> &MruVItemServiceStub() const;
        const std::unique_ptr<MruVServerService::Stub> &MruVServerServiceStub() const;

        CompletionQueue completionQueue;

        const Status &getLastStatus() const;
        void setLastStatus(const Status &lastStatus);

    private:
        API();

        API(const API &);

        std::shared_ptr<Channel> _channel;
        std::unique_ptr<MruVAccountsService::Stub> _accounts;
        std::unique_ptr<MruVCharactersService::Stub> _characters;
        std::unique_ptr<MruVDevToolsService::Stub> _devtools;
        std::unique_ptr<MruVGroupsService::Stub> _groups;
        std::unique_ptr<MruVItemService::Stub> _items;
        std::unique_ptr<MruVServerService::Stub> _server;
        Status _lastStatus;
    };
};

#endif
