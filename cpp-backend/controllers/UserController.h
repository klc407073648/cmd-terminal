#pragma once

#include <drogon/HttpController.h>
#include <drogon/orm/Mapper.h>
#include <services/UserServiceImpl.h>
#include <models/User.h>
#include <common/ResultUtils.h>
#include <string>
#include <json/json.h>

using namespace drogon;
using namespace drogon_model::cmdterminal;
using namespace drogon::orm;
using namespace cmdterminal;

class UserController : public drogon::HttpController<UserController>
{
public:
  METHOD_LIST_BEGIN

  ADD_METHOD_TO(UserController::userRegister, "/api/user/register", Post, Options);
  ADD_METHOD_TO(UserController::userLogin, "/api/user/login", Post, Options);
  ADD_METHOD_TO(UserController::userLogout, "/api/user/logout", Post, Options);
  ADD_METHOD_TO(UserController::searchUsers, "/api/user/search", Get, Options);
  ADD_METHOD_TO(UserController::getCurrentUser, "/api/user/current", Get, Options);
  ADD_METHOD_TO(UserController::deleteUsers, "/api/user/delete", Post, Options);

  METHOD_LIST_END

  void userRegister(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser);
  void userLogin(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser);
  void userLogout(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void searchUsers(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void getCurrentUser(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void deleteUsers(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser);

public:
  UserController()
      : srvPtr_(new UserServiceImpl())
  {
    LOG_DEBUG << "UserController constructor!";
  }

private:
  bool isAdmin(const HttpRequestPtr &request);

private:
  UserServicePtr srvPtr_;
};
