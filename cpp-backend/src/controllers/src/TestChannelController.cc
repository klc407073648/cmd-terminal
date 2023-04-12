#include <controllers/TestChannelController.h>
#include <common/HttpResponseUtils.h>
#include <string>
#include <json/json.h>

using namespace cmdterminal;

TestChannelController::TestChannelController() : srvPtr_(new TestChannelServiceImpl())
{
    LOG_DEBUG << "TestChannelController constructor!";
}

TestChannelController::~TestChannelController()
{
    LOG_DEBUG << "TestChannelController destructor!";
}

void TestChannelController::testChannel(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    try
    {
		LOG_DEBUG << "TestChannelController testChannel";
        std::string res = srvPtr_->testChannel(request);
        callNormalResponse(std::move(callback), res);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}
