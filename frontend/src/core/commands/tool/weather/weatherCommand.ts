import {CommandType} from "../../../command";
import {getCurrentWeather, getFutureWeather} from "./weatherApi";


/**
 * 用户类型
 */
interface weatherResultType {
    from: string;
    to: string;
    trans_result: Array<Array<string>>;
}

/**
 * 翻译命令
 * @author klc
 */
const weatherCommand: CommandType = {
        func: "weather",
        name: "天气",
        alias: [],
        params: [
            {
                key: "cityname",
                desc: "城市名称",
                required: true,
            },
        ],
        options: [
            {
                key: "now",
                desc: "当天天气",
                alias: ["n"],
                type: "string",
                defaultValue: "",
            },
            {
                key: "future",
                desc: "未来天气",
                alias: ["f"],
                type: "string",
                defaultValue: "3",
            }
        ],
        async action(options, terminal) {
            const {_, now, future} = options;
            if (_.length < 1) {
                terminal.writeTextErrorResult("参数不足");
                return;
            }
            const cityname = _.join(" ");

            //未来天气
            if (!future) {
                const res = await getFutureWeather(cityname, future).catch((err) => {
                    terminal.writeTextErrorResult(err?.name + ":" + err?.message);
                });
                // 请求成功
                //调整
                if (res?.code !== 0) {
                    terminal.writeTextErrorResult(res?.message + ":" + res?.description);
                } else {
                    terminal.writeTextSuccessResult("未来天气");
                }
            }

            //当天天气
            const res = await getCurrentWeather(cityname).catch((err) => {
                terminal.writeTextErrorResult(err?.name + ":" + err?.message);
            });
            // 请求成功
            //调整
            if (res?.code !== 0) {
                terminal.writeTextErrorResult(res?.message + ":" + res?.description);
            } else {
                terminal.writeTextSuccessResult("当前天气");
            }
        }
    };

export default weatherCommand;
