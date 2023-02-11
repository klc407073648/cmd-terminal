import baiduCommand from "../commands/search/baiduCommand";
import baidudevCommand from "../commands/search/baidudevCommand";
import bingCommand from "../commands/search//bingCommand";
import githubCommand from "../commands/search//githubCommand";
import googleCommand from "../commands/search/googleCommand";
import zhihuCommand from "../commands/search/zhihuCommand";
import {CommandType} from "../command";

/**
 * 搜索源
 */
const searchSet: Record<string, CommandType> = {
  baidu: baiduCommand,
  baidudev: baidudevCommand,
  bing: bingCommand,
  github: githubCommand,
  google: googleCommand,
  zhihu: zhihuCommand,
};


export default searchSet;
