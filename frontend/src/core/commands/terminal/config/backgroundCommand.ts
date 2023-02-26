import {CommandType} from "../../../command";
import {useTerminalConfigStore} from "./terminalConfigStore";
import axios from "axios";
import myAxios from "../../../../plugins/myAxios";
import {getRandomBackground} from "./backgroundApi";

/**
 * 切换终端背景
 * @author klc
 */
const backgroundCommand: CommandType = {
    func: "background",
    name: "切换终端背景",
    alias: ["bg"],
    params: [
        {
            key: "url",
            desc: "图片地址（不填则随机）",
            required: false,
        },
    ],
    options: [],
    async action(options, terminal) {
        const {_} = options;
        let url = _[0];
        if (_.length > 0) {
            url = _[0];
        }
        const {setBackground} = useTerminalConfigStore();
        if (!url) {
            // 随机获取壁纸
            const res = await getRandomBackground().catch((err) => {
                terminal.writeTextErrorResult(err?.name + ":" + err?.message);
            });

            //异常返回直接return
            if(!res){
                return;
            }

            if (res?.code !== 0) {
                terminal.writeTextErrorResult(res?.message + ":" + res?.description);
            } else {
                setBackground(res.data);
            }

        }
        //如果url不可达，则提示报错 todo
        setBackground(url);
    },
};

export default backgroundCommand;
