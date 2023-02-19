#ifndef __INTERFACE_SERVICE_IMPL_H__
#define __INTERFACE_SERVICE_IMPL_H__

#include <models/Interface.h>
#include <services/InterfaceService.h>
#include <drogon/drogon.h>

using drogon_model::cmdterminal::Interface;

namespace cmdterminal
{
  class InterfaceServiceImpl : public InterfaceService
  {
  public:
    InterfaceServiceImpl();
    ~InterfaceServiceImpl();

    std::string getBackground() override;
    std::string getTranslate() override;

  private:
    Mapper<Interface> InterfaceMapper = drogon::orm::Mapper<Interface>(drogon::app().getDbClient()); // 对象持久化映射层,连接User对象和数据库
  };
}

#endif //__INTERFACE_SERVICE_IMPL_H__