import {doCommandExecute} from "../../../commandExecutor";
import {useUserStore} from "../user/userStore";
import TerminalType = CmdTerminal.TerminalType;


/**
 * 输出用户日志，若登录用户名非默认值local，则将操作日志内容写入数据库
 * @param inputText 命令内容
 * @param terminal  终端
 */
export const writeUserLog = async (inputText: string, terminal: TerminalType) => {
    const {loginUser} = useUserStore();
    console.log('writeUserLog in:', loginUser)

    if (loginUser.userAccount !== "local") {
        console.log('用户' + loginUser.userAccount + ' 已登录，需要记录日志')
        const mml = "write_user_log" + ' ' + inputText.replaceAll(" ", "%") + " -h"
        //点击回车提交时，默认记录隐藏日志不将结果显示在界面上，且通过%替换真正执行的命令，在writeUserLogCommand里再替换回来，写入后端日志库
        console.log('mml:' + mml)
        await doCommandExecute(mml, terminal);
    } else {
        console.log('用户未登录，不需要记录日志')
    }

};
