# 前端

# 目录结构

- components   组件封装
- configs      配置文件(路由配置)
- constants    常量
- core         核心文件(命令具体实现)
- pages        页面 
- plugins      插件封装
- utils        工具类

# 详细内容

## components

- CmdTerminal

	- 提交命令逻辑

		- 按键事件：@press-enter="doSubmitCommand"，也可以使用其他 @keydown.alt=
		- doSubmitCommand里执行props.onSubmitCommand?.(inputText)
		- 进入indexPage里的onSubmitCommand，转而调用doCommandExecute

- ContentOutput

	- 输出内容组件

		- type OutputStatusType = "info" | "success" | "warning" | "error" | "system";
		- 存在输出结果无指定OutputStatusType的情况

- shortcuts

	- 逻辑

		- 1. CmdTerminal里onMounted函数执行 registerShortcuts
		- 2. 使用document.onkeydown进行键盘的监听
		- 研究： KeyboardEvent的内容

- hint

	- 概念：命令提示功能
	- 逻辑：当输入框内容发送变化时，触发getUsageStr获取用法提示

- history

	- 概念：查看历史功能
	- 逻辑

		- 1.所有输入的命令，都会维护在commandList
		- 2. 记录当前命令所在位置：commandHistoryPos
		- 3. 获取键盘输入的↑和↓的事件，来切换当前inputCommand的文本内容，显示在界面上

- type.d.ts

	- 声明命名空间

		- 解决重名问题，多个命令空间里可以有相同的函数，调用时通过加上命名空间前缀来区分

	- CommandInputType
	- OutputType

		- 输出状态

			- OutputStatusType

		- 类型分类

			- CommandOutputType
			- TextOutputType
			- ComponentOutputType

	- TerminalType

		- 定义一组访问及操作终端的方法

## configs

- route

	- 配置路由

## core

- command.d.ts

	- 接口内容定义
	- CommandType
	- CommandParamsType
	- CommandOptionType

- commandExecutor

	- doCommandExecute

		- TerminalType感觉不太合适
		- 处理逻辑

			- 1.预处理去掉输入字符串的首尾
			- 2.getCommand，去commandList里找匹配的命令
			- 3.解析参数，有子命令则重新解析user login xxx => login xxx ，递归调用 doCommandExecute

				- 父子命令实现递归处理

			- 4.执行命令，如果携带--help给出命令逻辑，否则直接执行命令体里的action函数

- commandRegister

	- 提供命令列表和根据名称找命令的map结构
	- 逻辑：将所有命令添加到commandList，并且创建命令名称和实体的映射(别名也需要创建)

		- 注意点：别名会有覆盖情况，后面注册的会覆盖前面的，待处理

	- commandList
	- commandMap

- 命令集分类

	- constants
	- fanyi
	- hot
	- read
	- record
	- relax
	- search
	- space

		- 空间管理
		- 常规的add,cd,copy,list,mkdir,move,pwd,remove命令

			- 添加和切换目录，前面要加/

		- 核心：spaceStore

			- 在缓存里，如何考虑维护用户的数据在数据库

	- terminal
	- timing
	- todo
	- user

		- 分析子命令的详细逻辑

	- varbook

## pages

- 负责连接终端和命令控制系统
- 通过ref获取到cmd-terminal的DOM对象

## plugins

- axios

	- 网络请求库的二次封装

- dayjs

	- 日期处理

## utils

- smartText

	- 识别文本中的超链接