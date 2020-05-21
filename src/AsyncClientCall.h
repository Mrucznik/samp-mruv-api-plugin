//
// Created by mrucznik on 18.05.2020.
//

#ifndef MRUVAPI_ASYNCCLIENTCALL_H
#define MRUVAPI_ASYNCCLIENTCALL_H

#include <grpcpp/support/status.h>

#include <utility>
#include "CCallback.hpp"
#include "common.hpp"

using grpc::Status;

class AsyncClientCallCallback {
public:
    virtual void Execute() = 0;
};

template<class T>
class AsyncClientCall : public AsyncClientCallCallback {
public:
    const char* callbackName;
    const char* callbackFormat;
    Status status;
    T response;

    AsyncClientCall(const function<std::shared_ptr<CCallback>(AsyncClientCall<T>&, CError<CCallback> &)> &getCallback,
                    const char *callbackName, const char *callbackFormat)
            : callbackName(callbackName), callbackFormat(callbackFormat), GetCallback(getCallback) {}

    void Execute() override {
        if (this->status.ok())
        {
            CError<CCallback> callback_error;
            std::shared_ptr<CCallback> callback = GetCallback(*this, callback_error);
            if (callback_error && callback_error.type() != CCallback::Error::EMPTY_NAME) {
                logprintf("create err %s", callback_error.msg().c_str());
                return;
            }

            callback->Execute();
        }
        else
        {
            logprintf("rpc failed");
        }
    };

private:
    std::function<std::shared_ptr<CCallback>(AsyncClientCall<T>&, CError<CCallback>&)> GetCallback;
};


#endif //MRUVAPI_ASYNCCLIENTCALL_H
