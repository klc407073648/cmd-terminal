import { CommandType } from "./command";
import searchSet from "./cmdsets/searchSet";
import spaceSet from "./cmdsets/spaceSet";
import manageSet from "./cmdsets/manageSet";
import relaxSet from "./cmdsets/relaxSet";
import toolSet from "./cmdsets/toolSet";
import terminalSet from "./cmdsets/terminalSet";
import setinfoCommand from "./commands/z-endcmd/setinfoCommand";
import logSet from "./cmdsets/logSet";

/**
 * 命令列表（数组元素顺序会影响 help 命令的展示顺序）
 */
const commandList: CommandType[] = [
  ...Object.values(manageSet),//管理功能
  ...Object.values(relaxSet),//休闲功能
  ...Object.values(searchSet),//搜索功能
  ...Object.values(spaceSet),//空间功能
  ...Object.values(toolSet),//工具功能
  ...Object.values(terminalSet),//终端功能
  ...Object.values(logSet),//终端功能
    setinfoCommand,//命令集查询命令单独注册
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
