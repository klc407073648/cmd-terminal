import userCommands from "./user/userCommands";
import {CommandType} from "../../command";


/**
 * 搜索源
 */
const manageSet: Record<string, CommandType> = {
    user: userCommands,
};

export default [ ...userCommands];
