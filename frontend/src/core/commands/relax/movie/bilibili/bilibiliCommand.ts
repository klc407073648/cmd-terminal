import { CommandType } from "../../../../command";
import { defineAsyncComponent } from "vue";
import ComponentOutputType = CmdTerminal.ComponentOutputType;
import useCommandOptionType from "../../../../../constants/CommandOptionType";
const { searchContext,isOpenCur} = useCommandOptionType()

/**
 * B 站搜索命令
 * @author klc
 */
const bilibiliCommand: CommandType = {
  func: "bilibili",
  name: "bilibili 搜索",
  alias: ["bzhan", "bili"],
  params: [
    searchContext
  ],
  options: [
    isOpenCur,
    {
      key: "bvid",
      desc: "B站视频id",
      alias: ["b"],
      type: "string",
    },
  ],
  collapsible: true,
  action(options, terminal) {
    const { _, self, bvid } = options;
    // 优先打开视频
    if (bvid) {
      const output: ComponentOutputType = {
        type: "component",
        component: defineAsyncComponent(() => import("./BilibiliBox.vue")),
        props: {
          bvid,
        },
      };
      terminal.writeResult(output);
      return;
    }
    const word = _.length > 0 ? _[0] : "";
    const targetLink = `https://search.bilibili.com/all?keyword=${word}`;
    if (self) {
      window.location.href = targetLink;
    } else {
      window.open(targetLink);
    }
  },
};

export default bilibiliCommand;
