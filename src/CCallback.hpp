//Copyright (c) 2016, BlueG
//All rights reserved.
//
//Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
//
//1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
//
//2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
//
//3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
//
//THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
// Modified by Mrucznik

#pragma once

#include "CSingleton.hpp"

typedef void(*logprintf_t)(const char *format, ...);

#include <string>
#include <queue>
#include <functional>
#include <list>
#include <unordered_set>
#include <tuple>
#include <cstdarg>
#include <boost/any.hpp>
#include <amx/amx.h>

using std::string;
using std::queue;
using std::function;
using std::list;
using std::unordered_set;
using std::tuple;

#include "CError.hpp"

class CCallback {
public: //type definitions
    using ParamList_t = list<tuple<char, boost::any>>;

    enum class Error {
        NONE,
        INVALID_AMX,
        INVALID_PARAMETERS,
        INVALID_PARAM_COUNT,
        INVALID_FORMAT_SPECIFIER,
        EMPTY_NAME,
        NOT_FOUND,
        EXPECTED_ARRAY_SIZE,
        INVALID_ARRAY_SIZE,
        NO_ARRAY_SIZE,
    };
    static const string ModuleName;

public: //constructor / destructor
    CCallback(AMX *amx, int cb_idx, ParamList_t &&params) :
            m_AmxInstance(amx),
            m_AmxCallbackIndex(cb_idx),
            m_Params(params) {}

    ~CCallback() = default;

private: //variables
    AMX *m_AmxInstance = nullptr;
    int m_AmxCallbackIndex = -1;

    ParamList_t m_Params;

public: //functions
    bool Execute();

public: //factory functions
    static std::shared_ptr<CCallback> Create(AMX *amx, const char *name, const char *format,
                                             cell *params, cell param_offset,
                                             CError<CCallback> &error);

    static std::shared_ptr<CCallback> Create(CError<CCallback> &error,
                                             AMX *amx, const char *name, const char *format, ...);
};

class CCallbackManager : public CSingleton<CCallbackManager> {
    friend class CSingleton<CCallbackManager>;

private: //constructor / destructor
    CCallbackManager() = default;

    ~CCallbackManager() override = default;


private: //variables
    unordered_set<const AMX *> m_AmxInstances;


public: //functions
    inline bool IsValidAmx(const AMX *amx) {
        return m_AmxInstances.count(amx) == 1;
    }

    inline void AddAmx(const AMX *amx) {
        m_AmxInstances.insert(amx);
    }

    inline void RemoveAmx(const AMX *amx) {
        m_AmxInstances.erase(amx);
    }

};
