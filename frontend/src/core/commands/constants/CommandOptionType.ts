import {CommandOptionType} from "../../command";

/**
 * 常用命令选项类型
 */

/**
 * 是否当前页面打开
 * @author klc
 */
const isOpenCur: CommandOptionType[] =[
  {
    key: "self",
    desc: "是否当前页面打开",
    alias: ["s"],
    type: "boolean",
    defaultValue: false,
  }]

export default isOpenCur;
