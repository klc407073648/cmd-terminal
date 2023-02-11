import { CommandType } from "../../command";
import useCommandOptionType from "../../../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()
/**
 * 必应搜索命令
 * @author klc
 */
const bingCommand: CommandType = {
  func: "bing",
  name: "必应搜索",
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
    const targetLink = `https://www.bing.com/search?q=${word}`;
    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default bingCommand;
