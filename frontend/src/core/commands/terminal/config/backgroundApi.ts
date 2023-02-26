import myAxios from "../../../../plugins/myAxios";

/**
 * 翻译文本
 * @param keywords
 * @param config
 */
export const getRandomBackground = async () => {
  return await myAxios.post("/background/get/random");
};

