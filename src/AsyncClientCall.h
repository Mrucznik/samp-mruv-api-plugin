//
// Created by mrucznik on 18.05.2020.
//

#ifndef MRUVAPI_ASYNCCLIENTCALL_H
#define MRUVAPI_ASYNCCLIENTCALL_H

#include <grpcpp/support/status.h>

#include <utility>
#include "CCallback.hpp"

using grpc::Status;

template <class T>
struct AsyncClientCall {
public:
    std::shared_ptr<CCallback> callback;
    Status status;
    T response;

    explicit AsyncClientCall(std::shared_ptr<CCallback> callback) : callback(std::move(callback)) {}
private:
};


#endif //MRUVAPI_ASYNCCLIENTCALL_H
