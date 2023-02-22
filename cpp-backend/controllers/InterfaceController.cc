#include "InterfaceController.h"
#include <common/HttpResponseUtils.h>
#include <string>
#include <json/json.h>

using namespace cmdterminal;

InterfaceController::InterfaceController(): srvPtr_(new InterfaceServiceImpl())
{
    LOG_DEBUG << "InterfaceController constructor!";
}

InterfaceController::~InterfaceController()
{
    LOG_DEBUG << "InterfaceController destructor!";
}

void InterfaceController::getBackground(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
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
    try
    {
        std::string translalteRes = srvPtr_->getTranslate(request);

        callNormalResponse(std::move(callback),translalteRes);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback),e);
    }
}