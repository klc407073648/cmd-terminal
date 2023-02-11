import listCommand from "../commands/space/listCommand";
import removeCommand from "../commands/space/removeCommand";
import addCommand from "../commands/space/addCommand";
import mkdirCommand from "../commands/space/mkdirCommand";
import pwdCommand from "../commands/space/pwdCommand";
import cdCommand from "../commands/space/cdCommand";
import moveCommand from "../commands/space/moveCommand";
import copyCommand from "../commands/space/copyCommand";
import {CommandType} from "../command";

/**
 *  空间命令集
 */
const spaceSet: Record<string, CommandType> = {
  list: listCommand,
  remove: removeCommand,
  add: addCommand,
  mkdir: mkdirCommand,
  pwd: pwdCommand,
  cd: cdCommand,
  move: moveCommand,
  copy: copyCommand,
};

/**
 * 空间命令，类似文件系统 + 收藏夹
 */
export default spaceSet;
