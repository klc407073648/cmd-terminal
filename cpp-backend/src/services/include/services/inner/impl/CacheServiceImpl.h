#ifndef __Cache_SERVICE_IMPL_H__
#define __Cache_SERVICE_IMPL_H__

#include <services/inner/CacheService.h>
#include <models/Interface.h>
#include <drogon/drogon.h>
#include <map>

using drogon_model::cmdterminal::Interface;

enum CacheType
{
  BY_MEMEORY,
  BY_REDIS
};
  
namespace cmdterminal
{

  class CacheServiceImpl : public CacheService
  {
  public:
    CacheServiceImpl();
    ~CacheServiceImpl();
    bool getInterfaceInfoByName(const std::string &name,Interface &interface) override;

  private:
    void initData();

  private:
    Mapper<Interface> interfaceMapper_ = drogon::orm::Mapper<Interface>(drogon::app().getDbClient()); // 对象持久化映射层,连接User对象和数据库
    std::map<std::string, Interface> name2Interface_;
    CacheType cacheType_;
  };
}

#endif //__Cache_SERVICE_IMPL_H__