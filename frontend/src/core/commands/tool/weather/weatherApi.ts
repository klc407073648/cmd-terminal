import myAxios from "../../../../plugins/myAxios";

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
  return await myAxios.post("/weather/now", { city });
};

export const getFutureWeather = async (
    city: string,
    days: string
) => {
  if (!city) {
    return null;
  }
  return await myAxios.post("/weather/future", { city,days });
};
