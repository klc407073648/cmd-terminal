import userCommands from "../commands/manage/user/userCommands";
import {CommandType} from "../command";
import versionCommand from "../commands/manage/version/versionCommand";


/**
 * 搜索源
 */
const manageSet: Record<string, CommandType> = {
    user: userCommands,
    version:versionCommand
};

export default manageSet;
