#ifndef __LOG_CONTROLLER_H__
#define __LOG_CONTROLLER_H__

#include <drogon/drogon.h>
#include <services/impl/LogServiceImpl.h>

using namespace drogon;
using cmdterminal::LogServicePtr;

class LogController : public HttpController<LogController>
{
public:
  METHOD_LIST_BEGIN
  ADD_METHOD_TO(LogController::writeUserLog, "/api/log/user/{1}", Post, Options);
  METHOD_LIST_END

  LogController();
  ~LogController();

  void writeUserLog(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback,std::string userId);

private:
  LogServicePtr srvPtr_;
};

#endif //__LOG_CONTROLLER_H__