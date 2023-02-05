import { CommandType } from "../../command";
import useCommandOptionType from "../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()
/**
 * 百度搜索命令
 * @author klc
 */
const baiduCommand: CommandType = {
  func: "baidu",
  name: "百度搜索",
  alias: [],
  params: [
    searchContext
  ],
  options: [
    isOpenCur,
    {
      key: "picture",
      desc: "是否搜索图片",
      alias: ["p"],
      type: "boolean",
      defaultValue: false,
    },
  ],
  action(options, terminal) {
    const { _, self, picture } = options;
    const word = _.length > 0 ? _[0] : "";
    let targetLink = `https://www.baidu.com/s?wd=${word}`;
    // 搜索图片
    if (picture) {
      targetLink = `https://image.baidu.com/search/index?tn=baiduimage&word=${word}`;
    }
    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default baiduCommand;
