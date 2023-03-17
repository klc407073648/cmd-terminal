# 后端实现

## 目录结构

- common      公共处理类封装
- constants   常量
- controllers 控制逻辑层
- exception   异常
- filters     过滤器
- models      模型文件
- plugins     插件
- services    具体业务逻辑

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

## 工程使用

```
# 创建工程
dg_ctl create project usercenter

# 控制器创建
cd ./usercenter/controllers/
dg_ctl create controller -h ControllerTest

# 过滤器创建
cd ../filters/
dg_ctl create filter LoginFilter

# 创建模型，需要配置config.json里mysql配置信息
cd ..
dg_ctl create model models
```
