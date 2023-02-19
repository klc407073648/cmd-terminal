import { CommandType } from "../../../../command";
import { getSingleMusic } from "../../../relax/music/musicApi";
import { userRegister } from "../userApi";

/**
 * 用户注册命令
 * @author klc
 */
const registerCommand: CommandType = {
  func: "register",
  name: "用户注册",
  options: [
    {
      key: "userAccount",
      desc: "用户名",
      alias: ["u"],
      type: "string",
      required: true,
    },
    {
      key: "userPassword",
      desc: "密码",
      alias: ["p"],
      type: "string",
      required: true,
    },
    {
      key: "checkPassword",
      desc: "校验密码",
      alias: ["c"],
      type: "string",
      required: true,
    },
  ],
  async action(options, terminal) {
    const { userAccount, userPassword, checkPassword } = options;
    if (!userAccount) {
      terminal.writeTextErrorResult("请输入用户名");
      return;
    }
    if (!userPassword) {
      terminal.writeTextErrorResult("请输入密码");
      return;
    }
    if (!checkPassword) {
      terminal.writeTextErrorResult("请输入校验密码");
      return;
    }
    const res: any = await userRegister(userAccount, userPassword, checkPassword);
    if (res?.code === 0) {
      terminal.writeTextSuccessResult("注册成功");
    } else {
      terminal.writeTextErrorResult((res?.message + ":" + res?.description) ?? "注册失败");
    }
  },
};

export default registerCommand;
