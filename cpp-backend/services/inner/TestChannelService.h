#ifndef __TestChannel_SERVICE_H__
#define __TestChannel_SERVICE_H__

#include <string>
#include <memory>
#include <drogon/drogon.h>

using namespace drogon;

// TestChannelService 纯虚函数，接口类
namespace cmdterminal
{
  class TestChannelService;
  using TestChannelServicePtr = std::shared_ptr<TestChannelService>;

  class TestChannelService
  {
  public:
    /**
     * @brief 根据接口名称获取接口信息
     *
     */
    virtual std::string testChannel(const HttpRequestPtr &request) = 0;
  };
}

#endif //__TestChannel_SERVICE_H__