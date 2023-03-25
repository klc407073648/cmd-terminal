#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "userLogin.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 登录正常用户
TEST_F(UserControllerLoginTest, Login_correct_user)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGIN_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGIN_PATH,
                      "/req/Given_correct_user_When_login_Then_return_success.json",
                      "/resp/Given_correct_user_When_login_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    // test readArrayStringFromJson
    /*
    [readArrayStringFromJson] key: checkPasswordvalue: 12345678
    [readArrayStringFromJson] key: userAccountvalue: testuser
    [readArrayStringFromJson] key: userPasswordvalue: 12345678
    [readArrayStringFromJson] key: checkPasswordvalue: 12345678333
    [readArrayStringFromJson] key: userAccountvalue: testuser222
    [readArrayStringFromJson] key: userPasswordvalue: 12345678333
    [readArrayStringFromJson] file: /home/stibel/cpp-backend/testcase/user/json/login/req/Given_correct_array_user_When_login_Then_return_success.json, 
    res:[{"checkPassword":"12345678","userAccount":"testuser","userPassword":"12345678"},
    {"checkPassword":"12345678333","userAccount":"testuser222","userPassword":"12345678333"}]
    */
    std::string temp = LOGIN_PATH + "/req/Given_correct_array_user_When_login_Then_return_success.json";
    httpTest.readArrayStringFromJson(temp);

    EXPECT_EQ(resp, res) << "Login_correct_user req and resp not same.";
}

// 登录不存在的用户
TEST_F(UserControllerLoginTest, Login_no_exist_user)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGIN_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGIN_PATH,
                      "/req/Given_no_exist_user_When_login_Then_return_fail.json",
                      "/resp/Given_no_exist_user_When_login_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Login_no_exist_user req and resp not same.";
}