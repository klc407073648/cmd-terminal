import { CommandType } from "../../command";
import isOpenCur from "../constants/CommandOptionType";

/**
 * 百度搜索命令
 * @author klc
 */
const stibelCommand: CommandType = {
  func: "stibel",
  name: "C++全栈知识体系",
  alias: [],
  options: isOpenCur,
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
