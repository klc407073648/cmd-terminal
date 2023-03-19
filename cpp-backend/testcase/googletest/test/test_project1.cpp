#include <iostream>
#include "gtest/gtest.h"
#include <json/json.h>
#include <drogon/HttpClient.h>
#include <drogon/HttpAppFramework.h>
#include <drogon/drogon_test.h>
#include <StiBel/Util.h>

using namespace drogon;
using namespace StiBel;

#include "project1.h"


// IndependentMethod is a test case - here, we have 2 tests for this 1 test case
TEST(IndependentMethod, ResetsToZero) {
	int i = 3;
	independentMethod(i);
	EXPECT_EQ(0, i);

	i = 12;
	independentMethod(i);
	EXPECT_EQ(0,i);
}

TEST(IndependentMethod, ResetsToZero2) {
	int i = 0;
	independentMethod(i);
	EXPECT_EQ(0, i);
}

// The fixture for testing class Project1. From google test primer.
class Project1Test : public ::testing::Test {
protected:
	// You can remove any or all of the following functions if its body
	// is empty.

	Project1Test() {
		// You can do set-up work for each test here.
	}

	virtual ~Project1Test() {
		// You can do clean-up work that doesn't throw exceptions here.
	}

	// If the constructor and destructor are not enough for setting up
	// and cleaning up each test, you can define the following methods:
	virtual void SetUp() {
		client = HttpClient::newHttpClient("81.68.132.31", 8082);
    	req = HttpRequest::newHttpRequest();
	}

	virtual void TearDown() {
		// Code here will be called immediately after each test (right
		// before the destructor).
	}

	// Objects declared here can be used by all tests in the test case for Project1.
	Project1 p;

	public:
		HttpClientPtr client;
		HttpRequestPtr req;
};

// Test case must be called the class above
// Also note: use TEST_F instead of TEST to access the test fixture (from google test primer)

//测试OK
TEST_F(Project1Test, RandomBackground111222) {
	std::cout<<"RandomBackground111";
	std::string res = ShellUtil::execShellPipe("curl -XPOST 127.0.0.1:8082/api/user/register -H 'content-type:  application/json' -d '{\"userAccount\":\"111\",\"userPassword\":\"222\",\"checkPassword\":\"333\",\"planetCode\":\"4444\"}'");
	
	std::cout<<"res"<<res;
	EXPECT_EQ("", "");
}

//不考虑用drogon的 httpClient和HttpRequest，找一个三方库http2来构造请求
TEST_F(Project1Test, RandomBackground111) {
	std::cout<<"RandomBackground111";
	auto client = HttpClient::newHttpClient("https://api.btstu.cn");
    auto req = HttpRequest::newHttpRequest();
    req->setMethod(drogon::Get);
    req->setPath("/sjbz/api.php");
    req->setParameter("lx", "dongman");
    req->setParameter("format", "json");
	
	//'https://api.btstu.cn/sjbz/api.php', 'Get', '{\"lx\":\"dongman\",\"format\":\"json\"}'

    std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req,1);
    std::string respBody = static_cast<std::string>((resp.second)->body());
	std::cout<<"respBody"<<respBody;
	EXPECT_EQ("", "");
}

TEST_F(Project1Test, RandomBackground) {
	req->setMethod(drogon::Post);
    req->setPath("/api/user/register");
    req->setBody("{\"userAccount\":\"111\",\"userPassword\":\"222\",\"checkPassword\":\"333\",\"planetCode\":\"4444\"}");
	std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req,3);
    std::string respBody = static_cast<std::string>((resp.second)->body());
	EXPECT_EQ(respBody, "");
}

// }  // namespace - could surround Project1Test in a namespace