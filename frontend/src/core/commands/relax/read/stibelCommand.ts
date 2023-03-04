import { CommandType } from "../../../command";
import useCommandOptionType from "../../../../constants/CommandOptionType";

const { searchContext,isOpenCur} = useCommandOptionType()

/**
 * 百度搜索命令
 * @author klc
 */
const stibelCommand: CommandType = {
  func: "stibel",
  name: "C++全栈知识体系",
  alias: ['sti'],
  options: [isOpenCur],
  action(options, terminal) {
    const { _, self,  } = options;
    let targetLink = `https://www.stibel.icu/`;

    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default stibelCommand;
