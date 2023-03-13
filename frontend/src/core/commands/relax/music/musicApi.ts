import myAxios from "../../../../plugins/myAxios";
import {AXIOS_ERROR, AxiosErrorResponse} from "../../../../constants/ResponseUtil";

/**
 * 搜索单条音乐
 * @param keywords
 */
export const getSingleMusic = async (keywords: string) => {
  if (!keywords) {
    return null;
  }
  return await myAxios.post("/music/get", { keywords }).catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};
