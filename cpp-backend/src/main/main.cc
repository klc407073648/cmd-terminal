#include <drogon/drogon.h>

using namespace drogon;

int main()
{
    //app().addListener("0.0.0.0", 8082).run();
	app().loadConfigFile("../conf/config.json").run();
    app().registerPostHandlingAdvice([](const drogon::HttpRequestPtr &,
                                        const drogon::HttpResponsePtr &resp) {
        resp->addHeader("Access-Control-Allow-Origin", "*");
		resp->addHeader("Access-Control-Allow-Credentials", "true");
		resp->addHeader("Access-Control-Allow-Headers", "*");
		resp->addHeader("Access-Control-Allow-Methods", "*");
		resp->addHeader("Access-Control-Expose-Headers", "*");
    });
}
