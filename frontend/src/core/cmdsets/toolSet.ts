import fanyiCommand from "../commands/tool/fanyi/fanyiCommand"
import timingCommand from "../commands/tool/time/timingCommand"
import dateCommand from "../commands/tool/time/dateCommand"
import todoCommand from "../commands/tool/todo/todoCommand"
import pingCommand from "../commands/tool/dailyuse/pingCommand"
import {CommandType} from "../command";
import weatherCommand from "../commands/tool/weather/weatherCommand";

const toolSet: Record<string, CommandType> = {
    todo: todoCommand,
    timing: timingCommand,
    date: dateCommand,
    weather:weatherCommand,
    ping: pingCommand,
    fanyi: fanyiCommand,
};

export default toolSet;

