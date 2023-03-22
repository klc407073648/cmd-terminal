#include <iostream>
#include "gtest/gtest.h"
#include "CommonContants.h"
#include "HttpTest.h"
#include "weather.h"
#include <Poco/Net/HTTPRequest.h>

using namespace Poco;
using namespace Poco::Net;

// 查询当前天气
TEST_F(InterfaceControllerWeatherTest, Weather_current)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, WEATHER_URI + "/now", HTTPMessage::HTTP_1_1,
                      "application/json", WEATHER_PATH,
                      "/req/Given_city_When_query_now_weather_Then_return_success.json",
                      "/resp/Given_city_When_query_now_weather_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Weather_current req and resp not same.";
}

// 查询未来天气
TEST_F(InterfaceControllerWeatherTest, Weather_future)
{
    HttpTest httpTest(BACKEND_IP, BACKEND_PORT, HTTPRequest::HTTP_POST, WEATHER_URI+ "/future", HTTPMessage::HTTP_1_1,
                      "application/json", WEATHER_PATH,
                      "/req/Given_city_When_query_future_weather_Then_return_success.json",
                      "/resp/Given_city_When_query_future_weather_Then_return_success_resp.json");

    std::string resp = httpTest.sendRequest();
    std::string res = httpTest.readStringFromJson(httpTest.getRespFullPath());

    EXPECT_EQ(resp, res) << "Weather_future req and resp not same.";
}