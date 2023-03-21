#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "UserControllerTest.h"
#include "HttpTest.h"
#include "userLogin.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 登录正常用户
TEST_F(UserControllerTest, Login_correct_user)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGIN_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGIN_PATH,
                      "/req/Given_correct_user_When_login_Then_return_success.json",
                      "/resp/Given_correct_user_When_login_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp+"\n", res) << "Login_correct_user req and resp not same.";
}

// 登录不存在的用户
TEST_F(UserControllerTest, Login_no_exist_user)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGIN_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGIN_PATH,
                      "/req/Given_no_exist_user_When_login_Then_return_fail.json",
                      "/resp/Given_no_exist_user_When_login_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp+"\n", res) << "Login_no_exist_user req and resp not same.";
}