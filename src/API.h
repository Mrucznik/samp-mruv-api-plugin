//
// Created by mrucznik on 21.05.2020.
//

#ifndef MRUVAPI_API_H
#define MRUVAPI_API_H

#include <grpcpp/create_channel.h>
#include <accounts/accounts.grpc.pb.h>
#include <characters/characters.grpc.pb.h>
#include <devtools/devtools.grpc.pb.h>
#include <groups/groups.grpc.pb.h>
#include <items/items.grpc.pb.h>
#include <server/server.grpc.pb.h>
#include <thread>

#include "CSingleton.hpp"

using namespace mruv;
using namespace mruv::devtools;
using namespace mruv::server;
using grpc::Channel;
using grpc::Status;
using grpc::StatusCode;
using grpc::CompletionQueue;

class API : public CSingleton<API> {
    friend class CSingleton<API>;

public:
    bool Connect(int);

    const std::unique_ptr<MruVAccountsService::Stub> &MruVAccountsServiceStub() const;

    const std::unique_ptr<MruVCharactersService::Stub> &MruVCharactersServiceStub() const;

    const std::unique_ptr<MruVDevToolsService::Stub> &MruVDevToolsServiceStub() const;

    const std::unique_ptr<MruVGroupsService::Stub> &MruVGroupsServiceStub() const;

    const std::unique_ptr<MruVItemService::Stub> &MruVItemServiceStub() const;

    const std::unique_ptr<MruVServerService::Stub> &MruVServerServiceStub() const;

    CompletionQueue completionQueue;

    void CompletionQueueThreadFunc();

    const Status &getLastStatus() const;

    void setLastStatus(const Status &lastStatus);

private:
    API();
    ~API() override;

    std::shared_ptr<Channel> _channel;
    std::unique_ptr<MruVAccountsService::Stub> _accounts;
    std::unique_ptr<MruVCharactersService::Stub> _characters;
    std::unique_ptr<MruVDevToolsService::Stub> _devtools;
    std::unique_ptr<MruVGroupsService::Stub> _groups;
    std::unique_ptr<MruVItemService::Stub> _items;
    std::unique_ptr<MruVServerService::Stub> _server;
    Status _lastStatus;

    std::thread* _completionQueueThread;
};


#endif //MRUVAPI_API_H
