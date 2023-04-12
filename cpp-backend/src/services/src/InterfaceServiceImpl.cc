#include <services/impl/InterfaceServiceImpl.h>
#include <drogon/utils/Utilities.h>
#include <trantor/utils/Utilities.h>
#include <trantor/utils/Date.h>
#include <constants/InterfaceConstant.h>
#include <common/ErrorCode.h>
#include <exception/BusinessException.h>
#include <regex>
#include <locale>
#include <codecvt>
#include <json/json.h>
#include <cctype>

using namespace cmdterminal;
using namespace drogon;
using namespace drogon::internal;

InterfaceServiceImpl::InterfaceServiceImpl() : cacheServicePtr_(new CacheServiceImpl())
{
    LOG_INFO << "InterfaceServiceImpl constructor!";
    initHttpMethodMap();
}

InterfaceServiceImpl::~InterfaceServiceImpl()
{
    LOG_INFO << "InterfaceServiceImpl destructor!";
}

void InterfaceServiceImpl::initHttpMethodMap()
{
    httpMethodMap["Get"] = drogon::Get;
    httpMethodMap["Post"] = drogon::Post;
    httpMethodMap["Head"] = drogon::Head;
    httpMethodMap["Put"] = drogon::Put;
    httpMethodMap["Delete"] = drogon::Delete;
    httpMethodMap["Options"] = drogon::Options;
    httpMethodMap["Patch"] = drogon::Patch;
    httpMethodMap["Invalid"] = drogon::Invalid;
}

std::string InterfaceServiceImpl::getBackground(const HttpRequestPtr &request)
{
    std::string funName = __FUNCTION__;
    std::string imgurl("");

    try
    {
        // 1. 根据缓存获取接口信息
        Interface interface;

        if (!cacheServicePtr_->getInterfaceInfoByName(funName, interface))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
        }

        // 2. 校验接口内容有效性
        checkInterface(interface);

        // 3. 读取url,method
        std::string url = interface.getValueOfUrl();
        std::string method = interface.getValueOfMethod();
        std::string lx = ((*(request->getJsonObject()))["lx"]).asString();

        std::string host("");
        std::string path("");
        getHostAndPathFromUrl(url, host, path);

        auto client = HttpClient::newHttpClient(host);
        auto req = HttpRequest::newHttpRequest();
        req->setMethod(httpMethodMap[method]);
        req->setPath(path);
        req->setParameter("lx", lx);
        req->setParameter("format", BACKGROUND_FORMAT);

        imgurl = syncSendRequest(req, client, "imgurl");
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
    }
    return imgurl;
}

std::string InterfaceServiceImpl::getTranslate(const HttpRequestPtr &request)
{
    std::string funName = __FUNCTION__;
    std::string translateRes("");

    try
    {
        // 1. 根据缓存获取接口信息
        Interface interface;

        if (!cacheServicePtr_->getInterfaceInfoByName(funName, interface))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
        }

        // 2. 校验接口内容有效性
        checkInterface(interface);

        // 3. 读取url,method
        std::string url = interface.getValueOfUrl();
        std::string method = interface.getValueOfMethod();

        // 4. 从数据库获取密钥信息
        std::string appid = FANYI_API_APPID;
        std::string key = FANYI_API_KEY;

        std::string host("");
        std::string path("");
        getHostAndPathFromUrl(url, host, path);
        auto client = HttpClient::newHttpClient(host);

        // 5. 百度云翻译api方法
        auto json = *(request->getJsonObject()); // 从请求参数中获取keywords,from,to内容

        std::string keywords = json.isMember("keywords") ? json["keywords"].asString() : "";
        std::string from = json.isMember("config") ? ((json["config"]).isMember("from") ? json["config"]["from"].asString() : "") : "";
        std::string to = json.isMember("config") ? ((json["config"]).isMember("to") ? json["config"]["to"].asString() : "") : "";

        LOG_INFO << "[getTranslate] keywords:" << keywords << ", from:" << from << ", to:" << to;
        std::string salt = std::to_string(trantor::Date::now().microSecondsSinceEpoch()).substr(0, 10); // 随机数
        std::string sign = utils::getMd5(appid + keywords + salt + key);
        toLower(sign);

        auto req = HttpRequest::newHttpRequest();
        req->setMethod(httpMethodMap[method]);
        req->setPath(path);
        req->setParameter("q", keywords);  // 请求翻译query	UTF-8编码
        req->setParameter("from", from);   // 翻译源语言	语言列表(可设置为auto)
        req->setParameter("to", to);       // 译文语言	语言列表(不可设置为auto)
        req->setParameter("appid", appid); // APP ID	可在管理控制台查看
        req->setParameter("salt", salt);   // appid+q+salt+密钥 的MD5值
        req->setParameter("sign", sign);   // 要转小写才行
        translateRes = syncSendRequest(req, client);
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
    }

    return translateRes;
}

