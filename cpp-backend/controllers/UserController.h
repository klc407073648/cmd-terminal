#pragma once

#include <drogon/HttpController.h>
#include <drogon/orm/Mapper.h>
#include <services/UserServiceImpl.h>
#include <models/User.h>
#include <common/ResultUtils.h>
#include <string>
#include <json/json.h>

using namespace drogon;
using namespace drogon_model::testuser;
using namespace drogon::orm;
using namespace usercenter;

class UserController : public drogon::HttpController<UserController>
{
public:
  METHOD_LIST_BEGIN
  // use METHOD_ADD to add your custom processing function here;
  // METHOD_ADD(user::userRegister, "/register", Post);                  //path is /api/v1/User/{arg1}
  // METHOD_ADD(user::userLogin, "/login", Post);  //path is /api/v1/User/{arg1}/detailinfo
  // METHOD_ADD(user::userLogout, "/logout", Post);                 //path is /api/v1/User/{arg1}
  // METHOD_ADD(user::searchUsers, "/search", Get);                 //path is /api/v1/User/{arg1}
  // METHOD_ADD(user::getCurrentUser, "/current", Get);                 //path is /api/v1/User/{arg1}
  // METHOD_ADD(user::deleteUsers, "/delete", Post);                 //path is /api/v1/User/{arg1}

  ADD_METHOD_TO(UserController::userRegister, "/api/user/register", Post, Options); // path is /api/v1/User/{arg1}
  ADD_METHOD_TO(UserController::userLogin, "/api/user/login", Post, Options);       // path is /api/v1/User/{arg1}/detailinfo
  ADD_METHOD_TO(UserController::userLogout, "/api/user/logout", Post, Options);     // path is /api/v1/User/{arg1}
  ADD_METHOD_TO(UserController::searchUsers, "/api/user/search", Get, Options);     // path is /api/v1/User/{arg1}
  ADD_METHOD_TO(UserController::getCurrentUser, "/api/user/current", Get, Options); // path is /api/v1/User/{arg1}
  ADD_METHOD_TO(UserController::deleteUsers, "/api/user/delete", Post, Options);    // path is /api/v1/User/{arg1}

  METHOD_LIST_END

  void userRegister(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser);
  void userLogin(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser);
  void userLogout(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void searchUsers(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void getCurrentUser(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback);
  void deleteUsers(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser);

public:
  UserController()
      : userSrvPtr_(new UserServiceImpl())
  {
    LOG_DEBUG << "UserController constructor!";
  }

private:
  bool isAdmin(const HttpRequestPtr &request);

  // TODO
  void retErrorJsonResponse(BusinessException &e);

private:
  UserServicePtr userSrvPtr_;
};
