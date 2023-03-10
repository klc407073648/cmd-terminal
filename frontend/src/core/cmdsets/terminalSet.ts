import backgroundCommand from "../commands/terminal/config/backgroundCommand"
import hintCommand from "../commands/terminal/config/hintCommand"
import resetCommand from "../commands/terminal/operate/resetCommand"
import welcomeCommand from "../commands/terminal/config/welcomeCommand"
import helpCommand from "../commands/terminal/help/helpCommand"
import infoCommand from "../commands/terminal/info/infoCommand"
import shortcutCommand from "../commands/terminal/shortcut/shortcutCommand"
import clearCommand from "../commands/terminal/operate/clearCommand"
import historyCommand from "../commands/terminal/operate/historyCommand"
import {CommandType} from "../command";


/**
 *  终端命令集
 */
const terminalSet: Record<string, CommandType> = {
    background: backgroundCommand,
    hint: hintCommand,
    reset: resetCommand,
    welcome: welcomeCommand,
    help: helpCommand,
    info: infoCommand,
    shortcut: shortcutCommand,
    clear: clearCommand,
    history: historyCommand,
};

export default terminalSet;
