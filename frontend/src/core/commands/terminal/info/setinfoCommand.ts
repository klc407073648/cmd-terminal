import { CommandType } from "../../../command";
import { defineAsyncComponent } from "vue";
import ComponentOutputType = CmdTerminal.ComponentOutputType;
import TextOutputType = CmdTerminal.TextOutputType;

import useCommandOptionType from "../../constants/CommandOptionType";

const { searchContext} = useCommandOptionType()

import relaxSet from "../../relax/relaxCommands"
import {commandMap} from "../../../commandRegister";
/**
 * 查看网站本身信息命令
 * @author klc
 */
const setinfoCommand: CommandType = {
  func: "setinfo",
  name: "查看命令集",
  alias: ["set"],
  params: [
    searchContext
  ],
  options: [],
  action(options, terminal): void {
    const { _, self } = options;
    const word = _.length > 0 ? _[0] : "";
    var output = "";
    for(var index=0;index <relaxSet.length;index++){
      console.log("relaxSet",index,relaxSet[index])
      output = output + relaxSet[index].func +  " " + relaxSet[index].name + "\n"
    }
    console.log("relaxSet",relaxSet)
    console.log("relaxSet keys",relaxSet.keys())
    terminal.writeTextResult(JSON.stringify(output));
  },
};

export default setinfoCommand;
