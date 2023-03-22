#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "userLogout.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 正常注销
TEST_F(UserControllerLogoutTest, Logout_normal)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, LOGOUT_URI, HTTPMessage::HTTP_1_1,
                      "application/json", LOGOUT_PATH,
                      "",
                      "/resp/Given_null_When_logout_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Logout_normal req and resp not same.";
}