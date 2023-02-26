#ifndef __INTERFACE_SERVICE_IMPL_H__
#define __INTERFACE_SERVICE_IMPL_H__

#include <models/Interface.h>
#include <services/InterfaceService.h>
#include <drogon/drogon.h>
#include <map>

using drogon_model::cmdterminal::Interface;

namespace cmdterminal
{
  class InterfaceServiceImpl : public InterfaceService
  {
  public:
    InterfaceServiceImpl();
    ~InterfaceServiceImpl();

    std::string getBackground() override;
    std::string getTranslate(const HttpRequestPtr &request) override;

  private:
  /**
   * @brief 从URL信息里获取主机地址和路径
   * 
   * @param url 
   * @param host 
   * @param path 
   */
    void getHostAndPathFromUrl(const std::string &url, std::string &host, std::string &path);
    /**
     * @brief 根据json字符串内容递归设置HttpRequest的请求参数
     * 
     * @param req 
     * @param jsonStr 
     */
    void setHttpRequestParam(const HttpRequestPtr &req, const std::string &jsonStr);
    /**
     * @brief 同步发送Http请求，解析返回信息里keyword字符串对应的内容
     * 
     * @param req 
     * @param client 
     * @param keyword 
     * @return std::string 
     */
    std::string syncSendRequest(const HttpRequestPtr &req, const HttpClientPtr &client, const std::string &keyword="");
    void initHttpMethodMap();
    void toLower(std::string &str);

  private:
    Mapper<Interface> InterfaceMapper = drogon::orm::Mapper<Interface>(drogon::app().getDbClient()); // 对象持久化映射层,连接User对象和数据库
    std::map<std::string, drogon::HttpMethod> httpMethodMap;
  };
}

#endif //__INTERFACE_SERVICE_IMPL_H__