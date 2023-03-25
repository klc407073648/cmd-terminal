#include <iostream>
#include "gtest/gtest.h"
#include <json/json.h>
#include <iostream>
#include <Poco/URI.h>
#include <Poco/StreamCopier.h>
#include <Poco/Net/HTTPClientSession.h>
#include <Poco/Net/HTTPRequest.h>
#include <Poco/Net/HTMLForm.h>
#include <Poco/Net/HTTPResponse.h>
#include <Poco/Net/NetException.h>
#include <string>
#include <json/json.h>
#include <fstream>
#include "HttpTest.h"

using namespace Poco;
using namespace Poco::Net;

HttpTest::HttpTest(const std::string &host, Poco::UInt16 port, const std::string &method, const std::string &uri,
				   const std::string &version, const std::string &contentType, const std::string &rootPath,
				   const std::string &reqJsonFile, const std::string &respJsonFile) : _host(host), _port(port), _method(method),
																					  _uri(uri), _version(version), _contentType(contentType), _rootPath(rootPath), _reqJsonFile(reqJsonFile), _respJsonFile(respJsonFile)
{
}

HttpTest::~HttpTest(){};

std::string HttpTest::readStringFromJson(const std::string &file)
{
	Json::Reader reader;
	Json::Value root;

	const char *path = file.c_str();
	std::ifstream infile(path);

	reader.parse(infile, root);
	Json::FastWriter fast_writer;

	std::string res = fast_writer.write(root);

	// 查找换行符的位置
	int pos = res.find_last_of('\n');

	// 如果找到了换行符
	if (pos != std::string::npos)
	{
		res.erase(pos, 1); // 在换行符的位置删除一个字符，即删除换行符
	}

	std::cout << "[readStringFromJson] file: " << file << ", res:" << res << std::endl;

	return res;
}

std::string HttpTest::readArrayStringFromJson(const std::string &file)
{
	Json::Reader reader;
	Json::Value root;

	const char *path = file.c_str();
	std::ifstream infile(path);

	reader.parse(infile, root);

	int arraySize = root.size();

	// 读取数组信息
	//std::cout << "[readArrayStringFromJson] arraySize: " << arraySize << std::endl;
	for (int i = 0; i < arraySize; i++)
	{
		Json::Value::Members mem = root[i].getMemberNames();
		for (auto iter = mem.begin(); iter != mem.end(); iter++)
		{
			//std::cout << "[readArrayStringFromJson] key: " << *iter << "value: " << root[i][*iter].asString() << std::endl;
		}
	}

	Json::FastWriter fast_writer;

	std::string res = fast_writer.write(root);

	// 查找换行符的位置
	int pos = res.find_last_of('\n');

	// 如果找到了换行符
	if (pos != std::string::npos)
	{
		res.erase(pos, 1); // 在换行符的位置删除一个字符，即删除换行符
	}

	std::cout << "[readArrayStringFromJson] file: " << file << ", res:" << res << std::endl;

	return res;
}

std::string HttpTest::sendRequest()
{
	std::string result("");

	if (_method == HTTPRequest::HTTP_POST)
	{
		result = sendPostRequest();
	}
	else if (_method == HTTPRequest::HTTP_GET)
	{
		result = sendGetRequest();
	}

	std::cout << "[sendRequest] result:" << result << std::endl;

	return result;
}

std::string HttpTest::sendPostRequest()
{
	std::string result("");

	try
	{
		HTTPClientSession session(_host, _port);
		HTTPRequest request(_method, _uri, _version);
		request.setContentType(_contentType);

		if (_reqJsonFile.empty())
		{
			session.sendRequest(request);
		}
		else
		{
			std::string strBody = readStringFromJson(_rootPath + _reqJsonFile); // json格式的字符串
			request.setContentLength((int)strBody.length());
			session.sendRequest(request) << strBody; // 发送数据
		}

		HTTPResponse response;
		std::istream &is = session.receiveResponse(response);
		const HTTPResponse::HTTPStatus &status = response.getStatus();
		if (HTTPResponse::HTTPStatus::HTTP_OK == status)
		{
			StreamCopier::copyToString(is, result);
			return result;
		}
		else
		{
			std::cout << "HTTPStatus is not HTTP_OK val:" << status << std::endl;
		}
	}
	catch (const NetException &ex)
	{
		std::cerr << "ex: " << ex.displayText() << std::endl;
	}

	return result;
}

std::string HttpTest::sendGetRequest()
{
	std::string result("");

	try
	{
		HTTPClientSession session(_host, _port);
		HTTPRequest request(_method, _uri, _version);

		session.sendRequest(request);

		HTTPResponse response;
		std::istream &is = session.receiveResponse(response);
		const HTTPResponse::HTTPStatus &status = response.getStatus();
		if (HTTPResponse::HTTPStatus::HTTP_OK == status)
		{
			StreamCopier::copyToString(is, result);
			return result;
		}
		else
		{
			std::cout << "HTTPStatus is not HTTP_OK val:" << status << std::endl;
		}
	}
	catch (const NetException &ex)
	{
		std::cerr << "ex: " << ex.displayText() << std::endl;
	}

	return result;
}