import fanyiCommand from "../commands/tool/fanyi/fanyiCommand"
import timingCommand from "../commands/tool/time/timingCommand"
import dateCommand from "../commands/tool/time/dateCommand"
import todoCommand from "../commands/tool/todo/todoCommand"
import pingCommand from "../commands/tool/dailyuse/pingCommand"
import {CommandType} from "../command";

const toolSet: Record<string, CommandType> = {
    fanyi: fanyiCommand,
    todo: todoCommand,
    timing: timingCommand,
    date: dateCommand,
    ping: pingCommand,
};

export default toolSet;

