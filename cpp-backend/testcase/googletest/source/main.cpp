#include <iostream>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/NetException.h>
#include<string>
#include <json/json.h>
#include <fstream>

using namespace std;
using namespace Poco;
using namespace Poco::Net;
void getExample()
{
    try
    {
        //URI uri("https://api.btstu.cn/sjbz/api.php?lx=dongman&format=json");
        URI uri("http://api.eyekey.com/face/Check/checking?app_id=f89ae61fd63d4a63842277e9144a6bd2&app_key=af1cd33549c54b27ae24aeb041865da2&url=http%3A%2F%2Fpicview01.baomihua.com%2Fphotos%2F20120713%2Fm_14_634778197959062500_40614445.jpg");
		HTTPClientSession session(uri.getHost(), uri.getPort());
        HTTPRequest request(HTTPRequest::HTTP_GET, uri.getPathAndQuery());
        session.sendRequest(request);
        HTTPResponse response;
        std::istream &is = session.receiveResponse(response);
        const HTTPResponse::HTTPStatus &status = response.getStatus();
        if (HTTPResponse::HTTPStatus::HTTP_OK == status)
        {
            std::string result;
            StreamCopier::copyToString(is, result);
            std::cout << result << std::endl;
        }
        else
            std::cout << status << std::endl;
    }
    catch (const NetException &ex)
    {
        std::cerr << "ex: " << ex.displayText() << std::endl;
    }
}

void getfun1(){
	string searhName="hello";
	string result("");
	 try {
            URI url("https://www.baidu.com");
            HTTPClientSession session(url.getHost(),url.getPort());
            HTTPRequest req(HTTPRequest::HTTP_GET,HTTPRequest::HTTP_1_1);
            req.set("/s?word=", searhName);
            session.sendRequest(req);
            HTTPResponse res;
            istream & is = session.receiveResponse(res);
            StreamCopier::copyToString(is, result);
			std::cout << result << std::endl;
        }
        catch(NetException & ex){
            result = ex.displayText();
			std::cout << result << std::endl;
        }
	
}

void postExample()
{
    try
    {
        //URI uri("127.0.0.1:8082/api/user/register");
		//string path(uri.getPathAndQuery());
		//if (path.empty()) {
		//	path = "/";
		//}
 
	HTTPClientSession session("127.0.0.1", 8082);
	HTTPRequest request(HTTPRequest::HTTP_POST, "/api/user/register", HTTPMessage::HTTP_1_1);

	Json::Reader reader;
    Json::Value root;
    const char* path = "/home/stibel/cpp-backend/testcase/googletest/json/register/req/Given_userAccount_Null_When_register_Then_return_fail.json";
    std::ifstream infile(path);
   
    reader.parse(infile, root);

	string strBody = root.toStyledString();//jso格式的字符串 {}

    std::cout << "strBody:" << strBody << std::endl;
	//设置类型为application/json
	request.setContentType("application/json");
	request.setContentLength((int) strBody.length());
	//发送数据
	session.sendRequest(request) << strBody;

        HTTPResponse response;
        std::istream &is = session.receiveResponse(response);
        const HTTPResponse::HTTPStatus &status = response.getStatus();
        if (HTTPResponse::HTTPStatus::HTTP_OK == status)
        {
            std::string result;
            StreamCopier::copyToString(is, result);
            std::cout << result << std::endl;

            const char* path = "/home/stibel/cpp-backend/testcase/googletest/json/register/resp/Given_userAccount_Null_When_register_Then_return_fail_resp.json";
            std::ifstream infile(path);
        
			Json::Reader reader;
			Json::Value root;
            reader.parse(infile, root);
			Json::FastWriter fast_writer; 
            string res = fast_writer.write(root);
            std::cout << "res:" << res << std::endl;
			if(result == res){
				std::cout << "check success" << std::endl;
			}
			else {
				std::cout << "check fail" << std::endl;
			}
        }
        else
            std::cout << status << std::endl;
    }
    catch (const NetException &ex)
    {
        std::cerr << "ex: " << ex.displayText() << std::endl;
    }
}
int main()
{
    //getExample();
	getfun1();
    std::cout << std::endl;
    postExample();
    std::cout << std::endl;
    std::system("pause");
    return 0;
}