std::string InterfaceServiceImpl::getBackendVersion(const HttpRequestPtr &request)
{
    std::string funName = __FUNCTION__;
    std::string version("");

    try
    {
        // 1. 根据缓存获取接口信息
        Interface interface;

        if (!cacheServicePtr_->getInterfaceInfoByName(funName, interface))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
        }

        // 2. 校验接口内容有效性
        checkInterface(interface);

        // 3. 返回后端版本号,待存储到数据库
        version = "drogon:V1.1.0";
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
    }

    return version;
}

std::string InterfaceServiceImpl::getCurrentWeather(const HttpRequestPtr &request)
{
    std::string funName = __FUNCTION__;
    std::string weatherInfo("");
    try
    {
        // 1. 根据缓存获取接口信息
        Interface interface;

        if (!cacheServicePtr_->getInterfaceInfoByName(funName, interface))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
        }

        // 2. 校验接口内容有效性
        checkInterface(interface);

        // 3. 获取url,method
        std::string url = interface.getValueOfUrl();
        std::string method = interface.getValueOfMethod();

        std::string host("");
        std::string path("");
        getHostAndPathFromUrl(url, host, path);

        // 4. 填写对应请求内容，发送请求
        auto client = HttpClient::newHttpClient(host);
        auto req = HttpRequest::newHttpRequest();
        req->setMethod(httpMethodMap[method]);
        req->setPath(path);

        auto json = *(request->getJsonObject());
        std::string city = json.isMember("city") ? json["city"].asString() : "";

        // 高德天气API
        req->setParameter("key", WEATHER_API_KEY); // 请求服务权限标识
        req->setParameter("city", city);           // 城市编码
        req->setParameter("extensions", "base");   // 气象类型 base:返回实况天气,all:返回预报天气
        req->setParameter("output", "JSON");       // 返回格式:可选值：JSON,XML ,默认JSON

        weatherInfo = syncSendRequest(req, client);
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
    }

    return weatherInfo;
}

std::string InterfaceServiceImpl::getFutureWeather(const HttpRequestPtr &request)
{
    std::string funName = __FUNCTION__;
    std::string weatherInfo("");
    try
    {
        // 1. 根据缓存获取接口信息
        Interface interface;

        if (!cacheServicePtr_->getInterfaceInfoByName(funName, interface))
        {
            throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
        }

        // 2. 校验接口内容有效性
        checkInterface(interface);

        // 3. 获取url,method
        std::string url = interface.getValueOfUrl();
        std::string method = interface.getValueOfMethod();

        std::string host("");
        std::string path("");
        getHostAndPathFromUrl(url, host, path);

        // 4. 填写对应请求内容，发送请求
        auto client = HttpClient::newHttpClient(host);
        auto req = HttpRequest::newHttpRequest();
        req->setMethod(httpMethodMap[method]);
        req->setPath(path);

        auto json = *(request->getJsonObject());
        std::string city = json.isMember("city") ? json["city"].asString() : "";

        // 高德天气API
        req->setParameter("key", WEATHER_API_KEY); // 请求服务权限标识
        req->setParameter("city", city);           // 城市编码
        req->setParameter("extensions", "all");    // 气象类型 base:返回实况天气,all:返回预报天气
        req->setParameter("output", "JSON");       // 返回格式:可选值：JSON,XML ,默认JSON

        weatherInfo = syncSendRequest(req, client);
    }
    catch (const DrogonDbException &e)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), funName + "接口不存在");
    }

    return weatherInfo;
}

