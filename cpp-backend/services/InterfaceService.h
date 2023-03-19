#ifndef __INTERFACE_SERVICE_H__
#define __INTERFACE_SERVICE_H__

#include <string>
#include <memory>
#include <drogon/drogon.h>

using namespace drogon;

// InterfaceService 纯虚函数，接口类
namespace cmdterminal
{
  class InterfaceService;
  using InterfaceServicePtr = std::shared_ptr<InterfaceService>;

  class InterfaceService
  {
  public:
    /**
     * @brief 获取随机背景地址
     *
     */
    virtual std::string getBackground(const HttpRequestPtr &request) = 0;

    /**
     * @brief 获取翻译结果
     *
     */
    virtual std::string getTranslate(const HttpRequestPtr &request) = 0;

    /**
     * @brief 获取后台版本信息
     *
     */
    virtual std::string getBackendVersion(const HttpRequestPtr &request) = 0;

    /**
     * @brief 获取当前天气
     *
     */
    virtual std::string getCurrentWeather(const HttpRequestPtr &request) = 0;

    /**
     * @brief 获取未来天气
     *
     */
    virtual std::string getFutureWeather(const HttpRequestPtr &request) = 0;
  };
}

#endif //__INTERFACE_SERVICE_H__