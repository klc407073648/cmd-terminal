import { CommandType } from "../../command";
import useCommandOptionType from "../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()
/**
 * 知乎搜索命令
 * @author klc
 */
const zhihuCommand: CommandType = {
  func: "zhihu",
  name: "知乎搜索",
  alias: [],
  params: [
    searchContext,
  ],
  options: [
    isOpenCur
  ],
  action(options, terminal) {
    const { _, self } = options;
    const word = _.length > 0 ? _[0] : "";
    const targetLink = `https://www.zhihu.com/search?q=${word}`;
    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default zhihuCommand;
