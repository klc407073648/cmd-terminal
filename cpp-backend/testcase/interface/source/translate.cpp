#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "translate.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 查询当前天气
TEST_F(InterfaceControllerTranslateTest, Translate_hello)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, TRANSLATE_URI, HTTPMessage::HTTP_1_1,
                      "application/json", TRANSLATE_PATH,
                      "/req/Given_hello_When_translate_Then_return_success.json",
                      "/resp/Given_hello_When_translate_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp , res) << "Translate_hello req and resp not same.";
}