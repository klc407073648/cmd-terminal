#ifndef __LOG_SERVICE_IMPL_H__
#define __LOG_SERVICE_IMPL_H__

#include <models/Log.h>
#include <services/LogService.h>
#include <drogon/drogon.h>
#include <map>

using drogon_model::cmdterminal::Log;

namespace cmdterminal
{
  class LogServiceImpl : public LogService
  {
  public:
    LogServiceImpl();
    ~LogServiceImpl();

    bool writeUserLog(long userid,const std::string& content) override;

  private:
    Mapper<Log> logMapper = drogon::orm::Mapper<Log>(drogon::app().getDbClient()); // 对象持久化映射层,连接User对象和数据库
  };
}

#endif //__LOG_SERVICE_IMPL_H__