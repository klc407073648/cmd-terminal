#include<string>

const std::string BACKEND_IP = "127.0.0.1";
const int BACKEND_PORT = 8082;
const std::string JSON_ROOT_PATH = "/home/stibel/cpp-backend/testcase";

const std::string CURRENT_URI = "/api/user/current";
const std::string CURRENT_PATH = JSON_ROOT_PATH + "/user/json/current";

const std::string LOGIN_URI = "/api/user/login";
const std::string LOGIN_PATH = JSON_ROOT_PATH + "/user/json/login";

const std::string LOGOUT_URI = "/api/user/logout";
const std::string LOGOUT_PATH = JSON_ROOT_PATH + "/user/json/logout";

const std::string REGISTER_URI = "/api/user/register";
const std::string REGISTER_PATH = JSON_ROOT_PATH + "/user/json/register";