import { CommandType } from "../../command";
import { defineAsyncComponent } from "vue";
import ComponentOutputType = CmdTerminal.ComponentOutputType;
import TextOutputType = CmdTerminal.TextOutputType;

import useCommandOptionType from "../../../constants/CommandOptionType";

const { searchContext,displaySearchItem} = useCommandOptionType()

import {commandMap} from "../../commandRegister";
import relaxSet from "../../cmdsets/relaxSet"
import manageSet from "../../cmdsets/manageSet";
import terminalSet from "../../cmdsets/terminalSet";
import spaceSet from "../../cmdsets/spaceSet";
import toolSet from "../../cmdsets/toolSet";
import searchSet from "../../cmdsets/searchSet";
import {stringify} from "querystring";
import {isAdmin,NO_AUTH_EXEC_CMD} from "../manage/user/userCommon";
import logSet from "../../cmdsets/logSet";

/**
 * 命令全集 (确保其他命令集先于setinfo命令初始化，创建z-endcmd目录，滞后setinfo命令注册)
 * @author klc
 */
const fullCmdSet: Record<string, Record<string, CommandType>> = {
  manage: manageSet,
  relax: relaxSet,
  search: searchSet,
  space: spaceSet,
  terminal: terminalSet,
  tool: toolSet,
  log: logSet,
};

/**
 * 查看网站本身信息命令
 * @author klc
 */
const setinfoCommand: CommandType = {
  func: "setinfo",
  name: "查看命令集",
  alias: ["set"],
  params: [
    searchContext,
  ],
  options: [
    displaySearchItem,
  ],
  action(options, terminal): void {

    if(!isAdmin()){
      terminal.writeTextErrorResult(NO_AUTH_EXEC_CMD);
      return;
    }

    const { _, self,item } = options;
    //const word = _.length > 0 ? _[0] : "";

    if(item){
      terminal.writeTextSuccessResult("搜索源:" + Object.keys(fullCmdSet).toString());
      return
    }

    const word = _.length > 0 ? (_.join(" ")).trim() : "";//去掉前后空格

    console.log("word:"+word)
    if(word == ""){
      terminal.writeTextErrorResult("查询命令集必须输入：" + Object.keys(fullCmdSet));
      return;
    }
    var curCmdSet = fullCmdSet[word];
    const output: ComponentOutputType = {
      type: "component",
      component: defineAsyncComponent(() => import("./SetInfoBox.vue")),
      props: {
        name:word,
        cmdSets:curCmdSet,
      },
    };
    terminal.writeResult(output);
  },
};

export default setinfoCommand;
