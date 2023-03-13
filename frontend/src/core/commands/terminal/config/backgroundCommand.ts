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
    options: [
        {
            key: "lx",
            desc: "选择输出分类[meizi|dongman|fengjing|suiji]",
            alias: ["l"],
            type: "string",
            defaultValue: "fengjing",
        }
    ],
    helpDetails: [
        "名称	    必填	    类型	    说明",
        "method	    否	    string	输出壁纸端[mobile|pc|zsy]默认为pc",
        "lx	        否	    string	选择输出分类[meizi|dongman|fengjing|suiji]，为空随机输出",
        "format	    否	    string	输出壁纸格式[json|images]默认为images"
    ],
    async action(options, terminal) {
        const {_, lx} = options;
        let url = _[0];
        if (_.length > 0) {
            url = _[0];
        }
        const {setBackground} = useTerminalConfigStore();

        console.log("url=" + url + ",lx=" + lx)

        if(!(lx === "meizi" ||lx === "dongman" ||lx === "fengjing" ||lx === "suiji" )){
            terminal.writeTextErrorResult("选择输出分类[meizi|dongman|fengjing|suiji]");
            return;
        }

        if (!url) {
            // 随机获取壁纸
            const res = await getRandomBackground(lx)

            if (res?.code !== 0) {
                terminal.writeTextErrorResult(res?.message + ":" + res?.description);
            } else {
                setBackground(res.data);
            }
        }
        //如果url不可达，则提示报错 todo 暂不实现
        setBackground(url);
    },
};

export default backgroundCommand;
