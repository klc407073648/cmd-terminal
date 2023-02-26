
import {CommandType} from "../command";
import writeUserLogCommand from "../commands/log/writeUserLogCommand";

const logSet: Record<string, CommandType> = {
    writeUser: writeUserLogCommand,
};

export default logSet;

