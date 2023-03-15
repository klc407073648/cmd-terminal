# 学习笔记

## 安装前置依赖

1. 在yuindex路径下，执行yarn，安装前端的依赖
2. 进入server路径，创建config.prod.js 区分不同的环境，填入生产环境的信息，并执行yarn安装后端的依赖

## 运行项目

1. 可以看 package.json 文件里的内容，前端直接执行 "dev": "vite",
2. 后端执行 cross-env NODE_ENV=prod node src/index.js

可以再关注具体模块怎么实现：

例如：bg，music的实现方法

看一下大家对yuindex的改进

注意事项：

* 通过.gitignore来限制一些生产环境的文件不要提交到代码库

tips:

* 全局请求日志记录
* 跨域
* 用户登录及session分布式存储

技术栈;

* Sequelize是一个基于promise的 Node.js ORM工具，目前支持 Postgres,MySQL,MartiaDB, SQLite以及Micresoft SQL Server,Amazon Redshift,Snowflake’s Data Cloud。
  它具有强大的事务支持，关联关系，随读和建进加裁读联复制等功能。

    * pomise 的核心原理：发布订阅模式，通过两个队列来展存成功的回调(onResolve)和失败的回调(onReject)
	* Promise: https://blog.csdn.net/weixin_38099964/article/details/113746365 
	* promise 和 async https://www.cnblogs.com/Hsong/p/14948492.html
	* require 和 import https://blog.csdn.net/liya_nan/article/details/81141244
	
* Express
	* 基于Node.js 平台，快速、开放、极简的Web开发框架团面
	
音乐的话，考虑是不是可以  歌曲 + 歌手方式搜索

鉴权模式，只有登录才能执行的内容


思路：
1. 命令集添加
2. 区别命令的执行结果，添加status标志
3. 添加定时命令，可以用于提醒适度休息
4. 支持命令帮助显示，单个和所有命令的查询
5. 命令输入提示，联想
6. 添加用户模块，包括注册，登录，注销
7. 支持命令进行折叠
8. 支持快捷键   (add 添加 shortcut 快捷键命令，补充提示)



1. 命令集： admin权限控制，添加权限等,可以尝试写一个空间系统的命令TODO。


.ts文件
1.既包含类型信息又可执行代码。
2.可以被编译成js文件，然后执行代码。
3.编写程序代码的地方

.d.ts文件
1.只包含类型信息的类型声明文件。
2.不会生成js文件，仅用于提供类型信息。
3.为js提供类型信息

总结：.ts（代码实现文件） .d.ts(类型声明文件)
https://blog.csdn.net/skxx123/article/details/126267884

问题：ref获取dom，起的变量名一定要和ref后的名字一致么？
答：不一致可以的，但是最终return中的名字要和ref中的值一致！！！


props学习
pinia状态管理  sessionStorage windowStorage

hint.ts  使用了Compostition API  hook 

return{
  person,
  ...toRefs(person)//  ...将对象以key:value形式展开，name:person.name

}

防抖学习 

防抖函数 debounce - 知乎

//自定义一个ref——名为：myRef
			function myRef(value,delay){
				let timer
				return customRef((track,trigger)=>{
					return {
						get(){
							console.log(`有人从myRef这个容器中读取数据了，我把${value}给他了`)
							track() //通知Vue追踪value的变化（提前和get商量一下，让他认为这个value是有用的）
							return value
						},
						set(newValue){
							console.log(`有人把myRef这个容器中数据改为了：${newValue}`)
							clearTimeout(timer)
							timer = setTimeout(()=>{
								value = newValue
								trigger() //通知Vue去重新解析模板
							},delay)
						},
					}
				})
			}

Options API 和 Composition API 比较

占位  loading的思想   react里面也有

前置所需Promise、axios、ES6、Ajax知识均有系统、强大、独立课程，链接在置顶评论中！