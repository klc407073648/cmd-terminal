#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "userRegister.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 用户注册,非空校验
TEST_F(UserControllerRegisterTest, Register_userAccount_Null)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, REGISTER_URI, HTTPMessage::HTTP_1_1,
                      "application/json", REGISTER_PATH,
                      "/req/Given_userAccount_Null_When_register_Then_return_fail.json",
                      "/resp/Given_userAccount_Null_When_register_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Register_userAccount_Null req and resp not same.";
}

// 用户注册,账号长度校验
TEST_F(UserControllerRegisterTest, Register_userAccount_Length_Less_than_4)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, REGISTER_URI, HTTPMessage::HTTP_1_1,
                      "application/json", REGISTER_PATH,
                      "/req/Given_userAccount_Length_Less_than_4_When_register_Then_return_fail.json",
                      "/resp/Given_userAccount_Length_Less_than_4_When_register_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Register_userAccount_Length_Less_than_4 req and resp not same.";
}

// 用户注册,密码长度校验
TEST_F(UserControllerRegisterTest, Register_userPassword_Length_Less_than_8)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, REGISTER_URI, HTTPMessage::HTTP_1_1,
                      "application/json", REGISTER_PATH,
                      "/req/Given_userPassword_Length_Less_than_8_When_register_Then_return_fail.json",
                      "/resp/Given_userPassword_Length_Less_than_8_When_register_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Register_userPassword_Length_Less_than_8 req and resp not same.";
}

// 用户注册,账号重复性校验
TEST_F(UserControllerRegisterTest, Register_userAccount_unique)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, REGISTER_URI, HTTPMessage::HTTP_1_1,
                      "application/json", REGISTER_PATH,
                      "/req/Given_userAccount_unique_When_register_Then_return_fail.json",
                      "/resp/Given_userAccount_unique_When_register_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Register_userAccount_unique req and resp not same.";
}

// 用户注册,账号特殊字符校验
TEST_F(UserControllerRegisterTest, Register_userAccount_contain_special_charater)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, REGISTER_URI, HTTPMessage::HTTP_1_1,
                      "application/json", REGISTER_PATH,
                      "/req/Given_userAccount_contain_special_charater_When_register_Then_return_fail.json",
                      "/resp/Given_userAccount_contain_special_charater_When_register_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Register_userAccount_contain_special_charater req and resp not same.";
}

// 用户注册,密码和校验密码相同性校验
TEST_F(UserControllerRegisterTest, Register_userPassword_checkPassword_not_same)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, REGISTER_URI, HTTPMessage::HTTP_1_1,
                      "application/json", REGISTER_PATH,
                      "/req/Given_userPassword_checkPassword_not_same_When_register_Then_return_fail.json",
                      "/resp/Given_userPassword_checkPassword_not_same_When_register_Then_return_fail_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Register_userPassword_checkPassword_not_same req and resp not same.";
}

// 用户注册,星球编号校验