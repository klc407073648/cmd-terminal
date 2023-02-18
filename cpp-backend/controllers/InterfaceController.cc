#include "InterfaceController.h"
#include <models/User.h>
#include <constants/UserConstant.h>
#include <common/Response2json.h>
#include <common/HttpResponseUtils.h>

using namespace cmdterminal;

void InterfaceController::getBackground(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_INFO << "InterfaceController::getBackground in";

    try
    {
        std::string url = srvPtr_->getBackground();
        callNormalResponse(std::move(callback),url);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback),e);
    }
}


void InterfaceController::getTranslate(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_INFO << "InterfaceController::getTranslate in";

    try
    {
        std::string translalteRes = srvPtr_->getTranslate();

        callNormalResponse(std::move(callback),translalteRes);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback),e);
    }
}