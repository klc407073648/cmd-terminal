#ifndef __USER_SERVICE_H__
#define __USER_SERVICE_H__

#include <memory>
#include <string>
#include <vector>
#include <drogon/drogon.h>
#include <models/User.h>

using drogon_model::cmdterminal::User;
using namespace drogon;

// UserService 纯虚函数，接口类
namespace cmdterminal
{
  class UserService;
  using UserServicePtr = std::shared_ptr<UserService>;

  class UserService
  {
  public:
    /**
     * @brief 用户注册
     *
     * @param userAccount   用户账号
     * @param userPassword  用户密码
     * @param checkPassword 校验密码
     * @param planetCode    星球编号
     * @return 新用户 id
     */
    virtual long userRegister(const std::string &userAccount, const std::string &userPassword, const std::string &checkPassword, const std::string &planetCode="10000") = 0;

    /**
     * @brief 用户登录
     *
     * @param userAccount  用户账号
     * @param userPassword 用户密码
     * @param request      原始请求
     * @return 脱敏后的用户信息
     */
    virtual User userLogin(const std::string &userAccount, const std::string &userPassword, const HttpRequestPtr &request) = 0;

    /**
     * @brief 用户注销
     *
     * @param request  原始请求
     * @return 注销是否成功
     */
    virtual long userLogout(const HttpRequestPtr &request) = 0;

    /**
     * @brief 根据用户名查询用户
     *
     * @param username  用户名
     * @return 用户列表
     */
    virtual std::vector<User> userSearch(const std::string &username) = 0;

    /**
     * @brief 获取当前用户信息
     *
     * @param id    用户ID
     * @return 当前用户
     */
    virtual User userCurrent(long id) = 0;

    /**
     * @brief 根据id删除用户
     *
     * @param id    用户ID
     * @return 成功:true,失败:false
     */
    virtual bool userDelete(long id) = 0;

    /**
     * @brief 根据标签搜索用户
     * 
     * @param tagNameList 用户拥有的标签
     * @return 用户列表
     */
    virtual std::vector<User> searchUsersByTags(std::vector<std::string> tagNameList) = 0;

    /**
     * @brief 是否Admin用户
     * 
     * @param request  原始请求
     * @return 是否Admin用户
     */
    virtual bool isAdmin(const HttpRequestPtr &request) = 0;

  };
}

#endif //__USER_SERVICE_H__