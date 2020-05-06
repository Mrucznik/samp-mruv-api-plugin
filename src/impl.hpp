/*
# impl.hpp

From here on, it's just regular C++ code, no AMX/Pawn/SA:MP stuff. This header
is for declaring implementation functions for the plugin's core functionality.
*/

#ifndef MRUVAPI_IMPL_H
#define MRUVAPI_IMPL_H

#include <grpcpp/create_channel.h>
#include <items/items.grpc.pb.h>

using namespace mruv;
using grpc::Channel;
using grpc::Status;
using grpc::StatusCode;

namespace Impl {

    class API {
    public:
        static API &Get() {
            static API singleton;
            return singleton;
        }

        bool Connect(int);

        const std::unique_ptr<MruVItemService::Stub> &MruVItemServiceStub() const;

        const Status &getLastStatus() const;
        void setLastStatus(const Status &lastStatus);

    private:
        API();

        API(const API &);

        std::shared_ptr<Channel> _channel;
        std::unique_ptr<MruVItemService::Stub> _items;
        Status _lastStatus;
    };
};

#endif
