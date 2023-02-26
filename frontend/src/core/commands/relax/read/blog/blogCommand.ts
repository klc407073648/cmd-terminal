import { defineAsyncComponent } from "vue";
import ComponentOutputType = CmdTerminal.ComponentOutputType;
import {CommandType} from "../../../../command";

/**
 * 查看版本
 * @author klc
 */
const blogCommand: CommandType = {
  func: "blog",
  name: "博客",
  desc: "博客列表",
  alias: [],
  params: [],
  options: [],
  collapsible: true,
  action(options, terminal): void {
    const output: ComponentOutputType = {
      type: "component",
      component: defineAsyncComponent(() => import("./BlogBox.vue")),
    };
    terminal.writeResult(output);
  },
};

export default blogCommand;
