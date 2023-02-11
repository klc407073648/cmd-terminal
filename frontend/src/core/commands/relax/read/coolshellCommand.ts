import { CommandType } from "../../../command";
import isOpenCur from "../../../../constants/CommandOptionType";

/**
 * 百度搜索命令
 * @author klc
 */
const coolshellCommand: CommandType = {
  func: "coolshell",
  name: "酷壳",
  alias: ['cool'],
  options: [isOpenCur],
  action(options, terminal) {
    const { _, self } = options;
    let targetLink = `https://www.coolshell.cn/`;

    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default coolshellCommand;
