#include "InterfaceServiceImpl.h"
#include <drogon/utils/Utilities.h>
#include <trantor/utils/Utilities.h>
#include <trantor/utils/Date.h>
#include <common/ErrorCode.h>
#include <exception/BusinessException.h>
#include <regex>
#include <locale>
#include <codecvt>
#include <json/json.h>

using namespace cmdterminal;
using namespace drogon;
using namespace drogon::internal;

InterfaceServiceImpl::InterfaceServiceImpl()
{
    LOG_DEBUG << "InterfaceServiceImpl constructor!";
}

InterfaceServiceImpl::~InterfaceServiceImpl()
{
    LOG_DEBUG << "InterfaceServiceImpl destructor!";
}

std::string InterfaceServiceImpl::getBackground()
{
    std::string imgurl("");
    try
    {
        auto Interface = InterfaceMapper.findOne(Criteria(Interface::Cols::_name, CompareOperator::EQ, "getBackground"));

        // 3. 用户脱密
        std::string httpUrl = Interface.getValueOfUrl();

        LOG_INFO << "InterfaceServiceImpl::getBackground httpUrl" << httpUrl;

        auto client = HttpClient::newHttpClient("https://api.btstu.cn"); // https://api.btstu.cn/sjbz/api.php?lx=dongman&format=json
        auto req = HttpRequest::newHttpRequest();
        req->setMethod(drogon::Get);
        req->setPath("/sjbz/api.php");
        req->setParameter("lx", "dongman");
        req->setParameter("format", "json");
        // InterfaceServiceImpl:: getBody{"code":"200","imgurl":"https:\/\/img.btstu.cn\/api\/images\/5e82f63b10af7.jpg","width":"1920","height":"1080"} - InterfaceServiceImpl.cc:34

        // 异步调用，直接返回了拿不到imgurl
        /*
        client->sendRequest(req, [&imgurl](ReqResult result, const HttpResponsePtr &resp) {
            std::string respBody = static_cast<std::string>(resp->body());
            Json::Reader reader;
            Json::Value value;
            if (reader.parse(respBody, value))
            {
                LOG_INFO << "InterfaceServiceImpl:: imgurl" << value["imgurl"].asString();
                imgurl = value["imgurl"].asString();
            }

            LOG_INFO << "InterfaceServiceImpl:: getBody" << resp->body();
        });
        */
        // 同步调用
        std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req);
        std::string respBody = static_cast<std::string>((resp.second)->body());
        Json::Reader reader;
        Json::Value value;
        if (reader.parse(respBody, value))
        {
            LOG_INFO << "InterfaceServiceImpl:: imgurl" << value["imgurl"].asString();
            imgurl = value["imgurl"].asString();
        }
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), "getBackground接口不存在");
    }

    return imgurl;
}

std::string InterfaceServiceImpl::getTranslate()
{
    LOG_INFO << "InterfaceServiceImpl::getTranslate in";

    auto client = HttpClient::newHttpClient("http://api.fanyi.baidu.com/api/trans/vip/translate");
    std::string appid = "20160413000018571";
    std::string key = "12345678";
    std::string keywords = "apple";
    std::string salt = "1435660288"; // utils::genRandomString(10);
    // std::string temp = utf8_encode(to_wstring(appid + keywords + salt + key));
    //std::string temp = utf8_encode(to_wstring("2015063000000001apple143566028812345678"));
    auto sign = "39c436658c2f20730931b5139094c0a7";
    LOG_INFO << "InterfaceServiceImpl::getTranslate keywords:" << keywords;
    LOG_INFO << "InterfaceServiceImpl::getTranslate appid:" << appid;
    LOG_INFO << "InterfaceServiceImpl::getTranslate key:" << key;
    LOG_INFO << "InterfaceServiceImpl::getTranslate salt:" << salt;
    //LOG_INFO << "InterfaceServiceImpl::getTranslate temp:" << temp;
    LOG_INFO << "InterfaceServiceImpl::getTranslate sign:" << sign;
    auto req = HttpRequest::newHttpRequest();

    req->setMethod(drogon::Get);
    req->setParameter("q", "apple");
    req->setParameter("from", "auto");
    req->setParameter("to", "zh");
    req->setParameter("appid", "20230217001565627");
    req->setParameter("salt", "1435660288");
    req->setParameter("sign", "98ae3e39e00c102540200a8615739aa5"); // 要转小写才行

    /*
    http://api.fanyi.baidu.com/api/trans/vip/translate?q=apple&from=auto&to=zh&appid=20230217001565627&salt=1435660288&sign=98ae3e39e00c102540200a8615739aa5
    APP ID：20230217001565627
    密钥：oBb8QjQvxqywMug9TJl5
    20230217001565627apple1435660288oBb8QjQvxqywMug9TJl5
    */

    std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req);
    std::string respBody = static_cast<std::string>((resp.second)->body());
    LOG_INFO << "InterfaceServiceImpl::getTranslate body:" << respBody;
    // LOG_INFO << "InterfaceServiceImpl::getTranslate respBody" <<respBody;

    return respBody;
}