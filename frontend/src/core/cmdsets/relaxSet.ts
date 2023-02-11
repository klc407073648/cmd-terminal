import  bilibiliCommand from "../commands/relax/movie/bilibili/bilibiliCommand"
import  hotCommand from "../commands/relax/music/hot/hotCommand"
import  musicCommand from "../commands/relax/music/musicCommand"
import  stibelCommand from "../commands/relax/read/stibelCommand"
import  coolshellCommand from "../commands/relax/read/coolshellCommand"
import  pdaiCommand from "../commands/relax/read/pdaiCommand"
import {CommandType} from "../command";


/**
 *  休闲娱乐命令集
 */
const relaxSet: Record<string, CommandType> = {
    blibli: bilibiliCommand,
    hot: hotCommand,
    music: musicCommand,
    stibel: stibelCommand,
    coolshell: coolshellCommand,
    pdai: pdaiCommand,
};

export default relaxSet;
