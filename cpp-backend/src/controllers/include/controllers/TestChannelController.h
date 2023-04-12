#ifndef __TestChannel_CONTROLLER_H__
#define __TestChannel_CONTROLLER_H__

#include <services/inner/impl/TestChannelServiceImpl.h>
#include <drogon/drogon.h>

using namespace drogon;
using cmdterminal::TestChannelServicePtr;

class TestChannelController : public drogon::HttpController<TestChannelController>
{
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(TestChannelController::testChannel, "/api/testchannel", Post, Options);
  METHOD_LIST_END

  TestChannelController();
  ~TestChannelController();

  void testChannel(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  
private:
  TestChannelServicePtr srvPtr_;
};

#endif //__TestChannel_CONTROLLER_H__
