import { CommandType } from "../../../command";
import registerCommand from "./subCommands/registerCommand";
import loginCommand from "./subCommands/loginCommand";
import { getLoginUser } from "./userApi";
import { useUserStore } from "./userStore";
import { LOCAL_USER } from "./userConstant";
import logoutCommand from "./subCommands/logoutCommand";

/**
 * 用户命令
 * @author klc
 */
const userCommand: CommandType = {
  func: "user",
  name: "用户",
  alias: [],
  params: [
    {
      key: "subCommand",
      desc: "子命令",
      required: true,
    },
  ],
  helpDetails: ["注册用户：user register -u testadmin -p 12345678 -c 12345678",
      "登录用户：user login -u testadmin -p 12345678 ",
      "注销用户：user logout"],
  subCommands: {
    login: loginCommand,
    register: registerCommand,
    logout: logoutCommand,
  },
  options: [],
  async action(options, terminal) {
    const { loginUser } = useUserStore();
    if (loginUser && loginUser.userAccount !== LOCAL_USER.userAccount) {
      let text = `当前用户：${loginUser.userAccount}`;
      if (loginUser.email) {
        text += ` ${loginUser.email}`;
      }
      terminal.writeTextResult(text);
    } else {
      terminal.writeTextErrorResult("未登录，请执行 user login 命令登录");
    }
  },
};

export default userCommand;
