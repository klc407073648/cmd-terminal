#pragma once

#include <string>

//常成员函数，待处理
class ErrorCode
{
public:
    ErrorCode(int code, const std::string &message, const std::string &description)
        : code_(code), message_(message), description_(description)
    {
    }

    int getCode()
    {
        return code_;
    }

    const std::string &getMessage()
    {
        return message_;
    }

    const std::string &getDescription()
    {
        return description_;
    }

public:
    static ErrorCode SUCCESS()
    {
        return ErrorCode(0, "ok", "");
    }

    static ErrorCode PARAMS_ERROR()
    {
        return ErrorCode(40000, "请求参数错误", "");
    }

    static ErrorCode NULL_ERROR()
    {
        return ErrorCode(40001, "请求数据为空", "");
    }

    static ErrorCode NO_LOGIN()
    {
        return ErrorCode(40100, "未登录", "");
    }

    static ErrorCode NO_AUTH()
    {
        return ErrorCode(40101, "无权限", "");
    }

    static ErrorCode SYSTEM_ERROR()
    {
        return ErrorCode(50000, "系统内部异常", "");
    }

private:
    int code_;                //状态码
    std::string message_;     //状态码信息
    std::string description_; //状态码描述
};
