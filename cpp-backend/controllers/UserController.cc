#include "UserController.h"
#include <models/User.h>
#include <constants/UserConstant.h>
#include <common/Response2json.h>
#include <common/HttpResponseUtils.h>

using namespace cmdterminal;

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
        auto userJson = (*json);
        auto user = User(userJson);

        LOG_INFO << "UserController::fromRequest user:" << jsonStr;
        LOG_INFO << "UserController::fromRequest method:" << req.getMethodString();
        LOG_INFO << "UserController::fromRequest query string:" << req.getQuery();
        LOG_INFO << "UserController::fromRequest Headers:" << unordered_map2string(req.getHeaders());
        LOG_INFO << "UserController::fromRequest Parameters:" << unordered_map2string(req.getParameters());
        return user;
    }
}

void UserController::userRegister(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser)
{
    LOG_INFO << "UserController::userRegister in";

    std::string checkPassword = ((*(request->getJsonObject()))["checkPassword"]).asString();

    try
    {
        std::string userAccount = reqUser.getValueOfUseraccount();
        std::string userPassword = reqUser.getValueOfUserpassword();
        // std::string checkPassword = checkPassword_;
        // std::string planetCode = reqUser.getValueOfPlanetcode();

        if (userAccount.size() == 0 || userPassword.size() == 0 || checkPassword.size() == 0)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "入参中账号或密码或校验密码或星球编号为空");
        }

        long id = srvPtr_->userRegister(userAccount, userPassword, checkPassword);

        callNormalResponse(std::move(callback), id);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
    }
}

void UserController::userLogin(const HttpRequestPtr &request, std::function<void(const HttpResponsePtr &)> &&callback, User &&reqUser)
{
    LOG_INFO << "UserController::userLogin in";

    try
    {
        std::string userAccount = reqUser.getValueOfUseraccount();
        std::string userPassword = reqUser.getValueOfUserpassword();

        if (userAccount.size() == 0 || userPassword.size() == 0)
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), "入参中账号或密码为空");
        }

        auto user = srvPtr_->userLogin(userAccount, userPassword, request);
        callNormalResponse(std::move(callback), user);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
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

        long result = srvPtr_->userLogout(request);

        callNormalResponse(std::move(callback), result);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
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
        std::vector<User> userList = srvPtr_->userSearch(username);

        callNormalResponse(std::move(callback), userList);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
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
        User user = srvPtr_->userCurrent(userId);

        callNormalResponse(std::move(callback), user);
    }
    catch (BusinessException &e)
    {
        callErrorResponse(std::move(callback), e);
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

        bool ret = srvPtr_->userDelete(id);

        callNormalResponse(std::move(callback), ret);
    }
    catch (BusinessException &e)
    {

        callErrorResponse(std::move(callback), e);
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