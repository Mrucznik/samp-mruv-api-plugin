//
// Created by mrucznik on 18.05.2020.
//

#include "AsyncClientCall.h"

template<class T>
void AsyncClientCall<T>::Execute() {
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
}