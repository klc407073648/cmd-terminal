import { CommandType } from "../../../../command";
import { userLogin, userRegister } from "../userApi";
import { useUserStore } from "../userStore";

/**
 * 用户登录命令
 * @author klc
 */
const loginCommand: CommandType = {
  func: "login",
  name: "用户登录",
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
  ],
  async action(options, terminal) {
    const { userAccount, userPassword } = options;
    if (!userAccount) {
      terminal.writeTextErrorResult("请输入用户名");
      return;
    }
    if (!userPassword) {
      terminal.writeTextErrorResult("请输入密码");
      return;
    }
    const res: any = await userLogin(userAccount, userPassword);
    const { setLoginUser } = useUserStore();
    if (res?.code === 0) {
      setLoginUser(res.data);
      terminal.writeTextSuccessResult("登录成功");
    } else {
      terminal.writeTextErrorResult((res?.message + ":" + res?.description)?? "登录失败");
    }
  },
};

export default loginCommand;
