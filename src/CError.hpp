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

#include <string>
#include <fmt/format.h>

using std::string;


template<typename T>
class CError
{
	using ErrorType = typename T::Error;
public:
	CError() :
		m_Type(ErrorType::NONE)
	{ }
	CError(ErrorType type, string &&msg) :
		m_Type(type),
		m_Message(std::move(msg))
	{ }
	template<typename... Args>
	CError(ErrorType type, string &&format, Args &&...args) :
		m_Type(type),
		m_Message(fmt::format(format, std::forward<Args>(args)...))
	{ }
	~CError() = default;

	operator bool() const
	{
		return m_Type != ErrorType::NONE;
	}

	const string &msg() const
	{
		return m_Message;
	}
	const ErrorType type() const
	{
		return m_Type;
	}
	const string &module() const
	{
		return T::ModuleName;
	}

	void set(ErrorType type, string &&msg)
	{
		m_Type = type;
		m_Message.assign(std::move(msg));
	}
	template<typename... Args>
	void set(ErrorType type, string &&format, Args &&...args)
	{
		m_Type = type;
		m_Message.assign(fmt::format(format, std::forward<Args>(args)...));
	}

private:
	ErrorType m_Type;
	string m_Message;
};
