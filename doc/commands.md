# cmdTerminal 命令大全

## 命令集分类

- 管理 manage：用户、权限等管理
- 休闲 relax：音乐、博客、blibli浏览
- 搜索 search：支持从不同搜索引擎检索内容(baidu,bing,zhihu,github)
- 空间 space：自实现的类文件系统，可以管理网页链接等内容
- 终端 terminal：定制或控制终端，比如更换背景、输出帮助、清屏、查看历史命令等
- 工具 tool：待处理事项、时间显示、天气查询、翻译内容。
- 日志 log：记录命令终端的各类日志。

## manage类

### 用户

用法：user <子命令>

帮助：

- 注册用户：user register -u testadmin -p 12345678 -c 12345678
- 登录用户：user login -u testadmin -p 12345678
- 注销用户：user logout

子命令：

- login 用户登录
- register 用户注册
- logout 用户注销

参数：

- subCommand 必填 子命令

## relax类

### bilibili 搜索

别名：bzhan, bili

用法：bilibili <搜索内容> [-s 是否当前页面打开] [-b B站视频id]

参数：

- word 必填 搜索内容

选项：

- -s, --self 可选 是否当前页面打开
- -b, --bvid 可选 B站视频id

### 热榜

命令：热榜

用法：hot [要查询的热榜]

参数：

- 热榜类别 可选 要查询的热榜

###  音乐

介绍：在线听音乐

用法：music <音乐名称>

参数：

- name 必填 音乐名称

### C++全栈知识体系

别名：sti

用法：stibel [-s 是否当前页面打开]

选项：

- -s, --self 可选 是否当前页面打开

### Java全栈知识体系

用法：pdai [-s 是否当前页面打开]

选项：

- -s, --self 可选 是否当前页面打开

### 酷壳

别名：cool

用法：coolshell [-s 是否当前页面打开]

选项：

- -s, --self 可选 是否当前页面打开

### 博客

介绍：博客列表

用法：blog

## search类

### search 网页搜索

介绍：支持从不同平台快捷搜索内容

别名：s, sousuo, sou, query

用法：search <搜索内容> [-f from] [-s 是否当前页面打开]

参数：

- word 必填 搜索内容

选项：

- -f, --from 可选 默认：baidu
- -s, --self 可选 是否当前页面打开
- -i, --item 可选 显示搜索源

### 其他搜索

命令集 search

命令列表：

- search      网页搜索
- baidu       百度搜索
- bing        必应搜索
- google      Google 搜索
- baidudev    百度开发者搜索
- csdn        csdn搜索
- github      GitHub 搜索
- zhihu       知乎搜索
- douban      豆瓣搜索

## space类

## terminal类

### 切换终端背景

别名：bg

用法：background [图片地址（不填则随机）] [-l 选择输出分类[meizi|dongman|fengjing|suiji]]

帮助：

- 名称 必填 类型 说明
- method 否 string 输出壁纸端[mobile|pc|zsy]默认为pc
- lx 否 string 选择输出分类[meizi|dongman|fengjing|suiji]，为空随机输出
- format 否 string 输出壁纸格式[json|images]默认为images

参数：

- url 可选 图片地址（不填则随机）

选项：

- -l, --lx 可选 默认：fengjing 选择输出分类[meizi|dongman|fengjing|suiji]

### 开关提示

介绍：开启 / 关闭输入提示

用法：hint [开关：on 开启, off 关闭]

参数：

- switch 可选 默认：on 开关：on 开启, off 关闭

### 重置终端配置

用法：reset

### 自定义终端欢迎语

用法：welcome [终端提示文本（支持多个值，不填则无欢迎语）]

参数：

- texts 可选 终端提示文本（支持多个值，不填则无欢迎语）

### 查看帮助

别名：man

用法：help [命令英文名称]

参数：

- commandName 可选 命令英文名称

### 查看本站信息

别名：author, about

用法：info

### 快捷键

介绍：查看快捷键

用法：shortcut

### 清屏

别名：cl

用法：clear

### 查看执行历史

别名：h

用法：history

## tool类

### 待办事项

介绍：记录和管理任务

用法：todo <子命令>

子命令：

- add 添加任务

参数：

- subCommand 必填 子命令

### 定时器

用法：timing <-s 秒数>

选项：

- -s, --seconds 必填 秒数

### 日期

用法：date

### 天气

用法：weather <城市名称> [-n 当天天气] [-f 未来天气]

参数：

- city 必填 城市名称

选项：

- -n, --now 可选 当天天气

- -f, --future 可选 默认：3 未来天气

### ping

介绍：检测某个地址是否存活

用法：ping <目标地址> [-t 请求超时时间(单位:毫秒)]

参数：

- dest 必填 目标地址

选项：

- -t, --timeout 可选 默认：3000 请求超时时间(单位:毫秒)

### 翻译

用法：fanyi <要翻译的内容> [-f 源语言] [-t 目标语言]

参数：

- word 必填 要翻译的内容

选项：

- -f, --from 可选 默认：auto 源语言

- -t, --to 可选 默认：auto 目标语言

## log类

### 写用户操作日志

介绍：日志管理

用法：write_user_log <搜索内容> [-h 是否隐藏输出结果]

参数：

- word 必填 搜索内容

选项：

- -h, --hide 可选 是否隐藏输出结果
