#pragma once

#include <drogon/HttpResponse.h>
#include <common/ResultUtils.h>
#include <common/Response2json.h>
#include <exception/BusinessException.h>
#include <iostream>
#include <string>
#include <unordered_map>

//获取调用者函数的名称
static void callErrorResponse(std::function<void(const HttpResponsePtr &)> &&callback, BusinessException &e,std::string str = __builtin_FUNCTION())
{
    std::string callFunName = str;
    auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
    auto json = Response2json<long>::rep2json(base);

    LOG_ERROR << "[callErrorResponse] callFunName:" << callFunName <<", error response:" << json.toStyledString();

    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

template <class T>
static void callNormalResponse(std::function<void(const HttpResponsePtr &)> &&callback, T value,std::string str = __builtin_FUNCTION())
{
    std::string callFunName = str;
    
    auto base = ResultUtils<decltype(value)>::susscess(value);
    auto json = Response2json<decltype(value)>::rep2json(base);

    LOG_ERROR << "[callErrorResponse] callFunName:" << callFunName <<", normal response:" << json.toStyledString();

    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

static std::string unordered_map2string(const std::unordered_map<std::string, std::string>& umap){
    std::string res("");
    for(auto &pair:umap){
        res = res + pair.first + ": " + pair.second + ';';
    }
    return res;
}