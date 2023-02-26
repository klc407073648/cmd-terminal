#include "LogController.h"
#include <common/HttpResponseUtils.h>
#include <string>
#include <json/json.h>

using namespace cmdterminal;

LogController::LogController(): srvPtr_(new LogServiceImpl())
{
    LOG_DEBUG << "LogController constructor!";
}

LogController::~LogController()
{
    LOG_DEBUG << "LogController destructor!";
}

void LogController::writeUserLog(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback,std::string userId)
{
    std::string content = ((*(request->getJsonObject()))["content"]).asString();//如果测试Postman测试无content场景会出现Segmentation fault

    try
    {
        bool res = srvPtr_->writeUserLog(atol(userId.c_str()),content);
        callNormalResponse(std::move(callback),res);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback),e);
    }
}
