#pragma once

#include <memory>
#include <string>
#include <models/User.h>
#include <common/BaseResponse.h>
#include <common/ErrorCode.h>
#include <exception/BusinessException.h>
#include "UserService.h"

using namespace drogon;
using namespace drogon::orm;
using namespace drogon_model::cmdterminal;

namespace cmdterminal
{
  class UserServiceImpl : public UserService
  {
  public:
    UserServiceImpl()
    {
    }

    ~UserServiceImpl()
    {
    }

    long userRegister(const std::string &userAccount, const std::string &userPassword, const std::string &checkPassword, const std::string &planetCode=S_PLANET_CODE) override;

    User userLogin(const std::string &userAccount, const std::string &userPassword, const HttpRequestPtr &request) override;

    long userLogout(const HttpRequestPtr &request) override;

    std::vector<User> userSearch(const std::string &username) override;

    User userCurrent(long id) override;

    bool userDelete(long id) override;

    std::vector<User> searchUsersByTags(std::vector<std::string> tagNameList) override;

  private:
    User getSafetyUser(User originUser);                //获取脱密后的用户
    bool checkSpecialCharacter(const std::string &str); //校验特殊字符
    std::string encryptPwd(const std::string &str);     //密码加密

  private:
    Mapper<User> userMapper = Mapper<User>(app().getDbClient()); //对象持久化映射层,连接User对象和数据库
  };
}