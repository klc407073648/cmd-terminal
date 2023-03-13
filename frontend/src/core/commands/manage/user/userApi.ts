import myAxios from "../../../../plugins/myAxios";
import {AXIOS_ERROR, AxiosErrorResponse} from "../../../../constants/ResponseUtil";

/**
 * 用户登录
 * @param userAccount
 * @param userPassword
 */
export const userLogin = async (userAccount: string, userPassword: string) => {
  if (!userAccount || !userPassword) {
    return null;
  }
  return await myAxios.post("/user/login", { userAccount, userPassword }).catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};

/**
 * 用户注销
 */
export const userLogout = async () => {
  return await myAxios.post("/user/logout").catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};

/**
 * 用户注册
 * @param userAccount
 * @param userPassword
 * @param checkPassword
 */
export const userRegister = async (
  userAccount: string,
  userPassword: string,
  checkPassword: string
) => {
  if (!userAccount || !userPassword || !checkPassword) {
    return null;
  }
  return await myAxios.post("/user/register", { userAccount, userPassword, checkPassword }).catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};

/**
 * 获取当前登录用户
 */
export const getLoginUser = async () => {
  return await myAxios.get("/user/current").catch((err) => {
    return AxiosErrorResponse(AXIOS_ERROR,"",err)
  });
};

