#ifndef __LOG_SERVICE_H__
#define __LOG_SERVICE_H__

#include <string>
#include <memory>
#include <drogon/drogon.h>

using namespace drogon;

// LogService 纯虚函数，接口类
namespace cmdterminal
{
  class LogService;
  using LogServicePtr = std::shared_ptr<LogService>;

  class LogService
  {
  public:
    /**
     * @brief 写入用户日志
     *
     */
    virtual bool writeUserLog(long userid,const std::string& content) = 0;
  };
}

#endif //__LOG_SERVICE_H__