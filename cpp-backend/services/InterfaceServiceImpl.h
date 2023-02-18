#pragma once

#include <memory>
#include <string>
#include <models/Interface.h>
#include <common/BaseResponse.h>
#include <common/ErrorCode.h>
#include <exception/BusinessException.h>
#include "InterfaceService.h"

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::cmdterminal;

namespace cmdterminal
{
  class InterfaceServiceImpl : public InterfaceService
  {
  public:
    InterfaceServiceImpl()
    {
    }

    ~InterfaceServiceImpl()
    {
    }

    std::string getBackground() override;

    std::string getTranslate() override;

  private:

  private:
    Mapper<Interface> InterfaceMapper = Mapper<Interface>(app().getDbClient()); //对象持久化映射层,连接User对象和数据库
  };
}