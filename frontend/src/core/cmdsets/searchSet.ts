import baiduCommand from "../commands/search/baiduCommand";
import baidudevCommand from "../commands/search/baidudevCommand";
import bingCommand from "../commands/search//bingCommand";
import githubCommand from "../commands/search//githubCommand";
import googleCommand from "../commands/search/googleCommand";
import zhihuCommand from "../commands/search/zhihuCommand";
import {CommandType} from "../command";
import doubanCommand from "../commands/search/doubanCommand";
import csdnCommand from "../commands/search/csdnCommand";
import searchCommand from "../commands/search/searchCommand";

/**
 * 搜索源
 */
const searchSet: Record<string, CommandType> = {
  search:searchCommand,
  baidu: baiduCommand,
  bing: bingCommand,
  google: googleCommand,
  baidudev: baidudevCommand,
  csdn:csdnCommand,
  github: githubCommand,
  zhihu: zhihuCommand,
  douban:doubanCommand,
};


export default searchSet;
