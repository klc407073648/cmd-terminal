#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "background.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 获取动漫背景
TEST_F(InterfaceControllerBackgroundTest, Background_Dongman)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, BACKGROUND_URI, HTTPMessage::HTTP_1_1,
                      "application/json", BACKGROUND_PATH,
                      "/req/Given_dongman_When_get_background_Then_return_success.json",
                      "/resp/Given_dongman_When_get_background_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp , res) << "Background_Dongman req and resp not same.";
}