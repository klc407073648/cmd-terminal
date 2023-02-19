#ifndef __INTERFACE_SERVICE_H__
#define __INTERFACE_SERVICE_H__

#include <string>

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

#endif //__INTERFACE_SERVICE_H__