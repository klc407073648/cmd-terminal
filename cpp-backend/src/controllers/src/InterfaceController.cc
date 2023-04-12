#include <controllers/InterfaceController.h>
#include <common/HttpResponseUtils.h>
#include <string>
#include <json/json.h>

using namespace cmdterminal;

InterfaceController::InterfaceController() : srvPtr_(new InterfaceServiceImpl())
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
        std::string url = srvPtr_->getBackground(request);
        callNormalResponse(std::move(callback), url);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}

void InterfaceController::getTranslate(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
        std::string translalteRes = srvPtr_->getTranslate(request);

        callNormalResponse(std::move(callback), translalteRes);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}

void InterfaceController::getBackendVersion(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
        std::string version = srvPtr_->getBackendVersion(request);
        callNormalResponse(std::move(callback), version);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}

void InterfaceController::getCurrentWeather(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
        std::string weatherInfo = srvPtr_->getCurrentWeather(request);
        callNormalResponse(std::move(callback), weatherInfo);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}

void InterfaceController::getFutureWeather(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
        std::string weatherInfo = srvPtr_->getFutureWeather(request);
        callNormalResponse(std::move(callback), weatherInfo);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}