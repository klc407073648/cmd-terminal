#pragma once

#include <common/BaseResponse.h>
#include <string>
#include <vector>

/**
 * 返回工具类
 */
template <class T>
class ResultUtils
{
public:
    /**
     * 成功
     * @param data
     * @return
     * @param <T>
     */
    static BaseResponse<T> susscess(T data)
    {
        return BaseResponse<T>(0, data, "ok");
    }

    /**
     * 失败
     * @param errorCode
     * @return
     */
    static BaseResponse<T> error(ErrorCode errorCode)
    {
        return BaseResponse<T>(errorCode);
    }

    /**
     * 失败
     * @param errorCode
     * @return
     */
    static BaseResponse<T> error(ErrorCode errorCode, const std::string &message, const std::string &description)
    {
        return BaseResponse<T>(errorCode.getCode(), NULL, message, description);
    }

    /**
     * 失败
     * @param errorCode
     * @return
     */
    static BaseResponse<T> error(int errorCode, const std::string &message, const std::string &description)
    {
        return BaseResponse<T>(errorCode, NULL, message, description);
    }

    /**
     * 失败
     * @param errorCode
     * @return
     */
    static BaseResponse<T> error(ErrorCode errorCode, const std::string &description)
    {
        return BaseResponse<T>(errorCode.getCode(), NULL, errorCode.getMessage(), description);
    }
};
