import { CommandType } from "../../command";
import useCommandOptionType from "../../../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()
/**
 * GitHub 搜索命令
 * @author klc
 */
const githubCommand: CommandType = {
  func: "github",
  name: "GitHub 搜索",
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
    const targetLink = `https://github.com/search?q=${word}`;
    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default githubCommand;
