#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "backendVersion.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 登录正常用户,获取当前用户
TEST_F(InterfaceControllerBackendVersionTest, BackendVersion_query)
{
    //先登录
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_GET, BACKENDVERSION_URI, HTTPMessage::HTTP_1_1,
                      "application/json", BACKENDVERSION_PATH,
                      "",
                      "/resp/Given_null_When_query_backend_version_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp , res) << "BackendVersion_query login req and resp not same.";
}