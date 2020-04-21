//
// Created by mrucznik on 21.04.2020.
//

#include "MruVAPIClient.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using mruv::MruVItemService;
using mruv::VersionRequest;
using mruv::VersionResponse;

MruVAPIClient::MruVAPIClient(std::shared_ptr<Channel> channel)
        : stub_(MruVItemService::NewStub(channel)) {}

std::string MruVAPIClient::GetVersion() {
    // Data we are sending to the server.
    VersionRequest request;

    // Container for the data we expect from the server.
    VersionResponse reply;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    // The actual RPC.
    Status status = stub_->GetServiceVersion(&context, request, &reply);

    // Act upon its status.
    if (status.ok()) {
        return reply.version();
    } else {
        std::cout << status.error_code() << ": " << status.error_message()
                  << std::endl;
        return "RPC failed";
    }
}
