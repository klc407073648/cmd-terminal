import { CommandType } from "../../../command";
import { translate } from "./fanYiApi";


/**
 * 用户类型
 */
interface fanyiResultType {
  from: string;
  to: string;
  trans_result:Array<Array<string>>;
}
/**
 * 翻译命令
 * @author klc
 */
const fanyiCommand: CommandType = {
  func: "fanyi",
  name: "翻译",
  alias: [],
  params: [
    {
      key: "word",
      desc: "要翻译的内容",
      required: true,
    },
  ],
  options: [
    {
      key: "from",
      desc: "源语言",
      alias: ["f"],
      type: "string",
      defaultValue: "auto",
    },
    {
      key: "to",
      desc: "目标语言",
      alias: ["t"],
      type: "string",
      defaultValue: "auto",
    },
  ],
  async action(options, terminal) {
    const { _, from, to } = options;
    if (_.length < 1) {
      terminal.writeTextErrorResult("参数不足");
      return;
    }
    const keywords = _.join(" ");
    const res: any = await translate(keywords, {
      from,
      to,
    }).catch((err) => {
      //异常捕获
      terminal.writeTextErrorResult(err?.name + ":" + err?.message);
    });

    //异常返回直接return
    if(!res){
      return;
    }

    if (res?.code === 0) {
      //const tmp :fanyiResultType = JSON.parse(res.data);
      //const tmp = JSON.parse(res.data);
      //console.log(res.data);
      //console.log(tmp["trans_result"][0].dst);
      terminal.writeTextSuccessResult(
        `翻译结果：${(JSON.parse(res.data)).trans_result[0].dst}`
      );
    } else {
      terminal.writeTextErrorResult(res?.message ?? "翻译失败");
    }
  },
};

export default fanyiCommand;
