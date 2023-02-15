#pragma once

#include <exception>
#include <functional>
#include <common/ErrorCode.h>

class BusinessException : public std::exception
{
public:
    BusinessException(const std::string &message, int code, const std::string &description)
        : message_(message), code_(code), description_(description)
    {
    }

    BusinessException(ErrorCode errorCode)
        : message_(errorCode.getMessage()), code_(errorCode.getCode()), description_(errorCode.getDescription())
    {
    }

    BusinessException(ErrorCode errorCode, const std::string &description)
        : message_(errorCode.getMessage()), code_(errorCode.getCode()), description_(description)
    {
    }

    BusinessException() = delete;

    int getCode()
    {
        return code_;
    }

    const std::string & getDescription()
    {
        return description_;
    }
	
	const std::string & getMessage()
    {
        return message_;
    }

    const char *what() const noexcept override
    {
        return message_.data();
    }

private:
    int code_;
    std::string message_;
    std::string description_;
};
