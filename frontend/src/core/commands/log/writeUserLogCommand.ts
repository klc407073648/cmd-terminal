import { CommandType } from "../../command";
import ComponentOutputType = CmdTerminal.ComponentOutputType;
import myAxios from "../../../plugins/myAxios";
import {useUserStore} from "../manage/user/userStore";
import useCommandOptionType from "../../../constants/CommandOptionType";
const { searchContext,isHide} = useCommandOptionType()

/**
 * 音乐命令
 * @author klc
 */
const writeUserLogCommand: CommandType = {
  func: "write_user_log",
  name: "写用户操作日志",
  desc: "日志管理",
  params: [
    searchContext
  ],
  options: [isHide],
  collapsible: true,
  async action(options, terminal): void {
    const { _, hide } = options;
    if (_.length < 1) {
      terminal.writeTextErrorResult("参数不足");
      return;
    }
    const content = _[0].replaceAll("%"," ");//将%转换为空格
    let data = {"content": content}
    const { loginUser } = useUserStore();
    const id = loginUser.id

    //restful请求写入id的日志记录，待规划后台实现表，直接往对应id插入日志记录即可
    const res1 = await myAxios.post("/log/user/"+id,data).then((res) => {
      //调整
      if(res?.code !== 0){
        if(hide){
          console.log("success res:",res)
        }
        else {
          terminal.writeTextErrorResult(res?.message + ":" + res?.description);
        }
      }
      else{
        if(hide){
          console.log("fail res:",res)
        }
        else {
          terminal.writeResult("写入成功");
        }
      }
    }).catch((err) => {
      if(hide){
        console.log("err res:",err)
      }
      else {
        terminal.writeTextErrorResult(err?.name + ":" + err?.message);
      }
    });
  },
};

export default writeUserLogCommand;
