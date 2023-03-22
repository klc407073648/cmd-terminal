#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "userCurrent.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 登录正常用户,获取当前用户
TEST_F(UserControllerCurrentTest, Current_Login_correct_user)
{
    //先登录
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGIN_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGIN_PATH,
                      "/req/Given_correct_user_When_login_Then_return_success.json",
                      "/resp/Given_correct_user_When_login_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Current_Login_correct_user login req and resp not same.";

    //再获取当前用户
    HttpTest httpTest2(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_GET, CURRENT_URI, HTTPMessage::HTTP_1_1,
                      "application/json", CURRENT_PATH,
                      "",
                      "/resp/Given_login_user_When_query_Then_return_success_resp.json");

    std::string resp2 = httpTest2.sendRequest();
    std::string res2 = httpTest2.readStringFromJson(httpTest2.getRespFullPath());

    EXPECT_EQ(resp2, res2) << "Current_Login_correct_user current req and resp not same.";

}

// 登录不存在的用户
TEST_F(UserControllerCurrentTest, Current_Login_no_exist_user)
{
    //先注销
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGIN_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGIN_PATH,
                      "/req/Given_no_exist_user_When_login_Then_return_fail.json",
                      "/resp/Given_no_exist_user_When_login_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Current_Login_no_exist_user req and resp not same.";

    //再获取当前用户
    HttpTest httpTest2(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_GET, CURRENT_URI, HTTPMessage::HTTP_1_1,
                      "application/json", CURRENT_PATH,
                      "",
                      "/resp/Given_login_user_When_query_Then_return_success_resp.json");

    std::string resp2 = httpTest2.sendRequest();
    std::string res2 = httpTest2.readStringFromJson(httpTest2.getRespFullPath());

    EXPECT_EQ(resp2, res2) << "Current_Login_no_exist_user current req and resp not same.";

}