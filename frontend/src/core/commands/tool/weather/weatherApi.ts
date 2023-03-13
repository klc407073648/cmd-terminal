import myAxios from "../../../../plugins/myAxios";
import {AXIOS_ERROR, AxiosErrorResponse} from "../../../../constants/ResponseUtil";

/**
 * 翻译文本
 * @param keywords
 * @param config
 */
export const getCurrentWeather = async (
  city: string
) => {
  if (!city) {
    return null;
  }
  return await myAxios.post("/weather/now", { city }).catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};

export const getFutureWeather = async (
    city: string,
    days: string
) => {
  if (!city) {
    return null;
  }
  return await myAxios.post("/weather/future", { city,days }).catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};
