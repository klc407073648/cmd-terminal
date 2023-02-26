import myAxios from "../../../../plugins/myAxios";

/**
 * 翻译文本
 * @param keywords
 * @param config
 */
export const getCurrentWeather = async (
  cityname: string
) => {
  if (!cityname) {
    return null;
  }
  return await myAxios.post("/weather/now", { cityname });
};

export const getFutureWeather = async (
    cityname: string,
    days: string
) => {
  if (!cityname) {
    return null;
  }
  return await myAxios.post("/weather/future", { cityname,days });
};
