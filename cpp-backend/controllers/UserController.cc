#include "UserController.h"
#include <models/User.h>
#include <constants/UserConstant.h>
#include <common/Response2json.h>

using namespace usercenter;

// Add definition of your processing function here
namespace drogon
{
    /**
     * @brief This template is used to convert a request object to a custom
     * type object. Users must specialize the template for a particular type.
     */
    template <>
    inline User fromRequest(const HttpRequest &req)
    {
        auto json = req.getJsonObject();
        auto jsonStr = (*json).toStyledString();
        LOG_INFO << "UserController::fromRequest:" << jsonStr;
        auto userJson = (*json);
        auto user = User(userJson);
        return user;
    }
}

void UserController::userRegister(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser)
{
    LOG_INFO << "UserController::userRegister in";

    std::string checkPassword = ((*(request->getJsonObject()))["checkPassword"]).asString();

    try
    {
        if (reqUser.getUseraccount() == nullptr || reqUser.getUserpassword() == nullptr || checkPassword == "" )
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "入参中账号或密码或校验密码或星球编号不存在");
        }

        std::string userAccount = reqUser.getValueOfUseraccount();
        std::string userPassword = reqUser.getValueOfUserpassword();
        // std::string checkPassword = checkPassword_;
        //std::string planetCode = reqUser.getValueOfPlanetcode();

        if (userAccount.size() == 0 || userPassword.size() == 0 || checkPassword.size() == 0)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "入参中账号或密码或校验密码或星球编号为空");
        }

        long id = userSrvPtr_->userRegister(userAccount, userPassword, checkPassword);

        auto base = ResultUtils<long>::susscess(id);
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
    catch (BusinessException &e)
    {
        LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
        auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

void UserController::userLogin(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser)
{
    LOG_INFO << "UserController::userLogin in";

    try
    {
        if (reqUser.getUseraccount() == nullptr || reqUser.getUserpassword() == nullptr)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "入参中账号或密码不存在");
        }

        std::string userAccount = reqUser.getValueOfUseraccount();
        std::string userPassword = reqUser.getValueOfUserpassword();

        if (userAccount.size() == 0 || userPassword.size() == 0)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "入参中账号或密码为空");
        }

        auto user = userSrvPtr_->userLogin(userAccount, userPassword, request);

        auto base = ResultUtils<User>::susscess(user);
        auto json = Response2json<User>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
    catch (BusinessException &e)
    {
        LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
        auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

void UserController::userLogout(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_INFO << "UserController::userLogout in";

    try
    {
        if (request == nullptr)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "请求为空");
        }

        long result = userSrvPtr_->userLogout(request);

        auto base = ResultUtils<long>::susscess(result);
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
    catch (BusinessException &e)
    {
        LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
        auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

void UserController::searchUsers(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_INFO << "UserController::searchUsers in";

    try
    {
        if (!isAdmin(request))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "非管理员用户，无查询权限");
        }

        std::string username = request->getParameter("username");
        LOG_INFO << "UserController::username" << username;

        std::vector<User> userList = userSrvPtr_->userSearch(username);

        auto base = ResultUtils<std::vector<User>>::susscess(userList);
        auto json = Response2json<std::vector<User>>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
    catch (BusinessException &e)
    {
        LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
        auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

void UserController::getCurrentUser(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback)
{
    LOG_INFO << "UserController::getCurrentUser in";

    try
    {
        bool isFind = request->getSession()->find(USER_LOGIN_STATE);

        if (!isFind)
        {
            throw BusinessException(ErrorCode::NO_LOGIN());
        }

        User curentUser = request->getSession()->get<User>(USER_LOGIN_STATE);

        long userId = curentUser.getValueOfId();

        User user = userSrvPtr_->userCurrent(userId);

        auto base = ResultUtils<User>::susscess(user);
        auto json = Response2json<User>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
    catch (BusinessException &e)
    {
        LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
        auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

void UserController::deleteUsers(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser)
{
    LOG_INFO << "UserController::deleteUsers in";

    try
    {
        if (!isAdmin(request))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "非管理员用户，无删除权限");
        }

        auto id = (reqUser.getId() != nullptr) ? reqUser.getValueOfId() : -1;

        if (id <= 0)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "用户id不合法");
        }

        bool ret = userSrvPtr_->userDelete(id);

        auto base = ResultUtils<bool>::susscess(ret);
        auto json = Response2json<bool>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
    catch (BusinessException &e)
    {
        LOG_INFO << "BusinessException error: message:" << e.what() << ",description" << e.getDescription();
        auto base = ResultUtils<long>::error(e.getCode(), e.getMessage(), e.getDescription());
        auto json = Response2json<long>::rep2json(base);
        auto resp = HttpResponse::newHttpJsonResponse(json);
        callback(resp);
    }
}

bool UserController::isAdmin(const HttpRequestPtr &request)
{
    LOG_INFO << "UserController::isAdmin in";

    bool isFind = request->getSession()->find(USER_LOGIN_STATE);

    if (isFind)
    {
        User user = request->getSession()->get<User>(USER_LOGIN_STATE);
        if (user.getValueOfUserrole() == ADMIN_ROLE)
        {
            return true;
        }
    }

    return false;
}

void UserController::retErrorJsonResponse(BusinessException &e)
{
}
