#pragma once

#include <iostream>
#include <string>
#include "ErrorCode.h"

template <class T>
class BaseResponse
{
public:
    BaseResponse(int code, T data, const std::string &message, const std::string &description)
        : code_(code), data_(data), message_(message), description_(description)
    {
    }

    BaseResponse(int code, T data)
        : code_(code), data_(data), message_(""), description_("")
    {
    }

    BaseResponse(int code, T data, const std::string &message)
        : code_(code), data_(data), message_(message), description_("")
    {
    }

    BaseResponse(ErrorCode errorCode)
        : code_(errorCode.getCode()), data_(NULL), message_(errorCode.getMessage()), description_(errorCode.getDescription())
    {
    }

    int getCode()
    {
        return code_;
    }

    T getData()
    {
        return data_;
    }

    const std::string &getMessage()
    {
        return message_;
    }

    const std::string &getDescription()
    {
        return description_;
    }

private:
    int code_;
    T data_;
    std::string message_;
    std::string description_;
};