void InterfaceServiceImpl::getHostAndPathFromUrl(const std::string &url, std::string &host, std::string &path)
{
    try
    {
        int postion = url.find("//");

        int divide_postion = url.find("/", postion + 2);

        if (divide_postion != -1)
        {
            host = url.substr(0, divide_postion);
            path = url.substr(divide_postion);
        }
        else
        {
            host = url;
        }

        LOG_INFO << "[getHostAndPathFromUrl] url:" << url << ", host:" << host << ", path:" << path;
    }
    catch (...)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), "解析接口url信息错误");
    }
}

void InterfaceServiceImpl::getRequestParams(const std::string &json, std::map<std::string, std::string> &retMap)
{
    Json::Reader reader;
    Json::Value paramValue;

    if (reader.parse(json, paramValue))
    {
        Json::Value::Members mem = paramValue.getMemberNames();

        for (auto iter = mem.begin(); iter != mem.end(); iter++)
        {
            if (paramValue[*iter].type() == Json::objectValue)
            {
                getRequestParams(paramValue[*iter].asString(), retMap);
            }
            else if (paramValue[*iter].type() == Json::arrayValue)
            {
                // 数组则不处理
            }
            else if (paramValue[*iter].type() == Json::stringValue)
            {
                retMap[*iter] = paramValue[*iter].asString();
            }
            else if (paramValue[*iter].type() == Json::realValue)
            {
                retMap[*iter] = paramValue[*iter].asString();
            }
            else if (paramValue[*iter].type() == Json::uintValue)
            {
                retMap[*iter] = paramValue[*iter].asString();
            }
            else
            {
                retMap[*iter] = paramValue[*iter].asString();
            }
        }
        return;
    }
}

std::string InterfaceServiceImpl::syncSendRequest(const HttpRequestPtr &req, const HttpClientPtr &client, const std::string &keyword)
{
    std::string res("");
    
    std::pair<ReqResult, HttpResponsePtr> resp = client->sendRequest(req);
    std::string respBody("");
    if (resp.first == ReqResult::Ok)
    {
        respBody = static_cast<std::string>((resp.second)->body()); // TODO 翻译和背景 有问题，会core
    }
    else
    {
        LOG_ERROR << "[syncSendRequest] error";
        return res;
    }

    LOG_INFO << "[syncSendRequest] respBody:" << respBody;

    if (keyword.empty())
    {
        return respBody;
    }

    Json::Reader reader;
    Json::Value value;
    if (reader.parse(respBody, value))
    {
        res = value[keyword].asString();
    }

    LOG_INFO << "[syncSendRequest] keyword:" << keyword << ", value:" << res;

    return res;
}

void InterfaceServiceImpl::checkInterface(const Interface &interface)
{
    std::string name = interface.getValueOfName();

    if (interface.getValueOfStatus() != 0)
    {
        throw BusinessException(ErrorCode::PARAMS_ERROR(), name + "接口状态异常");
    }

    /*
    if(interface.getValueOfIsdelete != "0"){
        throw BusinessException(ErrorCode::PARAMS_ERROR(), name + "接口已经删除");
    }
    */
}

void InterfaceServiceImpl::toLower(std::string &str)
{
    for (int i = 0; i < str.size(); i++)
    {
        str[i] = tolower(str[i]);
    }
}