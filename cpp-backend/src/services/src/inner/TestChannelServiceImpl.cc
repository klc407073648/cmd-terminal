#include <services/inner/impl/TestChannelServiceImpl.h>
#include <json/json.h>
#include <exception/BusinessException.h>

using namespace cmdterminal;
using namespace drogon;

TestChannelServiceImpl::TestChannelServiceImpl()
{
    LOG_INFO << "TestChannelServiceImpl constructor!";
}

TestChannelServiceImpl::~TestChannelServiceImpl()
{
    LOG_INFO << "TestChannelServiceImpl destructor!";
}


std::string TestChannelServiceImpl::testChannel(const HttpRequestPtr &request)
{
	LOG_INFO << "[syncSendRequest] testChannel in:";
	
	
    auto client = HttpClient::newHttpClient("127.0.0.1", 8082);
    auto req = HttpRequest::newHttpRequest();
    req->setMethod(drogon::Post);
    req->setPath("/api/user/register");
    req->setBody("{\"userAccount\":\"111\",\"userPassword\":\"222\",\"checkPassword\":\"333\",\"planetCode\":\"4444\"}");
	std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req);
	
	
    /*
    client->sendRequest(req,[](ReqResult r, const HttpResponsePtr &resp) {
                            //REQUIRE(r == ReqResult::Ok);
                            //REQUIRE(resp->getBody().length() == 44618UL);
							LOG_INFO << "[syncSendRequest] respBody:" << resp->body();
                        });
    */

   
	//成功
	/*
	auto client = HttpClient::newHttpClient("https://api.btstu.cn");
    auto req = HttpRequest::newHttpRequest();
    req->setMethod(drogon::Get);
    req->setPath("/sjbz/api.php");
    req->setParameter("lx", "dongman");
    req->setParameter("format", "json");
	
	//'https://api.btstu.cn/sjbz/api.php', 'Get', '{\"lx\":\"dongman\",\"format\":\"json\"}'

    std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req);
    std::string respBody = static_cast<std::string>((resp.second)->body());

    LOG_INFO << "[syncSendRequest] respBody:" << respBody;
	*/

    return "";
}
