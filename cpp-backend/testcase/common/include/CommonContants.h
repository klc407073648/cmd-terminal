#include<string>

//const std::string BACKEND_IP = "$CMD_TERMINAL_BACKEND_IP";
//const int BACKEND_PORT = 8005;
//const std::string JSON_ROOT_PATH = "$CMD_TERMINAL_ROOT_PATH/testcase";

const std::string BACKEND_IP = "127.0.0.1";
const int BACKEND_PORT = 8005;
const std::string JSON_ROOT_PATH = "/home/stibel/cmd-terminal/cpp-backend/testcase";

const std::string CURRENT_URI = "/api/user/current";
const std::string CURRENT_PATH = JSON_ROOT_PATH + "/user/json/current";

const std::string LOGIN_URI = "/api/user/login";
const std::string LOGIN_PATH = JSON_ROOT_PATH + "/user/json/login";

const std::string LOGOUT_URI = "/api/user/logout";
const std::string LOGOUT_PATH = JSON_ROOT_PATH + "/user/json/logout";

const std::string REGISTER_URI = "/api/user/register";
const std::string REGISTER_PATH = JSON_ROOT_PATH + "/user/json/register";

const std::string WEATHER_URI = "/api/weather";
const std::string WEATHER_PATH = JSON_ROOT_PATH + "/interface/json/weather";

const std::string BACKENDVERSION_URI = "/api/backend/version";
const std::string BACKENDVERSION_PATH = JSON_ROOT_PATH + "/interface/json/backend/version";

const std::string BACKGROUND_URI = "/api/background/get/random";
const std::string BACKGROUND_PATH = JSON_ROOT_PATH + "/interface/json/background";

const std::string TRANSLATE_URI = "/api/fanyi/translate";
const std::string TRANSLATE_PATH = JSON_ROOT_PATH + "/interface/json/translate";