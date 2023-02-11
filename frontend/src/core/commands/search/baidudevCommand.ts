import { CommandType } from "../../command";
import useCommandOptionType from "../../../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()
/**
 * 百度开发者搜索命令
 * @author klc
 */
const baidudevCommand: CommandType = {
  func: "baidudev",
  name: "百度开发者搜索",
  alias: ["dev"],
  params: [
    searchContext,
  ],
  options: [
    isOpenCur
  ],
  action(options, terminal) {
    const { _, self } = options;
    const word = _.length > 0 ? _[0] : "";
    const targetLink = `https://kaifa.baidu.com/searchPage?wd=${word}`;
    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default baidudevCommand;
