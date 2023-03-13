import myAxios from "../../../../../plugins/myAxios";
import {AXIOS_ERROR, AxiosErrorResponse} from "../../../../../constants/ResponseUtil";

/**
 * 获取音乐热榜
 */
export const listHotMusics = async () => {
  return await myAxios.post("/music/list/hot", {}).catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};
