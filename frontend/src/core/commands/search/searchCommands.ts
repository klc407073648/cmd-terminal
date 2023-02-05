import {CommandType} from "../../command";
import baiduCommand from "./baiduCommand";
import baidudevCommand from "./baidudevCommand";
import bilibiliCommand from "../relax/movie/bilibili/bilibiliCommand";
import bingCommand from "./bingCommand";
import githubCommand from "./githubCommand";
import googleCommand from "./googleCommand";
import zhihuCommand from "./zhihuCommand";
import useCommandOptionType from "../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()

/**
 * 搜索源
 */
const fromDict: Record<string, CommandType> = {
  bilibili: bilibiliCommand,
  baidu: baiduCommand,
  baidudev: baidudevCommand,
  bing: bingCommand,
  github: githubCommand,
  google: googleCommand,
  zhihu: zhihuCommand,
};

/**
 * 搜索命令
 * @author klc
 */
const searchCommand: CommandType = {
  func: "search",
  name: "网页搜索",
  alias: ["s", "sousuo", "sou", "query"],
  desc: "支持从不同平台快捷搜索内容",
  params: [
    searchContext,
  ],
  options: [
    {
      // 来源
      key: "from",
      alias: ["f"],
      type: "string",
      defaultValue: "baidu",
    },
    isOpenCur
  ],
  // 默认使用百度搜索
  action: (options, terminal) => {
    const { from = "baidu" } = options;
    // 执行不同搜索源的搜索方法
    const fromObj = fromDict[from];
    if (!fromObj) {
      terminal.writeTextErrorResult("找不到搜索源");
      return;
    }
    return fromObj.action(options, terminal);
  },
};

export default [searchCommand, ...Object.values(fromDict)];
