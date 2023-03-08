#ifndef __CACHE_SERVICE_H__
#define __CACHE_SERVICE_H__

#include <string>
#include <memory>
#include <drogon/drogon.h>
#include <models/Interface.h>

using drogon_model::cmdterminal::Interface;

using namespace drogon;

// CacheService 纯虚函数，接口类
namespace cmdterminal
{
  class CacheService;
  using CacheServicePtr = std::shared_ptr<CacheService>;

  class CacheService
  {
  public:
    /**
     * @brief 根据接口名称获取接口信息
     *
     */
    virtual bool getInterfaceInfoByName(const std::string &name,Interface &interface) = 0;
  };
}

#endif //__CACHE_SERVICE_H__