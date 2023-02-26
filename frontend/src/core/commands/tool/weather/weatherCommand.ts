import {CommandType} from "../../../command";
import {getCurrentWeather, getFutureWeather} from "./weatherApi";
import {defineAsyncComponent} from "vue";
import ComponentOutputType = CmdTerminal.ComponentOutputType;


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
                key: "city",
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
            const city = _.join(" ");
            var weather;
            var weatherInfo;

            if (!future) {
                //未来天气
                weather = await getFutureWeather(city, future).catch((err) => {
                    terminal.writeTextErrorResult(err?.name + ":" + err?.message);
                });

                weatherInfo = (JSON.parse(weather?.data))?.forecasts
            }
            else{
                //当天天气
                weather = await getCurrentWeather(city).catch((err) => {
                    terminal.writeTextErrorResult(err?.name + ":" + err?.message);
                });
                weatherInfo = (JSON.parse(weather?.data))?.lives
            }

            // 请求成功
            //调整
            if (weather?.code !== 0) {
                terminal.writeTextErrorResult(weather?.message + ":" + weather?.description);
                return;
            }

            console.log(weatherInfo)

            const output: ComponentOutputType = {
                type: "component",
                component: defineAsyncComponent(() => import("./WeatherBox.vue")),
                props: {
                    weatherInfo,
                },
            };
            terminal.writeResult(output);
        }
    };

export default weatherCommand;
