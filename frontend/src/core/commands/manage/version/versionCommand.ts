import { CommandType } from "../../../command";
import { defineAsyncComponent } from "vue";
import ComponentOutputType = CmdTerminal.ComponentOutputType;

/**
 * 查看版本
 * @author klc
 */
const versionCommand: CommandType = {
  func: "version",
  name: "版本",
  desc: "查看版本",
  alias: [],
  params: [],
  options: [],
  collapsible: true,
  action(options, terminal): void {
    const output: ComponentOutputType = {
      type: "component",
      component: defineAsyncComponent(() => import("./VersionBox.vue")),
    };
    terminal.writeResult(output);
  },
};

export default versionCommand;
