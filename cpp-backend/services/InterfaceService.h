#pragma once

#include <memory>
#include <string>
#include <vector>
#include <models/Interface.h>
#include <drogon/HttpController.h>

using namespace drogon;
using namespace drogon_model::cmdterminal;

// InterfaceService 纯虚函数，接口类
namespace cmdterminal
{
  static std::string S_PLANET_CODE = "10000";

  class InterfaceService;
  using InterfaceServicePtr = std::shared_ptr<InterfaceService>;

  class InterfaceService
  {
  public:
    /**
     * @brief 获取随机背景地址
     *
     */
    virtual std::string getBackground() = 0;

    /**
     * @brief 获取翻译结果
     *
     */
    virtual std::string getTranslate() = 0;

  };
}
