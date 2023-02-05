import { CommandType } from "./command";
import searchCommands from "./commands/search/searchCommands";
import spaceCommands from "./commands/space/spaceCommands";
import manageCommands from "./commands/manage/manageCommands";
import relaxCommands from "./commands/relax/relaxCommands";
import toolCommands from "./commands/tool/toolCommands";
import terminalCommands from "./commands/terminal/terminalCommands";

/**
 * 命令列表（数组元素顺序会影响 help 命令的展示顺序）
 */
const commandList: CommandType[] = [
  ...manageCommands,//管理功能
  ...relaxCommands,//休闲功能
  ...searchCommands,//搜索功能
  ...spaceCommands,//空间功能
  ...toolCommands,//工具功能
  ...terminalCommands,//终端功能
];

/**
 * 命令字典
 */
const commandMap: Record<string, CommandType> = {};

commandList.forEach((command) => {
  commandMap[command.func] = command;
  command.alias?.forEach((name) => {
    commandMap[name] = command;
  });
});

export { commandList, commandMap };
