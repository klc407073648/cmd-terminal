#include <drogon/drogon.h>

using namespace drogon;

int main()
{
    //设置文件输出
    trantor::AsyncFileLogger asyncFileLogger;
    asyncFileLogger.setFileName("cmdterminal",".log","../logs/");
    asyncFileLogger.startLogging();
    trantor::Logger::setOutputFunction(
        [&](const char *msg, const uint64_t len) {
            asyncFileLogger.output(msg, len);
        },
        [&]() { asyncFileLogger.flush(); });
    asyncFileLogger.setFileSizeLimit(100000000);

    //加载项目配置文件
	app().loadConfigFile("../conf/config.json").run();

    //支持跨域请求
    app().registerPostHandlingAdvice([](const drogon::HttpRequestPtr &,
                                        const drogon::HttpResponsePtr &resp) {
        resp->addHeader("Access-Control-Allow-Origin", "*");
		resp->addHeader("Access-Control-Allow-Credentials", "true");
		resp->addHeader("Access-Control-Allow-Headers", "*");
		resp->addHeader("Access-Control-Allow-Methods", "*");
		resp->addHeader("Access-Control-Expose-Headers", "*");
    });
}
