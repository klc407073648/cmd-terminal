import listCommand from "../commands/space/listCommand";
import removeCommand from "../commands/space/removeCommand";
import addCommand from "../commands/space/addCommand";
import mkdirCommand from "../commands/space/mkdirCommand";
import pwdCommand from "../commands/space/pwdCommand";
import cdCommand from "../commands/space/cdCommand";
import moveCommand from "../commands/space/moveCommand";
import copyCommand from "../commands/space/copyCommand";
import {CommandType} from "../command";
import gotoCommand from "../commands/space/gotoCommand";

/**
 *  空间命令集
 */
const spaceSet: Record<string, CommandType> = {
  mkdir: mkdirCommand,
  cd: cdCommand,
  add: addCommand,
  remove: removeCommand,
  move: moveCommand,
  copy: copyCommand,
  list: listCommand,
  pwd: pwdCommand,
  goto: gotoCommand,
};

/**
 * 空间命令，类似文件系统 + 收藏夹
 */
export default spaceSet;
