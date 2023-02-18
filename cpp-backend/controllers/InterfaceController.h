#pragma once

#include <drogon/HttpController.h>
#include <drogon/orm/Mapper.h>
#include <services/InterfaceServiceImpl.h>
#include <models/User.h>
#include <common/ResultUtils.h>
#include <string>
#include <json/json.h>

using namespace drogon;
using namespace drogon_model::cmdterminal;
using namespace drogon::orm;
using namespace cmdterminal;

class InterfaceController : public drogon::HttpController<InterfaceController>
{
public:
  METHOD_LIST_BEGIN
  
  ADD_METHOD_TO(InterfaceController::getBackground, "/api/background/get/random", Get, Options); 
  ADD_METHOD_TO(InterfaceController::getTranslate, "/api/fanyi/translate", Get, Options);
  
  METHOD_LIST_END

  void getBackground(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void getTranslate(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  
public:
  InterfaceController()
      : srvPtr_(new InterfaceServiceImpl())
  {
    LOG_DEBUG << "InterfaceController constructor!";
  }

private:

private:
  InterfaceServicePtr srvPtr_;
};
