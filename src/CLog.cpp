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

#include "CLog.hpp"

#include <amx/amx.h>


void CDebugInfoManager::Update(AMX *const amx, const char *func) {
    m_Amx = amx;
    m_NativeName = func;
    m_Info.clear();
    m_Available = samplog::Api::Get()->GetAmxFunctionCallTrace(amx, m_Info);
}

void CDebugInfoManager::Clear() {
    m_Amx = nullptr;
    m_NativeName = nullptr;
    m_Available = false;
}

CScopedDebugInfo::CScopedDebugInfo(AMX *const amx, const char *func,
                                   cell *const params, const char *params_format /* = ""*/) {
    CDebugInfoManager::Get()->Update(amx, func);

    auto &logger = CLog::Get()->m_Logger;
    if (logger.IsLogLevel(LogLevel::DEBUG))
        logger.LogNativeCall(amx, params, func, params_format);
}
