#pragma once

#include <iostream>
#include <string>
#include "ResultUtils.h"
#include "BaseResponse.h"
#include <drogon/HttpResponse.h>
#include <unordered_map>

static void callErrorResponse(std::function<void(const HttpResponsePtr &)> &&callback, BusinessException &e)
{
    LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
    auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
    auto json = Response2json<long>::rep2json(base);
    auto resp = HttpResponse::newHttpJsonResponse(json);
    callback(resp);
}

template <class T>
static void callNormalResponse(std::function<void(const HttpResponsePtr &)> &&callback, T value)
{
    auto base = ResultUtils<decltype(value)>::susscess(value);
    auto json = Response2json<decltype(value)>::rep2json(base);
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