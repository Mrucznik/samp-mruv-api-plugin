//
// Created by mrucznik on 21.04.2020.
//

#ifndef MRUVAPI_MRUVAPICLIENT_H
#define MRUVAPI_MRUVAPICLIENT_H

#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include "items/items.grpc.pb.h"

using grpc::Channel;
using grpc::Status;

using mruv::MruVItemService;

class MruVAPIClient {
public:
    MruVAPIClient(std::shared_ptr<Channel> channel);

    // Assembles the client's payload, sends it and presents the response back
    // from the server.
    std::string GetVersion();

private:
    std::unique_ptr<MruVItemService::Stub> stub_;
};


#endif //MRUVAPI_MRUVAPICLIENT_H
