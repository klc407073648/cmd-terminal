import myAxios from "../../../../plugins/myAxios";
import {AXIOS_ERROR, AxiosErrorResponse} from "../../../../constants/ResponseUtil";

/**
 * 翻译文本
 * @param keywords
 * @param config
 */
export const getRandomBackground = async (lx:string) => {
  return await myAxios.post("/background/get/random",{lx}).catch((err) => {
    console.log(err)
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};

