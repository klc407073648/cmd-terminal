#ifndef __TestChannel_SERVICE_IMPL_H__
#define __TestChannel_SERVICE_IMPL_H__

#include <services/inner/TestChannelService.h>
#include <models/Interface.h>
#include <drogon/drogon.h>
#include <map>

using drogon_model::cmdterminal::Interface;
  
namespace cmdterminal
{

  class TestChannelServiceImpl : public TestChannelService
  {
  public:
    TestChannelServiceImpl();
    ~TestChannelServiceImpl();
    std::string testChannel(const HttpRequestPtr &request) override;

  private:

  private:
  };
}

#endif //__TestChannel_SERVICE_IMPL_H__