import {CommandOptionType, CommandParamsType} from "../core/command";

/**
 * 常用命令选项类型
 */

const useCommandOptionType = () => {
/**
 * 是否当前页面打开
 * @author klc
 */
const isOpenCur: CommandOptionType =
  {
    key: "self",
    desc: "是否当前页面打开",
    alias: ["s"],
    type: "boolean",
    defaultValue: false,
  }

/**
 * 搜索内容
 * @author klc
 */
const searchContext: CommandParamsType =
    {
        key: "word",
        desc: "搜索内容",
        required: true,
    }
    return {
        isOpenCur,
        searchContext,
    };
};
export default useCommandOptionType;
