import { CommandType } from "../../../command";
import useCommandOptionType from "../../../../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()


/**
 * 百度搜索命令
 * @author klc
 */
const pdaiCommand: CommandType = {
  func: "pdai",
  name: "Java全栈知识体系",
  alias: [],
  options: [isOpenCur],
  action(options, terminal) {
    const { _, self } = options;
    let targetLink = `https://www.pdai.tech/`;

    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default pdaiCommand;
