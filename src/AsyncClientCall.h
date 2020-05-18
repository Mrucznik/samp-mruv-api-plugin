//
// Created by mrucznik on 18.05.2020.
//

#ifndef MRUVAPI_ASYNCCLIENTCALL_H
#define MRUVAPI_ASYNCCLIENTCALL_H

#include <grpcpp/support/status.h>

using grpc::Status;

template <class T>
class AsyncClientCall {
public:
    const char* callbackName;
    Status status;
    T response;

    explicit AsyncClientCall(const char *callbackName) : callbackName(callbackName) {

    }

    void CallCallback() {

    }

private:
};


#endif //MRUVAPI_ASYNCCLIENTCALL_H
