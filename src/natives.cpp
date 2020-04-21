/*
# natives.cpp

This source file contains the bridge between natives and implementations. I
prefer to keep the actual implementation separate. The implementation contains
no instances of `cell` or `AMX*` and is purely C++ and external library code.
The code here acts as the translation between AMX data types and native types.
*/

#include <grpcpp/create_channel.h>
#include "natives.hpp"
#include "accounts/accounts.grpc.pb.h"
#include "MruVAPIClient.h"

cell Natives::MyFunction(AMX *amx, cell *params) {
    MruVAPIClient greeter(grpc::CreateChannel(
            "localhost:50051", grpc::InsecureChannelCredentials()));
    std::string user("world");
    std::string reply = greeter.SayHello(user);
    std::cout << "Greeter received: " << reply << std::endl;

    logprintf("Hello world! %s", reply.c_str());
    return 0;
}
