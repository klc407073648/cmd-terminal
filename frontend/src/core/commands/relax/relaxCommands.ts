import  bilibiliCommand from "./movie/bilibili/bilibiliCommand"
import  hotCommand from "./music/hot/hotCommand"
import  musicCommand from "./music/musicCommand"
import  stibelCommand from "./read/stibelCommand"
import  coolshellCommand from "./read/coolshellCommand"
import  pdaiCommand from "./read/pdaiCommand"
import {CommandType} from "../../command";


/**
 * 搜索源
 */
const relaxSet: Record<string, CommandType> = {
    blibli: bilibiliCommand,
    hot: hotCommand,
    music: musicCommand,
    stibel: stibelCommand,
    coolshell: coolshellCommand,
    pdai: pdaiCommand,
};

export default [bilibiliCommand,hotCommand,musicCommand,stibelCommand,coolshellCommand,pdaiCommand,relaxSet];
