#ifndef __USER_SERVICE_IMPL_H__
#define __USER_SERVICE_IMPL_H__

#include <models/User.h>
#include <services/UserService.h>
#include <drogon/drogon.h>

using drogon_model::cmdterminal::User;

namespace cmdterminal
{
  class UserServiceImpl : public UserService
  {
  public:
    UserServiceImpl();
    ~UserServiceImpl();
  
    long userRegister(const std::string &userAccount, const std::string &userPassword, const std::string &checkPassword, const std::string &planetCode) override;

    User userLogin(const std::string &userAccount, const std::string &userPassword, const HttpRequestPtr &request) override;

    long userLogout(const HttpRequestPtr &request) override;

    std::vector<User> userSearch(const std::string &username) override;

    User userCurrent(long id) override;

    bool userDelete(long id) override;

    std::vector<User> searchUsersByTags(std::vector<std::string> tagNameList) override;

    bool isAdmin(const HttpRequestPtr &request) override;  

  private:
    User getSafetyUser(User originUser);                //获取脱密后的用户
    bool checkSpecialCharacter(const std::string &str); //校验特殊字符
    std::string encryptPwd(const std::string &str);     //密码加密

  private:
    Mapper<User> userMapper = drogon::orm::Mapper<User>(drogon::app().getDbClient()); //对象持久化映射层,连接User对象和数据库
  };
}

#endif //__USER_SERVICE_IMPL_H__