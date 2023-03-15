# 后端实现

# 概述

利用 Drogon 的C++ Web开发框架，实现MVC风格的代码格式。

* M层: 采用Drogon自带的orm框架，连接数据库自动生成models文件
* C层: 使用 Controller 风格，可以直接设置请求路径对应的处理函数的映射关系。
	* 提供统一的过滤器处理
	* http请求前置处理

# 后端服务

## 内容

1. UserService
	* 用户注册、登录、注销
2. InterfaceService
	* 第三方接口
		- 百度翻译API
		- 搏天API(随机背景)
		- 高德天气API
3. LogService
	* 针对前端已经登录的用户，记录用户的操作日志
4. CacheService
	* 缓存服务	
		* 可以使用本地缓存和redis缓存两种，用枚举区分,  后期考虑定时更新,数据库和缓存同步，Redis待实现
		* 目前作用: 后端启动时加载第三方接口数据库中相关数据，后续调用InterfaceService时，不需要每次都去查询(第三方接口变动不大)

## 接口路径

* InterfaceController
	* getBackground, "/api/background/get/random", Post
	* getTranslate, "/api/fanyi/translate", Post
	* getBackendVersion, "/api/backend/version", Get
	* getCurrentWeather, "/api/weather/now", Post
	* getFutureWeather, "/api/weather/future", Post

* LogController
	* writeUserLog, "/api/log/user/{1}", Post

* UserController
	* userRegister, "/api/user/register", Post
	* userLogin, "/api/user/login", Post
	* userLogout, "/api/user/logout", Post
	* searchUsers, "/api/user/search", Get
	* getCurrentUser, "/api/user/current", Get
	* deleteUsers, "/api/user/delete", Post
